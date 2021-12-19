#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "PlayerMonster.h"
#include "FightingPhase.h"
#include "BagNShop.h"

using namespace std;

void Kingdom1(int choice, Bag *B, Player *T);
void Slime(int choice, Bag *B, Player *T);
void Ruins(int choice, Player *T, Bag *B);
void Forest(int choice, Player *T, Bag *B);
void Nation(int choice, Player *T, Bag *B);
void Kingdom2(int choice, Player *T, Bag *B);
void Forest2(int choice, Player *T, Bag *B);
void DemonCastle(int choice, Player *T, Bag *B);

struct MapNInfo {
	string MapName;
	string QuestGiven;
	string Location1;
	string Location2;
	string Location3;
	string Location4;
	bool L1 = false;
	bool L2 = false;
	bool L3 = false;
	bool AccessedLocation = false;
};

int Location = 0;
//The list of locations and their what is inside those locations
MapNInfo LocationNames[8]{
	{"Kingdom of Silcox", "Estevan the Potion Seller", "Reynol The Sword Seller", "Mario The Armour Seller", "Joseph's House" ,"King Lucian's Palace", false, false, false, true},
	{"Slimy Swamp", "Jimmy The Anarchist", "Slime", "Poisonous Slimes", "Electic Slime", "King Slime", false, false, false, false},
	{"Ancient Ruins", "Makoto the Mage", "Golem", "Spirit", "Undead", "Ancient Golem", false, false, false, false},
	{"Forest of Fortuna", "Asta The Elve", "Goblin", "Wild Hogs", "Tornado Wolf", "Goblin Leader", false, false, false, false},
	{"Dwarf Nation", "Chamy The Food Enjoyer", "Construction Center", "Dwarf Research", "Dwarf Hotel", "King Dwarf", false, false, false, false},
	{"Kingdom of Hinojosa", "Matt The tourist", "Training Ground", "Enrique Home's", "Ramen Shop", "King Nichola's Palace", false, false, false, false},
	{"Kaprak Forest", "Yoshi the Forest Keeper", "Ogre", "Fire Slime", "Giant Snakes", "Ogre Leader", false, false, false, false},
	{"Demon Castle", "General Lucifer", "General Abaddon", "General Mormo", "General Satan", "Demon King Liebe", false, false, false, false},
};

//Displays information about the player
void Status(Player T, Bag O) {
	cout << endl;
	cout << "============================================================================" << endl;
	cout << "Current Status on Hero" << endl;
	cout << "============================================================================" << endl;
	cout << "Hero Class: "<< T.getTitle() << endl;
	cout << "Hero Name: " << T.getName() << endl;
	cout << "Health: " << T.getHealth() <<"    "<< "Mana: " << T.getMana() << endl;
	cout << "Attack: " << T.getNAttack() << "- " << T.getAttack() << " Damage" << endl;
	cout << "Ultimate Attack: " << T.getUAttack() << "- " << T.getUltimate() << " Damage" << endl;
	cout << "Current Coins: " << O.coins << endl;
	cout << "============================================================================" << endl;
}

//Main menu where the player select an option
int Menu() {
	int choice;
	cout << endl;
	cout << "Player Menu" << endl;
	cout << "Current Location: " << LocationNames[Location].MapName<< endl;
	cout << "============================================================================" << endl;
	cout << "1). Quest Book" << endl;
	cout << "2). Teleport" << endl;
	cout << "3). Current Location Map" << endl;
	cout << "4). Hero Status" << endl;
	cout << "5). Inventory" << endl;
	cout << "6). Save Data" << endl;
	cout << "7). Exit Game" << endl;
	cout << "============================================================================" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice < 1 || choice > 7) {
		cout << "Choice not within range" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
	}

	return choice;
}


//Side Quests
//Main Quests
//Information about the quests themselfs
struct Quest {
	string QuestN;
	bool complete = false;
	string description;
	string Item;
	int amountItem; 
	bool givenTask = false;
};

//Information about the quest
Quest ListCheck[18]{
	{"Slippery Adventure", false, "Defeat the Slime King and give King Lucian the Crown" , "Slime Crown", 1, true},
	{"Technology Advances", false, "Defeat the Ancient Golem and return it to King Lucian", "Golem Core", 1, false},
	{"Help the Eleves", false, "Defeat the packs of Goblins", "Kill the Golbin Leader" , 1, false},
	{"Drawf Weaponization", false, "Help the Draft create a weapon ", "Obtain the Mass Destructive Weapons", 1, false},
	{"Conflict with another Nation", false, "You and a kingdom representative will fight", "Defeat Enrique the Kingdom representitive", 1, false},
	{"Ogre Tribe Massacre", false, "The King has informed you that a villages are being raided by Ogres", "Defeat the Ogre Tribe Leader", 1, false},
	{"Defeat The Demon King", false, "Obtain the Keys from each General", "Demon Key", 4, false},
	//Side Quests
	{"Rescue Estavan Daugther", false, "Estevan Daugther has gone missing and it might be the Slime king doing", "Rescue Estevan's Daugther", 1, false},
	{"Slime Gathering", false, "Get 5 Electric Slime Essence", "Electric Slime Essence", 5, false},
	{"Weird Guy Request for souls", false, "Get 5 Ghost Souls", "Souls", 5, false},
	{"Missing Sword", false, "Help Asta find his sword. Mayde the Goblin leader stole it?", "Sword", 1, false},
	{"Slime Desert", false, "Chamy wants some slimes for desert", "Slime Essence", 20, false},
	{"Shocking Experience", false, "The Construction Center needs electricity", "Electric Slime Essence", 20, false},
	{"Return to the Past", false, "The Dwarf Research Team needs Golem Core", "Core", 20, false},
	{"To the Fur", false, "A hotel needs some Wolf Fur for its workers", "Wolf's Fur", 20, false},
	{"Save the Baby", false, "Yoshi Lost Baby Mario!", "Baby Mario", 1, false},
	{"Robbed Man", false, "Locate where this man wallet is in the Ramen Shop", "Wallet", 1, false},
};
//Displays the quests if you were given the task to and if its not complete since if you completed them you dont need to view it
void QuestBook() {
	cout << endl;
	cout << "============================================================================" << endl;
	cout << "Main Quest" << endl;
	for (int x = 0; x < 7; x++) {
		if (ListCheck[x].givenTask == true && ListCheck[x].complete == false) {
			cout << ListCheck[x].QuestN << "- " << ListCheck[x].description << endl <<" - " << ListCheck[x].Item;
			cout << " Amount: " << ListCheck[x].amountItem << endl;
			break;
		}
	}
	cout << "============================================================================" << endl;
	cout << "Side Quests" << endl;
	for (int x = 7; x < 18; x++) {
		if (ListCheck[x].givenTask == true && ListCheck[x].complete == false ) {
			cout << ListCheck[x].QuestN << "- " << ListCheck[x].description << " - " << ListCheck[x].Item << endl;
			cout << "Amount: " << ListCheck[x].amountItem << endl;
			cout << "--------------------------------------------------------------------" << endl;
		}
	}

	cout << "============================================================================" << endl;
}


