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

#include "tcuOhosNativeDisplay.hpp"
#include "egluGLContextFactory.hpp"
#include "eglwLibrary.hpp"
#include "eglwFunctions.hpp"
#include "eglwEnums.hpp"
#include "deUniquePtr.hpp"

#include "egluDefs.hpp"

using namespace tcu;
using namespace OHOS_ROSEN;
using namespace egl;

using std::string;
using de::MovePtr;
using de::UniquePtr;
using glu::ContextFactory;
using eglu::GLContextFactory;
using eglu::NativeDisplay;
using eglu::NativeDisplayFactory;
using eglu::NativeWindow;
using eglu::NativeWindowFactory;
using eglu::NativePixmap;
using eglu::NativePixmapFactory;
using eglu::WindowParams;
using tcu::TextureLevel;

#include "ohos_context_i.h"

OhosDisplay::OhosDisplay (void) 
    : NativeDisplay(CAPABILITIES)
{
    //TODO: create display
    printf("OhosDisplay::OhosDisplay\n");
}

void* OhosDisplay::getPlatformNative (void) {
    //TODO: 获取rosen display
    printf("OhosDisplay::getPlatformNative\n");
    return EGL_DEFAULT_DISPLAY; 
}

// eglw::EGLNativeDisplayType OhosDisplay::getPlatformExtension (void)    
// {
//     //TODO: 获取rosen display
//     printf("OhosDisplay::getPlatformExtension\n");
//     return reinterpret_cast<eglw::EGLNativeDisplayType>(this); 
// }

eglw::EGLNativeDisplayType OhosDisplay::getLegacyNative (void)    
{ 
    //TODO: 获取rosen display
    printf("OhosDisplay::getLegacyNative\n");
    return EGL_DEFAULT_DISPLAY; 
}

// call2_BEGIN
eglw::EGLBoolean OhosLibrary::bindAPI(eglw::EGLenum api) const
{
    return OHOS::OhosContextI::GetInstance().OH_bindAPI(api);
}

eglw::EGLBoolean OhosLibrary::bindTexImage(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint buffer) const
{
    return OHOS::OhosContextI::GetInstance().OH_bindTexImage(dpy, surface, buffer);
}

eglw::EGLBoolean OhosLibrary::chooseConfig(eglw::EGLDisplay dpy, const eglw::EGLint *attrib_list, eglw::EGLConfig *configs, eglw::EGLint config_size, eglw::EGLint *num_config) const
{
    return OHOS::OhosContextI::GetInstance().OH_chooseConfig(dpy, attrib_list, configs, config_size, num_config);
}

eglw::EGLint OhosLibrary::clientWaitSync(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint flags, eglw::EGLTime timeout) const
{
    return OHOS::OhosContextI::GetInstance().OH_clientWaitSync(dpy, sync, flags, timeout);
}

eglw::EGLint OhosLibrary::clientWaitSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint flags, eglw::EGLTimeKHR timeout) const
{
    return OHOS::OhosContextI::GetInstance().OH_clientWaitSyncKHR(dpy, sync, flags, timeout);
}

eglw::EGLBoolean OhosLibrary::copyBuffers(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLNativePixmapType target) const
{
    return OHOS::OhosContextI::GetInstance().OH_copyBuffers(dpy, surface, target);
}

eglw::EGLContext OhosLibrary::createContext(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLContext share_context, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createContext(dpy, config, share_context, attrib_list);
}

eglw::EGLImage OhosLibrary::createImage(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLenum target, eglw::EGLClientBuffer buffer, const eglw::EGLAttrib *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createImage(dpy, ctx, target, buffer, reinterpret_cast<const int *>(attrib_list));
}

eglw::EGLImageKHR OhosLibrary::createImageKHR(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLenum target, eglw::EGLClientBuffer buffer, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createImageKHR(dpy, ctx, target, buffer, attrib_list);
}

eglw::EGLSurface OhosLibrary::createPbufferFromClientBuffer(eglw::EGLDisplay dpy, eglw::EGLenum buftype, eglw::EGLClientBuffer buffer, eglw::EGLConfig config, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
}

eglw::EGLSurface OhosLibrary::createPbufferSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPbufferSurface(dpy, config, attrib_list);
}

eglw::EGLSurface OhosLibrary::createPixmapSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLNativePixmapType pixmap, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPixmapSurface(dpy, config, pixmap, attrib_list);
}

eglw::EGLSurface OhosLibrary::createPlatformPixmapSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_pixmap, const eglw::EGLAttrib *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPlatformPixmapSurface(dpy, config, native_pixmap, reinterpret_cast<const int *>(attrib_list));
}

