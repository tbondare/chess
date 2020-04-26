//
// Created by tanya on 23.04.20.
//

#ifndef CHESS_CHESSBOARD_HPP
#define CHESS_CHESSBOARD_HPP

#include <iostream>
#include <vector>
#include "Chessman.hpp"
#include <memory>

using namespace std;
enum Color {WHITE, BLACK};

struct Cell
{
    Color color;
    shared_ptr <Chessman> piece;
};

class ChessBoard
{
public:
    void create();
    void move();
    void check_mate()
    {

    }
    void check_castling()
    {

    }
    void load(string name)
    {

    }
    Color check_whose_move();
    void print();
    void save(string name)
    {

    }
private:
    void set_first_or_last_row(int rowIndex);

    vector <vector <Cell>> table;
    Color nextPlayer = WHITE;
};


#endif //CHESS_CHESSBOARD_HPP
