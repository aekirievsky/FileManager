#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "FileManager.h"
#include<string>
#include<Windows.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string path{ "D:/" };
	FileManager manager(path);
	std::string folderName{ "D:/TestFolder" };
	std::string newFolderName{ "D:/RenameTestFolder" };
	std::string folderNameForCopy{ "D:/RenameTestFolder - копия" };
	std::string mask{ ".txt" };
	std::string fileName{ "D:/TestFolder/example.txt" };
	uintmax_t folderSize{};
	int key{ -1 };
	cout << "Defaul disk: " << path << endl;
	while (key) {
		cout << "Menu:" << endl
			<< "1 - show disk" << endl
			<< "2 - create folder" << endl
			<< "3 - create file" << endl
			<< "4 - rename folder" << endl
			<< "5 - copy folder" << endl
			<< "6 - show folder size" << endl
			<< "7 - search file by mask" << endl
			<< "8 - delete folder" << endl
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
			cout << "Create file in: " << fileName << endl;
			for (int i = 0; i < 10; i++)
			{
				uint64_t index{ fileName.rfind("example") + ((std::string)("example")).size() };

				manager.createFile(fileName.substr(0, index) + "_" + std::to_string(i) + fileName.substr(fileName.rfind(".")));

			}
			break;
		case 4:
			cout << "Default new folder name: " << newFolderName << endl;
			manager.renameFolder(folderName, newFolderName);
			cout << endl;
			break;
		case 5:
			cout << "Default folder for copy: " << folderNameForCopy << endl;
			manager.copyFolder(newFolderName, folderNameForCopy);
			break;
		case 6:
			folderSize = manager.calculateFolderSize(newFolderName);
			cout << "Size default folder = " << folderSize << " byte" << endl;
			break;
		case 7:
			cout << "Default disk for search: " << newFolderName << endl
				<< "mask: " << mask << endl;
			manager.searchFilesByMask(newFolderName, mask);
			break;
		case 8:
			cout << "Default folder for delete: " << newFolderName << endl;
			manager.deleteFolder(newFolderName);
			manager.deleteFolder(folderNameForCopy);
			break;
		case 0:
			cout << "See you soon" << endl;
			return 0;
		default:
			cout << "Wrong choice" << endl;

		}
		system("pause");
		system("cls");
	}


	return 0;
}


