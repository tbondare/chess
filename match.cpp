//
// Created by tanya on 25.04.20.
//

#include "match.hpp"
#include <iostream>
#include <experimental/filesystem>
#include "CommandInput.hpp"

using namespace std;

void Match::start()
{
    chessBoard.create();
}

bool Match::load()
{
    string name;
    cout << "Enter the file name to load" << endl;
    cin >> name;
    if (experimental::filesystem::exists(name))
        chessBoard.load(name);
    else
    {
        cout << "file " << name << " was not found" << endl;
        return false;
    }
    return true;
}

void Match::run(CommandInput& commandInput)
{

    chessBoard.print();
    auto currentCommand = commandInput.get_match_command();
    while (currentCommand != FINISH)
    {
        if (currentCommand == MOVE)
        {
            if (!chessBoard.move(commandInput.get_coordinates()))
            {
                chessBoard.print();
                return;
            }
            else
                chessBoard.print();
        }
        else if (currentCommand == SAVE)
        {
            cout << "Enter the file name to save" << endl;
            string name;
            cin >> name;
            chessBoard.save(name);
        }
        else if (currentCommand == RESTART)
        {
            chessBoard.create();
            chessBoard.print();
        }
        else if (currentCommand == LOAD)
        {
            if (load())
                chessBoard.print();
        }
        currentCommand = commandInput.get_match_command();
    }
    chessBoard.check_whose_move();
}