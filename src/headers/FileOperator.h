#ifndef FILE_OPERATOR_H
#define FILE_OPERATOR_H
namespace RiverI {
	class FileOperator {
	private:
		static void HelpMarker(const char* desc);
	public:
		static void Render(bool* V_Open);
	};
};
#endif