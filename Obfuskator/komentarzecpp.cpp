
class komentarzecpp : public komentarzepas
{

public:
	komentarzecpp operator=(komentarzecpp & kl);
	string komentarze_jedno(string glowa, string oddzielacz, string kom);

	komentarzecpp(tekst &glowa);
};



komentarzecpp komentarzecpp::operator=(komentarzecpp & kl)
{
	this->glowa = kl.glowa;
	return *this;
}

string komentarzecpp::komentarze_jedno(string glowa, string oddzielacz, string kom)//usuwa komentarze jednoelementowe
{
	if (glowa.size() == 0)return glowa;
	string tymczas = glowa;
	string tmp = tymczas;
	int war = metod.szukaj(tymczas, kom);//wyszukaj poczatku komentarza
	int cudzy = metod.szukaj(tymczas, oddzielacz);//wyszukaj cudzys≥Ûw
	if (war != -1)//czy nie znaleziono poczπtek komentarza w lini
	{
		do
		{
			if (war < cudzy && war != -1)//czy komentarz istnieje i czy jest przed cudzys≥owiem 
			{

				for (int a = war; a < tymczas.size(); a++) tymczas[a] = ' ';//usuÒ linie od poczatku komentarza
				return tymczas;
			}
			if (cudzy != -1)//czy nie ma cudzys≥owiu
			{
				tmp[cudzy] = ' ';
				cudzy = metod.szukaj(tmp, oddzielacz);//znajdz kolejny cudzys≥Ûw
				if (cudzy == -1) for (int a = war; a < tymczas.size(); a++) tymczas[a] = ' ';//usuÒ linie jeøeli nie ma komentarza
				else for (int a = war; a < cudzy; a++) tmp[a] = ' ';//usuÒ tekst aø cudzys≥owia
			}
			cudzy = metod.szukaj(tmp, oddzielacz);//znajdü kolejny cudzys≥Ûw
			if (metod.szukaj(tmp, kom) != -1 && metod.szukaj(tmp, kom) > metod.szukaj(tmp, oddzielacz)) {//jeøeli znaleziono komentarz, ale jest za cudzys≥owiem 
				war = metod.szukaj(tmp, kom);//znajdü komentarz
				break;
			}
			war = metod.szukaj(tmp, kom);//znajdz kolejny komentarz
		} while (war != -1);
		for (int a = war; a < tymczas.size(); a++) tymczas[a] = ' ';//usuÒ linie od poczπtku komentarzu
	}
		return tymczas;
}


komentarzecpp::komentarzecpp(tekst &glowa) : komentarzepas()
{
	cout << "rozpoczeto usuwac komentarze" << endl;
	*this->glowa = glowa;
	tekst *tym = this->glowa;
	bool pierwszy = 1;
	bool wielo = 0;
	while (this->glowa->nast != nullptr)
	{
		string 	tmp = blok_komentarzy(this->glowa->linia, "\"", "/*", "*/", wielo, 0);//usuÒ blok komentarzy
		tmp = komentarze_jedno(tmp, "\"", "//");//usuÒ komentarze jednoliniowe
		{ 
		if (pierwszy == 0) this->glowa->linia = tmp;//zamieÒ tekst zawarty w elemencie jeøeli nie jest on g≥owπ listy
		else
		{
			glowa.linia = tmp;//zmieÒ tekst w g≥owie
			pierwszy = 0;
		}
		tym = this->glowa;
		this->glowa = this->glowa->nast;
		}
	}
	cout << "zakonczono usuwac komentarze" << endl;
}
