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

#ifndef _ROSEN_CONTEXT_H_
#define _ROSEN_CONTEXT_H_

#include<stdint.h>

namespace OHOS {

enum class RCI_GLES_VERSION {
    V20 = 20,
    V30 = 30,
    V31 = 31,
    V32 = 32,
    V42 = 42
};

enum class RCI_PROFILE {
    ES = 0,
    CORE,
    COMPATIBILITY
};

enum class RCI_CONTEXT_FLAG
{
    NONE                = 0,
	ROBUST				= (1<<0),	//!< Robust context
	DEBUG				= (1<<1),	//!< Debug context
	FORWARD_COMPATIBLE	= (1<<2),	//!< Forward-compatible context
};

enum class RCI_SURFACE_TYPE
{
    NONE = 0,
    WINDOW,
    PIXMAP,
    PBUFFER
};

struct RCI_PIXEL_FORMAT
{
	int32_t redBits;
	int32_t greenBits;
	int32_t blueBits;
	int32_t alphaBits;
	int32_t depthBits;
	int32_t stencilBits;
	int32_t numSamples;
};

typedef void (*FunctionPointer)();

class OhosContextI {
public:
    static void SetInstance(void *instance);    
    static OhosContextI &GetInstance();

    virtual bool SetConfig(int32_t w,int32_t h,RCI_GLES_VERSION ver,RCI_PIXEL_FORMAT pf,RCI_SURFACE_TYPE st,RCI_PROFILE tp,RCI_CONTEXT_FLAG flags) = 0;
    virtual bool InitNativeWindow() = 0;
    virtual bool InitEglSurface() = 0;
    virtual bool InitEglContext() = 0;

    virtual void MakeCurrent() = 0;
    virtual void SwapBuffer() = 0;

    virtual int32_t GetAttrib(int32_t attrType) = 0;

    virtual uint64_t CreateWindow(uint32_t x,uint32_t y,uint32_t width,uint32_t height) = 0;
    virtual void *GetNativeWindow(uint64_t windowId) = 0;
    virtual void DestoryWindow(uint64_t windowId) = 0;

