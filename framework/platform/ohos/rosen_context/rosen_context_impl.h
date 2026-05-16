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

#ifndef _ROSEN_CONTEXT_IMPL_H_
#define _ROSEN_CONTEXT_IMPL_H_

#include <map>

#include "ohos_context_i.h"

#include "ui/rs_display_node.h"
#include "ui/rs_surface_node.h"

#include "EGL/egl.h"
#include "EGL/eglext.h"
#include "GLES3/gl32.h"

namespace OHOS {
namespace Rosen {

class RosenContextImpl : public OHOS::OhosContextI {
public:
    RosenContextImpl();

    bool SetConfig(int32_t w,int32_t h,RCI_GLES_VERSION ver,RCI_PIXEL_FORMAT pf,RCI_SURFACE_TYPE st,RCI_PROFILE tp,RCI_CONTEXT_FLAG flags) override;
    bool InitNativeWindow() override;
    bool InitEglSurface() override;
    bool InitEglContext() override;

    void MakeCurrent() override;
    void SwapBuffer() override;

    int32_t GetAttrib(int32_t attrType) override;

    uint64_t CreateWindow(uint32_t x,uint32_t y,uint32_t width,uint32_t height) override;
    void *GetNativeWindow(uint64_t windowId) override;
    void DestoryWindow(uint64_t windowId) override;

