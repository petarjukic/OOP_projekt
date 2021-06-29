#ifndef Game_H
#define Game_H
#include"Player.h"
#include"Board.h"
#include<iostream>
#include<vector>

using namespace std;

class Game {
private:
	int broj_partija;
public:
	Game();

	vector<Player*> igrac;
	void SetPlayer(vector<Player*> igr) { igrac = igr; }
	void KolicinaPartija();
	void Igra();
	int ProvjeraRez(Board& pl);
	void ProvjeraPobj(int i, int j);
	
	~Game(){}
};
#endif