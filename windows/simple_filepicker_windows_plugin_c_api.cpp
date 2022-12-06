#include "include/simple_filepicker_windows/simple_filepicker_windows_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "simple_filepicker_windows_plugin.h"

void SimpleFilepickerWindowsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  simple_filepicker_windows::SimpleFilepickerWindowsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
