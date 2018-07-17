#pragma once
#include "Vector.h"
#include "Player.h"

class Team
{
private:
	char* name;
	Vector <Player*> players;
public:
	Team();
	Team(const Team& other);
	Team(const char*, const Vector <Player*>& players);
	Team& operator=(const Team& rhs);
	~Team();

	const char* getName()const;
	void setName(const char*);

	Vector<Player*>& getPlayers();
	void setPlayers(const Vector<Player*>& players);
	void removePlayer(Player& player);

};
