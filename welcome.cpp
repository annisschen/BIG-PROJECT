#include "welcome.h"


void welcome()
{
	clear();
	char *hello = "Do you have logic?";

// 	initscr();
// 	noecho();
// 	curs_set(FALSE);
	bool startbutton_on;

	attron(A_BOLD);
	mvprintw(LINES / 2 - 4, COLS / 2 - strlen(hello) / 2, "%s", hello);
	attroff(A_BOLD);
	attron(A_REVERSE);
	mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
	attroff(A_REVERSE);
	mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
	mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
	refresh();


	int ch;
	cbreak();
	noecho();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	bool start_game = true;
	bool game_solver = false;
	bool about_game = false;

	while (1) 
	{

		ch = getch();
		switch (ch)
		{
		case KEY_UP:
			if (start_game) 
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2+2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_NORMAL);
				refresh();
				start_game = false;
				game_solver = false;
				about_game = true;
			}
			else if(game_solver)
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_NORMAL);
				refresh();
				start_game = true;
				game_solver = false;
				about_game = false;
			}
			else if(about_game)
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_NORMAL);
				refresh();
				start_game = false;
				game_solver = true;
				about_game = false;
			}
			break;
		case KEY_DOWN:
			if (start_game) 
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_NORMAL);
				refresh();
				start_game = false;
				game_solver = true;
				about_game = false;
			}
			else if(game_solver)
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_NORMAL);
				refresh();
				start_game = false;
				game_solver = false;
				about_game = true;
			}
			else if (about_game)
			{
				attron(A_REVERSE);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start Game");
				attroff(A_REVERSE);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 4, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("GAME SOLVER") / 2, "%s", "Game Solver");
				attroff(A_NORMAL);
				refresh();
				start_game = true;
				game_solver = false;
				about_game = false;
			}
			break;
		case 10:
			if (start_game) 
			{
				game();
			}
			else if(game_solver)
			{
				
				int *g[16][16];
				solve_game();
				attron(A_REVERSE);
				mvprintw(20, COLS - strlen("Return"), "%s", "Return");
				attroff(A_REVERSE);
				int ch;
				while (1)
				{
					ch = getch();
					if (ch == 10)
					{
						welcome();
					}
					else
						break;
				}
			}
			else if (about_game) 
			{
				about();
			}
			break;
		}
	}

	endwin();
	return;
}
void solve_game() {
	initscr();
	clear();
	refresh();
	vector< string> shudu;

	shudu.resize(19);

	ifstream in("shudu moban.txt");
	//ifstream in("shudu1.txt");
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 37; ++j)
		{
			char a;
			in >> a;
			shudu[i] += a;
		}
	}

	show_shudu("shudu moban.txt", 0);
	//show_shudu("shudu1.txt",0);

	add_number(shudu);
	
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 37; ++j)
		{
			if ((shudu[i])[j] == '*')
			{
				(shudu[i])[j] = ' ';
			}
		}
	}

	char *line;
	line = new char[37];
	for (int i = 0; i < 19; ++i) {
		attron(A_REVERSE);
		strcpy(line, shudu[i].c_str());
		attroff(A_REVERSE);
	}
	
	clear();
	for (int i = 0; i < 19; ++i) {
		char* line;
		line = new char[37];
		strcpy(line, shudu[i].c_str());
		mvprintw(0 + i, 0, line);
	}
	refresh();
}

void about() 
{
	initscr();
	clear();
	char* ABOUT;
	ABOUT = "This is a logical game";
	mvprintw(LINES / 2 - 8, (COLS - strlen(ABOUT))/ 2 , ABOUT);
	attron(A_BOLD);
	mvprintw(LINES / 2 - 6, (COLS - strlen("game rules")) / 2, "game rules");
	attroff(A_BOLD);
	mvprintw(LINES / 2 - 4, COLS / 2 - 36, "1.Player is * .");
	mvprintw(LINES / 2 - 3, COLS / 2 - 36, "2.Entrance is \\ .");
	mvprintw(LINES / 2 - 2, COLS / 2 - 36, "3.There are four exits which are / .");
	mvprintw(LINES / 2 - 1, COLS / 2 - 36, "4.There are four keys which contain information about each exit.");
	mvprintw(LINES / 2 - 0, COLS / 2 - 36, "5.The level of each gate is different.");
	mvprintw(LINES / 2 - 0, COLS / 2 - 36, "6.You can use the keyboard up and down to control the shift of the characters.");



	int ch;
	cbreak();
	noecho();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	
	bool return_on = true;

	attron(A_REVERSE);
	mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
	attroff(A_REVERSE);


	while (1) 
	{
		ch = getch();
		
		if (ch == 10) {
			if (return_on)
			{
				welcome();
			}
		}
	}
}

void add_number(vector<string>&shudu)
{
	int question[9][9];
	int x = 1;
	int y = 2;
	move(x, y);
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(1);
	while (1)
	{
		int ch = getch();
		switch (ch)
		{
		case KEY_UP:
			if (x - 2 > 0)
			{
				x = x - 2;
				y = y;
			}
			break;

		case KEY_DOWN:
			if (x + 2 < 18)
			{
				x = x + 2;
				y = y;
			}
			break;

		case KEY_LEFT:
			if (y - 4 > 0)
			{
				x = x;
				y = y - 4;
			}
			break;

		case KEY_RIGHT:
			if (y + 4 < 36)
			{
				x = x;
				y = y + 4;
			}
			break;

		case '0':
			printw("0");
			shudu[x][y] = '0';
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
		{
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				int a;
				a = int(shudu[2 * i + 1][4 * j + 2] - '0');
				if (0 <= a && a < 10) {
					question[i][j] = a;
				}
				else
				{
					question[i][j] = 0;
				}
			}
		}
// 		int a[9][9];
// 		for (int i = 0; i < 9; ++i) {
// 			for (int j = 0; j < 9; ++j) {
// 				a[i][j] = question[i][j];
// 			}
// 		}
		my_main(question);

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				int m;
				m = question[i][j];
			}
		}

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				char a = question[i][j]+48;
				shudu[2 * i + 1][4 * j + 2] = a;
			}
		}
		char *line;
		line = new char[37];
		for (int i = 0; i < 19; ++i) {
			strcpy(line, shudu[i].c_str());
		}
		return;
		break; 
		}
		}
		move(x, y);
		refresh();
	}
}
