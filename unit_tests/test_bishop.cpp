//
// Created by tanya on 29.04.20.
//

#include "../chessboard.hpp"

void test_bishop()
{
    //check KILL
    ChessBoard chessBoard;
    chessBoard.create_clean_board();
    chessBoard.put_chessman("d1", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("e2", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │WB│  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │BQ│  │  │  ║2\n"
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
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("d1-e2"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WB│  │  │  ║2\n"
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
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("d1", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("e2", make_shared<Queen>(), WHITE);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │WB│  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WQ│  │  │  ║2\n"
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
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("d1-e2"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │WB│  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WQ│  │  │  ║2\n"
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
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("e2", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("b5", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WB│  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │BQ│  │  │  │  │  │  ║5\n"
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
    chessBoard.move(Coordinates("e2-b5"));
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
                           "5║  │WB│  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │  │  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "BLACK's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("b5", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("f2", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │BQ│  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │WB│  │  │  │  │  │  ║5\n"
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
    chessBoard.move(Coordinates("b5-g1"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │BQ│  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │WB│  │  │  │  │  │  ║5\n"
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
    //check MOVE
    chessBoard.create_clean_board();
    chessBoard.put_chessman("e2", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("b5", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WB│  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │BQ│  │  │  │  │  │  ║5\n"
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
    chessBoard.move(Coordinates("e2-a6"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │WB│  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │  │  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │BQ│  │  │  │  │  │  ║5\n"
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
    chessBoard.create_clean_board();
    chessBoard.put_chessman("b5", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("c6", make_shared<Queen>(), BLACK);
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
                           "5║  │WB│  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │BQ│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.move(Coordinates("b5-d7"));
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
                           "5║  │WB│  │  │  │  │  │  ║5\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "6║  │  │BQ│  │  │  │  │  ║6\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "7║  │  │  │  │  │  │  │  ║7\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "8║  │  │  │  │  │  │  │  ║8\n"
                           " ╚══╧══╧══╧══╧══╧══╧══╧══╝\n"
                           "   a  b  c  d  e  f  g  h\n"
                           "            Black\n"
                           "WHITE's move next\n");
    chessBoard.create_clean_board();
    chessBoard.put_chessman("b5", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("c4", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │BQ│  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │WB│  │  │  │  │  │  ║5\n"
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
    chessBoard.move(Coordinates("b5-d3"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │BQ│  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │WB│  │  │  │  │  │  ║5\n"
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
    chessBoard.create_clean_board();
    chessBoard.put_chessman("d5", make_shared<Bishop>(), WHITE);
    chessBoard.put_chessman("c4", make_shared<Queen>(), BLACK);
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │BQ│  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │WB│  │  │  │  ║5\n"
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
    chessBoard.move(Coordinates("d5-b3"));
    chessBoard.check_board("            White\n"
                           "   a  b  c  d  e  f  g  h\n"
                           " ╔══╤══╤══╤══╤══╤══╤══╤══╗\n"
                           "1║  │  │  │  │  │  │  │  ║1\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "2║  │  │  │  │  │  │  │  ║2\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "3║  │  │  │  │  │  │  │  ║3\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "4║  │  │BQ│  │  │  │  │  ║4\n"
                           " ╟──┼──┼──┼──┼──┼──┼──┼──╢\n"
                           "5║  │  │  │WB│  │  │  │  ║5\n"
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
}
