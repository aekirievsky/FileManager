#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "FileManager.h"


int main()
{
	std::string path{ "D:\ExampleGit" };
	FileManager manager(path);
	
	manager.showDrives(path);

	return 0;
}


