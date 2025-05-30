/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 * This file was generated by /scripts/gen_framework.py
 */

virtual PFN_vkVoidFunction	getDeviceProcAddr						(VkDevice device, const char* pName) const;
virtual void				destroyDevice							(VkDevice device, const VkAllocationCallbacks* pAllocator) const;
virtual void				getDeviceQueue							(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) const;
virtual VkResult			queueSubmit								(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) const;
virtual VkResult			queueWaitIdle							(VkQueue queue) const;
virtual VkResult			deviceWaitIdle							(VkDevice device) const;
virtual VkResult			allocateMemory							(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) const;
virtual VkResult			mapMemory								(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) const;
virtual void				unmapMemory								(VkDevice device, VkDeviceMemory memory) const;
virtual VkResult			flushMappedMemoryRanges					(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const;
virtual VkResult			invalidateMappedMemoryRanges			(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const;
virtual void				getDeviceMemoryCommitment				(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) const;
virtual void				getBufferMemoryRequirements				(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) const;
virtual VkResult			bindBufferMemory						(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) const;
virtual void				getImageMemoryRequirements				(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) const;
virtual VkResult			bindImageMemory							(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) const;
virtual VkResult			createFence								(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const;
virtual void				destroyFence							(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			resetFences								(VkDevice device, uint32_t fenceCount, const VkFence* pFences) const;
virtual VkResult			getFenceStatus							(VkDevice device, VkFence fence) const;
virtual VkResult			waitForFences							(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) const;
virtual VkResult			createSemaphore							(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) const;
virtual void				destroySemaphore						(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createEvent								(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) const;
virtual void				destroyEvent							(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			getEventStatus							(VkDevice device, VkEvent event) const;
virtual VkResult			setEvent								(VkDevice device, VkEvent event) const;
virtual VkResult			resetEvent								(VkDevice device, VkEvent event) const;
virtual VkResult			createQueryPool							(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) const;
virtual VkResult			getQueryPoolResults						(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) const;
virtual void				resetQueryPool							(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const;
virtual VkResult			createBuffer							(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) const;
virtual void				destroyBuffer							(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createBufferView						(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) const;
virtual void				destroyBufferView						(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createImage								(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) const;
virtual void				destroyImage							(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) const;
virtual void				getImageSubresourceLayout				(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) const;
virtual VkResult			createImageView							(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) const;
virtual void				destroyImageView						(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createPipelineCache						(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) const;
virtual void				destroyPipelineCache					(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createGraphicsPipelines					(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const;
virtual VkResult			createComputePipelines					(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const;
virtual void				destroyPipeline							(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createPipelineLayout					(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) const;
virtual void				destroyPipelineLayout					(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createSampler							(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) const;
virtual void				destroySampler							(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createDescriptorSetLayout				(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) const;
virtual void				destroyDescriptorSetLayout				(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createDescriptorPool					(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) const;
virtual VkResult			resetDescriptorPool						(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) const;
virtual VkResult			allocateDescriptorSets					(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) const;
virtual VkResult			freeDescriptorSets						(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) const;
virtual void				updateDescriptorSets					(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) const;
virtual VkResult			createFramebuffer						(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) const;
virtual void				destroyFramebuffer						(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) const;
virtual VkResult			createRenderPass						(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const;
virtual void				destroyRenderPass						(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) const;
virtual void				getRenderAreaGranularity				(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) const;
virtual VkResult			createCommandPool						(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) const;
virtual VkResult			resetCommandPool						(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) const;
virtual VkResult			allocateCommandBuffers					(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) const;
virtual void				freeCommandBuffers						(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const;
virtual VkResult			beginCommandBuffer						(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) const;
virtual VkResult			endCommandBuffer						(VkCommandBuffer commandBuffer) const;
virtual VkResult			resetCommandBuffer						(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) const;
virtual void				cmdBindPipeline							(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) const;
virtual void				cmdSetViewport							(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) const;
virtual void				cmdSetScissor							(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) const;
virtual void				cmdSetLineWidth							(VkCommandBuffer commandBuffer, float lineWidth) const;
virtual void				cmdSetDepthBias							(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const;
virtual void				cmdSetBlendConstants					(VkCommandBuffer commandBuffer, const float blendConstants[4]) const;
virtual void				cmdSetDepthBounds						(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) const;
virtual void				cmdSetStencilCompareMask				(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) const;
virtual void				cmdSetStencilWriteMask					(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) const;
virtual void				cmdSetStencilReference					(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) const;
virtual void				cmdBindDescriptorSets					(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) const;
virtual void				cmdBindIndexBuffer						(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) const;
virtual void				cmdBindVertexBuffers					(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) const;
virtual void				cmdDraw									(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const;
virtual void				cmdDrawIndexed							(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const;
virtual void				cmdDrawIndirect							(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const;
virtual void				cmdDrawIndexedIndirect					(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const;
virtual void				cmdDispatch								(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
virtual void				cmdDispatchIndirect						(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) const;
virtual void				cmdCopyBuffer							(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) const;
virtual void				cmdCopyImage							(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) const;
virtual void				cmdBlitImage							(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) const;
virtual void				cmdCopyBufferToImage					(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) const;
virtual void				cmdCopyImageToBuffer					(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) const;
virtual void				cmdUpdateBuffer							(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) const;
virtual void				cmdFillBuffer							(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) const;
virtual void				cmdClearColorImage						(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const;
virtual void				cmdClearDepthStencilImage				(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const;
virtual void				cmdClearAttachments						(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) const;
virtual void				cmdResolveImage							(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) const;
virtual void				cmdSetEvent								(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const;
virtual void				cmdResetEvent							(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const;
virtual void				cmdWaitEvents							(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const;
virtual void				cmdPipelineBarrier						(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const;
virtual void				cmdBeginQuery							(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) const;
virtual void				cmdEndQuery								(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) const;
virtual void				cmdResetQueryPool						(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const;
virtual void				cmdWriteTimestamp						(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) const;
virtual void				cmdCopyQueryPoolResults					(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) const;
virtual void				cmdPushConstants						(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) const;
virtual void				cmdBeginRenderPass						(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) const;
virtual void				cmdNextSubpass							(VkCommandBuffer commandBuffer, VkSubpassContents contents) const;
virtual void				cmdEndRenderPass						(VkCommandBuffer commandBuffer) const;
virtual void				cmdExecuteCommands						(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const;
virtual VkResult			createSharedSwapchainsKHR				(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) const;
virtual VkResult			createSwapchainKHR						(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) const;
virtual VkResult			getSwapchainImagesKHR					(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) const;
virtual VkResult			acquireNextImageKHR						(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) const;
virtual VkResult			queuePresentKHR							(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) const;
virtual VkResult			getMemoryFdKHR							(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) const;
virtual VkResult			getMemoryFdPropertiesKHR				(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) const;
virtual VkResult			getMemorySciBufNV						(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo, pt::NvSciBufObj* pHandle) const;
virtual VkResult			getSemaphoreFdKHR						(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) const;
virtual VkResult			importSemaphoreFdKHR					(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) const;
virtual VkResult			getFenceFdKHR							(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) const;
virtual VkResult			importFenceFdKHR						(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) const;
virtual VkResult			getFenceSciSyncFenceNV					(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle) const;
virtual VkResult			getFenceSciSyncObjNV					(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle) const;
virtual VkResult			importFenceSciSyncFenceNV				(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) const;
virtual VkResult			importFenceSciSyncObjNV					(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) const;
virtual VkResult			getSemaphoreSciSyncObjNV				(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo, void* pHandle) const;
virtual VkResult			importSemaphoreSciSyncObjNV				(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo) const;
virtual VkResult			createSemaphoreSciSyncPoolNV			(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphoreSciSyncPoolNV* pSemaphorePool) const;
virtual VkResult			displayPowerControlEXT					(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) const;
virtual VkResult			registerDeviceEventEXT					(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const;
virtual VkResult			registerDisplayEventEXT					(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const;
virtual VkResult			getSwapchainCounterEXT					(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) const;
virtual void				getDeviceGroupPeerMemoryFeatures		(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) const;
virtual VkResult			bindBufferMemory2						(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) const;
virtual VkResult			bindImageMemory2						(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) const;
virtual void				cmdSetDeviceMask						(VkCommandBuffer commandBuffer, uint32_t deviceMask) const;
virtual VkResult			getDeviceGroupPresentCapabilitiesKHR	(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) const;
virtual VkResult			getDeviceGroupSurfacePresentModesKHR	(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) const;
virtual VkResult			acquireNextImage2KHR					(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) const;
virtual void				cmdDispatchBase							(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
virtual void				setHdrMetadataEXT						(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) const;
virtual VkResult			getSwapchainStatusKHR					(VkDevice device, VkSwapchainKHR swapchain) const;
virtual void				cmdSetDiscardRectangleEXT				(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) const;
virtual void				cmdSetDiscardRectangleEnableEXT			(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) const;
virtual void				cmdSetDiscardRectangleModeEXT			(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) const;
virtual void				cmdSetSampleLocationsEXT				(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) const;
virtual void				getBufferMemoryRequirements2			(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const;
virtual void				getImageMemoryRequirements2				(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const;
virtual VkResult			createSamplerYcbcrConversion			(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) const;
virtual void				destroySamplerYcbcrConversion			(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) const;
virtual void				getDeviceQueue2							(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) const;
virtual void				getDescriptorSetLayoutSupport			(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) const;
virtual VkResult			getCalibratedTimestampsEXT				(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) const;
virtual VkResult			setDebugUtilsObjectNameEXT				(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) const;
virtual VkResult			setDebugUtilsObjectTagEXT				(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) const;
virtual void				queueBeginDebugUtilsLabelEXT			(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const;
virtual void				queueEndDebugUtilsLabelEXT				(VkQueue queue) const;
virtual void				queueInsertDebugUtilsLabelEXT			(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const;
virtual void				cmdBeginDebugUtilsLabelEXT				(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const;
virtual void				cmdEndDebugUtilsLabelEXT				(VkCommandBuffer commandBuffer) const;
virtual void				cmdInsertDebugUtilsLabelEXT				(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const;
virtual VkResult			getMemoryHostPointerPropertiesEXT		(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) const;
virtual VkResult			createRenderPass2						(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const;
virtual void				cmdBeginRenderPass2						(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) const;
virtual void				cmdNextSubpass2							(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) const;
virtual void				cmdEndRenderPass2						(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) const;
virtual VkResult			getSemaphoreCounterValue				(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) const;
virtual VkResult			waitSemaphores							(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) const;
virtual VkResult			signalSemaphore							(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) const;
virtual void				cmdDrawIndirectCount					(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
virtual void				cmdDrawIndexedIndirectCount				(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
virtual void				cmdSetCheckpointNV						(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) const;
virtual void				getQueueCheckpointDataNV				(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) const;
virtual VkResult			acquireProfilingLockKHR					(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) const;
virtual void				releaseProfilingLockKHR					(VkDevice device) const;
virtual VkResult			getImageDrmFormatModifierPropertiesEXT	(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) const;
virtual uint64_t			getBufferOpaqueCaptureAddress			(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) const;
virtual VkDeviceAddress		getBufferDeviceAddress					(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) const;
virtual uint64_t			getDeviceMemoryOpaqueCaptureAddress		(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const;
virtual void				cmdSetLineStippleEXT					(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) const;
virtual VkResult			getFaultData							(VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults) const;
virtual void				cmdSetCullModeEXT						(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) const;
virtual void				cmdSetFrontFaceEXT						(VkCommandBuffer commandBuffer, VkFrontFace frontFace) const;
virtual void				cmdSetPrimitiveTopologyEXT				(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) const;
virtual void				cmdSetViewportWithCountEXT				(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) const;
virtual void				cmdSetScissorWithCountEXT				(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) const;
virtual void				cmdBindVertexBuffers2EXT				(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) const;
virtual void				cmdSetDepthTestEnableEXT				(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) const;
virtual void				cmdSetDepthWriteEnableEXT				(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) const;
virtual void				cmdSetDepthCompareOpEXT					(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) const;
virtual void				cmdSetDepthBoundsTestEnableEXT			(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) const;
virtual void				cmdSetStencilTestEnableEXT				(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) const;
virtual void				cmdSetStencilOpEXT						(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) const;
virtual void				cmdSetPatchControlPointsEXT				(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) const;
virtual void				cmdSetRasterizerDiscardEnableEXT		(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) const;
virtual void				cmdSetDepthBiasEnableEXT				(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) const;
virtual void				cmdSetLogicOpEXT						(VkCommandBuffer commandBuffer, VkLogicOp logicOp) const;
virtual void				cmdSetPrimitiveRestartEnableEXT			(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) const;
virtual void				cmdCopyBuffer2KHR						(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) const;
virtual void				cmdCopyImage2KHR						(VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) const;
virtual void				cmdBlitImage2KHR						(VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) const;
virtual void				cmdCopyBufferToImage2KHR				(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) const;
virtual void				cmdCopyImageToBuffer2KHR				(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) const;
virtual void				cmdResolveImage2KHR						(VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) const;
virtual void				cmdRefreshObjectsKHR					(VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects) const;
virtual void				cmdSetFragmentShadingRateKHR			(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) const;
virtual void				cmdSetVertexInputEXT					(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) const;
virtual void				cmdSetColorWriteEnableEXT				(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) const;
virtual void				cmdSetEvent2KHR							(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfoKHR* pDependencyInfo) const;
virtual void				cmdResetEvent2KHR						(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) const;
virtual void				cmdWaitEvents2KHR						(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfoKHR* pDependencyInfos) const;
virtual void				cmdPipelineBarrier2KHR					(VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo) const;
virtual VkResult			queueSubmit2KHR							(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2KHR* pSubmits, VkFence fence) const;
virtual void				cmdWriteTimestamp2KHR					(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) const;
virtual void				getQueueCheckpointData2NV				(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) const;
virtual void				getCommandPoolMemoryConsumption			(VkDevice device, VkCommandPool commandPool, VkCommandBuffer commandBuffer, VkCommandPoolMemoryConsumption* pConsumption) const;
virtual VkResult			getScreenBufferPropertiesQNX			(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) const;
