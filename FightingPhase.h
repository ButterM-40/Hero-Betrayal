#pragma once
#include <iostream>
#include <string>
#include "PlayerMonster.h"
#include "BagNShop.h"

using namespace std;

/*
	Each turn will change with player or monter depending on the bool turn. 
	This is a recursive function so it stops when ethier player or monther reach 0 hp
	player has access to a bag with potions, 2 attacks, and a escape witha  25% to success
	monsters have haccess to 2 attacks with a 50 50 chance of ethier of the two
	If a player win then it obtains the coins, and monster drop
	Potions menu works 

*/


//int MonsterH, int MonsterA, int MonsterSA, string MonsterNA, string MonsterSSA, string MonsterName, int *Potion1, int *Potion2, int *Potion3, int *Potion4, int *Potion5, int *Potion6, int *Potion7
void PlayerFighter(Player P, Monster M, Bag *B, bool turn, int creature, int BossRegistration) {
	int choice = 0;
	int PotionChoice = 0;
	int CoinFlip2 = 0;
	string dummy;

	//Base so if you defeat or get defeat it ends the function
	if (M.getMonsterHealth() <= 0) {
		B->increaseCoin(M.getMonsterCoin());//obtain the coins you got
		cout << "============================================================================" << endl;
		cout << "You defeated " << M.getMonsterName() << endl; //name of the defeated creature
		cout << "Coin Gained: " << M.getMonsterCoin() << endl; // Coins gained
		cout << "Drop: " << M.getMonsterDrop() << endl; //display drop
		cout << "============================================================================" << endl;
		if (BossRegistration == -1) {
			B->MosterDrop[creature] += 1; //increase amount drop
		}
		else {
			B->ItemBoss[BossRegistration] += 1; //increase boss drop
		}
		return;
	}
	//Another base so it ends if the player is defeated
	else if (P.getHealth() <= 0) {
		cout << "You were defeated by " << M.getMonsterName() << endl;
		return;
	}

		cout << "============================================================================" << endl;
		cout << "BATTLE: " << P.getTitle() << " v.s " << M.getMonsterName() << endl;
		cout << endl << endl << endl;
		cout << endl << "Current " << M.getMonsterName() << " HP: " << M.getMonsterHealth() << endl << endl;
		cout << M.getMonsterName() << " Attack: " << M.getMonsterAttack() << endl;
		cout << M.getMonsterName() << " Ultimate: " << M.getMonsterUltimate() << endl;
		cout << "Current HP: " << P.getHealth() << "             " << "Current Mana: " << P.getMana() << endl;
		cout << "Attack: " << P.getAttack() << endl;
		cout << "Ultimate: " << P.getUltimate() << endl;
		cout << endl;
		cout << "Turn ";

		if (turn == true) {
			do {
				//Menu of the Player attack phase
				cout << P.getTitle() << endl;
				cout << "============================================================================" << endl;
				cout << "1. " << P.getNAttack() << "                      2." << P.getUAttack() << endl;
				cout << "3. Potions" << "                           4. Run Away!" << endl;
				cout << "============================================================================" << endl;
				cout << "Enter Choice:";
				cin >> choice;

				cout << endl << endl;


				//Case 1 and 2 just calculate battle damage to the creature
				switch (choice) {
				case 1:
					cout << "============================================================================" << endl;
					cout << "You attack the " << M.getMonsterName() << " with " << P.getNAttack() << endl;
					M.reduceHealth(P.getAttack());
					turn = false;
					cout << "============================================================================" << endl;
					break;
				case 2:
					cout << "============================================================================" << endl;
					if (P.getMana() >= P.getManaUAttack()) {
						P.usedMana();
						cout << "You attack the " << M.getMonsterName() << " with " << P.getUAttack() << endl;
						M.reduceHealth(P.getUltimate());
						turn = false;
					}
					else {
						cout << "You dont have enough Mana" << endl;
					}
					cout << "============================================================================" << endl;
					break;
				case 3:
					cout << endl;
					//Bag Menu has different items of potions and decreases the potion amount if you use it
					//it calculates how much are you using the health potion or mana
					//The stentgh potion increase your attack x2
					cout << "Potion Bag" << endl;
					cout << "=======================" << endl;
					cout << "1). Small Health Potion: " << B->getSHP() << endl;
					cout << "2). Medium Health Potion: " << B->getMHP() << endl;
					cout << "3). Large Health Potion: " << B->getLHP() << endl;
					cout << "4). Small Mana Potion: " << B->getSMP() << endl;
					cout << "5). Medium Mana Potion: " << B->getMMP() << endl;
					cout << "6). Large Mana Potion: " << B->getLMP() << endl;
					cout << "7). Strength Potion: " << B->getStrength() << endl;
					cout << "8). Exit Bag" << endl;
					cout << "=======================" << endl;
					cout << "Enter Choice: ";
					cin >> PotionChoice;

					switch (PotionChoice) {
					case 1:
						if (B->getSHP() > 0) {
							cout << "You have gain 100 HP" << endl;
							B->SHP -= 1;
							P.UsedHealthP(100);
						}
						else { cout << "You dont have this item." << endl; }
						break;
					case 2:
						if (B->getMHP() > 0) {
							cout << "You have gain 250 HP" << endl;
							B->MHP -= 1;
							P.UsedHealthP(250);
						}
						else { cout << "You dont have this item." << endl; }
						break;

					case 3:
						if (B->getLHP() > 0) {
							cout << "You have gain 500 HP" << endl;
							B->LHP -= 1;
							P.UsedHealthP(500);
						}
						else { cout << "You dont have this item." << endl; }
						break;
					case 4:
						if (B->getSMP() > 0) {
							cout << "You have gain 100 Mana" << endl;
							B->SMP -= 1;
							P.UsedManaP(100);
						}
						else { cout << "You dont have this item." << endl; }
						break;
					case 5:
						if (B->getMMP() > 0) {
							cout << "You have gain 250 HP" << endl;
							B->MMP -= 1;
							P.UsedManaP(250);
						}
						else { cout << "You dont have this item." << endl; }
						break;
					case 6:
						if (B->getLMP() > 0) {
							cout << "You have gain 500 HP" << endl;
							B->LMP -= 1;
							P.UsedManaP(500);
						}
						else { cout << "You dont have this item." << endl; }
					case 7:
						if (B->getStrength() > 0) {
							cout << "You have gain x2 Attack until the end of the game" << endl;
							B->strengthPotion -= 1;
							P.strengthPotionUse();
						}
						else { cout << "You dont have this item." << endl; }
						break;
					case 8:
						cout << "Exiting Bag..." << endl;
					default:
						cout << "Incorrect Choice" << endl;
					}
					break;
				case 4:

					srand(time(0));

					CoinFlip2 = rand() % 4 + 1;

					if (CoinFlip2 == 1) {

						cout << "You have Escaped" << endl;
						return;
					}
					else {
						cout << "Your attempt to run away, but you slipped and fell" << endl;
						turn = false;
					}
					break;

				default:
					cout << "Incorrect Choice" << endl;
				}
			}while (turn != false);
		}
		else if (turn == false) {

			int CoinFlip = 0;

			cout << M.getMonsterName() << endl;

			srand(time(0));

			CoinFlip = rand() % 3 + 1;
			cout << "============================================================================" << endl;
			if (CoinFlip == 1 || CoinFlip == 2) {
				cout << M.getMonsterName() << " attacked you with " << M.getMonsterAttackN() << endl;
				cout << "Damage Taken: " << M.getMonsterAttack() << endl;
				P.ReduceHealth(M.getMonsterAttack());
			}
			else {
				cout << M.getMonsterName() << " attacked you with " << M.getMonsterSAttackN() << endl;
				cout << "Damage Taken: " << M.getMonsterUltimate() << endl;
				P.ReduceHealth(M.getMonsterUltimate());
			}
			cout << "============================================================================" << endl;
			turn = true;

		}

		
		cout << "Press Enter to Continue" << endl;
		cin.ignore();
		getline(cin, dummy);
		PlayerFighter(P, M, B, turn, creature, BossRegistration); //Recursive function 
}