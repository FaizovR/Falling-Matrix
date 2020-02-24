//
// Created by Harriet Barrett on 12/02/2020.
//

#include "../includes/Lab_1.h"
#include "../includes/Game.h"


Game::Game(int boxWidth, int boxHeight) {
	this->boxWidth = boxWidth;
	this->boxHeight = boxHeight;
}

void Game::setRenderFreq(int renderFreq) {
	Game::renderFreq = renderFreq;
}

void Game::setNewLineFreq(int newLineFreq) {
	Game::newLineFreq = newLineFreq;
}

void Game::setLineLength(int lineLength) {
	Game::lineLength = lineLength;
}

int Game::getRenderFreq() const {
	return renderFreq;
}

int Game::getNewLineFreq() const {
	return newLineFreq;
}

int Game::getBoxHeight() const {
	return boxHeight;
}

void Game::setWindow(WINDOW *window) {
	Game::window = window;
}

WINDOW *Game::getWindow() const {
	return window;
}

bool Game::isLineHere(int posX) {
	for (size_t i = 0; i < linesList.size(); ++i) {
		if (linesList.at(i).getLastCoord() == posX && linesList.at(i).getLastCoordY() <=  0)
			return true;
	}
	return false;
}

void Game::addNewLine() {
 	int PosX = 1 + rand() % boxWidth;
 	if (linesList.empty()) {
		linesList.push_back(Line(lineLength, PosX, this->colorMod));
	}
 	else if (!isLineHere(PosX))
 		linesList.push_back(Line(lineLength, PosX, this->colorMod));
}

void Game::renderGame() {
	for (size_t i = 0; i < linesList.size(); i++) {
		linesList.at(i).drawLine(boxHeight, window);
	}
}

void Game::shiftLines() {
	for (size_t i = 0; i < linesList.size(); i++) {
		linesList.at(i).shiftDownLine();
		linesList.at(i).changeStatusLine(this->boxHeight);
	}
}

void Game::deleteLinesOverBox() {
	for (size_t i = 0; i < linesList.size(); i++) {
		if (linesList.at(i).getStatusDeath())
		{
			linesList.erase(linesList.begin() + i);
			i--;
		}
	}
}

Game::~Game() {
	linesList.clear();
}

int Game::getColorMod() const {
	return colorMod;
}

void Game::setColorMod(int colorMod) {
	Game::colorMod = colorMod;
}
