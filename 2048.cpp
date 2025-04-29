#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
#include <iostream>
using namespace std;
int main()
{
	int board[row][col];
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			board[i][j] = 0;
		}
	}
	return 0;
}