    void *GetNativeWindowEx() override;
    void OhosWindowResize(int32_t w,int32_t h) override;
    void* EglGetConfig() override { return config_;}

// implemented1_BEGIN
    uint32_t OH_bindAPI(uint32_t api) override;
    uint32_t OH_bindTexImage(void* dpy, void* surface, int32_t buffer) override;
    uint32_t OH_chooseConfig(void* dpy, const int32_t *attrib_list, void* *configs, int32_t config_size, int32_t *num_config) override;
    int32_t OH_clientWaitSync(void* dpy, void* sync, int32_t flags, uint64_t timeout) override;
    int32_t OH_clientWaitSyncKHR(void* dpy, void* sync, int32_t flags, uint64_t timeout) override;
    uint32_t OH_copyBuffers(void* dpy, void* surface, void* target) override;
    void* OH_createContext(void* dpy, void* config, void* share_context, const int32_t *attrib_list) override;
    void* OH_createImage(void* dpy, void* ctx, uint32_t target, void* buffer, const int *attrib_list) override;
    void* OH_createImageKHR(void* dpy, void* ctx, uint32_t target, void* buffer, const int32_t *attrib_list) override;
    void* OH_createPbufferFromClientBuffer(void* dpy, uint32_t buftype, void* buffer, void* config, const int32_t *attrib_list) override;
    void* OH_createPbufferSurface(void* dpy, void* config, const int32_t *attrib_list) override;
    void* OH_createPixmapSurface(void* dpy, void* config, void* pixmap, const int32_t *attrib_list) override;
    void* OH_createPlatformPixmapSurface(void* dpy, void* config, void *native_pixmap, const int *attrib_list) override;
    void* OH_createPlatformPixmapSurfaceEXT(void* dpy, void* config, void *native_pixmap, const int32_t *attrib_list) override;
    void* OH_createPlatformWindowSurface(void* dpy, void* config, void *native_window, const int *attrib_list) override;
    void* OH_createPlatformWindowSurfaceEXT(void* dpy, void* config, void *native_window, const int32_t *attrib_list) override;
    void* OH_createSync(void* dpy, uint32_t type, const int *attrib_list) override;
    void* OH_createSyncKHR(void* dpy, uint32_t type, const int32_t *attrib_list) override;
    void* OH_createWindowSurface(void* dpy, void* config, void* win, const int32_t *attrib_list) override;
    uint32_t OH_destroyContext(void* dpy, void* ctx) override;
    uint32_t OH_destroyImage(void* dpy, void* image) override;
    uint32_t OH_destroyImageKHR(void* dpy, void* image) override;
    uint32_t OH_destroySurface(void* dpy, void* surface) override;
    uint32_t OH_destroySync(void* dpy, void* sync) override;
    uint32_t OH_destroySyncKHR(void* dpy, void* sync) override;
    uint32_t OH_getConfigAttrib(void* dpy, void* config, int32_t attribute, int32_t *value) override;
    uint32_t OH_getConfigs(void* dpy, void* *configs, int32_t config_size, int32_t *num_config) override;
    void* OH_getCurrentContext() override;
    void* OH_getCurrentDisplay() override;
    void* OH_getCurrentSurface(int32_t readdraw) override;
    void* OH_getDisplay(void* display_id) override;
    int32_t OH_getError() override;
    void* OH_getPlatformDisplay(uint32_t platform, void *native_display, const int *attrib_list) override;
    void* OH_getPlatformDisplayEXT(uint32_t platform, void *native_display, const int32_t *attrib_list) override;
    FunctionPointer OH_getProcAddress(const char *procname) override;
    uint32_t OH_getSyncAttrib(void* dpy, void* sync, int32_t attribute, int *value) override;
    uint32_t OH_getSyncAttribKHR(void* dpy, void* sync, int32_t attribute, int32_t *value) override;
    uint32_t OH_initialize(void* dpy, int32_t *major, int32_t *minor) override;
    uint32_t OH_lockSurfaceKHR(void* dpy, void* surface, const int32_t *attrib_list) override;
    uint32_t OH_makeCurrent(void* dpy, void* draw, void* read, void* ctx) override;
    uint32_t OH_queryAPI() override;
    uint32_t OH_queryContext(void* dpy, void* ctx, int32_t attribute, int32_t *value) override;
    const char* OH_queryString(void* dpy, int32_t name) override;
    uint32_t OH_querySurface(void* dpy, void* surface, int32_t attribute, int32_t *value) override;
    uint32_t OH_releaseTexImage(void* dpy, void* surface, int32_t buffer) override;
    uint32_t OH_releaseThread() override;
    uint32_t OH_setDamageRegionKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects) override;
    uint32_t OH_signalSyncKHR(void* dpy, void* sync, uint32_t mode) override;
    uint32_t OH_surfaceAttrib(void* dpy, void* surface, int32_t attribute, int32_t value) override;
    uint32_t OH_swapBuffers(void* dpy, void* surface) override;
    uint32_t OH_swapBuffersWithDamageKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects) override;
    uint32_t OH_swapInterval(void* dpy, int32_t interval) override;
    uint32_t OH_terminate(void* dpy) override;
    uint32_t OH_unlockSurfaceKHR(void* dpy, void* surface) override;
    uint32_t OH_waitClient() override;
    uint32_t OH_waitGL() override;
    uint32_t OH_waitNative(int32_t engine) override;
    uint32_t OH_waitSync(void* dpy, void* sync, int32_t flags) override;
    int32_t OH_waitSyncKHR(void* dpy, void* sync, int32_t flags) override;
    static bool CheckIfNeedOpengl();
// implemented1_END

private:
    void InitProducer();
    bool InitEgl();
    void ShowConfig(EGLConfig cfg);

    RCI_GLES_VERSION glesVersion_;
    RCI_PROFILE typeProfile_;
    RCI_CONTEXT_FLAG contextFlags_;
    RCI_SURFACE_TYPE surfaceType_;
    int32_t width_;
    int32_t height_;
    RCI_PIXEL_FORMAT pixelFormat_;
    EGLConfig *allConfigs_;
    EGLint configCount_;

    RSDisplayNode::SharedPtr displayNode_ = nullptr;
    std::shared_ptr<RSSurfaceNode> surfaceNode_;
    sptr<Surface> producer_;

    EGLDisplay eglDisplay_;

    EGLConfig config_;

    struct NativeWindow* nativeWindow_ = nullptr;

    EGLSurface eglSurface_ = EGL_NO_SURFACE;

    EGLContext eglContext_ = EGL_NO_CONTEXT;
    bool eglInited_ = false;


    struct VulkanWindows {
        std::shared_ptr<RSSurfaceNode> surfaceNode_;
        sptr<Surface> producer_;
        struct NativeWindow* nativeWindow_;
    };
    std::map<uint64_t,struct VulkanWindows> vulkanWindows_;
};

}
}

#endif
