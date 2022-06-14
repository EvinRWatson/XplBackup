#include <iostream>
#include <vector>
#include <string>
#include "..\XplLib\FileOps.h"
#include "..\XplLib\ErrorFunc.h"

void ExecuteEntries(std::vector<std::vector<std::string>> content)
{
	for (int i = 0; i < content.size(); i++)
	{
		std::vector<std::string> currentEntry = content[i];
		std::string RecordType = currentEntry[1];

		if (RecordType.compare("local") == 0)
		{
			LocalData CurrentRecord(currentEntry);
			CurrentRecord.Run();
		}
	}
}

int main(int argc, char* argv[])
{
    std::vector<std::vector<std::string>> content = ReadEntriesFile();

	ExecuteEntries(content);
}