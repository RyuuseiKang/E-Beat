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

#include "../Extension/ofxQRCodeGenerator.h"

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
	//void setData();

	bool isReady();

private:

	DataViewer *dataViewer;

	vector<string> designerVector;

	// 여기서부터 디자이너용
	vector<int> ScoreBackgroundRect;
	vector<int> RankBackgroundRect;

	ofxTextBlock ScoreLabel;
	vector<double> ScoreLabelVector;
	vector<int> ScoreLabelColorVector;
	ofxTextBlock JudgeLabel[4];
	vector<int> JudgeTextBlock0Vector;
	vector<int> JudgeTextBlock1Vector;
	vector<int> JudgeTextBlock2Vector;
	vector<int> JudgeTextBlock3Vector;
	ofxQRCodeGenerator nicknameRegisterQR;
	vector<double> nicknameRegisterQRVector;
	vector<int> nicknameRegisterBackgroundRectVector;
	ofImage registrationUserNameLabel;
	vector<int> registrationUserNameLabelVector;


	bool isResultEnd = false;

	void registrationToServer();
	string dataKey = "7kJKg1qGB5fO27r9T76n";

	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorIntType(vector<string> str);
	vector<double> changeVectorDoubleType(vector<string> str);

	ofImage boxLeft, boxRight, boxTop, boxBottom, boxLeftTop, boxRightTop, boxLeftBottom, boxRightBottom;
};

#endif /* __RESULT_HPP_ */