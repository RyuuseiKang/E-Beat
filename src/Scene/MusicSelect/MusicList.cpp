#include "MusicList.h"
//
//  MusicList.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 04/04/2019.
//

MusicList::MusicList() {

}

MusicList::~MusicList() {

}

void MusicList::update() {
	if (isMove)
		moveCounter--;
	else
		return;

	if(moveCounter <= 0)
		isMove = false;

	if(selectedPosition - 1 < 0)
		card[selectedPosition - 1].update();

	card[selectedPosition].update();

	if (selectedPosition + 1 >= maxCount)
		card[selectedPosition + 1].update();
}

void MusicList::draw() {
	ofPushMatrix();

	if (isMove) {
		double moveX = ((-(1 / 20.0) * moveCounter * moveCounter) + 20) / 20 * 500;
		if (moveDirection)
			moveX = -moveX;
		ofTranslate(moveX, 0, 0);
	}

	for (int i = 0; i <= 5; i++) {
		ofTranslate(normalPadding + 285, 0, 0);
		card[i].draw(0);
	}

	ofPopMatrix();
}

void MusicList::move(bool direction) {
	moveCounter = 20;
	isMove = true;
	moveDirection = direction;

	if (selectedPosition - 1 < 0)
		card[selectedPosition - 1].Deselect();

	card[selectedPosition].Select();

	if (selectedPosition + 1 >= maxCount)
		card[selectedPosition + 1].Deselect();
}