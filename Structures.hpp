//
// Created by tanya on 27.04.20.
//

#ifndef CHESS_STRUCTURES_HPP
#define CHESS_STRUCTURES_HPP

#include <vector>
#include <memory>

using namespace std;

enum Color {WHITE, BLACK};
class Chessman;

struct Cell
{
    Color color;
    shared_ptr <Chessman> piece;
};

struct Coordinates
{
    Coordinates(){}
    Coordinates(string command)
    {
        if ((command[0] >= 'a' && command[0] <= 'h') && (command[3] >= 'a' && command[3] <= 'h')
            && (command[1] >= '1' && command[1] <= '8') && (command[4] >= '1' && command[4] <= '8'))
        {
            from_x = command[0] - 'a';
            to_x = command[3] - 'a';
            from_y = command[1] - '1';
            to_y = command[4] - '1';
        }
        else
            throw runtime_error ("Wrong coordinates string");
    }
    Coordinates (int from_x, int from_y, int to_x, int to_y)
        : from_x(from_x)
        , from_y(from_y)
        , to_x(to_x)
        , to_y(to_y)
        {}
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};

enum CheckMateResult {NOMATE, BREAK, CONTINUE};

struct CheckMateData
{
    const vector <vector <Cell>>& table;
    vector <vector <Cell>> tableCopy;
    Color nextPlayer;
    Coordinates kingCoordinates;
    int pieceX;
    int pieceY;

    const Cell& get_piece_cell()
    {
        return table[pieceX][pieceY];
    }

    void kill(int x, int y)
    {
        tableCopy[x][y] = get_piece_cell();
        tableCopy[pieceX][pieceY].piece = nullptr;
    }

    void step(int x, int y)
    {
        tableCopy[x][y] = get_piece_cell();
        tableCopy[pieceX][pieceY].piece = nullptr;
    }

    void move_undo(int x, int y)
    {
        tableCopy[x][y] = table[x][y];
        tableCopy[pieceX][pieceY] = table[pieceX][pieceY];
    }

    CheckMateResult check_mate(int i, int j);
    CheckMateResult check_mate_for_king(int i, int j);
};

#endif //CHESS_STRUCTURES_HPP

