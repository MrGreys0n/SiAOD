// Простой вставки ----- Шелла со смещением Р. Седжвика. ----- Быстрая сортировка (опорный элемент в середине)
//

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;

void random_arr(int* arr, int n) 
{
	for (int i = 0; i < n; i++)
		arr[i] = 1 + rand() % 100;
}

void arr_out(int* arr, int n) 
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubble_sort(int* arr, int n)
{
	// Для всех элементов
	for (int i = 0; i < n - 1; i++)
		for (int j = (n - 1); j > i; j--) // для всех элементов после i-ого
			if (arr[j - 1] > arr[j]) // если текущий элемент меньше предыдущего
				swap(arr[j - 1], arr[j]);
}

int sedgwicks_step(int inc[], int size) 
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do 
	{
		if (++s % 2)
			inc[s] = 8 * p1 - 6 * p2 + 1;
		else 
		{
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} 
	while (3 * inc[s] < size);

	return s > 0 ? s-1 : 0;
}

void shell_sort(int* a, int size) 
{
	int inc, j, seq[40], size_seq;
	size_seq = sedgwicks_step(seq, size);
	while (size_seq >= 0) 
	{
		inc = seq[size_seq--];
		for (int i = inc; i < size; i++) 
		{
			int temp = a[i];
			for (j = i - inc; (j >= 0) && (a[j] > temp); j -= inc)
				a[j + inc] = a[j];
			a[j + inc] = temp;
		}
	}
}

void heapify(int* arr, int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heap_sort(int* arr, int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	int* arr = new int[n];

	random_arr(arr, n);
	arr_out(arr, n);

	unsigned int start_time = clock();
	//bubble_sort(arr, n);
	//shell_sort(arr, n);
	heap_sort(arr, n);
	arr_out(arr, n);

	cout << clock() - start_time;
}
