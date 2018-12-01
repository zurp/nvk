/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY node-vulkan v0.0.9
 */
#ifndef __VK_VKDEVICEGROUPRENDERPASSBEGININFO_H__
#define __VK_VKDEVICEGROUPRENDERPASSBEGININFO_H__

#include <nan.h>

#include <vulkan/vulkan_win32.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class _VkDeviceGroupRenderPassBeginInfo: public Nan::ObjectWrap {

  public:
    // #methods
    static NAN_METHOD(New);
    // #accessors
    static NAN_GETTER(GetsType);
    static NAN_SETTER(SetsType);
    
    Nan::Persistent<v8::Object, v8::CopyablePersistentTraits<v8::Object>> pNext;
    static NAN_GETTER(GetpNext);
    static NAN_SETTER(SetpNext);
    
    static NAN_GETTER(GetdeviceMask);
    static NAN_SETTER(SetdeviceMask);
    
    static NAN_GETTER(GetdeviceRenderAreaCount);
    static NAN_SETTER(SetdeviceRenderAreaCount);
    
    std::vector<VkRect2D>* vpDeviceRenderAreas;
    Nan::Persistent<v8::Array, v8::CopyablePersistentTraits<v8::Array>> pDeviceRenderAreas;
    static NAN_GETTER(GetpDeviceRenderAreas);
    static NAN_SETTER(SetpDeviceRenderAreas);
    

    // real instance
    VkDeviceGroupRenderPassBeginInfo instance = {};

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    bool flush(void);

  private:

    _VkDeviceGroupRenderPassBeginInfo();
    ~_VkDeviceGroupRenderPassBeginInfo();

};

#endif