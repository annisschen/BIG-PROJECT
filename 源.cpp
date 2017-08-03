#include <curses.h>
#include <string.h>
#include "welcome.h"

int main()
{
	initscr();
	noecho();
	curs_set(FALSE);
	welcome();
}