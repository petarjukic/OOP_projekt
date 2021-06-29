Klase:
	Player (bazna klasa):
		ima public članove int broj_bodova i char znak. Konstruktor koji postavlja broj_bodova na 0
		i virtualni destruktor. Ima i 3 virtualne funkcije. Prva virtualna funkcija je string VratiIme()
		pomoću koje na kraju programa ispisujemo ima pobjednika(ako pobjednik postoji). Druga virtualna
		funkcija je char** PotzH(char** pot) koja nam služi kako bi vratili potez HumalPlayer. Treća i 
		zadnja virtualna funkcija je char** PotzC(char** pot) koja nam služi kako bi vratili potez 
		ComputerPlayer.
	
	HumanPlayer:
		klasa HumanPlayer je izvedena klasa iz klase Player. Ima private član string ime koji određuje
		ime igrača. Ima public funkcije koje su: konstruktor HumanPlayer(string i) koji prima string
		koji određuje ime igrača. Funkcija string VratiIme() vraća ime igrača kojeg tražimo u slučaju 
		pobjednika igre. Funkcija char** PotezH(char** pot) vraća odigrani potez igrča. 
		char** POtzC(char** pot) za ovu klasu ne radi nista jer je to virtualna funkcija i ta je funckija
		potrebna kod klase ComputerPlayer. I destruktor ~HumanPlayer() koji briše ime igrača.
	
	ComputerPlayer:
		string VratiIme() vraća prazan string jer je to virtualna funkcija i ona važna za klasu 
		HumanPlayer. Funkcija char** PotezC(char** pot) vraća potez kojeg je računalo odabralo. Funckija
		char** PotezH(char** pot) za ovu klasu ne radi ništa jer je to virtalna funkcija koja je potrebna 
		klasi HumanPlayer.

	Game:
		klasa zadužena za logiku igre. Ima private član int broj_partija koji određuje koliko igara
		će se igrati. Konstruktor Game() postavlja broj_partija na 0 a taj broj određuje igrač.
		vector<Player*> igrac u taj vector se spremaju igrač/i za kasniji pristup njihovim članovima 
		i funkcijama. Funkcija void SetPlayer(vector<Player*> igr) sprema igrača ili igrače u član 	
		vector<Player*> koji su stvoreni. Funkcija void KolicinaPartija() služi kako bi igrač odabrao
		broj puta koliko želi igrat igru. void Igra() je funkcija u kojoj se igra igra. Funkcija 
		int ProvjeraRez(Board& pl) provjerava trenutno stanje tj. da li ima pobjednika nakon svakog
		odigranog poteza. void ProvjeraPobj(int i, int j) prima bodove igrača te određuje tko je pobjednik.
		Destruktor ~Game() briše klasu i sve njene podatke.

	Boadr:
		član int broj_znakova provjerava da li je polča puna, ploča je puna ako je broj_znakova = 9.
		char** ploca sprema znakove 'X' i 'O' na koordinate koje odredi računalo ili igrač.
		Konstruktor Board() postavlja broj_znakova na 0 i stvara 2D niz tj. ploču. void Ploca iscrtava
		ploču i znakove koji su uneseni na određenim koordinatama. void NovaPloca stvara novu ploču 
		nakon svake završene igre. Destruktor ~Board() briše storenu ploču.


main.cpp:
	U file-u main se nalazi mogućnost izbora igranja protiv računala ili protiv drugog igrača.
	Nakon odabira imaju 2 funkcije jedna IgracKomp() koje ništa ne prima te stvara kalsu HumanPlayer i
	ComputerPlayer i Game. Igrac dobiva znak 'X' te se sprema u vector<Player*> i poziva se funkcija Igra()
	koja se nalazi u klasi Game. Ako je broj igrača 2 iz main-a će se pozvati funkcija void DvaIgrača()
	u kojoj se stvara klasa Game te dvije klase HumanPlayer jer je odlučeno da će se igrati protiv drugog
	igrača. U funkciji igrac1 ima znak 'X', a igrac2 znak'O' te se i iz nje poziva funkcija Igra() koja se
	nalazi u klasi Game i u file-u Game.cpp.

