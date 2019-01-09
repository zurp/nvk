/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY node-vulkan v0.1.0
 */
#ifndef __VK_VKPHYSICALDEVICEFRAGMENTDENSITYMAPPROPERTIESEXT_H__
#define __VK_VKPHYSICALDEVICEFRAGMENTDENSITYMAPPROPERTIESEXT_H__

#include <nan.h>

#include <vulkan/vulkan_win32.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class _VkPhysicalDeviceFragmentDensityMapPropertiesEXT: public Nan::ObjectWrap {

  public:
    // #methods
    static NAN_METHOD(New);
    // #accessors
    static NAN_GETTER(GetsType);
      Nan::Persistent<v8::Object, v8::CopyablePersistentTraits<v8::Object>> minFragmentDensityTexelSize;
      static NAN_GETTER(GetminFragmentDensityTexelSize);
      Nan::Persistent<v8::Object, v8::CopyablePersistentTraits<v8::Object>> maxFragmentDensityTexelSize;
      static NAN_GETTER(GetmaxFragmentDensityTexelSize);
    static NAN_GETTER(GetfragmentDensityInvocations);

    // real instance
    VkPhysicalDeviceFragmentDensityMapPropertiesEXT instance = {};

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    bool flush(void);

  private:

    _VkPhysicalDeviceFragmentDensityMapPropertiesEXT();
    ~_VkPhysicalDeviceFragmentDensityMapPropertiesEXT();

};

#endif