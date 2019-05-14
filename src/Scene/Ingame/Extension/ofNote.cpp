//
//  ofNote.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 05/05/2019.
//

#include "ofNote.hpp"

ofNote::ofNote() {

}

ofNote::ofNote(NOTE_TYPE _type) {
	type = _type;
}


ofNote::~ofNote() {

}

void ofNote::update() {

}

void ofNote::draw(float x, float y) {
	if (!isVisible) return;

	//ofTranslate(0, slider, 0);
	float borderWidth = 5 * pow(float(length), noteBorder);
	float notePos = (pos * noteWidth);
	noteImage[0]->draw(notePos, y, borderWidth, noteHeight);
	noteImage[1]->draw(notePos + borderWidth, y, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
	noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, y, borderWidth, noteHeight);

	
}

void ofNote::setNoteImage(ofImage *img) {
	noteImage[0] = &img[0];
	noteImage[1] = &img[1];
	noteImage[2] = &img[2];
}

void ofNote::setNoteLength(int _length) {
	length = _length;
}

void ofNote::setNoteOption(NOTE_TYPE _type) {
	type = _type;
}

void ofNote::setPosition(int _pos) {
	pos = _pos;
}

void ofNote::hide() {
	isVisible = false;
}
