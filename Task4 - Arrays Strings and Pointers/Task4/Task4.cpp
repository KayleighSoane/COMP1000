// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{

	void task1();
		int Farray[10];
		for (int i = 1; i <= 10; i++) {
			Farray[i-1] = i;
			cout << Farray[i-1] << " ";
			
		}
		cout << endl;
		cout << endl;


	void task2();
		string a = "My name is ";
		string b = "Kayleigh.";
		string c = a + b;
		cout << c << endl;
		cout << "The length of the two strings is " << c.length() << endl;
		if (a.length() == b.length()) {
			cout << "The strings are equal in length" << endl;
		}
		else {
			cout << "The strings are not equal in length" << endl;
		}
		cout << endl;


	void task3();
		int value = 5;
		int* xPtr = &value;									// int* xPtr declares a pointer to an integer and initializes it with the address of value
		cout << "The value is: " << *xPtr << endl;			// Writing xPtr prints the address of value, but writing *xPtr prints the value stored at that address
		int newvalue = *xPtr + 10;							// Printing *xPtr is the same as printing value
		cout << "The new value is: " << newvalue << endl;
		cout << endl;


	void task4();
		int arrayP[5] = { 4,67,43,2,7 };
		for (int i = 0; i < 5; i++) {
			int* yPtr = &arrayP[i];
			cout << "Element " << i << " is " << *yPtr << endl;
		}
		cout << endl;
		for (int i = 0; i < 5; i++) {
			int* yPtr = &arrayP[i];
			cout << "Element " << i << " plus 2 is " << *yPtr + 2 << endl;
		}
		cout << endl;


	void task5();
		char* Poo = new char[20];						// 'new' idynamically allocates
		cout << "Input 19 characters" << endl;			// Last character of array is null terminator
		cin.getline(Poo, 20);							// Reads input (up to 19 characters the null terminator) and stores it in Poo					
		cout << Poo << endl;
		cout << "Length: " << strlen(Poo) << endl;
		delete[] Poo;									// Frees the memory allocated for the character array Poo. 'delete' only works for memory allocated with 'new'
		


		
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
