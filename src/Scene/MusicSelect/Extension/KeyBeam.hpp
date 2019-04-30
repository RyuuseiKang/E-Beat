//
//  KeyBeam.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#ifndef __KEY_BEAM_HPP_
#define __KEY_BEAM_HPP_

#include <iostream>
#include "../ofMain.h"

class KeyBeam : ofImage {
public:
	KeyBeam();
	~KeyBeam();

	void update();
	void draw();
	
	void setCount(int num);
	bool setColor(string color);
	void Active();

private:
	bool isActive;
	void setPosition(float _x, float _y);
	float x = (1920 / 2) - (319 * 2);
	float y = 1080 - 136;

	float alpha = 0;
	int alphaKey;
};

#endif /* __KEY_BEAM_HPP_ */
