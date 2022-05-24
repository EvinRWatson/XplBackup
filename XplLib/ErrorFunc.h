#include <iostream>

void DisplayArgumentError(char* argv)
{
    std::string ErrorMessage = "Command not recognized: ";
    ErrorMessage.append(argv);
    std::cout << ErrorMessage << std::endl;
}