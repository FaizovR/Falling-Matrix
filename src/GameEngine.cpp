//
// Created by Harriet Barrett on 24/02/2020.
//
#include "../includes/Lab_1.h"

void	init_color_pairs()
{
	init_pair(8, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
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

void sleep_t(int micsec) {
	micsec++;
	usleep(10000 * micsec);
}

void		engineGame(Game *game)
{
	char ch = 1;
	unsigned long time = 0;

	box(game->getWindow(), 0, 0);
	halfdelay(1);
	int counter;
	while (ch != 'q')
	{
		while (1)
		{
			counter = game->getNewLineFreq();
			if (time >= 100)
			{
				while (counter > 0)
				{
					game->addNewLine();
					counter--;
				}
				time = 0;
			}
			game->renderGame();
			wrefresh(game->getWindow());
			sleep_t(game->getRenderFreq());

			time += game->getRenderFreq();
			game->shiftLines();
			game->deleteLinesOverBox();
		}
	}
}