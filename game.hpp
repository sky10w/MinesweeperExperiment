#pragma once
#include <iostream>
#include "board.hpp"
#include "base.hpp"

class Game
{
public:
    using query_t = std::pair<int, Point>;
private:
    Board b;
    int _maxLength;
    bool _end;
    int calculateDigits(int x);

    void printBoard(Board& b);
    bool act(Board& b, query_t q);
    query_t ask();
    bool endGame();
public:
    Game(bool debug = 0);
    void run();
};

