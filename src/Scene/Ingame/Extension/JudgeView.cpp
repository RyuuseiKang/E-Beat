//
//  JudgeView.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/09/2019.
//

#include "JudgeView.hpp"

JudgeView::JudgeView() {
	judgeImage[0] = new ofImage();
	judgeImage[1] = new ofImage();
	judgeImage[2] = new ofImage();
	judgeImage[3] = new ofImage();

	judgeImage[0]->load("Scene/Ingame/LaneViewer/Judge/perfect.png");
	judgeImage[1]->load("Scene/Ingame/LaneViewer/Judge/great.png");
	judgeImage[2]->load("Scene/Ingame/LaneViewer/Judge/good.png");
	judgeImage[3]->load("Scene/Ingame/LaneViewer/Judge/miss.png");
}

JudgeView::~JudgeView() {

}

void JudgeView::AddJugde(short _judgeTime) {
	int key;
	if (abs(_judgeTime) <= 55)
		key = 0;
	else if (abs(_judgeTime) <= 150)
		key = 1;
	else if (abs(_judgeTime) <= 350)
		key = 2;
	else
		key = 3;

	imageVector.push_back(new JudgeImage(judgeImage[key]));
}

void JudgeView::update() {
	for (vector<JudgeImage*>::iterator imageIterator = imageVector.begin(); imageIterator != imageVector.end(); ) {
		if ((*imageIterator)->isEnd()) {
			JudgeImage* jImage = (*imageIterator);
			imageIterator = imageVector.erase(imageIterator);
			delete jImage;
		}
		else {
			(*imageIterator)->update();
			++imageIterator;
		}	
	}
}

void JudgeView::draw() {
	for (vector<JudgeImage*>::iterator imageIterator = imageVector.begin(); imageIterator != imageVector.end(); imageIterator++) {
		(*imageIterator)->draw();
	}
}
