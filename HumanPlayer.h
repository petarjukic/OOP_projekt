#ifndef HumanPlayer_H
#define HumanPlayer_H
#include"Player.h"
#include<iostream>
#include<string>

using namespace std;

class HumanPlayer :public Player {
private:
	string ime;
public:
	HumanPlayer(string i) { ime = i; }
	
	string VratiIme() { return ime; }
	char** PotezH(char** pot);
	char** PotezC(char** pot) { char** a{}; return a; }
	
	~HumanPlayer() { ime.clear(); }
};
#endif