//Maps Sections

/*Teleporation work as a form of going to different location in the world such only to those you have access too*/
void menuTeleport() {
	int choice;
	int y = 1;
	int x = 0;
	cout << endl;
	cout << "Teleportation Menu" << endl;
	cout << "============================================================================" << endl;
	for (x = 0; x < 8; x++) {
		if (LocationNames[x].AccessedLocation == true) { //if location is true then you it will display and you will have access to
			cout << x + 1 << "). "<< LocationNames[x].MapName << endl;
			y++; //checking how many locations you have
		}
	}
	cout << y << "). Exit Teleporation" << endl;
	cout << "============================================================================" << endl;
	cout << "Enter Choice: ";
	cin >> choice;
	while (choice > y || choice < 1) {
		cout << "Not a valid choice" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
	}

	if (choice != y) { //if choice isnt y then i remove 1 since its based on a array 
		Location = choice - 1;
	}
}

//Map displays the different location within each locationea each being 5 and using the Location 
int map(Bag *B, Player *T) { //Dispaly map
	int choice;
	cout << "|==============================|" << endl;
	cout << "|              Map             | Current Location: " << LocationNames[Location].MapName << endl;
	cout << "|==============================| 1). "<< LocationNames[Location].QuestGiven << endl;
	cout << "|_________|     5    |_________| 2). " << LocationNames[Location].Location1 << endl;
	cout << "|         |----------|         | 3). " << LocationNames[Location].Location2 << endl;
	cout << "|_________|----------|_________| 4). " << LocationNames[Location].Location3 << endl;
	cout << "|____3_____           ____4____| 5). " << LocationNames[Location].Location4 << endl;
	cout << "|____1_____     H     ____2____| 6). Exit" << endl;
	cout << "===============================|" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice > 6 || choice < 1) {
		cout << "Not a valid choice" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
	}

	switch (Location) {
	case 0:
		Kingdom1(choice, B, T);
		break;
	case 1:
		Slime(choice, B, T);
		break;
	case 2:
		Ruins(choice, T, B);
		break;
	case 3:
		Forest(choice, T, B);
		break;
	case 4:
		Nation(choice, T, B);
		break;
	case 5:
		Kingdom2(choice, T, B);
		break;
	case 6:
		Forest2(choice, T, B);
		break;
	case 7:
		DemonCastle(choice, T, B);
		break;
	}

	return choice;
}

//Some prompts
void SummonStory() {
	string dummy;
	cout << "Aqua the Goddess: Hello child, I have summon you to defeat the Demon King in the name of the Gods" << endl;
	cout << "                  In this world of monsters and humans, You have been choosen to be the Symbol of Protection" << endl;
	cout << "                  I understand this is sudden, but the people need you. Please make your way to the protal." << endl << endl;
	cout << "System: You are being teleported to the world!" << endl;
	cout << "Press Enter to continue...";
	cin.get();
	getline(cin, dummy);
}

//Introducing the king promp
void KingIntro(Player T) {
	string dummy;
	//Introduction Setting
	cout << "=====================================================" << endl;
	cout << "As you start you journey you see a nearby" << endl;
	cout << "Kindom, you step foot, but the guards stop" << endl;
	cout << "you from entering." << endl;
	cout << "=====================================================" << endl;
	cout << "Press Enter to continue...";
	getline(cin, dummy);
	cout << endl;
	cout << T.getName() << ": The goddess has" << endl;
	cout << "	sent me to defeat the Demon Lord" << endl;
	cout << "Guard: Oh your a summoned Hero, we had a few of your" << endl;
	cout << "	kind here before. Meet with the king Hero." << endl;
	cout << endl << "*You question what he has said as other were" << endl;
	cout << "	summoned before you wondering what happened*" << endl;
	cout << "=====================================================" << endl;
	cout << "Press Enter to continue...";
	getline(cin, dummy);
	cout << endl;
	cout << "As you entered the palace of the king, their several" << endl;
	cout << "guards protecting such as important man, making you" << endl;
	cout << "nervous. Then you see the door and enter" << endl;
	cout << "=====================================================" << endl;
	cout << "Press Enter to continue...";
	getline(cin, dummy);
	cout << endl;
	cout << T.getName() << ": Hello, sir I am here to aid " << endl;
	cout << "	during the battle of the Demon King. " << endl;
	cout << "King Lucian: Ah of course, but you need to demonstrate " << endl;
	cout << "	your strenght to me. Please defeat King Slime from the forest" << endl;
	cout << "	for me. This isnt a small task, but do your best" << endl;
	cout << "=====================================================" << endl;
	LocationNames[1].AccessedLocation = true;
}

