#include <iostream>
#include "solve.h"

int g[16][16];
inline void GetABlank(int &x, int &y)
{
	x = y = -1;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			if (g[i][j] == 0)
			{
				x = i, y = j;
				break;
			}
}
inline bool CheckRow(int x, int value)
{
	for (int i = 1; i <= 9; ++i)
		if (g[x][i] == value)
			return false;
	return true;
}
inline bool CheckCol(int y, int value)
{
	for (int i = 1; i <= 9; ++i)
		if (g[i][y] == value)
			return false;
	return true;
}
inline bool CheckSmall(int x, int y, int value)
{
	int xs = (x - 1) / 3 * 3 + 1;
	int xt = ((x - 1) / 3 + 1) * 3;
	int ys = (y - 1) / 3 * 3 + 1;
	int yt = ((y - 1) / 3 + 1) * 3;
	for (int i = xs; i <= xt; ++i)
		for (int j = ys; j <= yt; ++j)
			if (g[i][j] == value)
				return false;
	return true;
}
inline bool CheckAll(int x, int y, int value)
{
	return CheckRow(x, value)
		&& CheckCol(y, value)
		&& CheckSmall(x, y, value);
}
bool Solve(void)
{
	int i, j;
	GetABlank(i, j);
	if (i == -1 && j == -1)
		return true;
	for (int k = 1; k <= 9; ++k)
	{
		if (CheckAll(i, j, k))
		{
			g[i][j] = k;
			if (!Solve())
				g[i][j] = 0;
			else
				return true;
		}
	}
	return false;
}
void my_main(int a[9][9])
{
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			g[i][j] = a[i - 1][j - 1];

	if (Solve()) {
		for (int i = 1; i <= 9; ++i)
			for (int j = 1; j <= 9; ++j)
			{
				 a[i-1][j-1] = g[i][j];
			}
	}
		
}