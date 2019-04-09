#include <iostream>
#include <vector>

#include "Game.h"

Game game;

int main()
{
	game.InitializeDeck();
	game.SplitDeck();
	game.DistributeDeck();
	game.PlayTurn();
	game.CheckWinner();

	system("pause");

	return 0;
}