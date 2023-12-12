from .common.codegen import CodeGen, VulkanWrapperGenerator
from .common.vulkantypes import \
        VulkanAPI, makeVulkanTypeSimple, iterateVulkanType
from .common.vulkantypes import EXCLUDED_APIS

RESOURCE_TRACKER_ENTRIES = [
    "vkEnumerateInstanceExtensionProperties",
    "vkEnumerateDeviceExtensionProperties",
    "vkEnumeratePhysicalDevices",
    "vkAllocateMemory",
    "vkFreeMemory",
    "vkCreateImage",
    "vkDestroyImage",
    "vkGetImageMemoryRequirements",
    "vkGetImageMemoryRequirements2",
    "vkGetImageMemoryRequirements2KHR",
    "vkBindImageMemory",
    "vkBindImageMemory2",
    "vkBindImageMemory2KHR",
    "vkCreateBuffer",
    "vkDestroyBuffer",
    "vkGetBufferMemoryRequirements",
    "vkGetBufferMemoryRequirements2",
    "vkGetBufferMemoryRequirements2KHR",
    "vkBindBufferMemory",
    "vkBindBufferMemory2",
    "vkBindBufferMemory2KHR",
    "vkCreateSemaphore",
    "vkDestroySemaphore",
    "vkQueueSubmit",
    "vkQueueWaitIdle",
    "vkImportSemaphoreFdKHR",
    "vkGetSemaphoreFdKHR",
    # Warning: These need to be defined in vk.xml (currently no-op) {
    "vkGetMemoryFuchsiaHandleKHR",
    "vkGetMemoryFuchsiaHandlePropertiesKHR",
    "vkGetSemaphoreFuchsiaHandleKHR",
    "vkImportSemaphoreFuchsiaHandleKHR",
    # } end Warning: These need to be defined in vk.xml (currently no-op)
    "vkGetAndroidHardwareBufferPropertiesANDROID",
    "vkGetMemoryAndroidHardwareBufferANDROID",
    "vkCreateSamplerYcbcrConversion",
    "vkDestroySamplerYcbcrConversion",
    "vkCreateSamplerYcbcrConversionKHR",
    "vkDestroySamplerYcbcrConversionKHR",
    "vkUpdateDescriptorSetWithTemplate",
    "vkGetPhysicalDeviceImageFormatProperties2",
    "vkGetPhysicalDeviceImageFormatProperties2KHR",
    "vkBeginCommandBuffer",
    "vkEndCommandBuffer",
    "vkResetCommandBuffer",
    "vkCreateImageView",
    "vkCreateSampler",
    "vkGetPhysicalDeviceExternalFenceProperties",
    "vkGetPhysicalDeviceExternalFencePropertiesKHR",
    "vkCreateFence",
    "vkResetFences",
    "vkImportFenceFdKHR",
    "vkGetFenceFdKHR",
    "vkWaitForFences",
    "vkCreateDescriptorPool",
    "vkDestroyDescriptorPool",
    "vkResetDescriptorPool",
    "vkAllocateDescriptorSets",
    "vkFreeDescriptorSets",
    "vkCreateDescriptorSetLayout",
    "vkUpdateDescriptorSets",
    "vkCmdExecuteCommands",
    "vkCmdBindDescriptorSets",
    "vkDestroyDescriptorSetLayout",
    "vkAllocateCommandBuffers",
]

SUCCESS_VAL = {
    "VkResult" : ["VK_SUCCESS"],
}

POSTPROCESSES = {
    "vkResetCommandPool" : """if (vkResetCommandPool_VkResult_return == VK_SUCCESS) {
        ResourceTracker::get()->resetCommandPoolStagingInfo(commandPool);
    }""",
    "vkAllocateCommandBuffers" : """if (vkAllocateCommandBuffers_VkResult_return == VK_SUCCESS) {
        ResourceTracker::get()->addToCommandPool(pAllocateInfo->commandPool, pAllocateInfo->commandBufferCount, pCommandBuffers);
    }""",
}

def is_cmdbuf_dispatch(api):
    return "VkCommandBuffer" == api.parameters[0].typeName

def is_queue_dispatch(api):
    return "VkQueue" == api.parameters[0].typeName

