
#include "stdafx.h"
#include "header.h"
#include<time.h>
using namespace std;

int main(int argc, char * argv[])
{
	srand(time(NULL));
	string nazwa;
	cout << "podaj sciezke: ";
	cin >> nazwa;
	
	bool blad = 0;
	
		wczytanie wczyt(nazwa, blad);
		int szuk = nazwa.rfind(".cpp");
		if (blad == 0)
		{
			if (szuk != -1 && szuk + 4 == nazwa.size())
			{
				cout << "wykryto jezyk: c++" << endl;
				int ile = 9;
				string zm[] = { "int","short","long","string","char","bool","float","double","void" };
				komentarzecpp komy(*wczyt.glowa);
				zmiennecpp zmien(*wczyt.glowa, zm, ile);
			}
			else
			{
				szuk = nazwa.rfind(".PAS");
				if (szuk != -1 && szuk + 4 == nazwa.size())
				{
					cout << "wykryto jezyk: pascal" << endl;
					int ile = 10;
					string zm[] = { "string","integer","byte","shortint","word","longint","char","real","single","double" };
					komentarzepas komy(*wczyt.glowa);
					zmiennepas zmien(*wczyt.glowa, zm, ile);
				}
				else
				{
					szuk = nazwa.rfind(".java");
					if (szuk != -1 && szuk + 5 == nazwa.size())
					{
						cout << "wykryto jezyk: java" << endl;
						int ile = 10;
						string zm[] = { "int","short","long","String","char","bool","float","double","void","Scanner" };
						komentarzecpp komy(*wczyt.glowa);
						zmiennecpp zmien(*wczyt.glowa, zm, ile);
					}
					else
					{
						szuk = nazwa.rfind(".html");
						if (szuk != -1 && szuk + 5 == nazwa.size())
						{
							cout << "wykryto jezyk: javascript " << endl;
							int ile = 2;
							string zm[] = { "var","function" };
							komentarzecpp komy(*wczyt.glowa);
							zmiennejs zmien(*wczyt.glowa, zm, ile);
						}
						else cout << "nie wykryto jezyku" << endl;

					}
				}
			}
			zapis zapisz(wczyt, nazwa);
		}
		
	system("pause");
    return 0;
}

