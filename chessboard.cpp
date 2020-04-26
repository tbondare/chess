//
// Created by tanya on 23.04.20.
//

#include "chessboard.hpp"
#include <memory>

void ChessBoard::set_first_or_last_row(int rowIndex)
{
    table[0][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Rook>());
    table[1][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Knight>());
    table[2][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Bishop>());
    table[3][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Queen>());
    table[4][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<King>());
    table[5][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Bishop>());
    table[6][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Knight>());
    table[7][rowIndex].piece = dynamic_pointer_cast <Chessman> (make_shared<Rook>());
}

void ChessBoard::create()
{
    table.resize(8);
    for (int i = 0; i < 8; i++)
        table[i].resize(8);
    set_first_or_last_row(0);
    for (int i = 0; i < 8; i++)
    {
        table[i][1].piece = dynamic_pointer_cast <Chessman> (make_shared<Pawn>());
        table[i][6].piece = dynamic_pointer_cast <Chessman> (make_shared<Pawn>());
        table[i][0].color = WHITE;
        table[i][1].color = WHITE;
        table[i][6].color = BLACK;
        table[i][7].color = BLACK;
    }
    set_first_or_last_row(7);
}

void ChessBoard::print()
{
    cout << "            White" << endl;
    cout << "   a  b  c  d  e  f  g  h" << endl;
    cout << " ╔══╤══╤══╤══╤══╤══╤══╤══╗" << endl;
    for (int i = 0; i < 8; ++i)
    {
        cout << i + 1 << "║";
        for (int j = 0; j < 8; ++j)
        {
            if (table[j][i].piece)
            {
                table[j][i].color == WHITE ? cout << "W" : cout << "B";
                table[j][i].piece->print_letter();
            }
            else
                cout << "  ";
            if (j == 7)
                cout << "║" << i + 1 << endl;
            else
                cout << "│";
        }
        if (i == 7)
            cout << " ╚══╧══╧══╧══╧══╧══╧══╧══╝" << endl;
        else
            cout << " ╟──┼──┼──┼──┼──┼──┼──┼──╢" << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl;
    cout << "            Black" << endl;
}

Color ChessBoard::check_whose_move()
{}

void ChessBoard::move()
{}