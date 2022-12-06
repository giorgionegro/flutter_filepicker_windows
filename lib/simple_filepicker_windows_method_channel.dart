import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'simple_filepicker_windows_platform_interface.dart';

/// An implementation of [SimpleFilepickerWindowsPlatform] that uses method channels.
class MethodChannelSimpleFilepickerWindows
    extends SimpleFilepickerWindowsPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('simple_filepicker_windows');
  static const MethodChannel _channel = MethodChannel('filepicker');
  @override
  Future<List<String>> showFilePicker(List<String> allowedExtensions,
      {bool pickMultiple = false}) async {
    //conver the list to a string like *.jpg;*.png;vlc.exe
    String allowedExtensionsString = allowedExtensions.join(';');

    final List<dynamic> result = await _channel.invokeMethod(
        'showFilePicker', <String, dynamic>{
      'allowedExtensions': allowedExtensionsString,
      'pickMultiple': pickMultiple
    });
    return result.cast<String>();
  }
}
