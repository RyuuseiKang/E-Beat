//
//  JudgeImage.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/09/2019.
//

#ifndef __JUDGE_IMAGE_
#define __JUDGE_IMAGE_

#include <iostream>
#include "../ofMain.h"
#include "ofNote.hpp"

// https://github.com/nicolausYes/easing-functions
#include "../Extension/easing.h"

class JudgeImage {
public:
	JudgeImage();
	JudgeImage(ofImage* _image);
	~JudgeImage();

	void update();
	void draw();

	bool isEnd();

private:
	double leastTime = 35;
	double t = 0;

	ofImage* image;
};

#endif /* __JUDGE_IMAGE_ */