eglw::EGLSurface OhosLibrary::createPlatformPixmapSurfaceEXT(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_pixmap, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPlatformPixmapSurfaceEXT(dpy, config, native_pixmap, attrib_list);
}

eglw::EGLSurface OhosLibrary::createPlatformWindowSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_window, const eglw::EGLAttrib *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPlatformWindowSurface(dpy, config, native_window, reinterpret_cast<const int *>(attrib_list));
}

eglw::EGLSurface OhosLibrary::createPlatformWindowSurfaceEXT(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_window, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createPlatformWindowSurfaceEXT(dpy, config, native_window, attrib_list);
}

eglw::EGLSync OhosLibrary::createSync(eglw::EGLDisplay dpy, eglw::EGLenum type, const eglw::EGLAttrib *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createSync(dpy, type, reinterpret_cast<const int *>(attrib_list));
}

eglw::EGLSyncKHR OhosLibrary::createSyncKHR(eglw::EGLDisplay dpy, eglw::EGLenum type, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createSyncKHR(dpy, type, attrib_list);
}

eglw::EGLSurface OhosLibrary::createWindowSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLNativeWindowType win, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_createWindowSurface(dpy, config, win, attrib_list);
}

eglw::EGLBoolean OhosLibrary::destroyContext(eglw::EGLDisplay dpy, eglw::EGLContext ctx) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroyContext(dpy, ctx);
}

eglw::EGLBoolean OhosLibrary::destroyImage(eglw::EGLDisplay dpy, eglw::EGLImage image) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroyImage(dpy, image);
}

eglw::EGLBoolean OhosLibrary::destroyImageKHR(eglw::EGLDisplay dpy, eglw::EGLImageKHR image) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroyImageKHR(dpy, image);
}

eglw::EGLBoolean OhosLibrary::destroySurface(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroySurface(dpy, surface);
}

eglw::EGLBoolean OhosLibrary::destroySync(eglw::EGLDisplay dpy, eglw::EGLSync sync) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroySync(dpy, sync);
}

eglw::EGLBoolean OhosLibrary::destroySyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync) const
{
    return OHOS::OhosContextI::GetInstance().OH_destroySyncKHR(dpy, sync);
}

eglw::EGLBoolean OhosLibrary::getConfigAttrib(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLint attribute, eglw::EGLint *value) const
{
    return OHOS::OhosContextI::GetInstance().OH_getConfigAttrib(dpy, config, attribute, value);
}

eglw::EGLBoolean OhosLibrary::getConfigs(eglw::EGLDisplay dpy, eglw::EGLConfig *configs, eglw::EGLint config_size, eglw::EGLint *num_config) const
{
    return OHOS::OhosContextI::GetInstance().OH_getConfigs(dpy, configs, config_size, num_config);
}

eglw::EGLContext OhosLibrary::getCurrentContext() const
{
    return OHOS::OhosContextI::GetInstance().OH_getCurrentContext();
}

eglw::EGLDisplay OhosLibrary::getCurrentDisplay() const
{
    return OHOS::OhosContextI::GetInstance().OH_getCurrentDisplay();
}

eglw::EGLSurface OhosLibrary::getCurrentSurface(eglw::EGLint readdraw) const
{
    return OHOS::OhosContextI::GetInstance().OH_getCurrentSurface(readdraw);
}

eglw::EGLDisplay OhosLibrary::getDisplay(eglw::EGLNativeDisplayType display_id) const
{
    return OHOS::OhosContextI::GetInstance().OH_getDisplay(display_id);
}

eglw::EGLint OhosLibrary::getError() const
{
    return OHOS::OhosContextI::GetInstance().OH_getError();
}

eglw::EGLDisplay OhosLibrary::getPlatformDisplay(eglw::EGLenum platform, void *native_display, const eglw::EGLAttrib *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_getPlatformDisplay(platform, native_display, reinterpret_cast<const int *>(attrib_list));
}

eglw::EGLDisplay OhosLibrary::getPlatformDisplayEXT(eglw::EGLenum platform, void *native_display, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_getPlatformDisplayEXT(platform, native_display, attrib_list);
}

eglw::__eglMustCastToProperFunctionPointerType OhosLibrary::getProcAddress(const char *procname) const
{
    return OHOS::OhosContextI::GetInstance().OH_getProcAddress(procname);
}

eglw::EGLBoolean OhosLibrary::getSyncAttrib(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint attribute, eglw::EGLAttrib *value) const
{
    return OHOS::OhosContextI::GetInstance().OH_getSyncAttrib(dpy, sync, attribute, reinterpret_cast<int *>(value));
}

eglw::EGLBoolean OhosLibrary::getSyncAttribKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint attribute, eglw::EGLint *value) const
{
    return OHOS::OhosContextI::GetInstance().OH_getSyncAttribKHR(dpy, sync, attribute, value);
}

