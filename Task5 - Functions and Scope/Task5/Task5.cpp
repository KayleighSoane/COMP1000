// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int addTwoNumbers(int a, int b)
{
    return a + b;
}

void swapNumbers(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

float calculateDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	cout << "Distance = " << calculateDistance(x1, y1, x2, y2) << endl;
}

int counter = 0;
void incrementCounter()
{
	counter++;
}
void displayCounter()
{
	cout << "Counter: " << counter << endl;
}
	
static int FunctionCount = 0;
void trackFunctionCalls()
{
	FunctionCount++;
	cout << "Function called " << FunctionCount << " times" << endl;
}

int main()
{

	void task1();
		int a, b;
		cout << "enter an integer to add:";
		cin >> a;
		cout << "enter a second integer to add:";
		cin >> b;
		cout << "Sum = " << addTwoNumbers(a, b) << endl;
		cout << endl;
		
	void task2();
		cout << "enter an integer to swap:";
		cin >> a;
		cout << "enter a second integer to swap:";
		cin >> b;
		cout << "a = " << a << ", b = " << b << endl;
		swapNumbers(a, b);
		cout << "Swapped: a = " << a << ", b = " << b << endl;
		cout << endl;

	void task3();
		float x1, y1, x2, y2;
		cout << "enter x value for coordinate 1:";
		cin >> x1;
		cout << "enter y value for coordinate 1:";
		cin >> y1;
		cout << "(" << x1 << ", " << y1 << ")" << endl;
		cout << "enter x value for coordinate 2:";
		cin >> x2;
		cout << "enter y value for coordinate 2:";
		cin >> y2;
		cout << "(" << x2 << ", " << y2 << ")" << endl;
		cout << "Distance = " << calculateDistance(x1, y1, x2, y2) << endl;
		cout << endl;

	void task4();
		displayCounter();
		incrementCounter();
		incrementCounter();
		displayCounter();
		incrementCounter();
		incrementCounter();
		incrementCounter();
		displayCounter();
		incrementCounter();
		displayCounter();
		cout << endl;

	void task5();
	for (int n = 0; n < 5; n++) {
		trackFunctionCalls();
		}




	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
