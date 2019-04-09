#pragma once

#include <ostream>
#include <string>

namespace cards
{
	const unsigned int ASSETS = 4;
	const unsigned int VALUES = 10;

	const std::string assets[ASSETS] = { "Diamond", "Club", "Spade", "Heart" };
	const std::string values[VALUES] = { "Ace", "2", "3", "4", "5", "6", "7", "Queen", "Jack", "King" };
}

struct Card
{
	Card(std::string a, std::string v);
	int GetValue();
	void Print(std::ostream& stream);
	bool operator==(Card const& a);
	bool operator>(Card const& a);
	bool operator>=(Card const& a);
	bool operator<(Card const& a);
	bool operator<=(Card const& a);
	friend std::ostream& operator<<(std::ostream& stream, Card& card);

	std::string asset;
	std::string value;
};