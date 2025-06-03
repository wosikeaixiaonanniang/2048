#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include "ui.h"
#include "gamecore.h"


int main()
{
	playername = "name";
	issignin = false;
	usercheck = false;
	GameUI ui;
	FreeConsole();
	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	ui.startmenu();
	return 0;
}
