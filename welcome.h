#pragma once
#include "curses.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "signal.h"
#include "welcome.h"
#include "curses.h"
#include "game.h"
#include "solve.h"

using namespace std;

void welcome();

void solve_game();

void about();

void game();

void add_number(vector<string>&shudu);