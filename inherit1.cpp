#include <iostream>
#include <string>
using namespace std;

class TwoDShape
{
protected:
	double width, height;
public:
	TwoDShape(double w, double h)
	{
		width = w;
		height = h;
	}

	void showDim()
	{
		cout << "width = " << width << " height = " << height << endl;
	}
};

class Triangle: public TwoDShape
{
protected:
	string style;
public:
	Triangle(double w, double h, string s): TwoDShape(w, h)
	{
		style = s;
	}

	Triangle(double x): TwoDShape(x, x) 
	{
		style = "isosceles";
	}

	double area()
	{
		return (width*height)/2.0;
	}

	void showStyle()
	{
		cout << "The triangle is " << style << endl;
	}	
};

class ColorTriangle: public Triangle
{
private:
	string color;
public:
	ColorTriangle(double w, double h, string s, string c): Triangle(w, h, s)
	{
		color = c;
	}

	ColorTriangle(double x, string c): Triangle(x)
	{
		color = c;
	}

	void showColor()
	{
		cout << "The color = " << color << endl;
	}
};

void main()
{
	ColorTriangle T1(10.5, 8.5, "right", "red"), T2(7, "blue");

	T1.showColor();
	T1.showStyle();
	T1.showDim();

	T2.showColor();
	T2.showStyle();
	T2.showDim();
}