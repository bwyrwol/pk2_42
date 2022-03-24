#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <initializer_list>

constexpr auto LICZBA_SEMESTROW = 7;

class student
{
private:
	static int liczba_studentow;

	std::string nazwisko;
	std::string imie;
	const int numer_legitymacji = 0;

	int semestr = 0;
	int* srednia;

public:
	student();
	student(std::string nazwisko, std::string imie, int numer_legitymacji);
	student(const student& _student);
	student(const student& _student, int numer_legitymacji);
	student(student&& _student) noexcept;
	
	~student();

	void dodaj_srednia(int srednia);
	void dodaj_srednia(const std::initializer_list<int>& srednie);
	void wyswietl(void);

	void nazwisko_set(std::string _nazwisko);
	std::string nazwisko_get(void);
	void imie_set(std::string _imie);
	std::string imie_get(void);
	int numer_legitymacji_get(void);
	int semestr_get(void);
	void srednia_get(int*& srednia, int semestr);
};

#endif//STUDENT_H