#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void gameover(int score, int step)
{
	ExMessage msg = { 0 };

	setfillcolor(RGB(189, 172, 162));
	fillrectangle(150, 300, 720 - 150, 300 + 300);
	settextstyle(30, 0, "微软雅黑");

	char scoreStr[20];
	sprintf(scoreStr, "%d", score);
	int hspace = (100 - textwidth(scoreStr)) / 2;
	int vspace = (50 - textheight(scoreStr)) / 2;
	outtextxy(350 + hspace, 320 + vspace, scoreStr);
	hspace = (100 - textwidth("所得分数")) / 2;
	vspace = (50 - textheight("所得分数")) / 2;
	outtextxy(225 + hspace, 320 + vspace, "所得分数");

	hspace = (100 - textwidth("所用步数")) / 2;
	vspace = (50 - textheight("所用步数")) / 2;
	outtextxy(225 + hspace, 370 + vspace, "所用步数");
	char stepStr[20];
	sprintf(stepStr, "%d", step);
	hspace = (100 - textwidth(stepStr)) / 2;
	vspace = (50 - textheight(stepStr)) / 2;
	outtextxy(350 + hspace, 370 + vspace, stepStr);
	hspace = (100 - textwidth("所用时间")) / 2;
	vspace = (50 - textheight("所用时间")) / 2;
	outtextxy(225 + hspace, 420 + vspace, "所用时间");
	hspace = (100 - textwidth("00:00:00")) / 2;
	vspace = (50 - textheight("00:00:00")) / 2;
	outtextxy(350 + hspace, 420 + vspace, "00:00:00");
	while (1)
	{
		BeginBatchDraw();

		if (msg.x >= 250 && msg.x <= 720-250 && msg.y >= 500 && msg.y <= 550)
		{
			setfillcolor(RGB(125, 125, 125));
			solidrectangle(250, 500, 720 - 250, 500 + 50);
			settextstyle(40, 0, "微软雅黑");
			int hspace = (220 - textwidth("确  认")) / 2;
			int vspace = (50 - textheight("确  认")) / 2;
			outtextxy(250 + hspace, 500 + vspace, "确  认");
		}
		else
		{
			setfillcolor(RGB(209, 191, 182));
			solidrectangle(250, 500, 720 - 250, 500 + 50);
			settextstyle(40, 0, "微软雅黑");
			int hspace = (220 - textwidth("确  认")) / 2;
			int vspace = (50 - textheight("确  认")) / 2;
			outtextxy(250 + hspace, 500 + vspace, "确  认");
		}
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(250, 500, 250 + 220, 500 + 50, msg.x, msg.y))//确认
				{
					startmenu();
				}

				break;

			}
		}
	}
}
bool button(int x1, int y1, int x2, int y2, int msgx, int msgy)
{
	if (msgx >= x1 && msgx <= x2 && msgy >= y1 && msgy <= y2)
	{
		return true;
	}
	else
		return false;


}
void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy,const char str[])
{
	if (msgx >= x1 && msgx <= x2 && msgy >= y1 && msgy <= y2)
	{
		startbuttonshow(y1, str, 125, 125, 125);
	}
	else
	{
		startbuttonshow(y1, str, 189, 172, 162);
	}
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
		setfillcolor(RGB(92, 206, 251));
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
void updatedisplay(int score, int board[4][4])
{
	int bestscore = 0;
	BeginBatchDraw();
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
	hspace = (100 - textwidth("best")) / 2;
	vspace = (50 - textheight("best")) / 2;
	outtextxy(450 + hspace, 100 + vspace, "best");
	char bestStr[20];
	sprintf(bestStr, "%d", bestscore);
	hspace = (100 - textwidth(bestStr)) / 2;
	vspace = (50 - textheight(bestStr)) / 2;
	outtextxy(450 + hspace, 150 + vspace, bestStr);
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
	settextstyle(40, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	hspace = (100 - textwidth("score")) / 2;
	vspace = (50 - textheight("score")) / 2;
	outtextxy(340 + hspace, 100 + vspace, "score");
	char scoreStr[20];
	sprintf(scoreStr, "%d", score);
	hspace = (100 - textwidth(scoreStr)) / 2;
	vspace = (50 - textheight(scoreStr)) / 2;
	outtextxy(340 + hspace, 150 + vspace, scoreStr);
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			givecolor(board[i][j], i, j);
		}
	}
	EndBatchDraw();
}
void gamemenu(int board[4][4])
{
	ExMessage msg = { 0 };
	//撤回
	int backStack[3][4][4];  
	int backScores[3];       
	int backSteps[3];        
	int backTop = -1;        // -1表示空

	//分数，步数
	int score = 0;
	int step = 0;
	
	//给格子上色和数字显示
	//生产2个随机数
	generateRandomTile(board);
	generateRandomTile(board);
	updatedisplay(score, board);
	int checktime = 1000000;
	int check = 1;
	while (1)//游戏界面用
	{
		if (checktime)
		{
			checktime--;
		}
		else
		{
			printf("检查\n");

			checktime = 1000000;
			check = 0;
			for(int i = 0;i < 4;i++)
				for (int j = 0;j < 4;j++)
				{
					if (board[i][j] == 0)
					{
						check = 1;
					}
				}
			if (!check)
			{
				gameover(score, step);//结束游戏
			}
		}
		if (peekmessage(&msg, EX_KEY | EX_MOUSE))
		{
			if (msg.message == WM_KEYDOWN)
			{
				if(msg.vkcode == VK_UP || msg.vkcode == VK_DOWN || msg.vkcode == VK_LEFT || msg.vkcode == VK_RIGHT)
				if (backTop < 2) 
				{
					backTop++; 
					memcpy(backStack[backTop], board, sizeof(int) * 4 * 4);
					backScores[backTop] = score;
					backSteps[backTop] = step;
				}
				else 
				{
					for (int i = 0; i < 2; i++)
					{
						memcpy(backStack[i], backStack[i + 1], sizeof(int) * 4 * 4);
						backScores[i] = backScores[i + 1];
						backSteps[i] = backSteps[i + 1];
					}
					memcpy(backStack[2], board, sizeof(int) * 4 * 4);
					backScores[2] = score;
					backSteps[2] = step;
				}
					switch (msg.vkcode)
					{
					case VK_UP:
						printf("up\n");
						step++;
						numberadd(board, score, DIR_LEFT);
						generateRandomTile(board);


						updatedisplay(score, board);

						break;
					case VK_DOWN:
						printf("down\n");
						step++;
						numberadd(board, score, DIR_RIGHT);
						generateRandomTile(board);

						updatedisplay(score, board);


						break;
					case VK_LEFT:
						printf("left\n");
						step++;
						numberadd(board, score, DIR_UP);
						generateRandomTile(board);

						updatedisplay(score, board);


						break;
					case VK_RIGHT:
						printf("right\n");
						step++;
						numberadd(board, score, DIR_DOWN );
						generateRandomTile(board);

						updatedisplay(score, board);


						break;
					default:
						break;

					}
				
			}
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(310, 280, 340, 310, msg.x, msg.y))//撤回
				{
					if (backTop >= 0) // 如果有历史记录
					{
						printf("悔步\n");

						// 恢复棋盘
						memcpy(board, backStack[backTop], sizeof(int) * 4 * 4);
						score = backScores[backTop];
						step = backSteps[backTop];

						// 更新显示
						updatedisplay(score, board);
						backTop--; // 栈顶指针回退
					}
					else
					{
						printf("无法悔棋，没有历史记录\n");
					}
				}
				if (button(340, 280, 370, 310, msg.x, msg.y))//暂停
				{
					printf("暂停\n", msg.x, msg.y);

				}
				if (button(370, 280, 400, 310, msg.x, msg.y))//放弃
				{
					gameover(score, step);//结束游戏
				}
				printf("%d,%d\n", msg.x, msg.y);
				break;




			}
		}

		

		

		
			

	}
}
void startbuttonshow(int y, const char str[],int a,int b,int c)
{

	setfillcolor(RGB(a, b, c));
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
	while (1)
	{
		BeginBatchDraw();

		buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "确  认");
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//确认
				{
					cleardevice();

					return;
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
	outtextxy(130 + hspace, 200 + vspace, "←");
	solidrectangle(150, 390, 150 + 150, 390 + 150);
	hspace = (150 - textwidth("||")) / 2;
	vspace = (150 - textheight("||")) / 2;
	outtextxy(150 + hspace, 390 + vspace, "||");
	solidrectangle(150, 560, 150 + 150, 560 + 150);
	hspace = (150 - textwidth("×")) / 2;
	vspace = (150 - textheight("×")) / 2;
	outtextxy(150 + hspace, 560 + vspace, "×");
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

	while (1)
	{
		BeginBatchDraw();
		buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "确  认");
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//确认
				{
					cleardevice();

					return;
				}

				break;

			}
		}
	}

}
void drawBoxes(int offsetY) 
{
	settextstyle(200, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	int hspace = (720 - textwidth("2048")) / 2;
	outtextxy(hspace, offsetY, "2048");
	setfillcolor(RGB(189, 172, 162));
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	solidrectangle((720 - 600) / 2, 200 + offsetY, (720 - 600) / 2 + 600, 200 + offsetY + 60);

	char yourtext[300];
	sprintf(yourtext, "您的分数为:%d	您的排名为:%d", 114514,1);//文字内容
	int textWidth = textwidth(yourtext);
	int textHeight = textheight(yourtext);
	outtextxy((720 - textWidth) / 2, 200 + offsetY + (60 - textHeight) / 2, yourtext);
	int startY = 150 + 200 + offsetY;

	for (int i = 0; i < BOX_COUNT; i++) 
	{
		solidrectangle((720 - 600) / 2, startY + i * 70, (720 - 600) / 2 + 600, startY + i * 70 + 60);

		char text[300];
		sprintf(text, "%s的分数为:%d    %s的排名为:%d", "man", i + 1, "man", i + 1);
		int textWidth = textwidth(text);
		int textHeight = textheight(text);
		outtextxy((720 - textWidth) / 2, startY + i * 70 + (60 - textHeight) / 2, text);
	}
}

void signin() 
{
	int loginX = (720 - 500) / 2;
	int loginY = (960 - 350) / 2;

	setfillcolor(RGB(255, 255, 255));
	solidrectangle(loginX, loginY, loginX + 500, loginY + 350);

	settextstyle(40, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	const char* title = "用户登录";
	outtextxy(loginX + (500 - textwidth(title)) / 2, loginY + 30, title);

	string nametext;
	string passtext;
	bool namein = false;
	bool wordin = false;

	ExMessage msg = { 0 };
	bool running = true;
	while (running) 
	{
		BeginBatchDraw();
		cleardevice();
		settextstyle(200, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		settextcolor(DARKGRAY);
		//背景
		int hspace = (320 - textwidth("2048")) / 2;
		int vspace = (200 - textheight("2048")) / 2;
		outtextxy(200 + hspace, vspace, "2048");
		startbuttonshow(230, "开 始 游 戏", 189, 172, 162);
		startbuttonshow(360, "游 戏 规 则", 189, 172, 162);
		startbuttonshow(490, "按 键 说 明", 189, 172, 162);
		startbuttonshow(620, "积 分 排 名", 189, 172, 162);
		startbuttonshow(750, "退 出 游 戏", 189, 172, 162);
		setfillcolor(RGB(189 * 0.9, 172 * 0.9, 162 * 0.9));
		solidrectangle(loginX, loginY, loginX + 500, loginY + 350);

		settextstyle(40, 0, "微软雅黑");
		outtextxy(loginX + (500 - textwidth(title)) / 2, loginY + 30, title);

		settextstyle(30, 0, "微软雅黑");
		outtextxy(loginX + 50, loginY + 70, "账号:");
		outtextxy(loginX + 50, loginY + 150, "密码:");

		setfillcolor(RGB(240, 240, 240));
		solidrectangle(loginX + 50, loginY + 100, loginX + 50 + 500 - 100, loginY + 100 + 50);
		rectangle(loginX + 50, loginY + 100, loginX + 50 + 500 - 100, loginY + 100 + 50);

		setfillcolor(RGB(240, 240, 240));
		solidrectangle(loginX + 50, loginY + 180, loginX + 50 + 500 - 100, loginY + 180 + 50);
		rectangle(loginX + 50, loginY + 180, loginX + 50 + 500 - 100, loginY + 180 + 50);
		//显示

		settextcolor(BLACK);
		if (!nametext.empty()) {
				outtextxy(loginX + 50 + 10, loginY + 100 + (50 - textheight("A")) / 2, nametext.c_str());
		}

		if (!passtext.empty()) 
		{
			string stars(passtext.size(), '*');
			outtextxy(loginX + 50 + 10, loginY + 180 + (50 - textheight("A")) / 2, stars.c_str());
		}

		if (msg.x >= loginX+50 && msg.x <= loginX+ 50 + 180 && msg.y >= loginY+250 && msg.y <= loginY + 310)
		{
			setfillcolor(RGB(125, 125, 125));
			solidrectangle(loginX + 50, loginY + 250, loginX + 50 + 180, loginY + 310);
			settextstyle(30, 0, "微软雅黑");
			int hspace = (180  - textwidth("登录")) / 2;
			int vspace = (60 - textheight("登录")) / 2;
			outtextxy(loginX + 50 + hspace, loginY + 250 + vspace, "登录");
		}
		else
		{
			setfillcolor(RGB(189, 172, 162));
			solidrectangle(loginX + 50, loginY + 250, loginX + 50 + 180, loginY + 310);
			settextstyle(30, 0, "微软雅黑");
			int hspace = (180 - textwidth("登录")) / 2;
			int vspace = (60 - textheight("登录")) / 2;
			outtextxy(loginX + 50 + hspace, loginY + 250 + vspace, "登录");
		}

		if (msg.x >= loginX + 50 + 220 && msg.x <= loginX  +50 + 220 + 180 && msg.y >= loginY + 250 && msg.y <= loginY + 310)
		{
			setfillcolor(RGB(125, 125, 125));
			solidrectangle(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310);
			settextstyle(30, 0, "微软雅黑");
			int hspace = (180 - textwidth("注册")) / 2;
			int vspace = (60 - textheight("注册")) / 2;
			outtextxy(loginX + 50 + 220 + hspace, loginY + 250 + vspace, "注册");
		}
		else
		{
			setfillcolor(RGB(189, 172, 162));
			solidrectangle(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310);
			settextstyle(30, 0, "微软雅黑");
			int hspace = (180 - textwidth("注册")) / 2;
			int vspace = (60 - textheight("注册")) / 2;
			outtextxy(loginX + 50 + 220 + hspace, loginY + 250 + vspace, "注册");
		}


		outtextxy(loginX + 470, loginY, "X");
		EndBatchDraw();

		while (peekmessage(&msg)) 
		{
			switch (msg.message) 
			{
			case WM_LBUTTONDOWN:
				// 检查是否点击了输入框
				namein = button(loginX + 50, loginY + 100,loginX + 50 + 500 - 100,loginY + 100 + 50,msg.x, msg.y);
				wordin = button(loginX + 50, loginY + 180,loginX + 50 + 500 - 100,loginY + 180 + 50,msg.x, msg.y);
				if (button(loginX + 50, loginY + 250, loginX + 50 + 180, loginY + 310, msg.x, msg.y))
				{
					running = false;//确认密码
					cleardevice();

				}
				if (button(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310, msg.x, msg.y))
				{
					running = false;//注册
					cleardevice();

				}
				if (button(loginX + 470, loginY, loginX + 500, loginY + 30, msg.x, msg.y))
				{
					cleardevice();

					running = false;//注册
				}
				break;

			case WM_CHAR:
				if (namein) 
				{
					if (msg.vkcode == '\b') 
					{ 
						if (!nametext.empty()) {
							nametext.pop_back();
						}
					}//删除
					else if (msg.vkcode >= 32 && msg.vkcode <= 126 && nametext.length() <= 20) 
					{ 
						nametext += (char)msg.vkcode;
					}//输入
				}
				else if (wordin) 
				{
					if (msg.vkcode == '\b') 
					{ 
						if (!passtext.empty()) {
							passtext.pop_back();
						}
					}//删除
					else if (msg.vkcode >= 32 && msg.vkcode <= 126 && passtext.length() <= 20) 
					{ 
						passtext += (char)msg.vkcode;
					}//输入
				}
				break;
			}
		}
	}

}
void rankmenu() 
{
	ExMessage msg = { 0 };
	int scrollOffset = 0; // 滚动偏移量
	const int maxScroll = 0; // 最大滚动量
	const int minScroll = -(150 + BOX_COUNT * 70 - (720 - 350)); // 最小滚动量

	cleardevice();
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	int hspace = 0;

	while (1) 
	{
		BeginBatchDraw();
		cleardevice();
		drawBoxes(scrollOffset);
		buttoncolor((720 - 420) / 2, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 150, (720 - 420) / 2 + 420, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 300, msg.x, msg.y, "确  认");
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				if (button((720 - 420) / 2, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 150, (720 - 420) / 2 + 420, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 300, msg.x, msg.y))
				{
					cleardevice();
					return;
				}
				break;

			case WM_MOUSEWHEEL:
				scrollOffset += msg.wheel / 120 * 30; // 调整滚动速度

				if (scrollOffset > maxScroll) scrollOffset = maxScroll;
				if (scrollOffset < minScroll) scrollOffset = minScroll;
				break;
			}
		}
	}
}

void startmenu()
{
	ExMessage msg = { 0 };
	bool issignin = false;
	//背景
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	
	
	//按键
	int check = 1;
	while (check)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			//按钮
			BeginBatchDraw();
			//2048文字
			settextstyle(200, 0, "微软雅黑");
			setbkmode(TRANSPARENT);
			settextcolor(DARKGRAY);
			int hspace = (320 - textwidth("2048")) / 2;
			int vspace = (200 - textheight("2048")) / 2;
			outtextxy(200 + hspace, vspace, "2048");
			buttoncolor(150, 230, 150 + 420, 230 + 80, msg.x, msg.y, "开 始 游 戏");
			buttoncolor(150, 360, 150 + 420, 360 + 80, msg.x, msg.y, "游 戏 规 则");
			buttoncolor(150, 490, 150 + 420, 490 + 80, msg.x, msg.y, "按 键 说 明");
			buttoncolor(150, 620, 150 + 420, 620 + 80, msg.x, msg.y, "积 分 排 名");
			buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "退 出 游 戏");
			if (msg.x >= 20 && msg.x <= 20+60 && msg.y >= 10 && msg.y <= 10+40)
			{
				setfillcolor(RGB(125, 125, 125));
				solidrectangle(20, 10, 20 + 60, 10 + 30);
				settextstyle(30, 0, "微软雅黑");
				int hspace = (60 - textwidth("登录")) / 2;
				int vspace = (30 - textheight("登录")) / 2;
				outtextxy(20 + hspace, 10 + vspace, "登录");
			}
			else
			{
				setfillcolor(RGB(189, 172, 162));
				solidrectangle(20, 10, 20 + 60, 10 + 30);
				settextstyle(30, 0, "微软雅黑");
				int hspace = (60 - textwidth("登录")) / 2;
				int vspace = (30 - textheight("登录")) / 2;
				outtextxy(20 + hspace, 10 + vspace, "登录");
			}
			
			EndBatchDraw();




			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 230, 150 + 420, 230 + 80, msg.x, msg.y))//开始游戏
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
				if (button(150, 360, 150 + 420, 360 + 80, msg.x, msg.y))//游戏规则
				{
					secondmenu();

				}
				if (button(150, 490, 150 + 420, 490 + 80, msg.x, msg.y))//按键说明
				{
					cleardevice();
					thirdmenu();
				}
				if (button(150, 620, 150 + 420, 620 + 80, msg.x, msg.y))//积分排名
				{
					rankmenu();

				}
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//关闭游戏
				{
					closegraph();
					exit(0);
				}
				
					if (button(20, 10, 20 + 60, 10+ 30, msg.x, msg.y))//登录
					{
						if (!issignin)
						{
							signin();
						}

					}
				break;

			}
		}
		msg.message = { 0 };
	}
}