/// ������ ��������
#pragma once
#include <string>
#include <fstream>
using namespace std;

class Student
{
	/// ��� ��������
	string Name ;

	/// ������� ��������
	string Surname;

	/// ������� ��������
	int Age;

public:

	/// ����������� �� ���������
	Student();

	/// ����������� ����������� ��������
	Student(string name, string surname, int age);

	/// �������� ��� ��������
	string getName();

	/// ������ ��� ��������
	void setName(string name);

	/// �������� ������� ��������
	string getSurname();

	/// ������ ������� ��������
	void setSurname(string surname);

	/// �������� ������� ��������
	int getAge();

	/// ������ ������� ��������
	void setAge(int age);

	/// �������� ��� ������ ����� ������ � ����
	friend ofstream& operator << (ofstream& fout, const Student& obj);

	/// �������� ��� ���������� �� ����� ����� ������
	friend ifstream& operator >> (ifstream& fin, Student& obj);

	/// ���������� 
	~Student();
};

