//
//  ofSelectSlider.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "ofSelectSlider.h"

ofSelectSlider::ofSelectSlider() {

}

ofSelectSlider::~ofSelectSlider() {

}

void ofSelectSlider::draw() {
	// 슬라이더 전체
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle(620, 958, 680, 4);

	// 슬라이더 
	ofSetColor(255, 255, 255, 255);
	ofDrawRectangle(620 + ((680 / maxCount) * position) - 2, 958 - 3, (680 / maxCount) + 4, 10);
}

void ofSelectSlider::setMaxCount(int _maxCount) {
	maxCount = _maxCount;
}

void ofSelectSlider::setPosition(int _position) {
	position = _position;
}
