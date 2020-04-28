//
// Created by tanya on 27.04.20.
//

#include "../chessboard.hpp"

void check_pawn()
{
    ChessBoard chessBoard;
    chessBoard.create_clean_board();
    chessBoard.put_chessman(3, 6, make_shared <Pawn>(), BLACK);
    chessBoard.put_chessman(4, 5, make_shared<Pawn>(), WHITE);
    chessBoard.print();
    chessBoard.move(Coordinates {3, 6, 4, 5});
    chessBoard.print();
}
