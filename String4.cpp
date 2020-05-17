#include <iostream>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StringLength(char str[], const int n);
void ToUpper(char str[]);
void ToLower(char str[]);
void Shrink(char str[]);
bool check_polindrom(string word);


void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StringLength(char str[], const int n)
{
	int temp = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] != '\0')temp++; else return temp;
	}
}
void ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		if (str[i] >= 'а' && str[i] <= 'я') {
			str[i] = str[i] - 32;
		}
	}
}
void ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
		if (str[i] >= 'А' && str[i] <= 'Я') {
			str[i] = str[i] + 32;
		}
	}
}
void Shrink(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == '\t')str[i] = ' ';
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
		{
			for (int j = i--; str[j]; ++j)
			{
				str[j] = str[j + 1];
			}
		}
	}
}


	bool check_polindrom(string word)
	{
		int len = word.length();
		for (int i = 0; i < len / 2; ++i)
		{
			if (word[i] != word[len - i - 1])
			{
				return false;
			}
		}
		return true;
	}

	void main()
	{
		setlocale(LC_ALL, "");
		/*cout << "Hello World" << endl;
		cout << sizeof("Hello") << endl;
		cout << typeid("Hello").name() << endl;

		char str[] = { 'H','e','l','l','o',0 };
		cout << str << endl;
		cout << typeid(str).name() << endl;
		*/
		/*char str[] = "Hello";
		cout << str << endl;
		cout << sizeof(str) << endl;
		cout << typeid(str).name() << endl;

		const char* str1 = "Hello";---
		cout << str1 << endl;
		cout << sizeof(str1) << endl;
		cout << typeid(str1).name() << endl;*/

		const int n = 256;
		char str[n] = {};
		cout << "Введите строку: ";
		//cin >> str;
		InputLine(str, n);
		cout << str << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << str[i];
		}
		cout << endl;
		cout << StringLength(str, n);

		Shrink(str);
		for (int i = 0; i < n; ++i)
		{
			cout << str[i];
		}
		string str;
		cout << "Enter the word: ";
		cin >> str;
		if (check_polindrom(str))
		{
			cout << "Word is polindrom.";
		}
		else
		{
			cout << "Word is not polindrom";
		}
		return ;
	}