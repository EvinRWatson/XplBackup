#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "ErrorFunc.h"
#include "DataObjects/LocalData.h"


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