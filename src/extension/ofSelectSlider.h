//
//  ofSelectSlider.h
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#ifndef __OF_SELECT_SLIDER_H_
#define __OF_SELECT_SLIDER_H_

#include <iostream>
#include "../ofMain.h"

class ofSelectSlider {
public:
	ofSelectSlider();
	~ofSelectSlider();

	void draw();

	void setMaxCount(int _maxCount);
	void setPosition(int _position);

private:

	int position = 0;
	float maxCount = 1;
};

#endif __OF_SELECT_SLIDER_H_