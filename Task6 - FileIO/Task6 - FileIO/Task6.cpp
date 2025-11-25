#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

// ofstream to write to files

int createFile() {
	ofstream outputFile;
	outputFile.open("file.txt");
	if (!outputFile.is_open()) {
		cerr << "Error opening file" << endl;
		return -1;
	}
	float score = 62.50;
	string name = "Kayleigh Soane";
	outputFile << "Name:" << setw(21) << name << endl;
	outputFile << "Age:" << setw(10) << 20 << endl;
	outputFile << "Score:" << setw(10) << setprecision(4) << score << endl;
}


int main() {
	string name = "Kayleigh Soane";
	int age = 20;
	float score = 62.50;

	createFile();

	ifstream inputFile;
	inputFile.open("file.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening file" << endl;
		return -1;
	}
	string word;
	string line;
	getline(inputFile, line);
	cout << line << endl;
	for (int i = 0; i < 4; i++) {
		inputFile >> word;
		cout << word << "\t";
	}

	ofstream output_dFile;
	output_dFile.open("destination.txt");
	if (!output_dFile.is_open()) {
		cerr << "Error opening file" << endl;
		return -1;
	}

	string copy;
	string full;
	if (inputFile.is_open() && output_dFile.is_open()) {
		inputFile.clear();
		inputFile.seekg(0, ios::beg);
		while (getline(inputFile, copy)) {
			full += copy + "\n";
		}
		output_dFile << full;
		if (output_dFile.fail()) {
			cerr << "Error writing to file" << endl;
			return -1;
		}
	}
	inputFile.close();
	return 0;
}