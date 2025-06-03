#pragma once
#include <algorithm>
#include <chrono>
#include <cmath>
#include <easyx.h>
#include <fstream>
#include <math.h>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

const int row = 4; // 4行
const int col = 4; // 4列
const int score = 0; // 总得分
#define DIR_UP 1
#define DIR_DOWN 2
#define DIR_LEFT 3
#define DIR_RIGHT 4
const int BOX_COUNT = 10; // 横框数量
static string playername; // 横框数量
static bool issignin;
static bool usercheck;

struct User {
    string name;
    string password;
};

class GameTime {
public:
    int hours;
    int minutes;
    int seconds;
};

class GameTimer {
public:
    clock_t startTime;
    clock_t pauseTime;
    int elapsedSeconds;
    bool isPaused;

    void start();
    void pause();
    void resume();
    GameTime getGameTime();
};

class Player {
public:
    std::string name;
    int score;
    int step;
    int rank;
    Player* next;

    Player()
        : score(0)
        , step(0)
        , rank(0)
        , next(nullptr)
    {
    }
    Player(const Player& other)
        : name(other.name)
        , score(other.score)
        , step(other.step)
        , rank(other.rank)
        , next(nullptr)
    {
    }

    static void record(std::string name, int score, int step);
    static Player* showrecord();
    static Player* findrecord(std::string name);
};

void numberadd(int board[4][4], int& score, int direction);
void thirdmenu();
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
void gamemenu(int board[4][4], bool issignin);
void givecolor(int num, int x, int y);
void startbuttonshow(int y, const char str[], int a, int b, int c);
void startmenu();
void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy, const char str[]);
void registerUser(string name, string password);
bool checkUser(string name, string password);
extern "C" void show_message_window(const char* message);
void showerror(const char str[]);
