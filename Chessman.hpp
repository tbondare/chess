//
// Created by tanya on 26.04.20.
//

#ifndef CHESS_CHESSMAN_HPP
#define CHESS_CHESSMAN_HPP

#include <iostream>
using namespace std;

class Chessman
{
public:
    virtual ~Chessman() = default;
    virtual void print_letter() = 0;
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
};

#endif //CHESS_CHESSMAN_HPP
