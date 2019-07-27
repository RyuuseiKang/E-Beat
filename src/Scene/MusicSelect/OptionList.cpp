//
//  OptionList.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 27/07/2019.
//

#include "OptionList.hpp"

OptionList::OptionList() {

}

OptionList::~OptionList() {

}

void OptionList::update() {
	// 이동 연산
	if (isMove)
		moveCounter--;
	else
		return;

	if (moveCounter <= 0)
		isMove = false;
}

void OptionList::draw(int _x, int _y, int _z) {
	ofPushMatrix();

	ofTranslate(_x, _y, _z);
	
	// 이동 애니메이션 처리
	if (isMove) {
		double moveY = ((-(1 / 10.0) * (moveCounter - 10) * (moveCounter - 10)) + 10) / 10 * distance;
		if (!moveDirection)
			moveY = -moveY;
		ofTranslate(0, moveY, 0);
	}

	if(moveDirection)
		ofDrawBitmapStringHighlight("Option List", 100, 100);
	else
		ofDrawBitmapStringHighlight("Option List", 100, 100 + distance);

	ofPopMatrix();
}

void OptionList::keyPressed(int key) {

}

void OptionList::keyReleased(int key) {

}

void OptionList::animationStart(bool _direction) {
	moveDirection = _direction;
	isMove = true;
	moveCounter = 15;
}
