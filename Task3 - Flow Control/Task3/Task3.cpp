// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


    void task1() {
        int age;
        cout << "Enter your Age" << endl;
        cin >> age;

        if (age < 18) {
            cout << "You are not eligible to vote." << endl;
        }
        else {
            cout << "You are eligible to vote." << endl;
        }
    }


    void task2() {
        int score;
        cout << "Enter your marks" << endl;
        cin >> score;

        if (score >= 90) {
            cout << "Grade A" << endl;
        }
        else if (score >= 80) {
            cout << "Grade B" << endl;
        }
        else if (score >= 70) {
            cout << "Grade C" << endl;
        }
        else if (score >= 60) {
            cout << "Grade D" << endl;
        }
        else {
            cout << "Grade F" << endl;
        }
    }


    void task3() {
        int numa, numb, oper, result;
        cout << "Input the first number" << endl;
        cin >> numa;
        cout << "Input the operator: " << endl;
        cout << "1 = Addition; 2 = Subtraction; 3 = Multiplication; 4 = Division" << endl;
        cin >> oper;
        cout << "Input the second number" << endl;
        cin >> numb;

        switch (oper) {
        case 1:
            result = numa + numb;
            cout << "Answer:" << result << endl;
            break;
        case 2:
            result = numa - numb;
            cout << "Answer:" << result << endl;
            break;
        case 3:
            result = numa * numb;
            cout << "Answer:" << result << endl;
            break;
        case 4:
            result = numa / numb;
            cout << "Answer:" << result << endl;
            break;
        default:
            cout << "Invalid operation" << endl;
        }
    }

    void task4() {
        int choice;
		cout << "***** MENU *****" << endl;
		cout << "1. Start New Game" << endl;
		cout << "2. Load Game" << endl;
		cout << "3. Quit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Game Starting" << endl;
            break;
        case 2:
            cout << "Loading Game" << endl;
            break;
        case 3:
            cout << "Game Ended" << endl;
            break;
        default:
            cout << "INVALID INPUT" << endl;
        }
    }


  //  void task5() {
  //      int temp;
  //      cout << "Enter the temperature in Celsius: " << endl;
  //      cin >> temp;
  //      if (temp >= 0) {
  //          if (temp >= 15) {
  //                  cout << "It's cold." << endl;
  //          }if (temp >= 30) {
  //                  cout << "It's warm." << endl;
  //           }if (temp > 30) {
  //                  cout << "It's hot." << endl;
  //          }
  //      }
  //      else {
  //          cout << "It's freezing." << endl;
  //      }
  //   }

    void task5() {
        int temp;
        cout << "Enter the temperature in Celsius: " << endl;
        cin >> temp;
        if (temp <= 15) {
            if (temp <= 0) {
                cout << "It's freezing." << endl;
            } else {
                cout << "It's cold." << endl;
            }
        } else {
            if (temp >= 30) {
                cout << "It's hot." << endl;
            } else {
                cout << "It's warm." << endl;
			}
		}
       
    }


int main() {
    task1();
    cout << endl;
    task2();
    cout << endl;
    task3();
    cout << endl;
    task4();
    cout << endl;
    task5();
	cout << endl;
        return 0;
}

