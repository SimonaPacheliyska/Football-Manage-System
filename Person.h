#pragma once
#include <iostream>
#include <iosfwd> //forward declaration for iostream

class Person
{
protected:
	char* firstName;
	char* lastName;
	unsigned age;
public:
	Person();
	Person(const char*, const char*, unsigned);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();

	//getters
	const char* getFirstName()const;
	const char* getLastName()const;
	unsigned getAge()const;

	//setters
	void setFirstName(const char*);
	void setLastName(const char*);
	void setAge(unsigned);

	friend std::ostream& operator<<(std::ostream& os, const Person& rhs);
};