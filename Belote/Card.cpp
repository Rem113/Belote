#include "Card.h"

Card::Card(std::string a, std::string v)
{
	this->asset = a;
	this->value = v;
}

int Card::GetValue()
{
	for (unsigned int i = 0; i < cards::VALUES; ++i)
		if (cards::values[i] == this->value)
			return i;
}

void Card::Print(std::ostream& stream)
{
	stream << this->value << " of " << this->asset;
}

bool Card::operator==(Card const& a)
{
	return (a.asset == this->asset && a.value == this->value);
}

bool Card::operator>(Card const & a)
{
	for (unsigned int i = 0; i < cards::VALUES; ++i)
	{
		if (this->value == cards::values[i])
			return false;
		if (a.value == cards::values[i])
			return true;
	}
}

bool Card::operator>=(Card const & a)
{
	if (this->value == a.value)
		return true;

	for (unsigned int i = 0; i < cards::VALUES; ++i)
	{
		if (this->value == cards::values[i])
			return false;
		if (a.value == cards::values[i])
			return true;
	}
}

bool Card::operator<(Card const & a)
{
	for (unsigned int i = 0; i < cards::VALUES; ++i)
	{
		if (this->value == cards::values[i])
			return true;
		if (a.value == cards::values[i])
			return false;
	}
}

bool Card::operator<=(Card const & a)
{
	if (this->value == a.value)
		return true;

	for (unsigned int i = 0; i < cards::VALUES; ++i)
	{
		if (this->value == cards::values[i])
			return true;
		if (a.value == cards::values[i])
			return false;
	}
}

std::ostream& operator<<(std::ostream& stream, Card& card)
{
	card.Print(stream);
	return stream;
}