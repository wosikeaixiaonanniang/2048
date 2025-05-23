#pragma once
#include <math.h>
#include <string.h>
#include <easyx.h>
const int row = 4;//4行
const int col = 4;//4列
const int score = 0;//总得分
void thirdmenu();
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
void gamemenu(int board[4][4]);
void givecolor(int num, int x, int y);
void startbuttonshow(int y, const char str[],int a,int b,int c);
void startmenu();
void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy, const char str[]);



