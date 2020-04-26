//
// Created by tanya on 25.04.20.
//

#ifndef CHESS_COMMANDINPUT_HPP
#define CHESS_COMMANDINPUT_HPP

#include <iostream>

enum Commands {START, LOAD, EXIT, FINISH, MOVE, SAVE, RESTART};

class CommandInput
{
public:
    Commands get_start_command()
    {
        return (START);
    }
    Commands get_match_command()
    {
        return (MOVE);
    }
};


#endif //CHESS_COMMANDINPUT_HPP
