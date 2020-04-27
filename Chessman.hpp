//
// Created by tanya on 26.04.20.
//

#ifndef CHESS_CHESSMAN_HPP
#define CHESS_CHESSMAN_HPP

#include "Structures.hpp"
#include "CommandInput.hpp"
#include <iostream>

using namespace std;
enum MoveType {STEP, KILL, INVALID};

class Chessman
{
public:
    virtual ~Chessman() = default;
    virtual void print_letter() = 0;
    virtual MoveType check_move(vector <vector <Cell>>& table, Coordinates coordinates) = 0;
};

class Rook : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'R';
    }
};

class Knight : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'N';
    }
};

class Bishop : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'B';
    }
};

class King : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'K';
    }
};

class Queen : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'Q';
    }
};

class Pawn : public Chessman
{
public:
    void print_letter() override
    {
        cout << 'P';
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
