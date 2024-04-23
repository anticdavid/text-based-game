
#include "KnightSpace.h"
#include <cstdlib>

KnightSpace::KnightSpace()
{
	failedPersuade = 0; //number of failed persuades
	persuaded = 0; //number of successful persuades 
	honorableAnswers = 0; //number of honorable answers
	this->checked = false;
	this->isCleared = false;
	this->skipable = false; //this room cannot be left without completing the challenge
}


KnightSpace::~KnightSpace()
{
}

void KnightSpace::challenge()
{
	description();
	while (!isCleared) { //while room is not cleared
		cout << "You spot the knight standing in front of you. Even though he is old,"; //printing challenge and first question
		cout << " he still looks strong. He wants to have a chat with you" << endl;
		cout << "________________________________________________" << endl;
		cout << "First question: You found bag of coins in tavern. What do you do?" << endl;
		cout << "______________________________" << endl;
		cout << "\t(1) Ask innkeeper if he knows whose money it is" << endl;
		cout << "\t(2) Keep money for yourself" << endl;
		cout << "\t(3) Split the money with you (persuade)" << endl;
		cout << "________________________________________________" << endl;
		answer = readNumber(); //reading answer
		while (answer < 1 || answer>3) { //making sure that the number is 1,2 or 3
			cout << "Please insert number 1, 2 or 3" << endl;
			answer = readNumber();
		}
		if (answer == 1) { honorableAnswers++; } //if answer is 1, raise number of honorable answers
		if (answer == 3) { //if player tried to persuade knight
			if (randChance(2)) { //one in a two chance of successful persuasion
				persuaded++; //incrementing number of successful persuasions
			}
			else {
				failedPersuade++; //incrementing number of failed persuasions
			}
		}
		cout << "________________________________________________" << endl; //same as first question
		cout << "Okay, next question." << endl;
		cout << "A beggar asks you for money. What do you do?" << endl;
		cout << "______________________________" << endl;
		cout << "\t(1) I just walk by. I don't care about him" << endl;
		cout << "\t(2) Give him 5 coins, he seems hungry" << endl;
		cout << "\t(3) I don't give him anything, we could go for a beer instead (persuade)" << endl;
		cout << "________________________________________________" << endl;
		answer = readNumber();
		while (answer < 1 || answer>3) { //while the number user input is wrong
			cout << "Please insert number 1, 2 or 3" << endl;
			answer = readNumber();
		}
		if (answer == 2) { honorableAnswers++; } //answer 2 is honorable answer
		if (answer == 3) { //answer 3 is persuasion
			if (randChance(2 + failedPersuade)) { //if player failed to persuade knight the first time, he is more likely to fail second time
				persuaded++; //incrementing number of successful persuasions
			}
			else {
				failedPersuade++;//incrementing number of failed persuasions
			}
		}
		cout << "________________________________________________" << endl; //same as previous two
		cout << "Final question." << endl;
		cout << "You see a bandit attacking innocent villagers. What do you do?" << endl;
		cout << "______________________________" << endl;
		cout << "\t(1) Join him in attacking, there might be some good loot (persuade)" << endl;
		cout << "\t(2) I pretend like I don't notice that" << endl;
		cout << "\t(3) I try to protect them" << endl;
		cout << "________________________________________________" << endl;
		answer = readNumber();
		while (answer < 1 || answer>3) { //while number player input is wrong
			cout << "Please insert number 1, 2 or 3" << endl;
			answer = readNumber();
		}
		if (answer == 3) { honorableAnswers++; } //answer 3 is honorable answer
		if (answer == 1) {
			if (randChance(2 + failedPersuade)) { //once again, more failed persuasions, less likely to persuade now
				persuaded++; //incrementing number of successful persuasions
			}
			else {
				failedPersuade++; //incrementing number of failed persuasions
			}
		}
		if (failedPersuade == 3) { //if player failed to persuade knight all three times
			cout << "Knight is angry at you, and he slashes you with his sword." << endl;
			Player::healthBuff(-50); //player loses 50hp
			if (Player::hp > 0) {  //if player managed to survive attack
				cout << "Still, he has no intent of fighting you, since he thinks you're not worthy of his blade." << endl;
				Player::gainXP(30); //gain 30xp
			}
			else {
				Player::alive = false; //otherwise, player is dead
			}

		}
		else
			if (persuaded >= 2) { //if player successfully persuaded knight
				cout << "Knight smirks at you. He gives you his blade" << endl;
				Player::bag->addItem(new DarkKnightBlade()); //give player knight's blade
				Player::gainXP(40); //player gains 40xp
			}
			else
				if (honorableAnswers == 3) { //if player gave all 3 honorable answers
					cout << "Knight is proud of you. He gives you his spear" << endl;
					if (randChance(3)) { //he has 1 in 3 chance of getting enchantment
						cout << "You got enchantment: Knight's honor. +5 Attack" << endl;
						Player::atk += 5;
					}
					Player::bag->addItem(new KnightsSpear()); //and he gets knight's spear
					Player::gainXP(40); //player gains 40xp
				}
				else {
					Player::gainXP(30);//otherwise, player just gains 30xp
					if (randChance(3)) { //and he has 1 in 3 chance of getting knight's spear
						cout << "Knight gives you his spear, saying he won't be needing it anymore." << endl;
						Player::bag->addItem(new KnightsSpear()); //give player item
					}
				}
				cout << "Knight says that you are free to roam this place, he won't be bothering you." <<

					endl;
				cleared(); //room is cleared
				skipable = true; //you can finally leave the room
	}
}

void KnightSpace::description() //space description
{
	if (isCleared) { 
		cout << "This space is already cleared. Proceed to next one..." << endl;
	}
	else {
		cout << "This is KnightSpace! Test your honor!" << endl;
	}
}

void KnightSpace::checkSurroundings(Bag * bag) //check surroundings for items
{
	if (!checked) { //player finds potion when checking this space
		cout << "You found potion! Do you want to place it in your bag? (y/n)" << endl;
		char ans = readChar();
		if (tolower(ans) == 'y') { //if player answers 'y' or 'Y'
			bag->addItem(new HealingPotion()); //place potion in bag
		}
		checked = true; //this room is now checked
	}
	else {
		cout << "You already checked this place." << endl;
	}
}
