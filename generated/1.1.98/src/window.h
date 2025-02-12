#ifndef __VK_WINDOW_H__
#define __VK_WINDOW_H__

#include <nan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanWindow: public Nan::ObjectWrap {

  public:

    static NAN_METHOD(New);

    int width = 480;
    int height = 320;
    std::string title = "undefined";

    double mouseLastX = 0;
    double mouseLastY = 0;

    // event callbacks
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onresize;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onfocus;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onclose;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onkeydown;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onkeyup;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onmousemove;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onmousewheel;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onmousedown;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> onmouseup;
    Nan::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function>> ondrop;

    GLFWwindow* instance;

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(v8::Local<v8::Object> exports);

    static NAN_METHOD(pollEvents);
    static NAN_METHOD(focus);
    static NAN_METHOD(close);
    static NAN_METHOD(shouldClose);
    static NAN_METHOD(createSurface);
    static NAN_METHOD(getRequiredInstanceExtensions);

    static NAN_GETTER(Gettitle);
    static NAN_SETTER(Settitle);

    static NAN_GETTER(Getwidth);
    static NAN_SETTER(Setwidth);

    static NAN_GETTER(Getheight);
    static NAN_SETTER(Setheight);

    static NAN_GETTER(Getonresize);
    static NAN_SETTER(Setonresize);

    static NAN_GETTER(Getonfocus);
    static NAN_SETTER(Setonfocus);

    static NAN_GETTER(Getonclose);
    static NAN_SETTER(Setonclose);

    static NAN_GETTER(Getonkeydown);
    static NAN_SETTER(Setonkeydown);

    static NAN_GETTER(Getonkeyup);
    static NAN_SETTER(Setonkeyup);

    static NAN_GETTER(Getonmousemove);
    static NAN_SETTER(Setonmousemove);

    static NAN_GETTER(Getonmousewheel);
    static NAN_SETTER(Setonmousewheel);

    static NAN_GETTER(Getonmousedown);
    static NAN_SETTER(Setonmousedown);

    static NAN_GETTER(Getonmouseup);
    static NAN_SETTER(Setonmouseup);

    static NAN_GETTER(Getondrop);
    static NAN_SETTER(Setondrop);

    static void onWindowResize(GLFWwindow*, int, int);
    static void onWindowFocus(GLFWwindow*, int);
    static void onWindowClose(GLFWwindow*);
    static void onWindowKeyPress(GLFWwindow*, int, int, int, int);
    static void onWindowMouseMove(GLFWwindow*, double, double);
    static void onWindowMouseWheel(GLFWwindow*, double, double);
    static void onWindowMouseButton(GLFWwindow*, int, int, int);
    static void onWindowDrop(GLFWwindow*, int, const char**);

  private:
    VulkanWindow();
    ~VulkanWindow();

};

Nan::Persistent<v8::FunctionTemplate> VulkanWindow::constructor;

VulkanWindow::VulkanWindow() {}
VulkanWindow::~VulkanWindow() {}

void VulkanWindow::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
  Nan::HandleScope scope;

  // constructor
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(VulkanWindow::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("VulkanWindow").ToLocalChecked());

  // prototype
  v8::Local<v8::ObjectTemplate> proto = ctor->PrototypeTemplate();

  Nan::SetPrototypeMethod(ctor, "pollEvents", pollEvents);
  Nan::SetPrototypeMethod(ctor, "focus", focus);
  Nan::SetPrototypeMethod(ctor, "close", close);
  Nan::SetPrototypeMethod(ctor, "shouldClose", shouldClose);
  Nan::SetPrototypeMethod(ctor, "createSurface", createSurface);
  Nan::SetPrototypeMethod(ctor, "getRequiredInstanceExtensions", getRequiredInstanceExtensions);

  SetPrototypeAccessor(proto, Nan::New("title").ToLocalChecked(), Gettitle, Settitle, ctor);
  SetPrototypeAccessor(proto, Nan::New("width").ToLocalChecked(), Getwidth, Setwidth, ctor);
  SetPrototypeAccessor(proto, Nan::New("height").ToLocalChecked(), Getheight, Setheight, ctor);

  SetPrototypeAccessor(proto, Nan::New("onresize").ToLocalChecked(), Getonresize, Setonresize, ctor);
  SetPrototypeAccessor(proto, Nan::New("onfocus").ToLocalChecked(), Getonfocus, Setonfocus, ctor);
  SetPrototypeAccessor(proto, Nan::New("onclose").ToLocalChecked(), Getonclose, Setonclose, ctor);
  SetPrototypeAccessor(proto, Nan::New("onkeydown").ToLocalChecked(), Getonkeydown, Setonkeydown, ctor);
  SetPrototypeAccessor(proto, Nan::New("onkeyup").ToLocalChecked(), Getonkeyup, Setonkeyup, ctor);
  SetPrototypeAccessor(proto, Nan::New("onmousemove").ToLocalChecked(), Getonmousemove, Setonmousemove, ctor);
  SetPrototypeAccessor(proto, Nan::New("onmousewheel").ToLocalChecked(), Getonmousewheel, Setonmousewheel, ctor);
  SetPrototypeAccessor(proto, Nan::New("onmousedown").ToLocalChecked(), Getonmousedown, Setonmousedown, ctor);
  SetPrototypeAccessor(proto, Nan::New("onmouseup").ToLocalChecked(), Getonmouseup, Setonmouseup, ctor);
  SetPrototypeAccessor(proto, Nan::New("ondrop").ToLocalChecked(), Getondrop, Setondrop, ctor);

  Nan::Set(target, Nan::New("VulkanWindow").ToLocalChecked(), ctor->GetFunction());
}

