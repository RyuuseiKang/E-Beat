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

	void setNoteImage(ofImage *img);
	void setOriginData(string noteData);

	void setNoteOption(NOTE_TYPE _type);

	void setNoteLength(char _length);
	void setEndNoteLength(char _length);
	void addNoteLength(char _length);

	void setPosition(int _pos);
	void addPosition(int _pos);
	void setEndPosition(int _pos);

	void setYPosition(int _y);
	void addYPosition(int _y);
	void setEndYPosition(int _endY);

	void hide();

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

	const float noteHeight = 20;
	const float noteWidth = 14.25;
	const float noteBorder = 0.35;

	bool isVisible = true;

	int noteType;
};

#endif // __OF_NOTE_HPP_
