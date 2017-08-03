#pragma once
#include "curses.h"
#include <iostream>
#include <string>

using namespace std;

void welcome();

void about();

void mykeyprogram();

void GetABlank(int & x, int & y);

bool CheckRow(int x, int value);

bool CheckCol(int y, int value);

bool CheckSmall(int x, int y, int value);

bool CheckAll(int x, int y, int value);

bool Solve(void);

void game();
