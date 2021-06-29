#include"ComputerPlayer.h"
#include<iostream>
#include<time.h>

using namespace std;

char** ComputerPlayer::PotezC(char** pot)
{
	srand(time(NULL));
	znak = 'O';

	int izbor_redak = (rand() % 3);
	int izbor_stupac = (rand() % 3);
	bool dozvoljeni_potez = false;

	while (!dozvoljeni_potez) {
		if (pot[izbor_redak][izbor_stupac] == 'X' || pot[izbor_redak][izbor_stupac] == 'O') {
			srand(time(NULL));
			izbor_redak = rand() % 3;
			izbor_stupac = rand() % 3;
		}

		else {
			pot[izbor_redak][izbor_stupac] = znak;
			dozvoljeni_potez = true;
		}
	}
	return pot;
}