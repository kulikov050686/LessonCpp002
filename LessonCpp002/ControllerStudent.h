#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
using namespace std;

class ControllerStudent
{
	/// ���� � �������� �����
	string Path;

	/// ���������� ���������
	int NumberOfStudents;

	/// ������ ���������
	Student* student;

	/// ��� ��������
	string NameStudent;

	/// ������� ��������
	string SurnameSrudent;

	/// ������� ��������
	int AgeStudent;

	/// ��������, �������� ������������� �������
	void CreateDeleteVariable(int numberofstudent);

public:
	/// ����������� �� ���������
	ControllerStudent();

	/// �������� ��������� ���������� ���������
	bool Add(int numberofstudent);

	/// ���� ���������������� �������
	bool SaveWhole(string path);

	/// ��������� � ����� �����
	bool SaveToEnd(string path);

	/// ������ ������ �� �����
	bool ReadData(string path);

	/// �������� ������ �� ������
	bool ChangeData(int number);

	/// ������� ������ �� ������
	bool Delete(int number);

	/// ����� ������
	void Show();

	// �������� ���������� ���������
	int getNumberOfStudents();
	
	/// ����������
	~ControllerStudent();
};

