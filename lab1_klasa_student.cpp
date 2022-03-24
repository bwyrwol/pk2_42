/*
    
    1. Zadeklarowac klase student z polami prywatnymi: nazwisko (string), imie (string), numer_legitymacji (const int), semstr (int) oraz    srednia (int gwiazdka, wskaznik na tablice zawierajaca srednie z poszczegolnych semestrow),
    2. Dodac do klasy: konstruktor domyslny (ustawiajacy pola np. "Jan Nowak" nr leg. 0), konstruktor wieloargumenowy (pozwalajacy ustawic pola imie, nazwisko i numer legitymacji na dowolne wartosci) oraz destruktor; w konstruktorach i destruktorze wprowadzic raportowanie ich wywolania (np. na cout),
    3. Dodac metody: dodaj_srednia pozwalajaca wprowadzic srednia dla biezacego semestru oraz wyswietl pozwalajaca wyswietlic wszystkie dane o studencie,
    4. Dodac konstruktory: kopiujacy oraz przenoszacy i sprawdzic ich dzialanie, zwrocic uwage na pole numer_legitymacji,
    5. Dodac metode: dodaj_srednia pozwalajaca wprowadzic srednie dla kilku semestrow, wykorzystac std::initializer_list,
    6. Dodac do klasy pole statyczne pozwalajace przechowywac liczbe utworzonych obiektow, wyswietlac na konsoli kazda zmiane tego pola,
    7. Dodac metody set/get dla pol klasy.

 */
#include <iostream>
#include <string>
#include <utility>
#include "student.h"

using namespace std;

void separator(void)
{
    std::cout << "---------------------------------------------------" << endl;
}

#define __SEPARATOR__ separator()


int main()
{
    student s0;
    student s1("Kowalski", "Jan", 123456);
    s1.dodaj_srednia({3,4,5,3,2});

    s0.wyswietl();
    __SEPARATOR__;
    s1.wyswietl();
    __SEPARATOR__;
    student s2(s1, 7654321);
    s2.wyswietl();
    __SEPARATOR__;

    student s3 = move(s1);
    s3.wyswietl();
    __SEPARATOR__;
    s1.wyswietl();
    __SEPARATOR__;

    int* srednia3 = new int[LICZBA_SEMESTROW];
    s3.srednia_get(srednia3, s3.semestr_get());

    cout << "Srednia:";
    for (int i = 0; i < s3.semestr_get(); i++)
    {
        cout << " " << srednia3[i];
    }
    cout << endl;

    delete [] srednia3;

    __SEPARATOR__;
    //...
}
