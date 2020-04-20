#include "Student.h"

Student::Student()
{
	this->Name = "Name";
	this->Surname = "Surname";
	this->Age = 18;
}

Student::Student(const Student& object)
{
	this->Age = object.Age;
	this->Name = object.Name;
	this->Surname = object.Surname;
}

Student::Student(string name, string surname, int age)
{
	this->Name = name;
	this->Surname = surname;
	this->Age = age;
}

string Student::getName()
{
	return this->Name;
}

void Student::setName(string name)
{
	this->Name = name;
}

string Student::getSurname()
{
	return this->Surname;
}

void Student::setSurname(string surname)
{
	this->Surname = surname;
}

int Student::getAge()
{
	return this->Age;
}

void Student::setAge(int age)
{
	this->Age = age;
}

Student::~Student()
{
	
}

ofstream& operator << (ofstream& fout, const Student& obj)
{
	fout << obj.Name << endl;
	fout << obj.Surname << endl;
	fout << obj.Age << endl;

	return fout;
}

ifstream& operator >> (ifstream& fin, Student& obj)
{
	getline(fin, obj.Name);
	getline(fin, obj.Surname);
	fin >> obj.Age;
	fin.get();

	return fin;
}
