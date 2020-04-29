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
    bool move(Coordinates coordinates);
    void load(string name);
    Color check_whose_move();
    void print();
    void save(string name);
    void create_clean_board();
    template <typename T>
    void put_chessman(string str, shared_ptr <T> piece, Color color)
    {
        Coordinates coordinates(str+"-e6");
        table[coordinates.from_x][coordinates.from_y].piece = dynamic_pointer_cast <Chessman> (piece);
        table[coordinates.from_x][coordinates.from_y].color = color;
    }
    bool check_shah();
    static Coordinates find_next_player_king(const vector <vector <Cell>>& table, Color nextPlayer);
    static bool check_shah_for_king(const vector <vector <Cell>>& table, Coordinates coordinates);
    void check_board(string boardForCheck);
private:
    void set_first_or_last_row(int rowIndex);
    void metamorfing_pawn(Coordinates coordinates);
    bool check_mate();

    string print_to_string();
    vector <vector <Cell>> table;
    Color nextPlayer = WHITE;
};

#endif //CHESS_CHESSBOARD_HPP
