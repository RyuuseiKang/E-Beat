//
//  DataViewer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/04/2019.
//

#ifndef __DATA_VIEWER_HPP_
#define __DATA_VIEWER_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/FileSystem.hpp"
#include "../Extension/ofxTextBlock.h"

class DataViewer {
public:

	DataViewer();
	DataViewer(FileSystem* _file);
	~DataViewer();

	void update();
	void draw();

	void setScore(double _score);
	void upCombo();
	void breakCombo();

	void readDesigner();
	
private:
	void setDesign();

	vector<string> designerVector;
	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorType(vector<string> str);

	double score;
	unsigned int combo;

	// 판정 예
	// JUSTICE_CRITICAL
	// JUSTICE
	// ATTACK
	//MISS
	unsigned int judge[4];
    ofxTextBlock judgeTextBlock[4];

	unsigned int maxCombo;

	ofImage LevelBackgroundRect;
	vector<int> LevelBackgroundRectVector;
    
    ofColor levelColor[2];
};

#endif // __DATA_VIEWER_HPP_