void VulkanWindow::onWindowResize(GLFWwindow* window, int w, int h) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  self->width = w;
  self->height = h;
  if (self->onresize.IsEmpty()) return;
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  out->Set(Nan::New("width").ToLocalChecked(), Nan::New(self->width));
  out->Set(Nan::New("height").ToLocalChecked(), Nan::New(self->height));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onresize), argc, argv);
}

void VulkanWindow::onWindowFocus(GLFWwindow* window, int focused) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  if (self->onfocus.IsEmpty()) return;
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  out->Set(Nan::New("focused").ToLocalChecked(), Nan::New(!!focused));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onfocus), argc, argv);
}

void VulkanWindow::onWindowClose(GLFWwindow* window) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  if (self->onclose.IsEmpty()) return;
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onclose), argc, argv);
}

void VulkanWindow::onWindowKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods) {
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  out->Set(Nan::New("keyCode").ToLocalChecked(), Nan::New(key));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  // press
  if (action == GLFW_PRESS) {
    if (!(self->onkeydown.IsEmpty())) {
      Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onkeydown), argc, argv);
    }
  }
  // release
  else if (action == GLFW_RELEASE) {
    if (!(self->onkeyup.IsEmpty())) {
      Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onkeyup), argc, argv);
    }
  }
}

void VulkanWindow::onWindowMouseMove(GLFWwindow* window, double x, double y) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  double movementX = self->mouseLastX - x;
  double movementY = self->mouseLastY - y;
  self->mouseLastX = x;
  self->mouseLastY = y;
  if (self->onmousemove.IsEmpty()) return;
  out->Set(Nan::New("x").ToLocalChecked(), Nan::New(x));
  out->Set(Nan::New("y").ToLocalChecked(), Nan::New(y));
  out->Set(Nan::New("movementX").ToLocalChecked(), Nan::New(movementX));
  out->Set(Nan::New("movementY").ToLocalChecked(), Nan::New(movementY));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onmousemove), argc, argv);
}

void VulkanWindow::onWindowMouseWheel(GLFWwindow* window, double deltaX, double deltaY) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  if (self->onmousewheel.IsEmpty()) return;
  double mouseX = 0;
  double mouseY = 0;
  glfwGetCursorPos(window, &mouseX, &mouseY);
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  out->Set(Nan::New("x").ToLocalChecked(), Nan::New(mouseX));
  out->Set(Nan::New("y").ToLocalChecked(), Nan::New(mouseY));
  out->Set(Nan::New("deltaX").ToLocalChecked(), Nan::New(deltaX));
  out->Set(Nan::New("deltaY").ToLocalChecked(), Nan::New(deltaY));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onmousewheel), argc, argv);
}

void VulkanWindow::onWindowMouseButton(GLFWwindow* window, int button, int action, int mods) {
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  double mouseX = 0;
  double mouseY = 0;
  glfwGetCursorPos(window, &mouseX, &mouseY);
  out->Set(Nan::New("x").ToLocalChecked(), Nan::New(mouseX));
  out->Set(Nan::New("y").ToLocalChecked(), Nan::New(mouseY));
  out->Set(Nan::New("button").ToLocalChecked(), Nan::New(button));
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  // press
  if (action == GLFW_PRESS) {
    if (!(self->onmousedown.IsEmpty())) {
      Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onmousedown), argc, argv);
    }
  }
  // release
  else if (action == GLFW_RELEASE) {
    if (!(self->onmouseup.IsEmpty())) {
      Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->onmouseup), argc, argv);
    }
  }
}

