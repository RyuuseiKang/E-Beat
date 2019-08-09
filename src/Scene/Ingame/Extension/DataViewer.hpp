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
#include "../Extension/ScrollableTextBlock.hpp"

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

	void setDifficult(int _difficult);
	void setLevel(int _level);

private:
	void setDesign();
	void LoadBoxRect();
	void DrawBoxRect(float x, float y, float w, float h);

	//ScrollableTextBlock musicNameLabel;
	vector<int> musicNameLabelVector;
	//ScrollableTextBlock artistNameLabel;
	vector<int> artistNameLabelVector;

	ofImage albumArt;

	vector<string> designerVector;
	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorIntType(vector<string> str);
	vector<double> changeVectorDoubleType(vector<string> str);

	double score;
	ofxTextBlock scoreLabel;
	vector<int> scoreLabelVector;
	unsigned int combo;

	// 판정 예
	// JUSTICE_CRITICAL
	// JUSTICE
	// ATTACK
	// MISS
	unsigned int judge[4];
	ofxTextBlock judgeTextBlock[4];

	unsigned int maxCombo;

	int difficult = 1;
	int level = 10;
	ofxTextBlock difficultyLabel;
	vector<double> difficultyLabelVector;
	int difficultyLabelWidth;
	int difficultyFontSize;
	vector<int> difficultyLabelColorVector;
	ofxTextBlock levelLabel;
	vector<double> levelLabelVector;
	vector<int> levelLabelColorVector;

	ofImage LevelBackgroundRect;
	vector<int> LevelBackgroundRectVector;

	ofMesh levelColorBackgroundMesh;
	vector<double> levelColorBackgroundMeshVector;

	ofColor levelColor[5];
	vector<int> levelColorVector[5];

	vector<int> userProfileBoxVector;
	vector<int> userProfileBoxBorderVector;

	vector<int> musicProfileSpliterVector;
	vector<int> musicProfileBoxBorderVector;
	vector<int> musicProfileHalfBoxVector;
	vector<int> musicProfileHalfInBoxVector;
	vector<int> musicProfileBoxVector;

	vector<int> judgeDetailBoxBorderVector;
	vector<int> judgeDetailHalfBoxVector;
	vector<int> judgeDetailHalfInBoxVector;
	vector<int> judgeDetailBoxVector;

	vector<int> albumArtVector;
	vector<int> albumArtBoxVector;

	ofImage boxLeft, boxRight, boxTop, boxBottom, boxLeftTop, boxRightTop, boxLeftBottom, boxRightBottom;
};

#endif // __DATA_VIEWER_HPP_
