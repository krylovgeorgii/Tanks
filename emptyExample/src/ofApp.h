#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Barrier.h"

class ofApp : public ofBaseApp {
private:
	const int W = 1920;
	const int H = 1080;

public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	inline int getW() const {
		return W;
	}

	inline int getH() const {
		return H;
	}
	
	void move();

	Player p1 { W - 1, H - 1 } ;
	vector<MovableBarrier> barriers;
};
/* END FILE offApp.h */
