/*
1.  Дана последовательность натуральных чисел (одно число в строке), завершающаяся числом 0. 
	Определите, какое количество элементов этой последовательности, равны ее наибольшему элементу.

2.	Дан линейный однонаправленный список. Вывести значения узлов списка по правилу: 
	сначала все отрицательные, затем все остальные.
*/

#include <iostream>
using namespace std;

// однонаправленный список
struct Node 
{
	int val;
	Node* next;

	Node(int _val) : val(_val), next(nullptr) {}
};

struct list 
{
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	bool is_empty() 
	{
		return first == nullptr;
	}

	void push_back(int _val) 
	{
		Node* p = new Node(_val);
		if (is_empty()) 
		{
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void print() 
	{
		if (is_empty())
			return;

		Node* p = first;
		while (p) 
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void emplaceBack(short val) 
	{
		Node* new_last = new Node(val);
		if (is_empty()) 
		{
			first = new_last;
			return;
		}

		Node* p = first;
		while (p->next) p = p->next;
		// сейчас p = last
		p->next = new_last;
	}

	// рекурсивная функция
	void printCustom(Node* p, list* ans = nullptr) const 
	{
		if (!ans) ans = new list();

		if (p) 
		{
			if (p->val < 0)
				cout << p->val << " ";
			else
				ans->emplaceBack(p->val);
			printCustom(p->next, ans);
		}
		else
			ans->print();
	}
};


// рекурсивная функция
void rec1(int maximum, int counter)
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "Max = " << maximum << "; Counter = " << counter;
		return;
	}
	else
		if (n > maximum)
			rec1(n, 1);
		else if (n == maximum)
			rec1(maximum, ++counter);
		else
			rec1(maximum, counter);
}

int main()
{
	int  maximum = 0, counter = 0;
	rec1(maximum, counter);
	cout << "\n--------------------\n";

	list l;
	l.push_back(3);
	l.push_back(123);
	l.push_back(-8);
	l.push_back(-123);
	l.push_back(1);
	l.printCustom(l.first);
}
