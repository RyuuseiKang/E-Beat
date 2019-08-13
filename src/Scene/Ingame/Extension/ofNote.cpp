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

	float borderWidth = 5 * pow(float(length), noteBorder);
	float notePos = (pos * noteWidth);
	float endBorderWidth = 5 * pow(float(endLength), noteBorder);
	float endNotePos = (endPos * noteWidth);
	noteImage[0]->draw(notePos, y, borderWidth, noteHeight);
	noteImage[1]->draw(notePos + borderWidth, y, (noteWidth * length) - borderWidth - borderWidth, noteHeight);
	noteImage[2]->draw(notePos + borderWidth + (noteWidth * length) - borderWidth - borderWidth, y, borderWidth, noteHeight);

	if(noteType >= 2) {
			noteImage[0]->draw(endNotePos, endY, endBorderWidth, noteHeight);
			noteImage[1]->draw(endNotePos + endBorderWidth, endY, (noteWidth * endLength) - endBorderWidth - endBorderWidth, noteHeight);
			noteImage[2]->draw(endNotePos + endBorderWidth + (noteWidth * endLength) - endBorderWidth - endBorderWidth, endY, endBorderWidth, noteHeight);
	}
}

void ofNote::setNoteImage(ofImage *img, int _type) {
	switch (_type) {
	case 1:
		normalNoteImage[0] = &img[0];
		normalNoteImage[1] = &img[1];
		normalNoteImage[2] = &img[2];
		break;

	case 2:
		longNoteImage[0] = &img[0];
		longNoteImage[1] = &img[1];
		longNoteImage[2] = &img[2];
		break;

	case 3:
		slideNoteImage[0] = &img[0];
		slideNoteImage[1] = &img[1];
		slideNoteImage[2] = &img[2];
		break;
	}
}

void ofNote::setOriginData(string noteData) {
	char _length = noteData.substr(1, 1).c_str()[0];
	if (noteData.substr(1, 1).c_str()[0] >= 'a') length = _length - 87;
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

void ofNote::setNoteLength(string _length) {
	char len = _length.substr(1, 1).c_str()[0];

	if (len >= 'a') length = len - 87;
	else length = atoi(&len);
}

void ofNote::setEndNoteLength(string _length) {
	char len = _length.substr(1, 1).c_str()[0];

	if (len >= 'a') endLength = len - 87;
	else endLength = atoi(&len);
}

void ofNote::addNoteLength(string _length) {
	char len = _length.substr(1, 1).c_str()[0];

	if (len >= 'a') middleLength.push_back(len - 87);
	else middleLength.push_back(atoi(&len));
}

void ofNote::setNoteOption(NOTE_TYPE _type) {
	type = _type;
}

void ofNote::setType(int _type) {
	noteType = _type;

	switch (noteType) {
	case 1:
		noteImage[0] = normalNoteImage[0];
		noteImage[1] = normalNoteImage[1];
		noteImage[2] = normalNoteImage[2];
		break;

	case 2:
		noteImage[0] = longNoteImage[0];
		noteImage[1] = longNoteImage[1];
		noteImage[2] = longNoteImage[2];
		break;

	case 3:
		noteImage[0] = slideNoteImage[0];
		noteImage[1] = slideNoteImage[1];
		noteImage[2] = slideNoteImage[2];
		break;

	}

	colorType[0][0] = ofColor(169, 85, 236, 216);
	colorType[0][1] = ofColor(240, 244, 8, 216);
	colorType[1][0] = ofColor(169, 85, 236, 216);
	colorType[1][1] = ofColor(14, 228, 245, 216);
}

void ofNote::setPosition(int _pos) {
	pos = _pos;
}

void ofNote::addPosition(int _pos) {
	middlePos.push_back(_pos);
}

void ofNote::setEndPosition(int _pos) {
	endPos = _pos;
}

void ofNote::setYPosition(int _y) {
	y = -_y;
}

void ofNote::addYPosition(int _y) {
	middleY.push_back(-_y);
}

void ofNote::setEndYPosition(int _endY) {
	endY = -_endY;
}

void ofNote::setHiSpeed(double _hiSpeed) {
	hiSpeed = _hiSpeed;

	y = y * hiSpeed;
	endY = endY * hiSpeed;
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
			position = make_pair(make_pair(position.first.first, middlePos[i]), make_pair(position.second.first, middleY[i] * hiSpeed));
			noteLength = make_pair(noteLength.first, middleLength[i]);

			addMesh(position, noteLength, noteType);

			position = make_pair(make_pair(middlePos[i], NULL), make_pair(middleY[i] * hiSpeed, NULL));
			noteLength = make_pair(middleLength[i], NULL);
		}

		position = make_pair(make_pair(position.first.first, endPos), make_pair(position.second.first, endY));
		noteLength = make_pair(noteLength.first, endLength);

		addMesh(position, noteLength, noteType);
	}
}

void ofNote::addMesh(pair<pair<int, int>, pair<double, double>> _position, pair<int, int> _noteLength, int _noteType) {
	// x, y to x, y
	pair<pair<double, double>, pair<double, double>> firstPosition = make_pair(make_pair((_position.first.first * noteWidth), _position.second.first + (noteHeight / 2)), make_pair((_position.first.first * noteWidth) + (noteWidth * _noteLength.first), _position.second.first + (noteHeight / 2)));
	pair<pair<double, double>, pair<double, double>> endPosition = make_pair(make_pair((_position.first.second * noteWidth), _position.second.second + (noteHeight / 2)), make_pair((_position.first.second * noteWidth) + (noteWidth * _noteLength.second), _position.second.second + (noteHeight / 2)));
	
	pair<pair<double, double>, pair<double, double>> middlePosition = make_pair(make_pair((firstPosition.first.first + endPosition.first.first) / 2, (firstPosition.first.second + endPosition.first.second) / 2), make_pair((firstPosition.second.first + endPosition.second.first) / 2, (firstPosition.second.second + endPosition.second.second) / 2));
	
	ofMesh mesh[2];
	mesh[0].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh[0].addVertex(ofPoint(firstPosition.first.first, firstPosition.first.second));
	mesh[0].addColor(colorType[_noteType - 2][0]);
	mesh[0].addVertex(ofPoint(firstPosition.second.first, firstPosition.second.second));
	mesh[0].addColor(colorType[_noteType - 2][0]);
	mesh[0].addVertex(ofPoint(middlePosition.first.first, middlePosition.first.second));
	mesh[0].addColor(colorType[_noteType - 2][1]);
	mesh[0].addVertex(ofPoint(middlePosition.second.first, middlePosition.second.second));
	mesh[0].addColor(colorType[_noteType - 2][1]);

	mesh[1].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh[1].addVertex(ofPoint(endPosition.first.first, endPosition.first.second));
	mesh[1].addColor(colorType[_noteType - 2][0]);
	mesh[1].addVertex(ofPoint(endPosition.second.first, endPosition.second.second));
	mesh[1].addColor(colorType[_noteType - 2][0]);
	mesh[1].addVertex(ofPoint(middlePosition.first.first, middlePosition.first.second));
	mesh[1].addColor(colorType[_noteType - 2][1]);
	mesh[1].addVertex(ofPoint(middlePosition.second.first, middlePosition.second.second));
	mesh[1].addColor(colorType[_noteType - 2][1]);

	meshVector.push_back(make_pair(mesh[0], mesh[1]));
}