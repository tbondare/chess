//
// Created by tanya on 30.04.20.
//

#include "Structures.hpp"
#include "chessboard.hpp"

CheckMateResult CheckMateData::check_mate(int i, int j)
{
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
        return BREAK;
    if (table[i][j].piece)
    {
        if (table[i][j].color != get_piece_cell().color)
        {
            kill(i, j);
            if (!ChessBoard::check_shah_for_king(tableCopy, kingCoordinates))
                return NOMATE;
            move_undo(i, j);
        }
        return BREAK;
    }
    else
    {
        step(i, j);
        if (!ChessBoard::check_shah_for_king(tableCopy, kingCoordinates))
            return NOMATE;
        move_undo(i, j);
    }
    return CONTINUE;
}

CheckMateResult CheckMateData::check_mate_for_king(int i, int j)
{
    if (i < 0 || i >= 8 || j < 0 || j >= 8)
        return BREAK;
    if (table[i][j].piece)
    {
        if (table[i][j].color != get_piece_cell().color)
        {
            kill(i, j);
            if (!ChessBoard::check_shah_for_king(tableCopy, Coordinates(-1, -1, i, j)))
                return NOMATE;
            move_undo(i, j);
        }
        return BREAK;
    }
    else
    {
        step(i, j);
        if (!ChessBoard::check_shah_for_king(tableCopy, Coordinates(-1, -1, i, j)))
            return NOMATE;
        move_undo(i, j);
    }
    return CONTINUE;
}