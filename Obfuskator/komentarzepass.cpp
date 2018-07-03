
#include "metody.cpp"
using namespace std;




class komentarzepas
{
public:
	komentarzepas operator=(komentarzepas &kl);
	tekst *glowa=new tekst;
	string blok_komentarzy(string glowa, string oddzielacz, string koniec, string kom, bool &komen,bool dodatkowe);
	toolbox metod;
	komentarzepas(tekst &glowa);
	komentarzepas() = default;
	~komentarzepas() = default;
};


komentarzepas komentarzepas::operator=(komentarzepas & kl)
{
	this->glowa = kl.glowa;
	return *this;
}


string komentarzepas::blok_komentarzy(string glowa, string oddzielacz, string start, string kon, bool &komen,bool dodatkowe)//funkcja usuwa komentarze ktore moga ale nie musza konczyc sie na 1 linijce
{
	if (glowa.size() == 0) return glowa;
	int koniec=metod.szukaj(glowa, kon);
	if (komen == 1 && koniec != -1)//usun linijke od poczatku az do konca komentarza jezeli juz wczesniej byl komentarz i jest koniec komentarza
	{
		for (int a = 0; a < koniec + kon.size(); a++)glowa[a] = ' ';
		komen = 0;
	}
	else if(komen==1)for (int a = 0; a < glowa.size(); a++)glowa[a] = ' ';//usun linijke jezeli nie ma konca komentarza a zostal rozpoczety wczesniej
	koniec = metod.szukaj(glowa, kon);
	int oddziel = metod.szukaj(glowa, oddzielacz);
	int pocz = metod.szukaj(glowa, start);
	string tmp=glowa;
	do
	{ 
	if(pocz!=-1)//czy jest poczatek komentarza
		if (oddziel == -1)//czy jest element od ktorego nie nalezy wykrywac poczatku
		{
			if (koniec == -1)//czy znaleziono koniec komentarza
			{
				for (int a = pocz; a < glowa.size(); a++)glowa[a] = ' ';
				komen = 1;
				return glowa;
			}
			else for (int a = pocz; a < koniec+kon.size(); a++) glowa[a] = ' ';
			tmp = glowa;
		}
		else
		{
			if (dodatkowe == 1)//czy jest element ktory anuluje znalezienie wczesniejszego poczatku komentarza
			{
				if (tmp[pocz - 1] == 92 || tmp[pocz - 1] == 39) tmp[pocz] = ' ';//jezeli wystapily znaki ktore anuluja znalezienie wczesniejszego znaku, usun znaleziony poczatek komentarza
				pocz = metod.szukaj(tmp, start);//znajdz poczatek komentarza
			}
			else
			{
				if(pocz!=0)while (tmp[pocz - 1] == 39 || tmp[pocz + 1] == 39)//jezeli komentarz nie jest na poczatku a komentarz zaczyna sie przy znakach anulujacych znalezienie zmiennych
				{
					tmp[pocz] = ' ';
					pocz = metod.szukaj(tmp, start);//usun znak rozpoczecia komentarza i znajdz kolejny
				}
			}
				if (pocz > oddziel)	tmp = metod.usun(tmp, oddzielacz);//czy znaleziony poczatek jest w srodku tekstu wypisywanego na ekran lub w zmiennej typu string
				else if(koniec!=-1) for (int a = pocz; a < koniec + kon.size(); a++)tmp[a] = glowa[a] = ' ';//usun ciag od poczatku az do konca komentarza
			
			
		}

	oddziel = metod.szukaj(tmp, oddzielacz);//znajdz nowy poczatek tekstu wypisywanego na ekran lub w zmiennej typu string
	pocz = metod.szukaj(tmp, start);//znajdz poczatek komentarza
	koniec = metod.szukaj(tmp, kon);//znajdz koniec komentarza
	} while (pocz!=-1);
	return glowa;

}


komentarzepas::komentarzepas(tekst &glowa)
{
	cout << "rozpoczeto usuwac komentarze" << endl;
	*this->glowa = glowa;
	bool pierwszy = 1;
	bool wielo = 0;
	while (this->glowa->nast != nullptr)
	{
		
		string tmp = blok_komentarzy(this->glowa->linia,"'","{", "}",wielo,0);//usun komentarze wieloliniowe
		if (pierwszy == 0) this->glowa->linia = tmp;//czy petla nie jest na 1 elemencie listy, jak nie to wstaw zmieniona linie bez komentarzy do listy
		else
		{
			glowa.linia = tmp;
			pierwszy = 0;
		}
		this->glowa = this->glowa->nast;
	}
	cout << "zakonczono usuwac komentarze" << endl;
}
