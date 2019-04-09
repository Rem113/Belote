#pragma once

#include <vector>

#include "Card.h"

class Deck
{
	public:
		Deck(bool plays);

		void Empty();	// Empties the deck
		void Fill();	// Fills the deck with basic cards
		void Shuffle();
		void Print();
		void Sort();
		int Count();
		bool Plays();
		Card Peek(int i);
		Card DrawCard();	// Draws a card and removes it from the deck
		bool PopCard(Card& card);
		void AddCard(Card& card);
		void KeepCard(bool answer, Card& card);

	private:
		std::vector<Card> deck;
		bool plays;
};