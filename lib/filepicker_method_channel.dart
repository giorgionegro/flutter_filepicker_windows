import 'package:filepicker/filepicker_platform_interface.dart';
import 'package:flutter/services.dart';

class MethodChannelFilepicker extends FilepickerPlatform {
  static const MethodChannel _channel =
  const MethodChannel('filepicker');

  @override
  Future<String?> getPlatformVersion() async {
    final String? result =
    await _channel.invokeMethod('getPlatformVersion');
    return result;
  }

  @override
  Future<List<String>> showFilePicker(List<String> allowedExtensions,
      {bool pickMultiple = false}) async {
    //conver the list to a string like *.jpg;*.png;vlc.exe
    String allowedExtensionsString = allowedExtensions.join(';');



    final List<dynamic> result = await _channel.invokeMethod('showFilePicker',
        <String, dynamic>{'allowedExtensions': allowedExtensionsString, 'pickMultiple': pickMultiple});
    return result.cast<String>();
  }
}