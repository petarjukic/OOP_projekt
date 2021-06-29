#include"Game.h"
#include"ComputerPlayer.h"
#include"Board.h"
#include<iostream>
#include<string>

using namespace std;

Game::Game()
{
	broj_partija = 0;
}

void Game::KolicinaPartija()
{
	int broj;
	do
	{
		cout << "odaberite koliko partija zelite odigrati" << endl;
		cin >> broj;
		broj_partija = broj;
	} while (broj <= 0);
}

int Game::ProvjeraRez(Board& pl)
{
	int brojacX = 0;
	int brojacO = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (pl.ploca[i][j] == 'X')
				++brojacX;
			if (pl.ploca[i][j] == 'O')
				++brojacO;
		}
		if (brojacX == 3)
			return 1;
		if (brojacO == 3)
			return 2;
		brojacO = 0;
		brojacX = 0;
	}
	if (pl.ploca[0][0] == 'X' && pl.ploca[1][0] == 'X' && pl.ploca[2][0] == 'X')
		return 1;
	else if (pl.ploca[0][0] == 'X' && pl.ploca[1][1] == 'X' && pl.ploca[2][2] == 'X')
		return 1;
	else if (pl.ploca[0][2] == 'X' && pl.ploca[1][1] == 'X' && pl.ploca[2][0] == 'X')
		return 1;
	else if (pl.ploca[0][2] == 'X' && pl.ploca[1][2] == 'X' && pl.ploca[2][2] == 'X')
		return 1;
	else if (pl.ploca[0][1] == 'X' && pl.ploca[1][1] == 'X' && pl.ploca[2][1] == 'X')
		return 1;

	if (pl.ploca[0][0] == 'O' && pl.ploca[1][0] == 'O' && pl.ploca[2][0] == 'O')
		return 2;
	else if (pl.ploca[0][0] == 'O' && pl.ploca[1][1] == 'O' && pl.ploca[2][2] == 'O')
		return 2;
	else if (pl.ploca[0][2] == 'O' && pl.ploca[1][1] == 'O' && pl.ploca[2][0] == 'O')
		return 2;
	else if (pl.ploca[0][2] == 'O' && pl.ploca[1][2] == 'O' && pl.ploca[2][2] == 'O')
		return 2;
	else if (pl.ploca[0][1] == 'O' && pl.ploca[1][1] == 'O' && pl.ploca[2][1] == 'O')
		return 2;

	if (pl.broj_znakova == 10)
		return 3;
	return 4;
}

void Game::ProvjeraPobj(int i, int j)
{
	cout << endl << endl << endl;
	if (igrac.size() == 2) {
		if (i > j)
			cout << "pobjednik je igrac1 " << igrac[0]->VratiIme() << endl;
		else if (i < j)
			cout << "pobjednik je igrac2 " << igrac[1]->VratiIme() << endl;
		else
			cout << "nerijeseno" << endl;
	}
	else {
		if (i > j)
			cout << "pobjednik je igrac1 " << igrac[0]->VratiIme() << endl;
		else if (i < j)
			cout << "racunalo je pobjednik " << endl;
		else
			cout << "nerijeseno" << endl;
	}
}

void Game::Igra()
{
	KolicinaPartija();
	Board pl;
	ComputerPlayer cmp;
	int br = broj_partija;

	while (broj_partija != 0) {
		pl.Ploca();
		while (true) {
			if (igrac.size() == 2) {
				pl.ploca = igrac[0]->PotezH(pl.ploca);
				pl.Ploca();

				if (ProvjeraRez(pl) == 1) {
					igrac[0]->broj_bodova++;
					ProvjeraPobj(igrac[0]->broj_bodova, igrac[1]->broj_bodova);
					pl.NovaPloca();
					break;
				}

				if (ProvjeraRez(pl) == 3) {
					ProvjeraPobj(igrac[0]->broj_bodova, igrac[1]->broj_bodova);
					pl.NovaPloca();
					break;
				}

				pl.ploca = igrac[1]->PotezH(pl.ploca);
				pl.Ploca();

				if (ProvjeraRez(pl) == 2) {
					igrac[1]->broj_bodova++;
					ProvjeraPobj(igrac[0]->broj_bodova, igrac[1]->broj_bodova);
					pl.NovaPloca();
					break;
				}

				if (ProvjeraRez(pl) == 3) {
					ProvjeraPobj(igrac[0]->broj_bodova, igrac[1]->broj_bodova);
					pl.NovaPloca();
					break;
				}
			}
			else {
				pl.ploca = igrac[0]->PotezH(pl.ploca);
				pl.Ploca();

				if (ProvjeraRez(pl) == 1) {
					igrac[0]->broj_bodova++;
					ProvjeraPobj(igrac[0]->broj_bodova, cmp.broj_bodova);
					pl.NovaPloca();
					break;
				}

				if (ProvjeraRez(pl) == 3) {
					ProvjeraPobj(igrac[0]->broj_bodova, cmp.broj_bodova);
					pl.NovaPloca();
					break;
				}

				pl.ploca = cmp.PotezC(pl.ploca);
				pl.Ploca();

				if (ProvjeraRez(pl) == 2) {
					cmp.broj_bodova++;
					ProvjeraPobj(igrac[0]->broj_bodova, cmp.broj_bodova);
					pl.NovaPloca();
					break;
				}

				if (ProvjeraRez(pl) == 3) {
					ProvjeraPobj(igrac[0]->broj_bodova, cmp.broj_bodova);
					pl.NovaPloca();
					break;
				}
			}
		}
		--broj_partija;
		pl.broj_znakova = 0;
	}

	if (igrac.size() == 2) {
		cout << endl << "nakon " << br << " odigranih rundi ";
		ProvjeraPobj(igrac[0]->broj_bodova, igrac[1]->broj_bodova);
	}

	else {
		cout << endl << "nakon odigranih " << br << " odigranih rundi ";
		ProvjeraPobj(igrac[0]->broj_bodova, cmp.broj_bodova);
	}
}