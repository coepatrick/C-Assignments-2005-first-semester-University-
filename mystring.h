//CSC191
//Lab 9
//10/21/2005
//Patrick Coe
//This program overloads <<, >>, +, and * to work with unions of sets.


#include <iostream>
using namespace std;

class Set
{
private:
	int A[100], n;
	bool dup();
public:
	Set()
	{
		n=0;
	}
	friend istream& operator >> (istream& cin, Set& s);
	friend ostream& operator << (ostream& cout, const Set s);
	friend Set operator + (const Set& s1, const Set& s2);
	friend Set operator * (const Set& s1, const Set& s2);


};

bool Set::dup()
{
	for (int i = 0; i <= n-1; i++)
		if (A[n] == A[i])
			return true;
	return false;
}

istream& operator >> (istream& cin, Set& s)
{
	cout << "Enter an integer:";
	cin >> s.A[s.n];

	while ((s.A[s.n] != -999) && (s.n < 100))
	{
		if (!s.dup())
			s.n++;
		cout << "Enter an integer:";
		cin >> s.A[s.n];
	}

	return cin;
}

Set operator + (const Set& s1, const Set& s2)
{
	bool check;
	Set s3 = s1;

	for(int cnt = 0; cnt < s2.n; cnt ++)
	{
		s3.A[s3.n] = s2.A[cnt];

		check = !s3.dup();

		if(check)
			s3.n++;
	}
	

	return s3;


}

Set operator * (const Set& s1, const Set& s2)
{
	Set s3;

	for(int cnt = 0; cnt < s2.n; cnt++)
		for(int cnt2 = 0; cnt2 < s2.n; cnt2++)
			if(s1.A[cnt] == s2.A[cnt2])
			{
				s3.A[s3.n] = s1.A[cnt];
				s3.n++;
			}
	
	return s3;
}


ostream&  operator << (ostream& cout, const Set s)
{
	cout << "{";
	for (int i = 0; i < s.n-1; i++)
		cout << s.A[i] << ", ";
	cout << s.A[s.n-1] << " }" << endl;

	return cout;
}

void main()
{
	Set S1, S2, S3;
	cin >> S1 >> S2;
	cout << S1 << S2 << endl;
	cout << S1 + S2 << endl; //set union
	cout << S1 * S2 << endl; //set intersection
}