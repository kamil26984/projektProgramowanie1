#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "Word.h"
#include "WordSet.h"

using namespace std;

string getUserInput(){
    string tmp;
    cin >> tmp;
    return tmp;
}

   Word getUserWord() {
    std::string tmp;
    std::cout << "podaj slowko i tlumaczenie " << std::endl;
    Word tmpWord;
    std::cin >> tmp;
    tmpWord.setWord(tmp);
    std::cin >> tmp;
    tmpWord.setTranslation(tmp);
    return tmpWord;
}

WordSet getUserSet(){
    WordSet newSet;
    string nazwa;
    cout << "podaj nazwe dla tego zestawu: \n";
    cin >> nazwa;
    newSet.setWord(nazwa);
    int n;
    cout << "ile bedzie slowek? \n";
    cin >> n;

    Word tmp;
    for(int i = 0; i < n; i++){
        tmp = getUserWord();
        newSet.addWord(tmp);
    }

    return newSet;
}

WordSet readFile(string file){
       WordSet newSet;
       newSet.setName(file);
       ifstream plik;
       plik.open("pliki/" + file + ".csv");

       Word w;
       list<Word> set;
       newSet.addSet(set);
       string tmp;

       if(plik.is_open()) {
           while (getline(plik, tmp)) {
               stringstream inputString(tmp);
               getline(inputString, tmp, ';');
               w.setWord(tmp);
               getline(inputString, tmp, ';');\
           w.setTranslation(tmp);
               newSet.addWord(w);
           }

           plik.close();
       }
       else
           cout << " nie udalo sie otworzyc pliku\n";
       return newSet;
   }

   void printList(list<Word> lista){
       list<Word>::iterator i;
       for(i = lista.begin(); i != lista.end(); i++){
           i->wypisz();
       }
   }

   int test(list<Word> lista){
    int n = lista.size();
    string odp[n];
    string tab[n];
    cout << "podaj tlumaczenia nastepojacych slwo: \n";


    int j = 0;
    list<Word>::iterator i;
    for(i = lista.begin(); i != lista.end(); i++){
        tab[j] = i->getTranslation();
        cout << i->getWord() << endl;
        cin >> odp[j];
        j++;
    }
    int wynik = 0;
    for(int ii = 0; ii < n; ii++){
        cout << tab[ii] << " " << odp[ii] << endl;
        if(tab[ii] == odp[ii])
            wynik++;
        else
            cout << "^^^" << endl;
    }

       return wynik;

}

void zapiszSet(WordSet set){
    ofstream plik;
    plik.open(set.getName() + ".csv");

    list<Word> tmp = set.getWords();

    if(plik.is_open()){

        list<Word>::iterator i;
        for(i = tmp.begin(); i != tmp.end(); i++){
            plik << i->getWord() <<';'<< i->getTranslation() << endl;
        }
    }

    plik.close();

}

int main() {

       WordSet testSet;
       testSet = readFile("zestaw1");
       printList(testSet.getWords());

       cout << "wynik testu : " << test(testSet.getWords()) << endl;


    return 0;
}
