// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


// csv file created and added to task 2 file

int main()
{
    ifstream file("json.csv");
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			string name, grade;
			getline(ss, name, ','); // prints '{"name": "Alice"'  - need to extract just Alice
			name = name.substr(name.find(":") + 3, name.length() - name.find(":") - 4);
			//name.length() is length of characters = 16
			//length of name.find(":") = 7, plus 3 is 10, brings us to the position of the first A in Alice
			//equation says: from the position of A, subtract the length of name.find(":") and 4 more characters
			//16 - length of name.find(":") - 4 = 5
			cout << "Name: " << name << "\t";
			getline(ss, grade, '}'); // prints ' grades: "85,90,75"' - extract 85,90,75
			grade = grade.substr(grade.find(":") + 3, grade.length() - grade.find(":") - 4);
			//desired length = 8
			//length = 19	grade.find = 7
			//19 - 7 = 12, - 4 = 8
			cout << "Grades: " << grade << endl;

		}
		file.close();
	}
	else {
		cerr << "Error opening file" << endl;
		return -1;
	}
}