    virtual void *GetNativeWindowEx() = 0;
    virtual void OhosWindowResize(int32_t w,int32_t h) = 0;
    virtual void* EglGetConfig() = 0;

// interface_BEGIN
    virtual uint32_t OH_bindAPI(uint32_t api) = 0;
    virtual uint32_t OH_bindTexImage(void* dpy, void* surface, int32_t buffer) = 0;
    virtual uint32_t OH_chooseConfig(void* dpy, const int32_t *attrib_list, void* *configs, int32_t config_size, int32_t *num_config) = 0;
    virtual int32_t OH_clientWaitSync(void* dpy, void* sync, int32_t flags, uint64_t timeout) = 0;
    virtual int32_t OH_clientWaitSyncKHR(void* dpy, void* sync, int32_t flags, uint64_t timeout) = 0;
    virtual uint32_t OH_copyBuffers(void* dpy, void* surface, void* target) = 0;
    virtual void* OH_createContext(void* dpy, void* config, void* share_context, const int32_t *attrib_list) = 0;
    virtual void* OH_createImage(void* dpy, void* ctx, uint32_t target, void* buffer, const int *attrib_list) = 0;
    virtual void* OH_createImageKHR(void* dpy, void* ctx, uint32_t target, void* buffer, const int32_t *attrib_list) = 0;
    virtual void* OH_createPbufferFromClientBuffer(void* dpy, uint32_t buftype, void* buffer, void* config, const int32_t *attrib_list) = 0;
    virtual void* OH_createPbufferSurface(void* dpy, void* config, const int32_t *attrib_list) = 0;
    virtual void* OH_createPixmapSurface(void* dpy, void* config, void* pixmap, const int32_t *attrib_list) = 0;
    virtual void* OH_createPlatformPixmapSurface(void* dpy, void* config, void *native_pixmap, const int *attrib_list) = 0;
    virtual void* OH_createPlatformPixmapSurfaceEXT(void* dpy, void* config, void *native_pixmap, const int32_t *attrib_list) = 0;
    virtual void* OH_createPlatformWindowSurface(void* dpy, void* config, void *native_window, const int *attrib_list) = 0;
    virtual void* OH_createPlatformWindowSurfaceEXT(void* dpy, void* config, void *native_window, const int32_t *attrib_list) = 0;
    virtual void* OH_createSync(void* dpy, uint32_t type, const int *attrib_list) = 0;
    virtual void* OH_createSyncKHR(void* dpy, uint32_t type, const int32_t *attrib_list) = 0;
    virtual void* OH_createWindowSurface(void* dpy, void* config, void* win, const int32_t *attrib_list) = 0;
    virtual uint32_t OH_destroyContext(void* dpy, void* ctx) = 0;
    virtual uint32_t OH_destroyImage(void* dpy, void* image) = 0;
    virtual uint32_t OH_destroyImageKHR(void* dpy, void* image) = 0;
    virtual uint32_t OH_destroySurface(void* dpy, void* surface) = 0;
    virtual uint32_t OH_destroySync(void* dpy, void* sync) = 0;
    virtual uint32_t OH_destroySyncKHR(void* dpy, void* sync) = 0;
    virtual uint32_t OH_getConfigAttrib(void* dpy, void* config, int32_t attribute, int32_t *value) = 0;
    virtual uint32_t OH_getConfigs(void* dpy, void* *configs, int32_t config_size, int32_t *num_config) = 0;
    virtual void* OH_getCurrentContext() = 0;
    virtual void* OH_getCurrentDisplay() = 0;
    virtual void* OH_getCurrentSurface(int32_t readdraw) = 0;
    virtual void* OH_getDisplay(void* display_id) = 0;
    virtual int32_t OH_getError() = 0;
    virtual void* OH_getPlatformDisplay(uint32_t platform, void *native_display, const int *attrib_list) = 0;
    virtual void* OH_getPlatformDisplayEXT(uint32_t platform, void *native_display, const int32_t *attrib_list) = 0;
    virtual FunctionPointer OH_getProcAddress(const char *procname) = 0;
    virtual uint32_t OH_getSyncAttrib(void* dpy, void* sync, int32_t attribute, int *value) = 0;
    virtual uint32_t OH_getSyncAttribKHR(void* dpy, void* sync, int32_t attribute, int32_t *value) = 0;
    virtual uint32_t OH_initialize(void* dpy, int32_t *major, int32_t *minor) = 0;
    virtual uint32_t OH_lockSurfaceKHR(void* dpy, void* surface, const int32_t *attrib_list) = 0;
    virtual uint32_t OH_makeCurrent(void* dpy, void* draw, void* read, void* ctx) = 0;
    virtual uint32_t OH_queryAPI() = 0;
    virtual uint32_t OH_queryContext(void* dpy, void* ctx, int32_t attribute, int32_t *value) = 0;
    virtual const char* OH_queryString(void* dpy, int32_t name) = 0;
    virtual uint32_t OH_querySurface(void* dpy, void* surface, int32_t attribute, int32_t *value) = 0;
    virtual uint32_t OH_releaseTexImage(void* dpy, void* surface, int32_t buffer) = 0;
    virtual uint32_t OH_releaseThread() = 0;
    virtual uint32_t OH_setDamageRegionKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects) = 0;
    virtual uint32_t OH_signalSyncKHR(void* dpy, void* sync, uint32_t mode) = 0;
    virtual uint32_t OH_surfaceAttrib(void* dpy, void* surface, int32_t attribute, int32_t value) = 0;
    virtual uint32_t OH_swapBuffers(void* dpy, void* surface) = 0;
    virtual uint32_t OH_swapBuffersWithDamageKHR(void* dpy, void* surface, int32_t *rects, int32_t n_rects) = 0;
    virtual uint32_t OH_swapInterval(void* dpy, int32_t interval) = 0;
    virtual uint32_t OH_terminate(void* dpy) = 0;
    virtual uint32_t OH_unlockSurfaceKHR(void* dpy, void* surface) = 0;
    virtual uint32_t OH_waitClient() = 0;
    virtual uint32_t OH_waitGL() = 0;
    virtual uint32_t OH_waitNative(int32_t engine) = 0;
    virtual uint32_t OH_waitSync(void* dpy, void* sync, int32_t flags) = 0;
    virtual int32_t OH_waitSyncKHR(void* dpy, void* sync, int32_t flags) = 0;
// interface_END

};

}

#endif