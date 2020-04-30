//
// Created by tanya on 30.04.20.
//

#include "../chessboard.hpp"

void test_mate()
{
    ChessBoard chessBoard;
    chessBoard.create_clean_board();
    chessBoard.put_chessman("c6", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("d7", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("g8", make_shared<King>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │WR│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    auto isNoMate = chessBoard.move(Coordinates("c6-c8"));
    if (isNoMate)
        throw runtime_error("check mate failed");
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │WR│  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("c6", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("d7", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("g8", make_shared<King>(), BLACK);
    chessBoard.put_chessman("f7", make_shared<Pawn>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │WR│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │BP│  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    isNoMate = chessBoard.move(Coordinates("c6-c8"));
    if (!isNoMate)
        throw runtime_error("check mate failed");
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │BP│  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │WR│  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("c6", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("d7", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("g8", make_shared<King>(), BLACK);
    chessBoard.put_chessman("b6", make_shared<Knight>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │BN│WR│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    isNoMate = chessBoard.move(Coordinates("c6-c8"));
    if (!isNoMate)
        throw runtime_error("check mate failed");
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │BN│  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │WR│  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("c6", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("d7", make_shared<Rook>(), WHITE);
    chessBoard.put_chessman("g8", make_shared<King>(), BLACK);
    chessBoard.put_chessman("e4", make_shared<Rook>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │BR│  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │WR│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    isNoMate = chessBoard.move(Coordinates("c6-c8"));
    if (!isNoMate)
        throw runtime_error("check mate failed");
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │BR│  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │WR│  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │WR│  │  │  │BK│  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
}