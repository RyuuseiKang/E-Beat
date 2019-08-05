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
	if (optionTimeLine.size()) {
		if (optionTimeLine[_bar] != NULL)
			m = optionTimeLine[_bar];
		else
			m = new Marker();
	}
	else
		m = new Marker();

	m->bpm = bpms[_key];
	m->option += 1;

	optionTimeLine[_bar] = m;
}

void LaneData::AddSpeed(int _bar, int _position, double _value) {
	Marker *m;
	if (optionTimeLine.size()) {
		if (optionTimeLine[_bar] != NULL)
			m = optionTimeLine[_bar];
		else
			m = new Marker();
	}
	else
		m = new Marker();

	m->speed = _value;
	m->option += 2;

	optionTimeLine[_bar] = m;
}

void LaneData::AddBarBeat(int _bar, double _value) {
	Marker *m;
	if (optionTimeLine.size()) {
		if (optionTimeLine[_bar] != NULL)
			m = optionTimeLine[_bar];
		else
			m = new Marker();
	}
	else
		m = new Marker();
		
	m->barBeat = _value;
	m->option += 4;

	optionTimeLine[_bar] = m;
}

void LaneData::AddNote(int _bar, string _key, string _value) {
	vector<Note*> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note *n = new Note;

		n->type = _value.substr(i * 2, 2);
		if (n->type != "00") {
			n->isExist = true;
			n->position = _key;
		}

		note.push_back(n);
	}
	noteLane.lane[_key][_bar].note = note;
}

void LaneData::AddLongNote(int _bar, string _key, string _group, string _value) {
	vector<Note*> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note *n = new Note;

		n->type = _value.substr(i * 2, 2);
		if (n->type != "00") {
			n->isExist = true;
			n->position = _key;
		}

		note.push_back(n);
	}
	longNoteLane.lane[_group][_bar].note = note;
}

void LaneData::AddSlideNote(int _bar, string _key, string _group, string _value) {
	vector<Note*> note;
	for (int i = 0; i < _value.length() / 2; i++) {
		Note *n = new Note;

		n->type = _value.substr(i * 2, 2);
		if (n->type != "00") {
			n->isExist = true;
			n->position = _key;
		}

		note.push_back(n);
	}
	slideLane.lane[_group][_bar][_key].note = note;
}

