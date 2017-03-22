#pragma once
#include "ofMain.h"

class Player
{
public:
	Player(int maxX, int maxY);

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

private:
	double x, y;
	double lx, rx, uy, dy;
	int H, W;
	double oldX, oldY;
	double oldLX, oldRX, oldUY, oldDY;
	const int MAX_X, MAX_Y;
	int keys[256];

	ofImage tankIcon;

	friend class ofApp;
};