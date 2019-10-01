//
//  OptionList.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 27/07/2019.
//

#include "OptionList.hpp"

OptionList::OptionList() {
	difficultyLagel.loadImage("Scene/MusicSelect/Difficulty_Label.png");

	levelLabel[0].loadImage("Scene/MusicSelect/Level_0.png");
	levelLabel[1].loadImage("Scene/MusicSelect/Level_1.png");
	levelLabel[2].loadImage("Scene/MusicSelect/Level_2.png");
}

OptionList::~OptionList() {

}

void OptionList::update() {
	// 이동 연산
	if (difficultyAnimationTime <= leastTime)
		difficultyAnimationTime++;
}

void OptionList::draw(int _x, int _y, int _z) {
	difficultyLagel.draw(1450, 230);
	
	auto easeOutExpo = getEasingFunction(EaseOutCirc);
	double animationValue = easeOutExpo(difficultyAnimationTime / leastTime);
	int diffYPos = difficultyAnimationDirection * ( (1 - animationValue) * 67);

	// 레벨 1598, 230 표시 위치, 높이 67

	levelLabel[2].draw(1598, 96 + (67 * difficulty) - diffYPos);
	levelLabel[1].draw(1598, 163 + (67 * difficulty) - diffYPos);
	levelLabel[0].draw(1598, 230 + (67 * difficulty) - diffYPos);


	ofPushMatrix();

	ofTranslate(_x, _y, _z);
	
	// 이동 애니메이션 처리
	// if (isDifficultyMove) {
	// 	double moveY = ((-(1 / 10.0) * (moveCounter - 10) * (moveCounter - 10)) + 10) / 10 * distance;
	// 	if (!moveDirection)
	// 		moveY = -moveY;
	// 	ofTranslate(0, moveY, 0);
	// }
	// 
	// if(moveDirection)
	// 	ofDrawBitmapStringHighlight("Option List", 100, 100);
	// else
	// 	ofDrawBitmapStringHighlight("Option List", 100, 100 + distance);

	ofPopMatrix();
}

void OptionList::keyPressed(int key) {
	if (key == 'd') {
		switch (option) {
		case 0:
			setDifficulty(false);
			break;

		case 1:
			break;
		}
	}

	if (key == 'f') {
		switch (option) {
		case 0:
			setDifficulty(true);
			break;

		case 1:
			break;
		}
	}

	if (key == 'k') {
		option++;

		if (option > 1)
			option = 0;
	}
}

void OptionList::keyReleased(int key) {

}

void OptionList::animationStart(bool _direction) {
	//moveDirection = _direction;
	//difficultyAnimationTime = 0;
}

int OptionList::getSpeed() {
	return speed;
}

int OptionList::getDifficulty() {
	return difficulty;
}

void OptionList::setDifficulty(bool _isUpper) {
	if (_isUpper)
		difficultyAnimationDirection = 1;
	else 
		difficultyAnimationDirection = -1;

	difficulty += difficultyAnimationDirection;

	bool isMoved = true;
	if (difficulty < 0) {
		difficulty = 0;
		isMoved = false;
	}

	if (difficulty > 2) {
		difficulty = 2;
		isMoved = false;
	}

	if(isMoved) 
		difficultyAnimationTime = 0;

	cout << "setting Difficulty: " << difficulty << endl;
}