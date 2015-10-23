//CSC191
//Assignment#5
//Patrick Coe
//10/13/2005
//This program uses recursive functions to add, subtract, divide or multiply a string of numbers.


//************************************
//* NOTE: This program currently     *
//* can't follow order of operations.*
//************************************



#include <iostream>
#include <string>
using namespace std;



class Arith
{
private:
	string E; //1+2+4-3+7
	//int('7') - int('0')
	int locate(int n);   //Finds the location of the last + or - sign, if none exists returns a -1
	float evalMD(int n); //Solves an equation that only involves multiplication and division.
public:
	int getL() {return E.length();} //Retrieves the length of the array
	void read();                    //Reads the equation
	void print(int n);				//Prints the equation.
	void printR(int n);				//Prints the equation in reverse order
	float eval(int n);				//Evaluates the equation.
	void printeval();				//Prints the evaluation of the equation.
};

void Arith::printeval()
{
	cout << eval(getL()) << endl;
}

void Arith::read()
{
	cout << "Enter a expression:";
	cin >> E;
}

void Arith::print(int n)
{
	if (n > 0)
	{
		print(n-1);
		cout << E[n-1];
	}
}

void Arith::printR(int n)
{
	if (n > 0)
	{
		cout << E[n-1];
		printR(n-1);
	}
}

float Arith::evalMD(int n)
{
	if (n == 1)
	return (E[0] - int('0'));

	float t = evalMD(n-2);

	//-------------------------------------------------------------------

	/*This is temporary code that has nothing to do with multiplication
		or division, but has been placed here so the program can handle
		some addtion and subtraction untill I figure out how to implement
		it properly.
		*/

/*	if (E[n-2] == '+')
       return (t + (int(E[n-1]) - int('0')));
	else if (E[n-2] == '-') //E[n-2] was '-'.
       return (t - (int(E[n-1]) - int('0')));
*/
	//-------------------------------------------------------------------

	if (E[n-2] == '*')
       return (t * (int(E[n-1]) - int('0')));
	else //E[n-2] was '/'.
       return (t / (int(E[n-1]) - int('0')));
}

int Arith::locate(int n)
{
	int loc = E.find('+');
	int loc2= E.find('-');
	
	if (loc > loc2)
		return loc;
	else
		return loc2;
}

float Arith::eval(int n)
{
	if (n == 1)
	return (E[0] - int('0'));


	int loc = locate(n);
	cout << loc << " ";

	if(loc == -1)
		return evalMD(n);

	float t = eval(n-2);


	if (E[n-2] == '+')
       return (t + (int(E[n-1]) - int('0')));
	else //E[n-2] was '-'.
       return (t - (int(E[n-1]) - int('0')));

}

void main()
{
	Arith A;
	char res;

	do
	{

		cout << endl;
		cout << "Please make a selection" << endl;
		cout << "1. Read an expression." << endl;
		cout << "2. Print the expression" << endl;
		cout << "3. Evaluate the parse tree." << endl;
		cout << "4. Exit" << endl; 


		cout << "select:";

		cin >> res;

		cout << endl;

		switch (res)
		{
		case '1':
			A.read();
			break;
		case '2':
			A.print(A.getL());
			break;
		case '3':
			A.printeval();
			break;
		case '4':
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != '4');
}