#include "../includes/Lab_1.h"
#include <thread>

void	init_color_pairs() {
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

void 	draw(class Line *line, class Game *game, WINDOW *win){
	wrefresh(win);
	box(win, 0, 0);
	line->shiftDownLine();
	line->drawLine(game->getBoxHeight(), win);
}

Game *init() {
	if (!initscr()) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	curs_set(0);
	refresh();
	srand(time(NULL));
	WINDOW *win = newwin(LINES, COLS, 0, 0);
	Game *game = new Game(COLS - 2, LINES - 2);
	game->setWindow(win);

	int temp;

	mvprintw(0, 0, "Write a render Frequency");
	mvprintw(1, 0, ">");
	if (!scanw("%d", &temp))
		throw "Scan Error\n";
	game->setRenderFreq(temp);

	mvprintw(3, 0, "Write a new line Frequency");
	mvprintw(4, 0, ">");
	scanw("%d", &temp);
	game->setNewLineFreq(temp);

	mvprintw(5, 0, "Write a line Length");
	mvprintw(6, 0, ">");
	scanw("%d", &temp);
	game->setLineLength(temp);

	mvprintw(7, 0, "Choose a color mode");
	mvprintw(8, 0, ">");
	scanw("%d", &temp);
	game->setColorMod(temp);
	//
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	init_color_pairs();
	return (game);
}



int		engineGame(Game *game) {
	char ch = 1;
	unsigned long time = 0;



	box(game->getWindow(), 0, 0);
	int i = 0;
//					game->addNewLine();
//	game->addNewLine();
	halfdelay(5);
	while (ch != 'q')
	{
		while (1)
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

//			game->deleteLinesOverBox();
		}
	}
	return (0);
}



using namespace std;

int main() {

	Game *game;
	try {
		game = init();
	} catch (...){
		cout << "shopa";
	}


	start_color();

	box(game->getWindow(), 0, 0);



	int i = 0;
	refresh();

	engineGame(game);

	wrefresh(game->getWindow());
	delwin(game->getWindow());
	endwin();
	delete game;
}