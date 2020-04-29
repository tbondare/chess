//
// Created by tanya on 26.04.20.
//

#ifndef CHESS_CHESSMAN_HPP
#define CHESS_CHESSMAN_HPP

#include "Structures.hpp"
#include "CommandInput.hpp"
#include <iostream>

using namespace std;
enum MoveType {STEP, KILL, INVALID, CASTLING_SHORT, CASTLING_LONG};

class Chessman
{
public:
    virtual ~Chessman() = default;
    virtual char get_letter() = 0;
    virtual MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) = 0;

    bool wasMove = false;
};

class Rook : public Chessman
{
public:
    char get_letter() override
    {
        return ('R');
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
        auto& cellTo = table[coordinates.to_x][coordinates.to_y];
        int stepX = coordinates.to_x - coordinates.from_x;
        int stepY = coordinates.to_y - coordinates.from_y;
        if (stepX == 0 && stepY != 0)
        {
            if (stepY < 0)
            {
                for (int i = coordinates.from_y - 1; i > coordinates.to_y ; i--)
                {
                    if (table[coordinates.from_x][i].piece)
                        return INVALID;
                }
            }
            else
            {
                for (int i = coordinates.from_y + 1; i < coordinates.to_y ; i++)
                {
                    if (table[coordinates.from_x][i].piece)
                        return INVALID;
                }
            }
            if (cellTo.piece)
            {
                if (cellTo.color == cellFrom.color)
                    return INVALID;
                return KILL;
            }
            return STEP;
        }
        else if (stepY == 0 && stepX != 0)
        {
            if (stepX < 0)
            {
                for (int i = coordinates.from_x - 1; i > coordinates.to_x ; i--)
                {
                    if (table[i][coordinates.from_y].piece)
                        return INVALID;
                }
            }
            else
            {
                for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                {
                    if (table[i][coordinates.from_y].piece)
                        return INVALID;
                }
            }
            if (cellTo.piece)
            {
                if (cellTo.color == cellFrom.color)
                    return INVALID;
                return KILL;
            }
            return STEP;
        }
        else
            return INVALID;
    }
};

class Knight : public Chessman
{
public:
    char get_letter() override
    {
        return ('N');
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
        auto& cellTo = table[coordinates.to_x][coordinates.to_y];
        int stepX = coordinates.to_x - coordinates.from_x;
        int stepY = coordinates.to_y - coordinates.from_y;
        if (!((abs(stepX) == 1 && abs(stepY) == 2) || (abs(stepX) == 2 && abs(stepY) == 1)))
            return INVALID;
        if (cellTo.piece)
        {
            if (cellTo.color == cellFrom.color)
                return INVALID;
            return KILL;
        }
        return STEP;
    }
};

class Bishop : public Chessman
{
public:
    char get_letter() override
    {
        return ('B');
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
        auto& cellTo = table[coordinates.to_x][coordinates.to_y];
        int stepX = coordinates.to_x - coordinates.from_x;
        int stepY = coordinates.to_y - coordinates.from_y;
        if (abs(stepX) != abs(stepY))
            return INVALID;
        if (stepX < 0 && stepY < 0)
        {
            for (int i = coordinates.from_x - 1; i > coordinates.to_x ; i--)
            {
                if (table[i][i].piece)
                    return INVALID;
            }
        }
        else if (stepX > 0 && stepY > 0)
        {
            for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
            {
                if (table[i][i].piece)
                    return INVALID;
            }
        }
        else if (stepX > 0 && stepY < 0)
        {
            for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
            {
                for (int j = coordinates.from_y - 1; j > coordinates.to_y ; j--)
                {
                    if (table[i][j].piece)
                        return INVALID;
                }
            }
        }
        else if (stepX < 0 && stepY > 0)
        {
            for (int j = coordinates.from_y - 1; j > coordinates.to_y ; j--)
            {
                for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                {
                    if (table[j][i].piece)
                        return INVALID;
                }
            }
        }
        if (cellTo.piece)
        {
            if (cellTo.color == cellFrom.color)
                return INVALID;
            return KILL;
        }
        return STEP;
    }
};

class King : public Chessman
{
public:
    char get_letter() override
    {
        return 'K';
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
        auto& cellTo = table[coordinates.to_x][coordinates.to_y];
        int stepX = coordinates.to_x - coordinates.from_x;
        int stepY = coordinates.to_y - coordinates.from_y;
        if (stepX == 2 && !wasMove && table[7][coordinates.from_y].piece && !(table[7][coordinates.from_y].piece->wasMove))
        {
            if (table[5][coordinates.from_y].piece)
                return INVALID;
            if (table[6][coordinates.from_y].piece)
                return INVALID;
            return CASTLING_SHORT;
        }
        else if (stepX == -2 && !wasMove && table[0][coordinates.from_y].piece && !(table[0][coordinates.from_y].piece->wasMove))
        {
            if (table[1][coordinates.from_y].piece)
                return INVALID;
            if (table[2][coordinates.from_y].piece)
                return INVALID;
            if (table[3][coordinates.from_y].piece)
                return INVALID;
            return CASTLING_LONG;
        }
        if (abs(stepX) != 1 || abs(stepY) != 1)
            return INVALID;
        if (cellTo.piece)
        {
            if (cellTo.color == cellFrom.color)
                return INVALID;
            return KILL;
        }
        return STEP;
    }
};

