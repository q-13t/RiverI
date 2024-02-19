#include "FileOperator.h"
#include <imgui.h>


#ifdef _DEBUG
#include <iostream>
#define LOG(message, value) std::cout << message << " : " << value << std::endl
#endif // DEBUG

void RiverI::FileOperator::HelpMarker(const char* desc) {
	ImGui::TextDisabled("(?)");

	if (ImGui::BeginItemTooltip()) {
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void RiverI::FileOperator::Render(bool* V_Open) {
	ImGuiWindowFlags window_flags = 0;
	if (!ImGui::Begin("Save Pallete", V_Open, window_flags)) {
		ImGui::End();
		return;
	}
	static char carr_file_name[128] = "";
	static int current_format = 0;
	static int current_file_type = 0;
	const char* formats[] = { "RGBA", "CMYK", "HSV" };
	const char* fileTypes[] = { "JSON","Key Value" };

	ImGui::InputTextWithHint("File name", "Enter name here", carr_file_name, sizeof(carr_file_name));
	ImGui::Combo("Format", &current_format, formats, ((int)(sizeof(formats) / sizeof(*(formats)))));
	ImGui::Combo("File", &current_file_type, fileTypes, ((int)(sizeof(fileTypes) / sizeof(*(fileTypes)))));

	if (ImGui::Button("Save")) {
		LOG("In data", "");
		LOG("File Name", carr_file_name);
		LOG("Format", formats[current_format]);
		LOG("File Type", fileTypes[current_file_type]);

		//TODO: imp save file bg thread
	}
	ImGui::End();
}
