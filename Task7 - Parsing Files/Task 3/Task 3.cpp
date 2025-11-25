// Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ifstream file("application.log");
	string line, error, warning;
	stringstream ss;
	int ecount = 0, wcount = 0;

	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
			if (line.find("ERROR") != string::npos) {
				ecount++;
				line = line.substr(line.find("5") + 2, line.length() - line.find("5"));
				error = line;
			}
			if (line.find("WARNING") != string::npos) {
				wcount++;
				line = line.substr(line.find("5") + 2, line.length() - line.find("5"));
				warning = line;
			}

		}
		file.close();
		cout << endl;
		cout << "Total ERRORS: " << ecount << endl;
		cout << "Total WARNINGS: " << wcount << endl;
		cout << endl << "ERROR/WARNING Details: " << endl;
		cout << error << endl;
		cout << warning << endl;
	}
	else {
		cerr << "Error opening file" << endl;
		return -1;
	}
}

