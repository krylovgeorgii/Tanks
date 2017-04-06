#pragma once
#include "ofMain.h"

class MovableBarrier {
public:
        MovableBarrier(double x, double y, int maxX, int maxY, int H = 30, int W = 100, string barrierIconFile = "images/brick.jpg") : 
		x(x), y(y), MAX_X(maxX), MAX_Y(maxY), H(H), W(W), barrierIconFile(barrierIconFile) {

		rx = x + W / 2;
		lx = x - W / 2;
    		uy = y + H / 2;
    		dy = y - H / 2;
 	}

        void setup();
        void draw();
	void move(const double dx, const double dy, double & newDeltaX, double & newDeltaY, vector<MovableBarrier> & barriers, unsigned int num);

	double getRX() const { return rx; }
	double getLX() const { return lx; }
	double getUY() const { return uy; }
	double getDY() const { return dy; }

private:
        double x, y;
	const int MAX_X, MAX_Y;
	int W, H;
	double lx, rx, uy, dy;	
	double oldX, oldY;	
	double oldLX, oldRX, oldUY, oldDY;

	string barrierIconFile;
        ofImage barrierIcon;
};
/* END FILE Barrier.h */
