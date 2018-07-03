#include<iostream>

using namespace std;



class zapis
{
public:
	zapis operator=(zapis &kl);

	int licznik;
	tekst *glowa = new tekst;
	zapis(wczytanie &glowa, string sciezka);
	~zapis();
};

zapis zapis::operator=(zapis & kl)
{
	this->glowa = kl.glowa;
	return *this;
}


zapis::zapis(wczytanie & glowa, string sciezka)//zapisz liste do pliku
{
	fstream p;
	p.open(sciezka, ios::out);
	tekst *tmp = glowa.glowa;
	for (int a = 0; a < glowa.licznik; a++)
	{
		p << tmp->linia << endl;
		tmp = tmp->nast;
	}

		p.close();

}
zapis::~zapis()
{
		delete(glowa);
}