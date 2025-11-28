#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <thread>
using namespace std;

const int X = 40;
const int Y = 20; //made map bigger
char map[X][Y];

// Player position
int playerX = 0;
int playerY = 0;

void score() { //PRIORITY
    int score = 0;
	// if (), score += points
    //kill zombie - 10 points
	//find health pack - 5 points
	//collect ammo - 2 points
	//collect food - 3 points
}

void timer() { 
    
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
    // bloackade = /
    //3 random blockades on the map
    // only reveal when next to them
    //cannot pass through blockades
    //makes map more of a maze
}

void roads() {
    //plan:
	//can only move on roads?
    //remove dots on map
}

void safety() {
    //plan:
    // safehouse = O
	//one safe house on the map
	// pauses zombie movement
    //exiting safehouse doesnt count as a turn
	//replenishes stats (health, ammo, hunger)
}

    //ZOMBIES
    //plan:
    // zombie = Z
	// spawn zombies at random locations each time
	// zombies move towards player every two turns - need a counter
	// if zombie reaches player, decrease health by 10
    //Z cannot replace P or E
    //need to be killable - true and false - bool

//tricky, did some research and was suggested to use vectors to store multiple coordinates
//with vectors, can store pairs of values and then access each pair as a single element in the vector
//can access single part of pair with .first or .second

vector<pair<short int, short int>> zomb; // Global
// Store each zombie's coordinates, can be called individually
void zomSpawn(int i, int n) {
    for (i = 0; i < n; i++) { 
        short int zomx = rand() % X;
        short int zomy = rand() % Y;
        if ((zomx == 0 && zomy == 0) || (zomx == X - 1 && zomy == Y - 1)) {
            i--;   
            continue;       //will regenerate random coordinates for this zombie if it spawns on P or E
        }
		map[zomx][zomy] = 'Z';         // Place zombie on map
		zomb.emplace_back(zomx, zomy); // Stores zombie coordinates - zomb[0].first and zomb[0].second is zomx and zomy of first zombie
    }
}
// this works - DO NOT CHANGE
// cout << zomb[0].first << ", " << zomb[0].second << endl; tested to see if coordinates are being stored correctly - worked


//need to figure out movement system
//start with just moving one zombie for testing
extern int moveCount;
class zombie {
public:
    short int x;
    short int y;

	zombie(short int startX, short int startY) { // = constructor - initializes new zombie object with starting coordinates
        x = startX;
        y = startY;
    }

    void moveTowards(int playerX, int playerY) {
        if (moveCount % 2 == 0) { // Move only on every second call
            map[x][y] = '.'; // Clear previous zombie position on map
            if (x < playerX) x++;//move zombie closer to player
            else if (x > playerX) x--;
            if (y < playerY) y++;
            else if (y > playerY) y--;
            map[x][y] = 'Z'; // Update zombie position on map
        }
	}
};
//order of zombie instructions:
//spawn zombies at random locations - not p or e
//every two player moves, move one space in random direction


//generate random coordinates for each zombie


void energy() {
    //plan:
	//supply = f
    //start with hunger full
    // if hunger is 0, decreases health over time?
}

void health() { //PRIORITY
	static int health = 100;
    cout << "Health: " << health << endl;
    if (map[playerX][playerY] == 'Z') {
        health -= 100;
    }
    if (health <= 0) {
        cout << "--------------------" << endl;
        cout << "You died. Game Over." << endl;
        cout << "--------------------" << endl;
        exit(0);
	}

//health is displayed but not decreasing when player hits zombie - fix zombies first
//not working because when P moves onto Z, Z is removed from map
} 

void hpack() {
    //plan:
    //health pack = +
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

void generateMap() { 
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            map[j][i] = '.';
        }
    }
    map[0][0] = 'P'; // Player start
    map[X - 1][Y - 1] = 'E'; // Exit
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

    //plan:
    //change so you dont have to click enter after an input
    //instruction menu
	//game exit option
    //make map bigger?

    // Place player in new position
    map[playerX][playerY] = 'P';
}

int moveCount = 0; 
int main(){
    static int Z = 3
        ; //number of zombies to spawn
	static int i;     //loop counter
    int start; 
	system("cls");
    
    cout << "========================" << endl;
    cout << "| ZOMBIE SURVIVAL GAME | " << endl;
    cout << "========================" << endl;
    cout << endl << "----------------" << endl;
	cout << "1 - Start Game" << endl;
	cout << "2 - Instructions" << endl;
	cout << "3 - Exit" << endl;
	cout << "----------------" << endl;
    cin >> start;

    if (start == 1) {
		
        system("cls");
		srand((time(0))); // Seed for random number generation - randomize map elements
        generateMap();
		zomSpawn(i, Z);
        

        while (true) {
			printMap();
			health();

			//thread t(timer); //doesn't like it if i move this line above printMap()
			
            char m;
            m = _getch(); // Get single character input without enter
            movePlayer(m);

            moveCount++;
            for (i = 0; i < Z; i++) {
                zombie z(zomb[i].first, zomb[i].second);//aim: upload zombie coords into x and y in class zombie - WORKS - first and second becomes x and y in class
                z.moveTowards(playerX, playerY);
				zomb[i].first = z.x;   //update vector coordinates after movement
				zomb[i].second = z.y;
            }
			//WORKS!! however - Zs overlap when they move onto same space - can i prevent this?

            if (playerX == X - 1 && playerY == Y - 1) {
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