#include "Events.h"

Events::Events()
	:type(NoCard), move(Unspecified)
{
}
Events::Events(TypeOfCards typeOfCards, MovementOfTheBall move)
{
	this->type = typeOfCards;
	this->move = move;
}

TypeOfCards Events::getType()const
{
	return this->type;
}

void Events::setType(TypeOfCards typeOfCards)
{
	this->type = typeOfCards;
}
MovementOfTheBall Events::getMove()const
{
	return this->move;
}
void Events::setMove(MovementOfTheBall move)
{
	this->move = move;
}