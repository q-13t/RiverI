#include "ColorEditor.h"
#include <imgui.h>
#include <map>
#include <iostream>

#ifdef _DEBUG
#define LOG(message, value) std::cout << message << " : " << value << std::endl
#else
#define LOG(message, value)
#endif // DEBUG

void RiverI::ColorEditor::HelpMarker(const char* desc) {
    ImGui::TextDisabled("(?)");

    if (ImGui::BeginItemTooltip()) {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
static bool printed = false;

void RiverI::ColorEditor::Render(bool* V_Open, std::map<const char*, ImVec4*>* colors) {
#ifdef _DEBUG
    if (!printed) {
          for (const auto& n : *colors)
              std::cout << n.first << " = " << n.second->x<<" " << n.second->y << " " << n.second->z << " " << n.second->w << "; \n";
        printed = true;
    }
#endif
    ImGuiWindowFlags window_flags = 0;

    if (!ImGui::Begin("Color Editor", V_Open, window_flags)){
        ImGui::End();
        return;
    }
    ImGui::SameLine(); HelpMarker(
        "Click on the color square to open a color picker.\n"
        "Click and hold to use drag and drop.\n"
        "Right-click on the color square to show options.\n"
        "CTRL+click on individual component to input value.\n");

    for (auto n : *colors) {
        ImGui::SeparatorText(n.first);
        if (ImGui::ColorEdit4(n.first, (float*)n.second));
    }
    ImGui::End();
}