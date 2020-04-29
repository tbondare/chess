//
// Created by tanya on 26.04.20.
//

#include "Chessman.hpp"
#include "chessboard.hpp"

bool Rook::check_mate(const vector <vector <Cell>>& table, Color nextPlayer, int x, int y)
{
    Coordinates coordinates = ChessBoard::find_next_player_king(table, nextPlayer);
    vector <vector <Cell>> tableCopy;
    tableCopy.resize(8);
    for (int i = 0; i < 8 ; ++i)
        tableCopy[i] = vector <Cell>(table[i]);
    for (int i = x+1; i < 8; ++i)
    {
        if (table[i][y].piece)
        {
            if (table[i][y].color != table[x][y].color)
            {
                // KILL
                tableCopy[i][y] = table[x][y];
                tableCopy[x][y].piece = nullptr;
                if (!ChessBoard::check_shah_for_king(tableCopy, coordinates))
                    return false;
                // Kill Undo
                tableCopy[i][y] = table[i][y];
                tableCopy[x][y] = table[x][y];
            }
        }
    }
    return true;
}