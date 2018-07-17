#include "Vector.h"
#include "Person.h"
#include "Player.h"
#include "Team.h"
#include "Match.h"

int main()
{
	Vector<Player*> players1;
	Vector<Player*> players2;

	Team BayernMunich("BayernMunich", players1);
	Team ManUnited("ManchesterUnited", players2);

	Person referee("Mike", "Dean", 48);
	Player player1("Robert","Lewandowski", 28, BayernMunich, 9, CenterForward, No, true);
	Player player2("Arjen", "Robben", 33, BayernMunich,10, CenterMidFielder, No, false);
	Player player3("Thomas", "Müller", 27, BayernMunich,13, RightForward, No, false);
	Player player4("Manuel", "Neuer", 31, BayernMunich, 1, Goalkeeper, No, false);
	Player player5("Franck", "Ribery", 31, BayernMunich, 7, LeftMidFielder, No, false);
	Player player6("Arturo","Vidal", 37, BayernMunich, 8, RightMidFielder, No, false);
	Player player7("Thiago", "Alcantara",34, BayernMunich, 16, LeftDefender, No, false);
	Player player8("Mats", "Hummels", 32, BayernMunich, 24, RightDefender, No, false);
	Player player9("Renato", "Sanches ", 28, BayernMunich, 18, LeftForward, No, false);
	Player player10("Douglas", "Costa", 26, BayernMunich, 15, CenterDefender, No, false);
	Player player11("Bastian", "Schweinsteiger", 32, BayernMunich, 32, LeftMidFielder, No, false);

	players1.push_back(&player1);
	players1.push_back(&player2);
	players1.push_back(&player3);
	players1.push_back(&player4);
	players1.push_back(&player5);
	players1.push_back(&player6);
	players1.push_back(&player7);
	players1.push_back(&player8);
	players1.push_back(&player9);
	players1.push_back(&player11);
	BayernMunich.setPlayers(players1);


	Player player12("Christiano", "Ronaldo", 33, ManUnited, 10, CenterMidFielder, No, false);
	Player player13("James", "Rodriguez", 27, ManUnited, 13, RightForward, No, false);
	Player player14("Gareth", "Bale", 31, ManUnited, 1, Goalkeeper, No, false);
	Player player15("Karim", "Benzema", 31, ManUnited, 7, LeftMidFielder, No, false);
	Player player16("Sergio", "Ramos", 37, ManUnited, 8, RightMidFielder, No, false);
	Player player17("Pepe", "Laveran", 34, ManUnited, 16, LeftDefender, No, false);
	Player player18("Francisco", "Suarez", 32, ManUnited, 24, RightDefender, No, false);
	Player player19("Keylor", "Navas ", 28, ManUnited, 18, LeftForward, No, false);
	Player player20("Marcelo", "Silva", 26, ManUnited, 15, CenterDefender, No, false);
	Player player21("Toni", "Kroos", 32, ManUnited, 32, LeftMidFielder, No, false);
	Player player22("Alvado", "Morata", 32, ManUnited, 32, LeftMidFielder, No, false);
	Player player23("Luka ", "Modric", 32, ManUnited, 32, LeftMidFielder, No, false);

	players2.push_back(&player12);
	players2.push_back(&player13);
	players2.push_back(&player14);
	players2.push_back(&player15);
	players2.push_back(&player16);
	players2.push_back(&player17);
	players2.push_back(&player18);
	players2.push_back(&player19);
	players2.push_back(&player20);
	players2.push_back(&player21);
	players2.push_back(&player22);
	players2.push_back(&player23);

	ManUnited.setPlayers(players2);

	Match match1(BayernMunich, ManUnited, 90);
	
	std::cout << "	Manchester United players:\n\n";
	for (size_t i = 0; i < ManUnited.getPlayers().size(); i++)
	{
	std::cout<< *ManUnited.getPlayers()[i] << std::endl;
	}
	std::cout << "\n	Bayern Munich players:\n\n";
	for (size_t i = 0; i < BayernMunich.getPlayers().size(); i++)
	{
		std::cout << *BayernMunich.getPlayers()[i] << std::endl;
	}
	std::cout << std::endl;
	match1.startTheGame();

	system("pause");
	return 0;
}