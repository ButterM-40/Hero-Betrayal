#pragma once

#include <string>
#include <iostream>
#include <time.h>


using namespace std;
class Player{
	private:
		string Title = "None";
		string Name = "None";
		string NAttack = "None";
		string UAttack = "None";
		int health = 100;
		int MaxHealth = 100;
		int attack = 100;
		int Ultimate = 200;
		int ManaUltimate = 100;
		int mana = 100;
		int MaxMana = 100;

	public:
		//Player Constructor
		Player(int h, int a, int u, int s, int m, string n, string NA, string UA) {
			health = h;
			MaxHealth = h;
			attack = a;
			Ultimate = u; 
			mana = m;
			MaxMana = m;
			Title = n;
			NAttack = NA;
			UAttack = UA;
		}

		void NewPlayer() {
			int choice;
			string n;
			bool yesName = false;
			string newstr;

			//User can have spaces within the names since it messes with the safe file
			cout << "No Spaces within the names" << endl;
				cout << "What is your name young hero?: ";
				cin.get();
				getline(cin, n);

				

				for (int x = 0; x < n.length(); x++) {
					if (n[x] == ' ') {
						yesName = true;
					}
				}
				while (yesName == true) {
					yesName = false;
					
					cout << "Please Use a Name without Space" << endl;
					cout << "What is your name young hero?: ";
					getline(cin, n);
					newstr = n;

					

					for (int x = 0; x < n.length(); x++) {
						if (n[x] == ' ') {
							yesName = true;
						}
					}
					n = newstr;
				}
				

			//User selects a class of their own choosing with pre-build information
			cout << endl;
			cout << "Please Select a Class" << endl;
			cout << "======================" << endl;
			cout << "1). Swordmen - Uses Swords" << endl;
			cout << "2). Shield - Uses Sheilds" << endl;
			cout << "3). Mage - Uses Magic" << endl;
			cout << "4). Archer - Uses Bow" << endl;
			cout << "======================" << endl;
			cout << "Enter Choice: ";
			cin >> choice;
		
			while (choice > 6 || choice < 1) {
				cout << "Choice not within range choose agian" << endl;
				cout << "Enter Choice";
				cin >> choice;
			}

			switch (choice) {
			case 1:
				//Test
				Title = "Swordmen";
				Name = n;
				NAttack = "Slash";
				UAttack = "Double-Slash";
				health = 200;
				MaxHealth = 200;
				attack = 200;
				Ultimate = 400;
				ManaUltimate = 200;
				mana = 200;
				MaxMana = 200;
				break;
			case 2:
				Title = "Shield";
				Name = n;
				NAttack = "Shield-Slam";
				UAttack = "Shield-Tackle";
				health = 500;
				MaxHealth = 500;
				attack = 50;
				Ultimate = 150;
				ManaUltimate = 30;
				mana = 30;
				MaxMana = 30;
				break;
			case 3:
				Title = "Mage";
				Name = n;
				NAttack = "Elemental-Strike";
				UAttack = "Small-Fire-Ball";
				health = 200;
				MaxHealth = 200;
				attack = 200;
				Ultimate = 300;
				ManaUltimate = 300;
				mana = 300;
				MaxMana = 300;
				break;
			case 4:
				Title = "Archer";
				Name = n;
				NAttack = "Arrow-Shots";
				UAttack = "Weak-Magical-Arrows";
				health = 200;
				MaxHealth = 200;
				attack = 150;
				Ultimate = 200;
				ManaUltimate = 150;
				mana = 150;
				MaxMana = 150;
				break;
			}

		}

		//All function named get just return the information needed
		string getTitle() {
			return Title;
		}

		string getName() {
			return Name;
		}

		int getHealth() {
			return health;
		}

		void upgradeHealth(int upgrade) {
			health += upgrade;
			MaxHealth += upgrade;
		}

		//Getting attacked by a creature
		void ReduceHealth(int inflict) {
			health -= inflict; 
		}

		int getAttack() {
			return attack;
		}

		void upgradeAttack(int upgrade) {
			attack += upgrade;
			Ultimate += upgrade;
		}

		int getUltimate() {
			return Ultimate;
		}

		string getNAttack() {
			return NAttack;
		}

		string getUAttack() {
			return UAttack;
		}
		int getManaUAttack() {
			return ManaUltimate;
		}
		void usedMana() {
			mana -= ManaUltimate;
		}

		void upgradeMana(int upgrade) {
			mana += upgrade;
			MaxMana += upgrade;
		}

		//Using the strength potion
		void strengthPotionUse() {
			attack *= 2;
			Ultimate *= 2;
		}

		int getMana() {
			return mana;
		}


		//This is used to write on the txt file all the functions that have set
		void setTitle(string t) {
			Title = t;
		}

		void setName(string t) {
			Name = t;
		}

		void setHealth(int t) {
			health = t;
			MaxHealth = t;
		}

		void setMana(int t) {
			mana = t;
			MaxMana = t;
		}

		void setManaUAttack(int t) {
			ManaUltimate = t;
		}

		void setUltimate(int t) {
			Ultimate = t;
		}

		void setNAttack(string t) {
			NAttack = t;
		}

		void setUAttack(string t) {
			UAttack = t;
		}

		void setAttack(int t) {
			attack = t;
		}

		//Calcuate the potions effect
		//Affected by potions
		bool UsedManaP(int ManaPotion) {
			if (mana + ManaPotion >= MaxMana) {
				ManaPotion = MaxMana - mana;

				if (ManaPotion == 0) {
					cout << "Max Mana Already" << endl;
					return false;
				}
				mana += ManaPotion;
				cout << "Mana Recoverd by " << ManaPotion << endl;
				cout << "Current Mana: " << mana << endl;
			}
			else {
				mana += ManaPotion;
				cout << "Mana Recoverd by " << ManaPotion << endl;
				cout << "Current Mana: " << mana << endl;
			}
			return true;
		}

		//Affected by potions
		bool UsedHealthP(int HealthPotion) {
			if (health + HealthPotion >= MaxHealth) {
				HealthPotion = MaxHealth - health;

				if (HealthPotion == 0) {
					cout << "Max Health Already" << endl;
					return false;
				}
				health += HealthPotion;
				cout << "Health Recoverd by " << HealthPotion << endl;
				cout << "Current Health: " << health << endl;
			}
			else {
				health += HealthPotion;
				cout << "Health Recoverd by " << HealthPotion << endl;
				cout << "Current Health: " << health << endl;
			}
			return true;
		}
};

class Monster {
	private:
		//Variables being used for the creature
		string Name;
		string AttackN;
		string SpecialAttack;
		int health = 100;
		int attack = 100;
		int SAttack = 100;
		int CoinDrop = 0;
		string dropN;
	public:
		//Creates a creature from scratch
		Monster(string N, string A, string S, int h, int a, int SA, int c, string d) {
			Name = N;
			AttackN = A;
			SpecialAttack = S;
			health = h;
			attack = a;
			SAttack = SA;
			CoinDrop = c;
			dropN = d;
		}
		//These function only return a the information needed
		string getMonsterName() {
			return Name;
		}
		string getMonsterDrop() {
			return dropN;
		}
		string getMonsterAttackN() {
			return AttackN;
		}
		string getMonsterSAttackN() {
			return SpecialAttack;
		}
		int getMonsterHealth() {
			return health;
		}
		int getMonsterAttack() {
			return attack;
		}
		int getMonsterUltimate() {
			return SAttack;
		}
		int getMonsterCoin() {
			return CoinDrop;
		}
		void reduceHealth(int j) {
			health -= j;
		}
};
