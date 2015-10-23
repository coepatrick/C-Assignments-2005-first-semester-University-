//CSC191
//Lab7
//10/07/05
//Patrick Coe
//This program diplays, reverses, sorts, searches and finds the maximum value of an array input by the user.


#include <iostream>
using namespace std;

class Arr
{
private:
	int A[100], n;
	int maxA(int);
	void bubble(int);
	int binsearch(int, int, int);
	void reverseA(int, int);

public:
	void readA();
	void printA();
	int maxA();
	void reverseA();
	void sort();
	void search();
	void rotate();
};

int Arr::maxA(int n)
{
	if (n == 1)
		return A[0];
	int t = maxA(n-1);
	if (t > A[n-1])
		return t;
	return A[n-1];
}

void Arr::bubble(int n)
{
	if (n <= 1)
		return;
	for(int i = 0; i <= n-2;i++)
		if (A[i] > A[i+1])
		{
			int t = A[i];
			A[i] = A[i+1];
			A[i+1] = t;
		}
	bubble(n-1);
}

int Arr::binsearch(int key, int l, int r)
{
	if (l > r)
		return -1;
	int m = (l+r)/2;
	if (key == A[m])
		return m;
	if (key < A[m])
		return binsearch(key, l, m-1);
	return binsearch(key, m+1, r);
}

void Arr::readA()
{
	int val;
	cout << "Enter an integer(-999 to stop):";
	cin >> val;
	n = 0;
	while ((val != -999) && (n < 100))
	{
		A[n++] = val;   //A[++n] = val;
		cout << "Enter an integer(-999 to stop):";
		cin >> val;
	}
}

void Arr::printA()
{
	for(int i = 0; i < n; i++)
		cout << A[i] << ' ';
	cout << endl;
}

int Arr::maxA()
{
	return maxA(n);
}

void Arr::reverseA()
{
	reverseA(0, n-1);

}

void Arr::reverseA(int l, int r)
{
	if(l > r)
		return;

	int temp = A[r];
	A[r] = A[l];
	A[l] = temp;

	reverseA(l+1,r-1);
}





void Arr::sort()
{
	bubble(n);
}

void Arr::search()
{
	int key;
	cout << "Enter your key";
	cin >> key;
	int t = binsearch(key, 0, n-1);
	if (t == -1)
		cout << "Key not found." << endl;
	else
		cout << key << " found at " << t << endl;
}

void main()
{
Arr A;
int res;

	do
	{
		cout << "1. read array"  << endl;
		cout << "2. print array" << endl;
		cout << "3. find max"    << endl;
		cout << "4. reverse array"<<endl;
		cout << "5. sort array"  << endl;
		cout << "6. search array"<< endl;
		cout << "7. exit" << endl;

		cout << "select:";
		cin >> res;

		
		switch (res)
		{
		case 1:
			A.readA();
			break;
		case 2:
			A.printA();
			break;
		case 3:
			cout << "The max is " << A.maxA() << "." << endl;
			break;
		case 4:
			A.reverseA();
			break;
		case 5:
			A.sort();
			break;
		case 6:
			A.search();
			break;
		case 7:
			cout << "Thanks for using my program." << endl;
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != 7);
}

