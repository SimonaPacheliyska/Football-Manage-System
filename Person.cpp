#include "Person.h"
#include <cstring>


Person::Person()
	:firstName(nullptr), lastName(nullptr), age(0)
{
}
Person::Person(const char* firstName, const char* lastName, unsigned age)
	: firstName(nullptr), lastName(nullptr), age(age)
{
	setFirstName(firstName);
	setLastName(lastName);
}
Person::Person(const Person& other)
	: firstName(nullptr), lastName(nullptr)
{
	setFirstName(other.firstName);
	setLastName(other.lastName);
	setAge(other.age);
}
Person& Person::operator=(const Person &rhs)
{
	if (this != &rhs)
	{
		setFirstName(rhs.firstName);
		setLastName(rhs.lastName);
		setAge(rhs.age);
	}
	return *this;
}
Person::~Person()
{
	delete[]this->firstName;
	delete[]this->lastName;
}

//getters
const char* Person::getFirstName()const
{
	return this->firstName;
}
const char* Person::getLastName()const
{
	return this->lastName;
}
unsigned Person::getAge() const
{
	return this->age;
}

//setters
void Person::setFirstName(const char* firstName)
{
	delete[]this->firstName;
	if (firstName != nullptr && strlen(firstName)>0)
	{
		this->firstName = new char[strlen(firstName) + 1];
		strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
		return;
	}
	this->firstName = new char[1];
	this->firstName[0] = '\0';
}
void Person::setLastName(const char* lastName)
{
	delete[]this->lastName;
	if (lastName != nullptr && strlen(lastName)>0)
	{
		this->lastName = new char[strlen(lastName) + 1];
		strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
		return;
	}
	this->lastName = new char[1];
	this->lastName[0] = '\0';
}
void Person::setAge(unsigned age)
{
	this->age = age;
}
///
/// Outputs all the information about the person.
///
std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
	os << rhs.firstName << ", " << rhs.lastName << ", " << rhs.age;
	return os;
}

