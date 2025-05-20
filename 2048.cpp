#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
#include <iostream>
#include <string.h>
using namespace std;
bool button(int x1, int y1, int x2, int y2, int msgx,int msgy)
{
	if (msgx >= x1 && msgx <= x2 && msgy >= y1 && msgy <= y2)
	{
		return true;
	}
	else
		return false;
	
	
}
void givecolor(int num, int x, int y)
{
	x++;
	y++;
	int hspace = 0;
	int vspace = 0;
	int size = 100;
	char str[10];
	if (num != 0)
	{
		sprintf(str, "%d", num);  // 数字转字符串
	}
	else
	{
		str[0] = '\0';  // 0 时不显示文字
	}
	switch (num)
	{
	case 0:
		setfillcolor(RGB(209, 191, 182));
		break;
		
	case 2:
		setfillcolor(RGB(92,206,251));
		size = 80;
		break;

	case 4:
		setfillcolor(RGB(146, 233, 253));
		size = 80;
		break;

	case 8:
		setfillcolor(RGB(201, 239, 253));
		size = 80;
		break;
	case 16:
		setfillcolor(WHITE);
		size = 60;
		break;
	case 32:
		setfillcolor(RGB(254, 214, 244));
		size = 60;
		break;
	case 64:
		setfillcolor(RGB(251, 167, 233));
		size = 60;
		break;
	case 128:
		setfillcolor(RGB(254, 127, 220));
		size = 50;
		break;
	case 256:
		setfillcolor(RGB(211, 46, 4));
		size = 50;
		break;
	case 512:
		setfillcolor(RGB(234, 93, 32));
		size = 50;
		break;
	case 1024:
		setfillcolor(RGB(253, 142, 62));
		size = 50;
		break;
	case 2048:
		setfillcolor(RGB(254, 190, 93));
		size = 50;
		break;
	case 4096:
		setfillcolor(RGB(230, 124, 191));
		size = 50;
		break;
	case 8192:
		setfillcolor(RGB(209, 83, 160));
		size = 50;
		break;
	default:
		size = 40;
		break;
	}
	int left = 100 + 24 * x + 100 * (x - 1);
	int top = 320 + 24 * y + 100 * (y - 1);
	solidroundrect(left, top, left + 100, top + 100, 20, 20);

	if (num != 0)
	{
		settextstyle(size, 0, "微软雅黑");  
		setbkmode(TRANSPARENT);
		hspace = (100 - textwidth(str)) / 2;
		vspace = (100 - textheight(str)) / 2;
		settextcolor(DARKGRAY);

		outtextxy(left + hspace, top + vspace, str);
	}

}

