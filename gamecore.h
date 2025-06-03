#pragma once
class GameCore
{
protected:
    int board[4][4] = { 0 }; // 棋盘状态
    int score = 0;         // 当前分数
    int step = 0;          // 当前步数
    bool moved = false;    // 上次操作是否移动
public:
    void newnumber(int board[4][4], int& score, int n);
    void record(string name, int score, int step);
    Player* findrecord(string name);

    bool slideAndMerge(int line[4], int& score);
    void numberadd(int board[4][4], int& score, int direction);
};
class GameTimer
{
public:

    clock_t startTime;
    clock_t pauseTime;
    int elapsedSeconds;
    bool isPaused;
};
class Time
{
protected:
    int hours;
    int minutes;
    int seconds;
    GameTimer Timer;
public:
    void startTimer(GameTimer& timer);
    void pauseTimer(GameTimer& timer);
    void resumeTimer(GameTimer& timer);
    Time getGameTime(GameTimer& timer);

};
