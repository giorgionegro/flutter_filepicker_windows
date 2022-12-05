
import 'filepicker_platform_interface.dart';

class Filepicker {


  /// Shows the file picker dialog.
  ///
  /// [allowedExtensions] is a list of allowed file extensions.
  ///
  /// [pickMultiple] indicates whether multiple files can be selected.
  static Future<List<String>> showFilePicker(List<String> allowedExtensions,
      { bool pickMultiple = false}) async {
    return await FilepickerPlatform.instance.showFilePicker(
        allowedExtensions,
        pickMultiple: pickMultiple);
  }
}

