#include "Match.h"

Match::Match()
{
}
Match::Match(const Team& _host, const Team& _guest, double duration)
	: host(_host), hostGoals(0),
	guest(_guest), guestGoals(0), duration(duration)
{
}

//getters and setters
const Team& Match::getHost()const
{
	return this->host;
}

void Match::setHost(const Team& host)
{
	this->host = host;
}

size_t Match::getHostGoals()const
{
	return this->hostGoals;
}
void Match::setHostGoals(size_t hostGoals)
{
	this->hostGoals = hostGoals;
}


const Team& Match::getGuest()const
{
	return this->guest;
}
void Match::setGuest(const Team& guest)
{
	this->guest = guest;
}


size_t Match::getGuestGoals()const
{
	return this->guestGoals;
}
void Match::setGuestGoals(size_t secondGoals)
{
	this->guestGoals = secondGoals;
}

//methods for events

///
/// Implements a string break by a given separator. Then puts the split std::string into an array
///
Vector<std::string> Match::split(const std::string & str, char delimiter)
{
	Vector<std::string> res;
	std::istringstream is(str);
	std::string out;
	while (getline(is, out, delimiter))
	{
		res.push_back(out);
	}
	return res;
}

///
///  Accepts a split std::string. 
///  In the case that the first word in the array is a "goal", 
/// it searches for the second keyword(which is expected to be the name of the team) in the array of words
/// and then increases the goals of the team.
///  In case of mismatching, function outputs a message.
///
void Match::scoresGoal(const Vector<std::string>& strings)
{
	if (strings[1] == this->host.getName())
	{
		std::cout << this->host.getName() << " scored a goal\n\n";
		this->hostGoals++;
		std::cout << "The result is " << hostGoals << " : " << guestGoals << std::endl;
		return;
	}
	if (strings[1] == this->guest.getName())
	{
		std::cout << this->guest.getName() << " scored a goal\n\n";
		this->guestGoals++;
		std::cout << "The result is " << hostGoals << " : " << guestGoals << std::endl;
		return;
	}
	std::cout << "Invalid input. Try again\n\n";
}
///
///  Accepts a split string. 
///  In the case that the first word in the array is a "tookTheBall", 
/// it searches for the second keyword(which is expected to be the name of the team) in the array 
/// and output a message for taking the ball.
///  In case of mismatching, function outputs a message again.
///
void Match::removingTheBall(const Vector<std::string>& strings)
{
	if (strings[0] == this->host.getName())
	{
		std::cout << this->host.getName() << " took the ball from " << this->guest.getName() << "\n\n";
		return;
	}
	if (strings[0] == this->guest.getName())
	{
		std::cout << this->guest.getName() << " took the ball from " << this->host.getName() <<"\n\n";
		return;
	}
	std::cout << "Invalid input. Try again\n\n";
}
///
///  Accepts a split std::string. 
///  In the case that the first word in the array is a "yellowCard" or "redCard", 
/// it searches for the second keyword(which is expected to be the name of the player) in the array 
/// and gives the player a violation. If he gets red car, he gets out out of the game.
///  In case of mismatching, function outputs a message.
///
void Match::makesViolation_YellowCard(const Vector<std::string>& strings)
{
		Vector<Player*>& playersHost = host.getPlayers();
		Vector<Player*>& playersGuest = guest.getPlayers();
		for (size_t i = 0; i<playersHost.size(); i++)
		{
			if (strings[1] == playersHost[i]->getFirstName())
			{
				if(playersHost[i]->getType() == Yellow_card)
				{
					makesViolation_RedCard(strings);
					return;
				}

				playersHost[i]->setType(Yellow_card);
				std::cout << playersHost[i]->getFirstName() << " got a yellow card\n";
				return;
			}
		}
		for (size_t i = 0; i<playersGuest.size(); i++)
		{
			if (strings[1] == playersGuest[i]->getFirstName())
			{
				playersGuest[i]->setType(Yellow_card);
				std::cout << playersGuest[i]->getFirstName() << " got a yellow card\n";
				return;
			}
		}

}
void Match::makesViolation_RedCard(const Vector<std::string>& strings)
{
		Vector<Player*>& playershost = host.getPlayers();
		Vector<Player*>& playersGuest = guest.getPlayers();
		for (size_t i = 0; i < playershost.size(); i++)
		{
			if (strings[1] == playershost[i]->getFirstName())
			{
				playershost[i]->setType(Red_card);
				std::cout << playershost[i]->getFirstName() << " got a red card and comes out of the game\n";
				this->host.removePlayer(*playershost[i]); //becouse it`s an array of pointers
				return;
			}
		}
		for (size_t i = 0; i < playersGuest.size(); i++)
		{
			if (strings[1] == playersGuest[i]->getFirstName())
			{
				playersGuest[i]->setType(Red_card);
				std::cout << playersGuest[i]->getFirstName() << " got a red card and comes out of the game\n";
				this->host.removePlayer(*playersGuest[i]); //becouse it`s an array of pointers
				return;
			}
		}
		std::cout << "Invalid input. Try again\n";
}
///
///
///

