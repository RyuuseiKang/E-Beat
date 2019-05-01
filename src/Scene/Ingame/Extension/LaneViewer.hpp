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

class LaneViewer {
public:
	LaneViewer();
	~LaneViewer();

	void update();
	void draw();

private:
	ofxPanel gui;

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
	ofImage texturePtr;
};

#endif // __LANE_VIEWER_HPP_