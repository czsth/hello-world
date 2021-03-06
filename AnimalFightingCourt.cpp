#include <iostream>
#include <string>
using namespace std;

class Animal
{
	double AP, HP;
	string name;
public:
	void setAP(double aAP = 1){
		AP = aAP;
	}
	void setHP(double aHP = 100){
		HP = aHP;
	}
	void virtual attack(Animal * victim){
		victim->getHP() -= this->getAP();
		cout << getName() << " -> " << victim->getName() << "  " << getAP() << "!" << endl;
	}
	double getAP(){
		return AP;
	}
	string & getName(){
		return name;
	}
	double & getHP(){
		return HP;
	}
	void virtual die(){
		cout << getName() << " KO" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(){
		setHP(120);
		setAP(25);
		getName() = "Dog";
	}
};

class BK : public Animal
{
public:
	BK(){
		setHP(150);
		setAP(20);
		getName() = "BK";
	}
};

class Court
{
	Animal *p1, *p2;
	Animal *winner;
public:
	Court(Animal * aP1, Animal * aP2){
		p1 = aP1, p2 = aP2;
	}
	void printIntroduction(Animal * player1, Animal * player2){
		Animal * player[2] = {player1, player2};
		for(int i = 0; i < 2; i++){
			cout << "Player " << i + 1 << " : " << player[i]->getName() << endl;
			cout << "\t" << "HP : " << player[i]->getHP() << endl;
			cout << "\t" << "AP : " << player[i]->getAP() << endl;
			cout << endl;
		}
		cout << "GAME START!!!!!" << endl << endl;
	}
	void fight(){
		printIntroduction(p1, p2);
		for(int i = 1; p1->getHP() > 0 && p2->getHP() > 0; i++){
			cout << "Round " << i << " :" << endl;
			p1->attack(p2);
			if(p2->getHP() > 0){
				p2->attack(p1);
			}
			cout << p1->getName() << "-" << p1->getHP() << "\t" 
			<< p2->getName() << "-" << p2->getHP() << endl;
			cout << "------------------------" << endl;
		}
		if(p1->getHP() <= 0){
			p1->die();
			winner = p2;
		}
		if(p2->getHP() <= 0){
			p2->die();
			winner = p1;
		}
		cout << "The Winner Is : " << winner->getName() << endl;
	}
};

int main(int argc, char const *argv[])
{
	BK bk;
	Dog dog;

	Court court(&bk, &dog);
	court.fight();

	return 0;
}
