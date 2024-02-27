#ifndef FILE_OPERATOR_H
#define FILE_OPERATOR_H

#include <imgui.h>
#include <map>

namespace RiverI {
	class FileOperator {
	private:
		static void HelpMarker(const char* desc);
	public:
		static void Render(bool* V_Open, std::map<const char*, ImVec4*>* colors);
	};
};
#endif