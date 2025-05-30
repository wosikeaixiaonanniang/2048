#pragma once
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <easyx.h>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

const int row = 4;
const int col = 4;
const int score = 0;
#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4
const int BOX_COUNT = 30;

struct Player {
    std::string name;
    int score;
    int step;
    int rank;
    struct Player* next = nullptr;
};

struct GameTime {
    int hours;
    int minutes;
    int seconds;
};

struct GameTimer {
    clock_t startTime;
    clock_t pauseTime;
    int elapsedSeconds;
    bool isPaused;
};

void thirdmenu();
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
void gamemenu(int board[4][4]);
void givecolor(int num, int x, int y);
void startbuttonshow(int y, const char str[], int a, int b, int c);
void startmenu();
void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy, const char str[]);

void newnumber(int board[4][4], int& score, int n);
void startTimer(GameTimer& timer);
void pauseTimer(GameTimer& timer);
void resumeTimer(GameTimer& timer);
GameTime getGameTime(GameTimer& timer);
void record(const std::string& name, int score, int step);
Player* showrecord();
Player* findrecord(const std::string& name);