//Main Quest given
void Kingdom1(int choice, Bag *B, Player *T) {
	string dummy;
	switch (choice) {
	case 1:
		cout << "======================================================" << endl;

		if (ListCheck[7].givenTask == false) {
			cout << "I'm Estevan the potion seller" << endl;
			cout << "I have a request for you young hero. Please" << endl;
			cout << "rescue my daugther. Il give you a reward" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Rescue Estevan's Daugther" << endl;
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			ListCheck[7].givenTask = true;
		}
		else if (B->ItemBoss[0] == 1 && ListCheck[7].givenTask == true && ListCheck[7].complete == false) {
			cout << "Thank you hero for saving my daugther" << endl;
			cout << "Here have this" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Coder Salary + 200 coins" << endl;
			cout << "Press Enter to continue...";
			B->EstevanDiscount = true;
			B->coins += 200;
			ListCheck[7].complete = true;
			cin.ignore();
			getline(cin, dummy);
		}
		cout << endl;
		cout << "Welcome to my shop im Estevan you're welcome to look around" << endl << "I sell different potions" << endl;

		B->shopPotion();

		break;
	case 2:
		cout << "Welcome to my shop im Reynol you're welcome to look around" << endl << "I mostly sell swords" << endl;

		B->shopWeapons(T);
		break;
	case 3:
		B->shopArmour(T);
		break;
	case 4:
		cout << "Joseph: Hello there hero, stay safe of your adventures!" << endl;
		cout << "Here take my old weapons" << endl;
		cout << "======================================================" << endl;
		cout << "NEW ITEM: Rusty Weapon +50" << endl;
		T->upgradeAttack(50);
	case 5:
		if (B->ItemBoss[0] == 1 && ListCheck[1].givenTask == false) {
			cout << "King Lucian: I see you have done well Hero. Thanks for bring me the " << endl;
			cout << "	Slime Crown. Now that i see your value, please collect the Ancient" << endl;
			cout << "	Golem Core for me" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			cout << endl;
			cout << T->getName() << ": Why am I getting this?" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;
			cout << "King Lucian: Its for a weapon to defeat the Demon King" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Technology Advances" << endl;
			LocationNames[2].AccessedLocation = true;
			ListCheck[1].givenTask = true;
			ListCheck[0].complete = true;
			
		}
		else if (B->ItemBoss[1] == 1 && ListCheck[2].givenTask == false) {
			cout << "King Lucian: Excellent work " << T->getName(); 
			cout << "	Your new mission is to help the Elves we are" << endl;
			cout << "	in contract with them to assist them and aswell" << endl;
			cout << "	as they assits us. They might give you something" << endl;
			cout << "	in return" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Help the Elves" << endl;
			ListCheck[2].givenTask = true;
			ListCheck[1].complete = true;
			LocationNames[3].AccessedLocation = true;
		}
		else if (B->ItemBoss[2] == 1 && ListCheck[3].givenTask == false) {
			cout << "King Lucian: Thanks for helping the elves" << endl;
			cout << "	now please go help the Dwarf with finalizing the" << endl;
			cout << "	weapons for the Demon king" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Drawf Weaponization" << endl;
			ListCheck[3].givenTask = true;
			ListCheck[2].complete = true;
			LocationNames[4].AccessedLocation = true;
		}
		else if (B->ItemBoss[3] == 1 && ListCheck[4].givenTask == false) {
			cout << "King Lucian: Im gald you were able to complete" << endl;
			cout << "	now hand over the weapon to my assistant" << endl;
			cout << "	since i have something to discuss with you about" << endl;
			cout << "	this task, but I have some issues to explain" << endl;
			cout << "	the Kingdom of Hinojosa doesnt trust our strength" << endl;
			cout << "	and teamwork to defeat the Demon King" << endl; 
			cout << "	I have seen your strength go represent us" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Conflict with another Nation" << endl;
			ListCheck[3].complete = true;
			ListCheck[4].givenTask = true;
			LocationNames[5].AccessedLocation = true;
		}
		else if (B->ItemBoss[4] == 1 && ListCheck[5].givenTask == false) {
			cout << "King Lucian: Thanks for representing us" << endl;
			cout << "	but I have bad news, the Ogres are attacking" << endl;
			cout << "	our villages, this must be the work for the Demon Lord" << endl;
			cout << "	please go save the people!" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Ogre Tribe Massacre" << endl;
			ListCheck[5].givenTask = true;
			ListCheck[4].complete = true;
			LocationNames[6].AccessedLocation = true;
		}
		else if (B->ItemBoss[5] == 1 && ListCheck[6].givenTask == false) {
			cout << "King Lucian: I see you have defeat the ogre" << endl;
			cout << "	this must be the doing of the Demon King we must" << endl;
			cout << "	defeat him immediatly please go and defeat him" << endl;
			cout << "======================================================" << endl;
			cout << endl;
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			cout << T->getName() <<": I understand, but i dont feel like im" << endl;
			cout << "	good enough to defeat him'" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;

			cout << "King Lucian: Have no fear, you would do great" << endl;
			cout << "======================================================" << endl;
			cout << "NEW MAIN QUEST: Defeat The Demon King" << endl;
			ListCheck[6].givenTask = true;
			ListCheck[5].complete = true;
			LocationNames[7].AccessedLocation = true;
		}
		else if (ListCheck[7].complete == true && B->ItemBoss[6] == 1) {
			cout << "King Lucian: Haha you have return great hero" << endl;
			cout << "	we must have a feast for the defeat of the king" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);
			cout << endl;
			cout << T->getName() << ": YOU MONSTER HOW COULD YOU DO THAT" << endl;
			cout << "	NOW EVERYTHING MAKES SENSE. WHY YOU WANTED ME TO" << endl;
			cout << "	YOU KILLED THE OTHER SUMMONED HERO AND USED ME AS A" << endl;
			cout << "	TOOL. SO YOU COULD DESTROY THE INNOCENT DEMONS" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;

			cout << "King Lucian: Child you do not understand THEIR DEMONS" << endl;
			cout << "	I did it to protect my people and expand my kingdom" << endl;
			cout << "	those to dont share the same ideology dont deserve" << endl;
			cout << "	to be apart of my kingdom. Such as you" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;
			
			cout << T->getName() << ": I WILL STOP YOU KING LUCIAN" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;
			cout << "King Lucian: Of course not, hahaha this is for the" << endl;
			cout << "	greater good. Guards kill the hero" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to continue...";
			getline(cin, dummy);
			cout << endl;

			cout << "As you are surrounder by the Guards, you massacre them one by one" << endl;
			cout << "but in the end you have died by backstabbed froma  random guard" << endl;
			cout << "you were tricked by corrupt humans, and fooled by the gods" << endl;
			cout << "Demons are known to be vile creatures yet these Demons" << endl;
			cout << "Were more humaine that the humans themself"<< endl;


			cout << endl << "The End." << endl;

		}
		else { cout << "Please continue to complete your quest" << endl;
		cout << "======================================================" << endl;
		}
		break;
	}
}

//Slimes Works Correct! Tests
//Information has access to different mobs fights and 1 quest giver
void Slime(int choice, Bag *B, Player *T) {
	string dummy;

	Monster *M;

	switch (choice) {
	case 1:
		if (ListCheck[8].givenTask == false) {
			cout << "Hello im Jimmy the anarchist" << endl;
			cout << "I am in need of 5 electric slimes for battle" << endl;
			cout << "would you mind getting some for me? Il give you this necklace" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Slime Gathering" << endl;
			ListCheck[8].givenTask = true;
		}
		else if (B->MosterDrop[2] >= 5 && ListCheck[8].givenTask == true && ListCheck[8].complete == false) {
			cout << "Thanks il use these slime to destroy a kingdom" << endl;
			cout << "I just dont like those castles" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Necklace of Attack - +100" << endl;
			T->upgradeAttack(100);
			B->MosterDrop[2] -= 5;
			ListCheck[8].complete = true;

		}
		else if (ListCheck[8].complete == false) {
			cout << "You dont have the items yet" << endl;
		}
		else {
			cout << "You have already completed my quest" << endl;
		}
		break;
	case 2:
		M = new Monster("Slime", "Acid", "Absorb", 100, 100, 200, 5, "Slime Essence");
		PlayerFighter(*T, *M, B, true, 0, -1);
		break;
	case 3:
		if (B->MosterDrop[0] >= 5 || LocationNames[1].L1 == true) {
			M = new Monster("Poison Slime", "Toxic", "Toxic Shot", 150, 150, 250, 10, "Poison Slime Essence");
			PlayerFighter(*T, *M, B, true, 1, -1);

			if (LocationNames[1].L1 == false) {
				B->MosterDrop[0] -= 5;
			}

			LocationNames[1].L1 = true;
		}
		else {
			cout << "You need 5 Slime Essence" << endl;
		}
		break;
	case 4:
		if (B->MosterDrop[1] >= 5 || LocationNames[1].L2 == true) {
			M = new Monster("Electric Slime", "Spark", "Electric Shot", 300, 100, 250, 15, "Electric Slime Essence");
			PlayerFighter(*T, *M, B, true, 2, -1);

			if (LocationNames[1].L2 == false) {
				B->MosterDrop[1] -= 5;
			}
			LocationNames[1].L2 = true;
		}
		else {
			cout << "You need 5 Poison Slime Essence" << endl;
		}
			break;
	case 5:
		if (B->MosterDrop[2] >= 5 && B->ItemBoss[0] == 0 || LocationNames[1].L3 == true && B->ItemBoss[0] == 0) {
			M = new Monster("Slime King", "Slimy Punch", "Combined Elements of Slime Attack", 600, 200, 300, 50, "Slime Crown");
			PlayerFighter(*T, *M, B, true, 0, 0);
			
			if(LocationNames[1].L3 == false){
				B->MosterDrop[2] -= 5;
			}

			if (B->ItemBoss[0] == 1) {
				cout << "Thanks for saving me Hero! The Slime King took me hostage" << endl;
			}

			LocationNames[1].L3 = true;
		}
		else if(B->ItemBoss[0] == 1){
			cout << "You have already defeat Slime King" << endl;
		}
		else {
			cout << "You need 5 Electric Slime Essence" << endl;
		}
		break;
		}
}

