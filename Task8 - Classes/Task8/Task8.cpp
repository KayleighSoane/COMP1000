// Task8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string title, author; float price;

public: 
	Book (string t, string a, float p) {title = t; author = a; price = p;}

	void displayInfo() {
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Price: " << price << endl;
	}		
};

class Student {
private:
	string name; int age; char grade;

public:
	void setName(string n) { name = n; }
	void setAge(int a) { age = a; }
	void setGrade(char g) { grade = g; }

	string getName() { return name; } //get() is a function on its own that gets the value of a private variable
	int getAge() { return age; }
	char getGrade() { return grade; }
};

class Car {
private:
	string make; int year;

public:
	Car() : make("Unknown"), year(0) {		//default constructor 
		cout << "Default constructor" << endl; }
	Car(string m, int y) : make(m), year(y){
		cout << "Parameterized constructor" << endl;} 
	~Car() {cout << "Destructor called for " << make << ", " << year << endl; } //is called at the end of the programme

	void display() { cout << "Car: " << make << ", " << year << endl; }
};

class Counter {
private:
	static int count;

public:
	Counter() { count++; } //increment count each time an object is created
	static int getCount() { return count; }
	~Counter() { count--; } 
};
int Counter::count = 0; //initializes the variable inside the class


int main()
{
	Book ProjectHailMary("Project Hail Mary", "Andy Weir", 15.99);
	ProjectHailMary.displayInfo();
	cout << endl;

	Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99); //can use for any book
	myBook.displayInfo();
	cout << endl;

	Student alice;
	alice.setName("Alice");
	alice.setAge(20);
	alice.setGrade('A');
	cout << "Student Name: " << alice.getName() << endl;
	cout << "Student Age: " << alice.getAge() << endl;
	cout << "Student Grade: " << alice.getGrade() << endl;
	cout << endl;

	Car car1; car1.display(); //default constructor
	Car toyota("Suzuki", 2020); toyota.display(); //parameterized constructor
	cout << endl;

	Counter c1;
	cout << "Count: " << Counter::getCount() << endl; 
	{
		Counter c2, c3;
		cout << "Count: " << c1.getCount() << endl;
	}
	cout << "Count: " << Counter::getCount() << endl;
	cout << endl;
	//using c1.getCount() produces the same results as Counter::getCount() would because it is static. But is misleading 
	//since it produces the result of the whole class, not just c1, so Counter::getCount() is preferred.
	//if it wasn't static, c1.getCount() would only return the count for c1.
}
