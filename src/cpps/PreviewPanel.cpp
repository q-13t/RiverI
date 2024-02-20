#include "PreviewPanel.h"
#include <imgui.h>


#include <iostream>
#ifdef _DEBUG
#define LOG(message, value) std::cout << message << " : " << value << std::endl
#endif // DEBUG

void RiverI::PreviewPanel::HelpMarker(const char* desc) {
	ImGui::TextDisabled("(?)");

	if (ImGui::BeginItemTooltip()) {
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

ImVec4 RiverI::PreviewPanel::getNegativeRGBA(ImVec4 *color) {
	return ImVec4(std::abs(255 - color->w), std::abs(255 - color->x), std::abs(255 - color->y), color->z);
}


ImVec2 RiverI::PreviewPanel::getCursorForText(ImVec2 *parent_size,const char *text) {
	ImVec2  text_size =  ImGui::CalcTextSize(text);
	return ImVec2((parent_size->x / 2) - text_size.x, (parent_size->y / 2) - text_size.y);
}

void RiverI::PreviewPanel::Render(bool* V_Open) {
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollWithMouse;
	if (!ImGui::Begin("Preview Palete", V_Open, 0)) {
		ImGui::End();
		return;
	}
	//Declares
	auto windowWidth = ImGui::GetWindowSize().x * 0.99;
	auto windowHeight = ImGui::GetWindowSize().y;
	auto child_flags = ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AutoResizeX;

	ImVec2 brand_size = ImVec2(windowWidth, windowHeight * 0.1);
	ImVec4 tmpCol = ImVec4(0.129f, 0.129f, 0.129f, 1.000f);

	// Brand
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(tmpCol));
		ImGui::BeginChild("Branding", brand_size, child_flags);
			ImGui::SetCursorPos(ImVec2(getCursorForText(&brand_size,"Brand")));
			ImGui::TextColored(ImVec4(255, 150, 0, 100), "Brand");//TODO : replace temp color
		ImGui::EndChild();
	ImGui::PopStyleColor();


	ImVec2 side_nav_size = ImVec2(windowWidth * 0.3, ImGui::GetWindowSize().y * 0.8);
	ImVec2 side_nav_element_size = ImVec2(side_nav_size.x, (side_nav_size.y / 5));// TODO: replace 5 with elements

	// Side nav
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(tmpCol));
		ImGui::BeginChild("Side Nav", side_nav_size, child_flags);
			
			ImVec4 Color_A = ImVec4(255, 150, 0, 100);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_A));
				ImGui::BeginChild("Color A", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Color A")));
					ImGui::TextColored(getNegativeRGBA(&Color_A), "Color A");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			ImVec4 Color_B = ImVec4(255,255,255,255);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_B));
				ImGui::BeginChild("Color B", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Color B")));
					ImGui::TextColored(getNegativeRGBA(&Color_B), "Color B");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			ImVec4 Color_C = ImVec4(0, 150, 0, 100);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_C));
				ImGui::BeginChild("Color C", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Color C")));
					ImGui::TextColored(getNegativeRGBA(&Color_C), "Color C");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			ImVec4 Color_D = ImVec4(255, 150, 100, 100);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_D));
				ImGui::BeginChild("Color D", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Color D")));
					ImGui::TextColored(getNegativeRGBA(&Color_D), "Color D");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

		ImGui::EndChild();
	ImGui::PopStyleColor();
	
	ImGui::SameLine();

	ImVec2 panel_size = ImVec2(windowWidth * 0.7, ImGui::GetWindowSize().y * 0.8);
	ImVec2 header_size = ImVec2(panel_size.x - 10, (panel_size.y * 0.1) - 10);
	ImVec2 lorem_size = ImVec2(panel_size.x - 10, (panel_size.y * 0.3) );
	ImVec2 image_size = ImVec2((panel_size.x / 3) - 10, (panel_size.y * 0.3) - 10);

	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(tmpCol));
		ImGui::BeginChild("Panel Nav", panel_size, child_flags);

			ImVec4 Color_Black = ImVec4(33, 33, 33, 255);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));//Headder
				ImGui::BeginChild("Color 1", header_size);
					ImGui::SetCursorPos(ImVec2(0, header_size.y / 2));
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			//ImVec4 Color_Black = ImVec4(255, 150, 100, 100);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));//Lorem
				ImGui::BeginChild("Color 2", lorem_size);
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");
				ImGui::EndChild();
			ImGui::PopStyleColor();

			//ImVec4 Color_Black = ImVec4(255, 150, 100, 100);//Image 1
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));
				ImGui::BeginChild("Color 3", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Color D")));
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::SameLine();
			//ImVec4 Color_Black = ImVec4(255, 150, 100, 100); //Image 2
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));
				ImGui::BeginChild("Color 4", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Color D")));
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::SameLine();
			//ImVec4 Color_Black = ImVec4(255, 150, 100, 100);//Image 3
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));
				ImGui::BeginChild("Color 5", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Color D")));
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			//ImVec4 Color_Black = ImVec4(255, 150, 100, 100);
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(Color_Black));//Lorem
				ImGui::BeginChild("Color 6", lorem_size);
					ImGui::TextColored(getNegativeRGBA(&Color_Black), "Color D");
				ImGui::EndChild();
			ImGui::PopStyleColor();
		
			ImGui::EndChild();
	ImGui::PopStyleColor();


	const char* text = "Text Hidden";
	int cur_width = 0;
	ImVec2  text_size = ImGui::CalcTextSize(text);
	ImVec2 footer_size = ImVec2(windowWidth ,std::max(windowHeight - (panel_size.y + side_nav_size.y), text_size.y * 2));

	//Footer
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(tmpCol));
		ImGui::BeginChild("Footer", footer_size, child_flags);
		ImGui::PushItemWidth(77);
			while (footer_size.x > (cur_width += ImGui::CalcTextSize(text).x)) {
				ImGui::SetCursorPos(ImVec2(0, footer_size.y / 2));
				ImGui::SameLine(); ImGui::TextColored(getNegativeRGBA(&tmpCol), text);
			} 
		ImGui::PopItemWidth();
		ImGui::EndChild();
	ImGui::PopStyleColor();

	ImGui::End();
}
