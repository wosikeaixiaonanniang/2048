#pragma once
#include <math.h>
#include <string>
#include <easyx.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
const int row = 4;//4行
const int col = 4;//4列
const int score = 0;//总得分
#define DIR_UP    1
#define DIR_DOWN  2
#define DIR_LEFT  3
#define DIR_RIGHT 4
const int BOX_COUNT = 10; // 横框数量
static string playername; // 横框数量
static bool issignin;
static bool usercheck;


class Player 
{
public:

    std::string name;
    int score;
    int step;
    int rank;
    class Player* next;
  
};
class PlayerManager 
{
private:

public:
    
   

};




class User 
{
public:

    string name;
    string password;
};
Player* showrecord();
