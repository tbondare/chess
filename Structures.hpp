//
// Created by tanya on 27.04.20.
//

#ifndef CHESS_STRUCTURES_HPP
#define CHESS_STRUCTURES_HPP

#include <vector>
#include <memory>

using namespace std;

enum Color {WHITE, BLACK};
class Chessman;

struct Cell
{
    Color color;
    shared_ptr <Chessman> piece;
};

struct Coordinates
{
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};

#endif //CHESS_STRUCTURES_HPP

