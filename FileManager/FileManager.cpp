#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "FileManager.h"
#include<string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	std::string path{ "F:/" };
	FileManager manager(path);
	std::string folderName {"F:/TestFolder"};
	std::string newFolderName{"F:/RenameTestFolder"};
	std::string folderNameForCopy{"F:/CopyFolder/example.txt"};
	uintmax_t folderSize{};
	int key{ -1 };
	cout << "Defaul disk F:/" << endl;
	while (key) {
		cout << "Menu:" << endl
			<< "1 - show disk" << endl
			<< "2 - create folder" << endl
			<< "3 - rename folder" << endl
			<< "4 - delete folder" << endl
			<< "5 - copy folder" << endl
			<< "6 - show folder size" << endl
			<< "7 - search file by mask" << endl
			<< "0 - exit" << endl
			<< "Your choice: ";
		cin >> key;
		switch (key)
		{
		case 1:
			manager.showDrives(path);
			break;
		case 2:
			cout << "Default folder name: " << folderName << endl;
			manager.createFolder(folderName);
			cout << endl;
			break;
		case 3:
			cout << "Default new folder name: " << newFolderName << endl;
			manager.renameFolder(folderName, newFolderName);
			cout << endl;
			break;
		case 4:
			cout << "Default folder for delete: " << newFolderName << endl;
			manager.deleteFolder(newFolderName);
			break;
		case 5:
			cout << "Default folder for copy: " << folderNameForCopy;
			manager.copyFolder(folderName, folderNameForCopy);
			break;
		case 6:
			folderSize = manager.calculateFolderSize(folderName);
			cout << "Size default folder = " << folderSize << " byte" << endl;
			break;
		case 0:
			cout << "See you soon" << endl;
			return 0;

		}
		system("pause");
		system("cls");
	}


	return 0;
}


