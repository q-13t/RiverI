#ifndef COLOR_EDITOR_H
#define COLOR_EDITOR_H

namespace RiverI {

	class ColorEditor {
	public:
		static void Render(bool* V_Open, float(*arr_color)[16][4]);
	private:
		static void HelpMarker(const char* desc);
	};
}

#endif // !COLOR_EDITOR_H
