using namespace std;
#include "signal.h"
#include <fstream>
#include <vector>
#include "game.h"
#include <curses.h>
#include <windows.h>


//****************************************开始游戏**********************************
//1.人物是 * 
//2.开始的门是 / 
//3.结束的门是 \ 
//4.钥匙是 1 ，2，3，4 
//5.题目来自于 数独 
//6.每一个门对应一个题目，有难度区分



void game()
{
	initscr();
	int level;
	level = 1;

	//退出游戏的判断
	
	bool end_game = false;
	
	//初始化一个和map信息有关的数组，来存放信息

	int map_information[4];

	//初始化一个数组来存放map

	vector<string> map;
	
	//游戏判断

	while (!end_game)
	{
		initscr();
		//signal(level);
		clear();
		refresh();

		//这是一个读取map地图的数组

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

		while (!in.bad())
		{

			int width, height;

			in >> width;
			in >> height;

			in.ignore();

			map_information[0] = width;
			map_information[1] = height;


			map.resize(height);
			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j)
				{
					char a;
					in >> a;
					//cout << a;
					map[i] += a;
				}
			}

			// 			for (int i = 0; i < height; ++i) {
			// 				cout << map[i] << endl;
			// 			}

			// 		for (int i = 0; i < height; ++i) {
			// 			mvprintw(0 + i, 0, map[i]);
			// 		}
			// 		refresh();
			//找到入口


			int info = 2;
			for (int i = 0; i < height; ++i) {
				string a;
				a = map[i];
				for (int j = 0; j < width; ++j)
				{
					if (a[j] == 92)  // 92==
					{
						map_information[info] = i;
						map_information[info + 1] = j;
					}
				}
			}

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

			//下面的x,y是起始位置的坐标

			x = map_information[2] + direction[0];
			y = map_information[3] + direction[1];


			//cout << KEY_UP << "  " << KEY_DOWN << "  " << KEY_LEFT << "  " << KEY_RIGHT;

			while (!end_game) {

				(map[x])[y] = '*';

				show_map(map_information, map);
				
				keypad(stdscr, TRUE);
				cbreak();
				noecho();
				int ch = getch();

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

				(map[x])[y] = ' ';
				x = x + direction[0];
				y = y + direction[1];

				switch (map[x][y])
				{
				case '#':
					end_game = true;
					endgame();
					break;
				case '1':
					showkey1();
					break;
				case '2':
					showkey2();
					break;
				case '3':
					showkey3();
					break;
				case '4':
					showkey4();
					break;
				case '/':
					gate(x,y,width,height);
				default:
					break;
				};
			}

		}
		return;
	}
}



void show_map(int map_information[4], vector<string> map) {

	clear();
	refresh();
	move(0, 0);
	int width, height;
	width = map_information[0];
	height = map_information[1];


	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if ((map[i])[j] == '0') {
				(map[i])[j] = ' ';
			}
		}
	}

	for (int i = 0; i < height; ++i) {
		char* line;
		line = new char[width];
		strcpy(line, map[i].c_str());
		mvprintw(0 + i, 0, line);
	}
	refresh();
}



void endgame() {
	initscr();
	clear();
	refresh();
	mvprintw(LINES / 2, (COLS - strlen("GAME OVER")) / 2, "GAME OVER");
	attron(A_BOLD);
	mvprintw(LINES - 1, (COLS - strlen("return")), "return");
	attroff(A_BOLD);
	refresh();
	while (1) {
		char ch;
		ch = getch();
		switch (ch)
		{
		case 10:
			welcome();
		default:
			break;
		}
	}
	
}



void showkey1() {
	initscr();
	clear();
	mvprintw(LINES / 2, (COLS - strlen("The above gate is not the hardest one.")) / 2, "The above gate is not the hardest one.");
	refresh();
	char ch;
	
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 10:
			return;
		default:
			break;
		}
	}
}


void showkey2() {
	initscr();
	clear();
	mvprintw(LINES / 2, (COLS - strlen("The above gate is the harder than the left one.")) / 2, "The above gate is the harder than left the one.");
	refresh();
	char ch;
	
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 10:
			return;
		default:
			break;
		}
	}
}


void showkey3() {
	initscr();
	clear();
	mvprintw(LINES / 2, (COLS - strlen("The below gate is easier than the above one.")) / 2, "The below gate is easier than the above one.");
	refresh();
	char ch;
	
	while (1)
	{
		ch = getch(); 
		switch (ch)
		{
		case 10:
			return;
		default:
			break;
		}
	}
	
}



void showkey4() {
	initscr();
	clear();
	mvprintw(LINES / 2, (COLS - strlen("The left gate is harder than the below one.")) / 2, "The left gate is harder than the below one.");
	refresh();
	char ch;
	
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 10:
			return;
		default:
			break;
		}
	}
}



