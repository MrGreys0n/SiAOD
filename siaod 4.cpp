#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


/*Учет занятых и свободных аудиторий в расписании занятий группы ВУЗА.
Структура записи по отдельному занятию: номер группы, код дисциплины, день недели, номер пары, номер аудитории.
Определить структуру для хранения сведений по аудиториям вуза в соответствии с вашими тестовыми данными. 
Операции
1)	Заполнение записи по отдельному занятию с клавиатуры. Номер аудитории должен быть выбран из таблицы учета аудиторий.
2)	Вставить запись так, чтобы занятия одного дня недели составляли отдельный подсписок. Запись вставлять в конец своего подсписка.
3)	Удалить записи из расписания по заданной дисциплине (по коду)/
4)	Вывести расписание по заданной дисциплины (по коду).
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

	cout << "Введите номер группы: " << endl;
	cin >> lesson.number_of_group;

	cout << "Введите код дисциплины: " << endl;
	cin >> lesson.code_of_dis;

	cout << "Введите день недели: " << endl;
	cin >> lesson.day;

	cout << "Введите номер пары: " << endl;
	cin >> lesson.pair;

	cout << "Введите номер аудитории: " << endl;
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
	cout << "Введите код дисциплины для вывода: ";
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
	cout << "Введите код дисциплины для удаления: ";
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

	cout << "Введите количество занятий: " << endl;
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
