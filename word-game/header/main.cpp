#include <iostream>
#include<fstream>
#include<string>
#include <vector>
#include<time.h>
#include "Words_and_Dictinory.h"
#include <stdlib.h>
using namespace std;

int main()
{
	int sayi = 9;
	string dizi[10];
	cout << sayi ;
	ifstream outfile;
	vector<string> kelime_list;
	vector<string> kelime_list1;
	vector<string> uygun_kelimeler;
	dictinory dict(kelime_list, uygun_kelimeler);

	kelime_list1 = dict.readwords(outfile);

	vector<string> suit_list;

	suit_list = dict.take();

	string gizli_kelime;

	gizli_kelime = dict.check(suit_list);
	
	cout <<"Bilbakalim Oyununa Hosgeldiniz:\n5 harften olusan bir kelime tuttum." << endl;

	words word;
	word.flagg = false;
	word.sayýý = 0;
	word.playGame(gizli_kelime, kelime_list1);
	
	return 0;
}