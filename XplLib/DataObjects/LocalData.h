#pragma once
#include <string>
#include "Data.h"

class LocalData : public Data
{
	public:
		std::string SourcePath;
		std::string DestinationPath;

		LocalData()
		{
			Type = "local";
		}

		static LocalData ConvertEntryToLocalData(std::vector<std::string> entry)
		{
			LocalData localData;
			localData.EntryNumber = entry[0];
			localData.SourcePath = entry[2];
			localData.DestinationPath = entry[3];
			return localData;
		}
};