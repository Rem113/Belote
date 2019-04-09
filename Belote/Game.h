#pragma once

#include <vector>

#include "Deck.h"

class Game
{
	public:
		Game();

		void InitializeDeck();
		void SplitDeck();
		void DistributeDeck();
		void PlayTurn();
		void CheckWinner();

		void AddCardToBoard(Card& card);
		void PrintScores();

		static const int PLAYERS = 4;
		static int scores[PLAYERS];

	private:
		Deck mainDeck;
		Deck board;
		Deck players[PLAYERS];
		int firstPlayer;
		int lastTrick;
};