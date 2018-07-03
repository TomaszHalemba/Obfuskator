#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct tekst
{
	string linia;
	tekst *nast;

};

class wczytanie
{
public:
	wczytanie operator=(wczytanie &kl);
	friend ostream & operator<<(ostream &os, const wczytanie &kl);
	int licznik=0;
	tekst *glowa = new tekst;
	wczytanie(string sciezka,bool &blad);
	wczytanie() = default;
	~wczytanie();
};


wczytanie wczytanie::operator=(wczytanie & kl)
{
	this->licznik = kl.licznik;
	this->glowa = kl.glowa;
	return *this;
}
ostream & operator<<(ostream &os, const wczytanie &kl)
{
	os << kl.licznik<<endl;
	tekst *tym = kl.glowa;
	for (int a = 0; a < kl.licznik; a++)
	{
		os << tym->linia << endl;
		tym = tym->nast;
	}
	return os;
}



void operator+(wczytanie &glowa,string lin)//dodaje now¹ linie do listy
{
	tekst *nowy = new tekst;
	nowy->linia = lin;
	nowy->nast = nullptr;

	if (glowa.licznik == 0)//czy glowa jest pusta
	{
		glowa.glowa = nowy;
		glowa.licznik++;
	}
	else
	{
		tekst *tym = glowa.glowa;
		while (tym->nast)//przejdz na koniec listy
		{
			tym = tym->nast;
		}

		tym->nast = nowy;//dodaj nowy sk³adnik
		glowa.licznik++;
	}
	
}



wczytanie::wczytanie(string sciezka,bool &blad)
{
	cout << "rozpoczeto wczytywanie pliku" << endl;
	this->glowa=nullptr;
	fstream plik;
	plik.open(sciezka, ios::in);
	if(plik.good())//czy plik zosta³ otwarty
	while (!plik.eof())
	{
		string lin;
		getline(plik, lin);//pobierz linie z pliku
		*this + lin;//dodaj do listy linie
	}
	else
	{
		cout << "blad wczytania!" << endl;
		blad = 1;
	}
	plik.close();
	cout << "zakonczono wczytywanie pliku" << endl;
}

wczytanie::~wczytanie()
{
	
	for(int a=0;a<licznik-1;a++)
	{
		tekst *tmp = glowa;
		glowa = tmp->nast;
		delete(tmp);
	}
}