#pragma once
#include <curses.h>
#include <string>
#include "welcome.h"
#include "game.h"
#include "signal.h"
#include <fstream>
#include <vector>


bool Solve(void);

void my_main(int a[9][9]);

inline bool CheckAll(int x, int y, int value);

inline bool CheckSmall(int x, int y, int value);

inline bool CheckCol(int y, int value);

inline bool CheckRow(int x, int value);

inline void GetABlank(int &x, int &y);
