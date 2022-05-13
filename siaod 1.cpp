/*
1.	Îïðåäåëèòü, ñêîëüêî ðàç â ìàññèâå âñòðå÷àåòñÿ ìàêñèìàëüíîå çíà÷åíèå è ñôîðìèðîâàòü ìàññèâ èíäåêñîâ ýòèõ ýëåìåíòîâ.
2.	Óäàëèòü âñå ìàêñèìàëüíûå çíà÷åíèÿ, èñïîëüçóÿ ìàññèâ èõ èíäåêñîâ.
3.	Åñëè â ìàññèâå òîëüêî îäíî ìàêñèìàëüíîå çíà÷åíèå, òî äîáàâèòü òàêîå æå çíà÷åíèå â ìàññèâ.
*/


#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream>
using namespace std;
const int LEN = 20;


void outputVector(vector<int>& vec) //ôóíêöèÿ âûâîäà âåêòîðà
{
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
}

int maxNum(int* mas) //ôóíêöèÿ, íàõîäÿùàÿ ìàêñèìàëüíîå çíà÷åíèå
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int maxNum(vector<int>& mas) //ôóíêöèÿ, íàõîäÿùàÿ ìàêñèìàëüíîå çíà÷åíèå
{
	int maximum = -200000000;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] > maximum)
			maximum = mas[i];
	}
	return maximum;
}

int countMaxNums(int* mas) //ôóíêöèÿ, íàõîäÿùàÿ ìàêñèìàëüíîå çíà÷åíèå
{
	int maximum = maxNum(mas), counter = 0;
	for (int i = 0; i < LEN; i++)
	{
		if (mas[i] == maximum)
			counter++;
	}
	return counter;
}

int countMaxNums(vector<int>& mas) //ôóíêöèÿ, íàõîäÿùàÿ ìàêñèìàëüíîå çíà÷åíèå âåêòîðà
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

void int_massiv_stat_dyn(int* a) //ãåíåðèðóåì öåëûé ñëó÷àéíûé ÑÒÀÒÈ×ÅÑÊÈÉ ÈËÈ ÄÈÍÀÌÈ×ÅÑÊÈÉ ìàññèâ
{
	srand(time(0)); // èíèöèàëèçàöèÿ ãåíåðàöèè ñëó÷àéíûõ ÷èñåë
	//ãåíåðèðóåì öåëûé ñëó÷àéíûé ìàññèâ èç LEN ýëìåíòîâ
	for (int i = 0; i < LEN; i++)
		a[i] = -10 + rand() % 20;
	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // âûâîä ðåçóëüòàòà íà ýêðàíå
	cout << "\n";
}

void inputVector(vector<int>& a)
{
	srand(time(0)); // èíèöèàëèçàöèÿ ãåíåðàöèè ñëó÷àéíûõ ÷èñåë
	//ãåíåðèðóåì öåëûé ñëó÷àéíûé âåêòî èç LEN ýëìåíòîâ
	for (int i = 0; i < LEN; i++)
		a[i] = (-10 + rand() % 20);

	for (int i = 0; i < LEN; i++)
		cout << a[i] << " "; // âûâîä ðåçóëüòàòà íà ýêðàíå
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
	cout << "Ìàññèâ ïîñëå èçìåíåíèé:";
	outputVector(v);
}

void changetovec(int* mass, vector<int>& v) // ôóíêöèÿ âñòàâêè ýëåìåíòà äëÿ ñòàòè÷åñêîãî è äèíàìè÷åñêîãî ìàññèâîâ
{
	for (int i = 0; i < LEN; ++i)
		v.push_back(mass[i]); // çàïèõíóëè âñ¸ èç íåèçìåí¸ííîãî ìàññèâà â âåêòîð
	int x = countMaxNums(mass);
	if (x == 1)
		v.push_back(maxNum(mass));
	else
	{
		int* s = findMaximums(mass);
		for (int i = 0; i < x; i++)
			v.erase(v.begin() + s[i] - i);
	}
	cout << "Ìàññèâ ïîñëå èçìåíåíèé:";
	outputVector(v);
}


int main()
{
	setlocale(LC_ALL, "");
	cout << "Ïðàêòè÷åñêàÿ ðàáîòà ¹1 Ñàâåëüåâ Ñåðãåé" << endl;
	bool s;
	int arr[LEN];
	int arr1[LEN];
	vector<int> vect; //ïóñòîé âåêòîð äëÿ òðåòüåãî çàäàíèÿ

	cout << "Âûáåðèòå ìàññèâ:" << endl << "1 - ñòàòè÷åñêèé" << endl << "2 - äèíàìè÷åñêèé" << endl << "3 - âåêòîð" << endl;
	int mode, size;
	do
	{
		cin >> mode;
		if (mode < 1 || mode > 3) cout << "Òàêîãî ðåæèìà íåò. Ââåäèòå ÷èñëî îò 1 äî 3: ";
	} while (mode < 1 || mode > 3);


	switch (mode)
	{
		case 1:
		{//Ñòàòè÷åñêèé ìàññèâ

			bool s;
			int arr[LEN];
			int arr1[LEN];
			vector<int> vect; //ïóñòîé âåêòîð äëÿ òðåòüåãî çàäàíèÿ

			cout << "Èçíà÷àëüíûé ñôîðìèðîâàííûé ðàíäîìíî ìàññèâ: " << endl;
			int_massiv_stat_dyn(arr); //ñîçäàëè öåëî÷èñëåííûé ìàññèâ ðàçìåðà LEN
			cout << "Ìàêñèìàëüíûé ýëåìåíò: " << maxNum(arr) << ", êîë-âî ìàêñ. ýëåìåíòîâ: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 2:
		{ //Äèíàìè÷åñêèé ìàññèâ
			bool s;
			int* dynny = new int[LEN];
			int* dynny1 = new int[LEN];
			vector<int> vect; //ïóñòîé âåêòîð äëÿ òðåòüåãî çàäàíèÿ

			cout << "Èçíà÷àëüíûé ñôîðìèðîâàííûé ðàíäîìíî ìàññèâ: " << endl;
			int_massiv_stat_dyn(arr); //ñîçäàëè öåëî÷èñëåííûé ìàññèâ ðàçìåðà LEN
			cout << "Ìàêñèìàëüíûé ýëåìåíò: " << maxNum(arr) << ", êîë-âî ìàêñ. ýëåìåíòîâ: " << countMaxNums(arr) << endl << endl;
			changetovec(arr, vect);
			break;
		}
		case 3:
		{//âåêòîð
			bool s;
			vector<int> victor(LEN); //èíèöèàëèçèðóåì âåêòîð
			cout << "Èçíà÷àëüíûé ñôîðìèðîâàííûé ðàíäîìíî ìàññèâ: " << endl;
			inputVector(victor);
			cout << "Ìàêñèìàëüíûé ýëåìåíò: " << maxNum(victor) << ", êîë-âî ìàêñ. ýëåìåíòîâ: " << countMaxNums(victor) << endl << endl;
			changetovec(victor);
			break;
		}
	}
}
