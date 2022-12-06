# simple_filepicker_windows

simple filepicker plugin for windows without any dependencies(hopefully)



## Usage

```
import 'package:simple_filepicker_windows/simple_filepicker_windows.dart';

void main() {
  final files = SimpleFilePickerWindows.showFilePicker(["*.png","*.pdf","myfile.*","mydocument.txt"],pickMultiple: false);
  print(files);
}
```


## Version History

* 1.0.0 - Initial release
* 1.0.0+7 - null safety
* 1.0.0+8 - small fixes
