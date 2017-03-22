#pragma once


#include "ofMain.h"

#include <string>
#include <vector>

class MovableBarrier 
{
public:
	MovableBarrier(double x, double y, int maxX, int maxY, double H = 30, double W = 100, string barrierIconFile = "images/brick.jpg");

	void setup();
	void draw();
	void move(double dx, double dy, double & newDeldoubleaX, double & newDeldoubleaY, vector<MovableBarrier> & barriers, unsigned int num);

	double getRX() const { return rx; }
	double getLX() const { return lx; }
	double getUY() const { return uy; }
	double getDY() const { return dy; }

private:
	double x, y;
	const int MAX_X, MAX_Y;
	double W, H;
	double lx, rx, uy, dy;
	double oldX, oldY;
	double oldLX, oldRX, oldUY, oldDY;

	string barrierIconFile;
	ofImage barrierIcon;
};