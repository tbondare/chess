//
// Created by tanya on 23.04.20.
//

#ifndef CHESS_CHESSBOARD_HPP
#define CHESS_CHESSBOARD_HPP

#include <iostream>
#include "Chessman.hpp"
#include "CommandInput.hpp"
#include "Structures.hpp"

using namespace std;

class ChessBoard
{
public:
    void create();
    void move(Coordinates coordinates);
    void check_mate()
    {

    }
    void load(string name);
    Color check_whose_move();
    void print();
    void save(string name);
    void create_clean_board();
    template <typename T>
    void put_chessman(int x, int y, shared_ptr <T> piece, Color color)
    {
        table[x][y].piece = dynamic_pointer_cast <Chessman> (piece);
        table[x][y].color = color;
    }
    bool check_shah();
private:
    void set_first_or_last_row(int rowIndex);
    void metamorfing_pawn(Coordinates coordinates);

    vector <vector <Cell>> table;
    Color nextPlayer = WHITE;
};


#endif //CHESS_CHESSBOARD_HPP
