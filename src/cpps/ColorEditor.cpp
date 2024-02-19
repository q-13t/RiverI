#include "ColorEditor.h"
#include <imgui.h>

void RiverI::ColorEditor::Render(bool * V_Open){
    ImGuiWindowFlags window_flags = 0;

    if (!ImGui::Begin("Color Editor", V_Open, window_flags)){
        ImGui::End();
        return;
    }
    ImGui::End();
}
