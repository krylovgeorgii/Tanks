#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundAuto(false);
        ofBackground(100, 10, 10);

        p1.setup();

        barriers.push_back(MovableBarrier(300, 300, W - 1, H - 1));
        barriers.push_back(MovableBarrier(500, 500, W - 1, H - 1));
        barriers.push_back(MovableBarrier(700, 700, W - 1, H - 1));
         barriers.push_back(MovableBarrier(300, 800, W - 1, H - 1));

        for (unsigned int i = 0; i < barriers.size(); ++i) {
            barriers[i].setup();
        }
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(255, 255, 255);

    p1.move();

    move();

    for (unsigned int i = 0; i < barriers.size(); ++i) {
        barriers[i].draw();
    }

    p1.draw();
}

void ofApp::move() {
    unsigned int counter = 0;

    for (unsigned int i = 0; i < barriers.size(); ++i) {
        if (counter > 1) break;

        if((p1.getUY() >= barriers[i].getDY() && p1.getDY() <= barriers[i].getUY()
                && ((p1.getRX() > barriers[i].getLX() && p1.getOldRX() <= barriers[i].getLX())
                || (p1.getLX() < barriers[i].getRX() && p1.getOldLX() >= barriers[i].getLX())))
                ||(p1.getRX() >= barriers[i].getLX() && p1.getLX() <= barriers[i].getRX()
                && ((p1.getDY() < barriers[i].getUY() && p1.getOldDY() >= barriers[i].getUY())
                || (p1.getUY() > barriers[i].getDY() && p1.getOldUY() <= barriers[i].getDY())))) {

            double newDeltaX, newDeltaY;
            double tmpX = p1.getRX() - p1.getOldRX();
            double tmpY = p1.getUY() - p1.getOldUY();

            if (abs(tmpX) > abs(tmpY)) { tmpY = 0; }
            else { tmpX = 0; }

            barriers[i].move(tmpX, tmpY, newDeltaX, newDeltaY, barriers, i);

            if (abs(tmpX) > abs(tmpY)) {
                p1.x -= newDeltaX;
                p1.y = p1.oldY;
            } else {
                p1.y -= newDeltaY;
                p1.x = p1.oldX;
            }

            ++counter;
        }
    }

    p1.rx = p1.x + p1.W / 2;
    p1.lx = p1.x - p1.W / 2;
    p1.uy = p1.y + p1.H / 2;
    p1.dy = p1.y - p1.H / 2;

    if (counter > 1) {
        p1.x = p1.oldX;
        p1.y = p1.oldY;
    } else if (counter == 1) {
        p1.speed = 0.12;
    } else {
        p1.speed = 0.2;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
        p1.keyChange(key, 1);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
        p1.keyChange(key, 0);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
/* END FILE offApp.cpp */

