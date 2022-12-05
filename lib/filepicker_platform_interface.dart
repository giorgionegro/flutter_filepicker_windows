import 'package:flutter/services.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'filepicker_method_channel.dart';

abstract class FilepickerPlatform extends PlatformInterface {
  /// Constructs a FilepickerPlatform.
  FilepickerPlatform() : super(token: _token);

  static final Object _token = Object();

  static FilepickerPlatform _instance = MethodChannelFilepicker();

  /// The default instance of [FilepickerPlatform] to use.
  ///
  /// Defaults to [MethodChannelFilepicker].
  static FilepickerPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FilepickerPlatform] when
  /// they register themselves.
  static set instance(FilepickerPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  /// Gets the platform version.
  Future<String?> getPlatformVersion() {
    throw UnimplementedError('getPlatformVersion() has not been implemented.');
  }

  /// Shows the file picker dialog.
  ///
  /// [allowedExtensions] is a list of allowed file extensions.
  ///
  /// [pickMultiple] indicates whether multiple files can be selected.
  Future<List<String>> showFilePicker(List<String> allowedExtensions,
      {bool pickMultiple = false});
}