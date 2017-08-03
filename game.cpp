using namespace std;
#include "signal.h"
#include <fstream>
#include <vector>
#include "game.h"
#include <curses.h>
#include <windows.h>
void game()
{
	initscr();
	int level;
	level = 1;
	bool end_game = false;
	while (!end_game)
	{
		initscr();
		signal(level);
		clear();
		refresh();
		char* map_name;
		switch (level)
		{
		case 1:
			map_name = "map1.txt";
			break;
		case 2:
			map_name = "map2.txt";
			break;
		case 3:
			map_name = "map3.txt";
			break;
		default:
			break;
		}

		ifstream in(map_name);
		
		int map_information[4];
		int width, height;
		char find;

		in >> width;
		in >> height;

		in.ignore();
        //vector <vector<char>> map;
		//vector<char>map;


		char** map;

		map = new char*[width+1];//�ǵ�Ҫdelete��for(int i = 0; i < M; i ++)     delete[] a[i];		delete[]a;
		for (int i = 0; i < height; ++i)
		{
			map[i] = new char[height];
		}

	

		map_information[0] = width;
		map_information[1] = height;


// 		
		
		//��txt���������map����

		for (int i = 0; i < height; ++i) {
			in.getline(map[i], width + 1);
		}

		for (int i = 0; i < height; ++i) {
			mvprintw(0 + i, 0, map[i]);
		}
		int info = 2;
		refresh();
		//�ҵ����

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width+1; ++j)
			{
				if(map[i][j]==92)
				{
					map_information[info] = i;
					map_information[info + 1] = j;
				}
			}
		}



		show_map(map_information,map);
		

		//game start
		int UP[2];
		UP[0] = -1;
		UP[1] = 0;

		int	DOWN[2];
		DOWN[0] = 1;
		DOWN[1] = 0;

		int	LEFT[2];
		LEFT[0] = 0;
		LEFT[1] = -1;

		int	RIGHT[2];
		RIGHT[0] = 0;
		RIGHT[1] = 1;

		int x, y;
		int direction[2];

		direction[0] = UP[0];
		direction[1] = UP[1];

		//�����x,y����ʼλ�õ�����

		x = map_information[2] + direction[0];
		y = map_information[3] + direction[1];
		
		
		while (!end_game) {
			
			map[x][y] = '0';
			show_map(map_information, map);
			Sleep(1000);
			char ch=getch();
			switch (ch)
			{
			case KEY_UP:
				direction[0] = UP[0];
				direction[1] = UP[1];
				break;
			case KEY_DOWN:
				direction[0] = DOWN[0];
				direction[1] = DOWN[1];
				break;
			case KEY_LEFT:
				direction[0] = LEFT[0];
				direction[1] = LEFT[1];
				break;
			case KEY_RIGHT:
				direction[0] = RIGHT[0];
				direction[1] = RIGHT[1];
				break;
			default:
				break;
			}
			x = x + direction[0];
			y = y + direction[1];
			if (map[x][y] != '#')
			{
				end_game = true;
				end();
			}
		}

		

	}
	

	return;
}

void show_map(int map_information[4],char** map) {

	clear();
	refresh();
	move(0, 0);
	int width, height;
	width = map_information[0];
	height = map_information[1];

	for (int i = 0; i < height; ++i) {
		mvprintw(0+i,0,map[i]);
		
	}
	refresh();
}

void end() {
	initscr();
	clear();
	refresh();
	mvprintw(LINES / 2, (COLS - strlen("GAME OVER")) / 2, "GAME OVER");
	refresh();
}