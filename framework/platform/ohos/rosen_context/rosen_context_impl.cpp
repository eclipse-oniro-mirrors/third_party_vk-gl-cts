/*
 * Copyright (c) 2022 Shenzhen Kaihong Digital Industry Development Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "rosen_context_impl.h"

#include "ui/rs_surface_extractor.h"
#include "backend/rs_surface_ohos_gl.h"

using namespace OHOS;
using namespace Rosen;

RosenContextImpl::RosenContextImpl()
{
    InitEgl();
    InitProducer();
}

#define PRINT_EGL_CONFIG(type)                             \
    {                                                      \
        int32_t value;                                     \
        eglGetConfigAttrib(eglDisplay, cfg, type, &value); \
        printf("  %s: %d\n", #type, value);                \
    }
void PrintEglConfig(void *eglDisplay, EGLConfig cfg)
{
    // 打印颜色缓冲区属性
    PRINT_EGL_CONFIG(EGL_BUFFER_SIZE)
    PRINT_EGL_CONFIG(EGL_RED_SIZE)
    PRINT_EGL_CONFIG(EGL_GREEN_SIZE)
    PRINT_EGL_CONFIG(EGL_BLUE_SIZE)
    PRINT_EGL_CONFIG(EGL_ALPHA_SIZE)
    PRINT_EGL_CONFIG(EGL_DEPTH_SIZE)
    PRINT_EGL_CONFIG(EGL_STENCIL_SIZE)

    // 打印其他属性
    PRINT_EGL_CONFIG(EGL_CONFIG_CAVEAT)
    PRINT_EGL_CONFIG(EGL_CONFIG_ID)
    PRINT_EGL_CONFIG(EGL_LEVEL)
    PRINT_EGL_CONFIG(EGL_MAX_PBUFFER_WIDTH)
    PRINT_EGL_CONFIG(EGL_MAX_PBUFFER_HEIGHT)
    PRINT_EGL_CONFIG(EGL_MAX_PBUFFER_PIXELS)
    PRINT_EGL_CONFIG(EGL_NATIVE_VISUAL_ID)
    PRINT_EGL_CONFIG(EGL_SAMPLES)
    PRINT_EGL_CONFIG(EGL_SAMPLE_BUFFERS)
    PRINT_EGL_CONFIG(EGL_SURFACE_TYPE)
    PRINT_EGL_CONFIG(EGL_RENDERABLE_TYPE)
    PRINT_EGL_CONFIG(EGL_TRANSPARENT_TYPE)
    PRINT_EGL_CONFIG(EGL_TRANSPARENT_RED_VALUE)
    PRINT_EGL_CONFIG(EGL_TRANSPARENT_GREEN_VALUE)
    PRINT_EGL_CONFIG(EGL_TRANSPARENT_BLUE_VALUE)
}

void RosenContextImpl::ShowConfig(EGLConfig cfg)
{
    EGLint red, green, blue, alpha, depth, stencil, samples, sft, rt;

    eglGetConfigAttrib(eglDisplay_, cfg, EGL_RED_SIZE, &red);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_GREEN_SIZE, &green);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_BLUE_SIZE, &blue);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_ALPHA_SIZE, &alpha);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_DEPTH_SIZE, &depth);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_STENCIL_SIZE, &stencil);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_SAMPLES, &samples);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_SURFACE_TYPE, &sft);
    eglGetConfigAttrib(eglDisplay_, cfg, EGL_RENDERABLE_TYPE, &rt);

    printf("%8d%8d%8d%8d%8d%8d%8d%8d%8d\n", red, green, blue, alpha, depth, stencil, samples, sft, rt);
}

void RosenContextImpl::InitProducer()
{
    displayNode_ = RSDisplayNode::Create(RSDisplayNodeConfig());
    surfaceNode_ = RSSurfaceNode::Create(RSSurfaceNodeConfig());
    surfaceNode_->SetBounds(0, 0, 512, 512);
    displayNode_->AddChild(surfaceNode_, -1);

    std::shared_ptr<RSSurface> rsSurface = RSSurfaceExtractor::ExtractRSSurface(surfaceNode_);
    std::shared_ptr<RSSurfaceOhosGl> rsSurfaceOhosGl = std::static_pointer_cast<RSSurfaceOhosGl>(rsSurface);
    producer_ = rsSurfaceOhosGl->GetSurface();
}

bool RosenContextImpl::InitEgl()
{
    if (eglInited_)
    {
        return true;
    }
    eglDisplay_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (eglDisplay_ == EGL_NO_DISPLAY)
    {
        printf("Failed to create EGLDisplay gl errno : %x", eglGetError());
        return false;
    }

    EGLint major, minor;
    if (eglInitialize(eglDisplay_, &major, &minor) == EGL_FALSE)
    {
        printf("Failed to initialize EGLDisplay");
        return false;
    }

    if (CheckIfNeedOpengl())
    {
        if (eglBindAPI(EGL_OPENGL_API) == EGL_FALSE)
        {
            printf("Failed to eglBindAPI(EGL_OPENGL_API)");
            return false;
        }
    }

    glDepthMask(GL_TRUE);

    eglGetConfigs(eglDisplay_, NULL, 0, &configCount_);
    allConfigs_ = new EGLConfig[configCount_];
    eglGetConfigs(eglDisplay_, allConfigs_, configCount_, &configCount_);

    printf("config count : %d\n", configCount_);
    printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s\n", "red", "green", "blue", "alpha", "depth", "stencil", "samples", "sft", "rt");
    for (int i = 0; i < configCount_; i++)
    {
        ShowConfig(allConfigs_[i]);
    }
    eglInited_ = true;
    return true;
}

bool RosenContextImpl::CheckIfNeedOpengl()
{
    const char* needOpenglEnv = "NEED_OPENGL";
    const char* needOpenglEnvValue = getenv(needOpenglEnv);
    if (needOpenglEnvValue && std::string(needOpenglEnvValue) ==  "1")
    {
        return true;
    }
    return false;
}

bool RosenContextImpl::SetConfig(int32_t w, int32_t h, RCI_GLES_VERSION ver, RCI_PIXEL_FORMAT pf, RCI_SURFACE_TYPE st, RCI_PROFILE tp, RCI_CONTEXT_FLAG flags)
{
    glesVersion_ = ver;
    typeProfile_ = tp;
    contextFlags_ = flags;
    surfaceType_ = st;
    width_ = w;
    height_ = h;
    pixelFormat_ = pf;

    EGLint eglApi;
    switch (typeProfile_)
    {
    case RCI_PROFILE::ES:
        eglApi = EGL_OPENGL_ES_API;
        break;
    case RCI_PROFILE::CORE:
        eglApi = EGL_OPENGL_API;
        break;
    case RCI_PROFILE::COMPATIBILITY:
        eglApi = EGL_OPENGL_API;
        break;
    default:
        return false;
    }
    if (eglBindAPI(eglApi) == EGL_FALSE)
    {
        printf("Failed to bind OpenGL (ES) API");
        return false;
    }

    std::vector<EGLint> frameBufferAttribs;
    frameBufferAttribs.push_back(EGL_RENDERABLE_TYPE);
    if (eglApi == EGL_OPENGL_API)
    {
        frameBufferAttribs.push_back(EGL_OPENGL_BIT);
    } else {
        switch (static_cast<int>(glesVersion_) / 10)
        {
        case 3:
            frameBufferAttribs.push_back(EGL_OPENGL_ES3_BIT);
            break;
        case 2:
            frameBufferAttribs.push_back(EGL_OPENGL_ES2_BIT);
            break;
        default:
            frameBufferAttribs.push_back(EGL_OPENGL_ES_BIT);
        }
    }

    frameBufferAttribs.push_back(EGL_SURFACE_TYPE);
    switch (surfaceType_)
    {
    case RCI_SURFACE_TYPE::NONE:
        frameBufferAttribs.push_back(EGL_DONT_CARE);
        break;
    case RCI_SURFACE_TYPE::PBUFFER:
        frameBufferAttribs.push_back(EGL_PBUFFER_BIT);
        break;
    case RCI_SURFACE_TYPE::PIXMAP:
        frameBufferAttribs.push_back(EGL_PIXMAP_BIT);
        break;
    case RCI_SURFACE_TYPE::WINDOW:
        frameBufferAttribs.push_back(EGL_WINDOW_BIT);
        break;
    }

    if (pixelFormat_.redBits != -1)
    {
        frameBufferAttribs.push_back(EGL_RED_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.redBits);
    }
    if (pixelFormat_.greenBits != -1)
    {
        frameBufferAttribs.push_back(EGL_GREEN_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.greenBits);
    }
    if (pixelFormat_.blueBits != -1)
    {
        frameBufferAttribs.push_back(EGL_BLUE_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.blueBits);
    }
    if (pixelFormat_.alphaBits != -1)
    {
        frameBufferAttribs.push_back(EGL_ALPHA_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.alphaBits);
    }
    if (pixelFormat_.depthBits != -1)
    {
        frameBufferAttribs.push_back(EGL_DEPTH_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.depthBits);
    }
    if (pixelFormat_.stencilBits != -1)
    {
        frameBufferAttribs.push_back(EGL_STENCIL_SIZE);
        frameBufferAttribs.push_back(pixelFormat_.stencilBits);
    }
    if (pixelFormat_.numSamples != -1)
    {
        frameBufferAttribs.push_back(EGL_SAMPLES);
        frameBufferAttribs.push_back(pixelFormat_.numSamples);
    }
    frameBufferAttribs.push_back(EGL_NONE);

    unsigned int ret;
    EGLint count;
    ret = eglChooseConfig(eglDisplay_, &frameBufferAttribs[0], &config_, 1, &count);
    printf("ret=%d,count=%d\n", ret, count);
    if (!(ret && static_cast<unsigned int>(count) >= 1))
    {
        printf("Failed to eglChooseConfig\n");
        return false;
    }
    EGLint red, green, blue, alpha, depth, stencil, samples;
    eglGetConfigAttrib(eglDisplay_, config_, EGL_RED_SIZE, &red);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_GREEN_SIZE, &green);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_BLUE_SIZE, &blue);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_ALPHA_SIZE, &alpha);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_DEPTH_SIZE, &depth);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_STENCIL_SIZE, &stencil);
    eglGetConfigAttrib(eglDisplay_, config_, EGL_SAMPLES, &samples);
    ShowConfig(config_);
    if (pixelFormat_.redBits == -1)
    {
        pixelFormat_.redBits = red;
    }
    else if (pixelFormat_.redBits != red)
    {
        printf("Failed to eglChooseConfig redBits %d != %d\n", pixelFormat_.redBits, red);
        return false;
    }

    if (pixelFormat_.greenBits == -1)
    {
        pixelFormat_.greenBits = green;
    }
    else if (pixelFormat_.greenBits != green)
    {
        printf("Failed to eglChooseConfig redBits %d != %d\n", pixelFormat_.greenBits, green);
        return false;
    }

    if (pixelFormat_.blueBits != blue)
    {
        if (pixelFormat_.blueBits != -1)
            printf("Failed to eglChooseConfig blueBits %d != %d\n", pixelFormat_.blueBits, blue);
        pixelFormat_.blueBits = blue;
    }

    if (pixelFormat_.alphaBits != alpha)
    {
        if (pixelFormat_.alphaBits != -1)
            printf("Failed to eglChooseConfig alphaBits %d != %d\n", pixelFormat_.alphaBits, alpha);
        pixelFormat_.alphaBits = alpha;
    }

    if (pixelFormat_.depthBits != depth)
    {
        if (pixelFormat_.depthBits != -1)
            printf("Failed to eglChooseConfig depthBits %d != %d\n", pixelFormat_.depthBits, depth);
        pixelFormat_.depthBits = depth;
    }

    if (pixelFormat_.stencilBits != stencil)
    {
        if (pixelFormat_.stencilBits != -1)
            printf("Failed to eglChooseConfig stencilBits %d != %d\n", pixelFormat_.stencilBits, stencil);
        pixelFormat_.stencilBits = stencil;
    }

    if (pixelFormat_.numSamples != samples)
    {
        if (pixelFormat_.numSamples != -1)
            printf("Failed to eglChooseConfig numSamples %d != %d\n", pixelFormat_.numSamples, samples);
        pixelFormat_.numSamples = samples;
    }
    printf("config ok\n");
    return true;
}

bool RosenContextImpl::InitNativeWindow()
{
    if (nativeWindow_ == nullptr)
    {
        nativeWindow_ = CreateNativeWindowFromSurface(&producer_);
    }
    NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY, width_, height_);
    if (pixelFormat_.stencilBits != -1)
    {
        NativeWindowHandleOpt(nativeWindow_, SET_STRIDE, pixelFormat_.stencilBits);
    }
    if (pixelFormat_.redBits == 8 && pixelFormat_.greenBits == 8 && pixelFormat_.blueBits == 8 && pixelFormat_.alphaBits == 8)
    {
        NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGBA_8888);
        // NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, PIXEL_FMT_RGBA_8888);
    }
    else if (pixelFormat_.redBits == 5 && pixelFormat_.greenBits == 6 && pixelFormat_.blueBits == 5 && pixelFormat_.alphaBits == 0)
    {
        NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGB_565);
        // NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, PIXEL_FMT_RGB_565);
    }
    else if (pixelFormat_.redBits == 4 && pixelFormat_.greenBits == 4 && pixelFormat_.blueBits == 4 && pixelFormat_.alphaBits == 4)
    {
        NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGBA_4444);
        // NativeWindowHandleOpt(nativeWindow_, SET_FORMAT, PIXEL_FMT_RGBA_4444);
    }
    printf("native window ok\n");
    return true;
}

bool RosenContextImpl::InitEglSurface()
{
    if (eglSurface_ != EGL_NO_SURFACE)
    {
        eglDestroySurface(eglDisplay_, eglSurface_);
        eglSurface_ = EGL_NO_SURFACE;
    }

    eglMakeCurrent(eglDisplay_, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

    std::vector<EGLint> surfaceAttribs;

    switch (surfaceType_)
    {
    case RCI_SURFACE_TYPE::NONE:
        break;
    case RCI_SURFACE_TYPE::WINDOW:
        // surfaceAttribs.push_back(EGL_GL_COLORSPACE_KHR);
        // TODO: EGL_GL_COLORSPACE_LINEAR_KHR, EGL_GL_COLORSPACE_SRGB_KHR
        // surfaceAttribs.push_back(EGL_GL_COLORSPACE_LINEAR_KHR);
        surfaceAttribs.push_back(EGL_NONE);

        eglSurface_ = eglCreateWindowSurface(eglDisplay_, config_, nativeWindow_, &surfaceAttribs[0]);
        if (eglSurface_ == EGL_NO_SURFACE)
        {
            printf("Failed to create eglsurface!!! %x\n", eglGetError());
            return false;
        }
        break;
    case RCI_SURFACE_TYPE::PBUFFER:
    case RCI_SURFACE_TYPE::PIXMAP:
        surfaceAttribs.push_back(EGL_WIDTH);
        surfaceAttribs.push_back(width_);
        surfaceAttribs.push_back(EGL_HEIGHT);
        surfaceAttribs.push_back(height_);
        surfaceAttribs.push_back(EGL_NONE);
        break;
    }
    printf("egl surface ok\n");
    return true;
}

bool RosenContextImpl::InitEglContext()
{
    if (eglContext_ != EGL_NO_CONTEXT)
    {
        eglDestroyContext(eglDisplay_, eglContext_);
        eglContext_ = EGL_NO_CONTEXT;
    }

    std::vector<EGLint> contextAttribs;
    contextAttribs.push_back(EGL_CONTEXT_MAJOR_VERSION_KHR);
    contextAttribs.push_back(static_cast<int>(glesVersion_) / 10);
    contextAttribs.push_back(EGL_CONTEXT_MINOR_VERSION_KHR);
    contextAttribs.push_back(static_cast<int>(glesVersion_) % 10);

    switch (typeProfile_)
    {
    case RCI_PROFILE::ES:
        break;
    case RCI_PROFILE::CORE:
        contextAttribs.push_back(EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR);
        contextAttribs.push_back(EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR);
        break;
    case RCI_PROFILE::COMPATIBILITY:
        contextAttribs.push_back(EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR);
        contextAttribs.push_back(EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR);
        break;
    }

    EGLint flags = 0;
    if ((static_cast<int>(contextFlags_) & static_cast<int>(RCI_CONTEXT_FLAG::DEBUG)) != 0)
        flags |= EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR;

    if ((static_cast<int>(contextFlags_) & static_cast<int>(RCI_CONTEXT_FLAG::ROBUST)) != 0)
        flags |= EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT_KHR;

    if ((static_cast<int>(contextFlags_) & static_cast<int>(RCI_CONTEXT_FLAG::FORWARD_COMPATIBLE)) != 0)
        flags |= EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR;

    contextAttribs.push_back(EGL_CONTEXT_FLAGS_KHR);
    contextAttribs.push_back(flags);

    contextAttribs.push_back(EGL_NONE);

    eglContext_ = eglCreateContext(eglDisplay_, config_, EGL_NO_CONTEXT, &contextAttribs[0]);
    if (eglContext_ == EGL_NO_CONTEXT)
    {
        printf("Failed to create egl context %x\n", eglGetError());
        return false;
    }
    printf("context ok\n");
    return true;
}

void RosenContextImpl::MakeCurrent()
{
    if (!eglMakeCurrent(eglDisplay_, eglSurface_, eglSurface_, eglContext_))
    {
        printf("eglMakeCurrent FAIL\n");
    }
}

void RosenContextImpl::SwapBuffer()
{
    eglSwapBuffers(eglDisplay_, eglSurface_);
    RSTransactionProxy::GetInstance()->FlushImplicitTransaction();
}

int32_t RosenContextImpl::GetAttrib(int32_t attrType)
{
    int32_t ret;
    eglGetConfigAttrib(eglDisplay_, config_, attrType, &ret);
    return ret;
}

uint64_t RosenContextImpl::CreateWindow(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
    static uint64_t windowId = 1;
    uint64_t wid = windowId++;

    // printf("impl create window %llu\n",wid);
    if (displayNode_ == nullptr)
    {
        displayNode_ = RSDisplayNode::Create(RSDisplayNodeConfig());
    }
    vulkanWindows_[wid].surfaceNode_ = RSSurfaceNode::Create(RSSurfaceNodeConfig());
    vulkanWindows_[wid].surfaceNode_->SetBounds(x, y, width, height);
    displayNode_->AddChild(vulkanWindows_[wid].surfaceNode_, -1);

    std::shared_ptr<RSSurface> rsSurface = RSSurfaceExtractor::ExtractRSSurface(vulkanWindows_[wid].surfaceNode_);
    std::shared_ptr<RSSurfaceOhosGl> rsSurfaceOhosGl = std::static_pointer_cast<RSSurfaceOhosGl>(rsSurface);
    vulkanWindows_[wid].producer_ = rsSurfaceOhosGl->GetSurface();

    vulkanWindows_[wid].nativeWindow_ = CreateNativeWindowFromSurface(&vulkanWindows_[wid].producer_);
    NativeWindowHandleOpt(vulkanWindows_[wid].nativeWindow_, SET_BUFFER_GEOMETRY, width, height);

    return wid;
}

void *RosenContextImpl::GetNativeWindow(uint64_t windowId)
{
    // printf("impl get native window %llu\n",windowId);
    return vulkanWindows_[windowId].nativeWindow_;
}

void RosenContextImpl::DestoryWindow(uint64_t windowId)
{
    // printf("impl destory window %llu\n",windowId);
    displayNode_->RemoveChild(vulkanWindows_[windowId].surfaceNode_);
    vulkanWindows_.erase(windowId);
}

void RosenContextImpl::OhosWindowResize(int32_t w, int32_t h)
{
    printf("RosenContextImpl::OhosWindowResize %d %d\n", w, h);
    width_ = w;
    height_ = h;
}

void *RosenContextImpl::GetNativeWindowEx()
{
    printf("RosenContextImpl::GetNativeWindowEx\n");
    if (nativeWindow_ == nullptr)
    {
        nativeWindow_ = CreateNativeWindowFromSurface(&producer_);
    }
    if (width_ > 0 && height_ > 0)
    {
        NativeWindowHandleOpt(nativeWindow_, SET_BUFFER_GEOMETRY, width_, height_);
    }

    return nativeWindow_;
}

// implemented2_BEGIN
uint32_t RosenContextImpl::OH_bindAPI(uint32_t api)
{
    auto ret = eglBindAPI(api);
    // std::cout<<" ! bindAPI("<<"api="<<api<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_bindTexImage(void* dpy, void* surface, int32_t buffer)
{
    auto ret = eglBindTexImage(dpy, surface, buffer);
    // std::cout<<" ! bindTexImage("<<"dpy="<<dpy<<", "<<"surface="<<surface<<", "<<"buffer="<<buffer<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_chooseConfig(void* dpy, const int32_t *attrib_list, void* *configs, int32_t config_size, int32_t *num_config)
{
    auto ret = eglChooseConfig(dpy, attrib_list, configs, config_size, num_config);
    // std::cout<<" ! chooseConfig("<<"dpy="<<dpy<<", "<<"attrib_list="<<attrib_list<<", "<<"configs="<<configs<<", "<<"config_size="<<config_size<<", "<<"num_config="<<num_config<<")" << "=" << ret << std::endl;
    return ret;
}

int32_t RosenContextImpl::OH_clientWaitSync(void* dpy, void* sync, int32_t flags, uint64_t timeout)
{
    auto ret = eglClientWaitSync(dpy, sync, flags, timeout);
    // std::cout<<" ! clientWaitSync("<<"dpy="<<dpy<<", "<<"sync="<<sync<<", "<<"flags="<<flags<<", "<<"timeout="<<timeout<<")" << "=" << ret << std::endl;
    return ret;
}

int32_t RosenContextImpl::OH_clientWaitSyncKHR(void* dpy, void* sync, int32_t flags, uint64_t timeout)
{
    printf("eglClientWaitSyncKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_copyBuffers(void* dpy, void* surface, void* target)
{
    auto ret = eglCopyBuffers(dpy, surface, target);
    // std::cout<<" ! copyBuffers("<<"dpy="<<dpy<<", "<<"surface="<<surface<<", "<<"target="<<target<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createContext(void* dpy, void* config, void* share_context, const int32_t *attrib_list)
{
    auto ret = eglCreateContext(dpy, config, share_context, attrib_list);
    // std::cout<<" ! createContext("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"share_context="<<share_context<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createImage(void* dpy, void* ctx, uint32_t target, void* buffer, const int *attrib_list)
{
    auto ret = eglCreateImage(dpy, ctx, target, buffer, reinterpret_cast<const EGLAttrib *>(attrib_list));
    // std::cout<<" ! createImage("<<"dpy="<<dpy<<", "<<"ctx="<<ctx<<", "<<"target="<<target<<", "<<"buffer="<<buffer<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createImageKHR(void* dpy, void* ctx, uint32_t target, void* buffer, const int32_t *attrib_list)
{
    printf("eglCreateImageKHR is not declared\n");
    return 0;
}

void* RosenContextImpl::OH_createPbufferFromClientBuffer(void* dpy, uint32_t buftype, void* buffer, void* config, const int32_t *attrib_list)
{
    auto ret = eglCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
    // std::cout<<" ! createPbufferFromClientBuffer("<<"dpy="<<dpy<<", "<<"buftype="<<buftype<<", "<<"buffer="<<buffer<<", "<<"config="<<config<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createPbufferSurface(void* dpy, void* config, const int32_t *attrib_list)
{
    auto ret = eglCreatePbufferSurface(dpy, config, attrib_list);
    // std::cout<<" ! createPbufferSurface("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createPixmapSurface(void* dpy, void* config, void* pixmap, const int32_t *attrib_list)
{
    auto ret = eglCreatePixmapSurface(dpy, config, pixmap, attrib_list);
    // std::cout<<" ! createPixmapSurface("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"pixmap="<<pixmap<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createPlatformPixmapSurface(void* dpy, void* config, void *native_pixmap, const int *attrib_list)
{
    auto ret = eglCreatePlatformPixmapSurface(dpy, config, native_pixmap, reinterpret_cast<const EGLAttrib *>(attrib_list));
    // std::cout<<" ! createPlatformPixmapSurface("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"native_pixmap="<<native_pixmap<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createPlatformPixmapSurfaceEXT(void* dpy, void* config, void *native_pixmap, const int32_t *attrib_list)
{
    printf("eglCreatePlatformPixmapSurfaceEXT is not declared\n");
    return 0;
}

void* RosenContextImpl::OH_createPlatformWindowSurface(void* dpy, void* config, void *native_window, const int *attrib_list)
{
    auto ret = eglCreatePlatformWindowSurface(dpy, config, native_window, reinterpret_cast<const EGLAttrib *>(attrib_list));
    // std::cout<<" ! createPlatformWindowSurface("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"native_window="<<native_window<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createPlatformWindowSurfaceEXT(void* dpy, void* config, void *native_window, const int32_t *attrib_list)
{
    printf("eglCreatePlatformWindowSurfaceEXT is not declared\n");
    return 0;
}

void* RosenContextImpl::OH_createSync(void* dpy, uint32_t type, const int *attrib_list)
{
    auto ret = eglCreateSync(dpy, type, reinterpret_cast<const EGLAttrib *>(attrib_list));
    // std::cout<<" ! createSync("<<"dpy="<<dpy<<", "<<"type="<<type<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_createSyncKHR(void* dpy, uint32_t type, const int32_t *attrib_list)
{
    printf("eglCreateSyncKHR is not declared\n");
    return 0;
}

void* RosenContextImpl::OH_createWindowSurface(void* dpy, void* config, void* win, const int32_t *attrib_list)
{
    EGLint red, green, blue, alpha, stencil;
    eglGetConfigAttrib(dpy, config, EGL_RED_SIZE, &red);
    eglGetConfigAttrib(dpy, config, EGL_GREEN_SIZE, &green);
    eglGetConfigAttrib(dpy, config, EGL_BLUE_SIZE, &blue);
    eglGetConfigAttrib(dpy, config, EGL_ALPHA_SIZE, &alpha);
    eglGetConfigAttrib(dpy, config, EGL_STENCIL_SIZE, &stencil);

    NativeWindowHandleOpt(nativeWindow_, SET_STRIDE, stencil);
    if (red == 8 && green == 8 && blue == 8 && alpha == 8)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGBA_8888);
    }
    else if (red == 8 && green == 8 && blue == 8 && alpha == 0)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGB_888);
    }
    else if (red == 5 && green == 6 && blue == 5 && alpha == 8)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGBA_5658);
    }
    else if (red == 5 && green == 6 && blue == 5 && alpha == 0)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGB_565);
    }
    else if (red == 4 && green == 4 && blue == 4 && alpha == 4)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGBA_4444);
    }
    else if (red == 4 && green == 4 && blue == 4 && alpha == 0)
    {
        NativeWindowHandleOpt((OHNativeWindow *)win, SET_FORMAT, GRAPHIC_PIXEL_FMT_RGB_444);
    }
    else
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    auto ret = eglCreateWindowSurface(dpy, config, (NativeWindow *)win, attrib_list);
    // std::cout<<" ! createWindowSurface("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"win="<<win<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_destroyContext(void* dpy, void* ctx)
{
    auto ret = eglDestroyContext(dpy, ctx);
    // std::cout<<" ! destroyContext("<<"dpy="<<dpy<<", "<<"ctx="<<ctx<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_destroyImage(void* dpy, void* image)
{
    auto ret = eglDestroyImage(dpy, image);
    // std::cout<<" ! destroyImage("<<"dpy="<<dpy<<", "<<"image="<<image<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_destroyImageKHR(void* dpy, void* image)
{
    printf("eglDestroyImageKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_destroySurface(void* dpy, void* surface)
{
    auto ret = eglDestroySurface(dpy, surface);
    // std::cout<<" ! destroySurface("<<"dpy="<<dpy<<", "<<"surface="<<surface<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_destroySync(void* dpy, void* sync)
{
    auto ret = eglDestroySync(dpy, sync);
    // std::cout<<" ! destroySync("<<"dpy="<<dpy<<", "<<"sync="<<sync<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_destroySyncKHR(void* dpy, void* sync)
{
    printf("eglDestroySyncKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_getConfigAttrib(void* dpy, void* config, int32_t attribute, int32_t *value)
{
    auto ret = eglGetConfigAttrib(dpy, config, attribute, value);
    // std::cout<<" ! getConfigAttrib("<<"dpy="<<dpy<<", "<<"config="<<config<<", "<<"attribute="<<attribute<<", "<<"value="<<value<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_getConfigs(void* dpy, void* *configs, int32_t config_size, int32_t *num_config)
{
    auto ret = eglGetConfigs(dpy, configs, config_size, num_config);
    // std::cout<<" ! getConfigs("<<"dpy="<<dpy<<", "<<"configs="<<configs<<", "<<"config_size="<<config_size<<", "<<"num_config="<<num_config<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getCurrentContext()
{
    auto ret = eglGetCurrentContext();
    // std::cout<<" ! getCurrentContext("<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getCurrentDisplay()
{
    auto ret = eglGetCurrentDisplay();
    // std::cout<<" ! getCurrentDisplay("<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getCurrentSurface(int32_t readdraw)
{
    auto ret = eglGetCurrentSurface(readdraw);
    // std::cout<<" ! getCurrentSurface("<<"readdraw="<<readdraw<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getDisplay(void* display_id)
{
    auto ret = eglGetDisplay(display_id);
    // std::cout<<" ! getDisplay("<<"display_id="<<display_id<<")" << "=" << ret << std::endl;
    return ret;
}

int32_t RosenContextImpl::OH_getError()
{
    auto ret = eglGetError();
    // std::cout<<" ! getError("<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getPlatformDisplay(uint32_t platform, void *native_display, const int *attrib_list)
{
    auto ret = eglGetPlatformDisplay(platform, native_display, reinterpret_cast<const EGLAttrib *>(attrib_list));
    // std::cout<<" ! getPlatformDisplay("<<"platform="<<platform<<", "<<"native_display="<<native_display<<", "<<"attrib_list="<<attrib_list<<")" << "=" << ret << std::endl;
    return ret;
}

void* RosenContextImpl::OH_getPlatformDisplayEXT(uint32_t platform, void *native_display, const int32_t *attrib_list)
{
    printf("eglGetPlatformDisplayEXT is not declared\n");
    return 0;
}

FunctionPointer RosenContextImpl::OH_getProcAddress(const char *procname)
{
    auto ret = eglGetProcAddress(procname);
    // std::cout<<" ! getProcAddress("<<"procname="<<procname<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_getSyncAttrib(void* dpy, void* sync, int32_t attribute, int *value)
{
    auto ret = eglGetSyncAttrib(dpy, sync, attribute, reinterpret_cast<EGLAttrib *>(value));
    // std::cout<<" ! getSyncAttrib("<<"dpy="<<dpy<<", "<<"sync="<<sync<<", "<<"attribute="<<attribute<<", "<<"value="<<value<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_getSyncAttribKHR(void* dpy, void* sync, int32_t attribute, int32_t *value)
{
    printf("eglGetSyncAttribKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_initialize(void* dpy, int32_t *major, int32_t *minor)
{
    auto ret = eglInitialize(dpy, major, minor);
    // std::cout<<" ! initialize("<<"dpy="<<dpy<<", "<<"major="<<major<<", "<<"minor="<<minor<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_lockSurfaceKHR(void* dpy, void* surface, const int32_t *attrib_list)
{
    printf("eglLockSurfaceKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_makeCurrent(void* dpy, void* draw, void* read, void* ctx)
{
    auto ret = eglMakeCurrent(dpy, draw, read, ctx);
    // std::cout<<" ! makeCurrent("<<"dpy="<<dpy<<", "<<"draw="<<draw<<", "<<"read="<<read<<", "<<"ctx="<<ctx<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_queryAPI()
{
    auto ret = eglQueryAPI();
    // std::cout<<" ! queryAPI("<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_queryContext(void* dpy, void* ctx, int32_t attribute, int32_t *value)
{
    auto ret = eglQueryContext(dpy, ctx, attribute, value);
    // std::cout<<" ! queryContext("<<"dpy="<<dpy<<", "<<"ctx="<<ctx<<", "<<"attribute="<<attribute<<", "<<"value="<<value<<")" << "=" << ret << std::endl;
    return ret;
}

const char* RosenContextImpl::OH_queryString(void* dpy, int32_t name)
{
    auto ret = eglQueryString(dpy, name);
    // std::cout<<" ! queryString("<<"dpy="<<dpy<<", "<<"name="<<name<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_querySurface(void* dpy, void* surface, int32_t attribute, int32_t *value)
{
    auto ret = eglQuerySurface(dpy, surface, attribute, value);
    // std::cout<<" ! querySurface("<<"dpy="<<dpy<<", "<<"surface="<<surface<<", "<<"attribute="<<attribute<<", "<<"value="<<value<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_releaseTexImage(void* dpy, void* surface, int32_t buffer)
{
    auto ret = eglReleaseTexImage(dpy, surface, buffer);
    // std::cout<<" ! releaseTexImage("<<"dpy="<<dpy<<", "<<"surface="<<surface<<", "<<"buffer="<<buffer<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_releaseThread()
{
    auto ret = eglReleaseThread();
    // std::cout<<" ! releaseThread("<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_setDamageRegionKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects)
{
    printf("eglSetDamageRegionKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_signalSyncKHR(void* dpy, void* sync, uint32_t mode)
{
    printf("eglSignalSyncKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_surfaceAttrib(void* dpy, void* surface, int32_t attribute, int32_t value)
{
    auto ret = eglSurfaceAttrib(dpy, surface, attribute, value);
    // std::cout<<" ! surfaceAttrib("<<"dpy="<<dpy<<", "<<"surface="<<surface<<", "<<"attribute="<<attribute<<", "<<"value="<<value<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_swapBuffers(void* dpy, void* surface)
{
    auto ret = eglSwapBuffers(dpy, surface);
    // std::cout<<" ! swapBuffers("<<"dpy="<<dpy<<", "<<"surface="<<surface<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_swapBuffersWithDamageKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects)
{
    printf("eglSwapBuffersWithDamageKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_swapInterval(void* dpy, int32_t interval)
{
    auto ret = eglSwapInterval(dpy, interval);
    // std::cout<<" ! swapInterval("<<"dpy="<<dpy<<", "<<"interval="<<interval<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_terminate(void* dpy)
{
    auto ret = eglTerminate(dpy);
    // std::cout<<" ! terminate("<<"dpy="<<dpy<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_unlockSurfaceKHR(void* dpy, void* surface)
{
    printf("eglUnlockSurfaceKHR is not declared\n");
    return 0;
}

uint32_t RosenContextImpl::OH_waitClient()
{
    auto ret = eglWaitClient();
    // std::cout<<" ! waitClient("<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_waitGL()
{
    auto ret = eglWaitGL();
    // std::cout<<" ! waitGL("<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_waitNative(int32_t engine)
{
    auto ret = eglWaitNative(engine);
    // std::cout<<" ! waitNative("<<"engine="<<engine<<")" << "=" << ret << std::endl;
    return ret;
}

uint32_t RosenContextImpl::OH_waitSync(void* dpy, void* sync, int32_t flags)
{
    auto ret = eglWaitSync(dpy, sync, flags);
    // std::cout<<" ! waitSync("<<"dpy="<<dpy<<", "<<"sync="<<sync<<", "<<"flags="<<flags<<")" << "=" << ret << std::endl;
    return ret;
}

int32_t RosenContextImpl::OH_waitSyncKHR(void* dpy, void* sync, int32_t flags)
{
    printf("eglWaitSyncKHR is not declared\n");
    return 0;
}

// implemented2_END