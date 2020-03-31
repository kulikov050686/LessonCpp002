#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
using namespace std;

class ControllerStudent
{
	/// Путь и название файла
	string Path;

	/// Количество студентов
	int NumberOfStudents;

	/// Массив студентов
	Student* student;

	/// Имя студента
	string NameStudent;

	/// Фамилия студента
	string SurnameSrudent;

	/// Возраст студента
	int AgeStudent;

	/// Создание, удаление динамического массива
	void CreateDeleteVariable(int numberofstudent);

public:
	/// Конструктор по умолчанию
	ControllerStudent();

	/// Добавить некоторое количество студентов
	bool Add(int numberofstudent);

	/// Файл перезаписывается целиком
	bool SaveWhole(string path);

	/// Сохранить в конец файла
	bool SaveToEnd(string path);

	/// Читает данные из файла
	bool ReadData(string path);

	/// Изменить данные по номеру
	bool ChangeData(int number);

	/// Удалить данные по номеру
	bool Delete(int number);

	/// Вывод данных
	void Show();

	// Получить количество студентов
	int getNumberOfStudents();
	
	/// Деструктор
	~ControllerStudent();
};

