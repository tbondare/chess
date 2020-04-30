//
// Created by tanya on 26.04.20.
//

#include "Chessman.hpp"
#include "chessboard.hpp"

bool Rook::check_mate(CheckMateData& data)
{
    for (int i = data.pieceX + 1; i < 8; ++i)
    {
        auto result = data.check_mate(i, data.pieceY);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int i = data.pieceX - 1; i >= 0; --i)
    {
        auto result = data.check_mate(i, data.pieceY);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int j = data.pieceY + 1; j < 8; ++j)
    {
        auto result = data.check_mate(data.pieceX, j);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int j = data.pieceY - 1; j >= 0; --j)
    {
        auto result = data.check_mate(data.pieceX, j);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    return true;
}

bool Knight::check_mate(CheckMateData &data)
{
    vector<int> stepX = {1, 2,  2,  1, -1, -2, -2, -1};
    vector<int> stepY = {2, 1, -1, -2, -2, -1,  1,  2};
    for (int c = 0; c < stepX.size(); ++c)
    {
        int i = data.pieceX + stepX[c];
        int j = data.pieceY + stepY[c];
        if (i >= 0 && i < 8 && j >= 0 && j < 8)
        {
            auto result = data.check_mate(i, j);
            if (result == NOMATE)
                return false;
        }
    }
    return true;
}

bool Bishop::check_mate(CheckMateData &data)
{
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX + step, data.pieceY + step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX + step, data.pieceY - step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX - step, data.pieceY + step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX - step, data.pieceY - step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    return true;
}

bool King::check_mate(CheckMateData &data)
{
    CheckMateResult result;
    result = data.check_mate_for_king(data.pieceX + 1, data.pieceY + 1);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX + 1, data.pieceY - 1);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX - 1, data.pieceY + 1);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX - 1, data.pieceY - 1);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX - 1, data.pieceY);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX + 1, data.pieceY);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX, data.pieceY - 1);
    if (result == NOMATE)
        return false;
    result = data.check_mate_for_king(data.pieceX, data.pieceY + 1);
    if (result == NOMATE)
        return false;
    return true;
}

bool Queen::check_mate(CheckMateData &data)
{
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX + step, data.pieceY + step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX + step, data.pieceY - step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX - step, data.pieceY + step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int step = 1; step < 8; ++step)
    {
        auto result = data.check_mate(data.pieceX - step, data.pieceY - step);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int i = data.pieceX + 1; i < 8; ++i)
    {
        auto result = data.check_mate(i, data.pieceY);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int i = data.pieceX - 1; i >= 0; --i)
    {
        auto result = data.check_mate(i, data.pieceY);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int j = data.pieceY + 1; j < 8; ++j)
    {
        auto result = data.check_mate(data.pieceX, j);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    for (int j = data.pieceY - 1; j >= 0; --j)
    {
        auto result = data.check_mate(data.pieceX, j);
        if (result == NOMATE)
            return false;
        else if (result == BREAK)
            break;
    }
    return true;
}

bool Pawn::check_mate(CheckMateData &data)
{
    int step;
    bool isFirstPosition;
    if (data.get_piece_cell().color == WHITE)
    {
        step = 1;
        isFirstPosition = data.pieceY == 1;
    }
    else
    {
        step = -1;
        isFirstPosition = data.pieceY == 6;
    }

    int i = data.pieceX;
    int j;
    if (isFirstPosition)
    {
        j = data.pieceY + 2 * step;
        if (!data.table[i][j].piece)
        {
            data.step(i, j);
            if (!ChessBoard::check_shah_for_king(data.tableCopy, data.kingCoordinates))
                return false;
            data.move_undo(i, j);
        }
    }
    j = data.pieceY + step;
    if (j >= 0 && j < 8)
    {
        if (!data.table[i][j].piece)
        {
            data.step(i, j);
            if (!ChessBoard::check_shah_for_king(data.tableCopy, data.kingCoordinates))
                return false;
            data.move_undo(i, j);
        }
        i = data.pieceX + 1;
        if (i >= 0 && i < 8 && data.table[i][j].piece && data.table[i][j].color != data.get_piece_cell().color)
        {
            data.kill(i, j);
            if (!ChessBoard::check_shah_for_king(data.tableCopy, data.kingCoordinates))
                return false;
            data.move_undo(i, j);
        }
        i = data.pieceX - 1;
        if (i >= 0 && i < 8 && data.table[i][j].piece && data.table[i][j].color != data.get_piece_cell().color)
        {
            data.kill(i, j);
            if (!ChessBoard::check_shah_for_king(data.tableCopy, data.kingCoordinates))
                return false;
            data.move_undo(i, j);
        }
    }
    return true;
}