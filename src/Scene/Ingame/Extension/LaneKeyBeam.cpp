//
//  KeyBeam.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/08/2019.
//

#include "LaneKeyBeam.hpp"

LaneKeyBeam::LaneKeyBeam() {
	for (int i = 0; i < 16; i++) {
		mesh[i].setMode(OF_PRIMITIVE_TRIANGLE_FAN);

		double x = (i * width);
		double height = 300;
		double gradientHeight = 150;

		mesh[i].addVertex(ofPoint(x, y));
		mesh[i].addColor(ofColor(255, 255, 255, 0));
		mesh[i].addVertex(ofPoint(x + width, y));
		mesh[i].addColor(ofColor(255, 255, 255, 0));
		mesh[i].addVertex(ofPoint(x + width, y + height));
		mesh[i].addColor(ofColor(255, 255, 255, 229));
		mesh[i].addVertex(ofPoint(x, y + height));
		mesh[i].addColor(ofColor(255, 255, 255, 229));

		// mesh[i][1].addVertex(ofPoint(x, y + height));
		// mesh[i][1].addColor(ofColor(255, 255, 255, 255));
		// mesh[i][1].addVertex(ofPoint(x + width, y + height));
		// mesh[i][1].addColor(ofColor(255, 255, 255, 255));
		// mesh[i][1].addVertex(ofPoint(x + width, y + height + gradientHeight));
		// mesh[i][1].addColor(ofColor(255, 255, 255, 0));
		// mesh[i][1].addVertex(ofPoint(x, y + height + gradientHeight));
		// mesh[i][1].addColor(ofColor(255, 255, 255, 0));
	}
}

LaneKeyBeam::~LaneKeyBeam() {

}

void LaneKeyBeam::SetKey(short _key) {
	for (int i = 0; i < 16; i++) {
		short binaryValue = pow(2, i);
		bool isPressed = (binaryValue == (_key & binaryValue));

		if (isPressed != keyPressed[i]) {
			if (isPressed != true) SetAnimation(i);
			
			keyPressed[i] = isPressed;

		}
	}
}

void LaneKeyBeam::draw() {
	for (int i = 0; i < 16; i++) {
		if (keyPressed[i])
			mesh[i].draw();
		else
			if (keyAnimation[i] > 0) {
				double opacity = (255.0 / keyAnimation[i]);
				// cout << opacity << endl;

				//mesh[i].setColor(mesh[i].getVertices().size(), ofColor(255, 255, 255, opacity));
				//mesh[i].draw();

				keyAnimation[i]--;
				ofSetColor(255, 255, 255, 255);
			}
	}
}


void LaneKeyBeam::SetAnimation(short _keyNum) {
	keyAnimation[_keyNum] = 16;
}
