#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void gameover(int score, int step)
{
	ExMessage msg = { 0 };

	setfillcolor(RGB(189, 172, 162));
	fillrectangle(150, 300, 720 - 150, 300 + 300);
	settextstyle(30, 0, "΢���ź�");

	char scoreStr[20];
	sprintf(scoreStr, "%d", score);
	int hspace = (100 - textwidth(scoreStr)) / 2;
	int vspace = (50 - textheight(scoreStr)) / 2;
	outtextxy(350 + hspace, 320 + vspace, scoreStr);
	hspace = (100 - textwidth("���÷���")) / 2;
	vspace = (50 - textheight("���÷���")) / 2;
	outtextxy(225 + hspace, 320 + vspace, "���÷���");

	hspace = (100 - textwidth("���ò���")) / 2;
	vspace = (50 - textheight("���ò���")) / 2;
	outtextxy(225 + hspace, 370 + vspace, "���ò���");
	char stepStr[20];
	sprintf(stepStr, "%d", step);
	hspace = (100 - textwidth(stepStr)) / 2;
	vspace = (50 - textheight(stepStr)) / 2;
	outtextxy(350 + hspace, 370 + vspace, stepStr);
	hspace = (100 - textwidth("����ʱ��")) / 2;
	vspace = (50 - textheight("����ʱ��")) / 2;
	outtextxy(225 + hspace, 420 + vspace, "����ʱ��");
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
			settextstyle(40, 0, "΢���ź�");
			int hspace = (220 - textwidth("ȷ  ��")) / 2;
			int vspace = (50 - textheight("ȷ  ��")) / 2;
			outtextxy(250 + hspace, 500 + vspace, "ȷ  ��");
		}
		else
		{
			setfillcolor(RGB(209, 191, 182));
			solidrectangle(250, 500, 720 - 250, 500 + 50);
			settextstyle(40, 0, "΢���ź�");
			int hspace = (220 - textwidth("ȷ  ��")) / 2;
			int vspace = (50 - textheight("ȷ  ��")) / 2;
			outtextxy(250 + hspace, 500 + vspace, "ȷ  ��");
		}
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(250, 500, 250 + 220, 500 + 50, msg.x, msg.y))//ȷ��
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
		sprintf(str, "%d", num);  // ����ת�ַ���
	}
	else
	{
		str[0] = '\0';  // 0 ʱ����ʾ����
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
		settextstyle(size, 0, "΢���ź�");
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
	//����������
	setbkcolor(RGB(254, 246, 238));
	cleardevice();
	setfillcolor(RGB(189, 172, 162));
	solidroundrect(100, 320, 100 + 520, 320 + 520, 50, 50);
	//2048����
	settextstyle(100, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	int hspace = (250 - textwidth("2048")) / 2;
	int vspace = (200 - textheight("2048")) / 2;
	outtextxy(110 + hspace, 60 + vspace, "2048");
	//������
	setfillcolor(RGB(189, 172, 162));

	solidroundrect(340, 100, 340 + 100, 100 + 100, 10, 10);
	setfillcolor(RGB(189, 172, 162));
	solidroundrect(450, 100, 450 + 100, 100 + 100, 10, 10);
	settextstyle(40, 0, "΢���ź�");
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
	//ʱ��
	hspace = (100 - textwidth("00:00:00")) / 2;
	vspace = (100 - textheight("00:00:00")) / 2;
	settextstyle(30, 0, "΢���ź�");
	outtextxy(325 + hspace, 200 + vspace, "00:00:00");
	//���� ��ͣ ����

	settextstyle(35, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	outtextxy(310, 280, "��");
	settextstyle(30, 0, "΢���ź�");
	settextcolor(DARKGRAY);
	outtextxy(350, 280, "||");
	settextstyle(40, 0, "΢���ź�");
	outtextxy(380, 275, "��");
	settextstyle(40, 0, "΢���ź�");
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
	//����
	int backStack[3][4][4];  
	int backScores[3];       
	int backSteps[3];        
	int backTop = -1;        // -1��ʾ��

	//����������
	int score = 0;
	int step = 0;
	
	//��������ɫ��������ʾ
	//����2�������
	generateRandomTile(board);
	generateRandomTile(board);
	updatedisplay(score, board);
	int checktime = 1000000;
	int check = 1;
	while (1)//��Ϸ������
	{
		if (checktime)
		{
			checktime--;
		}
		else
		{
			printf("���\n");

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
				gameover(score, step);//������Ϸ
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
				if (button(310, 280, 340, 310, msg.x, msg.y))//����
				{
					if (backTop >= 0) // �������ʷ��¼
					{
						printf("�ڲ�\n");

						// �ָ�����
						memcpy(board, backStack[backTop], sizeof(int) * 4 * 4);
						score = backScores[backTop];
						step = backSteps[backTop];

						// ������ʾ
						updatedisplay(score, board);
						backTop--; // ջ��ָ�����
					}
					else
					{
						printf("�޷����壬û����ʷ��¼\n");
					}
				}
				if (button(340, 280, 370, 310, msg.x, msg.y))//��ͣ
				{
					printf("��ͣ\n", msg.x, msg.y);

				}
				if (button(370, 280, 400, 310, msg.x, msg.y))//����
				{
					gameover(score, step);//������Ϸ
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
	settextstyle(60, 0, "΢���ź�");
	int hspace = (420 - textwidth(str)) / 2;
	int vspace = (80 - textheight(str)) / 2;
	outtextxy(150 + hspace, y + vspace, str);

}
void ruleshow(int y, const char str[])
{
	setfillcolor(RGB(189, 172, 162));
	solidrectangle(50, y, 50 + 620, y + 80);
	settextstyle(30, 0, "΢���ź�");
	int hspace = (520 - textwidth(str)) / 2;
	int vspace = (80 - textheight(str)) / 2;
	outtextxy(100 + hspace, y + vspace, str);
}
void secondmenu()
{
	ExMessage msg = { 0 };

	cleardevice();

	ruleshow(100, "Ŀ�꣺ͨ���ϲ���ͬ���ֵķ��飬���յõ�һ��2048�ķ��顣");

	ruleshow(200, "�ƶ�������ҿ���ͨ�����������ĸ����򻬶�");
	ruleshow(260, "�������ַ�����򻬶��ķ���£");

	ruleshow(360, "�ϲ�������ͬ���ֵķ����ڿ�£ʱ�����");
	ruleshow(420, "�����γ�һ���µķ��顣");


	ruleshow(520, "���ɹ���ÿ�λ����󣬿հ״����������һ��1��2�ķ��顣");
	ruleshow(620, "ʧ��������������и��Ӷ�������û�����ڵ���ͬ���ַ��顣");
	while (1)
	{
		BeginBatchDraw();

		buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "ȷ  ��");
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//ȷ��
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

	//������
	settextstyle(50, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	setfillcolor(RGB(189, 172, 162));
	solidrectangle(150, 50, 150 + 150, 50 + 150);
	outtextxy(215, 50, "��");
	outtextxy(215, 150, "��");
	outtextxy(160, 100, "��");
	outtextxy(250, 100, "��");
	solidrectangle(150, 220, 150 + 150, 220 + 150);
	int hspace = (150 - textwidth("��")) / 2;
	int vspace = (150 - textheight("��")) / 2;
	settextstyle(100, 0, "΢���ź�");
	outtextxy(130 + hspace, 200 + vspace, "��");
	solidrectangle(150, 390, 150 + 150, 390 + 150);
	hspace = (150 - textwidth("||")) / 2;
	vspace = (150 - textheight("||")) / 2;
	outtextxy(150 + hspace, 390 + vspace, "||");
	solidrectangle(150, 560, 150 + 150, 560 + 150);
	hspace = (150 - textwidth("��")) / 2;
	vspace = (150 - textheight("��")) / 2;
	outtextxy(150 + hspace, 560 + vspace, "��");
	//�Ҳ�����
	settextstyle(40, 0, "΢���ź�");

	solidrectangle(350, 100, 350 + 250, 100 + 50);
	hspace = (250 - textwidth("���������ƶ�����")) / 2;
	vspace = (50 - textheight("���������ƶ�����")) / 2;
	outtextxy(350 + hspace, 100 + vspace, "���������ƶ�����");
	solidrectangle(350, 270, 350 + 250, 270 + 50);
	hspace = (250 - textwidth("����һ��")) / 2;
	vspace = (50 - textheight("����һ��")) / 2;
	outtextxy(350 + hspace, 270 + vspace, "����һ��");
	solidrectangle(350, 440, 350 + 250, 440 + 50);
	hspace = (250 - textwidth("��ͣ��ʱ")) / 2;
	vspace = (50 - textheight("��ͣ��ʱ")) / 2;
	outtextxy(350 + hspace, 440 + vspace, "��ͣ��ʱ");
	solidrectangle(350, 610, 350 + 250, 610 + 50);
	hspace = (250 - textwidth("������Ϸ")) / 2;
	vspace = (50 - textheight("������Ϸ")) / 2;
	outtextxy(350 + hspace, 610 + vspace, "������Ϸ");
	//����

	while (1)
	{
		BeginBatchDraw();
		buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "ȷ  ��");
		EndBatchDraw();

		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//ȷ��
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
	settextstyle(200, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(DARKGRAY);
	int hspace = (720 - textwidth("2048")) / 2;
	outtextxy(hspace, offsetY, "2048");
	setfillcolor(RGB(189, 172, 162));
	settextstyle(30, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	solidrectangle((720 - 600) / 2, 200 + offsetY, (720 - 600) / 2 + 600, 200 + offsetY + 60);

	char yourtext[300];
	sprintf(yourtext, "���ķ���Ϊ:%d	��������Ϊ:%d", 114514,1);//��������
	int textWidth = textwidth(yourtext);
	int textHeight = textheight(yourtext);
	outtextxy((720 - textWidth) / 2, 200 + offsetY + (60 - textHeight) / 2, yourtext);
	int startY = 150 + 200 + offsetY;

	for (int i = 0; i < BOX_COUNT; i++) 
	{
		solidrectangle((720 - 600) / 2, startY + i * 70, (720 - 600) / 2 + 600, startY + i * 70 + 60);

		char text[300];
		sprintf(text, "%s�ķ���Ϊ:%d    %s������Ϊ:%d", "man", i + 1, "man", i + 1);
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

	settextstyle(40, 0, "΢���ź�");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	const char* title = "�û���¼";
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
		settextstyle(200, 0, "΢���ź�");
		setbkmode(TRANSPARENT);
		settextcolor(DARKGRAY);
		//����
		int hspace = (320 - textwidth("2048")) / 2;
		int vspace = (200 - textheight("2048")) / 2;
		outtextxy(200 + hspace, vspace, "2048");
		startbuttonshow(230, "�� ʼ �� Ϸ", 189, 172, 162);
		startbuttonshow(360, "�� Ϸ �� ��", 189, 172, 162);
		startbuttonshow(490, "�� �� ˵ ��", 189, 172, 162);
		startbuttonshow(620, "�� �� �� ��", 189, 172, 162);
		startbuttonshow(750, "�� �� �� Ϸ", 189, 172, 162);
		setfillcolor(RGB(189 * 0.9, 172 * 0.9, 162 * 0.9));
		solidrectangle(loginX, loginY, loginX + 500, loginY + 350);

		settextstyle(40, 0, "΢���ź�");
		outtextxy(loginX + (500 - textwidth(title)) / 2, loginY + 30, title);

		settextstyle(30, 0, "΢���ź�");
		outtextxy(loginX + 50, loginY + 70, "�˺�:");
		outtextxy(loginX + 50, loginY + 150, "����:");

		setfillcolor(RGB(240, 240, 240));
		solidrectangle(loginX + 50, loginY + 100, loginX + 50 + 500 - 100, loginY + 100 + 50);
		rectangle(loginX + 50, loginY + 100, loginX + 50 + 500 - 100, loginY + 100 + 50);

		setfillcolor(RGB(240, 240, 240));
		solidrectangle(loginX + 50, loginY + 180, loginX + 50 + 500 - 100, loginY + 180 + 50);
		rectangle(loginX + 50, loginY + 180, loginX + 50 + 500 - 100, loginY + 180 + 50);
		//��ʾ

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
			settextstyle(30, 0, "΢���ź�");
			int hspace = (180  - textwidth("��¼")) / 2;
			int vspace = (60 - textheight("��¼")) / 2;
			outtextxy(loginX + 50 + hspace, loginY + 250 + vspace, "��¼");
		}
		else
		{
			setfillcolor(RGB(189, 172, 162));
			solidrectangle(loginX + 50, loginY + 250, loginX + 50 + 180, loginY + 310);
			settextstyle(30, 0, "΢���ź�");
			int hspace = (180 - textwidth("��¼")) / 2;
			int vspace = (60 - textheight("��¼")) / 2;
			outtextxy(loginX + 50 + hspace, loginY + 250 + vspace, "��¼");
		}

		if (msg.x >= loginX + 50 + 220 && msg.x <= loginX  +50 + 220 + 180 && msg.y >= loginY + 250 && msg.y <= loginY + 310)
		{
			setfillcolor(RGB(125, 125, 125));
			solidrectangle(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310);
			settextstyle(30, 0, "΢���ź�");
			int hspace = (180 - textwidth("ע��")) / 2;
			int vspace = (60 - textheight("ע��")) / 2;
			outtextxy(loginX + 50 + 220 + hspace, loginY + 250 + vspace, "ע��");
		}
		else
		{
			setfillcolor(RGB(189, 172, 162));
			solidrectangle(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310);
			settextstyle(30, 0, "΢���ź�");
			int hspace = (180 - textwidth("ע��")) / 2;
			int vspace = (60 - textheight("ע��")) / 2;
			outtextxy(loginX + 50 + 220 + hspace, loginY + 250 + vspace, "ע��");
		}


		outtextxy(loginX + 470, loginY, "X");
		EndBatchDraw();

		while (peekmessage(&msg)) 
		{
			switch (msg.message) 
			{
			case WM_LBUTTONDOWN:
				// ����Ƿ����������
				namein = button(loginX + 50, loginY + 100,loginX + 50 + 500 - 100,loginY + 100 + 50,msg.x, msg.y);
				wordin = button(loginX + 50, loginY + 180,loginX + 50 + 500 - 100,loginY + 180 + 50,msg.x, msg.y);
				if (button(loginX + 50, loginY + 250, loginX + 50 + 180, loginY + 310, msg.x, msg.y))
				{
					running = false;//ȷ������
					cleardevice();

				}
				if (button(loginX + 50 + 220, loginY + 250, loginX + 50 + 220 + 180, loginY + 310, msg.x, msg.y))
				{
					running = false;//ע��
					cleardevice();

				}
				if (button(loginX + 470, loginY, loginX + 500, loginY + 30, msg.x, msg.y))
				{
					cleardevice();

					running = false;//ע��
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
					}//ɾ��
					else if (msg.vkcode >= 32 && msg.vkcode <= 126 && nametext.length() <= 20) 
					{ 
						nametext += (char)msg.vkcode;
					}//����
				}
				else if (wordin) 
				{
					if (msg.vkcode == '\b') 
					{ 
						if (!passtext.empty()) {
							passtext.pop_back();
						}
					}//ɾ��
					else if (msg.vkcode >= 32 && msg.vkcode <= 126 && passtext.length() <= 20) 
					{ 
						passtext += (char)msg.vkcode;
					}//����
				}
				break;
			}
		}
	}

}
void rankmenu() 
{
	ExMessage msg = { 0 };
	int scrollOffset = 0; // ����ƫ����
	const int maxScroll = 0; // ��������
	const int minScroll = -(150 + BOX_COUNT * 70 - (720 - 350)); // ��С������

	cleardevice();
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	int hspace = 0;

	while (1) 
	{
		BeginBatchDraw();
		cleardevice();
		drawBoxes(scrollOffset);
		buttoncolor((720 - 420) / 2, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 150, (720 - 420) / 2 + 420, 150 + 200 + scrollOffset + BOX_COUNT * 70 + 300, msg.x, msg.y, "ȷ  ��");
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
				scrollOffset += msg.wheel / 120 * 30; // ���������ٶ�

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
	//����
	setbkcolor(RGB(254, 246, 238));
	cleardevice();

	
	
	//����
	int check = 1;
	while (check)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			//��ť
			BeginBatchDraw();
			//2048����
			settextstyle(200, 0, "΢���ź�");
			setbkmode(TRANSPARENT);
			settextcolor(DARKGRAY);
			int hspace = (320 - textwidth("2048")) / 2;
			int vspace = (200 - textheight("2048")) / 2;
			outtextxy(200 + hspace, vspace, "2048");
			buttoncolor(150, 230, 150 + 420, 230 + 80, msg.x, msg.y, "�� ʼ �� Ϸ");
			buttoncolor(150, 360, 150 + 420, 360 + 80, msg.x, msg.y, "�� Ϸ �� ��");
			buttoncolor(150, 490, 150 + 420, 490 + 80, msg.x, msg.y, "�� �� ˵ ��");
			buttoncolor(150, 620, 150 + 420, 620 + 80, msg.x, msg.y, "�� �� �� ��");
			buttoncolor(150, 750, 150 + 420, 750 + 80, msg.x, msg.y, "�� �� �� Ϸ");
			if (msg.x >= 20 && msg.x <= 20+60 && msg.y >= 10 && msg.y <= 10+40)
			{
				setfillcolor(RGB(125, 125, 125));
				solidrectangle(20, 10, 20 + 60, 10 + 30);
				settextstyle(30, 0, "΢���ź�");
				int hspace = (60 - textwidth("��¼")) / 2;
				int vspace = (30 - textheight("��¼")) / 2;
				outtextxy(20 + hspace, 10 + vspace, "��¼");
			}
			else
			{
				setfillcolor(RGB(189, 172, 162));
				solidrectangle(20, 10, 20 + 60, 10 + 30);
				settextstyle(30, 0, "΢���ź�");
				int hspace = (60 - textwidth("��¼")) / 2;
				int vspace = (30 - textheight("��¼")) / 2;
				outtextxy(20 + hspace, 10 + vspace, "��¼");
			}
			
			EndBatchDraw();




			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (button(150, 230, 150 + 420, 230 + 80, msg.x, msg.y))//��ʼ��Ϸ
				{
					printf("��ʼ��Ϸ\n", msg.x, msg.y);
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
				if (button(150, 360, 150 + 420, 360 + 80, msg.x, msg.y))//��Ϸ����
				{
					secondmenu();

				}
				if (button(150, 490, 150 + 420, 490 + 80, msg.x, msg.y))//����˵��
				{
					cleardevice();
					thirdmenu();
				}
				if (button(150, 620, 150 + 420, 620 + 80, msg.x, msg.y))//��������
				{
					rankmenu();

				}
				if (button(150, 750, 150 + 420, 750 + 80, msg.x, msg.y))//�ر���Ϸ
				{
					closegraph();
					exit(0);
				}
				
					if (button(20, 10, 20 + 60, 10+ 30, msg.x, msg.y))//��¼
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