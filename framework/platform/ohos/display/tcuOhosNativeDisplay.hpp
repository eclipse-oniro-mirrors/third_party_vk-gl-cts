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
#ifndef _TCUOHOSROSENNATIVEDISPLAY_HPP
#define _TCUOHOSROSENNATIVEDISPLAY_HPP

#include "egluGLContextFactory.hpp"
#include "eglwLibrary.hpp"
#include "eglwFunctions.hpp"
#include "eglwEnums.hpp"
#include "deUniquePtr.hpp"

namespace tcu
{
namespace OHOS_ROSEN
{
namespace egl
{

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

class OhosLibrary : public eglw::DefaultLibrary
{
public:
    OhosLibrary (void)
        : eglw::DefaultLibrary("libEGL_impl.so")
    {
    }

// call1_BEGIN
    eglw::EGLBoolean bindAPI(eglw::EGLenum api) const;
    eglw::EGLBoolean bindTexImage(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint buffer) const;
    eglw::EGLBoolean chooseConfig(eglw::EGLDisplay dpy, const eglw::EGLint *attrib_list, eglw::EGLConfig *configs, eglw::EGLint config_size, eglw::EGLint *num_config) const;
    eglw::EGLint clientWaitSync(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint flags, eglw::EGLTime timeout) const;
    eglw::EGLint clientWaitSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint flags, eglw::EGLTimeKHR timeout) const;
    eglw::EGLBoolean copyBuffers(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLNativePixmapType target) const;
    eglw::EGLContext createContext(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLContext share_context, const eglw::EGLint *attrib_list) const;
    eglw::EGLImage createImage(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLenum target, eglw::EGLClientBuffer buffer, const eglw::EGLAttrib *attrib_list) const;
    eglw::EGLImageKHR createImageKHR(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLenum target, eglw::EGLClientBuffer buffer, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createPbufferFromClientBuffer(eglw::EGLDisplay dpy, eglw::EGLenum buftype, eglw::EGLClientBuffer buffer, eglw::EGLConfig config, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createPbufferSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createPixmapSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLNativePixmapType pixmap, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createPlatformPixmapSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_pixmap, const eglw::EGLAttrib *attrib_list) const;
    eglw::EGLSurface createPlatformPixmapSurfaceEXT(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_pixmap, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createPlatformWindowSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_window, const eglw::EGLAttrib *attrib_list) const;
    eglw::EGLSurface createPlatformWindowSurfaceEXT(eglw::EGLDisplay dpy, eglw::EGLConfig config, void *native_window, const eglw::EGLint *attrib_list) const;
    eglw::EGLSync createSync(eglw::EGLDisplay dpy, eglw::EGLenum type, const eglw::EGLAttrib *attrib_list) const;
    eglw::EGLSyncKHR createSyncKHR(eglw::EGLDisplay dpy, eglw::EGLenum type, const eglw::EGLint *attrib_list) const;
    eglw::EGLSurface createWindowSurface(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLNativeWindowType win, const eglw::EGLint *attrib_list) const;
    eglw::EGLBoolean destroyContext(eglw::EGLDisplay dpy, eglw::EGLContext ctx) const;
    eglw::EGLBoolean destroyImage(eglw::EGLDisplay dpy, eglw::EGLImage image) const;
    eglw::EGLBoolean destroyImageKHR(eglw::EGLDisplay dpy, eglw::EGLImageKHR image) const;
    eglw::EGLBoolean destroySurface(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const;
    eglw::EGLBoolean destroySync(eglw::EGLDisplay dpy, eglw::EGLSync sync) const;
    eglw::EGLBoolean destroySyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync) const;
    eglw::EGLBoolean getConfigAttrib(eglw::EGLDisplay dpy, eglw::EGLConfig config, eglw::EGLint attribute, eglw::EGLint *value) const;
    eglw::EGLBoolean getConfigs(eglw::EGLDisplay dpy, eglw::EGLConfig *configs, eglw::EGLint config_size, eglw::EGLint *num_config) const;
    eglw::EGLContext getCurrentContext() const;
    eglw::EGLDisplay getCurrentDisplay() const;
    eglw::EGLSurface getCurrentSurface(eglw::EGLint readdraw) const;
    eglw::EGLDisplay getDisplay(eglw::EGLNativeDisplayType display_id) const;
    eglw::EGLint getError() const;
    eglw::EGLDisplay getPlatformDisplay(eglw::EGLenum platform, void *native_display, const eglw::EGLAttrib *attrib_list) const;
    eglw::EGLDisplay getPlatformDisplayEXT(eglw::EGLenum platform, void *native_display, const eglw::EGLint *attrib_list) const;
    eglw::__eglMustCastToProperFunctionPointerType getProcAddress(const char *procname) const;
    eglw::EGLBoolean getSyncAttrib(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint attribute, eglw::EGLAttrib *value) const;
    eglw::EGLBoolean getSyncAttribKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint attribute, eglw::EGLint *value) const;
    eglw::EGLBoolean initialize(eglw::EGLDisplay dpy, eglw::EGLint *major, eglw::EGLint *minor) const;
    eglw::EGLBoolean lockSurfaceKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, const eglw::EGLint *attrib_list) const;
    eglw::EGLBoolean makeCurrent(eglw::EGLDisplay dpy, eglw::EGLSurface draw, eglw::EGLSurface read, eglw::EGLContext ctx) const;
    eglw::EGLenum queryAPI() const;
    eglw::EGLBoolean queryContext(eglw::EGLDisplay dpy, eglw::EGLContext ctx, eglw::EGLint attribute, eglw::EGLint *value) const;
    const char* queryString(eglw::EGLDisplay dpy, eglw::EGLint name) const;
    eglw::EGLBoolean querySurface(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint attribute, eglw::EGLint *value) const;
    eglw::EGLBoolean releaseTexImage(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint buffer) const;
    eglw::EGLBoolean releaseThread() const;
    eglw::EGLBoolean setDamageRegionKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint *rects, eglw::EGLint n_rects) const;
    eglw::EGLBoolean signalSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLenum mode) const;
    eglw::EGLBoolean surfaceAttrib(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint attribute, eglw::EGLint value) const;
    eglw::EGLBoolean swapBuffers(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const;
    eglw::EGLBoolean swapBuffersWithDamageKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface, eglw::EGLint *rects, eglw::EGLint n_rects) const;
    eglw::EGLBoolean swapInterval(eglw::EGLDisplay dpy, eglw::EGLint interval) const;
    eglw::EGLBoolean terminate(eglw::EGLDisplay dpy) const;
    eglw::EGLBoolean unlockSurfaceKHR(eglw::EGLDisplay dpy, eglw::EGLSurface surface) const;
    eglw::EGLBoolean waitClient() const;
    eglw::EGLBoolean waitGL() const;
    eglw::EGLBoolean waitNative(eglw::EGLint engine) const;
    eglw::EGLBoolean waitSync(eglw::EGLDisplay dpy, eglw::EGLSync sync, eglw::EGLint flags) const;
    eglw::EGLint waitSyncKHR(eglw::EGLDisplay dpy, eglw::EGLSyncKHR sync, eglw::EGLint flags) const;
// call1_END
};

class OhosDisplay : public NativeDisplay
{
public:
    static const Capability CAPABILITIES        = Capability(CAPABILITY_GET_DISPLAY_LEGACY);

    OhosDisplay                (void);
    // virtual ~OhosDisplay         (void) {};

    void*                        getPlatformNative        (void);
    // eglw::EGLNativeDisplayType    getPlatformExtension    (void);
    eglw::EGLNativeDisplayType    getLegacyNative            (void);

    // NativeDisplay&                getOhosDisplay            (void)            { return *this;}
    const eglw::Library&        getLibrary                (void) const    { return m_library;    }
    // const eglw::EGLAttrib*        getPlatformAttributes    (void) const    { return DE_NULL; }

private:
    OhosLibrary                        m_library;

};

} // egl
} // OHOS
} // tcu
#endif // _TCUOHOSROSENNATIVEDISPLAY_HPP