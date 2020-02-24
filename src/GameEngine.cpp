//
// Created by Harriet Barrett on 24/02/2020.
//
#include "../includes/Lab_1.h"

void	init_color_pairs()
{
	init_pair(8, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_GREEN, COLOR_GREEN);
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(5, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(7, COLOR_CYAN, COLOR_CYAN);
	init_pair(9,COLOR_GREEN, COLOR_BLACK);
}


Game *init()
{
	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	curs_set(0);
	refresh();
	srand(time(nullptr));
	WINDOW *win = newwin(LINES, COLS, 0, 0);
	Game *game = new Game(COLS - 2, LINES - 2);
	game->setWindow(win);

	while (1)
	{
		try
		{
			UserInputRenderFreq(game);
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}

	while (1)
	{
		try
		{
			UserInputNewLineFrequency(game);
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}

	while (1)
	{
		try
		{
			UserInputLineLength(game);
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}

	while (1)
	{
		try
		{
			UserInputColorMod(game);
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	init_color_pairs();
	return (game);
}



void		engineGame(Game *game)
{
	char ch = 1;
	unsigned long time = 0;

	box(game->getWindow(), 0, 0);
	halfdelay(1);
	while (ch != 'q')
	{
		while ((ch = getch()) && ch == ERR)
		{
			if ((time / game->getNewLineFreq() > 0 || time % game->getNewLineFreq() == 0))
			{
				while (time / game->getNewLineFreq() > 0)
				{
					game->addNewLine();
					time -= game->getNewLineFreq();
				}
				time = 0;
			}
			game->renderGame();
			wrefresh(game->getWindow());
			usleep(game->getRenderFreq());
			time += game->getRenderFreq();
			game->shiftLines();
			game->deleteLinesOverBox();
		}
	}
}