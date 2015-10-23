//CSC191
//lab assignment #11
//11/11/2005
//Patrick Coe
//This program adds and removes values to a list.

#include <iostream>
#include <stdlib.h> //for exit()
using namespace std;

template <class T>
class List
{
private:
	T *p;
	int size;
public:
	List(){size = 0;};
	~List(){delete [] p; p = NULL;};

	void addFirst(T item);
	void addLast(T item);

	void removeFirst();
	void removeLast();
	void printList();

	T& operator [] (int n);
	int length() {return size;};
};

template <class T>
void List<T>::addFirst(T item)
{
	T* newp = new T[size+1];
	if(newp == NULL)
	{
		cerr << "Memory failure!!!";
		exit(1);
	}

	for (int i = 0; i < size; i++)
		newp[i+1] = p[i];
	newp[0] = item;
	size++;
	delete[] p;
	p = newp;
}

template <class T>
void List<T>::addLast(T item)
{
	T* newp = new T[size+1];
	if(newp == NULL)
	{
		cerr << "Memory failure!!!";
		exit(1);
	}

	for (int i = 0; i < size; i++)
		newp[i] = p[i];
	newp[size] = item;
	size++;
	delete[] p;
	p = newp;
}

template <class T>
void List<T>::printList()
{
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
	cout << endl;
}

template <class T>
T& List<T>::operator [] (int n)
{
	if (n < 0 || n > size - 1)
	{
		cerr << "Index out of bound!!!";
		exit(1);
	}

	return p[n];
}

template <class T>
void List<T>::removeFirst()
{
	T* newp = new T[size-1];
	if(newp == NULL)
	{
		cerr << "Memory failure!!!";
		exit(1);
	}

	for (int i = 0; i < size-1; i++)
		newp[i] = p[i+1];
	size--;
	delete[] p;
	p = newp;
}

template <class T>
void List<T>::removeLast()
{
	T* newp = new T[size-1];
	if(newp == NULL)
	{
		cerr << "Memory failure!!!";
		exit(1);
	}

	for (int i = 0; i < size-1; i++)
		newp[i] = p[i];
	size--;
	delete[] p;
	p = newp;
}

void main()
{
	List<int> L;
	int num;
	char option;
	do
	{
		cout << "1. add first" << endl;
		cout << "2. add last" << endl;
		cout << "3. remove first" << endl;
		cout << "4. remove last" << endl;
		cout << "5. print List" << endl;
		cout << "6. Exit" << endl;

		cout << "Select:";
		cin >> option;

		switch (option)
		{
			case '1':
				cout << "enter a value to add: ";
				cin >> num;
				L.addFirst(num);
				break;
			case '2':
				cout << "enter a value to add: ";
				cin >> num;
				L.addLast(num);
				break;
			case '3':
				L.removeFirst();
				break;
			case '4':
				L.removeLast();
				break;
			case '5':
				L.printList();
				break;
			case '6':
				break;
		}
	} while (option != '6');
}