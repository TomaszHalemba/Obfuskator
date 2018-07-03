

struct nazwa
{
	string stary;
	string nowy;
	nazwa *nast;
};

class zmiennecpp
{
public:
	zmiennecpp operator=(zmiennecpp &kl);
	void dodajtypy(string *tab, int ile);
	string usun_ciag(string tekst, char oddzielacz);
	bool czy_zmienna(int szuk,int dl,string tekst);
	tekst *glowa = new tekst;
	wczytanie typy;
	toolbox metod;
	string losuj();
	void zamien(string &tekst, nazwa *&nazwy, char oddzielacz);
	void dodaj(string &tekst, int szuk);
	unsigned int liczniktyp;
	unsigned int licznikzm = 0;
	nazwa *nazwy = new nazwa;
	nazwa *koniec = new nazwa;
	zmiennecpp(tekst &glowa, string *tab, int ile);
	zmiennecpp() = default;
	~zmiennecpp();
};
void operator+(zmiennecpp &glowa, string now)//dodanie do listy nowej zmiennej 
{
	nazwa *nowy = new nazwa;
	nowy->stary = now;
	nowy->nowy = glowa.losuj();//wylosuj nazwe zmiennej
	nowy->nast = nullptr;
	
	if (glowa.licznikzm == 0)//czy zmienna jest 1 dodawan¹ 
	{
		glowa.koniec=glowa.nazwy = nowy;
		glowa.licznikzm++;
	}
	else
	{
		nazwa *tym;
		bool zm, byl = 0;
		do
		{
			zm = 0;
			tym = glowa.nazwy;
			
			//funkcja mieszajaca filtr blooma
			while (tym->nast)
			{
				if (nowy->nowy == tym->nowy) zm = 1;//czy nowa nazwa zmiennej juz istnieje
				if (nowy->stary == tym->stary)//czy zmienna juz byla kiedyœ dodana
				{
					byl = 1;
					break;
				}
				tym = tym->nast;

			}
			if (zm == 1)nowy->nowy = glowa.losuj();//je¿eli nazwa ju¿ by³a, wylosuj now¹
		} while (zm != 0 && byl != 1);
		if (byl == 0)//je¿eli zmiennej nie by³o, dodaj j¹ na koniec listy
		{
			tym->nast = nowy;
			glowa.koniec = nowy;
			glowa.licznikzm++;
		}
	}
}
zmiennecpp zmiennecpp::operator=(zmiennecpp &kl)
{
	this->glowa = kl.glowa;
	this->liczniktyp = kl.liczniktyp;
	this->koniec = kl.koniec;
	this->licznikzm = kl.licznikzm;
	this->nazwy = kl.nazwy;
	this->typy = kl.typy;
	return *this;
}

void zmiennecpp::dodaj(string &tmp,int szuk)//dodanie z linijki nowych zmiennych
{
	bool zd = 1;
	string nowy;
	bool fun=0;
	if (metod.szukaj(tmp, "(") <szuk && metod.szukaj(tmp, "(")!=-1)fun = 1;//sprawdŸ czy wyszukany typ jest w zmiennej
	for (int a = szuk; a < tmp.size(); a++)
	{

		if (tmp[a] != '=' && tmp[a] != ';' && tmp[a] != ','  && zd == 1 && tmp[a] != '[' && tmp[a]!='('&& tmp[a] != ')')//czy znaleziono element konczacy dodawania zmiennych
		{
		if(tmp[a]!=' ' && tmp[a] != '*' && tmp[a] != '&')	nowy += tmp[a];//dodanie znaku zmiennej
		}
		else zd = 0;
		if ((tmp[a] == ',' || tmp[a] == ';' || (a+1==tmp.size() && nowy.size()!=0) || tmp[a] == ')' || tmp[a] == '(') && nowy.size() != 0)//dodanie zmiennej do listy zmiennych
		{
			zd = 1;
			if(nowy!="main") *this + nowy;
			nowy = "";
		}
		if (tmp[a] == ';' || tmp[a] == '(' || tmp[a] == ')' || (tmp[a] == ',' && fun==1) )//czy jest koniec dodawania elementow w tej linicje
		{
	
			break;
		}
		tmp[a] = ' ';
		
	}

}

