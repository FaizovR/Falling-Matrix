//
// Created by Harriet Barrett on 12/02/2020.
//

#include "../includes/Lab_1.h"
#include "../includes/Line.h"
#include "../includes/Point.h"

Line::Line(int length, int offsetX, int colorMod) {
	this->length = length;
	this->offsetX = offsetX;
	this->statusDeath = false;
	for (int i = 0; i < length; i++) {
		if (colorMod == 1)
			arrayPoints.push_back(Point(offsetX, 0 - i, 1 + rand() % 7));
		else if (colorMod == 2)
			arrayPoints.push_back(Point(offsetX, 0 - i, 9));
	}
	arrayPoints.push_back(Point(offsetX, 0 - length, 8));
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

void Line::shiftUpLine() {
	for (int i = 0; i < length + 1; i++) {
		arrayPoints.at(i).shiftPointUp();
	}
}

Line::~Line() {
	arrayPoints.clear();
}

int Line::getStatusDeath() const {
	return statusDeath;
}

void	Line::changeStatusLine(int boxHeight) {
	this->statusDeath = boxHeight < arrayPoints.at(arrayPoints.size() - 1).getPosY();
}


int Line::getLastCoord() {
	return (arrayPoints.at(arrayPoints.size() - 1).getPosX());
}

int Line::getLastCoordY() {
	return (arrayPoints.at(arrayPoints.size() - 1).getPosY());
}

