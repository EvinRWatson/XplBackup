#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void CopyFiles(std::string SourcePath, std::string DestinationPath)
{
	std::string Message = "Copying " + SourcePath + " to " + DestinationPath;
	std::cout << Message << std::endl;

	try 
	{
		fs::copy(SourcePath, DestinationPath, fs::copy_options::recursive);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}