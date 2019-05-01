//
//  LaneViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#include "LaneViewer.hpp"

LaneViewer::LaneViewer() {
	gui.setup();
	gui.add(rX.setup("Rotate X", 56.6, -100, 100));
	gui.add(rY.setup("Rotate Y", 0, -100, 100));
	gui.add(rZ.setup("Rotate Z", 0, -100, 100));
	gui.add(tX.setup("Translate X", 903, 500, 1200));
	gui.add(tY.setup("Translate Y", 634.125, -500, 1200));
	gui.add(tZ.setup("Translate Z", -110, -300, 200));
	gui.add(x.setup("x", 0, -3000, 3000));
	gui.add(y.setup("y", 0, -3000, 3000));
	gui.add(w.setup("width", 113.8, -500, 500));
	gui.add(h.setup("height", 345, -500, 500));
}

LaneViewer::~LaneViewer() {

}

void LaneViewer::update() {

}

void LaneViewer::draw() {
	ofPushMatrix();
		ofRotateX(rX);
		ofRotateY(rY);
		ofRotateZ(rZ);
		ofTranslate(tX, tY, tZ);
		ofDrawRectangle(x, y, w, h);
	ofPopMatrix();

	gui.draw();
}