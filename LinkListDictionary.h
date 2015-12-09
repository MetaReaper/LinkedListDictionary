#ifndef LinkListDictionary
#define LinklistDictionary

	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <iostream>
	using namespace std;

	struct entry{
		int count;
		string word;
		entry * nextWord;
	};

	struct dict{
		int maxEntries;
		int numWords;
		entry * Words;
	};

	entry *LocateWord(dict&, string);
	bool FullDictionary(dict&);
	bool InsertWord(dict& ,string);
	string GetNextWord();
	void DumpDictionary(dict&);

#endif
