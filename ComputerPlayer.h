#ifndef ComputerPlayer_H
#define ComputerPlayer_H
#include"Player.h"
#include<iostream>
#include<string>


using namespace std;

class ComputerPlayer :public Player {
public:

	string VratiIme() { return ""; }
	char** PotezC(char** pot);
	char** PotezH(char** pot) { char** a{}; return a; }

};
#endif