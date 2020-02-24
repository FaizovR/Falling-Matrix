//
// Created by Harriet Barrett on 24/02/2020.
//
#include "../includes/Lab_1.h"

int		UserInput()
{
	int temp;
	printw("\n>");
	if (scanw((char *)"%d", &temp) == 0)
	{
		throw UserInputException((char *)"Wrong input! Try again ");
	}
	return (temp);
}

void	UserInputRenderFreq(Game *game)
{
	int temp;

	printw((char *)"Write a render Frequency");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException((char *)"Render frequency may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw((char *)"%s",inputExc.getErrorMessage());
		}
	}
	temp *= 1000000;
	game->setRenderFreq(temp);
}

void	UserInputNewLineFrequency(Game *game)
{
	int temp;
	printw((char *)"Write a new line Frequency");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException((char *)"New line frequency may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw((char *)"%s",inputExc.getErrorMessage());
		}
	}
	temp *= 1000000;
	game->setNewLineFreq(temp);
}

void	UserInputLineLength(Game *game)
{
	int temp;

	printw((char *)"Write a line Length");
	while (1)
	{
		try
		{
			temp = UserInput();
			if ( temp < 1 || temp > 30)
				throw UserInputException((char *)"Line length may be from 1 to 30! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw((char *)"%s",inputExc.getErrorMessage());
		}
	}
	game->setLineLength(temp);
}


void	UserInputColorMod(Game *game)
{
	int temp;

	printw((char *)"Choose a color mode: \n 1 = color mod \n 2 = green mod");
	while (1)
	{
		try
		{
			temp = UserInput();
			if (temp != 1 && temp != 2)
				throw UserInputException((char *)"Wrong color mod! Try again ");
			break;
		}
		catch (UserInputException& inputExc)
		{
			printw((char *)"%s",inputExc.getErrorMessage());
		}
	}
	game->setColorMod(temp);
}

