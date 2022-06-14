#pragma once
#include <string>
#include <filesystem>
#include "BaseData.h"

class LocalData : public BaseData
{
	public:
		std::string SourcePath;
		std::string DestinationPath;

		LocalData()
		{
			Type = "local";
		}

		LocalData(std::vector<std::string> entry)
		{
			EntryNumber = entry[0];
			Type = entry[1];
			SourcePath = entry[2];
			DestinationPath = entry[3];
		}

		void Run()
		{
			namespace fs = std::filesystem;
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
};