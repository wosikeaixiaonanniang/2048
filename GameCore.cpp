#include "GameCore.h"
#include "header.h"
using namespace std;

void GameCore::init()
{
    for (int i = 0; i < 2; i++)
        newNumber(4);
    score = 0;
    step = 0;
}

void GameCore::newNumber(int maxMultiple)
{
    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                emptyCells.emplace_back(i, j);

    if (emptyCells.empty())
        return;
    auto [x, y] = emptyCells[rand() % emptyCells.size()];
    int value = (rand() % 10 < 9) ? 2 : 4; // 90%概率生成2
    board[x][y] = min(value, maxMultiple);
    score += value;
}

void GameCore::handleMove(int direction)
{
    moved = false;
    int temp[4];
    switch (direction)
    {
    case DIR_UP:
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
                temp[i] = board[i][j];
            if (slideAndMerge(temp))
                moved = true;
            for (int i = 0; i < 4; i++)
                board[i][j] = temp[i];
        }
        break;
    case DIR_DOWN:
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
                temp[3 - i] = board[i][j];
            if (slideAndMerge(temp))
                moved = true;
            for (int i = 0; i < 4; i++)
                board[i][j] = temp[3 - i];
        }
        break;
    case DIR_LEFT:
        for (int i = 0; i < 4; i++)
            if (slideAndMerge(board[i]))
                moved = true;
        break;
    case DIR_RIGHT:
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                temp[3 - j] = board[i][j];
            if (slideAndMerge(temp))
                moved = true;
            for (int j = 0; j < 4; j++)
                board[i][j] = temp[3 - j];
        }
        break;
    }
    if (moved)
        step++;
}
