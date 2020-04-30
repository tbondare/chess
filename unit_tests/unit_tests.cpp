//
// Created by tanya on 25.04.20.
//
#include <iostream>
using namespace std;

void test_pawn();
void test_rook();
void test_knight();
void test_bishop();
void test_king();
void test_queen();
void test_mate();

int main()
{
    test_pawn();
    test_rook();
    test_knight();
    test_bishop();
    test_king();
    test_queen();
    test_mate();
    cout << "All tests were passed without errors." << endl;
    return 0;
}