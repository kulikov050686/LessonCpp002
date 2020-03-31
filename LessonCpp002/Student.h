/// Модель студента
#pragma once
#include <string>
#include <fstream>
using namespace std;

class Student
{
	/// Имя студента
	string Name ;

	/// Фамилия студента
	string Surname;

	/// Возраст студента
	int Age;

public:

	/// Конструктор по умолчанию
	Student();

	/// Конструктор конкретного студента
	Student(string name, string surname, int age);

	/// Получить имя студента
	string getName();

	/// Задать имя студента
	void setName(string name);

	/// Получить фамилию студента
	string getSurname();

	/// Задать фамилию студента
	void setSurname(string surname);

	/// Получить возраст студента
	int getAge();

	/// Задать возраст студента
	void setAge(int age);

	/// Оператор для записи полей класса в файл
	friend ofstream& operator << (ofstream& fout, const Student& obj);

	/// Оператор для считывания из файла полей класса
	friend ifstream& operator >> (ifstream& fin, Student& obj);

	/// Деструктор 
	~Student();
};

