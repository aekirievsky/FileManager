#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "FileManager.h"


int main()
{
	FileManager manager;
	manager.showCurrentDirectory();
	std::string path{ "C:/Users/itstep" };
	manager.showDrives(path);

	return 0;
}


