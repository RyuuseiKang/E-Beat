﻿//
//  ofSelectSlider.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#ifndef __OF_SELECT_SLIDER_HPP_
#define __OF_SELECT_SLIDER_HPP_

#include <iostream>
#include "../ofMain.h"
#include "Extension/ofxTextSuite.h"

class ofSelectSlider {
public:
	ofSelectSlider();
	~ofSelectSlider();

	void update();
	void draw(int _x, int _y, int _z);

	void setMaxCount(int _maxCount);
	void setPosition(int _position);

private:

	int position = 0;
	float maxCount = 1;

	ofxTextBlock slashText;
	ofxTextBlock maxText;
	ofxTextBlock positionText;
};

#endif __OF_SELECT_SLIDER_HPP_