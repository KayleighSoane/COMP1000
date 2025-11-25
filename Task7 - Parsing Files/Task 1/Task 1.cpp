// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


//csv file created and added to task 1 file

int main()
{
	string line;
	ifstream file("data.csv");

	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			string name, age, city;
			getline(ss, name, ',');
			getline(ss, age, ',');
			getline(ss, city, ',');
			cout << "Name: " << name << "\t" << "Age: " << age << "\t" << "City: " << city << endl;
		}
		file.close();
	}
	else {
		cerr << "Error opening file" << endl;
		return -1;
	}

}

