#pragma once
#include <curses.h>
#include <string>
#include "welcome.h"
#include "game.h"
#include "signal.h"
#include <fstream>
#include <vector>



void game();

void show_map(int[4], vector<string>);

void endgame();

void showkey1();

void showkey2();

void showkey3();

void showkey4();

void gate(int, int,int ,int);

void shudu(int);

void show_shudu(string,int);

void sovle_shudu(string shudu_name,vector< string>,int);

bool compare(vector<string> shudu, int level);

void vectory();

void get_a_shudu(vector<string>);

