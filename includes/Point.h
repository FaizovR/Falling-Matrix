#ifndef LAB_1_V2_POINT_H
# define LAB_1_V2_POINT_H


class Point{
private:
	int	color;
	char ch;
	int posX;
	int posY;
public:
	int getPosX() const;

	virtual ~Point();

	int getPosY() const;

	Point(int posX, int posY, int color);

	void drawPoint(int boxHeight, WINDOW *win);

	void shiftPointDown();

	void shiftPointUp();
};

#endif //LAB_1_V2_POINT_H
