//
// Created by Harriet Barrett on 24/02/2020.
//
#include "../includes/Lab_1.h"

int		UserInput()
{
	int temp;
	printw("\n>");
	if (scanw("%d", &temp) == 0)
	{
		throw UserInputException("Wrong input! Try again ");
	}
	return (temp);
}

void	UserInputRenderFreq(Game *game)
{
	int temp;

	printw("Write a render Frequency");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException("Render frequency may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}
	temp *= 100000;
	game->setRenderFreq(temp);
}

void	UserInputNewLineFrequency(Game *game)
{
	int temp;
	printw("Write a new line Frequency");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException("New line frequency may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}
	temp *= 100000;
	game->setNewLineFreq(temp);
}

void	UserInputLineLength(Game *game)
{
	int temp;

	printw("Write a line Length");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException("Line length may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}
	temp *= 100000;
	game->setLineLength(temp);
}


void	UserInputColorMod(Game *game)
{
	int temp;

	printw("Choose a color mode: \n 1 = color mod \n 2 = green mod");
	while (1)
	{
		try
		{
			temp = UserInput();
			if (temp != 1 && temp != 2)
				throw UserInputException("Wrong color mod! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw("%s",inputExc.getErrorMessage());
		}
	}
	game->setColorMod(temp);
}
