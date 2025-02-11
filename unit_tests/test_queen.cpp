//
// Created by tanya on 29.04.20.
//

#include "../chessboard.hpp"

void test_queen()
{
    ChessBoard chessBoard;
    chessBoard.create_clean_board();
    chessBoard.put_chessman("h4", make_shared<Queen>(), BLACK);
    chessBoard.put_chessman("h1", make_shared<Queen>(), WHITE);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │WQ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │BQ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("h1-a8"));
    chessBoard.move(Coordinates("h4-e1"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │BQ│  │  │  ║1\n"
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
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║WQ│  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("a8-a1"));
    chessBoard.move(Coordinates("e1-e8"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║WQ│  │  │  │  │  │  │  ║1\n"
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
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │BQ│  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.create();
    chessBoard.move(Coordinates("e2-e4"));
    chessBoard.move(Coordinates("e7-e5"));
    chessBoard.move(Coordinates("d1-g4"));
    chessBoard.move(Coordinates("d7-d6"));
    chessBoard.move(Coordinates("g4-f3"));
    chessBoard.move(Coordinates("h7-h5"));
    chessBoard.move(Coordinates("g1-e2"));
    chessBoard.move(Coordinates("c8-g4"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║WR│WN│WB│  │WK│WB│  │WR║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║WP│WP│WP│WP│WN│WP│WP│WP║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │WQ│  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │WP│  │BB│  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │BP│  │  │BP║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │BP│  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║BP│BP│BP│  │  │BP│BP│  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║BR│BN│  │BQ│BK│BB│BN│BR║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("f3-g4"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║WR│WN│WB│  │WK│WB│  │WR║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║WP│WP│WP│WP│WN│WP│WP│WP║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │WP│  │WQ│  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │BP│  │  │BP║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │BP│  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║BP│BP│BP│  │  │BP│BP│  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║BR│BN│  │BQ│BK│BB│BN│BR║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.move(Coordinates("d8-h4"));
    chessBoard.move(Coordinates("g4-e4"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║WR│WN│WB│  │WK│WB│  │WR║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║WP│WP│WP│WP│WN│WP│WP│WP║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │WP│  │WQ│BQ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │  │BP│  │  │BP║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │BP│  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║BP│BP│BP│  │  │BP│BP│  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║BR│BN│  │  │BK│BB│BN│BR║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
}
