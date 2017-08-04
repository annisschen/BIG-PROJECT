#include "welcome.h"
#include "curses.h"
#include "game.h"

void welcome()
{
	clear();
	char *hello = "Do you have logic?";

// 	initscr();
// 	noecho();
// 	curs_set(FALSE);
	bool startbutton_on;

	attron(A_BLINK);
	mvprintw(LINES / 2 - 4, COLS / 2 - strlen(hello) / 2, "%s", hello);
	attroff(A_BLINK);
	attron(A_BOLD);
	mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
	attroff(A_BOLD);
	mvprintw(LINES / 2 + 2, COLS / 2 - strlen("About") / 2, "%s", "About");
	refresh();
	startbutton_on = true;

	int ch;
	cbreak();
	noecho();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	bool start_game = false;
	while (!start_game) {

		ch = getch();
		switch (ch)
		{
		case KEY_UP:
			if (startbutton_on) {
				attron(A_BOLD);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_BOLD);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
				attroff(A_NORMAL);
				refresh();
				startbutton_on = false;
			}
			else {
				attron(A_BOLD);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
				attroff(A_BOLD);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				refresh();
				startbutton_on = true;
			}
			break;
		case KEY_DOWN:
			if (startbutton_on) {
				attron(A_BOLD);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_BOLD);
				attron(A_NORMAL);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
				attroff(A_NORMAL);
				refresh();
				startbutton_on = false;
			}
			else {
				attron(A_BOLD);
				mvprintw(LINES / 2, COLS / 2 - strlen("START GAME") / 2, "%s", "Start game");
				attroff(A_BOLD);
				attron(A_NORMAL);
				mvprintw(LINES / 2 + 2, COLS / 2 - strlen("About") / 2, "%s", "About");
				attroff(A_NORMAL);
				refresh();
				startbutton_on = true;
			}
			break;
		case 10:
			if (startbutton_on) {
				start_game = true;
				game();
			}
			else {
				about();
			}
			break;
		}
	}

	endwin();
	return;
}


void about() {
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

	attron(A_BOLD);
	mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
	attroff(A_BOLD);
	mvprintw(LINES - 1, COLS - strlen("GAME SOVLER"), "GAME SOVER");


	while (1) {
		ch = getch();
		switch (ch)
		{
		case KEY_UP:
			if (return_on) {
				attron(A_BOLD);
				mvprintw(LINES - 1, COLS - strlen("GAME SOVLER"), "GAME SOVER");
				attroff(A_BOLD);
				mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
				refresh();
				return_on = false;
			}
			else {
				
				mvprintw(LINES - 1, COLS - strlen("GAME SOVLER"), "GAME SOVER");
				attron(A_BOLD);
				mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
				attroff(A_BOLD);
				refresh();
				return_on = true;
			}
			break;
		case KEY_DOWN:
			if (return_on) {
				attron(A_BOLD);
				mvprintw(LINES - 1, COLS - strlen("GAME SOVLER"), "GAME SOVER");
				attroff(A_BOLD);
				mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
				refresh();
				return_on = false;
			}
			else {

				mvprintw(LINES - 1, COLS - strlen("GAME SOVLER"), "GAME SOVER");
				attron(A_BOLD);
				mvprintw(LINES - 2, COLS - strlen("RETURN") - 5, "RETURN");
				attroff(A_BOLD);
				refresh();
				return_on = true;
			}
			break;
		case 10:
			if (return_on) {
				welcome();
			}
			else {
				clear();

				refresh();
				mykeyprogram();
				while (1)
				{
					ch = getch();
					if (ch == 10) {
						welcome();
					}
				}
			}
			break;
		default:
			break;
		}
		

	}

}

 int g[16][16];
void mykeyprogram() {
	initscr();
	clear();
	mvprintw(5, COLS / 2 - strlen("This is a progam which can solve Sudoku.Please enter your Sudoku below."), "This is a progam which can solve Sudoku.Please enter your Sudoku below.");
	mvprintw(6, COLS / 2 - strlen("0 take the place of space"), "0 take the place of space");
	mvprintw(20, COLS / 2 - strlen("enter your Sudoku below"), "enter your Sudoku below");
	refresh();

	endwin();

	cout << "please enter the Sudoku" << endl;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			std::cin >> g[i][j];

	std::cout << std::endl;
	if (Solve())
		for (int i = 1; i <= 9; ++i)
			for (int j = 1; j <= 9; ++j)
				std::cout << g[i][j] << " \n"[j == 9];
	return ;
}



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