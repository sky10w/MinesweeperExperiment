#pragma once
#include <vector>
#include <iostream>
#include "base.hpp"

class Board
{
private:
    int _row, _col;
    int _bombNum;
    int _gameover;
    std::vector<std::vector<Cell>> _map;
public:
    const std::vector<std::vector<Cell>>& getMap();
    int  checkGameOver();

    //* this function needs completion *//
    Board(int row = 9, int col = 9, int bombNum = 10);

    //* the following functions needs definition *//
    bool reveal(Point pt);      // reveal a cell (return value indicates an error)
    bool mark(Point pt);        // mark a cell (return value indicated an error)
};
