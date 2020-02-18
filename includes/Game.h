#ifndef LAB_1_V2_GAME_H
# define LAB_1_V2_GAME_H

class Game {
private:

	int		boxWidth;
	int		boxHeight;
	int		renderFreq;
	int		newLineFreq;
	int		lineLength;
	int		colorMod;
	std::vector<Line> linesList;
	WINDOW	*window;
public:
	virtual ~Game();

	void setColorMod(int colorMod);

	int getColorMod() const;

	void	shiftLines();

	void	renderGame();

	bool isLineHere(int posX);

	void addNewLine();

	void setWindow(WINDOW *window);

	WINDOW *getWindow() const;

	int getBoxHeight() const;

	int getRenderFreq() const;

	int getNewLineFreq() const;

	void setLineLength(int lineLength);

	void setRenderFreq(int renderFreq);

	void setNewLineFreq(int newSnakeFreq);

	Game(int boxWidth, int boxHeight);

	void deleteLinesOverBox();
};


#endif //LAB_1_V2_GAME_H
