#include"HumanPlayer.h"
#include<iostream>

using namespace std;

char** HumanPlayer::PotezH(char** pot)
{
	int redak, stupac;
	bool dozvoljeni_potez = false;

	cout << endl << endl << "odaberite svoj potez" << endl << endl;

	while (!dozvoljeni_potez) {
		cout << "unesite zeljeni redak [0-2]" << endl;
		cin >> redak;

		cout << "unesite zeljeni stupac [0-2]" << endl;
		cin >> stupac;
		if ((stupac < 3 && stupac > -1) && (redak < 3 && redak > -1)) {
			if (pot[redak][stupac] == 'O' || pot[redak][stupac] == 'X') {
				cout << "unos nije moguc pokusaj ponovno na tom mjestu vec postoji znak" << endl;
			}
			else {
				pot[redak][stupac] = znak;
				dozvoljeni_potez = true;
			}
		}
		else {
			cout << "unesite druge koordinate jer trenutne nisu valjane" << endl;
		}
	}
	return pot;
}