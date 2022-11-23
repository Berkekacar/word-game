#ifndef WORDS_AND_DÝCTÝONRY_H
#define WORDS_AND_DÝCTÝONRY_H
using namespace std;

class dictinory 
{
private:
	vector<string> liste;
	vector<string> suitwords;

public:
	dictinory(vector<string> list, vector<string> list1);
	vector<string> readwords(ifstream &outfile);
	vector<string> take();
	string check(vector<string> uygunliste);
};

class words
{
private:
	string gizli_kelime;
public:
	bool flagg;
	int sayýý;
	string take_a_prediction(vector<string> lst);
	void gizliKelime(string kelime);
	int sameword(string tahmin);
	vector<int> konum(string tahmin);
	int sayac();
	void playGame(string gizli_kelime, vector<string> kelime_list1);
};
#endif