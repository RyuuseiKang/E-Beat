//
//  LaneData.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#include "LaneData.hpp"

LaneData::LaneData() {
	// 일반 노트 이미지
	for (int i = 0; i < 3; i++)
		normalNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Normal_0" + to_string(i + 1) + ".png");
	// 롱 노트 이미지
	for (int i = 0; i < 3; i++)
		longNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Long_0" + to_string(i + 1) + ".png");
	// 슬라이드 노트 이미지
	for (int i = 0; i < 3; i++)
		slideNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Slide_0" + to_string(i + 1) + ".png");
	// 보너스 노트 이미지
	for (int i = 0; i < 3; i++)
		bonusNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Bonus_0" + to_string(i + 1) + ".png");
}

LaneData::~LaneData() {

}

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
	NoteBar n;
	n.note = note;

	slideLane.lane[_group][_bar].push_back(n);
}

void LaneData::SetTBP(int _tbp) {
	tbp = _tbp;
}

void LaneData::SetHiSpeed(double _hiSpeed) {
	hiSpeed = _hiSpeed;
}

void LaneData::Process() {
	// 여기서 노트 데이터 시간을 계산해서 추가

	// 레인 싱크타입 잡는 작업
	typedef map<int, Marker*>::iterator markerOutmap;

	int lastBar = 0;
	int lastTime = 0;
	int lastPosition = 0;
	double lastBarBeat = 4;
	double lastBpm = 120;
	double lastSpeed = 1;

	for (markerOutmap markerIterator = optionTimeLine.begin(); markerIterator != optionTimeLine.end(); ++markerIterator) {
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
		double speed = markerIterator->second->speed;
		
		// 마디 첫 실제시간
		markerIterator->second->syncTime = ((60000 / lastBpm) * lastBarBeat * (bar - lastBar)) + lastTime;
		// 마디 첫 위치
		markerIterator->second->position = tbp * lastBarBeat * lastSpeed * (bar - lastBar) + lastPosition;

		// 한 마디 높이
		markerIterator->second->height = tbp * barBeat * speed;

		lastBpm = bpm;
		lastBarBeat = barBeat;
		lastBar = bar;
		lastSpeed = speed;

		// 마커의 첫 시간
		lastTime = markerIterator->second->syncTime;
		// 마커의 첫 위치
		lastPosition = markerIterator->second->position;

	}
	
	// 레인 싱크타임 잡는 작업 끝
	
	// 노트 싱크 잡는 작업
	typedef map<string, map<int, NoteBar>>::iterator noteLaneOutmap;
	typedef map<string, map<int, vector<NoteBar>>>::iterator slideLaneOutmap;
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
						++markerIterator;
					}
					--markerIterator;

					// 마디 한개 시간
					double fullyBarTime = (60000 / markerIterator->second->bpm) * markerIterator->second->barBeat;

					// 현재 마디 최초 시각
					double firstSyncTime = ((60000 / markerIterator->second->bpm) * markerIterator->second->barBeat * (noteBarIterator->first - markerIterator->first)) + markerIterator->second->syncTime;

					// 현재 마디 최초 포지션
					double firstPosition = (noteBarIterator->first - markerIterator->first) * markerIterator->second->height + markerIterator->second->position;

					// 노트들의 실제 시간 측정
					NoteBar noteBar = noteBarIterator->second;
					int noteSize = noteBar.note.size();

					for (noteOutVector noteIterator = noteBar.note.begin(); noteIterator != noteBar.note.end(); noteIterator++) {
						const char *noteType = (*noteIterator)->type.c_str();
						int dist = distance(noteBar.note.begin(), noteIterator);

						double YPos = (markerIterator->second->height / noteSize) * dist + firstPosition;
						ofNote *note;
						switch (noteType[0]) {
							// 노트 시작점
							case '1':
								note = new ofNote();
								note->setNoteImage(normalNote, 1);
								note->setNoteImage(longNote, 2);
								note->setNoteImage(slideNote, 3);
								noteMap.push_back(note);
								(*noteIterator)->note = note;

								// 노트 가로넓이
								(*noteIterator)->note->setNoteLength((*noteIterator)->type.c_str());
								// X포지션
								(*noteIterator)->note->setPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
								// Y포지션
								(*noteIterator)->note->setYPosition(YPos);

								(*noteIterator)->note->setType(1);
								break;

							// 노트 끝점
							case '2':
								(*noteIterator)->note = noteMap.back();

								// 노트 가로넓이
								(*noteIterator)->note->setEndNoteLength((*noteIterator)->type.c_str());
								// X포지션
								(*noteIterator)->note->setEndPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
								// Y포지션
								(*noteIterator)->note->setEndYPosition(YPos);

								(*noteIterator)->note->setType(2);
								break;

							// 노트 중간점
							case '3':
								(*noteIterator)->note = noteMap.back();

								// 노트 가로넓이
								(*noteIterator)->note->addNoteLength((*noteIterator)->type.c_str());
								// X포지션
								(*noteIterator)->note->addPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
								// Y포지션
								(*noteIterator)->note->addYPosition(YPos);
								break;
						}

						if ((*noteIterator)->type != "00") {
							double syncTime = (fullyBarTime / noteSize) * dist + firstSyncTime;
							(*noteIterator)->syncTime = syncTime;
							(*noteIterator)->note->addSyncTime(syncTime);

							if (noteType[0] == '1')
								sortedNoteMap[syncTime].push_back((*noteIterator)->note);
						}
					}

				}
			}
			markerIterator = optionTimeLine.begin();
		}

		// 슬라이드 레인 처리
		for (slideLaneOutmap noteLaneIterator = slideLane.lane.begin(); noteLaneIterator != slideLane.lane.end(); noteLaneIterator++) {
			markerIterator->first; // 마커의 마디번호
			noteLaneIterator->first; // 노트의 구분번호
			for (map<int, vector<NoteBar>>::iterator laneIterator = noteLaneIterator->second.begin(); laneIterator != noteLaneIterator->second.end(); laneIterator++) {
				for (vector<NoteBar>::iterator slideVectorIterator = laneIterator->second.begin(); slideVectorIterator != laneIterator->second.end(); slideVectorIterator++) {
					laneIterator->first; // 노트의 마디번호
					slideVectorIterator->note; // note값

					// 노트의 마디번호가 더 크면 현재 마커의 마디번호를 갱신
					while (markerIterator != optionTimeLine.end() && markerIterator->first <= laneIterator->first) {
						++markerIterator;
					}
					--markerIterator;

					// 마디 한개 시간
					double fullyBarTime = (60000 / markerIterator->second->bpm) * markerIterator->second->barBeat;

					// 현재 마디 최초 시각
					double firstSyncTime = ((60000 / markerIterator->second->bpm) * markerIterator->second->barBeat * (laneIterator->first - markerIterator->first)) + markerIterator->second->syncTime;

					// 현재 마디 최초 포지션
					double firstPosition = (laneIterator->first - markerIterator->first) * markerIterator->second->height + markerIterator->second->position;

					// 노트들의 실제 시간 측정
					NoteBar noteBar = *slideVectorIterator;
					int noteSize = noteBar.note.size();
					for (noteOutVector noteIterator = noteBar.note.begin(); noteIterator != noteBar.note.end(); noteIterator++) {
						const char *noteType = (*noteIterator)->type.c_str();
						int dist = distance(noteBar.note.begin(), noteIterator);

						double YPos = (markerIterator->second->height / noteSize) * dist + firstPosition;
						ofNote *note;

						switch (noteType[0]) {
							// 노트 시작점
						case '1':
							note = new ofNote();
							note->setNoteImage(normalNote, 1);
							note->setNoteImage(longNote, 2);
							note->setNoteImage(slideNote, 3);
							noteMap.push_back(note);
							(*noteIterator)->note = note;

							// 노트 가로넓이
							(*noteIterator)->note->setNoteLength((*noteIterator)->type.c_str());
							// X포지션
							(*noteIterator)->note->setPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
							// Y포지션
							(*noteIterator)->note->setYPosition(YPos);

							(*noteIterator)->note->setType(3);
							break;

							// 노트 끝점
						case '2':
							(*noteIterator)->note = noteMap.back();

							// 노트 가로넓이
							(*noteIterator)->note->setEndNoteLength((*noteIterator)->type.c_str());
							// X포지션
							(*noteIterator)->note->setEndPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
							// Y포지션
							(*noteIterator)->note->setEndYPosition(YPos);
							break;

							// 노트 중간점
						case '5':
							(*noteIterator)->note = noteMap.back();

							// 노트 가로넓이
							(*noteIterator)->note->addNoteLength((*noteIterator)->type.c_str());
							// X포지션
							(*noteIterator)->note->addPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
							// Y포지션
							(*noteIterator)->note->addYPosition(YPos);
							break;
						case '3':
							(*noteIterator)->note = noteMap.back();

							// 노트 가로넓이
							(*noteIterator)->note->addNoteLength((*noteIterator)->type.c_str());
							// X포지션
							(*noteIterator)->note->addPosition(strtol((*noteIterator)->position.c_str(), 0, 16));
							// Y포지션
							(*noteIterator)->note->addYPosition(YPos);
							break;
						}

						if ((*noteIterator)->type != "00") {
							double syncTime = (fullyBarTime / noteSize) * dist + firstSyncTime;
							(*noteIterator)->syncTime = syncTime;

							if (noteType[0] == '1')
								sortedNoteMap[syncTime].push_back((*noteIterator)->note);
						}
					}
				}
			}
			
		}

		break;
	}

}

