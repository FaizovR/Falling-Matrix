#ifndef LAB_1_V2_LAB_1_H
# define LAB_1_V2_LAB_1_H

/*
** ************************************************************************** **
**                                                                            **
** Libs                                                                       **
**                                                                            **
** ************************************************************************** **
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <list>
#include <vector>
#include <exception>

/*
** ************************************************************************** **
**                                                                            **
** Headers                                                                    **
**                                                                            **
** ************************************************************************** **
*/

#include "Point.h"
#include "Line.h"
#include "Game.h"
#include "Exception.h"

/*
** ************************************************************************** **
**                                                                            **
** UserInputUtilities                                                         **
**                                                                            **
** ************************************************************************** **
*/

int		UserInput();
void	UserInputRenderFreq(Game *game);
void	UserInputNewLineFrequency(Game *game);
void	UserInputLineLength(Game *game);
void	UserInputColorMod(Game *game);

/*
** ************************************************************************** **
**                                                                            **
** Game tools                                                                 **
**                                                                            **
** ************************************************************************** **
*/

Game	 *init();
void	init_color_pairs();
void	engineGame(Game *game);
#endif