eglw::EGLBoolean OhosLibrary::initialize(eglw::EGLDisplay dpy, eglw::EGLint *major, eglw::EGLint *minor) const
{
    return OHOS::OhosContextI::GetInstance().OH_initialize(dpy, major, minor);
}

eglw::EGLBoolean OhosLibrary::lockSurfaceKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, const eglw::EGLint *attrib_list) const
{
    return OHOS::OhosContextI::GetInstance().OH_lockSurfaceKHR(dpy, surface, attrib_list);
}

eglw::EGLBoolean OhosLibrary::makeCurrent(eglw::EGLDisplay dpy, eglw::EGLSurface draw, eglw::EGLSurface read, eglw::EGLContext ctx) const
{
    return OHOS::OhosContextI::GetInstance().OH_makeCurrent(dpy, draw, read, ctx);
}

eglw::EGLenum OhosLibrary::queryAPI() const
{
    return OHOS::OhosContextI::GetInstance().OH_queryAPI();
}

eglw::EGLBoolean OhosLibrary::queryContext(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLint attribute, eglw::EGLint *value) const
{
    return OHOS::OhosContextI::GetInstance().OH_queryContext(dpy, ctx, attribute, value);
}

const char* OhosLibrary::queryString(eglw::EGLDisplay dpy, eglw::EGLint name) const
{
    return OHOS::OhosContextI::GetInstance().OH_queryString(dpy, name);
}

eglw::EGLBoolean OhosLibrary::querySurface(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint attribute, eglw::EGLint *value) const
{
    return OHOS::OhosContextI::GetInstance().OH_querySurface(dpy, surface, attribute, value);
}

eglw::EGLBoolean OhosLibrary::releaseTexImage(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint buffer) const
{
    return OHOS::OhosContextI::GetInstance().OH_releaseTexImage(dpy, surface, buffer);
}

eglw::EGLBoolean OhosLibrary::releaseThread() const
{
    return OHOS::OhosContextI::GetInstance().OH_releaseThread();
}

eglw::EGLBoolean OhosLibrary::setDamageRegionKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint *rects, eglw::EGLint n_rects) const
{
    return OHOS::OhosContextI::GetInstance().OH_setDamageRegionKHR(dpy, surface, rects, n_rects);
}

eglw::EGLBoolean OhosLibrary::signalSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLenum mode) const
{
    return OHOS::OhosContextI::GetInstance().OH_signalSyncKHR(dpy, sync, mode);
}

eglw::EGLBoolean OhosLibrary::surfaceAttrib(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint attribute, eglw::EGLint value) const
{
    return OHOS::OhosContextI::GetInstance().OH_surfaceAttrib(dpy, surface, attribute, value);
}

eglw::EGLBoolean OhosLibrary::swapBuffers(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const
{
    return OHOS::OhosContextI::GetInstance().OH_swapBuffers(dpy, surface);
}

eglw::EGLBoolean OhosLibrary::swapBuffersWithDamageKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint *rects, eglw::EGLint n_rects) const
{
    return OHOS::OhosContextI::GetInstance().OH_swapBuffersWithDamageKHR(dpy, surface, rects, n_rects);
}

eglw::EGLBoolean OhosLibrary::swapInterval(eglw::EGLDisplay dpy, eglw::EGLint interval) const
{
    return OHOS::OhosContextI::GetInstance().OH_swapInterval(dpy, interval);
}

eglw::EGLBoolean OhosLibrary::terminate(eglw::EGLDisplay dpy) const
{
    return OHOS::OhosContextI::GetInstance().OH_terminate(dpy);
}

eglw::EGLBoolean OhosLibrary::unlockSurfaceKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const
{
    return OHOS::OhosContextI::GetInstance().OH_unlockSurfaceKHR(dpy, surface);
}

eglw::EGLBoolean OhosLibrary::waitClient() const
{
    return OHOS::OhosContextI::GetInstance().OH_waitClient();
}

eglw::EGLBoolean OhosLibrary::waitGL() const
{
    return OHOS::OhosContextI::GetInstance().OH_waitGL();
}

eglw::EGLBoolean OhosLibrary::waitNative(eglw::EGLint engine) const
{
    return OHOS::OhosContextI::GetInstance().OH_waitNative(engine);
}

eglw::EGLBoolean OhosLibrary::waitSync(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint flags) const
{
    return OHOS::OhosContextI::GetInstance().OH_waitSync(dpy, sync, flags);
}

eglw::EGLint OhosLibrary::waitSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint flags) const
{
    return OHOS::OhosContextI::GetInstance().OH_waitSyncKHR(dpy, sync, flags);
}

// call2_END