#ifndef FLUTTER_PLUGIN_SIMPLE_FILEPICKER_WINDOWS_PLUGIN_H_
#define FLUTTER_PLUGIN_SIMPLE_FILEPICKER_WINDOWS_PLUGIN_H_

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
namespace simple_filepicker_windows {

class SimpleFilepickerWindowsPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(PluginRegistrarWindows *registrar);

  SimpleFilepickerWindowsPlugin();

virtual
  ~SimpleFilepickerWindowsPlugin();

  void HandleMethodCall(
      const MethodCall<EncodableValue> &method_call,
std::unique_ptr<flutter::MethodResult<>> result);};

}  // namespace filepicker

#endif  // FILEPICKER_PLUGIN_H
