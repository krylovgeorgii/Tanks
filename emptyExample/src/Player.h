#pragma once
#include "ofMain.h"

//class ofApp;

class Player {
public:
        Player(int maxX, int maxY) : MAX_X(maxX), MAX_Y(maxY) {
		x = 200;
		y = 200;

		H = 70;
		W = 40;

		rx = x + W / 2;
		lx = x - W / 2;
		uy = y + H / 2;
		dy = y - H / 2;

		speed = 0.2;
 	}

        void setup();
        void draw();
        void keyChange(int key, int state);
        void move();

	double getX() const { return x; }
	double getY() const { return y; } 

	double getRX() const { return rx; }
	double getLX() const { return lx; }
	double getUY() const { return uy; }
	double getDY() const { return dy; }

	double getOldX() const { return oldX; }
	double getOldY() const { return oldY; }

	double getOldRX() const { return oldRX; }
	double getOldLX() const { return oldLX; }
	double getOldUY() const { return oldUY; }
	double getOldDY() const { return oldDY; } 

//private:
        double x, y;        
	double lx, rx, uy, dy;
	double speed;
	int H, W; 
	double oldX, oldY;
	double oldLX, oldRX, oldUY, oldDY;
	const int MAX_X, MAX_Y;
	int keys[256];

        ofImage tankIcon;

	//friend class ofApp;
};
/* END FILE Player.h */
