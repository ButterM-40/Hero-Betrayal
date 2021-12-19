#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Bag {
	string dummy;
	//Potion section
	int SHP = 0;
	int MHP = 0;
	int LHP = 0;
	int SMP = 0;
	int MMP = 0;
	int LMP = 0;
	int strengthPotion = 0;
	//0 Slime King, 1 Ancient Golem, 2 - Goblin Leader, 3 - Weapon, 4 - Enrique, 5 - Ogre, 6 - Demon Lord
	int ItemBoss[8] = { 0 };
	//0 - Slime, 1 - Poisin Slime, 2 - Electric Slime
	//3 - Golem, 4 - Ghost, 5 - Undead
	//6 - Golbin, 7 - Wild Hog, 8 - Tornado Wolf
	//9 - Ogre, 10 - Fire Slime, 11 - Giant Snake
	//12 - Enrique 13 - Dummy
	//14 - General Lucifer 15 - General Abaddon 16 - General Mormo General 17 - General Satan
	string MD[18] = { "Slime Essence", "Poison Slime Essence", "Electric Slime Essence", "Core", "Soul", "Skulls of Undead", "Goblin's Spears", "Hog's Skin", "Wolf's Fur", "Ogre's Skull", "Fire Slime Essence",
	"Snake's Fang", "None", "None", "Key-1", "Key-2", "Key-3", "Key-4"};
	int MosterDrop[18] = { 0 };
	bool wallet = false;
	//have you gotten the tool
	bool WA1[14] = { false };
	//Tool name 
	string WA1D[7] = { "Butter", "Steel", "Titanium", "Prophets", "Legendary Lucian's", "Demon Slayer", "Ancient Diety" };
	//Didnt use this
	bool EstevanDiscount = false;
	
	//Total coins
	int coins = 0;

	//Returns the amount of potions
	int getSHP() {
		return SHP;
	}
	int getMHP() {
		return MHP;
	}
	int getLHP() {
		return LHP;
	}
	int getSMP() {
		return SMP;
	}
	int getMMP() {
		return MMP;
	}
	int getLMP() {
		return LMP;
	}
	int getStrength() {
		return strengthPotion;
	}

	//Increase the coins
	void increaseCoin(int j) {
		coins += j;
	}

	//Displays Bag options
	void displayBag(Player T) {
		int choice;
		string dummy;
		cout << "Bag" << endl;
		cout << "============================================================================" << endl;
		cout << "1). Potions" << endl;
		cout << "2). Weapons" << endl;
		cout << "3). Armour" << endl;
		cout << "4). Monster Drops" << endl;
		cout << "5). Exit" << endl;
		cout << "============================================================================" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		while (choice > 5 || choice < 1) {
			cout << "Enter Choice" << endl;
			cin >> choice;
		}

		//Bag Options function
		switch (choice) {
		case 1:
			potionBag(); //views potions
			break;
		case 2:
			displayWeapons(T); // views weapons you have
			break;
		case 3:
			displayArmour(); // views armour you have
			break;
		case 4:
			displayDrops(); //view monster drops collected
			break;
		case 5:
			break;
		}
	}

	//Displays the potions you have
	void potionBag() {
		string dummy;
		cout << "============================================================================" << endl;
		cout << "Small Health Potion - " << SHP << endl;
		cout << "Small Mana Potion - " << SMP<< endl;
		cout << "Medium Health Potion - " << MHP << endl;
		cout << "Medium Mana Potion - " << MMP << endl;
		cout << "Large Health Potion - " << LHP<< endl;
		cout << "Large Mana Potion - " << LMP <<endl;
		cout << "Strength Potion - " << strengthPotion << endl;
		cout << "============================================================================" << endl;
	}

	//Displays the monster drops you have
	void displayDrops() {
		cout << "============================================================================" << endl;
		for (int x = 0; x < 18; x++) {
			//If monster drop is greater than 0 then display
			if (MosterDrop[x] >= 1) {
				if (x != 13 || x != 14) { //this is to it doesnt access a set of monsters 
					cout << MD[x] << ": " << MosterDrop[x] << endl; // displays drop and amount
				}
			}
		}
		cout << "============================================================================" << endl;
	}

	//Displays Weapons
	void displayWeapons(Player T) {
		string dummy;
		cout << "============================================================================" << endl;
		for (int x = 0; x < 7; x++) {
			if (WA1[x] == true) { //if true then display the weapon name
				cout << WA1D[x] << " " << "Weapon" << endl;
			}
		}
		cout << "============================================================================" << endl;
	}

	//Displays Armour
	void displayArmour() {
		string dummy;
		cout << "Armour in the Bag" << endl;
		cout << "============================================================================" << endl;
		for (int x = 7; x < 14; x++) {
			if (WA1[x] == true) { // if true displays armour
				cout << WA1D[x - 7] << " Armour" << endl;
			}
		}
		cout << "============================================================================" << endl;
	}

	/*
		Shop Section allows the user to purchase items and removes the coins from the
		if the user doesnt have the necessary coins then he is denied to purchase them
		he is allowed to purchase weapons , potions, and armour and mostly does the same function all of them to purchase
		when you purchase an item it then you obtain the attributes such as +100 your character get that attack or health
		if you have already purchase a weapon or armour then you cant buy it again
	*/


	void shopPotion() {
		int shopChoice;
		do {
			cout << "Potion Shop" << endl;
			cout << "Current Coins: " << coins << endl;
			cout << "============================================================================" << endl;
			cout << "1). Small Health Potion - Restores 100 HP" << endl;
			cout << "Price: 100 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "2). Medium Health Potion - Restores 250 HP" << endl;
			cout << "Price: 300 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "3). Large Health Potion - Restores 500 HP" << endl;
			cout << "Price: 600 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "4). Small Mana Potion - Restores 100 Mana" << endl;
			cout << "Price: 100 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "5). Medium Mana Potion - Restores 250 Mana" << endl;
			cout << "Price: 300 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "6). Large Mana Potion - Restores 500 Mana" << endl;
			cout << "Price: 600 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "7). Stenght Potion - x2 Attack" << endl;
			cout << "Price: 250 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "8). Exit" << endl;
			cout << "============================================================================" << endl;
			cout << "Enter Choice: ";
			cin >> shopChoice;

			switch (shopChoice) {
			case 1:
				if (coins >= 100) {
					coins -= 100;
					SHP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 2:
				if (coins >= 300) {
					coins -= 300;
					MHP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 3:
				if (coins >= 600) {
					coins -= 600;
					LHP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 4:
				if (coins >= 100) {
					coins -= 100;
					SMP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 5:
				if (coins >= 300) {
					coins -= 300;
					MMP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 6:
				if (coins >= 600) {
					coins -= 600;
					LMP += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 7:
				if (coins >= 250) {
					coins -= 250;
					strengthPotion += 1;
				}
				else {
					cout << "Sorry Lad you dont have enough coins" << endl;
				}
				break;
			case 8:
				cout << "Exiting..." << endl << endl << endl;
				break;
			}
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);

		} while (shopChoice != 8);
	}
	void shopWeapons(Player *T) {
		int shopChoice;
		do {
			cout << "Weapon Shop" << endl;
			cout << "Current Coins: " << coins << endl;
			cout << "============================================================================" << endl;
			cout << "1). Butter " << "Weapon" << " - +100 Attack" << endl;
			cout << "Price: 100 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "2). Steel "<< "Weapon" << "- +250 Attack" << endl;
			cout << "Price: 300 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "3). Titanium " << "Weapon" << " - +500 Attack" << endl;
			cout << "Price: 600 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "4). Prophets " << "Weapon" << " - +1000 Attack" << endl;
			cout << "Price: 1,200 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "5). Legendary Lucian's " << "Weapon" << " - + 2000 Attack" << endl;
			cout << "Price: 5,000 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "6). Demon Slayer " << "Weapon" << " - + 4000 Attack" << endl;
			cout << "Price: 20,500 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "7). Ancient Diety " << "Weapon" << " - + 8000 Attack" << endl;
			cout << "Price: 100,000 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "8). Exit" << endl;
			cout << "============================================================================" << endl;
			cout << "Enter Choice: ";
			cin >> shopChoice;
			switch (shopChoice) {
			case 1:
				if (coins >= 100 && WA1[0] != true) {
					coins -= 100;
					WA1[0] = true;
					T->upgradeAttack(100);
				}
				else {
					if (coins <= 100 && WA1[0] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[0] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 2:
				if (coins >= 300 && WA1[1] != true) {
					coins -= 300;
					WA1[1] = true;
					T->upgradeAttack(250);
				}
				else {
					if (coins <= 300 && WA1[1] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[1] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 3:
				if (coins >= 600 && WA1[2] != true) {
					coins -= 600;
					WA1[2] = true;
					T->upgradeAttack(600);
				}
				else {
					if (coins <= 600 && WA1[2] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[2] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 4:
				if (coins >= 1200 && WA1[3] != true) {
					coins -= 1200;
					WA1[3] = true;
					T->upgradeAttack(1000);
				}
				else {
					if (coins <= 1200 && WA1[3] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[3] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 5:
				if (coins >= 5000 && WA1[4] != true) {
					coins -= 5000;
					WA1[4] = true;
					T->upgradeAttack(2000);
				}
				else {
					if (coins <= 5000 && WA1[4] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[4] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 6:
				if (coins >= 20500 && WA1[5] != true) {
					coins -= 20500;
					WA1[5] = true;
					T->upgradeAttack(4000);
				}
				else {
					if (coins >= 20500 && WA1[5] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[5] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 7:
				if (coins >= 100000 && WA1[6] != true) {
					coins -= 100000;
					WA1[6] = true;
					T->upgradeAttack(8000);
				}
				else {
					if (coins >= 8000 && WA1[6] != true) {
						cout << "Sorry cant let you have these powerful weapons for you without the gold" << endl;
					}
					else if (WA1[6] == true) {
						cout << "You already have this Item." << endl;
					}

				}
				break;
			case 8:
				cout << "Exiting..." << endl << endl << endl;
				break;
			}
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			cout << endl << endl; 

		} while (shopChoice != 8);
	}
	void shopArmour(Player *T) {
		int shopChoice;
		do {
			cout << "Armour Shop" << endl;
			cout << "Current Coins: " << coins << endl;
			cout << "============================================================================" << endl;
			cout << "1). Butter Armour - +100 Health" << endl;
			cout << "Price: 100 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "2). Steel Armour - +250 Health" << endl;
			cout << "Price: 300 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "3). Titanium Armour - +500 Health" << endl;
			cout << "Price: 600 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "4). Prophets Armour - +1000 Health" << endl;
			cout << "Price: 1,200 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "5). Legendary Lucian's Armour - + 2000 Health" << endl;
			cout << "Price: 5,000 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "6). Demon Slayer Armour - + 6,000 Health" << endl;
			cout << "Price: 30,500 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "7). Ancient Diety Armour - + 10,000 Health" << endl;
			cout << "Price: 100,000 Coins" << endl;
			cout << "------------------------------------------" << endl;
			cout << "8). Exit" << endl;
			cout << "============================================================================" << endl;
			cout << "Enter Choice: ";
			cin >> shopChoice;
			switch (shopChoice) {
			case 1:
				if (coins >= 100 && WA1[7] != true) {
					coins -= 100;
					WA1[7] = true;
					T->upgradeHealth(100);
				}
				else {
					if (coins >= 100 && WA1[7] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[7] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 2:
				if (coins >= 300 && WA1[8] != true) {
					coins -= 300;
					WA1[8] = true;
					T->upgradeHealth(250);
				}
				else {
					if (coins >= 300 && WA1[8] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[8] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 3:
				if (coins >= 600 && WA1[9] != true) {
					coins -= 600;
					WA1[9] = true;
					T->upgradeHealth(500);
				}
				else {
					if (coins >= 600 && WA1[9] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[9] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 4:
				if (coins >= 1200 && WA1[10] != true) {
					coins -= 1200;
					WA1[10] = true;
					T->upgradeHealth(1000);
				}
				else {
					if (coins >= 1200 && WA1[10] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[10] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 5:
				if (coins >= 5000 && WA1[11] != true) {
					coins -= 5000;
					WA1[11] = true;
					T->upgradeHealth(2000);
				}
				else {
					if (coins >= 2000 && WA1[11] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[11] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 6:
				if (coins >= 30500 && WA1[12] != true) {
					coins -= 30500;
					WA1[12] = true;
					T->upgradeHealth(6000);
				}
				else {
					if (coins >= 30500 && WA1[12] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[12] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 7:
				if (coins >= 100000 && WA1[13] != true) {
					coins -= 100000;
					WA1[13] = true;
					T->upgradeHealth(10000);
				}
				else {
					if (coins >= 100000 && WA1[13] != true) {
						cout << "Sorry cant let you have these powerful armour for you without the gold" << endl;
					}
					else if (WA1[13] == true) {
						cout << "You already have this Item." << endl;
					}
				}
				break;
			case 8:
				cout << "Exiting..." << endl << endl << endl;
				break;
			}
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			cout << endl << endl;

		} while (shopChoice != 8);
	}
};
