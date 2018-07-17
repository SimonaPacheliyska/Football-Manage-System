#pragma once

enum TypeOfCards
{
	YellowCard,
	RedCard,
	NoCard
};
enum  MovementOfTheBall
{
	Unspecified,
	Forward,
	Backward,
	In_the_same_area
};
class Events
{
private:
	TypeOfCards type;
	MovementOfTheBall move;

public:
	Events();
	Events(TypeOfCards, MovementOfTheBall);


	TypeOfCards getType() const;
	void setType(TypeOfCards);

	MovementOfTheBall getMove()const;
	void setMove(MovementOfTheBall);
};

