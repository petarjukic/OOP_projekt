#include"Board.h"
#include<iostream>

using namespace std;

Board::Board()
{
	broj_znakova = 0;
	ploca = new char* [3];

	for (int i = 0; i < 3; ++i)
		ploca[i] = new char[3];

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			ploca[i][j] = ' ';
		}
	}
}

void Board::Ploca()
{
	cout << endl << endl << endl;
	++broj_znakova;

	for (int i = 0; i < 3; ++i) {
		cout << " ";
		for (int j = 0; j < 3; ++j) {

			cout << ploca[i][j];
			if (j == 2)
				continue;
			cout << " | ";
		}
		if (i == 2)
			continue;
		cout << endl << "___|___|___" << endl << "   |   |   " << endl;
	}
}

void Board::NovaPloca()
{
	char** novaploca;
	novaploca = new char* [3];
	for (int i = 0; i < 3; ++i) {
		novaploca[i] = new char[3];
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			novaploca[i][j] = ' ';
			ploca[i][j] = novaploca[i][j];
		}
	}
	delete[] novaploca;
}

Board::~Board()
{
	delete[] ploca;
}