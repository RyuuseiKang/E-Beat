//
//  ofSelectSlider.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "ofSelectSlider.hpp"

ofSelectSlider::ofSelectSlider() {
	slashText.init("Fonts/Gotham-Bold.ttf", 13);
	maxText.init("Fonts/Gotham-Bold.ttf", 16);
	positionText.init("Fonts/Gotham-Bold.ttf", 22);

	slashText.setText("/");

	maxText.setText(to_string(int(maxCount)));
	positionText.setText(to_string(position + 1));
}

ofSelectSlider::~ofSelectSlider() {

}

void ofSelectSlider::update() {

}

void ofSelectSlider::draw() {
	// 슬라이더 전체
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle(620, 958, 680, 4);

	// 슬라이더 
	ofSetColor(255, 255, 255, 255);
	ofDrawRectangle(620 + ((680 / maxCount) * position) - 2, 958 - 3, (680 / maxCount) + 4, 10);
	
	// 슬라이더 하단 숫자부
	slashText.setColor(255, 255, 255, 255);
	slashText.drawCenter(975, 974);
	// slashText.drawCenter(ofGetWidth() / 2, 974);

	maxText.setColor(255, 255, 255, 255);
	maxText.draw(981, 970);
	//maxText.drawString(to_string(int(maxCount)), 971, 992);

	positionText.setColor(255, 255, 255, 255);
	positionText.drawRight(960, 962);
	//positionText.drawString(to_string(position + 1), 946 - realWidth, 992);

}

void ofSelectSlider::setMaxCount(int _maxCount) {
	maxCount = _maxCount;

	maxText.setText(to_string(int(maxCount)));
	//maxText.wrapTextArea(ofGetWidth(), ofGetHeight());

	if (maxCount <= 0)
		maxCount = 1;
}

void ofSelectSlider::setPosition(int _position) {
	position = _position;

	positionText.setText(to_string(position + 1));
	//positionText.wrapTextArea(ofGetWidth(), ofGetHeight());

	if (position < 0)
		position = 0;

	if (position >= maxCount)
		position = maxCount - 1;
}
