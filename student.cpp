#include <iostream>
#include <initializer_list>
#include "student.h"

using namespace std;

int student::liczba_studentow = 0;

student::student():numer_legitymacji(0)
{
	imie = "Jan";
	nazwisko = "Nowak";

	srednia = new int[LICZBA_SEMESTROW];

	clog << ">>> wywolano konstruktor bezargumentowy obiektu [" << this << "]" << endl;
	liczba_studentow++;
}

student::student(std::string nazwisko, std::string imie, int numer_legitymacji):numer_legitymacji(numer_legitymacji)
{
	this->imie = imie;
	this->nazwisko = nazwisko;

	srednia = new int[LICZBA_SEMESTROW];

	clog << ">>> wywolano konstruktor wieloargumentowy obiektu [" << this << "]" << endl;
	liczba_studentow++;
}

student::student(const student& _student)
{
	imie = _student.imie;
	nazwisko = _student.nazwisko;
	semestr = _student.semestr;

	srednia = new int[LICZBA_SEMESTROW];

	for (int i = 0; i < semestr; i++)
	{
		if (semestr <= LICZBA_SEMESTROW)
			this->srednia[i] = _student.srednia[i];
	}

	clog << ">>> wywolano konstruktor kopiujacy obiektu [" << this << "]" << endl;
	liczba_studentow++;
}

student::student(student&& _student) noexcept
{
	imie = _student.imie;
	nazwisko = _student.nazwisko;
	semestr = _student.semestr;

	srednia = _student.srednia;
	_student.srednia = nullptr;

	clog << ">>> wywolano konstruktor przenoszacy obiektu [" << this << "]" << endl;
	liczba_studentow++;
}

student::student(const student& _student, int numer_legitymacji) :numer_legitymacji(numer_legitymacji)
{
	imie = _student.imie;
	nazwisko = _student.nazwisko;
	semestr = _student.semestr;

	srednia = new int[LICZBA_SEMESTROW];

	for (int i = 0; i < semestr; i++)
	{
		if (semestr <= LICZBA_SEMESTROW)
			this->srednia[i] = _student.srednia[i];
	}

	clog << ">>> wywolano konstruktor kopiujacy obiektu [" << this << "]" << endl;
	liczba_studentow++;
}

void student::dodaj_srednia(int srednia)
{
	if (semestr <= LICZBA_SEMESTROW)
		this->srednia[semestr++] = srednia;
}

void student::dodaj_srednia(const std::initializer_list<int>& srednie)
{
	for (auto const& srednia: srednie)
	{
		if (semestr <= LICZBA_SEMESTROW)
			this->srednia[semestr++] = srednia;
	}
}

void student::wyswietl(void)
{
	cout << "Nazwisko: " << nazwisko << " | ";
	cout << "Imie: " << imie << " | ";
	cout << "Nr leg.: " << numer_legitymacji << endl;

	cout << "Semestr: " << semestr << " | Oceny:";
	if ((semestr == 0) || (srednia == nullptr)) cout << " brak";
	else
	{
		for (int i = 0; i < semestr; i++)
			cout << " " << srednia[i];
	}
	cout << endl << "Liczba studentow: " << liczba_studentow << endl;
}


student::~student()
{
	delete[] srednia;

	clog << ">>> wywolano destruktor obiektu [" << this << "]" << endl;
	cout << "Liczba studentow: " << --liczba_studentow << endl;
}

void student::nazwisko_set(string _nazwisko)
{
	nazwisko = _nazwisko;
}

string student::nazwisko_get()
{
	return nazwisko;
}

void student::imie_set(string _imie)
{
	imie = _imie;
}

string student::imie_get()
{
	return imie;
}

int student::numer_legitymacji_get()
{
	return numer_legitymacji;
}

int student::semestr_get(void)
{
	return semestr;
}

void student::srednia_get(int*& _srednia, int _semestr)
{
	for (int i = 0; i < _semestr; i++)
	{
		if (i < semestr)
			_srednia[i] = srednia[i];
	}
}