void VulkanWindow::onWindowDrop(GLFWwindow* window, int count, const char** paths) {
  v8::Isolate *isolate = v8::Isolate::GetCurrent();
  VulkanWindow* self = static_cast<VulkanWindow*>(glfwGetWindowUserPointer(window));
  if (self->ondrop.IsEmpty()) return;
  v8::Local<v8::Object> out = Nan::New<v8::Object>();
  // fill paths
  v8::Local<v8::Array> arr = v8::Array::New(isolate, count);
  unsigned int len = count;
  for (unsigned int ii = 0; ii < len; ++ii) {
    v8::Local<v8::String> str = v8::String::NewFromUtf8(isolate, paths[ii]);
    arr->Set(ii, str);
  };
  // add to out obj
  out->Set(Nan::New("paths").ToLocalChecked(), arr);
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { out };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), Nan::New(self->ondrop), argc, argv);
}

NAN_METHOD(VulkanWindow::New) {
  VulkanWindow* self = new VulkanWindow();
  self->Wrap(info.Holder());
  // create glfw window
  if (info.IsConstructCall()) {
    // init glfw
    if (glfwInit() != GLFW_TRUE) return Nan::ThrowError("Failed to init GLFW!");
    // process arguments
    // Nan::New(VkApplicationInfo::constructor)->HasInstance(Nan::To<v8::Object>(info[0]).ToLocalChecked()))
    if (info[0]->IsObject()) {
      v8::Local<v8::Object> obj = Nan::To<v8::Object>(info[0]).ToLocalChecked();
      v8::Local<v8::Value> argWidth = obj->Get(Nan::New("width").ToLocalChecked());
      v8::Local<v8::Value> argHeight = obj->Get(Nan::New("height").ToLocalChecked());
      v8::Local<v8::Value> argTitle = obj->Get(Nan::New("title").ToLocalChecked());
      if (!argWidth->IsUndefined()) self->width = Nan::To<uint32_t>(argWidth).FromMaybe(0);
      if (!argHeight->IsUndefined()) self->height = Nan::To<uint32_t>(argHeight).FromMaybe(0);
      if (!argTitle->IsUndefined()) self->title = *v8::String::Utf8Value(v8::Isolate::GetCurrent(), argTitle);
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    GLFWwindow* window = glfwCreateWindow(self->width, self->height, self->title.c_str(), nullptr, nullptr);
    self->instance = window;
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, self);
    // window events
    glfwSetWindowSizeCallback(window, VulkanWindow::onWindowResize);
    glfwSetWindowFocusCallback(window, VulkanWindow::onWindowFocus);
    glfwSetWindowCloseCallback(window, VulkanWindow::onWindowClose);
    // keyboard events
    glfwSetKeyCallback(window, VulkanWindow::onWindowKeyPress);
    // mouse events
    glfwSetCursorPosCallback(window, VulkanWindow::onWindowMouseMove);
    glfwSetScrollCallback(window, VulkanWindow::onWindowMouseWheel);
    glfwSetMouseButtonCallback(window, VulkanWindow::onWindowMouseButton);
    // file drop
    glfwSetDropCallback(window, VulkanWindow::onWindowDrop);
  }
  info.GetReturnValue().Set(info.Holder());
}

NAN_METHOD(VulkanWindow::shouldClose) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  info.GetReturnValue().Set(Nan::New((bool)glfwWindowShouldClose(window)));
}

NAN_METHOD(VulkanWindow::focus) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  glfwFocusWindow(window);
}

NAN_METHOD(VulkanWindow::close) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  glfwSetWindowShouldClose(window, GLFW_TRUE);
  VulkanWindow::onWindowClose(window);
}

NAN_METHOD(VulkanWindow::pollEvents) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  if (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}

NAN_METHOD(VulkanWindow::createSurface) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());

  v8::Local<v8::Object> arg0;
  v8::Local<v8::Object> arg1;
  v8::Local<v8::Object> arg2;

  if (info[0]->IsObject()) arg0 = Nan::To<v8::Object>(info[0]).ToLocalChecked();
  if (info[1]->IsObject()) arg1 = Nan::To<v8::Object>(info[1]).ToLocalChecked();
  if (info[2]->IsObject()) arg2 = Nan::To<v8::Object>(info[2]).ToLocalChecked();

  _VkInstance* instance = Nan::ObjectWrap::Unwrap<_VkInstance>(arg0);
  _VkSurfaceKHR* surface = Nan::ObjectWrap::Unwrap<_VkSurfaceKHR>(arg2);

  VkResult out = glfwCreateWindowSurface(
    instance->instance,
    self->instance,
    nullptr,
    &surface->instance
  );

  info.GetReturnValue().Set(Nan::New(static_cast<int32_t>(out)));
}

NAN_METHOD(VulkanWindow::getRequiredInstanceExtensions) {
  v8::Isolate *isolate = info.GetIsolate();
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  v8::Local<v8::Array> out = v8::Array::New(isolate, glfwExtensionCount);
  for (unsigned int ii = 0; ii < glfwExtensionCount; ++ii) {
    v8::Local<v8::String> str = v8::String::NewFromUtf8(isolate, glfwExtensions[ii]);
    out->Set(ii, str);
  };

  info.GetReturnValue().Set(out);
}

