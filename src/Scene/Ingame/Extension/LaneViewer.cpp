//
//  LaneViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#include "LaneViewer.hpp"

LaneViewer::LaneViewer() {
	musicFile = new ofFile();

	musicFile->open(ofToDataPath("sus.sus"));

	for (int i = 0; i < 3; i++)
		normalNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Normal_0" + to_string(i + 1) + ".png");

	gui.setup();
	gui.add(rX.setup("Rotate X", 56.6, -100, 100));
	gui.add(rY.setup("Rotate Y", 0, -100, 100));
	gui.add(rZ.setup("Rotate Z", 165, -360, 360));
	gui.add(tX.setup("Translate X", 846, 500, 1200));
	gui.add(tY.setup("Translate Y", 634.125, -500, 2400));
	gui.add(tZ.setup("Translate Z", -110, -300, 200));
	gui.add(x.setup("x", 0, -3000, 3000));
	gui.add(y.setup("y", 0, -3000, 3000));
	gui.add(w.setup("width", 114, -500, 500));
	gui.add(h.setup("height", 150, -500, 500));
	gui.add(tilt.setup("tilt", 0, -100, 100));

	for ( int i = 0; i < 8; i++)
		texturePtr[i].loadImage("Scene/Ingame/LaneViewer/airNote" + to_string(i) + ".png");

	note = new ofNote(NOTE_TYPE(NORMAL_NOTE));
	note->setNoteImage(normalNote);
	note->setNoteLength(1);
}

LaneViewer::~LaneViewer() {

}

void LaneViewer::update() {
	n++;

	if (n < 0)
		n = 0;

	k = n % 24 / 3;
	texturePtr[k].resize(w, h / 2);

	airNotePath.clear();
	airNotePath.lineTo(x - tilt, y, 0);
	airNotePath.lineTo(x + w, y, 0);
	airNotePath.lineTo(x + w , y + (h / 2), 0);
	airNotePath.lineTo(x - tilt, y + (h / 2), 0);

	fbo.allocate(w, h, GL_RGBA); //or GL_RED if you are using the programmable renderer
	fbo.begin();
	ofClear(255, 255, 255, 0);
	airNotePath.draw();
	fbo.end();
	texturePtr[k].getTexture().setAlphaMask(fbo.getTexture());

	// airNote.clear();
	// airNote.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	// airNote.addVertex(ofPoint(x, y, 0));
	// airNote.addTexCoord(ofVec2f(0, 0));
	// airNote.addVertex(ofPoint(x + w, y, 0));
	// airNote.addTexCoord(ofVec2f(w, 0));
	// airNote.addVertex(ofPoint(x + w - tilt, y + (h / 2), 0));
	// airNote.addTexCoord(ofVec2f(w, h / 2));
	// airNote.addVertex(ofPoint(x - tilt, y + (h / 2), 0));
	// airNote.addTexCoord(ofVec2f(0, h / 2));
	// airNote.addVertex(ofPoint(x, y, 0));
	// airNote.addTexCoord(ofVec2f(0, 0));
	
}	

int slider = 0;
void LaneViewer::draw() {
	ofPushMatrix();
		ofRotateX(rX);
		ofTranslate(tX, tY, tZ);

		slider += 2;
		
		

		ofSetColor(255, 255, 255, 255);
		note->setPosition(0);
		note->setNoteLength(4);
		note->draw(x, y);

		note->setPosition(4);
		note->setNoteLength(4);
		note->draw(x, y - 50);
		
		note->setPosition(8);
		note->setNoteLength(4);
		note->draw(x, y - 120);

		note->setPosition(12);
		note->setNoteLength(4);
		note->draw(x, y - 90);

		note->setPosition(8);
		note->setNoteLength(4);
		note->draw(x, y - 90);

		//ofDrawRectangle(x, y, w, -700);

		ofRotateX(rX - (rX*2));
		ofRotateY(rY);
		ofRotateX(rZ);
		
		
		//texturePtr[k].draw(0, 0);
	ofPopMatrix();

	gui.draw();
}