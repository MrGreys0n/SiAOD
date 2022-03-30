#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


/*���� ������� � ��������� ��������� � ���������� ������� ������ ����.
��������� ������ �� ���������� �������: ����� ������, ��� ����������, ���� ������, ����� ����, ����� ���������.
���������� ��������� ��� �������� �������� �� ���������� ���� � ������������ � ������ ��������� �������. 
��������
1)	���������� ������ �� ���������� ������� � ����������. ����� ��������� ������ ���� ������ �� ������� ����� ���������.
2)	�������� ������ ���, ����� ������� ������ ��� ������ ���������� ��������� ���������. ������ ��������� � ����� ������ ���������.
3)	������� ������ �� ���������� �� �������� ���������� (�� ����)/
4)	������� ���������� �� �������� ���������� (�� ����).
*/

struct Lesson
{
	string number_of_group; 
	string code_of_dis; 
	string day; 
	string aud; 
	string pair;
};

Lesson addLesson()
{
	Lesson lesson;

	cout << "������� ����� ������: " << endl;
	cin >> lesson.number_of_group;

	cout << "������� ��� ����������: " << endl;
	cin >> lesson.code_of_dis;

	cout << "������� ���� ������: " << endl;
	cin >> lesson.day;

	cout << "������� ����� ����: " << endl;
	cin >> lesson.pair;

	cout << "������� ����� ���������: " << endl;
	cin >> lesson.aud;

	return lesson;
}

void addLessonInTable(Lesson lesson, vector<vector<vector<string>>> &array, int n)
{
	vector<string> lessonTable(5);
	bool f = true;
	vector<vector<string>> temp;

	lessonTable[0] = lesson.number_of_group;
	lessonTable[1] = lesson.code_of_dis;
	lessonTable[2] = lesson.day;
	lessonTable[3] = lesson.pair;
	lessonTable[4] = lesson.aud;

	for (int i = 0; i < array.size(); i++)
	{
		if (array[i][0].size() > 1 && array[i][0][2] == lesson.day)
		{
			array[i].push_back(lessonTable);
			f = false;
			break;
		}
	}
	if (f)
	{
		temp.push_back(lessonTable);
		array.push_back(temp);
	}
}

void printArray(vector<vector<vector<string>>> vector) {
	int i, j, k;
	for (i = 0; i < vector.size(); i++)
	{
		for (j = 0; j < vector[i].size(); j++)
		{
			for (k = 0; k < 5; k++)
				cout << setw(7) << vector[i][j][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printArrayByCode(vector<vector<vector<string>>> vector) {
	int i, j, k;
	string n;
	cout << "������� ��� ���������� ��� ������: ";
	cin >> n;
	for (i = 0; i < vector.size(); i++)
	{
		for (j = 0; j < vector[i].size(); j++)
		{
			if (vector[i][j][1] == n)
				for (k = 0; k < 5; k++)
					cout << setw(7) << vector[i][j][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void deleteLesson(vector<vector<vector<string>>>& array)
{
	int i, j, k;
	string n;
	cout << "������� ��� ���������� ��� ��������: ";
	cin >> n;
	for (i = 0; i < array.size(); i++)
	{
		for (j = 0; j < array[i].size(); j++)
		{
			if (array[i][j][1] == n)
				array[i].erase(array[i].begin() + j);
		}
		if (array[i].size() == 0) array.erase(array.begin() + i);
	}
}

int main() {
	setlocale(LC_ALL, "");
	vector<vector<vector<string>>> array;
	int n;

	cout << "������� ���������� �������: " << endl;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		Lesson lesson = addLesson();
		addLessonInTable(lesson, array, n);
	}

	printArray(array);
	printArrayByCode(array);
	deleteLesson(array);
	printArray(array);


	return 0;
}