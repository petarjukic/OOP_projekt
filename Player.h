#ifndef Player_H
#define Player_H
#include<iostream>

using namespace std;

class Player {
public:
	int broj_bodova;
	char znak;

	Player() { broj_bodova = 0; }

	virtual string VratiIme() = 0;
	virtual char** PotezH(char** pot) = 0;
	virtual char** PotezC(char** pot) = 0;

	virtual ~Player() {}
};
#endif