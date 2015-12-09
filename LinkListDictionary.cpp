#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;

typedef struct entry {  //Struct for each word in the dictionary
      int count = 1;
      string word;
      entry * nextWord = NULL;
} ENTRY;

typedef struct dict {   //Struct for dictionary
     int maxEntries = 0;
     int numWords = 0;
     entry * Words = NULL;
} DICT;

ENTRY *LocateWord(DICT& dictionary, WORD word){ //Check to see if the word fed into the dictionary already resides in the dictionary, returns location if found
	entry * pointer = dictionary.Words;
	while (pointer != NULL){
		if (pointer->word.compare(word)==0) {
			return pointer;
		}
		else pointer = pointer->nextWord;
	}
	return 0;
}

bool FullDictionary(DICT& dictionary){ //check to see if dictionary exceeds its limit if another word were to be inserted
	if (dictionary.numWords==dictionary.maxEntries)	return true;
	else return false;
}

bool InsertWord(DICT& dictionary,WORD word){ //will insert word into proper position to sort at the same time
	entry * pointer = dictionary.Words;
	if (dictionary.Words==0){
        entry * newWord = new entry;
		newWord->word = word;
		newWord->nextWord = pointer;
		dictionary.Words = newWord;
		dictionary.numWords++;
		return true;
	}
	if (FullDictionary(dictionary)) return false;
	if (word.compare(dictionary.Words->word)<0){
		entry * newWord = new entry;
		newWord->word = word;
		newWord->nextWord = pointer;
		dictionary.Words = newWord;
		dictionary.numWords++;
		return true;
	}
	while (pointer->nextWord!=NULL){
		if (word.compare(pointer->nextWord->word)<0){
			entry * newWord = new entry;
			newWord->word = word;
			newWord->nextWord = pointer->nextWord;
			pointer->nextWord = newWord;
			dictionary.numWords++;
			return true;
		}
		else pointer = pointer->nextWord;
	}
	entry newWord;
	newWord.word = word;
	newWord.nextWord = pointer->nextWord;
	dictionary.numWords++;
	return true;

}

string GetNextWord(){  //Reads the next word to be recorded to the dictionary
	bool endWord = false;
	string word;
    char character;

	while (cin.good()) {
		character = cin.get();
		if (isalpha(character)) {
			word.push_back(character);
			endWord = true;
		}
		else {
			if (endWord) {
				return word;
			}
		}
	}
	return word;
}

void DumpDictionary(DICT& dictionary){  //displays all words and their frequency to the user
	ENTRY * pointer = dictionary.Words;
	while (pointer != NULL) {
		printf("%-20s|%9i \n", pointer->word.c_str(), pointer->count);
		pointer = pointer->nextWord;
	}
}

