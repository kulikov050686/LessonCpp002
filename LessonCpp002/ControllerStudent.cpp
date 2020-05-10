#include "ControllerStudent.h"

void ControllerStudent::CreateDeleteVariable(int numberofstudent)
{
	if (student == nullptr)
	{
		if (numberofstudent >= 1)
		{
			student = new Student[numberofstudent];
		}
		else
		{
			cout << "Error!!!" << endl;
			student = nullptr;
		}
	}
	else
	{
		delete[] student;

		if (numberofstudent >= 1)
		{
			student = new Student[numberofstudent];
		}
		else
		{
			cout << "Error!!!" << endl;
			student = nullptr;
		}
	}	
}

ControllerStudent::ControllerStudent()
{
	NumberOfStudents = 0;
	AgeStudent = 0;
	student = nullptr;
}

ControllerStudent::ControllerStudent(const ControllerStudent& object)
{
	if (student != nullptr)
	{
		delete[] student;
	}

	this->Path = object.Path;
	this->AgeStudent = object.AgeStudent;
	this->NumberOfStudents = object.NumberOfStudents;
	this->NameStudent = object.NameStudent;
	this->SurnameSrudent = object.SurnameSrudent;

	if (object.student != nullptr)
	{
		this->student = new Student[object.NumberOfStudents];

		for (int i = 0; i < object.NumberOfStudents; i++)
		{
			this->student[i] = object.student[i];
		}
	}
}

bool ControllerStudent::Add(int numberofstudent)
{
	if (numberofstudent >= 1)
	{
		NumberOfStudents = numberofstudent;

		CreateDeleteVariable(NumberOfStudents);

		for (int i = 0; i < NumberOfStudents; i++)
		{
			cout << "Name: ";
			cin >> NameStudent;
			student[i].setName(NameStudent);

			cout << "Surname: ";
			cin >> SurnameSrudent;
			student[i].setSurname(SurnameSrudent);

			cout << "Age: ";
			cin >> AgeStudent;
			student[i].setAge(AgeStudent);

			cout << endl;
		}
		cout << "-------------------------------------------------------" << endl;

		return true;
	}

	return false;
}

bool ControllerStudent::SaveWhole(string path)
{
	if (student != nullptr)
	{
		Path = path;
		ofstream outFile;

		outFile.open(Path, ofstream::out);

		if (!outFile.is_open())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < NumberOfStudents; i++)
			{
				outFile << student[i];
			}
		}

		outFile.close();

		return true;
	}

	return false;
}

bool ControllerStudent::SaveToEnd(string path)
{
	if (student != nullptr)
	{		
		Path = path;
		ofstream outFile; 
		
		outFile.open(Path, ofstream::app);

		if (!outFile.is_open())
		{
			return false;
		}
		else
		{
			for (int i = 0; i < NumberOfStudents; i++)
			{
				outFile << student[i];
			}
		}

		outFile.close();

		return true;
	}

	return false;
}

bool ControllerStudent::ReadData(string path)
{
	Path = path;
	NumberOfStudents = 0;
	ifstream inFile;

	inFile.open(Path);

	if (!inFile.is_open())
	{
		return false;
	}
	else
	{		
		Student temp;

		while (inFile >> temp)
		{
			NumberOfStudents++;
		}

		CreateDeleteVariable(NumberOfStudents);

		inFile.clear();
		inFile.seekg(0, ios::beg);

		int i = 0;

		while (inFile >> temp)
		{
			student[i].setName(temp.getName());
			student[i].setSurname(temp.getSurname());
			student[i].setAge(temp.getAge());

			i++;
		}
	}

	inFile.close();	

	return true;
}

bool ControllerStudent::ChangeData(int number)
{
	if (student != nullptr)
	{
		if (0 <= number && number < NumberOfStudents)
		{
			cout << "Name: ";
			cin >> NameStudent;
			student[number].setName(NameStudent);

			cout << "Surname: ";
			cin >> SurnameSrudent;
			student[number].setSurname(SurnameSrudent);

			cout << "Age: ";
			cin >> AgeStudent;
			student[number].setAge(AgeStudent);

			cout << "-------------------------------------------------" << endl;

			return true;
		}		
	}

	return false;
}

bool ControllerStudent::Delete(int number)
{
	if (student != nullptr)
	{
		if (0 <= number && number < NumberOfStudents)
		{
			Student* temp = new Student[NumberOfStudents];

			for(int i = 0; i < NumberOfStudents; i++)
			{
				temp[i].setName(student[i].getName());
				temp[i].setSurname(student[i].getSurname());
				temp[i].setAge(student[i].getAge());
			}

			NumberOfStudents--;
			CreateDeleteVariable(NumberOfStudents);

			int j = 0;

			for (int i = 0; i < NumberOfStudents; i++)
			{
				if (i == number)
				{
					j++;
				}
				
				student[i].setName(temp[j].getName());
				student[i].setSurname(temp[j].getSurname());
				student[i].setAge(temp[j].getAge());
				j++;
			}

			delete[] temp;
			return true;
		}
	}

	return false;
}

void ControllerStudent::Show()
{
	for (int i = 0; i < NumberOfStudents; i++)
	{
		cout << "Name: " << student[i].getName() << endl;
		cout << "Surname: " << student[i].getSurname() << endl;
		cout << "Age: " << student[i].getAge() << endl;
		cout << endl;
	}

	cout << "---------------------------------------------------" << endl;
}

int ControllerStudent::getNumberOfStudents()
{
	return this->NumberOfStudents;
}

ControllerStudent::~ControllerStudent()
{
	delete[] student;	
}
