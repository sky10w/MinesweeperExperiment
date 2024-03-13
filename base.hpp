#pragma once

struct Cell
{
    bool isBomb;
    bool isRevealed;
    bool isMarked;
    int bombNum;
    Cell()
        : isBomb(false)
        , isRevealed(false)
        , isMarked(false)
        , bombNum(0)
    {}
};

struct Point
{
    int x, y;
    Point operator+(const Point& p) const
    {
        return { this->x + p.x, this->y + p.y };
    }
    Point operator-(const Point& p) const
    {
        return { this->x - p.x, this->y - p.y };
    }
};

namespace _Sign
{
    using sign_t = const char;
    sign_t UNCOVER = '_';
    sign_t BLANK = 'M';
    sign_t MINE = 'X';
    sign_t FLAG = 'P';
    sign_t NS[10] = { 'O', '1', '2', '3', '4', '5', '6','7', '8', '9' };
    sign_t getSign(const Cell& c);
};