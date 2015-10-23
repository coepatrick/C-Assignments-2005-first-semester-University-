//CSC191
//lab assignment #3 lab 3
//9/9/05
//Patrick Coe
//This program uses classes and functions to figure out the perimeter, area, and type of triangle based on the users input.


#include <iostream>
using namespace std;
#include <math.h>

class Triangle
{
private:
	float a, b, c, tb, tc;
	char type;
public:
	void readTri();
	void printTri();
	float get_perimeter();
	float get_area();
	char get_type();
};

void Triangle::readTri()
{
	cout << "Enter triangle (a, b, c): ";
	cin  >> a >> b >> c;
}

void Triangle::printTri()
{
	cout << "a = " << a << " b = " << b << " c = " << c << endl;
}

float Triangle::get_perimeter()
{
	return (a+b+c);
}

float Triangle::get_area()
{
	//Heron's formula
	tc = (get_perimeter())/2;
	return sqrt(tc*(tc - a)*(tc - b)*(tc - c));
}

char Triangle::get_type()
{

	while((c < b) || (c < a))
	{
		if(c < b)
		{
			tc = b;
			tb = c;
			c = tc;
			b = tb;
		}
		else if(c < a)
		{
			tc = a;
			tb = c;
			c = tc;
			a = tb;
		}
	}
	
	if(((a*a) + (b*b)) == (c*c))
		return 'r';
	else if(((a*a) + (b*b)) <= (c*c))
		return 'o';
	else
		return 'a';

}


void main()
{
	Triangle T;

	T.readTri();
	T.printTri();

	cout << "The perimeter is " << T.get_perimeter() << endl;
	cout << "The area is " << T.get_area() << endl;

	char t = T.get_type();

	if(t == 'a')
		cout << "this triangle is acute"  << endl;
	else if(t == 'r')
		cout << "this triangle is right"  << endl;
	else
		cout << "This triangle is obtuse" << endl;
}