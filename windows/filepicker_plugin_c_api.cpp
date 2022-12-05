#include "include/filepicker/filepicker_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "filepicker_plugin.h"

void FilepickerPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  filepicker::FilepickerPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
