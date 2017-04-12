// lab_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Person
{
private:
	char name[21];
	char surname[21];
	char middleName[21];
	int age;
public:
	Person()
	{
	}
	Person(char sName[21], char sSurname[21], char sMiddleName[21], int sAge)
	{
		setPerson(sName, sSurname, sMiddleName, sAge);
	}

	void setPerson(char _surname[21], char _name[21], char _middleName[21], int _age)
	{
		strcpy_s(surname, _surname);
		strcpy_s(name, _name);
		strcpy_s(middleName, _middleName);
		age = _age;
	}

	void setAge()
	{
		do
		{
			cout << "Введите возраст(0..200): ";
			cin >> age;
		} while ((age >= 0) || (age <= 200));
	}

	void setName()
	{
		do
		{
			cout << "Введете имя(не более 20 символов): ";
			cin >> name;
		} while ((strlen(name) > 0) || (strlen(name) <= 20));
	}

	void setSurname()
	{
		do
		{
			cout << "Введете фамилию(не более 20 символов) : ";
			cin >> surname;
		} while ((strlen(surname) > 0) || (strlen(surname) <= 20));
	}

	void setMiddleName()
	{
		do
		{
			cout << "Введете отчество(не более 20 символов): ";
			cin >> middleName;
		} while ((strlen(middleName) > 0) || (strlen(middleName) <= 20));
	}

	int getAge()
	{
		return age;
	}

	char* getName()
	{
		return name;
	}

	char* getSurname()
	{
		return surname;
	}

	char* getMiddleName()
	{
		return middleName;
	}

	void personInfo()
	{
		cout << getSurname() << " " << getName() << " " << getMiddleName() << ". Возраст: " << getAge() << endl;
	}

};

class Cashbox
{
private:
	Person cashier;
	Person client;

public:
	Cashbox(Person _cashier)
	{
		cashier = _cashier;
	}
	void setClient(Person _client)
	{
		client = _client;
		if((strcmp(client.getName(), cashier.getName())==0) && (strcmp(client.getSurname(), cashier.getSurname())==0) && (strcmp(client.getMiddleName(), cashier.getMiddleName())==0))
		{
			cout << "ФИО клиента совпадает с ФИО кассира!" << endl;
		}
	}

	void printInfo()
	{
		cout << "Кассир: ";
		cashier.personInfo();
		cout << "Клиент: ";
		client.personInfo();
	}
};


int main()
{
	setlocale(LC_CTYPE, "rus");
	Person cashier("Иванов", "Василий", "Васильевич", 18);
	cashier.personInfo();

	Cashbox cashbox(cashier);

	Person client("Васин", "Иван", "Васильевич", 18);
	cashbox.setClient(client);

	cashbox.printInfo();

	cashbox.setClient(cashier);

	cashbox.printInfo();
	
	return 0;
}