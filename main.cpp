#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "Word.h"
#include "WordSet.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

string getUserInput(){
    string tmp;
    cin >> tmp;
    return tmp;
}

   Word getUserWord() {
    string tmp;
    cout << "podaj slowko i tlumaczenie " << std::endl;
    Word tmpWord;
    tmp = getUserInput();
    tmpWord.setWord(tmp);
    cin >> tmp;
    tmpWord.setTranslation(tmp);
    return tmpWord;
}

WordSet getUserSet(){
    WordSet newSet;
    string nazwa;
    cout << "podaj nazwe dla tego zestawu: \n";
    cin >> nazwa;
    newSet.setName(nazwa);
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
    string tlumaczenia[n];
    string tabSlowek[n];


    int j = 0;
    list<Word>::iterator i;
    for(i = lista.begin(); i != lista.end(); i++){
        tabSlowek[j] = i->getWord();
        tlumaczenia[j] = i->getTranslation();

        j++;
    }


       cout << "podaj tlumaczenia nastepojacych slwo: \n";

    for(int i = 0; i < n; i++){
        cout << tabSlowek[i] << endl;
        cin >> odp[i];
    }

    int wynik = 0;
    for(int ii = 0; ii < n; ii++){
        cout << tabSlowek[ii] << " : " << tlumaczenia[ii] << "\n " << odp[ii] << endl;
        if(tlumaczenia[ii] == odp[ii])
            wynik++;
        else
            cout << "^^^" << endl;
    }

       return wynik;

}

void zapiszSet(WordSet set){
    ofstream plik;
    plik.open("pliki/"+set.getName() + ".csv");

    list<Word> tmp = set.getWords();

    if(plik.is_open()){

        list<Word>::iterator i;
        for(i = tmp.begin(); i != tmp.end(); i++){
            plik << i->getWord() <<';'<< i->getTranslation() << endl;
        }
    }

    plik.close();
    cout << "zestaw zapisany jako " << set.getName() << ".csv" << endl;

}

void testuj(){
    cout << "wybierz zestaw: \n";
    string nazwaZestawu;
    cin >> nazwaZestawu;
    WordSet zestaw;
    zestaw = readFile(nazwaZestawu);
    int n =  test(zestaw.getWords());
    cout << "wynik testu : " << n << "/" << zestaw.getWords().size()<< endl;
}

void addSet(){
    WordSet nowy = getUserSet();
    zapiszSet(nowy);
}


int program(){
    cout <<"dostepne opcje:\n";
    cout <<"test - sprawdz swoja wiedze z wybranym zestawem slowek\n"
           "nauka - przejdz zestaw uczac sie\n"
           "dodaj - dodaj nowy zestaw\n"
           "wyjdz - zakoncz program\n";

    string opcja;
    cin >> opcja;

  if(opcja == "wyjdz")
      return 0;
  if(opcja == "test")
      testuj();
  if(opcja == "nauka")
      return 0;
  if(opcja == "dodaj")
      addSet();

  return 1;
}

int main() {

    program();

    return 0;
}