Player.h:
	U file-u Player.h se nalazi bazna klasa Player za klase HumanPlayer i ComputerPlayer.

HumanPlayer.h:
	U fileu HumanPlayer.h se nalazi klasa HumanPlayer koja opisuje čovjeka igrača i ta je klasa izvedena iz
	Player klase.

HumanPlayer.cpp:
	U file-u HumanPlayer.cpp se nalazi funkcija char** HumanPlayer::PotezH(char** pot). Funkcija prima char**
	kako bi se moglo provjerit da li se na koordinatama koje korisnik unese već nalazi znak 'X' ili 'O'. U 
	funkciji korisnik unosi 2 koordinate koje određuju redak ploče i stupac. while petlja se izvršava sve dok
	korisnik ne unese koordinate na kojima nema znaka te na kraju vraća char** pot u kojem se nalazi ploča.

ComputerPlayer.h:
	U file-u ComputerPlayer.h se nalazi klasa ComputerPlayer koja je izvedena iz klase Player i predstavlja
	računalo kao igrača.

ComputerPlayer.cpp:
	U file-u ComputerPlayer.cpp se nalazi funkcija char** ComputerPlayer::PotezC(char** pot) pomoću koje 
	računalo određuje svoj potez. Računalo određuje potez preko rand() funkcije koja generira slučajne brojeve
	koji se nalaze od 0 do 2. U funkciji računalo određuje 2 koordinate koje određuju redak ploče i stupac. 
	while petlja se izvršava sve dok računalo ne odabere koordinate na kojima nema znaka te na kraju vraća
	char** pot u kojem se nalazi ploča.

Board.h:
	U file-u Board.h se nalazi klasa Board koja opisuje 2D ploču.

Board.cpp:
	U file-u Board.cpp se nalazi konstruktor za klasu Board koji postavlja broj_znakova na 0 te stvara	
	2D char ploču. Funkcija void Board::Ploca() ispisuje ploču i znakove koje je korisnik ili računalo unijelo.
	U funkciji void Board::NovaPloca() se stvara nova ploča nakon što se trunutna napuni ili ako je prije 
	toga prodađen pobjednik. Destruktor ~Board() brise char** ploca na kraju programa.

Game.h:
	U file-u Game.h se nalazi klasa Game.h koja određuje logiku igre.

Game.cpp:
	U file-u Game.cpp se nalazi konstruktor Game::Game() te funkcije void Game::KolicinaPartija(),
	int Game::ProvjeraRez(Board& pl), void Game::ProvjeraPobj(int i, int j), void Game::Igra().
	U konstruktoru Game::Game() se član broj_partija tipa int postavlja na 0. 
	Funkcija void Game::KolicinaPartija() pita korisnika da odredi broj koliko će se igara odigrati.
	int Game::ProvjeraRez(Board& pl) prima referencu Board kako bi se mogla trenutna ploča u kojoj se
	nalaze znakovi 'X' i 'O' mogla provjeriti da li ima pobjednika te se poziva nakon svakog odigranog poteza
	igrača ili računala. Vraća 1 ako je pobjednik igrac1 tj. igrač koji ima znak 'X', 2 ako je pobjednik 
	igrac2 tj. igrač koji ima znak 'O', 3 ako je ploča puna i nema pobjednika i 4 ako ništa od navedenog nije
	točno. 
	Funkcija void Game::ProvjeraPobj(int i, int j) prima dva integera koji predstavljaju broj bodova igrača
	ili igrača i računala. Funkcija ispisuje pobjednika ili neriješeno ako nema pobjednika tj. ako je broj
	bodova jednak.
	void Game::Igra() poziva funkciju KolicinaPartija() kako bi se znalo koliko će se igara odigrati, 
	stvara računalo igrača. Ima dvije while petlje. Prva while petlja se izvršava sve dok je broj_partija 
	razlićit on 0, a druga sve dok se ne odredi pobjednik ili ploča napuni.
	U drugoj while petlji se poziva funkcija za određivanje poteza igrača i/ili poteza računala.
	Nakon izlaska iz while petlji pozia se funkcija za provjeru pobjednika te nakon toga program završava.

