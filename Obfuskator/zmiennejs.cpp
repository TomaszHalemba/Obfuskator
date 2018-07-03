class zmiennejs :public zmiennecpp
{
public:
	zmiennejs operator=(zmiennejs &kl);
	void zamien(string &tekst, nazwa *&nazwy);
	zmiennejs(tekst &glowa, string *tab, int ile);
};

zmiennejs zmiennejs::operator=(zmiennejs &kl)
{
	this->glowa = kl.glowa;
	this->liczniktyp = kl.liczniktyp;
	this->koniec = kl.koniec;
	this->licznikzm = kl.licznikzm;
	this->nazwy = kl.nazwy;
	this->typy = kl.typy;
	return *this;
}

void zmiennejs::zamien(string &tekst, nazwa *&nazwy)
{
	while (nazwy != nullptr)//sprawdz czy s¹ jakies zmienne
	{
		bool zmien = 0;//czy wartosc jest zmienna
		string tmp = tekst;
		zmien = 0;
		int dl;
		int szuk = metod.szukaj(tmp, nazwy->stary);//szukaj czy jest nazwa zmiennej w tekscie
		while (szuk != -1)
		{

			dl = nazwy->stary.size();//dlugosc zmiennej starej
			zmien = 0;
			if (szuk == 0)zmien = 1;//jak zmienna jest na poczatku to nie trzeba sprawdzac czy sa znaki wczesniej
			else
				if (!((tmp[szuk - 1] >= 48 && tmp[szuk - 1] <= 57) || (tmp[szuk - 1] >= 65 && tmp[szuk - 1] <= 91) || (tmp[szuk - 1] >= 97 && tmp[szuk - 1] <= 122) || tmp[szuk - 1] == 95 ))zmien = 1;

			if (szuk + nazwy->stary.size() <= tekst.size())//czy zmienna nie konczy linni
				if (zmien == 1 && !((tmp[szuk + dl] >= 48 && tmp[szuk + dl] <= 57) || (tmp[szuk + dl] >= 65 && tmp[szuk + dl] <= 91) || (tmp[szuk + dl] >= 97 && tmp[szuk + dl] <= 122) || tmp[szuk + dl] == 95 ))zmien = 1;
				else if (zmien == 1)zmien = 0;




				if (zmien == 1)//czy znaleziona zmienna jest zmienna szukana
				{
					tekst.erase(szuk, nazwy->stary.size());
					tekst.insert(szuk, nazwy->nowy);//usun stara nazwe zmiennej i wstaw nowa
					tmp = tekst;
				}
				else
				{
					for (int a = szuk; a < szuk + nazwy->stary.size(); a++)tmp[a] = ' ';//usun z lini ciag znakow ktora zostala znaleziona zmienna, ale nie jest ni¹
				}
				szuk = metod.szukaj(tmp, nazwy->stary);

		}
		nazwy = nazwy->nast;
	}

}

zmiennejs::zmiennejs(tekst &glowa, string *tab, int ile)
{
	cout << "rozpoczeto zmieniac zmienne" << endl;
	*this->glowa = glowa;
	this->dodajtypy(tab, ile);//dodaj typy zmiennej do listy




	while (this->glowa->nast != nullptr)//wykonuj dopóki s¹ linnie tekstu
	{

		string tmp = this->glowa->linia;
		bool zmien = 0;
		do
		{
			tekst *tmptyp = this->typy.glowa;
			zmien = 0;
			for (int a = 0; a < typy.licznik; a++)//petla zamwieraj¹ca typy zmiennych
			{
				int szuk = metod.szukaj(tmp, tmptyp->linia);//wyszukaj czy w lini jest typ zmienniej
				if (szuk != -1) zmien = czy_zmienna(szuk, tmptyp->linia.size(), tmp);//sprawdz czy znaleziony typ jest zmienna
				
				if (zmien == 1 && szuk != -1)//je¿eli znaleziona ciag jest zmienna
				{
					for (int a = szuk; a < szuk + tmptyp->linia.size(); a++)tmp[a] = ' ';//usun nazwe typu z ciagu
					dodaj(tmp, szuk);//dodaj zmienna do listy 
					if (a >= liczniktyp)//czy zmienna ma byc uznana jako nowy typ
						this->typy + this->koniec->stary;
				}
				tmptyp = tmptyp->nast;
			}


		} while (zmien != 0);
		zmien = 0;
		if (this->licznikzm != 0)
		{

			nazwa *tmpzm = this->nazwy;
			if (zmien == 0)
			{
				tmpzm = this->nazwy;
				zamien(this->glowa->linia, tmpzm);//zamieñ zmienne w linii
			}
		}

		this->glowa = this->glowa->nast;
	}
	cout << "skonczono zmieniac zmienne" << endl;
}