// title
NAN_GETTER(VulkanWindow::Gettitle) {
  v8::Isolate *isolate = info.GetIsolate();
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  v8::Local<v8::String> str = v8::String::NewFromUtf8(isolate, self->title.c_str());
  info.GetReturnValue().Set(str);
}
NAN_SETTER(VulkanWindow::Settitle) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;

  v8::Local<v8::Value> argTitle = value;
  std::string title = *v8::String::Utf8Value(v8::Isolate::GetCurrent(), argTitle);
  glfwSetWindowTitle(window, title.c_str());
  self->title = title;
}

// width
NAN_GETTER(VulkanWindow::Getwidth) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->width));
}
NAN_SETTER(VulkanWindow::Setwidth) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  self->width = static_cast<int>(Nan::To<uint32_t>(value).FromMaybe(0));
  glfwSetWindowSize(window, self->width, self->height);
  VulkanWindow::onWindowResize(window, self->width, self->height);
}

// height
NAN_GETTER(VulkanWindow::Getheight) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  info.GetReturnValue().Set(Nan::New<v8::Number>(self->height));
}
NAN_SETTER(VulkanWindow::Setheight) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  GLFWwindow* window = self->instance;
  self->height = static_cast<int>(Nan::To<uint32_t>(value).FromMaybe(0));
  glfwSetWindowSize(window, self->width, self->height);
  VulkanWindow::onWindowResize(window, self->width, self->height);
}

// onresize
NAN_GETTER(VulkanWindow::Getonresize) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onresize.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onresize));
}
NAN_SETTER(VulkanWindow::Setonresize) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onresize.Reset<v8::Function>(value.As<v8::Function>());
  else self->onresize.Reset();
}

// onfocus
NAN_GETTER(VulkanWindow::Getonfocus) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onfocus.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onfocus));
}
NAN_SETTER(VulkanWindow::Setonfocus) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onfocus.Reset<v8::Function>(value.As<v8::Function>());
  else self->onfocus.Reset();
}

// onclose
NAN_GETTER(VulkanWindow::Getonclose) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onclose.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onclose));
}
NAN_SETTER(VulkanWindow::Setonclose) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onclose.Reset<v8::Function>(value.As<v8::Function>());
  else self->onclose.Reset();
}

// onkeydown
NAN_GETTER(VulkanWindow::Getonkeydown) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onkeydown.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onkeydown));
}
NAN_SETTER(VulkanWindow::Setonkeydown) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onkeydown.Reset<v8::Function>(value.As<v8::Function>());
  else self->onkeydown.Reset();
}

// onkeyup
NAN_GETTER(VulkanWindow::Getonkeyup) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onkeyup.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onkeyup));
}
NAN_SETTER(VulkanWindow::Setonkeyup) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onkeyup.Reset<v8::Function>(value.As<v8::Function>());
  else self->onkeyup.Reset();
}

// onmousemove
NAN_GETTER(VulkanWindow::Getonmousemove) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onmousemove.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onmousemove));
}
NAN_SETTER(VulkanWindow::Setonmousemove) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onmousemove.Reset<v8::Function>(value.As<v8::Function>());
  else self->onmousemove.Reset();
}

// onmousewheel
NAN_GETTER(VulkanWindow::Getonmousewheel) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onmousewheel.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onmousewheel));
}
NAN_SETTER(VulkanWindow::Setonmousewheel) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onmousewheel.Reset<v8::Function>(value.As<v8::Function>());
  else self->onmousewheel.Reset();
}

// onmousedown
NAN_GETTER(VulkanWindow::Getonmousedown) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onmousedown.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onmousedown));
}
NAN_SETTER(VulkanWindow::Setonmousedown) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onmousedown.Reset<v8::Function>(value.As<v8::Function>());
  else self->onmousedown.Reset();
}

// onmouseup
NAN_GETTER(VulkanWindow::Getonmouseup) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->onmouseup.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->onmouseup));
}
NAN_SETTER(VulkanWindow::Setonmouseup) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->onmouseup.Reset<v8::Function>(value.As<v8::Function>());
  else self->onmouseup.Reset();
}

// ondrop
NAN_GETTER(VulkanWindow::Getondrop) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (self->ondrop.IsEmpty()) info.GetReturnValue().SetNull();
  else info.GetReturnValue().Set(Nan::New<v8::Function>(self->ondrop));
}
NAN_SETTER(VulkanWindow::Setondrop) {
  VulkanWindow *self = Nan::ObjectWrap::Unwrap<VulkanWindow>(info.This());
  if (value->IsFunction()) self->ondrop.Reset<v8::Function>(value.As<v8::Function>());
  else self->ondrop.Reset();
}

#endif
