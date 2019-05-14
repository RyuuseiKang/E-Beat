//
//  Note.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 05/05/2019.
//

#include "Note.hpp"

Note::Note() {

}

Note::Note(NOTE_TYPE _type) {
	type = _type;
}


Note::~Note() {

}

void Note::update() {

}

void Note::draw(float x, float y) {
	if (!isVisible) return;

	//ofTranslate(0, slider, 0);
	float borderWidth = noteBorder * length * (1 + (3.5 / length));
	float notePos = (pos * noteWidth);
	noteImage[0]->draw(notePos, y, borderWidth, noteHeight);
	noteImage[1]->draw(notePos + borderWidth, y, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
	noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, y, borderWidth, noteHeight);
}

void Note::setNoteImage(ofImage *img) {
	noteImage[0] = &img[0];
	noteImage[1] = &img[1];
	noteImage[2] = &img[2];
}

void Note::setNoteLength(int _length) {
	length = _length;
}

void Note::setNoteOption(NOTE_TYPE _type) {
	type = _type;
}

void Note::setPosition(int _pos) {
	pos = _pos;
}

void Note::hide() {
	isVisible = false;
}
