//
//  ofNote.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 05/05/2019.
//

#ifndef __OF_NOTE_HPP_
#define __OF_NOTE_HPP_

#include "../ofMain.h"

enum NOTE_TYPE {
	NORMAL_NOTE,
	LONG_NOTE,
	AIR_UP_NOTE,
	AIR_DOWN_NOTE,
	AIR_LONG_NOTE
};

class ofNote {
public:
	ofNote();
	ofNote(NOTE_TYPE _type);
	~ofNote();

	void update();
	void draw();

	void setNoteImage(ofImage *img, int _type);
	void setOriginData(string noteData);

	void setNoteOption(NOTE_TYPE _type);
	void setType(int _type);

	void setNoteLength(const char *_length);
	void setEndNoteLength(const char *_length);
	void addNoteLength(const char *_length);

	void setPosition(int _pos);
	void addPosition(int _pos);
	void setEndPosition(int _pos);

	void setYPosition(int _y);
	void addYPosition(int _y);
	void setEndYPosition(int _endY);

	void setHiSpeed(double _hiSpeed);

	void hide();

	void Make();

private:
	NOTE_TYPE type;
	ofImage *noteImage[3];

	int length;
	int endLength;
	vector<int> middleLength;

	int pos;
	int endPos;
	vector<int> middlePos;

	double y;
	double endY;
	vector<double> middleY;

	const double noteHeight = 20;
	const double noteWidth = 14.25;
	const double noteBorder = 0.35;

	bool isVisible = true;

	int noteType = 1;

	double hiSpeed = 1.0;

	vector<pair<ofMesh, ofMesh>> meshVector;

	ofColor colorType[2][2];

	void ofNote::addMesh(pair<pair<int, int>, pair<double, double>> _position, pair<int, int> _noteLength, int _noteType);

};

#endif // __OF_NOTE_HPP_
