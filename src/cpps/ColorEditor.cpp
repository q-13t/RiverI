#include "ColorEditor.h"
#include <imgui.h>

void RiverI::ColorEditor::HelpMarker(const char* desc) {
    ImGui::TextDisabled("(?)");

    if (ImGui::BeginItemTooltip()) {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void RiverI::ColorEditor::Render(bool* V_Open, float (*arr_color)[16][4]) {
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

    ImGui::SeparatorText("Brand");
    ImGui::ColorEdit4("Brand", *arr_color[0]);

    ImGui::SeparatorText("Background");
    ImGui::ColorEdit4("Background", *arr_color[1]);

    ImGui::SeparatorText("Text Normal");
    ImGui::ColorEdit4("Text Normal", *arr_color[2]);

    ImGui::SeparatorText("Text Highlight");
    ImGui::ColorEdit4("Text Highlight", *arr_color[3]);

    ImGui::SeparatorText("Text Hidden");
    ImGui::ColorEdit4("Text Hidden", *arr_color[4]);

    ImGui::SeparatorText("Header");
    ImGui::ColorEdit4("Header", *arr_color[5]);

    ImGui::SeparatorText("Accent");
    ImGui::ColorEdit4("Accent", *arr_color[6]);

    ImGui::SeparatorText("Side Menu");
    ImGui::ColorEdit4("Side Menu", *arr_color[7]);

    ImGui::SeparatorText("Top Menu");
    ImGui::ColorEdit4("Top Menu", *arr_color[8]);

    ImGui::SeparatorText("Footer");
    ImGui::ColorEdit4("Footer", *arr_color[9]);

    ImGui::SeparatorText("Button Normal");
    ImGui::ColorEdit4("Button Normal", *arr_color[10]);

    ImGui::SeparatorText("Button Hover");
    ImGui::ColorEdit4("Button Hover", *arr_color[11]);

    ImGui::SeparatorText("Button Push");
    ImGui::ColorEdit4("Button Push", *arr_color[12]);

    ImGui::SeparatorText("Image 1");
    ImGui::ColorEdit4("Image 1", *arr_color[13]);

    ImGui::SeparatorText("Image 2");
    ImGui::ColorEdit4("Image 2", *arr_color[14]);

    ImGui::SeparatorText("Image 3");
    ImGui::ColorEdit4("Image 3", *arr_color[15]);

    ImGui::End();
}


