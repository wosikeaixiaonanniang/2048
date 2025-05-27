#pragma once
#include <algorithm>
#include <chrono>
#include <cmath>
#include <easyx.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const int row = 4;
const int col = 4;
const int score = 0;
#define DIR_UP    1
#define DIR_DOWN  2
#define DIR_LEFT  3
#define DIR_RIGHT 4
const int BOX_COUNT = 30; // 横框数量
struct GameTime {
    int hours;
    int minutes;
    int seconds;
};

struct Player {
    std::string name;
    int score;
    int step;
    int rank;
    struct Player* next;
};

void thirdmenu();
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
void gamemenu(int board[4][4]);
void givecolor(int num, int x, int y);
void startbuttonshow(int y, const char str[], int a, int b, int c);
void startmenu();
void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy, const char str[]);

void newnumber(int (&board)[4][4], int& score, int n); // 在随机位置生成新数字

void startGameTimer(); // 开始计时
GameTime getGameDuration(); // 获取游戏时长

void record(std::string name, int score, int step); // 保存记录
struct Player* showrecord(); // 获取排行榜
struct Player findrecord(std::string name); // 查找玩家记录
