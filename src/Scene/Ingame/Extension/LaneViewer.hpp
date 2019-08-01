//
//  LaneViewer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#ifndef __LANE_VIEWER_HPP_
#define __LANE_VIEWER_HPP_

#include <iostream>
#include "../ofMain.h"

#include "ofxGui.h"
#include "../Extension/FileSystem.hpp"
#include "Extension/Parser.hpp"
#include "Extension/LaneData.hpp"
#include "ofNote.hpp"

class LaneViewer {
public:
	LaneViewer();
	LaneViewer(FileSystem* _file);
	~LaneViewer();

	void update();
	void draw();

	void setMusicPosition(int _musicPos);
	void play();

private:
	int CalcYPosition(int _musicPos);
	void genrateNote();

	ofxPanel gui;

	ofFile *musicFile;

	Parser *parser;
	LaneData *laneData;
	//tapNote tapNotes;

	ofxFloatSlider rX;
	ofxFloatSlider rY;
	ofxFloatSlider rZ;
	ofxFloatSlider tX;
	ofxFloatSlider tY;
	ofxFloatSlider tZ;
	ofxFloatSlider x;
	ofxFloatSlider y;
	ofxFloatSlider w;
	ofxFloatSlider h;
	ofxFloatSlider tilt;

	ofMesh airNote;
	ofPath airNotePath;
	ofFbo fbo;
	ofImage texturePtr[8];

	int n;
	int k;

	ofImage normalNote[3];
	ofImage bonusNote[3];

	note_data notes;
	meta_data metas;

	map<int, vector<ofNote>* > noteMap;
	map<int, long> position;

	ofSoundPlayer player;

	string filePath;
};

#endif // __LANE_VIEWER_HPP_
