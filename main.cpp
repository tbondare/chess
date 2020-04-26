#include <iostream>
#include "match.hpp"
#include "CommandInput.hpp"
int main()
{
    Match match;
    CommandInput commandInput;
    auto currentCommand = commandInput.get_start_command();
    while (currentCommand != EXIT)
    {
        if (currentCommand == LOAD)
        {
            if(match.load())
                match.run(commandInput);
        }
        else
        {
            match.start();
            match.run(commandInput);
        }
        currentCommand = commandInput.get_start_command();
    }
    return 0;
}