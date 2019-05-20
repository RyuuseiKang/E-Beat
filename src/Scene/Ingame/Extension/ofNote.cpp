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

	// for (int i = 0; i < 3; i++)
	// 	noteImage[i]->loadImage("Scene/Ingame/LaneViewer/Note/Normal_0" + to_string(i + 1) + ".png");
}


ofNote::~ofNote() {

}

void ofNote::update() {

}

void ofNote::draw() {
	if (!isVisible) return;

	//ofTranslate(0, slider, 0);
	float borderWidth = 5 * pow(float(length), noteBorder);
	float notePos = (pos * noteWidth);
	noteImage[0]->draw(notePos, y, borderWidth, noteHeight);
	noteImage[1]->draw(notePos + borderWidth, y, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
	noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, y, borderWidth, noteHeight);

	//cout << "x: " << notePos << ", y: " << y << endl;
}

void ofNote::setNoteImage(ofImage *img) {
	noteImage[0] = &img[0];
	noteImage[1] = &img[1];
	noteImage[2] = &img[2];

}

void ofNote::setOriginData(string noteData) {
	char _length = noteData.substr(1, 1).c_str()[0];
	if (noteData.substr(1, 1).c_str()[0] >= 'a') length = 10 + 97 - _length;
	else length = atoi(&_length);

	cout << " Length: " << length;
	
	NOTE_TYPE _noteType;
	switch (atoi(noteData.substr(0, 1).c_str())) {
		case 1:
			_noteType = NORMAL_NOTE;
		break;
	}
	//setNoteOption(_noteType);
}

void ofNote::setNoteLength(int _length) {
	length = _length;
}

void ofNote::setNoteOption(NOTE_TYPE _type) {
	type = _type;
}

void ofNote::setPosition(int _pos) {
	cout << " Position: " << _pos << ", ";
	pos = _pos;
}

void ofNote::setYPosition(int _y) {
	y = _y;
}

void ofNote::hide() {
	isVisible = false;
}
