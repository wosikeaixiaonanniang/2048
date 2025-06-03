#define _CRT_SECURE_NO_WARNINGS
#include "header.h"



int main()
{
	playername = "name";
	issignin = false;
	usercheck = false;
	FreeConsole();
	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	startmenu();
	return 0;
}
