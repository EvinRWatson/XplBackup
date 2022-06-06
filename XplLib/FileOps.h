#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "ErrorFunc.h"
#include "DataObjects/LocalData.h"


std::list<BaseData*> ConvertStringEntriesToDataObjects(std::vector<std::vector<std::string>> content)
{
	std::list<BaseData*> dataObjects;

	for (int i = 0; i < content.size(); i++)
	{
		std::string CurrentEntryType = content[i][1].c_str();
		if (CurrentEntryType == "local")
		{
			LocalData localData(content[i]);
			dataObjects.push_back(&localData); //TODO, fix polymorphism
		}
	}

	return dataObjects;
}

std::vector<std::vector<std::string>> ReadEntriesFile()
{
	std::string fname = "..\\XplData\\entries.csv";

	std::vector<std::vector<std::string>> content;
	std::vector<std::string> row;
	std::string line, word;

	std::fstream file(fname, std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();

			std::stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		DisplayFileError();

	std::list<BaseData*> Test = ConvertStringEntriesToDataObjects(content);

	return content;
}


void PrintEntriesFile(std::vector<std::vector<std::string>> content)
{
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			std::cout << content[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void AddEntriesRecord(std::vector<std::vector<std::string>> content, std::vector<std::string> record)
{

}

void WriteEntriesFile(std::vector<std::vector<std::string>> content)
{

}