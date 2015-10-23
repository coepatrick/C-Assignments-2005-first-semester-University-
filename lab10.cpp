//CSC191
//Lab10
//Patrick Coe
//10/28/2005
//This program helps the programmer understand pointers a littl better.


#include <iostream>
using namespace std;

void main()
{
	long i = 1, *p = &i, &j = i, *q = p, *&r = p;
	long A[5] = {1,2,3,4,5};
	long *pA=A;

	cout << "         " << i << ' ' << &i << endl;
	cout << "         " << j << ' ' << &j << endl;
	cout << p << ' ' << *p << ' ' << &p << endl;
	cout << endl << endl;
	cout << q << ' ' << *q << ' ' << &q << endl;
	cout << r << ' ' << *r << ' ' << &r << endl;
	cout << A << ' ' << *A << ' ' << &A << ' ' << *A << ' ' << *(A+1) << endl;
	cout << pA << ' ' << *pA << ' ' << *(pA+1) << ' ' << pA[1] << endl;
	cout << ++pA << ' ' << pA[1] << endl;

}

/*
         1 0012FEDC       i is 1, so a one is output. &i is the location of i, it is output.
         1 0012FEDC       j is the same as i, so we have the same outputs.
0012FEDC 1 0012FEE0		  p points to the location of i, so it outputs the location of i. 
						  *p points to i, so it outputs what is stored in i
						  &p is the location of p, so it ouputs it's location.


0012FEDC 1 0012FED4		q points to p which points to the location of f.
						*q points to the location of *p, which points to i
						&q is the location of q
0012FEDC 1 0012FEE0		&r is the same as p, so it will output p, *p, and &p.
0012FEC0 1 0012FEC0 1 2 A is the location of A
						*A points to the first value in A
						&A points to the first location of A
						*A points to the first value in A
						*(A+1) points to the second value in A
0012FEC0 1 2 2			pA points to the location of A
						*pA points to the first value in A
						*pA points to the second value of A
						pA[1] points to the second value of the array in A
0012FEC4 3				++pA points to the location of 
						pA[1] points to the second value of the array in A

*/