void LaneData::GenerateNote() {
	// ofNote 마지막 작업
	typedef vector<ofNote*>::iterator noteMapOutMap;
	for (vector<ofNote*>::iterator noteMapIterator = noteMap.begin(); noteMapIterator != noteMap.end(); noteMapIterator++) {
		(*noteMapIterator)->setHiSpeed(hiSpeed);
		(*noteMapIterator)->Make();
	}

}

vector<ofNote*> LaneData::GetNoteMap() {
	return noteMap;
}

map<double, vector<ofNote*>> LaneData::GetSortedNoteMap() {
	return sortedNoteMap;
}

void LaneData::draw() {
	typedef vector<ofNote*>::iterator noteMapOutMap;
	for (vector<ofNote*>::iterator noteMapIterator = noteMap.begin(); noteMapIterator != noteMap.end(); noteMapIterator++) {
		(*noteMapIterator)->draw();
	}
}

Marker* LaneData::GetNowMarker(double _syncTime) {
	Marker* m;
	typedef map<int, Marker*>::iterator markerOutmap;
	for (markerOutmap markerIterator = optionTimeLine.begin(); markerIterator != optionTimeLine.end(); markerIterator++) {
		if (markerIterator->second->syncTime <= _syncTime) {
			m = markerIterator->second;
		}
		else {
			break;
		}
	}
	
	if (_syncTime <= 0)
		return NULL;
	else
		return m;
}