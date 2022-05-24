// XplCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "XplLib.h"

void DisplayCommandError(char* argv)
{
    std::string ErrorMessage = "Command not recognized: ";
    ErrorMessage.append(argv);
    std::cout << ErrorMessage << std::endl;
}

bool EvaluateArgument(char* argv)
{
    if (strcmp(argv, "add") == 0)
    {
        std::cout << "Adding" << std::endl;
    }
    else if(strcmp(argv, "remove") == 0)
    {
        std::cout << "Removing" << std::endl;
    }
    else if (strcmp(argv, "status") == 0)
    {
        std::cout << "Reading file..." << std::endl;
        ReadEntries();
    }
    else
    {
        DisplayCommandError(argv);
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    int count = 1;
    bool ValidCommand = true;

    // Display each command-line argument.
    while (ValidCommand == true && count < argc)
    {
        ValidCommand = EvaluateArgument(argv[count]);
        count++;
    }

    std::cout << "Ending Program" << std::endl;
}