#define _CRT_SECURE_NO_WARNINGS
#include "header.h"



struct player
{
	string name;
	int score;
	int step;
	int rank;
	struct player* next = NULL;
};
int main()
{
	playername = "name";
	issignin = false;
	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	startmenu();
	getchar();
	return 0;
}
