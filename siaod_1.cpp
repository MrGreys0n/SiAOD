/*
1.	����������, ������� ��� � ������� ����������� ������������ �������� � ������������ ������ �������� ���� ���������.
2.	������� ��� ������������ ��������, ��������� ������ �� ��������.
3.	���� � ������� ������ ���� ������������ ��������, �� �������� ����� �� �������� � ������.
*/


#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream>
using namespace std;
const int LEN = 20;


void outputVector(vector<int>& vec) //������� ������ �������
{
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
}

int maxNum(int* mas) //�������, ��������� ������������ ��������
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int maxNum(vector<int>& mas) //�������, ��������� ������������ ��������
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int countMaxNums(int* mas) //�������, ��������� ������������ ��������
{
	int maximum = maxNum(mas), counter = 0;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maximum)
			counter++;
	}
	return counter;
}

int countMaxNums(vector<int>& mas) //�������, ��������� ������������ �������� �������
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

void int_massiv_stat_dyn(int* a) //���������� ����� ��������� ����������� ��� ������������ ������
{
	srand(time(0)); // ������������� ��������� ��������� �����
	//���������� ����� ��������� ������ �� LEN ��������
	for (int i = 0; i < LEN; i++)
		a[i] = -10 + rand() % 20;
	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // ����� ���������� �� ������
	cout << "\n";
}

void inputVector(vector<int>& a)
{
	srand(time(0)); // ������������� ��������� ��������� �����
	//���������� ����� ��������� ����� �� LEN ��������
	for (int i = 0; i < LEN; i++)
		a[i] = (-10 + rand() % 20);

	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // ����� ���������� �� ������
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
	cout << "������ ����� ���������:";
	outputVector(v);
}

void changetovec(int* mass, vector<int>& v) // ������� ������� �������� ��� ������������ � ������������� ��������
{
	for (int i = 0; i < LEN; ++i)
		v.push_back(mass[i]); // ��������� �� �� ������������ ������� � ������
	int x = countMaxNums(mass);
	if (x == 1)
		v.push_back(maxNum(mass));
	else
	{
		int* s = findMaximums(mass);
		for (int i = 0; i < x; i++)
			v.erase(v.begin() + s[i] - i);
	}
	cout << "������ ����� ���������:";
	outputVector(v);
}


int main()
{
	setlocale(LC_ALL, "");
	cout << "������������ ������ �1 �������� ������" << endl;
	bool s;
	int arr[LEN];
	int arr1[LEN];
	vector<int> vect; //������ ������ ��� �������� �������

	cout << "�������� ������:" << endl << "1 - �����������" << endl << "2 - ������������" << endl << "3 - ������" << endl;
	int mode, size;
	do
	{
		cin >> mode;
		if (mode < 1 || mode > 3) cout << "������ ������ ���. ������� ����� �� 1 �� 3: ";
	} while (mode < 1 || mode > 3);


	switch (mode)
	{
		case 1:
		{//����������� ������

			bool s;
			int arr[LEN];
			int arr1[LEN];
			vector<int> vect; //������ ������ ��� �������� �������

			cout << "����������� �������������� �������� ������: " << endl;
			int_massiv_stat_dyn(arr); //������� ������������� ������ ������� LEN
			cout << "������������ �������: " << maxNum(arr) << ", ���-�� ����. ���������: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 2:
		{ //������������ ������
			bool s;
			int* dynny = new int[LEN];
			int* dynny1 = new int[LEN];
			vector<int> vect; //������ ������ ��� �������� �������

			cout << "����������� �������������� �������� ������: " << endl;
			int_massiv_stat_dyn(arr); //������� ������������� ������ ������� LEN
			cout << "������������ �������: " << maxNum(arr) << ", ���-�� ����. ���������: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 3:
		{//������
			bool s;
			vector<int> victor(LEN); //�������������� ������
			cout << "����������� �������������� �������� ������: " << endl;
			inputVector(victor);
			cout << "������������ �������: " << maxNum(victor) << ", ���-�� ����. ���������: " << countMaxNums(victor) << endl << endl;
			changetovec(victor);
			break;
		}
	}
}
