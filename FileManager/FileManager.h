#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#pragma once
#include <filesystem>
#include <experimental/filesystem>
#include <iostream>
#include <conio.h>



namespace fs = std::experimental::filesystem;

class FileManager
{
public:
	FileManager() {
		fs::current_path("C:/");
	}
	FileManager(fs::path(path)) {}

	void showCurrentDirectory() {
		std::cout << "Current directory = " << fs::current_path() << std::endl;
	}

	void showDrives(const std::string& path, int tabs = 0) {
		for (const auto& drive : fs::directory_iterator(path)) {
			/*for (int i = 0; i < tabs; i++)
			{
				std::cout << '\t';
			}*/
			//showDrives(drive.path().string(), tabs + 1);
			std::cout << drive.path().string() << std::endl;
		}
	}

	void createFolder(const std::string& path) {
		if (fs::exists(path)) {
			std::cout << "Folder exists" << std::endl;
		}
		else {
			fs::create_directory(path);
		}
	}

	void renameFolder(const std::string& oldPath, const std::string newPath) {
		if (fs::exists(oldPath))
		{
			fs::rename(oldPath, newPath);
		}
		else {
			std::cout << "Folder is not exists";
		}
	}

	void deleteFolder(const std::string& path) {
		if (fs::exists(path))
		{
			fs::remove_all(path);
		}
		else
		{
			std::cout << "Folder is not exists" << std::endl;
		}

	}

	void copyFolder(const std::string& sourcePath, std::string& destinationPath) {
		fs::copy(sourcePath, destinationPath, fs::copy_options::recursive);
	}

	uintmax_t calculateFolderSize(const std::string& path) {
		uintmax_t totalSize{};
		for (const auto& dirEntry : fs::recursive_directory_iterator(path))
		{
			totalSize += fs::file_size(dirEntry);
		}
		return totalSize;
	}
	void searchFilesByMask(const std::string& path, const std::string& mask) {
		for (const auto& dirEntry : fs::recursive_directory_iterator(path)) {
			if (fs::is_regular_file(dirEntry) && dirEntry.path().extension() == mask) {
				std::cout << dirEntry.path().string() << std::endl;
			}
		}
	}

	~FileManager() = default;
};

