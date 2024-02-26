#include "ColorEditor.h"
#include <imgui.h>
#include <map>
#include <iostream>

#ifdef _DEBUG
#define LOG(message, value) std::cout << message << " : " << value << std::endl
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
              std::cout << n.first << " = " << n.second->w << n.second->x << n.second->y << n.second->z << "; \n";
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
        float arr[4] = { n.second->x, n.second->y, n.second->y, n.second->w };
        if (ImGui::ColorEdit4(n.first, arr)) {
            LOG("arr[3]:", arr[3]);
            n.second->x = arr[0];
            n.second->y = arr[1];
            n.second->z = arr[2];
            n.second->w = arr[3];
        }
    }
    ImGui::End();
}