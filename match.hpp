//
// Created by tanya on 25.04.20.
//

#ifndef CHESS_MATCH_HPP
#define CHESS_MATCH_HPP
#include "chessboard.hpp"
#include "CommandInput.hpp"

class Match
{
public:
    bool load();
    void start();
    void run(CommandInput& commandInput);

private:
    ChessBoard chessBoard;
};


#endif //CHESS_MATCH_HPP
