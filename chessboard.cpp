//
// Created by tanya on 23.04.20.
//

#include "chessboard.hpp"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

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
    create_clean_board();
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

string ChessBoard::print_to_string()
{
    stringstream ss;
    ss << "            White" << endl;
    ss << "   a  b  c  d  e  f  g  h" << endl;
    ss << " ╔══╤══╤══╤══╤══╤══╤══╤══╗" << endl;
    for (int i = 0; i < 8; ++i)
    {
        ss << i + 1 << "║";
        for (int j = 0; j < 8; ++j)
        {
            if (table[j][i].piece)
            {
                table[j][i].color == WHITE ? ss << "W" : ss << "B";
                ss << table[j][i].piece->get_letter();
            }
            else
                ss << "  ";
            if (j == 7)
                ss << "║" << i + 1 << endl;
            else
                ss << "│";
        }
        if (i == 7)
            ss << " ╚══╧══╧══╧══╧══╧══╧══╧══╝" << endl;
        else
            ss << " ╟──┼──┼──┼──┼──┼──┼──┼──╢" << endl;
    }
    ss << "   a  b  c  d  e  f  g  h" << endl;
    ss << "            Black" << endl;
    if (nextPlayer == BLACK)
        ss << "BLACK's move next" << endl;
    else
        ss << "WHITE's move next" << endl;
    return (ss.str());
}
void ChessBoard::print()
{
    cout << print_to_string();
}

Color ChessBoard::check_whose_move()
{
    return (nextPlayer);
}

void ChessBoard::move(Coordinates coordinates)
{
    auto& cellFrom = table[coordinates.from_x][coordinates.from_y];
    auto& cellTo = table[coordinates.to_x][coordinates.to_y];
    auto memFrom = cellFrom;
    auto memTo = cellTo;
    if (cellFrom.piece)
    {
        if (nextPlayer != cellFrom.color)
        {
            cout << "It is not valid color of chessman" << endl;
            return;
        }
        auto result = cellFrom.piece->check_move(table, coordinates);
        if (result == INVALID)
        {
            cout << "It is not valid move" << endl;
            return;
        }
        if (result == STEP)
        {
            cellTo.color = cellFrom.color;
            cellFrom.piece.swap(cellTo.piece);
        }
        else if (result == KILL)
        {
            cellTo.piece = cellFrom.piece;
            cellTo.color = cellFrom.color;
            cellFrom.piece = nullptr;
        }
        else if (result == CASTLING_SHORT)
        {
            if (check_shah())
            {
                cout << "Cannot do castling, because king is under shah" << endl;
                return;
            }
            cellTo.color = cellFrom.color;
            cellFrom.piece.swap(cellTo.piece);
            table[7][coordinates.from_y].piece.swap(table[5][coordinates.from_y].piece);
            table[5][coordinates.from_y].color = table[7][coordinates.from_y].color;
        }
        else if (result == CASTLING_LONG)
        {
            if (check_shah())
            {
                cout << "Cannot do castling, because king is under shah" << endl;
                return;
            }
            cellTo.color = cellFrom.color;
            cellFrom.piece.swap(cellTo.piece);
            table[0][coordinates.from_y].piece.swap(table[2][coordinates.from_y].piece);
            table[2][coordinates.from_y].color = table[0][coordinates.from_y].color;
        }
        if (check_shah())
        {
            if (result == CASTLING_SHORT)
            {
                table[5][coordinates.from_y].piece.swap(table[7][coordinates.from_y].piece);
                table[7][coordinates.from_y].color = table[5][coordinates.from_y].color;
            }
            else if (result == CASTLING_LONG)
            {
                table[2][coordinates.from_y].piece.swap(table[0][coordinates.from_y].piece);
                table[0][coordinates.from_y].color = table[2][coordinates.from_y].color;
            }
            cellTo = memTo;
            cellFrom = memFrom;
            cout << "It is shah" << endl;
            return;
        }
        if (memFrom.piece->get_letter() == 'P')
        {
            if ((memFrom.color == BLACK && coordinates.to_y == 0) ||
            (memFrom.color == WHITE && coordinates.to_y == 7))
                metamorfing_pawn(coordinates);
        }
        if (cellFrom.color == BLACK)
            nextPlayer = WHITE;
        else
            nextPlayer = BLACK;
        cellTo.piece->wasMove = true;
    }
    else
        cout << "It is empty cell" << endl;
}

