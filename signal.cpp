#include "signal.h"

void signal(int level)
{
	clear();
	switch (level)
	{
	case 1: 
		move(LINES / 2, (COLS - strlen("level 1")) / 2);            /*move the cursor to the center*/
		waddstr(stdscr, "Level 1");
		refresh();
		Sleep(1000);
		break;
	case 2:
		move(LINES / 2, (COLS - strlen("level 2")) / 2);            /*move the cursor to the center*/
		waddstr(stdscr, "Level 2");
		refresh();
		break;
	case 3:
		move(LINES / 2, (COLS - strlen("level 3")) / 2);            /*move the cursor to the center*/
		waddstr(stdscr, "Level 3");
		refresh();
		break;
	default:
		break;
	}

	
}
