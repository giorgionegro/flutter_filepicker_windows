#ifndef FILEPICKER_PLUGIN_H
#define FILEPICKER_PLUGIN_H

#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>
#include <flutter/method_channel.h>
#include <flutter/method_call.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>
#include <flutter/method_channel.h>
#include <flutter/method_call.h>
#include <flutter/method_result.h>
#include <flutter/plugin_registrar_windows.h>


#include <Windows.h>

#include <memory>
#include <vector>

using namespace flutter;

namespace filepicker {

class FilepickerPlugin  : public flutter::Plugin{
 public:
  static void RegisterWithRegistrar(PluginRegistrarWindows *registrar);

  FilepickerPlugin();

virtual
  ~FilepickerPlugin();

  void HandleMethodCall(
      const MethodCall<EncodableValue> &method_call,
std::unique_ptr<flutter::MethodResult<>> result);};

}  // namespace filepicker

#endif  // FILEPICKER_PLUGIN_H
