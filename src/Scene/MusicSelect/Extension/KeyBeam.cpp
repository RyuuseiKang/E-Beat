//
//  KeyBeam.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#include "KeyBeam.hpp"

KeyBeam::KeyBeam() {

}

KeyBeam::~KeyBeam() {

}

void KeyBeam::update() {
	ofImage::update();

	if (isActive) {
		alpha = 1 / 30.0 * alphaKey * alphaKey / 30 * 255;
		alphaKey--;
		if (alphaKey < 0)
			isActive = false;
	}
}

void KeyBeam::draw() {
	//ofEnableAlphaBlending();
	if (isActive) {
		ofSetColor(255, 255, 255, alpha);
		ofImage::draw(x, y);
	}
	//ofDisableAlphaBlending();

	ofSetColor(255, 255, 255, 255);
}

void KeyBeam::setPosition(float _x, float _y) {
	x = _x;
	y = _y;
}

void KeyBeam::setCount(int num) {
	this->setPosition((1920 / 2 - 319 - 319) + (319 * num), 1080 - 136);
}

bool KeyBeam::setColor(string color) {
	return ofImage::loadImage("Scene/MusicSelect/BottomButtonsBeam_" + color + ".png");
}

void KeyBeam::Active() {
	isActive = true;
	alphaKey = 30;
}
