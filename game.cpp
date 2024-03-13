#include "game.hpp"

int Game::calculateDigits(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        x /= 10;
        cnt++;
    }
    return cnt;
}

void Game::printBoard(Board& b)
{
    auto mp = b.getMap();
    int row = mp.size();
    int col = mp[0].size();

    system("cls");

    // 打印列号
    std::cout << std::setw(_maxLength + 1) << " ";
    for (int i = 0; i < row; i++)
    {
        std::cout << std::setw(_maxLength) << i << " ";
    }
    std::cout << '\n';

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // The header of each line
            if (j == 0)
            {
                std::cout << std::setw(_maxLength) << i << " ";
            }
            // Print the corresponding letter
            auto& ele = mp[i][j];
            std::cout << std::setw(_maxLength) << _Sign::getSign(ele) << ' ';

            // Start a new line when it's necessary
            if (j == col - 1)
            {
                std::printf("\n");
            }
        }
    }
}

Game::Game(bool debug)
    :_end(false)
{
    int row, col, bomb;
    if (!debug)
    {
        std::cout << "Welcome to Minesweeper Game." << '\n';
        std::cout << "Please input the row num, column num and bomb num" << '\n';
        std::cin >> row >> col >> bomb;
    } else
    {
        row = 10, col = 10, bomb = 15;
    }
    b = Board(row, col, bomb);
    this->_maxLength = std::max(calculateDigits(row), calculateDigits(col));
}

void Game::run()
{
    while (!_end)
    {
        // Enters a loop where repeatedly print the board and ask for operation
        while (!b.checkGameOver())
        {
            // 1. Print the board
            printBoard(b);
            // 2. Ask for input
            auto res = ask();
            // 3. Execute corresponding operation
            if (act(b, res)) break;
        }

        // Print the board again to show the result
        printBoard(b);
        // End the game when WIN or LOSE
        _end = endGame();
    }
}

bool Game::act(Board& b, Game::query_t q)
{
    switch (q.first)
    {
    case 1:
        // reveal a cell
        if (b.reveal(q.second))
        {
            std::cout << "Fail to flip, please input again" << '\n';
            system("pause");
        }
        break;
    case 2:
        // mark a cell
        if (b.mark(q.second))
        {
            std::cout << "Fail to mark, please input again" << '\n';
            system("pause");
        }
        break;
    case 3:
        // quit the game
        return true;
        break;
    default:
        std::cout << "Unexpected operation code, please input again" << '\n';
        system("pause");
        break;
    }
    return false;
}

Game::query_t Game::ask()
{
    std::cout << "Please enter the operation code:\n"
        << "1. Flip a cell\t" << "2. Mark a cell as a bomb\n";
    int opt;
    std::cin >> opt;

    std::cout << "Please enter the coordination:\n";
    int coord_x, coord_y;
    std::cin >> coord_x >> coord_y;
    return { opt, Point{coord_x, coord_y} };
}

bool Game::endGame()
{
    if (b.checkGameOver() == 1)
    {
        std::cout << "Congratuate, you win!!" << '\n';
    } else if (b.checkGameOver() == 2)
    {
        std::cout << "Pity... you lose..." << '\n';
    }
    char retry;
    std::cout << "You wanna play again? ('y' or 'n')" << '\n';
    std::cin >> retry;
    return retry == 'y';
}
