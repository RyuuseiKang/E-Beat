//
//  MusicList.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 04/04/2019.
//

#include "MusicList.hpp"

MusicCard *card;
MusicList::MusicList() {
	card = new MusicCard[maxCount];

	//for(int i = 1; i <= maxCount; i++)
	//	card[i - 1].setImage(to_string(i));
}

void MusicList::addItem(string musicName) {
	static int i = 0;
	card[i].setMusicData(musicName);
	i++;
}

MusicList::~MusicList() {
	delete[] card;
}

void MusicList::update() {
	// 이동 연산
	if (isMove)
		moveCounter--;
	else
		return;
	
	if(moveCounter <= 0)
		isMove = false;
	
	// 카드들 update(); 처리
	for (int i = 0; i < maxCount; i++) {
		card[i].update();
	}

	//cout << selectedPosition << endl;
}

void MusicList::draw() {
	ofPushMatrix();
	
	// 초기 포지션 잡는 부분
	double pos = 363 - ((selectedPosition) * 311);
	//cout << pos << endl;
	ofTranslate(pos, 0, 0);

	// 이동 애니메이션 처리
	if (isMove) {
		double moveX = ((-(1 / 10.0) * (moveCounter - 10) * (moveCounter - 10)) + 10) / 10 * 285;
		if (!moveDirection)
			moveX = -moveX;
		ofTranslate(moveX, 0, 0);
	}
	
	// 돌면서 포지션 잡는 부분
	for (int i = 0; i < maxCount; i++) {
		if (i == selectedPosition)
			ofTranslate(285 + 26, 0, 0);
		else if (i == selectedPosition + 1)
			ofTranslate(423 + 75 + 48, 0, 0);
		else 
			ofTranslate(285 + 26, 0, 0);

		card[i].draw();
	}

	ofPopMatrix();
}

void MusicList::setPosition(int selectedKey) {
	bool direction = selectedKey - selectedPosition + 1;
	//cout << direction << endl;

	selectedPosition = selectedKey;

	if(direction)
	if (selectedPosition - 1 >= 0)
		card[selectedPosition - 1].Deselect(direction);

	card[selectedPosition].Select(direction);

	if(!direction)
	if (selectedPosition + 1 <= maxCount)
		card[selectedPosition + 1].Deselect(direction);

	move(direction);
}

void MusicList::setMaxCount(int max) {
	maxCount = max;
}

void MusicList::move(bool direction) {
	moveCounter = 10;
	isMove = true;
	moveDirection = direction;
}
