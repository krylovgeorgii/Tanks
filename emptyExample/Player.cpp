#include "Player.h"

Player::Player(int maxX, int maxY) : MAX_X(maxX), MAX_Y(maxY) 
{
	x = 200;
	y = 200;

	H = 70;
	W = 40;

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;
}

void Player::setup()
{
	tankIcon.load("images/tank.png");
}

void Player::move()
{
	double speed = 0.2;
	double speedX = 0, speedY = 0;

	oldX = x;
	oldY = y;

	oldLX = lx;
	oldRX = rx;
	oldUY = uy;
	oldDY = dy;

	if (keys['w'])
	{
		speedY = -speed;
	}

	if (keys['s'])
	{
		speedY = speed;
	}

	if (keys['a'])
	{
		speedX = -speed;
	}

	if (keys['d'])
	{
		speedX = speed;
	}

	x = x + speedX;
	y = y + speedY;

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;

	if (lx < 0)
	{
		x = W / 2;
	}
	else if (rx > MAX_X)
	{
		x = MAX_X - W / 2;
	}

	if (dy < 0)
	{
		y = H / 2;
	}
	else if (uy > MAX_Y)
	{
		y = MAX_Y - H / 2;
	}

	rx = x + W / 2;
	lx = x - W / 2;
	uy = y + H / 2;
	dy = y - H / 2;
}

void Player::draw()
{
	tankIcon.draw(lx, dy, W, H);
}

void Player::keyChange(int key, int state)
{
	keys[key] = state;
}