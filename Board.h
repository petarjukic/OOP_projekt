#ifndef Board_H
#define Board_H

using namespace std;

class Board {
public:
	int broj_znakova; //za provjeru je li ploca puna
	char** ploca;

	Board();
	void Ploca();
	void NovaPloca();
	~Board();
};
#endif