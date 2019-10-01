//
//  OptionList.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 27/07/2019.
//

#ifndef __OPTION_LIST_HPP_
#define __OPTION_LIST_HPP_

#include <iostream>
#include "../ofMain.h"

// https://github.com/nicolausYes/easing-functions
#include "../Extension/easing.h"

class OptionList {
public:
	OptionList();
	~OptionList();

	void update();
	void draw(int _x, int _y, int _z);
	void keyPressed(int key);
	void keyReleased(int key);

	void animationStart(bool _option);

	int getSpeed();
	int getDifficulty();
	void setDifficulty(bool _isUpper);

private:
	ofImage difficultyLagel;

	ofImage levelLabel[3];

	// 옵션 순번
	// 0: 난이도
	// 1: 속도
	int option = 0;

	int speed = 10;
	int difficulty = 0;

	bool isDifficultyMove = false;
	
	double leastTime = 20;
	double difficultyAnimationTime = 0;
	int difficultyAnimationDirection = 1;

	int distance = 300;
	
};

#endif /* __OPTION_LIST_HPP_ */