//Different mob fights and 1 quest giver
//Works Perfectly
void Ruins(int choice, Player *T, Bag *B) {
	string dummy;

	Monster *M;

	switch (choice) {
	case 1:
		if (ListCheck[9].givenTask == false) {
			cout << "Hello im " << LocationNames[2].QuestGiven << endl;
			cout << "I need 5 souls from the ghost for my new potions" << endl;
			cout << "Im to busy programming in anciet Java to get them myself" << endl;
			cout << "mind getting it for me?" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Weird Guy Request for souls" << endl;
			ListCheck[9].givenTask = true;
		}
		else if (B->MosterDrop[4] >= 5 && ListCheck[9].givenTask == true && ListCheck[9].complete == false) {
			cout << LocationNames[2].QuestGiven <<": Thanks for the souls" << endl;
			cout << "	Here is your payment" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Sword of the Java - +200 Attack" << endl;
			B->MosterDrop[4] -= 5;
			T->upgradeAttack(200);

			ListCheck[9].complete = true;
			cin.ignore();
			getline(cin, dummy);
		}
		else if (ListCheck[9].complete == false) {
			cout << "You havent gotten the items yet" << endl;
		}
		else {
			cout << "You have already completed my quest" << endl;
		}
		break;
	case 2:
		M = new Monster("Golem", "Rock Smash", "Cystalize Punch", 300, 120, 200, 20, "Core");
		PlayerFighter(*T, *M, B, true, 3, -1);
		break;
	case 3:
		if (B->MosterDrop[3] >= 5 || LocationNames[2].L1 == true) {
			M = new Monster("Ghost", "Life Extract", "Soul Punch", 300, 120, 250, 25, "Soul");
			PlayerFighter(*T, *M, B, true, 4, -1);

			if (LocationNames[2].L1 == false) {
				B->MosterDrop[3] -= 5;
			}

			LocationNames[2].L1 = true;
		}
		else {
			cout << "You need 5 Core" << endl;
		}
		break;
	case 4:
		if (B->MosterDrop[4] >= 5 || LocationNames[2].L2 == true) {
			M = new Monster("Undead", "Bite", "Sword Dance", 150, 300, 500, 30, "Skulls of Undead");
			PlayerFighter(*T, *M, B, true, 5, -1);

			if (LocationNames[2].L2 == false) {
				B->MosterDrop[4] -= 5;
			}

			LocationNames[2].L2 = true;
		}
		else {
			cout << "You need 5 Souls" << endl;
		}
		break;
	case 5:
		if (B->MosterDrop[5] >= 5 && B->ItemBoss[1] == 0 || LocationNames[2].L3 == true && B ->ItemBoss[1] == 0) {
			M = new Monster("Ancient Golem", "Hammer of the Ages", "Core Laser", 600, 500, 500, 50, "Ancient Core");
			PlayerFighter(*T, *M, B, true, 0, 1);

			if (LocationNames[2].L3 == false) {
				B->MosterDrop[5] -= 5;
			}

			LocationNames[2].L3 = true;
		}
		else if (B->ItemBoss[1] == 1) {
			cout << "You have already defeat the Ancient Golem" << endl;
		}
		else {
			cout << "You need 5 Skulls of Undead" << endl;
		}
		break;
	}
}

//Different mob fight and 1 quest giver
//Forest Works Correct! Tests
void Forest(int choice, Player *T, Bag *B) {
	string dummy;

	Monster *M;

	switch (choice) {
	case 1:
		if (ListCheck[10].givenTask == false) {
			cout << "Hello im " << LocationNames[3].QuestGiven << endl;
			cout << "Im a magic knight from a different kingdom, but i seem" << endl;
			cout << "to have lost my anti-magic sword, im useless without it" << endl;
			cout << "mind getting it for me?" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Missing Sword" << endl;
			ListCheck[10].givenTask = true;
		}
		else if (B->ItemBoss[2] == 1 && ListCheck[10].givenTask == true && ListCheck[10].complete == false) {
			cout << LocationNames[4].QuestGiven << ": Amazing you should be a" << endl;
			cout << "	Magic Knight, anyways here have this" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Five Leaf Black Clover +100 mana" << endl;
			T->upgradeMana(100);
			ListCheck[10].complete = true;
		}
		else if (ListCheck[10].complete == false) {
			cout << "You havent completed the task" << endl;
		}
		else {
			cout << "You have already completed my quest" << endl;
		}
		break;
	case 2:
		M = new Monster("Goblin", "Spear Attack", "Sneaky Surprise", 400, 420, 500, 40, "Goblin's Spears");
		PlayerFighter(*T, *M, B, true, 6, -1);
		break;
	case 3:
		if (B->MosterDrop[6] >= 5 || LocationNames[3].L1 == true) {
			M = new Monster("Wild Hogs", "Tusk Tackle", "Body Slam", 550, 320, 450, 50, "Hog's Skin");
			PlayerFighter(*T, *M, B, true, 7, -1);

			if (LocationNames[3].L1 == false) {
				B->MosterDrop[6] -= 5;
			}

			LocationNames[3].L1 = true;
		}
		else {
			cout << "You need 5 Goblin's Spears" << endl;
		}
		break;
	case 4:
		if (B->MosterDrop[7] >= 5 || LocationNames[3].L2 == true) {
			M = new Monster("Tornado Wolf", "Thunder Bite", "Tornado Manifestation", 700, 500, 700, 60, "Wolf's Fur");
			PlayerFighter(*T, *M, B, true, 8, -1);

			if (LocationNames[3].L2 == false) {
				B->MosterDrop[7] -= 5;
			}

			LocationNames[3].L2 = true;
		}
		else {
			cout << "You need 5 Hog's SKin" << endl;
		}
		break;
	case 5:
		if (B->MosterDrop[8] >= 5 && B->ItemBoss[2] == 0 || LocationNames[3].L3 == true && B->ItemBoss[2] == 0) {
			M = new Monster("Goblin Leader", "Stink Bombs", "Goblin Rush", 800, 800, 800, 200, "Random Sword");
			PlayerFighter(*T, *M, B, true, 0, 2);

			if (LocationNames[3].L3 == false) {
				B->MosterDrop[8] -= 5;
			}

			LocationNames[3].L3 = true;

		}
		else if (B->ItemBoss[2] == 1) {
			cout << "You have already defeat the Goblin Leader" << endl;
		}
		else {
			cout << "You need 5 Wolf's Fang" << endl;
		}
		break;
	}
}

