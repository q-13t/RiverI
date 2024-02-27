#include "FileOperator.h"
#include <imgui.h>
#include <iostream>
#include <fstream>
#include <map>
#include <thread>


#ifdef _DEBUG
#define LOG(message, value) std::cout << message << " : " << value << std::endl
#else
#define LOG(message, value)
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

static std::string decToHexa(int n) {
	char hexaDeciNum[2];
	int i = 0;
	while (n != 0) {
		int temp = 0;
		temp = n % 16;
		if (temp < 10) {
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	std::string hexCode = "";
	if (i == 2) {
		hexCode.push_back(hexaDeciNum[0]);
		hexCode.push_back(hexaDeciNum[1]);
	}
	else if (i == 1) {
		hexCode = "0";
		hexCode.push_back(hexaDeciNum[0]);
	}
	else if (i == 0) {
		hexCode = "00";
	}

	return hexCode;
}

static std::string convertRGBtoHex(int R, int G, int B) {
	if ((R >= 0 && R <= 255)
		&& (G >= 0 && G <= 255)
		&& (B >= 0 && B <= 255)) {
		std::string hexCode = "#";
		hexCode += decToHexa(R);
		hexCode += decToHexa(G);
		hexCode += decToHexa(B);
		return hexCode;
	}
	else { return "-1"; };
}

char curr_file_name[128];
int current_color_format = 0;
const char* color_format[] = { "RGBA", "HSVA", "HEX" };
int current_mapping_type = 0;
const char* mapping[] = { "JSON","Key Value" };
bool saving = false;

static void saveAsJSON(std::map<const char*, ImVec4*>* colors) {
	std::string fileName(curr_file_name);
	if (fileName.find(".json") == std::string::npos) {
		fileName += ".json";
	}

	std::ofstream file(fileName.c_str());
	if (!file.is_open()) return;

	file << "{" << "\n";

	switch (current_color_format) {
	case 0: {//RGBA
		for (auto iterable = colors->begin(); iterable != colors->end();) {
			file << "\"" << iterable->first << "\": \"" << std::round(iterable->second->x * 255.0f) << " " << std::round(iterable->second->y * 255.0f) << " " << std::round(iterable->second->z * 255.0f) << " " << std::round(iterable->second->w * 255.0f) << "\"";
			if (++iterable != colors->end()) file << ",\n"; else file << "\n";
		}
		break;
	}
	case 1: {//HSV
		for (auto iterable = colors->begin(); iterable != colors->end();) {
			float f[4] = { iterable->second->x , iterable->second->y , iterable->second->z, iterable->second->w  };
			ImGui::ColorConvertRGBtoHSV(f[0], f[1], f[2], f[0], f[1], f[2]);
			file << "\"" << iterable->first << "\": \"" << std::round( f[0] * 255) << " " << std::round(f[1] * 255) << " " << std::round(f[2] * 255) << " " << std::round(f[3] * 255) << "\"";
			if (++iterable != colors->end()) file << ",\n"; else file << "\n";
		}
		break;
	}
	case 2: {//HEX
		for (auto iterable = colors->begin(); iterable != colors->end();) {
			float f[4] = { std::round(iterable->second->x * 255.0f), std::round(iterable->second->y * 255.0f), std::round(iterable->second->z * 255.0f), std::round(iterable->second->w * 255.0f) };
			file << "\"" << iterable->first << "\": \"" << convertRGBtoHex(f[0], f[1], f[2]) << "\"";
			if (++iterable != colors->end()) file << ",\n"; else file << "\n";

		}
		break;
	}
	default: {break; }
	}

	file << "}" << "\n";
	file.close();
}

static void saveAsKeyValue(std::map<const char*, ImVec4*>* colors) {

	std::string fileName(curr_file_name);
	if (fileName.find(".txt") == std::string::npos) {
		fileName += ".txt";
	}

	std::ofstream file(fileName.c_str());
	if (!file.is_open()) return;

	switch (current_color_format) {
	case 0: {//RGBA
		for (auto const& iterable : *colors) {
			file << iterable.first << " = " << std::round(iterable.second->x * 255.0f) << " " << std::round(iterable.second->y * 255.0f) << " " << std::round(iterable.second->z * 255.0f) << " " << std::round(iterable.second->w * 255.0f) << "\n";
		}
		break;
	}
	case 1: {//HSV
		for (auto const& iterable : *colors) {
			float f[4] = { iterable.second->x , iterable.second->y , iterable.second->z, iterable.second->w };
			ImGui::ColorConvertRGBtoHSV(f[0], f[1], f[2], f[0], f[1], f[2]);
			file << iterable.first << " = " << std::round(f[0] * 255) << " " << std::round(f[1] * 255) << " " << std::round(f[2] * 255) << " " << std::round(f[3] * 255) << "\n";
		}
		break;
	}
	case 2: {//HEX		
		for (auto const& iterable : *colors) {
			float f[4] = { std::round(iterable.second->x * 255.0f), std::round(iterable.second->y * 255.0f), std::round(iterable.second->z * 255.0f), std::round(iterable.second->w * 255.0f) };
			file << iterable.first << " = " << convertRGBtoHex(f[0], f[1], f[2]) << "\n";
		}
		break;
	}
	default: {break; }
	}

	file.close();
}

static void doSave(std::map<const char*, ImVec4*>* colors) {
	LOG("In data", "");
	LOG("File Name", curr_file_name);
	LOG("Format", color_format[current_color_format]);
	LOG("File Type", mapping[current_mapping_type]);
	if (current_mapping_type == 0) {
		saveAsJSON(colors);
	}
	else {
		saveAsKeyValue(colors);
	}
	saving = false;
}


void RiverI::FileOperator::Render(bool* V_Open, std::map<const char*, ImVec4*>* colors) {
	ImGuiWindowFlags window_flags = 0;
	if (!ImGui::Begin("Save Pallete", V_Open, window_flags)) {
		ImGui::End();
		return;
	}

	ImGui::InputTextWithHint("File name", "Enter name here", curr_file_name, sizeof(curr_file_name));
	ImGui::Combo("Color Format", &current_color_format, color_format, ((int)(sizeof(color_format) / sizeof(*(color_format)))));
	ImGui::Combo("Mapping", &current_mapping_type, mapping, ((int)(sizeof(mapping) / sizeof(*(mapping)))));

	if (ImGui::Button("Save")) {
		if (!saving && strlen(curr_file_name) != 0) {
			saving = true;
			LOG("SAVING", saving);
			std::thread saving_thread(doSave, colors);
			saving_thread.detach();
		}
	}
	ImGui::End();
}
