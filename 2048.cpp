#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include "ui.h"
#include "gamecore.h"


int main()
{

	GameUI ui;
	FreeConsole();
	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	ui.showmenu();
	return 0;
}
