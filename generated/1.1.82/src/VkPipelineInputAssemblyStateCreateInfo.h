/*
 * MACHINE GENERATED, DO NOT EDIT
 * GENERATED BY node-vulkan v0.0.1
 */
#ifndef __VK_VKPIPELINEINPUTASSEMBLYSTATECREATEINFO_H__
#define __VK_VKPIPELINEINPUTASSEMBLYSTATECREATEINFO_H__

#include <nan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class _VkPipelineInputAssemblyStateCreateInfo: public Nan::ObjectWrap {

  public:
    // #methods
    static NAN_METHOD(New);
    // #accessors
    static NAN_GETTER(GetsType);
    static NAN_SETTER(SetsType);
    
    static NAN_GETTER(Getflags);
    static NAN_SETTER(Setflags);
    
    static NAN_GETTER(Gettopology);
    static NAN_SETTER(Settopology);
    
    static NAN_GETTER(GetprimitiveRestartEnable);
    static NAN_SETTER(SetprimitiveRestartEnable);
    

    // real instance
    VkPipelineInputAssemblyStateCreateInfo instance = {};

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);

  private:
    _VkPipelineInputAssemblyStateCreateInfo();
    ~_VkPipelineInputAssemblyStateCreateInfo();

};

#endif