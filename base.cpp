#include "base.hpp"

namespace _Sign
{
    sign_t getSign(const Cell& c)
    {
        if (c.isMarked)
        {
            return _Sign::FLAG;
        } else if (c.isRevealed == false)
        {
            return _Sign::UNCOVER;
        } else if (c.isBomb)
        {
            return _Sign::MINE;
        } else
        {
            return _Sign::NS[c.bombNum];
        }
    }
} // namespace _Sign