void LaneData::Process() {
	// 여기서 노트 데이터 시간을 계산해서 추가

	// 레인 싱크타입 잡는 작업
	typedef map<int, Marker*>::iterator markerOutmap;

	int lastBar = 0;
	int lastTime = 0;
	double lastBarBeat = 4;
	double lastBpm = 120;

	for (markerOutmap markerIterator = optionTimeLine.begin(); markerIterator != optionTimeLine.end(); markerIterator++) {
		int bar = markerIterator->first;

		char option = markerIterator->second->option;

		bool barBeatIncrement =	option & 0x0000004;
		bool speedIncrement =	option & 0x0000002;
		bool bpmIncrement =		option & 0x0000001;

		bool isNotBegin = markerIterator != optionTimeLine.begin();

		// barBeat 값이 비었을 경우
		if (!barBeatIncrement && isNotBegin) {
			--markerIterator;
			double _barBeat = markerIterator++->second->barBeat;
			markerIterator->second->barBeat = _barBeat;
		}

		// speed 값이 비었을 경우
		if (!speedIncrement && isNotBegin) {
			--markerIterator;
			double _speed = markerIterator++->second->speed;
			markerIterator->second->speed = _speed;
		}

		// bpm 값이 비었을 경우
		if (!bpmIncrement && isNotBegin) {
			--markerIterator;
			double _bpm = markerIterator++->second->bpm;
			markerIterator->second->bpm = _bpm;
		}

		double bpm = markerIterator->second->bpm;
		double barBeat = markerIterator->second->barBeat;
		
		markerIterator->second->syncTime = ((60 / lastBpm) * 1000 * lastBarBeat * (bar - lastBar)) + lastTime;

		lastBpm = bpm;
		lastBarBeat = barBeat;
		lastBar = bar;

		lastTime = markerIterator->second->syncTime;
	}
	
	// 레인 싱크타임 잡는 작업 끝
	
	// 노트 싱크 잡는 작업
	typedef map<string, map<int, NoteBar>>::iterator noteLaneOutmap;
	typedef map<string, map<int, map<string, NoteBar>>>::iterator slideNoteLaneOutmap;
	typedef map<int, NoteBar>::iterator noteBarOutmap;
	typedef vector<Note*>::iterator noteOutVector;

	for (markerOutmap markerIterator = optionTimeLine.begin(); markerIterator != optionTimeLine.end(); markerIterator++) {

		
		// 노트 싱크 잡는 작업
		noteLaneOutmap laneMap[3][2] = { {noteLane.lane.begin(), noteLane.lane.end()}, {longNoteLane.lane.begin(), longNoteLane.lane.end()}};

		for (int i = 0; i < 2; i++) {
			for (noteLaneOutmap noteLaneIterator = laneMap[i][0]; noteLaneIterator != laneMap[i][1]; noteLaneIterator++) {
				markerIterator->first; // 마커의 마디번호
				noteLaneIterator->first; // 노트의 레인번호
				for (noteBarOutmap noteBarIterator = noteLaneIterator->second.begin(); noteBarIterator != noteLaneIterator->second.end(); noteBarIterator++) {
					noteBarIterator->first; // 노트의 마디번호
					noteBarIterator->second; // note값

					// 노트의 마디번호가 더 크면 현재 마커의 마디번호를 갱신
					while (markerIterator != optionTimeLine.end() && markerIterator->first <= noteBarIterator->first) {
						markerIterator++;
					}
					markerIterator--;

					// 마디 한개 시간
					double fullyBarTime = (60 / markerIterator->second->bpm) * 1000 * markerIterator->second->barBeat;

					// 현재 마디 최초지점
					double firstSyncTime = ((60 / markerIterator->second->bpm) * 1000 * markerIterator->second->barBeat * (noteBarIterator->first - markerIterator->first)) + markerIterator->second->syncTime;

					// 노트들의 실제 시간 측정
					NoteBar noteBar = noteBarIterator->second;
					int noteSize = noteBar.note.size();
					for (noteOutVector noteIterator = noteBar.note.begin(); noteIterator != noteBar.note.end(); noteIterator++) {
						if ((*noteIterator)->type != "00") {
							int dist = distance(noteBar.note.begin(), noteIterator);
							double syncTime = (fullyBarTime / noteSize) * dist + firstSyncTime;
							(*noteIterator)->syncTime = syncTime;
						}
					}

				}
			}
			markerIterator = optionTimeLine.begin();
		}

		// 슬라이드 레인 처리
		for (slideNoteLaneOutmap noteLaneIterator = slideLane.lane.begin(); noteLaneIterator != slideLane.lane.end(); noteLaneIterator++) {
			markerIterator->first; // 마커의 마디번호
			noteLaneIterator->first; // 노트의 구분번호
			for (map<int, map<string, NoteBar>>::iterator laneIterator = noteLaneIterator->second.begin(); laneIterator != noteLaneIterator->second.end(); laneIterator++) {
				for (map<string, NoteBar>::iterator noteBarIterator = laneIterator->second.begin(); noteBarIterator != laneIterator->second.end(); noteBarIterator++) {
					laneIterator->first; // 노트의 마디번호
					noteBarIterator->second; // note값

					// 노트의 마디번호가 더 크면 현재 마커의 마디번호를 갱신
					while (markerIterator != optionTimeLine.end() && markerIterator->first <= laneIterator->first) {
						markerIterator++;
					}
					markerIterator--;

					// 마디 한개 시간
					double fullyBarTime = (60 / markerIterator->second->bpm) * 1000 * markerIterator->second->barBeat;

					// 현재 마디 최초지점
					double firstSyncTime = ((60 / markerIterator->second->bpm) * 1000 * markerIterator->second->barBeat * (laneIterator->first - markerIterator->first)) + markerIterator->second->syncTime;

					// 노트들의 실제 시간 측정
					NoteBar noteBar = noteBarIterator->second;
					int noteSize = noteBar.note.size();
					for (noteOutVector noteIterator = noteBar.note.begin(); noteIterator != noteBar.note.end(); noteIterator++) {
						if ((*noteIterator)->type != "00") {
							int dist = distance(noteBar.note.begin(), noteIterator);
							double syncTime = (fullyBarTime / noteSize) * dist + firstSyncTime;
							(*noteIterator)->syncTime = syncTime;
						}
					}

				}
			}
			
		}

		markerIterator = optionTimeLine.end();
	}

}
