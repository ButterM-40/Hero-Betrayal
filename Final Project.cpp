#include <iostream>
#include <fstream>
#include <string>
#include "PlayerMonster.h"
#include "BagNShop.h"
#include "StoryNDisplays.h"
#include "FightingPhase.h"

using namespace std;

int main()
{
	int GameMenu;
	Player Individual(100, 10, 170, 150, 160, "Hero", "Slay", "Ultimate Strike");
	Bag Purse;
	//Purse.Shop("Hero", AddAptr, AddWptr);
	
	//QuestBook();

	string dummy;
	int choice1;
	do {
		cout << "Hero Betrayal" << endl;
		cout << "==============" << endl;
		cout << "1). New World" << endl;
		cout << "2). Load World" << endl;
		cout << "3). Exit " << endl;
		cout << "==============" << endl;
		cout << "Enter Choice: ";
		cin >> choice1;

		cout << endl;

		switch (choice1) {
		case 1:
			Individual.NewPlayer();
			SummonStory();
			KingIntro(Individual);
			break;
		case 2:
			Load(&Purse, &Individual);
			break;
		case 3:
			return 0;
		default:
			cout << "Choice not within range" << endl;
		}

		cout << "Press Enter to continue...";
		getline(cin, dummy);
	} while (choice1 < 1 || choice1 > 3);

	//Menu itself for the player to access

	int MapSelection = 0;
	do {
		GameMenu = Menu();
		switch (GameMenu) {
		case 1:
			QuestBook();
			break;
		case 2:
			menuTeleport();
			break;
		case 3:
			map(&Purse, &Individual);
			break;
		case 4:
			Status(Individual, Purse);
			break;
		case 5:
			Purse.displayBag(Individual);
			break;
		case 6:
			cout << "Save Data" << endl;
			Save(&Purse, &Individual);
			break;
		case 7:
			cout << "Exit" << endl;
			break;
		//	return 0;
		default:
			cout << "Their was a mistake" << endl;

		}

		cout << "Press Enter to continue...";
		cin.ignore();
		getline(cin, dummy);

	} while (GameMenu != 7);

}