#include <map>
#include <imgui.h>
#ifndef COLOR_EDITOR_H
#define COLOR_EDITOR_H

namespace RiverI {

	class ColorEditor {
	public:
		static void Render(bool* V_Open, std::map<const char*, ImVec4*>* colors);
	private:
		static void HelpMarker(const char* desc);
	};
}

#endif // !COLOR_EDITOR_H
