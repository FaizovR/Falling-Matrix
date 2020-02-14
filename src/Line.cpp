//
// Created by Harriet Barrett on 12/02/2020.
//

#include "../includes/Lab_1.h"
#include "../includes/Line.h"
#include "../includes/Point.h"

Line::Line(int length, int offsetX) {
	this->length = length;
	this->offsetX = offsetX;
	this->statusDeath = false;
	for (int i = 0; i < length; i++) {
		arrayPoints.push_back(Point(offsetX, i - length + 1, 1 + rand() % 7));
	}
	arrayPoints.push_back(Point(offsetX, -length, 8));
}

void Line::drawLine(int boxHeight, WINDOW *win) {
	for (int i = 0; i < length + 1; i++) {
		arrayPoints.at(i).drawPoint(boxHeight, win);
	}
}

void Line::shiftDownLine() {
	for (int i = 0; i < length + 1; i++) {
		arrayPoints.at(i).shiftPointDown();
	}
}

Line::~Line() {
	arrayPoints.clear();
}

int Line::getStatusDeath() const {
	return statusDeath;
}

void	Line::changeStatusLine(int boxHeight) {
	if (arrayPoints.at(arrayPoints.size() - 1).getPosY() > boxHeight)
		this->statusDeath = true;
	else
		this->statusDeath = false;
}


int Line::getLastCoord() {
	return (arrayPoints.at(arrayPoints.size() - 1).getPosX());
}

int Line::getLastCoordY() {
	return (arrayPoints.at(arrayPoints.size() - 1).getPosY());
}

