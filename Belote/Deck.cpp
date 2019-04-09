#include <algorithm>
#include <iostream>
#include <random>

#include "Game.h"
#include "Deck.h"

extern Game game;

Deck::Deck(bool plays) : plays(plays)
{

}

void Deck::Empty()
{
	while (!this->deck.empty())
		this->deck.erase(this->deck.begin());
}

void Deck::Fill()
{
	Empty();

	for (unsigned int i = 0; i < cards::ASSETS; ++i)
	{
		for (unsigned int j = 0; j < cards::VALUES; ++j)
		{
			this->deck.emplace_back(Card(cards::assets[i], cards::values[j]));
		}
	}
}

void Deck::Shuffle()
{
	std::random_device rng;
	std::mt19937 urng(rng());
	std::shuffle(this->deck.begin(), this->deck.end(), urng);
}

void Deck::Print()
{
	for (unsigned int i = 0; i < this->deck.size(); ++i)
		std::cout << i + 1 << ". " << this->deck.at(i) << std::endl;
	
	std::cout << std::endl;
}

void Deck::Sort()
{
	bool flag = true;

	while (flag)
	{
		flag = false;

		for (unsigned int i = 1; i < this->Count(); ++i)
		{
			if (this->deck[i - 1] > this->deck[i])
			{
				Card temp = this->deck[i - 1];
				this->deck[i - 1] = this->deck[i];
				this->deck[i] = temp;

				flag = true;
			}
		}
	}
}

int Deck::Count()
{
	return this->deck.size();
}

bool Deck::Plays()
{
	return this->plays;
}

Card Deck::Peek(int i)
{
	return this->deck.at(i);
}

Card Deck::DrawCard()
{
	Card drawn = this->deck.at(0);
	this->deck.erase(this->deck.begin());
	return drawn;
}

bool Deck::PopCard(Card& card)
{
	for (unsigned int i = 0; i < this->deck.size(); ++i)
	{
		if (card == this->deck[i])
		{
			this->deck.erase(this->deck.begin() + i);
			return true;
		}
	}

	return false;
}

void Deck::AddCard(Card & card)
{
	this->deck.push_back(card);
}

void Deck::KeepCard(bool answer, Card& card)
{
	this->PopCard(card);

	if (answer)
		this->AddCard(card);

	else
		game.AddCardToBoard(card);
}
