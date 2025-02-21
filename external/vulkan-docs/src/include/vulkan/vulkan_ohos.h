#ifndef VULKAN_OHOS_H_
#define VULKAN_OHOS_H_ 1

/*
** Copyright 2015-2021 The Khronos Group Inc.
**
** SPDX-License-Identifier: Apache-2.0
*/

/*
** This header is generated from the Khronos Vulkan XML API Registry.
**
*/


#ifdef __cplusplus
extern "C" {
#endif



#define VK_OpenHarmony_OHOS_surface 1
struct NativeWindow;
#define VK_OpenHarmony_OHOS_SURFACE_SPEC_VERSION 1
#define VK_OpenHarmony_OHOS_SURFACE_EXTENSION_NAME "VK_OpenHarmony_OHOS_surface"
typedef VkFlags VkOHOSSurfaceCreateFlagsOpenHarmony;
typedef struct VkOHOSSurfaceCreateInfoOpenHarmony {
    VkStructureType                        sType;
    const void*                            pNext;
    VkOHOSSurfaceCreateFlagsOpenHarmony    flags;
    struct NativeWindow*                   window;
} VkOHOSSurfaceCreateInfoOpenHarmony;

typedef VkResult (VKAPI_PTR *PFN_vkCreateOHOSSurfaceOpenHarmony)(VkInstance instance, const VkOHOSSurfaceCreateInfoOpenHarmony* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vkCreateOHOSSurfaceOpenHarmony(
    VkInstance                                  instance,
    const VkOHOSSurfaceCreateInfoOpenHarmony*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface);
#endif

#ifdef __cplusplus
}
#endif

#endif
