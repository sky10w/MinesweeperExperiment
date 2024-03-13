#include "board.hpp"

Board::Board(int row, int col, int bombNum)
    : _row(row)
    , _col(col)
    , _bombNum(bombNum)
    , _gameover(0)
{
    _map.resize(_row);
    for (auto& m : _map) { m.resize(_col); }

    // TODO : other Initial code
}

int Board::checkGameOver()
{
    return this->_gameover;
}

const std::vector<std::vector<Cell>>& Board::getMap()
{
    return this->_map;
}

// TODO : the remaining functions