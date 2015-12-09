#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "LinkListDictionary.h"
using namespace std;

const int MAX = 100;

typedef string STRING;
typedef bool BOOL;
typedef string WORD;

dict dictionary={MAX,0,0};  /* your dictionary  */

string word;

int main (void) {
    entry *pos;
    while (1) {
       word = GetNextWord();
       if ( word.empty() )  {
           DumpDictionary(dictionary);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) !=  0 )
           pos->count++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full" << word <<  "cannot be added\n";
    }
    return 0;
}



