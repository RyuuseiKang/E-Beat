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

class OptionList {
public:
	OptionList();
	~OptionList();

	void update();
	void draw(int _x, int _y, int _z);
	void keyPressed(int key);
	void keyReleased(int key);

	void animationStart(bool _option);

private:

	int speed = 10;
	int difficulty = 0;

	bool isMove = false;
	bool moveDirection = false;
	int moveCounter = 15;

	int distance = 300;
	
};

#endif /* __OPTION_LIST_HPP_ */