void Match::attackEvent(const Vector<std::string>& strings)
{
	Vector<Player*>& playershost = host.getPlayers();
	Vector<Player*>& playersGuest = guest.getPlayers();
	for (size_t i = 0; i < playershost.size(); i++)
	{
		if (strings[1] == playershost[i]->getFirstName())
		{
			if (playershost[i]->attack()) //returns true if the player has the ball
			{
				std::cout << playershost[i]->getFirstName() << " is attacking\n";
				return;
			}
		}
	}
	for (size_t i = 0; i < playersGuest.size(); i++)
	{
		if (strings[1] == playersGuest[i]->getFirstName())
		{
			if (playersGuest[i]->attack()) //returns true if the player has the ball
			{
				std::cout << playersGuest[i]->getFirstName() << " is attacking\n";
				return;
			}
		}
	}
	std::cout << "This player is not able to attack because he doesn`t have the ball. Try with another one!\n";
}
void Match::passingInHost(const Vector<std::string>& strings)
{
	Vector<Player*>& playershost = host.getPlayers();
	int firstPos = -1, secondPos = -1;
	for (size_t i = 0; i < playershost.size(); i++)
	{
		if (strings[0] == playershost[i]->getFirstName()  )
		{
			firstPos = i;
			continue;
		}
		if (strings[2] == playershost[i]->getFirstName())
		{
			secondPos = i;
		}
	}
	if (firstPos != -1 && secondPos != -1)
	{
		std::cout << playershost[firstPos]->getFirstName() << " passed to " << playershost[secondPos]->getFirstName() << std::endl;
		playershost[firstPos]->passTo(*playershost[secondPos]);
	}
}
void Match::passingInGuest(const Vector<std::string>& strings)
{
	Vector<Player*>& playersGuest = guest.getPlayers();
	Player* first = nullptr;
	Player* second = nullptr;
	for (size_t i = 0; i < playersGuest.size(); i++)
	{
		if (strings[0] == playersGuest[i]->getFirstName())
		{
			first = playersGuest[i];
			continue;
		}
		if (strings[2] == playersGuest[i]->getFirstName())
		{
			second = playersGuest[i];
		}
	}
	if (first != nullptr && second != nullptr)
	{
		first->passTo(*second);
	}
}
void Match::startTheGame()
{
	std::string myString;
	std::cout << "	Hello, user. The rules of the game are :\n" << std::endl << "- you write different actions that you want to be executed;" << std::endl;
	std::cout << std::endl << "- if your input is correct, the program will process it as commands;\n" << std::endl;
	std::cout << "(examples: 1)attack \" \" name of the player,\n	   2)name of the player \" \" passTo \" \" name of another player,\n	   3)\"goal\" \" name of the team that scored the goal,\n	   ";
	std::cout << "4)\"name of team\" \" \" \"tookTheBall\",\n	   5)\"violation\(yellowCard, redCard)\" " "\" \" \"name of the player\") " << std::endl;
	std::cout << "\n- the game continues until you write \"END\";\n\n";
	std::cout << "- the program will return a result.\n" << std::endl;
	while (myString != "END")
	{
		std::cout << " Enter your event ";
		getline(std::cin, myString);
		Vector<std::string> strings = split(myString, ' ');
		//
		if(strings.size() == 0)
		{
			std::cout << "No input!\n";
			continue;
		}
		//
		if (strings[0] == "goal")
		{
			scoresGoal(strings);
		}
		else if (strings[1] == "tookTheBall")
		{
			removingTheBall(strings);
		}
		else if (strings[0] == "yellowCard")
		{
			makesViolation_YellowCard(strings);
		}
		else if (strings[0] == "redCard")
		{
			makesViolation_RedCard(strings);
		}
		else if (strings[0] == "attack")
		{
			attackEvent(strings);
		}
		else if (strings[1] == "passTo")
		{
			passingInHost(strings);
			passingInGuest(strings);
		}
		else
		{
			std::cout << "Invalid input. Try again\n\n";
		}
		std::cout << std::endl;
	}
	if(this->hostGoals>this->guestGoals)
	{
		std::cout << "The result is " << this->hostGoals << ":" << this->guestGoals << std::endl;
		std::cout << this->host.getName() << " is the winner\n";
		return;

	}
	if(this->hostGoals<this->guestGoals)
	{
		std::cout << "The result is " << this->hostGoals << ":" << this->guestGoals << std::endl;
		std::cout << this->guest.getName() << " is the winner\n";
		return;
	}
	
	std::cout << "There is no winner\n";
}
