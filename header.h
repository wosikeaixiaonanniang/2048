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
#define DIR_UP    1
#define DIR_DOWN  2
#define DIR_LEFT  3
#define DIR_RIGHT 4




class Player 
{
public:
    std::string name;
    int score;
    int step;
    int rank;
    class Player* next;
    string getname()
    {
        return name;
    }
    int getscore()
    {
        return score;
    }
    int getstep()
    {
        return step;
    }
    int getrank()
    {
        return rank;
    }
    Player* getnext()
    {
        return next;
    }
   
        
};
class User 
{
public:
    string name;
    string password;
};
