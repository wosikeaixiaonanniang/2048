#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <iostream>
void generateRandomTile(int board[4][4])
{
    int emptyCells = 0;
    int emptyPositions[16][2]; // 存储所有空白格子的坐标

    // 收集所有空白格子
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                emptyPositions[emptyCells][0] = i;
                emptyPositions[emptyCells][1] = j;
                emptyCells++;
            }
        }
    }

    // 如果有空白格子，随机选择一个位置放置2或4
    if (emptyCells > 0) {
        int pos = rand() % emptyCells;
        int value = (rand() % 10 == 0) ? 4 : 2; // 10%概率生成4
        board[emptyPositions[pos][0]][emptyPositions[pos][1]] = value;
    }
}
bool slideAndMerge(int line[4], int& score)
{
    bool moved = false;
    int temp[4] = { 0 };
    int index = 0;

    // 1. 移动所有数字到左侧（去除0）
    for (int i = 0; i < 4; i++) {
        if (line[i] != 0) {
            temp[index++] = line[i];
        }
    }

    // 2. 合并相邻相同数字
    for (int i = 0; i < 3; i++) {
        if (temp[i] != 0 && temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            score += temp[i]; // 加分
            temp[i + 1] = 0;
            moved = true;
        }
    }

    // 3. 再次移动（处理合并后可能出现的空位）
    index = 0;
    for (int i = 0; i < 4; i++) {
        line[i] = 0;
        if (temp[i] != 0) {
            line[index++] = temp[i];
        }
    }

    // 检查是否发生移动（与原始数据比较）
    for (int i = 0; i < 4; i++) {
        if (line[i] != temp[i]) {
            moved = true;
        }
    }

    return moved;
}

// 主逻辑函数
void numberadd(int board[4][4], int& score, int direction)
{
    bool moved = false;
    int temp[4];

    switch (direction) {
    case DIR_UP:
        // 处理每一列（从上到下）
        for (int j = 0; j < 4; j++) {
            // 提取一列
            for (int i = 0; i < 4; i++)
                temp[i] = board[i][j];
            // 处理这一列
            if (slideAndMerge(temp, score))
                moved = true;
            // 写回
            for (int i = 0; i < 4; i++)
                board[i][j] = temp[i];
        }
        break;

    case DIR_DOWN:
        // 处理每一列（从下到上）
        for (int j = 0; j < 4; j++) {
            // 提取一列（反向）
            for (int i = 0; i < 4; i++)
                temp[3 - i] = board[i][j];
            // 处理这一列
            if (slideAndMerge(temp, score))
                moved = true;
            // 写回（反向）
            for (int i = 0; i < 4; i++)
                board[i][j] = temp[3 - i];
        }
        break;

    case DIR_LEFT:
        // 处理每一行（从左到右）
        for (int i = 0; i < 4; i++) {
            // 直接处理行
            if (slideAndMerge(board[i], score))
                moved = true;
        }
        break;

    case DIR_RIGHT:
        // 处理每一行（从右到左）
        for (int i = 0; i < 4; i++) {
            // 提取一行（反向）
            for (int j = 0; j < 4; j++)
                temp[3 - j] = board[i][j];
            // 处理这一行
            if (slideAndMerge(temp, score))
                moved = true;
            // 写回（反向）
            for (int j = 0; j < 4; j++)
                board[i][j] = temp[3 - j];
        }
        break;
    }
}
