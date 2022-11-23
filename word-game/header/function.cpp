#include <iostream>
#include<fstream>
#include<string>
#include <vector>
#include<time.h>
#include "Words_and_Dictinory.h"
#include <stdlib.h>
using namespace std;

dictinory::dictinory(vector<string> list, vector<string> list1)
{
	liste = list;
	suitwords = list1;
}

vector<string> dictinory::readwords(ifstream &outfile)
{
	outfile.open("words.txt");
	string str;
	while (!outfile.eof())
	{
		outfile >> str;
		liste.push_back(str);
	}
	return liste;
}

vector<string> dictinory::take()
{
	string eleman;
	char ch;

	int x = 0;
	int xx = 0;
	int y = liste.size();

	while (x < y)
	{
		xx = 0;
		eleman = liste[x];
		bool flag = true;
		while (xx < 5)
		{
			ch = eleman[xx];
			for (int index = xx + 1; index < 5; index++)
			{
				if (ch == eleman[index])
				{
					flag = false;
				}
			}
			xx++;
		}
		if (flag == true)
		{
			suitwords.push_back(eleman);

		}
		x++;
	}
	return suitwords;

}

string dictinory::check(vector<string> uygunliste)
{
	srand(time(NULL));
	int sayý = 0 + rand() % uygunliste.size();
	return uygunliste[sayý];
}

string words::take_a_prediction(vector<string> lst)
{
	string str;
	bool flag1 = false;
	while (true)
	{
		system("COLOR 2");
		cout << "Tahmininiz nedir?";
		getline(cin, str);

		for (int i = 0; i < lst.size(); i++)
		{
			if (str == lst[i])
			{
				flag1 = true;
			}
		}
		if (str == "xxxxx")
		{
			system("COLOR 4");
			cout << "ipucu! gizli kelime " << gizli_kelime << endl;
			flagg = true;
			int x = sayac();
		}
		else if (flag1 == false)
		{
			cout << "tahmin listede yok" << endl;
		}

		if (flag1 == true)
		{
			return str;
		}

	}
}

void words::gizliKelime(string kelime)
{
	gizli_kelime = kelime;
}

int words::sameword(string tahmin)
{
	int t = 0;
	int miktar = 0;
	vector<char> harf;
	bool flag = true;

	for (int i = 0; i < 5; i++)
	{
		harf.push_back(tahmin[i]);
		for (int s = 0; s < i; s++)
		{
			if(harf[s]==tahmin[i])
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			continue;
		}
		
		

		t = gizli_kelime.find(tahmin[i]);
		if (t != -1)
		{
			miktar++;
		}
	}
	return miktar;
}

vector<int> words::konum(string tahmin)
{
	vector<int> vecindex;
	for (int i = 0; i < 5; i++)
	{
		if (tahmin[i] == gizli_kelime[i])
		{
			vecindex.push_back(i);
		}
	}
	return vecindex;
}

int words::sayac()
{
	sayýý++;
	return sayýý;
}

void words::playGame(string gizli_kelime, vector<string> kelime_list1)
{
	while (true)
	{
		gizliKelime(gizli_kelime);
		string tahmin = take_a_prediction(kelime_list1);
		int sayýýý = sayac();
		/*gizliKelime(gizli_kelime);*/
		int match_amaont = sameword(tahmin);
		vector<int> index_match = konum(tahmin);
		if (gizli_kelime == tahmin)
		{
			if (flagg == true)
			{
				cout << "Bildiniz! ipucu kullanarak " << sayýýý << " denemede" << endl;
				break;
			}
			else
			{
				cout << "Bildiniz! " << sayýýý << " denemede" << endl;
				break;
			}
		}

		cout << "eslesen sayisi=" << match_amaont << endl;
		cout << "dogru konum sayisi=" << index_match.size() << endl;
	}
}