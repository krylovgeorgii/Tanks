#include "MovableBarrierr.h"

MovableBarrier::MovableBarrier(double x, double y, int maxX, int maxY, double H, double W, string barrierIconFile) :
x(x), y(y), MAX_X(maxX), MAX_Y(maxY), H(H), W(W), barrierIconFile(barrierIconFile)
{

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;
}

void MovableBarrier::setup() {
	barrierIcon.load(barrierIconFile);
}

void MovableBarrier::draw() {
	barrierIcon.draw(lx, dy, W, H);
}

void MovableBarrier::move(const double deltaX, const double deltaY, double & newDeltaX, double & newDeltaY,
	vector<MovableBarrier> & barriers, unsigned int num) {

	newDeltaX = 0;
	newDeltaY = 0;

	oldX = x;
	oldY = y;

	oldLX = lx;
	oldRX = rx;
	oldUY = uy;
	oldDY = dy;

	x += deltaX;
	y += deltaY;

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;

	if (lx < 0) {
		x = W / 2;
	}
	else if (rx > MAX_X) {
		x = MAX_X - W / 2;
	}

	if (dy < 0) {
		y = H / 2;
	}
	else if (uy > MAX_Y) {
		y = MAX_Y - H / 2;
	}

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;

	for (unsigned int i = 0; i < barriers.size(); ++i) {
		if (i == num) continue;
		if ((uy >= barriers[i].getDY() && dy <= barriers[i].getUY())
			&& ((oldRX <= barriers[i].getLX() && rx > barriers[i].getLX())
				|| (oldLX >= barriers[i].getRX() && lx < barriers[i].getRX()))) {

			x = oldX;
		}

		if ((rx >= barriers[i].getLX() && lx <= barriers[i].getRX())
			&& ((oldUY <= barriers[i].getDY() && uy > barriers[i].getDY())
				|| (oldDY >= barriers[i].getUY() && dy < barriers[i].getUY()))) {

			y = oldY;
		}
	}

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;

	newDeltaX = deltaX + oldX - x;
	newDeltaY = deltaY + oldY - y;
}