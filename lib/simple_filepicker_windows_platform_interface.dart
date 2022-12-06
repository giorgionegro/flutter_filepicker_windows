import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'simple_filepicker_windows_method_channel.dart';

abstract class SimpleFilepickerWindowsPlatform extends PlatformInterface {
  /// Constructs a SimpleFilepickerWindowsPlatform.
  SimpleFilepickerWindowsPlatform() : super(token: _token);

  static final Object _token = Object();

  static SimpleFilepickerWindowsPlatform _instance =
      MethodChannelSimpleFilepickerWindows();

  /// The default instance of [SimpleFilepickerWindowsPlatform] to use.
  ///
  /// Defaults to [MethodChannelSimpleFilepickerWindows].
  static SimpleFilepickerWindowsPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [SimpleFilepickerWindowsPlatform] when
  /// they register themselves.
  static set instance(SimpleFilepickerWindowsPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<List<String>> showFilePicker(List<String> allowedExtensions,
      {bool pickMultiple = false});
}
