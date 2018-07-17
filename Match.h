#pragma once

#include "Team.h"
#include <iostream>
#include <sstream>
#include <string>

class Match
{
private:
	Team host; // It makes a copy of the fields from the class "Team"
	unsigned hostGoals;
	Team guest; // It makes a copy of the fields from the class "Team"
	unsigned guestGoals;
	double duration;
public:
	Match();
	Match(const Team& host, const Team& guest, double duration);

	const Team& getHost()const;
	void setHost(const Team&);

	unsigned getHostGoals()const;
	void setHostGoals(size_t);

	const Team& getGuest()const;
	void setGuest(const Team&);

	size_t getGuestGoals()const;
	void setGuestGoals(size_t);

private:
	Vector<std::string> split(const std::string& str, char delimiter);

	//events
	void scoresGoal(const Vector<std::string>& strings);
	void removingTheBall(const Vector<std::string>& strings);
	void makesViolation_YellowCard(const Vector<std::string>& strings);
	void makesViolation_RedCard(const Vector<std::string>& strings);
	void passingInHost(const Vector<std::string>& strings);
	void passingInGuest(const Vector<std::string>& strings);
	void attackEvent(const Vector<std::string>& strings);
public:
	void startTheGame();
};

