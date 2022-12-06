import 'dart:async';

import 'simple_filepicker_windows_platform_interface.dart';

class SimpleFilepickerWindows {
  /// Shows the file picker dialog.
  ///
  /// [allowedExtensions] is a list of allowed file extensions.
  ///
  /// [pickMultiple] indicates whether multiple files can be selected.
  static Future<List<String>> showFilePicker(List<String> allowedExtensions,
      {bool pickMultiple = false}) async {
    return (await SimpleFilepickerWindowsPlatform.instance
        .showFilePicker(allowedExtensions, pickMultiple: pickMultiple));
  }
}
