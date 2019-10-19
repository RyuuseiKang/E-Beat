//
//  Result.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/10/2019.
//

#ifndef __RESULT_HPP_
#define __RESULT_HPP_

#include <iostream>
#include "../ofMain.h"


#include "../Ingame/Extension/DataViewer.hpp"

class Result {
public:

	Result();
	~Result();

	void update(bool keys[256]);
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);

	void setDesign();
	void LoadBoxRect();
	void DrawBoxRect(float x, float y, float w, float h);

	void readDesigner();

	void setDataViewer(DataViewer *_dataViewer);

	bool isReady();

private:

	DataViewer *dataViewer;

	vector<string> designerVector;

	// 여기서부터 디자이너용
	vector<int> ScoreBackgroundRect;
	vector<int> RankBackgroundRect;

	bool isResultEnd = false;

	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorIntType(vector<string> str);
	vector<double> changeVectorDoubleType(vector<string> str);

	ofImage boxLeft, boxRight, boxTop, boxBottom, boxLeftTop, boxRightTop, boxLeftBottom, boxRightBottom;
};

#endif /* __RESULT_HPP_ */