bool ChessBoard::check_shah()
{
    Coordinates coordinates;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j].piece && table[i][j].piece->get_letter() == 'K' && table[i][j].color == nextPlayer)
            {
                coordinates.to_x = i;
                coordinates.to_y = j;
                break;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (table[i][j].piece && table[i][j].color != nextPlayer)
            {
                coordinates.from_x = i;
                coordinates.from_y = j;
                if (table[i][j].piece->check_move(table, coordinates) == KILL)
                    return true;
            }
        }
        return false;
    }
}

void ChessBoard::create_clean_board()
{
    table.clear();
    table.resize(8);
    for (int i = 0; i < 8; i++)
        table[i].resize(8);
    nextPlayer = WHITE;
}

void  ChessBoard:: metamorfing_pawn(Coordinates coordinates)
{
    string piece;
    cout << "Enter what chessman do you want to change the pawn: rook, knight, bishop, or queen" << endl;
    cin >> piece;
    while (true)
    {
        if (piece == "rook")
            table[coordinates.to_x][coordinates.to_y].piece = dynamic_pointer_cast <Chessman> (make_shared<Rook>());
        else if (piece == "knight")
            table[coordinates.to_x][coordinates.to_y].piece = dynamic_pointer_cast <Chessman> (make_shared<Knight>());
        else if (piece == "bishop")
            table[coordinates.to_x][coordinates.to_y].piece = dynamic_pointer_cast <Chessman> (make_shared<Bishop>());
        else if (piece == "queen")
            table[coordinates.to_x][coordinates.to_y].piece = dynamic_pointer_cast <Chessman> (make_shared<Queen>());
        else
        {
            cout << "The " << piece << " is not valid chessman. Try again" << endl;
            cout << "Enter what chessman do you want to change the pawn: rook, knight, bishop, or queen" << endl;
            cin >> piece;
            continue ;
        }
        break ;
    }
}

void ChessBoard::save(string name)
{
    ofstream file(name, ios::out);
    if (!file)
    {
        cout << "Failed to save file" << name << endl;
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            file << (int)table[i][j].color << endl;
            if (!table[i][j].piece)
                file << '-' << endl;
            else
            {
                file << table[i][j].piece->get_letter() << endl;
                file << table[i][j].piece->wasMove << endl;
            }
        }
    }
    file << (int)nextPlayer << endl;
    file.close();
}

void ChessBoard::load(string name)
{
    ifstream file(name, ios::in);
    if (!file)
    {
        cout << "Failed to load file" << name << endl;
        return;
    }
    create_clean_board();
    char symbolInFile;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            file >> (int&)table[i][j].color;
            file >> symbolInFile;
            if (symbolInFile == '-')
                continue ;
            else if (symbolInFile == 'R')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<Rook>());
            else if (symbolInFile == 'N')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<Knight>());
            else if (symbolInFile == 'B')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<Bishop>());
            else if (symbolInFile == 'Q')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<Queen>());
            else if (symbolInFile == 'K')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<King>());
            else if (symbolInFile == 'P')
                table[i][j].piece = dynamic_pointer_cast <Chessman> (make_shared<Pawn>());
            file >> table[i][j].piece->wasMove;
        }
    }
    file >> (int&)nextPlayer;
    file.close();
}

void ChessBoard::check_board(string boardForCheck)
{
    string board = print_to_string();
    if (board != boardForCheck)
    {
        cout << "Expected" << endl << boardForCheck << endl;
        cout << "Reality" << endl << board << endl << flush;
        throw runtime_error("check board failed");
    }

}