class Queen : public Chessman
{
public:
    char get_letter() override
    {
        return 'Q';
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
        auto& cellTo = table[coordinates.to_x][coordinates.to_y];
        int stepX = coordinates.to_x - coordinates.from_x;
        int stepY = coordinates.to_y - coordinates.from_y;
        if (abs(stepX) == abs(stepY))
        {
            if (stepX < 0 && stepY < 0)
            {
                for (int i = coordinates.from_x - 1; i > coordinates.to_x ; i--)
                {
                    if (table[i][i].piece)
                        return INVALID;
                }
            }
            else if (stepX > 0 && stepY > 0)
            {
                for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                {
                    if (table[i][i].piece)
                        return INVALID;
                }
            }
            else if (stepX > 0 && stepY < 0)
            {
                for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                {
                    for (int j = coordinates.from_y - 1; j > coordinates.to_y ; j--)
                    {
                        if (table[i][j].piece)
                            return INVALID;
                    }
                }
            }
            else if (stepX < 0 && stepY > 0)
            {
                for (int j = coordinates.from_y - 1; j > coordinates.to_y ; j--)
                {
                    for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                    {
                        if (table[j][i].piece)
                            return INVALID;
                    }
                }
            }
            if (cellTo.piece)
            {
                if (cellTo.color == cellFrom.color)
                    return INVALID;
                return KILL;
            }
            return STEP;
        }
        else if (stepX == 0 && stepY != 0)
        {
            if (stepY < 0)
            {
                for (int i = coordinates.from_y - 1; i > coordinates.to_y ; i--)
                {
                    if (table[coordinates.from_x][i].piece)
                        return INVALID;
                }
            }
            else
            {
                for (int i = coordinates.from_y + 1; i < coordinates.to_y ; i++)
                {
                    if (table[coordinates.from_x][i].piece)
                        return INVALID;
                }
            }
            if (cellTo.piece)
            {
                if (cellTo.color == cellFrom.color)
                    return INVALID;
                return KILL;
            }
            return STEP;
        }
        else if (stepY == 0 && stepX != 0)
        {
            if (stepX < 0)
            {
                for (int i = coordinates.from_x - 1; i > coordinates.to_x ; i--)
                {
                    if (table[i][coordinates.from_y].piece)
                        return INVALID;
                }
            }
            else
            {
                for (int i = coordinates.from_x + 1; i < coordinates.to_x ; i++)
                {
                    if (table[i][coordinates.from_y].piece)
                        return INVALID;
                }
            }
            if (cellTo.piece)
            {
                if (cellTo.color == cellFrom.color)
                    return INVALID;
                return KILL;
            }
            return STEP;
        }
        else
            return INVALID;
    }
};

class Pawn : public Chessman
{
public:
    char get_letter() override
    {
        return 'P';
    }
    MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) override
    {
        if (check_is_step_valid(table, coordinates))
            return STEP;
        else if (check_is_kill_valid (table, coordinates))
            return KILL;
        return INVALID;
    }

private:
    bool check_is_first_position(Color color, Coordinates coordinates)
    {
        if (color == WHITE)
            return coordinates.from_y == 1;
        else
            return coordinates.from_y == 6;
    }
    int count_step_length(Coordinates coordinates, Color color)
    {
        int step;
        if (color == BLACK)
            step = coordinates.from_y - coordinates.to_y;
        else
            step = coordinates.to_y - coordinates.from_y;
        return step;
    }
    bool check_is_step_valid(vector <vector <Cell>>& table, Coordinates coordinates)
    {
        auto& cell = table[coordinates.from_x][coordinates.from_y];
        if (coordinates.from_x != coordinates.to_x)
            return false;
        int stepLength = count_step_length(coordinates, cell.color);
        if (check_is_first_position(cell.color, coordinates))
        {
            if (!(stepLength <= 2 && stepLength > 0))
                return false;
            if (stepLength == 2)
            {
                if (table[coordinates.from_x][(coordinates.from_y + coordinates.to_y)/2].piece)
                    return false;
            }
        }
        else
        {
            if (!(stepLength <= 1 && stepLength > 0))
                return false;
        }
        if (table[coordinates.to_x][coordinates.to_y].piece)
            return false;
        return true;
    }
    bool check_is_kill_valid (vector <vector <Cell>>& table, Coordinates coordinates)
    {
        auto& cell = table[coordinates.from_x][coordinates.from_y];
        int stepLength_y = count_step_length(coordinates, cell.color);
        if (stepLength_y != 1)
            return false;
        int stepLength_x = coordinates.from_x - coordinates.to_x;
        if (stepLength_x != 1 && stepLength_x != -1)
            return false;
        if (!table[coordinates.to_x][coordinates.to_y].piece)
            return false;
        return !(cell.color == table[coordinates.to_x][coordinates.to_y].color);
    }
};

#endif //CHESS_CHESSMAN_HPP
