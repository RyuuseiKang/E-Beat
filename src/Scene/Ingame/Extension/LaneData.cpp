//
//  LaneData.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#include "LaneData.hpp"

void LaneData::AddBPMList(int _key, float _value) {
	bpms.at(_key) = _value;
}

void LaneData::AddBPM(int _bar, int _key) {
	optionTimeLine.at(_bar).bpm = bpms.at(_key);
}

void LaneData::AddSpeed(int _bar, int _position, float _value) {
	optionTimeLine.at(_bar).speed = _value;
}

void LaneData::AddBarBeat(int _bar, float _value) {
	optionTimeLine.at(_bar).barBeat = _value;
}

void LaneData::AddNote(int _bar, string _key, string _value) {
	for (int i = 0; i <= _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.position = _key;
		}

		noteLane.lane[_key][_bar].note.push_back(n);
	}
}

void LaneData::AddLongNote(int _bar, string _key, string _group, string _value) {
	for (int i = 0; i <= _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.position = _key;
		}

		longNoteLane.lane[_group][_bar].note.push_back(n);
	}
}

void LaneData::AddSlideNote(int _bar, string _key, string _group, string _value) {
	for (int i = 0; i <= _value.length() / 2; i++) {
		Note n;

		n.type = _value.substr(i * 2, 2);
		if (n.type != "00") {
			n.position = _key;
		}

		slideLane.lane[_group][_bar].note.push_back(n);
	}
}
