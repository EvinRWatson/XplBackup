#pragma once
#include <string>
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
};