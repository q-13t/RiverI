#ifndef PREVIEW_PANEL_H
#define PREVIEW_PANEL_H

#include <imgui.h>
#include <map>

namespace RiverI {
	class PreviewPanel {
	private:
		static void HelpMarker(const char* desc);
	public:
		static ImVec4 getNegativeRGBA(ImVec4* color);
		static ImVec2 getCursorForText(ImVec2* parent_size, const char* text);
		static void Render(bool* V_Open, std::map<const char*, ImVec4*>* colors);
	};
}
#endif