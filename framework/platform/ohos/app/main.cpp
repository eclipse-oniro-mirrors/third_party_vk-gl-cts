/*
 * Copyright (c) 2025 Shenzhen Kaihong Digital Industry Development Co., Ltd.
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

#include <stdio.h>

#include "app_main.h"

#include "ohos_context_i.h"

namespace OHOS
{
    class AppContext : public OHOS::OhosContextI
    {
    public:
        AppContext() {}
        bool SetConfig(int32_t w, int32_t h, RCI_GLES_VERSION ver, RCI_PIXEL_FORMAT pf, RCI_SURFACE_TYPE st, RCI_PROFILE tp, RCI_CONTEXT_FLAG flags) override;
        bool InitNativeWindow() override;
        bool InitEglSurface() override;
        bool InitEglContext() override;

        void MakeCurrent() override;
        void SwapBuffer() override;

        int32_t GetAttrib(int32_t attrType) override;

        uint64_t CreateWindow(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        void *GetNativeWindow(uint64_t windowId) override;
        void DestoryWindow(uint64_t windowId) override;


        void *GetNativeWindowEx() override;
        void OhosWindowResize(int32_t w,int32_t h) override;
        void* EglGetConfig() override;

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
    };
    bool AppContext::SetConfig(int32_t w, int32_t h, RCI_GLES_VERSION ver, RCI_PIXEL_FORMAT pf, RCI_SURFACE_TYPE st, RCI_PROFILE tp, RCI_CONTEXT_FLAG flags)
    {
        printf("!!!!!!!!!!!!!!!!!!!!!!SetConfig\n");
        printf("%d,%d,%d,%d,%d,%d,%d\n",w,h,ver,pf.redBits,st,tp,flags);
        return true;
    }
    bool AppContext::InitNativeWindow()
    {
        return true;
    }
    bool AppContext::InitEglSurface()
    {
        return true;
    }
    bool AppContext::InitEglContext()
    {
        return true;
    }
    void AppContext::MakeCurrent()
    {
    }
    void AppContext::SwapBuffer()
    {
    }
    int32_t AppContext::GetAttrib(int32_t attrType)
    {
        printf("attrType:%d\n",attrType);
        return 0;
    }
    uint64_t AppContext::CreateWindow(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        printf("x:%d,y:%d,width:%d,height:%d\n",x,y,width,height);
        return 0;
    }
    void *AppContext::GetNativeWindow(uint64_t windowId)
    {
        printf("windowId:%llu\n",windowId);
        return nullptr;
    }
    void AppContext::DestoryWindow(uint64_t windowId)
    {
        printf("windowId:%llu\n",windowId);
    }

    void *AppContext::GetNativeWindowEx()
    {
        return nullptr;
    }
    void AppContext::OhosWindowResize(int32_t w,int32_t h)
    {
        printf("w:%d,h:%d\n",w,h);
    }
    void* AppContext::EglGetConfig()
    {
        return nullptr;
    }

    uint32_t AppContext::OH_bindAPI(uint32_t api)
    {
        printf("api:%d\n",api);
        return 0;
    }
    uint32_t AppContext::OH_bindTexImage(void* dpy, void* surface, int32_t buffer)
    {
        printf("dpy:%p,surface:%p,buffer:%d\n",dpy,surface,buffer);
        return 0;
    }
    uint32_t AppContext::OH_chooseConfig(void* dpy, const int32_t *attrib_list, void* *configs, int32_t config_size, int32_t *num_config)
    {
        printf("dpy:%p,attrib_list:%p,configs:%p,config_size:%d,num_config:%p\n",dpy,attrib_list,configs,config_size,num_config);
        return 0;
    }
    int32_t AppContext::OH_clientWaitSync(void* dpy, void* sync, int32_t flags, uint64_t timeout)
    {
        printf("dpy:%p,sync:%p,flags:%d,timeout:%llu\n",dpy,sync,flags,timeout);
        return 0;
    }
    int32_t AppContext::OH_clientWaitSyncKHR(void* dpy, void* sync, int32_t flags, uint64_t timeout)
    {
        printf("dpy:%p,sync:%p,flags:%d,timeout:%llu\n",dpy,sync,flags,timeout);
        return 0;
    }
    uint32_t AppContext::OH_copyBuffers(void* dpy, void* surface, void* target)
    {
        printf("dpy:%p,surface:%p,target:%p\n",dpy,surface,target);
        return 0;
    }
    void* AppContext::OH_createContext(void* dpy, void* config, void* share_context, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,share_context:%p,attrib_list:%p\n",dpy,config,share_context,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createImage(void* dpy, void* ctx, uint32_t target, void* buffer, const int *attrib_list)
    {
        printf("dpy:%p,ctx:%p,target:%d,buffer:%p,attrib_list:%p\n",dpy,ctx,target,buffer,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createImageKHR(void* dpy, void* ctx, uint32_t target, void* buffer, const int32_t *attrib_list)
    {
        printf("dpy:%p,ctx:%p,target:%d,buffer:%p,attrib_list:%p\n",dpy,ctx,target,buffer,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPbufferFromClientBuffer(void* dpy, uint32_t buftype, void* buffer, void* config, const int32_t *attrib_list)
    {
        printf("dpy:%p,buftype:%d,buffer:%p,config:%p,attrib_list:%p\n",dpy,buftype,buffer,config,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPbufferSurface(void* dpy, void* config, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,attrib_list:%p\n",dpy,config,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPixmapSurface(void* dpy, void* config, void* pixmap, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,pixmap:%p,attrib_list:%p\n",dpy,config,pixmap,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPlatformPixmapSurface(void* dpy, void* config, void *native_pixmap, const int *attrib_list)
    {
        printf("dpy:%p,config:%p,native_pixmap:%p,attrib_list:%p\n",dpy,config,native_pixmap,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPlatformPixmapSurfaceEXT(void* dpy, void* config, void *native_pixmap, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,native_pixmap:%p,attrib_list:%p\n",dpy,config,native_pixmap,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPlatformWindowSurface(void* dpy, void* config, void *native_window, const int *attrib_list)
    {
        printf("dpy:%p,config:%p,native_window:%p,attrib_list:%p\n",dpy,config,native_window,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createPlatformWindowSurfaceEXT(void* dpy, void* config, void *native_window, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,native_window:%p,attrib_list:%p\n",dpy,config,native_window,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createSync(void* dpy, uint32_t type, const int *attrib_list)
    {
        printf("dpy:%p,type:%d,attrib_list:%p\n",dpy,type,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createSyncKHR(void* dpy, uint32_t type, const int32_t *attrib_list)
    {
        printf("dpy:%p,type:%d,attrib_list:%p\n",dpy,type,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_createWindowSurface(void* dpy, void* config, void* win, const int32_t *attrib_list)
    {
        printf("dpy:%p,config:%p,win:%p,attrib_list:%p\n",dpy,config,win,attrib_list);
        return nullptr;
    }
    uint32_t AppContext::OH_destroyContext(void* dpy, void* ctx)
    {
        printf("dpy:%p,ctx:%p\n",dpy,ctx);
        return 0;
    }
    uint32_t AppContext::OH_destroyImage(void* dpy, void* image)
    {
        printf("dpy:%p,image:%p\n",dpy,image);
        return 0;
    }
    uint32_t AppContext::OH_destroyImageKHR(void* dpy, void* image)
    {
        printf("dpy:%p,image:%p\n",dpy,image);
        return 0;
    }
    uint32_t AppContext::OH_destroySurface(void* dpy, void* surface)
    {
        printf("dpy:%p,surface:%p\n",dpy,surface);
        return 0;
    }
    uint32_t AppContext::OH_destroySync(void* dpy, void* sync)
    {
        printf("dpy:%p,sync:%p\n",dpy,sync);
        return 0;
    }
    uint32_t AppContext::OH_destroySyncKHR(void* dpy, void* sync)
    {
        printf("dpy:%p,sync:%p\n",dpy,sync);
        return 0;
    }
    uint32_t AppContext::OH_getConfigAttrib(void* dpy, void* config, int32_t attribute, int32_t *value)
    {
        printf("dpy:%p,config:%p,attribute:%d,value:%p\n",dpy,config,attribute,value);
        return 0;
    }
    uint32_t AppContext::OH_getConfigs(void* dpy, void* *configs, int32_t config_size, int32_t *num_config)
    {
        printf("dpy:%p,configs:%p,config_size:%d,num_config:%p\n",dpy,configs,config_size,num_config);
        return 0;
    }
    void* AppContext::OH_getCurrentContext()
    {
        printf("OH_getCurrentContext\n");
        return nullptr;
    }
    void* AppContext::OH_getCurrentDisplay()
    {
        printf("OH_getCurrentDisplay\n");
        return nullptr;
    }
    void* AppContext::OH_getCurrentSurface(int32_t readdraw)
    {
        printf("readdraw:%d\n",readdraw);
        return nullptr;
    }
    void* AppContext::OH_getDisplay(void* display_id)
    {
        printf("display_id:%p\n",display_id);
        return nullptr;
    }
    int32_t AppContext::OH_getError()
    {
        printf("OH_getError\n");
        return 0;
    }
    void* AppContext::OH_getPlatformDisplay(uint32_t platform, void *native_display, const int *attrib_list)
    {
        printf("platform:%d,native_display:%p,attrib_list:%p\n",platform,native_display,attrib_list);
        return nullptr;
    }
    void* AppContext::OH_getPlatformDisplayEXT(uint32_t platform, void *native_display, const int32_t *attrib_list)
    {
        printf("platform:%d,native_display:%p,attrib_list:%p\n",platform,native_display,attrib_list);
        return nullptr;
    }
    FunctionPointer AppContext::OH_getProcAddress(const char *procname)
    {
        printf("procname:%s\n",procname);
        return nullptr;
    }
    uint32_t AppContext::OH_getSyncAttrib(void* dpy, void* sync, int32_t attribute, int *value)
    {
        printf("dpy:%p,sync:%p,attribute:%d,value:%p\n",dpy,sync,attribute,value);
        return 0;
    }
    uint32_t AppContext::OH_getSyncAttribKHR(void* dpy, void* sync, int32_t attribute, int32_t *value)
    {
        printf("dpy:%p,sync:%p,attribute:%d,value:%p\n",dpy,sync,attribute,value);
        return 0;
    }
    uint32_t AppContext::OH_initialize(void* dpy, int32_t *major, int32_t *minor)
    {
        printf("dpy:%p,major:%p,minor:%p\n",dpy,major,minor);
        return 0;
    }
    uint32_t AppContext::OH_lockSurfaceKHR(void* dpy, void* surface, const int32_t *attrib_list)
    {
        printf("dpy:%p,surface:%p,attrib_list:%p\n",dpy,surface,attrib_list);
        return 0;
    }
    uint32_t AppContext::OH_makeCurrent(void* dpy, void* draw, void* read, void* ctx)
    {
        printf("dpy:%p,draw:%p,read:%p,ctx:%p\n",dpy,draw,read,ctx);
        return 0;
    }
    uint32_t AppContext::OH_queryAPI()
    {
        printf("OH_queryAPI\n");
        return 0;
    }
    uint32_t AppContext::OH_queryContext(void* dpy, void* ctx, int32_t attribute, int32_t *value)
    {
        printf("dpy:%p,ctx:%p,attribute:%d,value:%p\n",dpy,ctx,attribute,value);
        return 0;
    }
    const char* AppContext::OH_queryString(void* dpy, int32_t name)
    {
        printf("dpy:%p,name:%d\n",dpy,name);
        return nullptr;
    }
    uint32_t AppContext::OH_querySurface(void* dpy, void* surface, int32_t attribute, int32_t *value)
    {
        printf("dpy:%p,surface:%p,attribute:%d,value:%p\n",dpy,surface,attribute,value);
        return 0;
    }
    uint32_t AppContext::OH_releaseTexImage(void* dpy, void* surface, int32_t buffer)
    {
        printf("dpy:%p,surface:%p,buffer:%d\n",dpy,surface,buffer);
        return 0;
    }
    uint32_t AppContext::OH_releaseThread()
    {
        printf("OH_releaseThread\n");
        return 0;
    }
    uint32_t AppContext::OH_setDamageRegionKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects)
    {
        printf("dpy:%p,surface:%p,rects:%p,n_rects:%d\n",dpy,surface,rects,n_rects);
        return 0;
    }
    uint32_t AppContext::OH_signalSyncKHR(void* dpy, void* sync, uint32_t mode)
    {
        printf("dpy:%p,sync:%p,mode:%d\n",dpy,sync,mode);
        return 0;
    }
    uint32_t AppContext::OH_surfaceAttrib(void* dpy, void* surface, int32_t attribute, int32_t value)
    {
        printf("dpy:%p,surface:%p,attribute:%d,value:%d\n",dpy,surface,attribute,value);
        return 0;
    }
    uint32_t AppContext::OH_swapBuffers(void* dpy, void* surface)
    {
        printf("dpy:%p,surface:%p\n",dpy,surface);
        return 0;
    }
    uint32_t AppContext::OH_swapBuffersWithDamageKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects)
    {
        printf("dpy:%p,surface:%p,rects:%p,n_rects:%d\n",dpy,surface,rects,n_rects);
        return 0;
    }
    uint32_t AppContext::OH_swapInterval(void* dpy, int32_t interval)
    {
        printf("dpy:%p,interval:%d\n",dpy,interval);
        return 0;
    }
    uint32_t AppContext::OH_terminate(void* dpy)
    {
        printf("dpy:%p\n",dpy);
        return 0;
    }
    uint32_t AppContext::OH_unlockSurfaceKHR(void* dpy, void* surface)
    {
        printf("dpy:%p,surface:%p\n",dpy,surface);
        return 0;
    }
    uint32_t AppContext::OH_waitClient()
    {
        printf("OH_waitClient\n");
        return 0;
    }
    uint32_t AppContext::OH_waitGL()
    {
        printf("OH_waitGL\n");
        return 0;
    }
    uint32_t AppContext::OH_waitNative(int32_t engine)
    {
        printf("engine:%d\n",engine);
        return 0;
    }
    uint32_t AppContext::OH_waitSync(void* dpy, void* sync, int32_t flags)
    {
        printf("dpy:%p,sync:%p,flags:%d\n",dpy,sync,flags);
        return 0;
    }
    int32_t AppContext::OH_waitSyncKHR(void* dpy, void* sync, int32_t flags)
    {
        printf("dpy:%p,sync:%p,flags:%d\n",dpy,sync,flags);
        return 0;
    }
}

int main(int argc, char **argv)
{
    OHOS::AppContext appContext;
    OHOS::OhosContextI::SetInstance((void *)&appContext);
    // main1(argc, argv);
    // 构造argc和argv
    int32_t argCount = 1;
    char *argArray[1] = {"glcts"};
    // 调用main1函数
    main1(argCount, argArray);
    return 0;
}