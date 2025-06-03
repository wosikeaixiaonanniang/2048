#pragma once
#include "header.h"
#include "gamecore.h"
class GameUI : public GameCore ,public Time
{
protected:
	string playername = "name";
	bool issignin = false;
	int BOX_COUNT = 10;
public:
	void showerror(const char str[]);
	void gameover(int score, int step, GameTimer timer);
	bool button(int x1, int y1, int x2, int y2, int msgx, int msgy);
	void buttoncolor(int x1, int y1, int x2, int y2, int msgx, int msgy, const char str[]);
	void givecolor(int num, int x, int y);
	void updatedisplay(int score, int board[4][4], GameTimer timer);
	void gamemenu(int board[4][4], bool issignin);
	void startbuttonshow(int y, const char str[], int a, int b, int c);
	void ruleshow(int y, const char str[]);
	void signin();
	virtual void showmenu();
	void registerUser(string name, string password);
	bool checkUser(string name, string password);
};
class RankUI : public GameUI
{
public:
	void drawBoxes(int offsetY, string name, bool issignin);

	RankUI(string playername, bool issignin, int boxcount)
	{
		this->playername = playername;
		this->issignin = issignin;
		this->BOX_COUNT = boxcount;
	}
	void showmenu();
};
class RuleUI : public GameUI
{
public:
	void showmenu();
};
class ControlUI : public GameUI
{
public:
	void showmenu();
};
