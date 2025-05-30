#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <iostream>

using namespace std;
struct player {
    string name;
    int score;
    int step;
    int rank;
    struct player* next = NULL;
};
int main()
{

    initgraph(720, 900);
    setbkcolor(RGB(254, 246, 238));
    cleardevice();
    startmenu();
    getchar();
    return 0;
}
