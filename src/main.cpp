#include "../includes/Lab_1.h"

int main(void) {
	Game *game;
	game = init();
	start_color();
	box(game->getWindow(), 0, 0);
	refresh();
	engineGame(game);
	wrefresh(game->getWindow());
	delwin(game->getWindow());
	endwin();
	delete game;
}