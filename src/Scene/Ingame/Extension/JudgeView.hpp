//
//  JudgeView.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/09/2019.
//

#ifndef __JUDGE_VIEW_
#define __JUDGE_VIEW_

#include <iostream>
#include "../ofMain.h"
#include "ofNote.hpp"

#include "JudgeImage.hpp"

class JudgeView {
public:
	JudgeView();
	~JudgeView();

	void AddJugde(short _judgeTime);

	void update();
	void draw();

private:
	ofImage* judgeImage[4];

	vector<JudgeImage*> imageVector;
};

#endif /* __JUDGE_VIEW_ */