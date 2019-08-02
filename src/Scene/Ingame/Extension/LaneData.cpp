//
//  LaneData.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#include "LaneData.hpp"

void LaneData::AddBPMList(int _key, double _value) {
	bpms.insert(make_pair(_key, _value));
}

void LaneData::AddBPM(int _bar, int _key) {
	Marker *m;
	if (optionTimeLine[_bar] != NULL)
		m = optionTimeLine[_bar];
	else
		m = new Marker;


	m->bpm = bpms[_key];
	
	optionTimeLine[_bar] = m;
}

void LaneData::AddSpeed(int _bar, int _position, double _value) {
	Marker *m;
	if (optionTimeLine[_bar] != NULL)
		m = optionTimeLine[_bar];
	else
		m = new Marker;

	m->speed = _value;
	
	optionTimeLine[_bar] = m;
}

void LaneData::AddBarBeat(int _bar, double _value) {
	Marker *m;
	if (optionTimeLine[_bar] != NULL)
		m = optionTimeLine[_bar];
	else
		m = new Marker;

	m->barBeat = _value;

	optionTimeLine[_bar] = m;
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

void LaneData::Process() {
	// 여기서 노트 데이터 시간을 계산해서 추가

}
