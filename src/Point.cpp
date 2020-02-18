//
// Created by Harriet Barrett on 12/02/2020.
//

#include "../includes/Lab_1.h"
#include "../includes/Point.h"


Point::Point(int posX, int posY, int color) {
	this->ch = 33 + random() % 93;
	this->posX = posX;
	this->posY = posY;
	this->color = color;
}

void Point::drawPoint(int boxHeight, WINDOW *win) {
	if (posY > 0 && posY <= boxHeight) {
		mvwaddch(win, posY, posX,ch | COLOR_PAIR(color));
	}
}

void Point::shiftPointDown() {
	this->posY++;
}

int Point::getPosY() const {
	return posY;
}

Point::~Point() {
	
}

int Point::getPosX() const {
	return posX;
}
