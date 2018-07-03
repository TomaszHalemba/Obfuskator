using namespace std;

class toolbox
{
public:
	int szukaj(string tekst, string szuk);
	string usun(string tekst, string oddziel);
};

int toolbox::szukaj(string tekst, string szuk)//find
{
	bool czy_znal;
	if (tekst.size() < szuk.size())return -1;//je¿eli szukana jest dluzsza niz tekst zwroc 1
	for (int a = 0; a < tekst.size() - szuk.size() + 1; a++)
	{
		czy_znal = 1;

		for (int b = 0; b < szuk.size(); b++)
		{
			if (tekst[a + b] != szuk[b])
			{
				czy_znal = 0;
				break;
			}

		}

		if (czy_znal == 1)return a;
	}

	return -1;

}

string toolbox::usun(string tekst, string oddzielacz)//usuwa tekst od zmiennej, do zmiennej
{
	if (tekst.size() == 0) return tekst;//jezeli tekst jest pusty, zwroc tekst
	string tmp = tekst;
	int oddziel = szukaj(tekst, oddzielacz);//czy znaleziono zmienna od ktorej trzeba usuwac
	if (oddziel == -1)return tmp;//zwroc tekst jezeli nie znaleziono zmiennej
	else
	{
		do
		{
			tmp[oddziel] = ' ';
			if (szukaj(tekst, oddzielacz)!=-1) //czy jest 2 zmienna
				for (int a = oddziel; a <= szukaj(tmp, oddzielacz); a++)tmp[a] = ' ';
			oddziel = szukaj(tekst, oddzielacz);//sprawdz czy jest kolejna zmienna szukana
		} while (oddziel != -1);
	}
	return tmp;
}
