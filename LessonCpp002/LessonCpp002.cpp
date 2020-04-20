#include <iostream>
#include <string>
#include "ControllerStudent.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	string path = "myFile.txt";

	ControllerStudent* controllerStudent = new ControllerStudent();

	controllerStudent->Add(3);             // Создаём список студентов
	controllerStudent->Show();             // Печать списока студентов
	controllerStudent->SaveWhole(path);    // Сохраняем списов в файл

	cin.get();

	controllerStudent->ReadData(path);     // Читам список студентов из файла
	controllerStudent->Show();             // Печать списка студентов

	cin.get();

	controllerStudent->ChangeData(2);      // Меняем данные студента по номеру в массиве
	controllerStudent->Show();             // Печать списока студентов
	controllerStudent->SaveWhole(path);    // Сохраняем списов в файл

	cin.get();

	controllerStudent->ReadData(path);     // Читам список студентов из файла
	controllerStudent->Show();             // Печать списка студентов

	cin.get();

	controllerStudent->Delete(0);          // Удаляем стадента по номеру в массиве
	controllerStudent->Show();             // Печать списока студентов
	controllerStudent->SaveWhole(path);    // Сохраняем списов в файл

	cin.get();

	controllerStudent->ReadData(path);     // Читам список студентов из файла
	controllerStudent->Show();             // Печать списка студентов

	cin.get();

	delete controllerStudent;
	return 0;
}