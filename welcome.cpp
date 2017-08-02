#include "welcome.h"
#include "curses.h"
#include "game.h"

void welcome()
{
	clear();
	char *hello = "Do you have logic?";

	initscr();
	noecho();
	curs_set(FALSE);
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
	mvprintw(LINES / 2, COLS / 2 - strlen(ABOUT), ABOUT);
	attron(A_BOLD);
	mvprintw(LINES-1 , COLS - strlen("return"), "return");
	attroff(A_BOLD);

	refresh();
	cbreak();
	noecho();

	intrflush(stdscr, false);
	keypad(stdscr, true);
	while (1) {
		int ch = getch();
		if (ch == 10) {
			welcome();
		}
	}

}