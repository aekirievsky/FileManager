#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "FileManager.h"
#include<string>
#include<Windows.h>

using std::cout;
using std::endl;
using std::cin;

//void setConsoleColor(WORD attributes) {
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFOEX consoleInfo;
//	consoleInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
//	GetConsoleScreenBufferInfoEx(hConsole, &consoleInfo);
//	consoleInfo.wAttributes = attributes;
//	SetConsoleScreenBufferInfoEx(hConsole, &consoleInfo);
//}


int main()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string path{ "F:/" }; //ЗАМЕНИТЬ НА ДИСК D
	FileManager manager(path);
	std::string folderName{ "F:/TestFolder" }; //ЗАМЕНИТЬ НА ДИСК D
	std::string newFolderName{ "F:/RenameTestFolder" }; //ЗАМЕНИТЬ НА ДИСК D
	std::string folderNameForCopy{ "F:/RenameTestFolder - копия" }; //ЗАМЕНИТЬ НА ДИСК D
	std::string mask{ ".txt" };
	std::string fileName{ "F:/TestFolder/example.txt" }; //ЗАМЕНИТЬ НА ДИСК D
	uintmax_t folderSize{};
	int key{ -1 };
	cout << "\t\t" << "Defaul disk: " << path << endl;
	while (key) {
		cout << "\t\t" << "-------------------------" << endl
			<< "\t\t" << "-------------------------" << endl;
		cout << "\t\t" << "Menu:" << endl
			<< "\t\t" << "1 - show disk" << endl
			<< "\t\t" << "2 - create folder" << endl
			<< "\t\t" << "3 - create file" << endl
			<< "\t\t" << "4 - rename folder" << endl
			<< "\t\t" << "5 - copy folder" << endl
			<< "\t\t" << "6 - show folder size" << endl
			<< "\t\t" << "7 - search file by mask" << endl
			<< "\t\t" << "8 - delete folder" << endl
			<< "\t\t" << "0 - exit" << endl
			<< "\t\t" << "Your choice: ";
		cin >> key;
		cout << "\t\t" << "-------------------------" << endl
			<< "\t\t" << "-------------------------" << endl;
		switch (key)
		{
		case 1:
			manager.showDrives(path);
			break;
		case 2:
			cout << "\t\t" << "Default folder name: " << folderName << endl;
			manager.createFolder(folderName);
			cout << endl;
			break;
		case 3:
			cout << "\t\t" << "Create file in: " << fileName << endl;
			for (int i = 0; i < 10; i++)
			{
				uint64_t index{ fileName.rfind("example") + ((std::string)("example")).size() };

				manager.createFile(fileName.substr(0, index) + "_" + std::to_string(i) + fileName.substr(fileName.rfind(".")));

			}
			break;
		case 4:
			cout << "\t\t" << "Default new folder name: " << newFolderName << endl;
			manager.renameFolder(folderName, newFolderName);
			cout << endl;
			break;
		case 5:
			cout << "\t\t" << "Default folder for copy: " << folderNameForCopy << endl;
			manager.copyFolder(newFolderName, folderNameForCopy);
			break;
		case 6:
			folderSize = manager.calculateFolderSize(newFolderName);
			cout << "\t\t" << "Size default folder = " << folderSize << " byte" << endl;
			break;
		case 7:
			cout << "\t\t" << "Default disk for search: " << newFolderName << endl
				<< "\t\t" << "mask: " << mask << endl;
			manager.searchFilesByMask(newFolderName, mask);
			break;
		case 8:
			cout << "\t\t" << "Default folder for delete: " << newFolderName << endl;
			manager.deleteFolder(newFolderName);
			manager.deleteFolder(folderNameForCopy);
			break;
		case 0:
			cout << "\t\t" << "See you soon" << endl;
			return 0;
		default:
			cout << "\t\t" << "Wrong choice" << endl;

		}
		system("pause");
		system("cls");
	}


	return 0;
}