//{"Dwarf Nation", "Chamy The Food Enjoyer", "Construction Center", "Dwarf Research", "Dwarf Hotel", "King Dwarf", false, false, false, false}, 5
//Works Completely correct
//Different mission the user has to complete
void Nation(int choice, Player *T, Bag *B) {
	string dummy;

	Monster *M;

	switch (choice) {
	case 1:
		if (ListCheck[11].givenTask == false) {
			cout << "Hello im " << LocationNames[4].QuestGiven << endl;
			cout << "Im super hungry can you please get me some ingredients" << endl;
			cout << "I have heart that slimes are pretty tasty to drink Yummy!" << endl;
			cout << "get me 20 Slime Essence" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Slime Desert" << endl;
			ListCheck[11].givenTask = true;
		}
		else if (B->MosterDrop[0] >= 20 && ListCheck[11].givenTask == true && ListCheck[11].complete == false) {
			cout << LocationNames[4].QuestGiven << ": Yummy! these are so tasty" << endl;
			cout << "	thanks " << T->getName() << " here have this" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Sugary Candy - + 200 attack" << endl;
			T->upgradeAttack(200);
			B->MosterDrop[0] -= 20;
			ListCheck[11].complete = true;
		}
		else if (ListCheck[11].givenTask == true && ListCheck[11].complete == false) {
			cout << LocationNames[4].QuestGiven << ": You havent gotten the items we need come agian" << endl;
			cout << "when you have them" << endl;
			cout << "======================================================" << endl;

		}
		else {
			cout << "You have already completed my quest" << endl;

		}
		break;
	case 2:
		cout << B->MosterDrop[2] << endl;
		if (ListCheck[12].givenTask == false) {
			cout << "Hello there hero. I see your from the Kingdom of Lucian" << endl;
			cout << "	We're the Construction Center where we build the weapon" << endl;
			cout << "	Currently we're in need of 20 Electric Slimes to power" << endl;
			cout << "	weapon" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Shocking Experience" << endl;

			ListCheck[12].givenTask = true;
		}
		else if (B->MosterDrop[2] >= 20 && ListCheck[12].complete == false) {
			cout << "Thanks for the Electric Slime we're sure to complete it" << endl;
			cout << "	As a payment here have this" << endl;
			cout << "======================================================" << endl;
			cout << "Coin Gained: +500" << endl;
			B->coins += 500;
			B->MosterDrop[2] -= 20;

			ListCheck[12].complete = true;
		}
		else if (ListCheck[12].givenTask == true && ListCheck[12].complete == false) {
			cout << "Worker: You havent gotten the items we need come agian" << endl;
			cout << "when you have them" << endl;
			cout << "======================================================" << endl;

		}
		else {
			cout << "You have already completed this task" << endl;
			cout << "======================================================" << endl;
		}

		break;
	case 3:
		if (ListCheck[13].givenTask == false) {
			cout << "Hero! a great honor to see a summoned hero here, I see  you're" << endl;
			cout << "	from the Kingdom of Lucian, we're the Drawf Research Team" << endl;
			cout << "	We're looking into the Golems currently and how they work" << endl;
			cout << "	Mind Getting us 20 Golem Cores?" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Return to the Past" << endl;

			ListCheck[13].givenTask = true;
		}
		else if (B->MosterDrop[3] >= 20 && ListCheck[13].complete == false) {
			cout << "Worker: Thanks hero, maybe next time you come here" << endl;
			cout << "	mind if we experiment with your body its quite fascinating" << endl;
			cout << "	to see a summoned hero once in a while" << endl;
			cout << "	As a payment here have this" << endl;
			cout << "======================================================" << endl;
			cout << "Coin Gained: +500" << endl;
			B->coins += 500;
			B->ItemBoss[3] -= 20;

			ListCheck[13].complete = true;
		}
		else if (ListCheck[13].givenTask == true && ListCheck[13].complete == false) {
			cout << "Worker: You havent completed the task!" << endl;
			cout << "======================================================" << endl;

		}
		else {
			cout << "You have already completed this task" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 4:
		if (ListCheck[14].givenTask == false) {
			cout << "Well Hello there hero. As you can see this is the finest hotel" << endl;
			cout << "	in the Dwarf nation even King Lucian himself stayed here once" << endl;
			cout << "	we are missing some fabric mind getting this for us?" << endl;
			cout << "	Mind getting us 20 Tornado Wolf Fur?" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: To the Fur" << endl;

			ListCheck[14].givenTask = true;
		}
		else if (B->MosterDrop[8] >= 20 && ListCheck[14].complete == false) {
			cout << "Worker: Amazing well done Hero" << endl;
			cout << "	next time you come, we will give you a room just for" << endl;
			cout << "	you" << endl;
			cout << "======================================================" << endl;
			cout << "Coin Gained: +500" << endl;
			B->ItemBoss[8] -= 20;
			B->coins += 500;

			ListCheck[14].complete = true;
		}
		else if (ListCheck[14].givenTask == true && ListCheck[14].complete == false) {
			cout << "Worker: You havent completed the task!" << endl;
			cout << "======================================================" << endl;

		}
		else {
			cout << "You have already completed this task" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 5:
		if (ListCheck[12].complete == true && ListCheck[13].complete == true && ListCheck[14].complete == true && ListCheck[3].complete == false) {
			cout << "King Dwarf: Nice to finally meet the hero that has helped" << endl;
			cout << "	my people, I have already informed the king about your" << endl;
			cout << "	assistance. My workers as also finished the weapon, here!" << endl;
			cout << "===========================================================" << endl;
			cout << "You were given a destructive cannon, and oddly fits in your bag" << endl;
			cout << "Press Enter to continue...";
			cin.ignore();
			getline(cin, dummy);

			cout << endl << "King Dwarf: Please return to your king and stay safe" << endl;
			cout << "===========================================================" << endl;
			B->ItemBoss[3] = 1;
		}
		else if (ListCheck[12].complete == false || ListCheck[13].complete == false || ListCheck[14].complete == false) {
			cout << T->getName() << ": Mayde I should help the dwarf first" << endl;
			cout << "before I meet their king." << endl;
			cout << "===========================================================" << endl;
		}
		break;
	}
}
//Works Completely fine
void Kingdom2(int choice, Player *T, Bag *B) {
		string dummy;

		Monster *M;

		int choice2;
		switch (choice) {
		case 1:
			if (ListCheck[4].complete == true) {
				if (ListCheck[16].givenTask == false && ListCheck[4].complete == true) {
					cout << "Hello im " << LocationNames[5].QuestGiven << endl;
					cout << "Im quite lost and recently got robbed, mind finding my wallet?" << endl;
					cout << "======================================================" << endl;
					cout << "NEW SIDE QUEST: Robbed Man" << endl;
					ListCheck[16].givenTask = true;
				}
				else if (B->wallet == true && ListCheck[16].givenTask == true && ListCheck[16].complete == false) {
					cout << LocationNames[5].QuestGiven << ": Thank you" << endl;
					cout << "	have this! Its not much, but I got nothing" << endl;
					cout << "======================================================" << endl;
					cout << "NEW ITEM: Half Eaten Hamburger - + 200 Health" << endl;
					T->upgradeHealth(200);
					ListCheck[16].complete = true;
				}
				else if (ListCheck[16].givenTask == true && ListCheck[16].complete == false && B->wallet == false) {
					cout << "You have already completed my quest" << endl;
				}
				else {
					cout << "Please continue to look for my wallet" << endl;
					cout << "======================================================" << endl;
				}
			}
			else {
				cout << "Please Complete your mission" << endl;
				cout << "======================================================" << endl;

			}
			break;
		case 2:
			if (ListCheck[4].complete == true) {
				cout << "Training Ground" << endl;
				cout << "======================================================" << endl;
				cout << "1). Training Dummy" << endl;
				cout << "2). Train with Enrique" << endl;
				cout << "3). Exit" << endl;
				cout << "======================================================" << endl;
				cout << "Enter Choice: ";
				cin >> choice2;

				while (choice2 > 3 || choice2 < 1) {
					cout << "Enter Choice: ";
					cin >> choice2;
				}
				switch (choice2) {
				case 1:
					M = new Monster("Dummy", "None", "None", 4000, 0, 0, 0, "None");
					PlayerFighter(*T, *M, B, true, 13, -1);
					B->MosterDrop[13] -= 1;
					break;
				case 2:
					M = new Monster("Enrique", "Water Sword Dance", "Phase 3 Moon Slash", 4000, 2000, 4000, 0, "None");
					PlayerFighter(*T, *M, B, true, 12, -1);
					B->MosterDrop[12] -= 1;
					break;
				case 3:
					cout << "Exiting" << endl;
				}

			}
			else {
				cout << "Please Complete your mission" << endl;
				cout << "======================================================" << endl;

			}

			break;
		case 3:
			if (ListCheck[4].complete == true) {
				cout << "Enrique: Hello there " << T->getName() << endl;
				cout << "Il be in the training ground if you wanna to battle" << endl;
				cout << "======================================================" << endl;
			}
			else {
				cout << "Enrique: Get Lost weakling" << endl;
				cout << "======================================================" << endl;
			}
			break;
		case 4:
			if (ListCheck[4].complete == true) {

				if (B->wallet == false) {
					cout << "Hey look a wallet" << endl;
					cout << "======================================================" << endl;
					cout << "Press Enter to continue...";
					B->wallet = true;
					cin.ignore();
					getline(cin, dummy);
				}

				cout << "Ramen Shop" << endl;
				cout << "Price For each Ramen - 300 coins" << endl;
				cout << "======================================================" << endl;
				cout << "1). Naruto Ramen - +10 Attack" << endl;
				cout << "2). Sasuke Ramen - +10 Health" << endl;
				cout << "3). Sakura Ramen - +10 Mana" << endl;
				cout << "4). Exit Shop" << endl;
				cout << "======================================================" << endl;
				cout << "Enter Choice: ";
				cin >> choice2;

				while (choice2 > 4 || choice2 < 1) {
					cout << "Enter Choice: ";
					cin >> choice2;
				}
				if (B->coins >= 300 && choice2 != 4) {
					switch (choice2) {
					case 1:
						cout << "Yummy! Naruto Ramen increase my attack" << endl;
						T->upgradeAttack(10);
						break;
					case 2:
						cout << "A little bit left the village but its okay" << endl;
						cout << "Increased my health" << endl;
						T->upgradeHealth(10);
						break;
					case 3:
						cout << "A little tastless, but it increased my mana" << endl;
						T->upgradeMana(10);
						break;
					}
				}
				else if (choice2 == 4) {
					cout << "Exiting Shop" << endl;
				}
			}
			else {
				cout << "Please Complete your mission" << endl;
			}
			cout << "======================================================" << endl;
			break;
		case 5:
			if (ListCheck[4].complete != true) {
				cout << "King Nicholas: Welcome hero, I see King Lucian has sent you" << endl;
				cout << "	I might explain this to you summoned Hero since you're" << endl;
				cout << "	new to the world, but I dont trust the king you serve" << endl;
				cout << "	he is corrupt with power, I am just warning you" << endl;
				cout << "	I will still co-operate to defeat the Demon King" << endl;
				cout << "	but please demonstrate your strength here and now" << endl;
				cout << "	against my highest ranking soldier Enrique the Water" << endl;
				cout << "	Style swordman." << endl;
				cout << "======================================================" << endl;
				cout << "Press Enter to continue...";
				cin.ignore();
				getline(cin, dummy);
				cout << endl << "Enrique: Hello weakling demonstrate me your strength here and now" << endl;
				cout << "	Of course im to powerful so you wouldnt stand a chance" << endl;
				cout << "	il try my best right now and see your defeat" << endl;
				cout << "======================================================" << endl;
				cout << "Press Enter to continue...";
				getline(cin, dummy);
				cout << T->getName() << ": Alright, but I wont be defeat that easily" << endl;
				cout << "	Sir Enrique, il rival you and even demolish your skills" << endl;
				cout << "======================================================" << endl;
				cout << "Enrique: That what I like to hear haha" << endl;
				cout << "======================================================" << endl;
				cout << "Press Enter to continue...";
				getline(cin, dummy);
				
				M = new Monster("Enrique", "Water Sword Dance", "Phase 3 Moon Slash", 4000, 1000, 2000, 2000, "None");
				PlayerFighter(*T, *M, B, true, 0, 4);
				if (B->ItemBoss[4] == 1) {
					cout << "Enrique: Amazing you're skills are out of this world" << endl;
					cout << "	next time we fight I might not go as easy as you" << endl;
					cout << "	today." << endl;
					cout << "======================================================" << endl;
					cout << "Press Enter to continue...";
					cin.ignore();
					getline(cin, dummy);

					cout << "King Nicholas: Indeed your strength is even greater of " << endl;
					cout << "	the previous summoned heroes. May you lead us to victory" << endl;
					cout << "	hero." << endl;
					cout << "======================================================" << endl;
					ListCheck[4].complete = true;
				}
				else {
					cout << "Better Luck Next time weakling" << endl;
				}
			}
			else {
				cout << "You have already completed the task" << endl;
				cout << "======================================================" << endl;
				cout << "Press Enter to continue...";

			}
			break;
		}
}
//{"Kaprak Forest", "Yoshi the Forest Keeper", "Ogre", "Fire Slime", "Giant Snakes", "Ogre Leader", false, false, false, false},
//Works completely good
void Forest2(int choice, Player *T, Bag *B) {
	string dummy;

	Monster *M;

	switch (choice) {
	case 1:
		if (ListCheck[15].givenTask == false) {
			cout << "Hello im " << LocationNames[6].QuestGiven << endl;
			cout << "nice to meet you, someone took baby mario" << endl;
			cout << "this must be the doing of the ogre leader" << endl;
			cout << "can you please get him, im to weak to do it" << endl;
			cout << "======================================================" << endl;
			cout << "NEW SIDE QUEST: Save the Baby" << endl;
			ListCheck[16].givenTask = true;
		}
		else if (B->ItemBoss[5] == 1 && ListCheck[15].givenTask == true && ListCheck[15].complete == false) {
			cout << LocationNames[6].QuestGiven << ": YAHOOOOOOOOO" << endl;
			cout << "	Thank you, thank you very much here have this" << endl;
			cout << "======================================================" << endl;
			cout << "NEW ITEM: Yoshi Egg Necklace - +100 mana" << endl;
			T->upgradeMana(100);

			ListCheck[15].complete = true;
		}
		else {
			cout << "You have already completed my quest" << endl;
		}
		break;
	case 2:
		M = new Monster("Ogre", "Ogre Toss", "Demonic Ogre Rage", 5000, 1700, 2000, 500, "Ogre Skulls");
		PlayerFighter(*T, *M, B, true, 9, -1);
		break;
	case 3:
		if (B->MosterDrop[9] >= 5 || LocationNames[6].L1 == true) {
			M = new Monster("Fire Slime", "Fire Spit", "Fire Ball", 5100, 1800, 2000, 500, "Fire Slime Essence");
			PlayerFighter(*T, *M, B, true, 10, -1);

			if (LocationNames[6].L1 == false) {
				B->MosterDrop[9] -= 5;
			}

			LocationNames[6].L1 = true;
		}
		else {
			cout << "You need 5 Ogre Skulls" << endl;
		}
		break;
	case 4:
		if (B->MosterDrop[10] >= 5 || LocationNames[6].L2 == true) {
			M = new Monster("Giant Snake", "Venom Strike", "Strangle", 5200, 1900, 2000, 600, "Snake's Fang");
			PlayerFighter(*T, *M, B, true, 11, -1);
			if (LocationNames[6].L2 == false) {
				B->MosterDrop[10] -= 5;
			}
			LocationNames[6].L2 = true;
		}
		else {
			cout << "You need 5 Fire Slime Essence" << endl;
		}
		break;
	case 5:
		if (B->MosterDrop[11] >= 5 && B->ItemBoss[5] == 0 || LocationNames[6].L3 == true && B->ItemBoss[5] == 0) {
			M = new Monster("Ogre Leader", "Demonic Slash", "Ogre Bloodline Stomp", 6000, 2000, 3000, 2000, "Baby Mario");
			PlayerFighter(*T, *M, B, true, 0, 5);

			if (LocationNames[6].L3 == false) {
				B->MosterDrop[11] -= 5;
			}

			LocationNames[6].L3 = true;
		}
		else if (B->ItemBoss[5] == 1) {
			cout << "You have already defeat the Ogre Leader" << endl;
		}
		else {
			cout << "You need 5 Snake's Fang" << endl;
		}
		break;
	}
}
//Works Completely good
//All the Demon fights
void DemonCastle(int choice, Player *T, Bag *B) {
	string dummy;
	Monster *M;
	switch (choice) {
	case 1:
		if (B->MosterDrop[14] != 1) {
			cout << "General Lucifer: He He He, Hello hero I see you're here" << endl;
			cout << "	to defeat my king, but you shall never pass ahead" << endl;
			cout << "	He He He, battle me for the Key Hero" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			cin.ignore();
			getline(cin, dummy);
			M = new Monster("General Lucifer", "Aura of Darkness", "Dream Control", 4000, 4000, 4500, 4000, "Key 1");
			PlayerFighter(*T, *M, B, true, 14, -1);

			if (B->MosterDrop[14] == 1) {
				LocationNames[7].L1 = true;
			}
		}
		else if (B->MosterDrop[14] == 1 && LocationNames[7].L1 == true) {
			cout << "General Lucifer: He He He, get lost you already defeated me" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 2:
		if (B->MosterDrop[15] != 1 && LocationNames[7].L1 == true) {
			cout << "General Abaddon: I shall introduce myself, I am the " << endl;
			cout << "	keeper of the second gate. I shall not let you pass" << endl;
			cout << "	to my kind king. " << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			cin.ignore();
			getline(cin, dummy);
			M = new Monster("General Abaddon", "Gravitational Pull", "Black Whole", 4500, 4500, 5000, 5000, "Key 2");
			PlayerFighter(*T, *M, B, true, 15, -1);
			if (B->MosterDrop[15] == 1) {
				cout << "General Abaddon: Here have my key, but please be careful hero" << endl;
				cout << "======================================================" << endl;
				LocationNames[7].L2 = true;
			}
		}
		else if (LocationNames[7].L1 == false) {
			cout << T->getName() << ": Wait I need a key" << endl;
			cout << "======================================================" << endl;
		}
		else if (B->MosterDrop[15] == 1) {
			cout << "General Abaddon: You have already defeated me, do as you please" << endl;
			cout << "	but please consider my king is a very kind individual" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 3:
		if (B->MosterDrop[16] != 1 && LocationNames[7].L2 == true) {
			cout << "General Mormo: A hero? I never seen one in this level " << endl;
			cout << "	what a drag, why cant I just give you the key" << endl;
			cout << "	but I gotta pay respect to my kind king" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			cin.ignore();
			getline(cin, dummy);
			M = new Monster("General Mormo", "Soul Ripper", "Absolute Darkness", 6000, 7000, 75000, 10000, "Key 3");
			PlayerFighter(*T, *M, B, true, 16, -1);
			if (B->MosterDrop[16] == 1) {
				cout << "General Mormo:  Guess il go to sleep now" << endl;
				cout << "======================================================" << endl;
				LocationNames[7].L3 = true;
			}

			
		}
		else if (LocationNames[7].L2 == false) {
			cout << T->getName() << ": Wait I need a key" << endl;
			cout << "======================================================" << endl;
		}
		else if (B->MosterDrop[16] == 1) {
			cout << "General Mormo: Let me sleep" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 4:
		if (B->MosterDrop[17] != 1 && LocationNames[7].L3 == true) {
			cout << "General Satan: Hello their mortal, you dare challenge" << endl;
			cout << "	me. Pathetic, il show you true power of a General" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			cin.ignore();
			getline(cin, dummy);
			M = new Monster("General Satan", "Taunts of the Devil", "Devil Deal", 9000, 8500, 9000, 30000, "Key 4");
			PlayerFighter(*T, *M, B, true, 17, -1);
			if (B->MosterDrop[17] == 1) {
				cout << "General Satan:  IMPOSSIBLE IM THE STRONGEST HERE! HERE" << endl;
				cout << "	GET LOST" << endl;
				cout << "======================================================" << endl;
			}

			
		}
		else if (LocationNames[7].L3 == false) {
			cout << T->getName() << ": Wait I need a key" << endl;
			cout << "======================================================" << endl;
		}
		else if (B->MosterDrop[17] == 1) {
			cout << "General Satan: Get lost, im thinking of a plan to overtake" << endl;
			cout << "the King" << endl;
			cout << "======================================================" << endl;
		}
		break;
	case 5:
		if (B->MosterDrop[17] == 1 && B->MosterDrop[16] >= 1 && B->MosterDrop[15] >= 1 && B->MosterDrop[14] >= 1 && ListCheck[6].complete == false) {
			cout << "King Liebe: Ke Ke Ke, We finally meet, Prophet" << endl;
			cout << "	I see you have come to defeat me. But I wont give up" << endl;
			cout << "	and il protect my people for your corrupted people" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			cin.ignore();
			getline(cin, dummy);

			cout << T->getName() << ": *Thinking* What does he mean" << endl;
			cout << "	Speaking: Il slay you right here and now devil" << endl;
			cout << "======================================================" << endl;
			cout << "Press Enter to Continue..." << endl;
			getline(cin, dummy);

			M = new Monster("King Leibe", "Dimentional Aura", "Anti-Magic Pulvurizer", 12000, 10000, 11000, 100000, "None");
			PlayerFighter(*T, *M, B, true, 0, 6);
			
			if (B->ItemBoss[6] == 1) {
				cout << T->getName() << ": I killed the Demon King, I shall return" << endl;
				cout << "	to king Lucian, but i feel guilty somehow" << endl;
				cout << "======================================================" << endl;
				cout << "Press Enter to Continue..." << endl;
				getline(cin, dummy);
				cout << "As you leave the kingdom of devils you see a shining light" << endl;
				cout << "	destroying the kingdom of the devil" << endl;
				cout << "	you realize the mistake you have made" << endl;
				cout << "	and return in a hurry to the Kingdom of Lucian" << endl;
				cout << "======================================================" << endl;

				ListCheck[6].complete = true;
			}
			else {
				cout << "Better Luck Next Time" << endl;
				cout << "======================================================" << endl;
			}
		}
		else if (B->MosterDrop[17] != 1 && ListCheck[6].complete == false|| B->MosterDrop[16] != 1 && ListCheck[6].complete == false || B->MosterDrop[15] != 1 && ListCheck[6].complete == false || B->MosterDrop[14] != 1 && ListCheck[6].complete == false) {
			cout << T->getName() << ": Wait I need the 4 keys" << endl;
			cout << "======================================================" << endl;
		}
		else {
			cout << "You have already defeat the Demon King Leibe" << endl;
		}
		break;
	}
}
//Saves information by going 1 by 1 from each file Player, Bag and locations and adding them to the file
void Save(Bag *B, Player *T) {
	ofstream file;

	int choice;
	cout << "Are you sure? 1/ Yes, 2/No" << endl;
	cout << "Enter Choice: ";
	cin >> choice;

	while (choice < 1 || choice > 2) {
		cout << "Choice not within range" << endl;
		cout << "Are you sure? 1/ Yes, 2/No" << endl;
		cout << "Enter Choice:" << endl;
		cin >> choice;
	}

	if (choice == 1) {
		file.open("Save.txt");
		file << "99999";
		file << endl;
		file << T->getName();
		file << endl;
		file << T->getTitle();
		file << endl;
		file << T->getNAttack();
		file << endl;
		file << T->getUAttack();
		file << endl;
		file << T->getAttack();
		file << endl;
		file << T->getHealth();
		file << endl;
		file << T->getMana();
		file << endl;
		file << T->getManaUAttack();
		file << endl;
		file << T->getUltimate();
		file << endl;
		file << B->coins;
		file << endl;
		file << B->SHP;
		file << endl;
		file << B->MHP;
		file << endl;
		file << B->LHP;
		file << endl;
		file << B->SMP;
		file << endl;
		file << B->MMP;
		file << endl;
		file << B->LMP;
		file << endl;
		file << B->strengthPotion;
		file << endl;
		for (int x = 0;x < 8;x++) {
			file << B->ItemBoss[x];
			file << endl;
		}
		for (int x = 0; x < 18;x++) {
			file << B->MosterDrop[x];
			file << endl;
		}
		file << B->wallet;
		file << endl;
		for (int x = 0; x < 14;x++) {
			file << B->WA1[x];
			file << endl;
		}
		file << B->EstevanDiscount;
		file << endl;

		for (int x = 0; x < 8; x++) {
			file << LocationNames[x].L1;
			file << endl;
			file << LocationNames[x].L2;
			file << endl;
			file << LocationNames[x].L3;
			file << endl;
			file << LocationNames[x].AccessedLocation;
			file << endl;
		}
		for (int x = 0; x < 18;x++) {
			file << ListCheck[x].complete;
			file << endl;
			file << ListCheck[x].givenTask;
			file << endl;
		}
		file.close();
	}
	else {
		return;
	}
}

//Spits out the information and transfer them to their correcsponding spots
void Load(Bag *B, Player *T) {
	ifstream file;
	int Test;

	string s;
	int t;
		file.open("Save.txt");
		file >> Test;

		if (Test == -9999) {
			cout << "No Saved Data here" << endl;
			file.close();
			return;
		}

		file >> s;
		T->setName(s);
		
		file >> s;
		
		T->setTitle(s);

		file >> s;
		T->setNAttack(s);
		
		file >> s;
		T->setUAttack(s);
		file >> t;
		T->setAttack(t);
		file >> t;
		T->setHealth(t);
			
		file >> t;
		T->setMana(t);
			
		file >> t;
		T->setManaUAttack(t);
		file >> t;
		T->setUltimate(t);
		file >> B->coins;
		file >> B->SHP;
		file >> B->MHP;
		file >> B->LHP;
		file >> B->SMP;
		file >> B->MMP;
		file >> B->LMP;
		file >> B->strengthPotion;
		for (int x = 0;x < 8;x++) {
			file >> B->ItemBoss[x];
		}
		for (int x = 0; x < 18;x++) {
			file >> B->MosterDrop[x];
		}
		file >> B->wallet;
		for (int x = 0; x < 14;x++) {
			file >> B->WA1[x];
		}
		file >> B->EstevanDiscount;

		for (int x = 0; x < 8; x++) {
			file >> LocationNames[x].L1;
			file >> LocationNames[x].L2;
			file >> LocationNames[x].L3;
			file >> LocationNames[x].AccessedLocation;
		}
		for (int x = 0; x < 18;x++) {
			file >> ListCheck[x].complete;
			file >> ListCheck[x].givenTask;
		}
		file.close();
	}
