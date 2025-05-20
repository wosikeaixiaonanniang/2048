#pragma once
#include <math.h>
#include <string.h>
#include <easyx.h>
const int row = 4;//4ÐÐ
const int col = 4;//4ÁÐ
const int score = 0;//×ÜµÃ·Ö
void thirdmenu();
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
void gamemenu(int board[4][4]);
void givecolor(int num, int x, int y);
void startbuttonshow(int y, const char str[],int a,int b,int c);
void startmenu();



