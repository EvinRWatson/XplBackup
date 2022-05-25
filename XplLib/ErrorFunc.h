#pragma once
#include <iostream>

void DisplayArgumentError(char* argv)
{
    std::string ErrorMessage = "Command not recognized: ";
    ErrorMessage.append(argv);
    std::cout << ErrorMessage << std::endl;
}

void DisplayFileError()
{
    std::cout << "Could not open the file\n";
}