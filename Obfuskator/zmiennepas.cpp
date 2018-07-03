
class zmiennepas :public zmiennecpp
{
public:
	zmiennepas operator=(zmiennepas &kl);
	void dodaj_tyl(string &tmp, int szuk);
	zmiennepas(tekst &glowa, string *tab, int ile);
};
zmiennepas zmiennepas::operator=(zmiennepas &kl)
{
	this->glowa = kl.glowa;
	this->liczniktyp = kl.liczniktyp;
	this->koniec = kl.koniec;
	this->licznikzm = kl.licznikzm;
	this->nazwy = kl.nazwy;
	this->typy = kl.typy;
	return *this;
}

void zmiennepas::dodaj_tyl(string &tmp, int szuk)//dodaj wykryte zmienne zaczynajac od prawej strony idac w lewa strone linijki
{
	bool zd = 1;
	string nowy;
	if(metod.szukaj(tmp, "[")<metod.szukaj(tmp, "]") && metod.szukaj(tmp, "]")!=-1)for (int a = metod.szukaj(tmp, "["); a <= metod.szukaj(tmp, "]"); a++)tmp[a] = ' ';//usuwa rzeczy znajdujace sie w klamrach kwadratowych
	bool fun = 0;
	if (metod.szukaj(tmp, "(") <szuk && metod.szukaj(tmp, "(") != -1)fun = 1;//czy zmienna znajduje sie w funkcji
	for (int a = szuk; a >=0; a--)
	{

		if (tmp[a] != '=' && tmp[a] != ';' && tmp[a] != ','  && zd == 1 && tmp[a] != ' ' && tmp[a] != '('&& tmp[a] != ')' && tmp[a] != ':')//czy znaleziono element konczacy dodawania zmiennych
		{
			if (tmp[a] != ' ' && tmp[a] != '*' && tmp[a] != '&' && tmp[a] != ':')	nowy = tmp[a] + nowy;//dodanie znaku zmiennej
		}
		else if(nowy.size()!=0) zd = 0;
		if ((tmp[a] == ',' || tmp[a] == ';' || (a==0 && nowy.size() != 0) || tmp[a] == ')' || tmp[a] == '(' || tmp[a] == ' '  || tmp[a] == ':') && nowy.size() != 0)//dodanie zmiennej do listy zmiennych
		{
			zd = 1;
			if (nowy != "array" && nowy!="of" && nowy != "var"&& nowy != "with"&& nowy != "for") *this + nowy;
			nowy = "";
		}
		if (tmp[a] == ';' || tmp[a] == '(' || tmp[a] == ')' || (tmp[a] == ',' && fun == 1))//czy jest koniec dodawania elementow w tej linicje
		{

			break;
		}
		tmp[a] = ' ';

	}
}

zmiennepas::zmiennepas(tekst &glowa, string *tab, int ile)
{
	cout << "rozpoczeto zmieniac zmienne" << endl;
	*this->glowa = glowa;
	this->dodajtypy(tab, ile);//dodanie typów zmiennych
	this->typy + "record";
	this->typy + "function";

	while (this->glowa->nast != nullptr)//wykonuj dopóki s¹ linnie tekstu
	{

		string tmp = this->glowa->linia;
		bool zmien = 0;
		tmp = usun_ciag(tmp, '\'');//usuñ wszystko pomiêdzy '
		

		do
		{
			tekst *tmptyp = this->typy.glowa;
			zmien = 0;
			for (int a = 0; a < typy.licznik; a++)//petla zamwieraj¹ca typy zmiennych
			{
				int szuk = metod.szukaj(tmp, tmptyp->linia);//wyszukaj czy w lini jest typ zmienniej
				if (szuk != -1)
				{
					zmien = czy_zmienna(szuk, tmptyp->linia.size(), tmp);//sprawdz czy wyszukany ciag jest typem
				}
				if (zmien == 1 && szuk != -1)//je¿eli znaleziona ciag jest zmienna
				{
					for (int a = szuk; a < szuk + tmptyp->linia.size(); a++)tmp[a] = ' ';//usun nazwe typu z ciagu
					if (a >= liczniktyp && a != liczniktyp + 1)//czy znaleziony typ jest zmienna z programu ale nie funkcja
					{
						dodaj_tyl(tmp, szuk);
						this->typy + this->koniec->stary;
					}
					else 
						if (a == liczniktyp + 1)//czy typ jest funkcja
						{
							dodaj(tmp, szuk);
							this->typy + this->koniec->stary;//dodaj typ do zmiennej
						}
						else 	dodaj_tyl(tmp, szuk);//dodaj zmienna jezeli jest zmienna

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
				zamien(this->glowa->linia, tmpzm,'\'');//zamieñ zmienne w linii
			}
		}

		this->glowa = this->glowa->nast;
	}
	cout << "skonczono zmieniac zmienne" << endl;
}