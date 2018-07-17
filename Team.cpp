#include <cstring>
#include "Team.h"
#include "Player.h"
using namespace std;

Team::Team()
	:name(nullptr)
{
}

Team::Team(const Team& other)
	: name(nullptr), players(other.players)
{
	setName(other.name);
}

Team::Team(const char* name, const Vector<Player*>& _players)
	: name(nullptr), players(_players)
{
	setName(name);
}
Team& Team::operator=(const Team &rhs)
{
	if (this != &rhs)
	{
		this->name = nullptr;
		setName(rhs.name);
		this->players = rhs.players;
	}
	return *this;
}

Team::~Team()
{
	delete[] this->name;
}

const char* Team::getName()const
{
	return this->name;
}

void Team::setName(const char* name)
{
	delete[]this->name;
	if (name != nullptr && strlen(name)>0)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		return;
	}
	this->name = new char[1];
	this->name[0] = '\0';
}
///
/// Outputs all the information for each player in the array of players
///
 Vector<Player*>& Team::getPlayers()
{
	return this->players;
}

 void Team::setPlayers(const Vector<Player*>& players)
 {
	 this->players = players;
 }
 ///
 /// Removes player from the array by his number of a t-shirt.
 /// A temporary array is created. It is filled in with all the elements without the one requested.
 /// The operator= takes care of size decreasing.
 ///
 void Team::removePlayer(Player & player)
 {
	 Vector<Player*> temp;
	 for (size_t i = 0; i <this->players.size(); i++)
	 {
		 if (this->players[i]->getT_shirt() != player.getT_shirt())
		 {
			 temp.push_back(this->players[i]);
		 }
	 }
	 this->players = temp;
 }