void gate(int x,int y,int width,int height) {
	if (x == 0 ) {//上
		shudu(3);
	}
	if (x == height-1) {//下
		shudu(2);
	}
	if (y==0)//zuo
	{
		shudu(1);
	}
	if (y == width-1) {//you
		shudu(4);
	}
}


void shudu(int level) {
	string shudu_name;

	switch (level)
	{
	case 1:

		shudu_name = "shudu1.txt";
		show_shudu(shudu_name,level);
		break;

	case 2:

		shudu_name = "shudu2.txt";
		show_shudu(shudu_name, level);
		break;

	case 3:

		shudu_name = "shudu3.txt";
		show_shudu(shudu_name, level);
		break;

	case 4:

		shudu_name = "shudu4.txt";
		show_shudu(shudu_name, level);
		break;

	default:
		break;
	}
}


void show_shudu(string shudu_name,int level) {

	initscr();
	clear();

	ifstream in(shudu_name);

	vector< string> shudu;

	shudu.resize(19);

	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 37; ++j)
		{
			char a;
			in >> a;
			shudu[i] += a;
		}
	}

	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 37; ++j) {
			if ((shudu[i])[j] == '*') {
				(shudu[i])[j] = ' ';
			}
		}
	}
	for (int i = 0; i < 19; ++i) {
		char* line;
		line = new char[37];
		
		strcpy(line, shudu[i].c_str());
		attron(A_BOLD);
		mvprintw(0 + i, 0, line);
		attroff(A_BOLD);
	}
	refresh();
	sovle_shudu(shudu_name,shudu,level);
}



void sovle_shudu(string shudu_name,vector<string>shudu,int level) {
	int x = 1;
	int y = 2;
	move(x, y);
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(1);
	while (1) {
		int ch = getch();

		switch (ch)
		{
		case KEY_UP:

			if (x - 2 > 0) {
				x = x - 2;
				y = y;
			}
			break;

		case KEY_DOWN:

			if (x + 2 < 18) {
				x = x + 2;
				y = y;
			}
			break;

		case KEY_LEFT:

			if (y - 4 > 0) {
				x = x;
				y = y - 4;
			}
			break;

		case KEY_RIGHT:

			if (y + 4 < 36) {
				x = x;
				y = y + 4;
			}
			break;

		case '1':
			printw("1");
			
			shudu[x][y] = '1';
			break;

		case '2':
			printw("2");
			
			shudu[x][y] = '2';
			break;

		case '3':
			printw("3");
			
			shudu[x][y] = '3';
			break;

		case '4':
			printw("4");
			
			shudu[x][y] = '4';
			break;

		case '5':
			printw("5");
		
			shudu[x][y] = '5';
			break;

		case '6':
			printw("6");
			
			shudu[x][y] = '6';
			break;

		case '7':

			printw("7");
		
			shudu[x][y] = '7';
			break;

		case '8':

			printw("8");
			
			shudu[x][y] = '8';
			break;

		case '9':

			printw("9");
			shudu[x][y] = '9';
			break;

		case 10:

			if (compare(shudu, level)) {
				vectory();
			}
			else {
				endgame();
			}

		default:
			x = x;
			y = y;
			break;
		}

		move(x, y);

		refresh();
	}
}


bool compare(vector<string>shudu,int level) {
	string shudu_answer_name;
	switch (level)
	{
	case 1:
		shudu_answer_name = "shudu1 answer.txt";
		break;
	case 2:
		shudu_answer_name = "shudu2 answer.txt";
		break;
	case 3:
		shudu_answer_name = "shudu3 answer.txt";
		break;
	case 4:
		shudu_answer_name = "shudu4 answer.txt";
		break;
	default:
		break;
	}
	ifstream in(shudu_answer_name);
	int shudu_answer[9][9];
	int player_answer[9][9];
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			in >> shudu_answer[i][j];
		}
	}

	clear();
	refresh();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << shudu_answer[i][j] << " \n"[j == 8];
		}
	}

	int m = 0;

	for (int i = 1 ; i < 18;  m++) {
		int n = 0;
		for (int j = 2 ; j < 36;  ++n) {
			if (shudu[i][j] == ' ') {
				shudu[i][j] = '0';
			}
			player_answer[m][n] = shudu[i][j] - '0';
			j += 4;
		}
		i += 2;
	}

	clear();
	refresh();
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << player_answer[i][j] << " \n"[j == 8];
		}
	}

	int a = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (!(player_answer[i][j] == shudu_answer[i][j])) {
				return false;
			}
		}
	}
	return true;
}


void vectory() {
	initscr();
	clear();
	refresh();

	mvprintw(LINES / 2, (COLS - strlen("VECTORY")) / 2, "VECTORY");

	attron(A_BOLD);
	mvprintw(LINES - 1, (COLS - strlen("return")), "return");
	attroff(A_BOLD);
	refresh();

	while (1) {
		char ch;
		ch = getch();
		switch (ch)
		{
		case 10:
			welcome();
		default:
			break;
		}
	}
}