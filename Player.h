#pragma once
#include "Person.h"

class Team; // to have no recursive calls to headers


enum Positions
{
	Undefined,
	CenterDefender,
	LeftDefender,
	RightDefender,
	CenterMidFielder,
	LeftMidFielder,
	RightMidFielder,
	CenterForward,
	LeftForward,
	RightForward,
	Goalkeeper,
};
enum Offence
{
	No,
	Yellow_card,
	Red_card,
};
class Player : public Person
{
protected:
	Team* teamBelong;
	unsigned T_shirt;
	Positions position;
	Offence type;
	bool hasTheBall;
public:
	Player();
	Player(const char*, const char*, unsigned, Team&, unsigned, Positions, Offence, bool);
	Player(const Player&);
	Player& operator=(const Player&);

	//getters
	const Team& getTeamBelong()const;
	unsigned getT_shirt()const;
	Positions getPosition()const;
	Offence getType()const;
	bool getHasTheBall()const;

	//setters
	void setTeamBelong(Team&);
	void setT_shirt(unsigned);
	void setPosition(Positions);
	void setType(Offence);
	void setHasTheBall(bool);

	//methods
	bool attack();
	void passTo(Player& other);  
	friend std::ostream& operator<<(std::ostream& os, const Player& rhs);
};