//
//  JudgeImage.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/09/2019.
//

#include "JudgeImage.hpp"

JudgeImage::JudgeImage() {

}

JudgeImage::JudgeImage(ofImage* _image) {
	image = _image;
}

JudgeImage::~JudgeImage() {
	
}

void JudgeImage::update() {
	t++;
}

void JudgeImage::draw() {
	auto easeOutExpo = getEasingFunction(EaseOutExpo);
	double animationValue = easeOutExpo(t / leastTime);
	int yPos = 800 - (animationValue * 100);

	int xPos = ((1920 / 2) - (image->getWidth() / 2));

	ofSetColor(255, 255, 255, animationValue * 255);
	image->draw(xPos, yPos);
}

bool JudgeImage::isEnd() {
	return (t > leastTime);
}
