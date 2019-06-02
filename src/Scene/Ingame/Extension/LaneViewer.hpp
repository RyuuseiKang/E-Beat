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
#include "Extension/Parser.hpp"
#include "ofNote.hpp"

class LaneViewer {
public:
	LaneViewer();
	~LaneViewer();

	void update();
	void draw();

private:
	void genrateNote();

	ofxPanel gui;

	ofFile *musicFile;

	Parser *parser;
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
};

#endif // __LANE_VIEWER_HPP_
