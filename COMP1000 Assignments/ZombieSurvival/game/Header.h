#pragma once
#include <iostream>
#include <vector>
using namespace std;

//carry variavles over from game.cpp
extern int playerX, playerY;


class Zombie {
private:
	int z = 5; //no. zombies
	int x, y;
	vector<pair<int, int>> zomcoords; //vector to store zombie coordinates

public:

	Zombie(int X, int Y) {
		for (int i = 0; i < z; i++) {
			x = rand() % X;
			y = rand() % Y;
			if (x == 0 && y == 0 || x == X-1 && y == Y-1) {
				i--; //regenerate if spawns on player
				continue;
			}
			else {
				zomcoords.emplace_back(x, y); //store coordinates in vector
			}
		}
	}

	const vector<pair<int, int>>returncoords() const {
		return zomcoords; // return vector of coordinates to main program
		//map changes should be done in main program
	}

	void checkcoords() {
		for (int i = 0; i < z; i++) {
			cout << "Zombie " << i + 1 << " coordinates: (" << zomcoords[i].first << ", " << zomcoords[i].second << ")" << endl;
		}
	}


	//make it so two zombies won't choose the same target - can't have same coordinates?

	void zombmove(int px, int py) {		//playerX = px, playerY = py
		for (auto &coord : zomcoords) {	// : symbol means "in" - coord represents each item in zomcoords vector
			int zx = coord.first, zy = coord.second;
			int dx = px - zx, dy = py - zy;		//difference between player and zombie coordinates
			//move EITHER X OR Y coordinate closer to player, not both	
			if (dx == 0 && px == 0) {
				continue;
			}
			if (abs(dx) >= abs(dy)) { zx += (dx > 0 ? 1 : -1); }
			// abs() means negative or positive form of a number
			//if dx > 0 is true, add one, else subtract 1
			else { zy += (dy > 0 ? 1 : -1); }

			coord.first = zx;
			coord.second = zy;
		}	
	} 
};