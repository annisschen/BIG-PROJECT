#include "signal.h"

void signal(int level)
{
	switch (level)
	{
	case 1: 
		mvprintw(LINES / 2, COLS / 2 - strlen("LEVEL 1"), "LEVEL 1");
		refresh();
	default:
		break;
	}
}
