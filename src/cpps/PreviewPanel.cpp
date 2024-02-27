#include "PreviewPanel.h"
#include <imgui.h>


#include <iostream>
#include <map>
#ifdef _DEBUG
#define LOG(message, value) std::cout << message << " : " << value << std::endl
#else
#define LOG(message, value)
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

ImVec4 RiverI::PreviewPanel::getContrastRGBA(ImVec4 *color) {
	// x y z w
	return ImVec4(color->x + 0.3 > 1.0 ? color->x - 0.3 : color->x + 0.3, color->y + 0.3 > 1.0 ? color->y - 0.3 : color->y + 0.3, color->z + 0.3 > 1.0 ? color->z - 0.3 : color->z + 0.3, color->w);
}


ImVec2 RiverI::PreviewPanel::getCursorForText(ImVec2 *parent_size,const char *text) {
	ImVec2  text_size =  ImGui::CalcTextSize(text);
	return ImVec2((parent_size->x / 2) - text_size.x, (parent_size->y / 2) - text_size.y);
}

void RiverI::PreviewPanel::Render(bool* V_Open, std::map<const char*, ImVec4*>* colors) {
	if (!ImGui::Begin("Preview Palete", V_Open, 0)) {
		ImGui::End();
		return;
	}
	//Declares
	auto windowWidth = ImGui::GetWindowSize().x * 0.99;
	auto windowHeight = ImGui::GetWindowSize().y;
	auto child_flags = ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_AutoResizeX;

	ImVec2 brand_size = ImVec2(windowWidth, windowHeight * 0.2);

	ImVec2 side_nav_size = ImVec2(windowWidth * 0.3, windowHeight * 0.7);
	ImVec2 side_nav_element_size = ImVec2(side_nav_size.x, (side_nav_size.y / 6) - 10);

	//ImVec2 panel_size = ImVec2(windowWidth * 0.7, ImGui::GetWindowSize().y * 0.8);
	ImVec2 panel_size = ImVec2(windowWidth * 0.7, windowHeight * 0.7);
	ImVec2 header_size = ImVec2(panel_size.x - 10, (panel_size.y * 0.1) - 10);
	ImVec2 lorem_size = ImVec2(panel_size.x - 10, (panel_size.y * 0.3));
	ImVec2 image_size = ImVec2((panel_size.x / 3) - 10, (panel_size.y * 0.3) - 10);

	int cur_width = 0;

	const char* text = "Text Hidden";
	ImVec2  text_size = ImGui::CalcTextSize(text);
	const char* lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
	ImVec2 footer_size = ImVec2(windowWidth, std::max(windowHeight - (panel_size.y + side_nav_size.y), text_size.y * 2));

	// Brand
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Brand")));
		ImGui::BeginChild("Branding", brand_size, child_flags);
			ImGui::SetCursorPos(ImVec2(getCursorForText(&brand_size,"Brand")));
			ImGui::TextColored(getContrastRGBA(colors->at("Brand")), "Brand");
		ImGui::EndChild();
	ImGui::PopStyleColor();


	// Side nav
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Side Menu")));
		ImGui::BeginChild("Side Nav", side_nav_size, child_flags);
			
			// Button Normal
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Button Normal")));
				ImGui::BeginChild("Button Normal", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Button Normal")));
					ImGui::TextColored(getContrastRGBA(colors->at("Button Normal")), "Button Normal");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			// Button Hover
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Button Hover")));
				ImGui::BeginChild("Button Hover", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Button Hover")));
					ImGui::TextColored(getContrastRGBA(colors->at("Button Hover")), "Button Hover");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			// Button Push
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Button Push")));
				ImGui::BeginChild("Button Push", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Button Push")));
					ImGui::TextColored(getContrastRGBA(colors->at("Button Push")), "Button Push");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			//Text Normal
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
				ImGui::BeginChild("Text Normal 0", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Text Normal")));
					ImGui::TextColored(*colors->at("Text Normal"), "Text Normal");
				ImGui::EndChild();
			ImGui::PopStyleColor();

			//Text Highlighted
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
				ImGui::BeginChild("Text Highlight 1", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Text Highlight")));
					ImGui::TextColored(*colors->at("Text Highlight"), "Text Highlight");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			//Accent 
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Accent")));
				ImGui::BeginChild("Accent", side_nav_element_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&side_nav_element_size, "Accent")));
					ImGui::TextColored(getContrastRGBA(colors->at("Accent")), "Accent");
				ImGui::EndChild();
			ImGui::PopStyleColor();


		ImGui::EndChild();
	ImGui::PopStyleColor();
	
	ImGui::SameLine();


	// Content Pane
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
		ImGui::BeginChild("Panel Nav", panel_size, child_flags);

			
			//Headder
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
				ImGui::BeginChild("Header", header_size);
					ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
					ImGui::SetCursorPos(ImVec2(0, header_size.y / 2));
					ImGui::TextColored(*colors->at("Header"), "This Is An Example Header");
				ImGui::EndChild();
			ImGui::PopStyleColor();
			
			
			//Lorem
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
				ImGui::BeginChild("Text Normal 1", lorem_size);
					ImGui::PushTextWrapPos(ImGui::GetCursorPos().x);
					ImGui::TextColored(*colors->at("Text Normal"), lorem);
				ImGui::EndChild();
			ImGui::PopStyleColor();

			//Image 1
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Image 1")));
				ImGui::BeginChild("Image 1", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Image 1")));
					ImGui::TextColored(getContrastRGBA(colors->at("Image 1")), "Image 1");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::SameLine();

			//Image 2
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Image 2")));
				ImGui::BeginChild("Image 2", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Image 2")));
					ImGui::TextColored(getContrastRGBA(colors->at("Image 2")), "Image 2");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::SameLine();

			//Image 3
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Image 3")));
				ImGui::BeginChild("Image 3", image_size);
					ImGui::SetCursorPos(ImVec2(getCursorForText(&image_size, "Image 3")));
					ImGui::TextColored(getContrastRGBA(colors->at("Image 3")), "Image 3");// replace Imvec4 with getNegativeRGBA
				ImGui::EndChild();
			ImGui::PopStyleColor();

			
			//Lorem
			ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Background")));
				ImGui::BeginChild("Text Normal 2", lorem_size);
					ImGui::PushTextWrapPos(ImGui::GetCursorPos().x);
					ImGui::TextColored(*colors->at("Text Normal"), lorem);
				ImGui::EndChild();
			ImGui::PopStyleColor();
		
			ImGui::EndChild();
	ImGui::PopStyleColor();


	

	//Footer
	ImGui::PushStyleColor(ImGuiCol_ChildBg, ImGui::ColorConvertFloat4ToU32(*colors->at("Footer")));
		ImGui::BeginChild("Footer", footer_size, child_flags);
		ImGui::PushItemWidth(77);
			while (footer_size.x > (cur_width += ImGui::CalcTextSize(text).x)) {
				ImGui::SetCursorPos(ImVec2(0, footer_size.y / 2));
				ImGui::SameLine(); ImGui::TextColored(*colors->at("Text Hidden"), text);
			} 
		ImGui::PopItemWidth();
		ImGui::EndChild();
	ImGui::PopStyleColor();

	ImGui::End();
}
