#pragma once
#include <curses.h>
#include <string>
#include "welcome.h"
#include "game.h"
#include <fstream>
#include <vector>


// #define UP {-1,0}	
// #define DOWN {1,0}	
// #define LEFT {0,-1}	
// #define RIGHT {0,1}	
void game();

void show_map(int[4] , vector<string>);

void endgame();
