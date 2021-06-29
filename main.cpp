#include"Player.h"
#include"HumanPlayer.h"
#include"ComputerPlayer.h"
#include"Game.h"
#include"Board.h"
#include<iostream>
#include <string>
#include<vector>

using namespace std;

void IgracKomp()
{
	vector<Player*> pl;
	string ime1;
	Game igra;
	cout << "unesite ime igraca1: " << endl;
	cin >> ime1;

	HumanPlayer igrac1(ime1);
	igrac1.znak = 'X';
	Player* p1 = &igrac1;

	pl.push_back(p1);
	igra.SetPlayer(pl);

	igra.Igra();
}

void DvaIgraca()
{
	Game igra;
	string ime1, ime2;
	vector<Player*> pl;

	cout << "unesite ime igraca1: " << endl;
	cin >> ime1;
	cout << "unesite ime igraca2: " << endl;
	cin >> ime2;

	HumanPlayer igrac1(ime1);
	igrac1.znak = 'X';
	HumanPlayer igrac2(ime2);
	igrac2.znak = 'O';
	Player* p1 = &igrac1;
	Player* p2 = &igrac2;
	pl.push_back(p1);
	pl.push_back(p2);

	igra.SetPlayer(pl);
	igra.Igra();
}

int main()
{
	int odabir;
	do
	{
		cout << "zelite li igrati protiv drugog igraca ili protiv racunala." <<
			"Ako zelite protiv igraca odaberite 2,\na ako zelite protiv racunala odaberite 1" << endl;
		cin >> odabir;
	} while (odabir > 2 && odabir <= 0);

	if (odabir == 2)
		DvaIgraca();
	else
		IgracKomp();
}