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
	double getScore();
	void upPerfect();
	void upGreat();
	void upGood();
	void upMiss();
	void upCombo();
	void breakCombo();

	void readDesigner();

	void setDifficult(int _difficult);
	int getDifficult();
	void setLevel(int _level);

	double getRate();
	int getJudge0();
	int getJudge1();
	int getJudge2();
	int getJudge3();

	void setMusicName(string _musicName);
	string getMusicName();
	void setArtistName(string _artistName);
	void setMetaData(meta_data _metas);

private:
	void setDesign();
	void LoadBoxRect();
	void DrawBoxRect(float x, float y, float w, float h);

	ScrollableTextBlock musicNameLabel;
	vector<int> musicNameLabelVector;
	ScrollableTextBlock artistNameLabel;
	vector<int> artistNameLabelVector;

	ofImage albumArt;

	vector<string> designerVector;
	vector<string> dataParse(string itemName);
	vector<string> split(string str, char delimiter);
	vector<int> changeVectorIntType(vector<string> str);
	vector<double> changeVectorDoubleType(vector<string> str);

	double score = 0;
	ofxTextBlock scoreTextBlock;
	vector<int> scoreTextBlockVector;
	ofImage scoreLabel;
	vector<int> scoreLabelVector;
	unsigned int combo = 0;
	ofxTextBlock comboTextBlock;
	vector<int> comboTextBlockVector;
	ofImage comboLabel;
	vector<int> comboLabelVector;
	unsigned int maxCombo = 0;
	ofxTextBlock maxComboTextBlock;
	vector<int> maxComboTextBlockVector;
	ofImage maxComboLabel;
	vector<int> maxComboLabelVector;


	// 판정 예
	// JUSTICE_CRITICAL
	// JUSTICE
	// ATTACK
	// MISS
	unsigned int judge[4];
	ofxTextBlock judgeTextBlock[4];
	
	int difficult = 1;
	int level = 10;
	string musicName = "";

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

	ofImage JudgeBackground;
	vector<int> JudgeBackgroundVector;
	vector<int> JudgeTextBlock0Vector;
	vector<int> JudgeTextBlock1Vector;
	vector<int> JudgeTextBlock2Vector;
	vector<int> JudgeTextBlock3Vector;


	vector<int> albumArtVector;
	vector<int> albumArtBoxVector;

	ofImage boxLeft, boxRight, boxTop, boxBottom, boxLeftTop, boxRightTop, boxLeftBottom, boxRightBottom;
};

#endif // __DATA_VIEWER_HPP_
