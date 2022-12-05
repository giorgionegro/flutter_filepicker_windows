#include "filepicker_plugin.h"

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>
#include <windows.h>
#include <ShObjIdl.h>
#include <atlstr.h>
#include <string>
#include <vector>
#include <ShellAPI.h>

namespace filepicker {

	// static
	void FilepickerPlugin::RegisterWithRegistrar(





		flutter::PluginRegistrarWindows* registrar) {
		auto channel = std::make_unique<flutter::MethodChannel<>>(
			registrar->messenger(), "filepicker",
			&flutter::StandardMethodCodec::GetInstance());

		std::unique_ptr<FilepickerPlugin> plugin =
			std::make_unique<FilepickerPlugin>();

		channel->SetMethodCallHandler(
			[plugin_pointer = plugin.get()](const auto& call, auto result) {
				plugin_pointer->HandleMethodCall(call, std::move(result));
			});

		registrar->AddPlugin(std::move(plugin));



	}

	FilepickerPlugin::FilepickerPlugin() {}

	FilepickerPlugin::~FilepickerPlugin() {}

	void FilepickerPlugin::HandleMethodCall(
		const flutter::MethodCall<>& method_call,
		std::unique_ptr<flutter::MethodResult<>> result) {
		if (method_call.method_name().compare("showFilePicker") == 0) {
			// Get the arguments for the method call.
			const auto& args = method_call.arguments();
			const auto& arg_list = std::get_if<EncodableMap>(method_call.arguments());
			// Parse the arguments.
			auto allowed_types_string = std::get<std::string>(arg_list->at(EncodableValue("allowedExtensions")));
			auto pick_multiple = std::get<bool>(arg_list->find(EncodableValue("pickMultiple"))->second);
			// Open the file picker dialog.
			IFileOpenDialog* dialog;
			printf("showed dialog");
			HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, nullptr,
				CLSCTX_INPROC_SERVER,
				IID_IFileOpenDialog,
				reinterpret_cast<void**>(&dialog));			dialog->SetOptions(FOS_FORCEFILESYSTEM |
					(pick_multiple ? FOS_ALLOWMULTISELECT : 0));



			// Set the allowed file types.
			COMDLG_FILTERSPEC filter_spec;
			filter_spec.pszName = L"Allowed Files";
			int string_length = allowed_types_string.length() + 1;
            int buffer_size = MultiByteToWideChar(CP_UTF8, 0, allowed_types_string.c_str(), string_length, nullptr, 0);
            LPWSTR buffer = new WCHAR[buffer_size];
            MultiByteToWideChar(CP_UTF8, 0, allowed_types_string.c_str(), string_length, buffer, buffer_size);
            filter_spec.pszSpec = buffer;


			dialog->SetFileTypes(1, &filter_spec);
			//folder start should be program files


			// Show the dialog.
			if (FAILED(dialog->Show(nullptr))) {
				result->Error("Failed to show file picker");
				return;
			}


			// Get the selected file(s).
			IShellItemArray* item_array;
			if (FAILED(dialog->GetResults(&item_array))) {
				result->Error("Failed to get selected file(s)");
				return;
			}
			//manually count the number of items in the array
			DWORD count;
			item_array->GetCount(&count);




			// Get the selected file paths.
			std::vector<std::string> file_paths;
			for (DWORD i = 0; i < count; i++) {
				// Get the next selected file.
				IShellItem* item;
				if (FAILED(item_array->GetItemAt(i, &item))) {
					continue;
				}

				// Get the file path.
				LPWSTR path;
				if (FAILED(item->GetDisplayName(SIGDN_FILESYSPATH, &path))) {
					continue;

				}

				std::string path_string = CW2A(path);
				file_paths.push_back(path_string);
			}

			// Return the list of selected files.
			result->Success(flutter::EncodableList{ file_paths.begin(), file_paths.end() });
		}
		else {
			result->NotImplemented();
		}
	}

}  // namespace filepicker
