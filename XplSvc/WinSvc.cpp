#include <iostream>
#include <vector>
#include <string>
#include "..\XplLib\Local.h"
#include "..\XplLib\FileOps.h"
#include "..\XplLib\ErrorFunc.h"

void ExecuteEntries(std::vector<std::vector<std::string>> content)
{
	for (int i = 0; i < content.size(); i++)
	{
		std::string RecordType = content[i][1];
		if (RecordType.compare("local") == 0)
		{
			std::string SourcePath = content[i][2];
			std::string DestinationPath = content[i][3];
			CopyFiles(SourcePath, DestinationPath);
		}
	}
}

int main(int argc, char* argv[])
{
    std::vector<std::vector<std::string>> content = ReadEntriesFile();

	ExecuteEntries(content);
}