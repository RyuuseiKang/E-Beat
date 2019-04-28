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
	
	void setDifficult(int _difficult);

private:
	void setDesign();
	void DrawBoxRect(float x, float y, float w, float h);

	ofImage albumArt;

	vector<string> designerVector;
	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorIntType(vector<string> str);
	vector<double> changeVectorDoubleType(vector<string> str);

	double score;
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
	ofImage LevelBackgroundRect;
	vector<int> LevelBackgroundRectVector;

	ofMesh levelColorBackgroundMesh;
	vector<double> levelColorBackgroundMeshVector;

    ofColor levelColor[5];
	vector<int> levelColorVector[5];

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
};

#endif // __DATA_VIEWER_HPP_
