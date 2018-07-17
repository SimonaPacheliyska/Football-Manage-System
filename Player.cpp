#include "Player.h"
#include "Team.h"

Player::Player() : Person(), teamBelong(nullptr)
{
	setPosition(Undefined);
}
Player::Player(const char* firstName, const char* lastName, unsigned age, Team& teamBelong, unsigned T_shirt,
				Positions position, Offence type, bool hasTheBall)
	: Person(firstName, lastName, age), teamBelong(nullptr)
{
	setTeamBelong(teamBelong);
	setT_shirt(T_shirt);
	setPosition(position);
	setType(type);
	setHasTheBall(hasTheBall);
}
Player::Player(const Player &other)
	:Person(other)
{
	setTeamBelong(*other.teamBelong);
	setT_shirt(other.T_shirt);
	setPosition(other.position);
	setType(other.type);
	setHasTheBall(other.hasTheBall);
}
Player& Player::operator=(const Player& rhs)
{
	if (this != &rhs)
	{
		Person::operator=(rhs);
		setTeamBelong(*rhs.teamBelong); // Submission by value (because it`s a pointer).
		setT_shirt(rhs.T_shirt);
		setPosition(rhs.position);
		setType(rhs.type);
		setHasTheBall(rhs.hasTheBall);
	}
	return *this;
}

//getters
const Team& Player::getTeamBelong()const
{
	return *this->teamBelong;
}
unsigned Player::getT_shirt() const
{
	return this->T_shirt;
}
Positions Player::getPosition()const
{
	return this->position;
}
Offence Player::getType() const
{
	return this->type;
}
bool Player::getHasTheBall() const
{
	return this->hasTheBall;
}

//setters
void Player::setTeamBelong(Team& teamBelong)
{
	this->teamBelong = &teamBelong;
}
void Player::setT_shirt(unsigned T_shirt)
{
	this->T_shirt = T_shirt;
}
void Player::setPosition(Positions position)
{
	this->position = position;
}
void Player::setType(Offence type)
{
	this->type = type;
}
void Player::setHasTheBall(bool hasTheBall)
{
	this->hasTheBall = hasTheBall;
}

//some methods

///
/// Checks whether the player has the ball. If the player has the ball, he attacks.
///
bool Player::attack()
{
	return this->hasTheBall ? true : false;
}
///
/// Implements passing the ball. 
/// If the player has the ball, he can pass it to another player. 
/// Otherwise he can`t and the method will do nothing.
///
void Player::passTo(Player &other)
{
	if(this->hasTheBall)
	{
		setHasTheBall(false);
		other.setHasTheBall(true);
		return;
	}
}
///
/// Outputs all the information for the player. 
/// Because the parent's friends are not the inheritor's friends, the method should include parent`s information
///
std::ostream& operator<<(std::ostream& os, const Player& rhs)
{
	os << rhs.firstName << " " << rhs.lastName << ", " << rhs.age << ", ";
	os << rhs.teamBelong->getName() << ", " << rhs.T_shirt << ", ";
	switch (rhs.position)
	{
	case Undefined:os << "Undefined"; break;
		case CenterDefender:os << "CenterDefender"; break;
		case LeftDefender:os << "LeftDefender"; break;
		case RightDefender:os<< "RightDefender"; break;
		case CenterMidFielder:os << "CenterMidFielder"; break;
		case LeftMidFielder:os << "LeftMidFielder"; break;
		case RightMidFielder:os << "RightMidFielder"; break;
		case CenterForward:os << "CenterForward"; break;
		case LeftForward:os << "LeftForward"; break;
		case RightForward:os << "RightForward"; break;
		case Goalkeeper:os << "Goalkeeper"; break;
	}
	os << ", ";
	switch (rhs.type)
	{
	case No:os<<"No card"; break;
	case Yellow_card:os << "Yellow card"; break;
	case Red_card:os<<"Red card"; break;
	} 
	os<< ", " << rhs.hasTheBall;
	return os;
}