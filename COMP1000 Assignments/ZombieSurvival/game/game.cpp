//Only allowed to use standard library & windows.h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> // create colours and sleep
#include <thread>
#include "Header.h" // might have to move all code into cpp file to post as assignment
using namespace std;

const int X = 40, Y = 20;
char map[X][Y];
int playerX = 1, playerY = 1;
int h = 100;


void score() { //PRIORITY
    int score = 0;
	// if (), score += points
    //kill zombie - 10 points
	//find health pack - 5 points
	//collect ammo - 2 points
	//collect food - 3 points
}

void timer() { 
//timer = seconds or amount of moves 

//   for (times; times >= 0; times--) {
//       int minutes = times / 60;
//		int seconds = times % 60; //%60 (remainer after dividing by 60) of 300 is 0, of 299 is 59, of 298 is 58 etc
//		//system("cls"); // the refresh of timer and of map break the game - refresh independently? dont clear screen, just replace timer line?
//        cout << "\033[1;1H"; 
//        cout << "Time Left: " << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << flush << endl;/
		//replaces the previous line in console, effectively refreshing the timer
        //problem: prevents me from moving on the map
//		Sleep(1000);
}
    
	//WORKS BUT COUNTS DOWN BEFORE GAME STARTS
	//NEED TO USE MULTITHREADING TO RUN TIMER AND GAME SIMULTANEOUSLY BUT INDEPENDENTLY
	// teach myself multithreading in c++
    
    //Plan:
	//counts down from 300 but displayed as mins:secs
	//5:00 - next number is 4:59
    //when reaches 0, decrease miunute, display next second as 59
    //if timer runs out, game over - get swarmed and eaten
    // display timer at top of screen

void blockades() {
    //Plan:
    // bloackade = #
    //3 random blockades on the map
    // only reveal when next to them
    //P and Z cannot pass through blockades
    //makes map more of a maze
}


    //ZOMBIES
    //plan:
    // zombie = Z
	// spawn zombies at random locations each time
	// zombies move towards player every two turns - need a counter
	// if zombie reaches player, decrease health by 10
    //Z cannot replace P or E
    //need to be killable - true and false - bool

//order of zombie instructions:
//spawn zombies at random locations - not p or e
//every two player moves, move one space in random direction


//generate random coordinates for each zombie


void health() {}

//health is displayed but not decreasing when player hits zombie - fix zombies first
//not working because when P moves onto Z, Z is removed from map

void food() {
    //plan:
    //health pack = F
	// spawn 2 health packs at random locations
    //increase health by 20
}

void ammo() {
    int ammo = 6;
    //plan:
	//spacebar to shoot, ammo -1, counts as a turn
	// need to be next to zombie to shoot it
	//start with x amount of ammo
	// can pick up ammo on the map
	// add ammo to counter, when counter is zero print "out of ammo"
}

void generateWalls() {
    for (int i = 0; i < X; i++) {
        map[i][0] = '#';
        map[i][Y - 1] = '#';
	}
    for (int i = 0; i < Y; i++) {
        map[0][i] = '#';
        map[X - 1][i] = '#';
	}
}

void generateMap() { 
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            map[j][i] = '.';
        }
    }
    map[1][1] = 'P'; // Player start
    map[X - 2][Y - 2] = 'E'; // Exit
	generateWalls();
}

void printMap() {
    system("cls"); // Print map below the timer
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << map[j][i] << ' ';
        }
        cout << endl;
    }
}

void movePlayer(char move) {
    
    // Remove player from current position
    map[playerX][playerY] = '.';

    // Update position based on input
    if (move == 'W' || move == 'w') playerY = max(0, playerY - 1);
    if (move == 'S' || move == 's') playerY = min(Y - 1, playerY + 1);
    if (move == 'A' || move == 'a') playerX = max(0, playerX - 1);
    if (move == 'D' || move == 'd') playerX = min(X - 1, playerX + 1);
	if (move == '3') {                              // Exit game during play
        cout << endl << "------------" << endl;
        cout << "Exiting game" << endl;
        cout << "------------" << endl;
		exit(0);
	}

    // Place player in new position
    map[playerX][playerY] = 'P';
}


int main(){
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation - randomize map elements
	
    generateMap();
    Zombie z(X, Y); //create zombies - needs to be put after seed to generate new each time, but before map print to place zombies on map

	system("cls");
   
    cout << "==============================" << endl;
    cout << "| ZOMBIE APOCALYPSE SURVIVAL | " << endl;
    cout << "==============================" << endl << endl;
    cout << "----------------" << endl;
	cout << "1 - Start Game" << endl;
	cout << "2 - Instructions" << endl;
	cout << "3 - Exit" << endl;
	cout << "----------------" << endl;
    int start;
    cin >> start;

    if (start == 1) {
        system("cls");
        int movecount = 0; 

        auto zomcoords = z.returncoords(); //z.returncoords() transfer values to main
        for (auto initialzomcoords : zomcoords) {
            int zx = 0, zy = 0;
            zx = initialzomcoords.first;
			zy = initialzomcoords.second;
			map[zx][zy] = 'Z'; //place zombies on map
        }
        
        while (true) {
            printMap();
            z.checkcoords();

            char m;
            m = _getch(); // Get single character input without enter
            movePlayer(m);
            movecount++;

		    auto oldzomcoords = z.returncoords();
            if (movecount % 2 == 0) {
                z.zombmove(playerX, playerY); //move zombies
            }
			auto newzomcoords = z.returncoords();
			// make oldzombcoords . and newzombcoords Z on map
            for (auto o : oldzomcoords) {
                if (map[o.first][o.second] == 'Z') {
                    map[o.first][o.second] = '.'; //remove old zombie position
                }
		    }
            for (auto n : newzomcoords) {
               
                if (map[n.first][n.second] == map[playerX][playerY]) {
                    cout << "----------------------------" << endl;
                    cout << "A zombie got you. Game over." << endl;
                    cout << "----------------------------" << endl;
                    exit(0); // keep as debug for now until health system created
                } 
                else if (map[n.first][n.second] == 'E') {} //do nothing
                else { 
                    map[n.first][n.second] = 'Z'; 
                }
            }

            if (playerX == X - 2 && playerY == Y - 2) {
                cout << "-----------------------------------" << endl;
                cout << "You reached the exit. You survived!" << endl;
                cout << "-----------------------------------" << endl;
                exit(0);
            }
       }
    }
    else if (start == 2) {
		system("cls");
		cout << "-------------------------------------------------" << endl;
        cout << "Instructions:" << endl;
        cout << "Move using W (up), A (left), S (down), D (right)." << endl;
        cout << "Reach the 'E' to escape the zombies." << endl;
        cout << "Avoid zombies and manage your resources!" << endl;
        cout << "Exit game at any time by pressing 3." << endl;
        cout << endl;
        cout << "Press any key to return to main menu." << endl << endl;
		cout << "-------------------------------------------------" << endl;
		_getch();
		main();
    }
    else if (start == 3) {
		cout << endl << "------------" << endl;
        cout << "Exiting game" << endl;
		cout << "------------" << endl;
	}

    return 0;
}