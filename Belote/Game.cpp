#include <iostream>

#include "Game.h"

int Game::scores[Game::PLAYERS] { 0 };

Game::Game() : firstPlayer(0), lastTrick(0), mainDeck(false), board(false), players {true, true, true, true}
{
	
}

void Game::InitializeDeck()
{
	this->mainDeck.Fill();
	this->mainDeck.Shuffle();
}

void Game::SplitDeck()
{
	Card card = this->mainDeck.DrawCard();

	std::cout << "Would you like to keep this " << card << " ? Y/N" << std::endl;

	char answer;
	std::cin >> answer;

	switch (answer)
	{
		case 'Y':
		case 'y':
			this->players[this->firstPlayer].AddCard(card);
		break;

		case 'N':
		case 'n':
		default:
			this->AddCardToBoard(card);
		break;
	}

	++this->firstPlayer;

	if (this->firstPlayer == PLAYERS)
		this->firstPlayer = 0;
}

void Game::DistributeDeck()
{
	while (this->board.Count() < 4)
		this->AddCardToBoard(this->mainDeck.DrawCard());

	for (unsigned int i = 0; i < PLAYERS; ++i)
	{
		while (this->players[i].Count() < 3)
			this->players[i].AddCard(this->mainDeck.DrawCard());
	}
}

void Game::PlayTurn()
{
	for (unsigned int i = 0; i < PLAYERS; ++i)
	{
		system("cls");

		std::cout << "Here is the board : " << std::endl;
		this->board.Sort();
		this->board.Print();

		std::cout << "Here is your deck : " << std::endl;
		this->players[i].Sort();
		this->players[i].Print();

		std::cout << "Which card would you like to play ?" << std::endl;
		
		int choice = -1;
		std::cin >> choice;

		while (choice > this->players[i].Count() || choice < 1)
		{
			system("cls");

			std::cout << "You entered a wrong choice." << std::endl;
			std::cout << "Here is the board : " << std::endl;
			this->board.Sort();
			this->board.Print();

			std::cout << "Here is your deck : " << std::endl;
			this->players[i].Sort();
			this->players[i].Print();

			std::cout << "Which card would you like to play ?" << std::endl;

			std::cin >> choice;
		}

		Deck available(false);
		Deck pick(false);

		int sum = 0;
		int value = this->players[i].Peek(choice - 1).GetValue();
		
		while (sum < value)
		{
			int chosen = -1;

			available.Empty();

			for (unsigned int j = 0; j < this->board.Count(); ++j)
			{
				if (this->board.Peek(j) <= this->players[i].Peek(choice - 1))
				{
					bool flag = true;

					for (unsigned int k = 0; k < pick.Count(); ++k)
						if (pick.Peek(k) == this->board.Peek(j))
							flag = false;

					if (flag)
						available.AddCard(this->board.Peek(j));
				}
			}

			std::cout << "You've played the " << this->players[i].Peek(choice - 1) << "." << std::endl;

			if (pick.Count() != 0)
			{
				std::cout << "You've picked : " << std::endl;
				pick.Print();
			}
			
			available.Print();

			std::cout << "Select a card you'd like to take : " << std::endl;
			std::cin >> chosen;

			while (chosen < 0 || chosen > available.Count())
			{
				system("cls");

				std::cout << "You entered a wrong choice." << std::endl;
				std::cout << "You've played the " << this->players[i].Peek(choice - 1) << "." << std::endl;

				if (pick.Count() != 0)
				{
					std::cout << "You've picked : " << std::endl;
					pick.Print();
				}

				std::cout << "Here are the available cards : " << std::endl;
				available.Sort();
				available.Print();

				std::cout << "Select a card you'd like to take : " << std::endl;
				std::cin >> chosen;
			}

			pick.AddCard(available.Peek(chosen - 1));

			sum += available.Peek(chosen - 1).GetValue();

			available.PopCard(available.Peek(chosen - 1));
		}
	}
}

void Game::CheckWinner()
{
	PrintScores();
}

void Game::AddCardToBoard(Card& card)
{
	this->board.AddCard(card);
}

void Game::PrintScores()
{
	std::cout << std::endl;

	for (unsigned int i = 0; i < PLAYERS; ++i)
		std::cout << "The player " << i + 1 << " has scored " << this->scores[i] << " points !" << std::endl;

	std::cout << std::endl;
}
