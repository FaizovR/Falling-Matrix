#ifndef LAB_1_V2_LINE_H
#define LAB_1_V2_LINE_H


class Line{

private:
	bool		statusDeath;
	int		length;
	int		offsetX;
	std::vector<Point> arrayPoints;

public:

	Line(int length, int offsetX);

	void	drawLine(int boxHeight, WINDOW *win);

	void	shiftDownLine();

	virtual ~Line();

	int 	getStatusDeath() const;

	void	changeStatusLine(int boxHeight);

	int		getLastCoord();

	int		getLastCoordY();

};

#endif //LAB_1_V2_LINE_H