void zmiennecpp::zamien(string &tekst, nazwa *&nazwy,char oddzielacz)//zamienia nazwy zmiennych funkcji itp
{
	while (nazwy != nullptr)
	{
		bool zmien=0;
		string tmp = usun_ciag(tekst,oddzielacz);//usun ciag zawierajacy tekst wyswietlany na ekranie lub wartosc zmiennej string 
		zmien = 0;
		int dl;
		int szuk = metod.szukaj(tmp, nazwy->stary);//znajdz star¹ nazwe zmiennej
		while (szuk != -1)
		{
			
			zmien = czy_zmienna(szuk, nazwy->stary.size(), tmp);//sprawdz czy wyszukany ciag jest zmienna
			


			if (zmien == 1)//czy znaleziona zmienna jest zmienna szukana
			{
				tekst.erase(szuk, nazwy->stary.size());
				tekst.insert(szuk, nazwy->nowy);//usun stara nazwe zmiennej i wstaw nowa
				tmp=tekst;
			}
			else
			{
				for (int a = szuk; a < szuk + nazwy->stary.size(); a++)tmp[a] = ' ';//usun z lini ciag znakow ktora zostala znaleziona zmienna, ale nie jest ni¹
			}
			tmp = usun_ciag(tmp, oddzielacz);
			szuk = metod.szukaj(tmp, nazwy->stary);//wyszukaj czy jest kolejna stara nazwa zmiennej

		}
		nazwy = nazwy->nast;
	}

}
void zmiennecpp::dodajtypy( string *tab, int ile)//dodaje do listy typy zmiennych
{
	this->liczniktyp = ile;
	for (int a = 0; a < ile; a++)this->typy + tab[a];

}
string zmiennecpp::usun_ciag(string tekst, char oddzielacz)//usuwa zmienne od zmiennej do zmiennej
{
	string tmp = tekst;
	bool zmien=0;
	for (int a = 0; a < tekst.size(); a++)
	{

		if (zmien == 1 && tmp[a] == oddzielacz)//czy zmienna sie juz pojawila i czy znak jest zmienna
		{
			tmp[a] = ' ';
			zmien = 0;
		}
		if (tmp[a] == oddzielacz)zmien = 1;//jezeli znak jest zmienna, ustaw ze znak sie pojawil
		if (zmien == 1)tmp[a] = ' ';
	}
	return tmp;
}

string zmiennecpp::losuj()//losuje nazwe zmiennej 
{
	int x =4+ rand() % 9;
	string tmp;
	
	for (int a = 0; a < x; a++)
	{
		bool z = rand() % 2;
		if (z == 0)tmp += 65 + rand() % 26;//losuje du¿¹ litere
		else tmp += 97 + rand() % 26;//losuje ma³¹ litere
	}
	return tmp;
}

bool zmiennecpp::czy_zmienna(int szuk, int dl, string tmp)//czy wyszukana zmienna jest zmienna
{
	bool zmien = 0;
	if (szuk == 0)zmien = 1;//jak zmienna jest na poczatku to nie trzeba sprawdzac czy sa znaki wczesniej
	else
		if (!((tmp[szuk - 1] >= 48 && tmp[szuk - 1] <= 57) || (tmp[szuk - 1] >= 65 && tmp[szuk - 1] <= 90) || (tmp[szuk - 1] >= 97 && tmp[szuk - 1] <= 122) || tmp[szuk - 1] == 95))zmien = 1;

	if (szuk + dl <= tmp.size()) // czy zmienna nie konczy linni
		if (zmien == 1 && !((tmp[szuk + dl] >= 48 && tmp[szuk + dl] <= 57) || (tmp[szuk + dl] >= 65 && tmp[szuk + dl] <= 90) || (tmp[szuk + dl] >= 97 && tmp[szuk + dl] <= 122) || tmp[szuk + dl] == 95))zmien = 1;
		else if (zmien == 1)zmien = 0;

		return zmien;
}

zmiennecpp::zmiennecpp(tekst &glowa, string *tab, int ile)
{
	cout << "rozpoczeto zmieniac zmienne" << endl;
	*this->glowa = glowa;
	this->dodajtypy(tab, ile);//dodaje typy do listy
	this->typy + "struct";
	this->typy + "class";


	

	while (this->glowa->nast != nullptr)
	{

		string tmp = this->glowa->linia;
		int unsig = metod.szukaj(tmp, "unsigned");
		while (unsig!=-1)//usun wszystkie unsigned w lini
		{
			for (int a = unsig; a < unsig + 7; a++)tmp[a] = ' ';
			unsig = metod.szukaj(tmp, "unsigned");
		}
	
		bool zmien=0;
		tmp = usun_ciag(tmp, '\"');//usuñ wszystko pomiêdzy "

		
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
						if (zmien == 1 && szuk!=-1)//je¿eli znaleziona ciag jest zmienna
						{
							for (int a = szuk; a < szuk + tmptyp->linia.size(); a++)tmp[a] = ' ';//usun nazwe typu z ciagu
							dodaj(tmp,szuk);//dodaj zmienne do listy
							if (a >= liczniktyp)
							this->typy + this->koniec->stary;//dodaj zmienna do typu
						}
				tmptyp= tmptyp->nast;
			}


		} while (zmien!=0);
		zmien = 0;
		if (this->licznikzm!=0)
		{

			nazwa *tmpzm = this->nazwy;
			if (zmien == 0)
			{
				tmpzm = this->nazwy;
				zamien(this->glowa->linia, tmpzm,'\"');//zamieñ zmienne w linii
			}
		}

		this->glowa = this->glowa->nast;
	}
	cout << "skonczono zmieniac zmienne" << endl;
}

zmiennecpp::~zmiennecpp()
{


	delete(koniec);
	for(int a=0;a<licznikzm-1;a++)
	{
		nazwa *tmp = nazwy;
		nazwy = tmp->nast;
		delete(tmp);
	}

}