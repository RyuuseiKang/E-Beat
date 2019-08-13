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
	
	// 롱노트 그리기
	for (vector<pair<ofMesh, ofMesh>>::iterator meshVec_iter = meshVector.begin(); meshVec_iter != meshVector.end(); ++meshVec_iter) {
		(*meshVec_iter).first.draw();
		(*meshVec_iter).second.draw();
	}

	//ofTranslate(0, slider, 0);
	float borderWidth = 5 * pow(float(length), noteBorder);
	float notePos = (pos * noteWidth);
	noteImage[0]->draw(notePos, y, borderWidth, noteHeight);
	noteImage[1]->draw(notePos + borderWidth, y, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
	noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, y, borderWidth, noteHeight);

	switch (noteType) {
		case 2:
			noteImage[0]->draw(notePos, endY, borderWidth, noteHeight);
			noteImage[1]->draw(notePos + borderWidth, endY, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
			noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, endY, borderWidth, noteHeight);
			break;
	
		case 3:
	
			break;
	}
	

	//cout << "x: " << notePos << ", y: " << y << endl;
}

void ofNote::setNoteImage(ofImage *img, int _type) {
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

void ofNote::setNoteLength(const char *_length) {
	if (_length[1] >= 'a') length = 10 + 97 - _length[1];
	else length = atoi(&_length[1]);

	length = 4;
}

void ofNote::setEndNoteLength(const char *_length) {
	if (_length[1] >= 'a') endLength = 10 + 97 - _length[1];
	else endLength = atoi(&_length[1]);

	endLength = 4;
}

void ofNote::addNoteLength(const char *_length) {
	if (_length[1] >= 'a') middleLength.push_back(10 + 97 - _length[1]);
	//else middleLength.push_back(atoi(&_length[1]));

	middleLength.push_back(4);
}

void ofNote::setNoteOption(NOTE_TYPE _type) {
	type = _type;
}

void ofNote::setType(int _type) {
	noteType = _type;

	colorType[0][0] = ofColor(169, 85, 236, 216);
	colorType[0][1] = ofColor(240, 244, 8, 216);
	colorType[1][0] = ofColor(169, 85, 236, 216);
	colorType[1][1] = ofColor(14, 228, 245, 216);
}

void ofNote::setPosition(int _pos) {
	//cout << " Position: " << _pos << ", ";
	pos = _pos;
}

void ofNote::addPosition(int _pos) {
	middlePos.push_back(_pos);
}

void ofNote::setEndPosition(int _pos) {
	endPos = _pos;
}

void ofNote::setYPosition(int _y) {
	y = _y;
}

void ofNote::addYPosition(int _y) {
	middleY.push_back(_y);
}

void ofNote::setEndYPosition(int _endY) {
	endY = _endY;
}

void ofNote::setHiSpeed(double _hiSpeed) {
	hiSpeed = _hiSpeed;

	y = y * hiSpeed;
	endY = y * hiSpeed;
}

void ofNote::hide() {
	isVisible = false;
}

void ofNote::Make() {
	pair<pair<int, int>, pair<double, double>> position; // first->x, second->y
	pair<int, int> noteLength;

	position = make_pair(make_pair(pos, NULL), make_pair(y, NULL));
	noteLength = make_pair(length, NULL);

	// 첫 y포지션: y
	// 첫 x포지션: pos * noteWidth
	if (noteType >= 2) {
		for (int i = 0; i < middleLength.size(); i++) {
			position = make_pair(make_pair(position.first.first, middlePos[i]), make_pair(position.second.first, middleY[i]));
			noteLength = make_pair(noteLength.first, middleLength[i]);

			addMesh(position, noteLength, noteType);

			position = make_pair(make_pair(position.first.second, NULL), make_pair(position.second.second, NULL));
			noteLength = make_pair(noteLength.second, NULL);
		}

		position = make_pair(make_pair(position.first.first, endPos), make_pair(position.second.first, endY));
		noteLength = make_pair(noteLength.first, endLength);

		addMesh(position, noteLength, noteType);
	}
}

void ofNote::addMesh(pair<pair<int, int>, pair<double, double>> _position, pair<int, int> _noteLength, int _noteType) {
	// x, y to x, y
	pair<pair<double, double>, pair<double, double>> firstPosition = make_pair(make_pair((_position.first.first * noteWidth), (_position.second.first + (noteHeight / 2)) * hiSpeed), make_pair((_position.first.first * noteWidth) + (noteWidth * _noteLength.first), (_position.second.first + (noteHeight / 2)) * hiSpeed));
	pair<pair<double, double>, pair<double, double>> endPosition = make_pair(make_pair((_position.first.second * noteWidth), (_position.second.second + (noteHeight / 2)) * hiSpeed), make_pair((_position.first.second * noteWidth) + (noteWidth * _noteLength.second), (_position.second.second + (noteHeight / 2)) * hiSpeed));
	
	pair<pair<double, double>, pair<double, double>> middlePosition = make_pair(make_pair((firstPosition.first.first + endPosition.first.first) / 2, (firstPosition.first.second + endPosition.first.second) / 2), make_pair((firstPosition.second.first + endPosition.second.first) / 2, (firstPosition.second.second + endPosition.second.second) / 2));
	
	ofMesh mesh[2];
	mesh[0].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh[0].addVertex(ofPoint(firstPosition.first.first, firstPosition.first.second));
	mesh[0].addColor(colorType[_noteType - 2][0]);
	mesh[0].addVertex(ofPoint(firstPosition.second.first, firstPosition.second.second));
	mesh[0].addColor(colorType[_noteType - 1][0]);
	mesh[0].addVertex(ofPoint(middlePosition.first.first, middlePosition.first.second));
	mesh[0].addColor(colorType[_noteType - 1][1]);
	mesh[0].addVertex(ofPoint(middlePosition.second.first, middlePosition.second.second));
	mesh[0].addColor(colorType[_noteType - 1][1]);

	mesh[1].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh[1].addVertex(ofPoint(endPosition.first.first, endPosition.first.second));
	mesh[1].addColor(colorType[_noteType - 1][0]);
	mesh[1].addVertex(ofPoint(endPosition.second.first, endPosition.second.second));
	mesh[1].addColor(colorType[_noteType - 1][0]);
	mesh[1].addVertex(ofPoint(middlePosition.first.first, middlePosition.first.second));
	mesh[1].addColor(colorType[_noteType - 1][1]);
	mesh[1].addVertex(ofPoint(middlePosition.second.first, middlePosition.second.second));
	mesh[1].addColor(colorType[_noteType - 1][1]);

	meshVector.push_back(make_pair(mesh[0], mesh[1]));
}