class VulkanFuncTable(VulkanWrapperGenerator):
    def __init__(self, module, typeInfo):
        VulkanWrapperGenerator.__init__(self, module, typeInfo)
        self.typeInfo = typeInfo
        self.cgen = CodeGen()
        self.entries = []
        self.entryFeatures = []
        self.feature = None

    def onBegin(self,):
        cgen = self.cgen
        cgen.line("static void sOnInvalidDynamicallyCheckedCall(const char* apiname, const char* neededFeature)")
        cgen.beginBlock()
        cgen.stmt("ALOGE(\"invalid call to %s: %s not supported\", apiname, neededFeature)")
        cgen.stmt("abort()")
        cgen.endBlock()
        self.module.appendImpl(cgen.swapCode())
        pass

    def onBeginFeature(self, featureName):
        self.feature = featureName

    def onGenCmd(self, cmdinfo, name, alias):
        typeInfo = self.typeInfo
        cgen = self.cgen
        api = typeInfo.apis[name]
        self.entries.append(api)
        self.entryFeatures.append(self.feature)

        def genEncoderOrResourceTrackerCall(cgen, api, declareResources=True):
            cgen.stmt("AEMU_SCOPED_TRACE(\"%s\")" % api.name)

            if is_cmdbuf_dispatch(api):
                cgen.stmt("auto vkEnc = ResourceTracker::getCommandBufferEncoder(commandBuffer)")
            elif is_queue_dispatch(api):
                cgen.stmt("auto vkEnc = ResourceTracker::getQueueEncoder(queue)")
            else:
                cgen.stmt("auto vkEnc = ResourceTracker::getThreadLocalEncoder()")
            callLhs = None
            retTypeName = api.getRetTypeExpr()
            if retTypeName != "void":
                retVar = api.getRetVarExpr()
                cgen.stmt("%s %s = (%s)0" % (retTypeName, retVar, retTypeName))
                callLhs = retVar

            if name in RESOURCE_TRACKER_ENTRIES:
                if declareResources:
                    cgen.stmt("auto resources = ResourceTracker::get()")
                cgen.funcCall(
                    callLhs, "resources->" + "on_" + api.name,
                    ["vkEnc"] + SUCCESS_VAL.get(retTypeName, []) + \
                    [p.paramName for p in api.parameters])
            else:
                cgen.funcCall(
                    callLhs, "vkEnc->" + api.name, [p.paramName for p in api.parameters] + ["true /* do lock */"])

            if name in POSTPROCESSES:
                cgen.line(POSTPROCESSES[name])

            if retTypeName != "void":
                cgen.stmt("return %s" % retVar)


        api_entry = api.withModifiedName("entry_" + api.name)

        cgen.line("static " + self.cgen.makeFuncProto(api_entry))
        cgen.beginBlock()
        genEncoderOrResourceTrackerCall(cgen, api)
        cgen.endBlock()

        if self.isDeviceDispatch(api) and self.feature != "VK_VERSION_1_0":
            api_entry_dyn_check = api.withModifiedName("dynCheck_entry_" + api.name)
            cgen.line("static " + self.cgen.makeFuncProto(api_entry_dyn_check))
            cgen.beginBlock()
            if self.feature == "VK_VERSION_1_1":
                cgen.stmt("auto resources = ResourceTracker::get()")
                cgen.beginIf("resources->getApiVersionFromDevice(device) < VK_API_VERSION_1_1")
                cgen.stmt("sOnInvalidDynamicallyCheckedCall(\"%s\", \"%s\")" % (api.name, self.feature))
                cgen.endIf()
            elif self.feature != "VK_VERSION_1_0":
                cgen.stmt("auto resources = ResourceTracker::get()")
                cgen.beginIf("!resources->hasDeviceExtension(device, \"%s\")" % self.feature)
                cgen.stmt("sOnInvalidDynamicallyCheckedCall(\"%s\", \"%s\")" % (api.name, self.feature))
                cgen.endIf()
            else:
                print("About to generate a frivolous api!: dynCheck entry: %s" % api.name)
                raise
            genEncoderOrResourceTrackerCall(cgen, api, declareResources = False)
            cgen.endBlock()

        self.module.appendImpl(cgen.swapCode())

    def onEnd(self,):
        getProcAddressDecl = "void* goldfish_vulkan_get_proc_address(const char* name)"
        self.module.appendHeader(getProcAddressDecl + ";\n")
        self.module.appendImpl(getProcAddressDecl)
        self.cgen.beginBlock()

        prevFeature = None
        for e, f in zip(self.entries, self.entryFeatures):
            featureEndif = prevFeature is not None and (f != prevFeature)
            featureif = not featureEndif and (f != prevFeature)

            if featureEndif:
                self.cgen.leftline("#endif")
                self.cgen.leftline("#ifdef %s" % f)

            if featureif:
                self.cgen.leftline("#ifdef %s" % f)

            self.cgen.beginIf("!strcmp(name, \"%s\")" % e.name)
            if e.name in EXCLUDED_APIS:
                self.cgen.stmt("return nullptr")
            elif f == "VK_VERSION_1_1":
                self.cgen.stmt("return nullptr")
            elif f != "VK_VERSION_1_0":
                self.cgen.stmt("return nullptr")
            else:
                self.cgen.stmt("return (void*)%s" % ("entry_" + e.name))
            self.cgen.endIf()
            prevFeature = f

        self.cgen.leftline("#endif")

        self.cgen.stmt("return nullptr")
        self.cgen.endBlock()
        self.module.appendImpl(self.cgen.swapCode())

        getInstanceProcAddressDecl = "void* goldfish_vulkan_get_instance_proc_address(VkInstance instance, const char* name)"
        self.module.appendHeader(getInstanceProcAddressDecl + ";\n")
        self.module.appendImpl(getInstanceProcAddressDecl)
        self.cgen.beginBlock()

        self.cgen.stmt(
            "auto resources = ResourceTracker::get()")
        self.cgen.stmt(
            "bool has1_1OrHigher = resources->getApiVersionFromInstance(instance) >= VK_API_VERSION_1_1")

        prevFeature = None
        for e, f in zip(self.entries, self.entryFeatures):
            featureEndif = prevFeature is not None and (f != prevFeature)
            featureif = not featureEndif and (f != prevFeature)

            if featureEndif:
                self.cgen.leftline("#endif")
                self.cgen.leftline("#ifdef %s" % f)
            
            if featureif:
                self.cgen.leftline("#ifdef %s" % f)

            self.cgen.beginIf("!strcmp(name, \"%s\")" % e.name)

            entryPointExpr = "(void*)%s" % ("entry_" + e.name)

            if e.name in EXCLUDED_APIS:
                self.cgen.stmt("return nullptr")
            elif f == "VK_VERSION_1_1":
                if self.isDeviceDispatch(e):
                    self.cgen.stmt("return (void*)dynCheck_entry_%s" % e.name)
                else:
                    self.cgen.stmt( \
                        "return has1_1OrHigher ? %s : nullptr" % \
                        entryPointExpr)
            elif f != "VK_VERSION_1_0":
                if self.isDeviceDispatch(e):
                    self.cgen.stmt("return (void*)dynCheck_entry_%s" % e.name)
                else:
                    self.cgen.stmt( \
                        "bool hasExt = resources->hasInstanceExtension(instance, \"%s\")"  % f)
                    self.cgen.stmt("return hasExt ? %s : nullptr" % entryPointExpr)
            else:
                self.cgen.stmt("return %s" % entryPointExpr)
            self.cgen.endIf()
            prevFeature = f

        self.cgen.leftline("#endif")

        self.cgen.stmt("return nullptr")
        self.cgen.endBlock()
        self.module.appendImpl(self.cgen.swapCode())

        getDeviceProcAddressDecl = "void* goldfish_vulkan_get_device_proc_address(VkDevice device, const char* name)"
        self.module.appendHeader(getDeviceProcAddressDecl + ";\n")
        self.module.appendImpl(getDeviceProcAddressDecl)
        self.cgen.beginBlock()

        self.cgen.stmt(
            "auto resources = ResourceTracker::get()")
        self.cgen.stmt(
            "bool has1_1OrHigher = resources->getApiVersionFromDevice(device) >= VK_API_VERSION_1_1")

        prevFeature = None
        for e, f in zip(self.entries, self.entryFeatures):
            featureEndif = prevFeature is not None and (f != prevFeature)
            featureif = not featureEndif and (f != prevFeature)

            if featureEndif:
                self.cgen.leftline("#endif")
                self.cgen.leftline("#ifdef %s" % f)
            
            if featureif:
                self.cgen.leftline("#ifdef %s" % f)

            self.cgen.beginIf("!strcmp(name, \"%s\")" % e.name)

            entryPointExpr = "(void*)%s" % ("entry_" + e.name)

            if e.name in EXCLUDED_APIS:
                self.cgen.stmt("return nullptr")
            elif f == "VK_VERSION_1_1":
                self.cgen.stmt( \
                    "return has1_1OrHigher ? %s : nullptr" % \
                    entryPointExpr)
            elif f != "VK_VERSION_1_0":
                self.cgen.stmt( \
                    "bool hasExt = resources->hasDeviceExtension(device, \"%s\")"  % f)
                self.cgen.stmt("return hasExt ? %s : nullptr" % entryPointExpr)
            else:
                self.cgen.stmt("return %s" % entryPointExpr)
            self.cgen.endIf()
            prevFeature = f

        self.cgen.leftline("#endif")

        self.cgen.stmt("return nullptr")
        self.cgen.endBlock()

        self.module.appendImpl(self.cgen.swapCode())

    def isDeviceDispatch(self, api):
        return len(api.parameters) > 0 and "VkDevice" == api.parameters[0].typeName
