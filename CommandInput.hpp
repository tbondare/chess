//
// Created by tanya on 25.04.20.
//

#ifndef CHESS_COMMANDINPUT_HPP
#define CHESS_COMMANDINPUT_HPP

#include <iostream>
#include "Structures.hpp"
using namespace std;

enum Commands {START, LOAD, EXIT, FINISH, MOVE, SAVE, RESTART, UNDEFINED};

class CommandInput
{
public:
    Commands get_start_command()
    {
        string command;
        cout << "Enter one of the next commands: start, load, exit" << endl;
        cin >> command;
        if (command == "start")
            return START;
        else if (command == "load")
            return LOAD;
        else if (command == "exit")
            return EXIT;
        else
            cout << "Command " << command << " is not valid" << endl;
        return (UNDEFINED);
    }
    Commands get_match_command()
    {
        string command;
        cout << "Enter one of the next commands: finish, save, restart, load "
                "or enter your move coordinates like this: e2-e4" << endl;
        cin >> command;
        if (command == "finish")
            return FINISH;
        else if (command == "save")
            return SAVE;
        else if (command == "restart")
            return RESTART;
        else if (command == "load")
            return LOAD;
        else
        {
            if ((command[0] >= 'a' && command[0] <= 'h') && (command[3] >= 'a' && command[3] <= 'h')
            && (command[1] >= '1' && command[1] <= '8') && (command[4] >= '1' && command[4] <= '8'))
            {
                coordinate.from_x = command[0] - 'a';
                coordinate.to_x = command[3] - 'a';
                coordinate.from_y = command[1] - '1';
                coordinate.to_y = command[4] - '1';
                return (MOVE);
            }
            else
                cout << "Command " << command << " is not valid" << endl;
        }
        return (UNDEFINED);
    }
    Coordinates get_coordinates()
    {
        return coordinate;
    }

private:
    Coordinates coordinate;
};

#endif //CHESS_COMMANDINPUT_HPP