void gamemenu(int board[4][4])
{
	ExMessage msg = { 0 };


	//背景和棋盘
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	setfillcolor(RGB(189, 172, 162));
	solidroundrect(100, 320, 100 + 520, 320 + 520, 50, 50);
	//2048文字
	settextstyle(100, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	int hspace = (250 - textwidth("2048")) / 2;
	int vspace = (200 - textheight("2048")) / 2;
	outtextxy(110 + hspace, 60 + vspace, "2048");
	//积分栏
	setfillcolor(RGB(189, 172, 162));

	solidroundrect(340, 100, 340 + 100, 100 + 100, 10, 10);
	setfillcolor(RGB(189, 172, 162));
	solidroundrect(450, 100, 450 + 100, 100 + 100, 10, 10);
	settextstyle(40, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	hspace = (100 - textwidth("score")) / 2;
	vspace = (50 - textheight("score")) / 2;
	outtextxy(340 + hspace, 100 + vspace, "score");
	hspace = (100 - textwidth("best")) / 2;
	vspace = (50 - textheight("best")) / 2;
	outtextxy(450 + hspace, 100 + vspace, "best");
	//时间
	hspace = (100 - textwidth("00:00:00")) / 2;
	vspace = (100 - textheight("00:00:00")) / 2;
	settextstyle(30, 0, "微软雅黑");
	outtextxy(325 + hspace, 200 + vspace, "00:00:00");
	//撤销 暂停 结束
	
	settextstyle(35, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	outtextxy(310, 280, "←");
	settextstyle(30, 0, "微软雅黑");
	settextcolor(DARKGRAY);
	outtextxy(350, 280, "||");
	settextstyle(40, 0, "微软雅黑");
	outtextxy(380, 275, "×");
	//给格子上色和数字显示
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			givecolor(board[i][j], i, j);
		}
	}

	while (1)//游戏界面用
{	
	if (peekmessage(&msg, EX_MOUSE))
	{
		
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (button(310, 280, 340, 310, msg.x, msg.y))//撤回
			{
				printf("悔步\n", msg.x, msg.y);

			}
			if (button(340, 280, 370, 310, msg.x, msg.y))//暂停
			{
				printf("暂停\n", msg.x, msg.y);

			}
			if (button(370, 280, 400, 310, msg.x, msg.y))//放弃
			{
				printf("放弃\n", msg.x, msg.y);

			}
			printf("%d,%d\n", msg.x, msg.y);
			break;



			
		}
		
	}
	
}
}
void startbuttonshow(int y,const char str[])
{
	setfillcolor(RGB(189, 172, 162));
	solidrectangle(150, y, 150 + 420, y + 80);
	settextstyle(60, 0, "微软雅黑");
	int hspace = (420 - textwidth(str)) / 2;
	int vspace = (80 - textheight(str)) / 2;
	outtextxy(150 + hspace, y + vspace, str);
}
void ruleshow(int y, const char str[])
{
	setfillcolor(RGB(189, 172, 162));
	solidrectangle(50, y, 50 + 620, y + 80);
	settextstyle(30, 0, "微软雅黑");
	int hspace = (520 - textwidth(str)) / 2;
	int vspace = (80 - textheight(str)) / 2;
	outtextxy(100 + hspace, y + vspace, str);
}
void secondmenu()
{
	ExMessage msg = { 0 };

	cleardevice();

	ruleshow(100, "目标：通过合并相同数字的方块，最终得到一个2048的方块。");

	ruleshow(200, "移动规则：玩家可以通过上下左右四个方向滑动");
	ruleshow(260, "所有数字方块会向滑动的方向靠拢");

	ruleshow(360, "合并规则：相同数字的方块在靠拢时会相加");
	ruleshow(420, "并且形成一个新的方块。");


	ruleshow(520, "生成规则：每次滑动后，空白处会随机生成一个1或2的方块。");
	ruleshow(620, "失败条件：如果所有格子都填满且没有相邻的相同数字方块。");
	startbuttonshow(750, "确认");
	int check = 1;
	while (check)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//确认
				{
					check = 0;
					startmenu();
				}

				break;

			}
		}
	}

}
void thirdmenu()
{
	ExMessage msg = { 0 };

	//左侧符号
	settextstyle(50, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	setfillcolor(RGB(189, 172, 162));
	solidrectangle(150, 50, 150 + 150, 50 + 150);
	outtextxy(215, 50, "↑");
	outtextxy(215, 150, "↓");
	outtextxy(160, 100, "←");
	outtextxy(250, 100, "→");
	solidrectangle(150, 220, 150 + 150, 220 + 150);
	int hspace = (150 - textwidth("←")) / 2;
	int vspace = (150 - textheight("←")) / 2;
	settextstyle(100, 0, "微软雅黑");
	outtextxy(130+hspace, 200+vspace, "←");
	solidrectangle(150, 390, 150 + 150, 390 + 150);
	hspace = (150 - textwidth("||")) / 2;
	vspace = (150 - textheight("||")) / 2;
	outtextxy(150+hspace, 390+vspace, "||");
	solidrectangle(150, 560, 150 + 150, 560 + 150);
	hspace = (150 - textwidth("×")) / 2;
	vspace = (150 - textheight("×")) / 2;
	outtextxy(150+hspace, 560+vspace, "×");
	//右侧文字
	settextstyle(40, 0, "微软雅黑");
	
	solidrectangle(350, 100, 350 + 250, 100 + 50);
	hspace = (250 - textwidth("按键盘以移动方块")) / 2;
	vspace = (50 - textheight("按键盘以移动方块")) / 2;
	outtextxy(350 + hspace, 100 + vspace, "按键盘以移动方块");
	solidrectangle(350, 270, 350 + 250, 270 + 50);
	hspace = (250 - textwidth("撤回一步")) / 2;
	vspace = (50 - textheight("撤回一步")) / 2;
	outtextxy(350 + hspace, 270 + vspace, "撤回一步");
	solidrectangle(350, 440, 350 + 250, 440 + 50);
	hspace = (250 - textwidth("暂停计时")) / 2;
	vspace = (50 - textheight("暂停计时")) / 2;
	outtextxy(350 + hspace, 440 + vspace, "暂停计时");
	solidrectangle(350, 610, 350 + 250, 610 + 50);
	hspace = (250 - textwidth("放弃游戏")) / 2;
	vspace = (50 - textheight("放弃游戏")) / 2;
	outtextxy(350 + hspace, 610 + vspace, "放弃游戏");
	//返回
	startbuttonshow(750, "确认");

	int check = 1;
	while (check)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//确认
				{
					check = 0;
					startmenu();
				}
			
				break;

			}
		}
	}

}
void startmenu()
{
	ExMessage msg = { 0 };

	//背景
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	//2048文字
	settextstyle(200, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	int hspace = (320 - textwidth("2048")) / 2;
	int vspace = (200 - textheight("2048")) / 2;
	outtextxy(200 + hspace, vspace, "2048");
	//按钮
	startbuttonshow(230, "开 始 游 戏");
	startbuttonshow(360, "游 戏 规 则");
	startbuttonshow(490, "按 键 说 明");
	startbuttonshow(620, "积 分 排 名");
	startbuttonshow(750, "退 出 游 戏");
	//按键
	int check = 1;
	while (check)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 230, 150+420, 230+80, msg.x, msg.y))//开始游戏
				{
					printf("开始游戏\n", msg.x, msg.y);
					int board[row][col];
					for (int i = 0;i < row;i++)
					{
						for (int j = 0;j < col;j++)
						{
							board[i][j] = 0;
						}
					}
					gamemenu(board);

				}
				if (button(150, 360, 150 + 420, 360+80, msg.x, msg.y))//游戏规则
				{
					printf("游戏规则\n", msg.x, msg.y);
					secondmenu();

				}
				if (button(150, 490, 150 + 420, 490 + 80, msg.x, msg.y))//按键说明
				{
					printf("按键说明\n", msg.x, msg.y);
					cleardevice();
					thirdmenu();
				}
				if (button(150, 620, 150 + 420, 620 + 80, msg.x, msg.y))//积分排名
				{
					printf("积分排名\n", msg.x, msg.y);

				}
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//关闭游戏
				{
					printf("关闭游戏\n", msg.x, msg.y);
					closegraph(); 
					exit(0);
				}
				break;

			}
		}
	}
}
int main()
{

	initgraph(720, 900);
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	startmenu();
	

	getchar();
	return 0;
}
