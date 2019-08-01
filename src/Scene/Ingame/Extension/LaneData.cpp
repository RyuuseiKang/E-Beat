//
//  LaneData.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#include "LaneData.hpp"

void LaneData::AddBPMList(int _key, float _value) {
	bpms.insert(make_pair(_key, _value));
}

void LaneData::AddBPM(int _bar, int _key) {
	Marker m = optionTimeLine[_bar];
	m.bpm = bpms[_key];

	optionTimeLine.insert(make_pair(_bar, m));
}

void LaneData::AddSpeed(int _bar, int _position, float _value) {
	Marker m = optionTimeLine[_bar];
	m.speed = _value;

	optionTimeLine.insert(make_pair(_bar, m));
}

void LaneData::AddBarBeat(int _bar, float _value) {
	Marker m = optionTimeLine[_bar];
	m.barBeat = _value;

	optionTimeLine.insert(make_pair(_bar, m));
}

void LaneData::AddNote(int _bar, string _key, string _value) {
	vector<Note> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.isExist = true;
			n.position = _key;
		}

		note.push_back(n);
	}
	noteLane.lane[_key][_bar].note = note;
}

void LaneData::AddLongNote(int _bar, string _key, string _group, string _value) {
	vector<Note> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.isExist = true;
			n.position = _key;
		}

		note.push_back(n);
	}
	longNoteLane.lane[_group][_bar].note = note;
}

void LaneData::AddSlideNote(int _bar, string _key, string _group, string _value) {
	vector<Note> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.isExist = true;
			n.position = _key;
		}

		note.push_back(n);
		
	}
	slideLane.lane[_group][_bar].note = note;
}
