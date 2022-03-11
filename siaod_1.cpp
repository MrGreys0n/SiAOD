/*
1.	Определить, сколько раз в массиве встречается максимальное значение и сформировать массив индексов этих элементов.
2.	Удалить все максимальные значения, используя массив их индексов.
3.	Если в массиве только одно максимальное значение, то добавить такое же значение в массив.
*/


#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream>
using namespace std;
const int LEN = 20;


void outputVector(vector<int>& vec) //функция вывода вектора
{
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
}

int maxNum(int* mas) //функция, находящая максимальное значение
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int maxNum(vector<int>& mas) //функция, находящая максимальное значение
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int countMaxNums(int* mas) //функция, находящая максимальное значение
{
	int maximum = maxNum(mas), counter = 0;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maximum)
			counter++;
	}
	return counter;
}

int countMaxNums(vector<int>& mas) //функция, находящая максимальное значение вектора
{
	int maximum = maxNum(mas), counter = 0;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maximum)
			counter++;
	}
	return counter;
}

auto findMaximums(int* mas)
{
	int counter = countMaxNums(mas);
	int maxOfMas = maxNum(mas);
	int c = 0;
	int *listOfIndexes = new int[counter];
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maxOfMas)
		{
			listOfIndexes[c] = i;
			c++;
		}
	}
	return listOfIndexes;
}

auto findMaximums(vector<int>& mas)
{
	int counter = countMaxNums(mas);
	int maxOfMas = maxNum(mas);
	int c = 0;
	int* listOfIndexes = new int[counter];
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maxOfMas)
		{
			listOfIndexes[c] = i;
			c++;
		}
	}
	return listOfIndexes;
}

void int_massiv_stat_dyn(int* a) //генерируем целый случайный СТАТИЧЕСКИЙ ИЛИ ДИНАМИЧЕСКИЙ массив
{
	srand(time(0)); // инициализация генерации случайных чисел
	//генерируем целый случайный массив из LEN элментов
	for (int i = 0; i < LEN; i++)
		a[i] = -10 + rand() % 20;
	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // вывод результата на экране
	cout << "\n";
}

void inputVector(vector<int>& a)
{
	srand(time(0)); // инициализация генерации случайных чисел
	//генерируем целый случайный векто из LEN элментов
	for (int i = 0; i < LEN; i++)
		a[i] = (-10 + rand() % 20);

	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // вывод результата на экране
	cout << "\n";
}

void changetovec(vector<int>& v)
{
	int x = countMaxNums(v);
	if (x == 1)
		v.push_back(maxNum(v));
	else
	{
		int* s = findMaximums(v);
		for (int i = 0; i < x; i++)
			v.erase(v.begin() + s[i] - i);
	}
	cout << "Массив после изменений:";
	outputVector(v);
}

void changetovec(int* mass, vector<int>& v) // функция вставки элемента для статического и динамического массивов
{
	for (int i = 0; i < LEN; ++i)
		v.push_back(mass[i]); // запихнули всё из неизменённого массива в вектор
	int x = countMaxNums(mass);
	if (x == 1)
		v.push_back(maxNum(mass));
	else
	{
		int* s = findMaximums(mass);
		for (int i = 0; i < x; i++)
			v.erase(v.begin() + s[i] - i);
	}
	cout << "Массив после изменений:";
	outputVector(v);
}


int main()
{
	setlocale(LC_ALL, "");
	cout << "Практическая работа №1 Савельев Сергей" << endl;
	bool s;
	int arr[LEN];
	int arr1[LEN];
	vector<int> vect; //пустой вектор для третьего задания

	cout << "Выберите массив:" << endl << "1 - статический" << endl << "2 - динамический" << endl << "3 - вектор" << endl;
	int mode, size;
	do
	{
		cin >> mode;
		if (mode < 1 || mode > 3) cout << "Такого режима нет. Введите число от 1 до 3: ";
	} while (mode < 1 || mode > 3);


	switch (mode)
	{
		case 1:
		{//Статический массив

			bool s;
			int arr[LEN];
			int arr1[LEN];
			vector<int> vect; //пустой вектор для третьего задания

			cout << "Изначальный сформированный рандомно массив: " << endl;
			int_massiv_stat_dyn(arr); //создали целочисленный массив размера LEN
			cout << "Максимальный элемент: " << maxNum(arr) << ", кол-во макс. элементов: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 2:
		{ //Динамический массив
			bool s;
			int* dynny = new int[LEN];
			int* dynny1 = new int[LEN];
			vector<int> vect; //пустой вектор для третьего задания

			cout << "Изначальный сформированный рандомно массив: " << endl;
			int_massiv_stat_dyn(arr); //создали целочисленный массив размера LEN
			cout << "Максимальный элемент: " << maxNum(arr) << ", кол-во макс. элементов: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 3:
		{//вектор
			bool s;
			vector<int> victor(LEN); //инициализируем вектор
			cout << "Изначальный сформированный рандомно массив: " << endl;
			inputVector(victor);
			cout << "Максимальный элемент: " << maxNum(victor) << ", кол-во макс. элементов: " << countMaxNums(victor) << endl << endl;
			changetovec(victor);
			break;
		}
	}
}
