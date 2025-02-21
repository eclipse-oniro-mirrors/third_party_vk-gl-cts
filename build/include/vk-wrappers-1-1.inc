
if (!(ptrs_.vkGetPhysicalDeviceProperties2 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties2>(getInstanceProcAddr(instance_, "vkGetPhysicalDeviceProperties2")))) {
  return Result("Vulkan: Unable to load vkGetPhysicalDeviceProperties2 pointer");
}
