#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{

	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	startmenu();
	

	getchar();
	return 0;
}
