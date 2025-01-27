//
//  LaneViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#include "LaneViewer.hpp"

LaneViewer::LaneViewer() {

}

LaneViewer::LaneViewer(FileSystem* _file, DataViewer * _dataViewer) {

	// 파일 주소 취득 및 노래 대기
	filePath = _file->getNowMusicPath();
	
	// 레인 데이터 생성
	laneData = new LaneData();
	dataViewer = _dataViewer;

	// 파서 생성
	parser = new Parser(filePath + _file->getNowMusicDifficulty() + ".sus", laneData);

	gui.setup();
	gui.add(rX.setup("Rotate X", 56.25, 55.5, 57.5));
	gui.add(rY.setup("Rotate Y", 0, -100, 100));
	gui.add(rZ.setup("Rotate Z", 165, -360, 360));
	gui.add(tX.setup("Translate X", 846.1, 845.0, 847.0));
	gui.add(tY.setup("Translate Y", 966, -10000, 18400));
	gui.add(tZ.setup("Translate Z", -104.503, -95.0, -105.5));
	gui.add(x.setup("x", 0, -3000, 3000));
	gui.add(y.setup("y", 0, -3000, 3000));
	gui.add(w.setup("width", 114, -500, 500));
	gui.add(h.setup("height", 150, -500, 500));
	gui.add(tilt.setup("tilt", 0, -100, 100));

	for (int i = 0; i < 8; i++)
		texturePtr[i].loadImage("Scene/Ingame/LaneViewer/airNote" + to_string(i) + ".png");

	// 키빔
	laneKeyBeam = new LaneKeyBeam();

	keyMap.clear();
	instanceKeyMap['d'] = false;
	instanceKeyMap['D'] = false;
	instanceKeyMap['f'] = false;
	instanceKeyMap['F'] = false;
	instanceKeyMap['j'] = false;
	instanceKeyMap['J'] = false;
	instanceKeyMap['k'] = false;
	instanceKeyMap['K'] = false;

	// 여기서부터 노트 생성
	GenerateNote();
}

LaneViewer::~LaneViewer() {
	delete parser;
	delete laneData;

	delete laneKeyBeam;
}

void LaneViewer::update(bool keys[256]) {
	// 여기서 레인 갱신
	double nowMS = player->getPositionMS() - wavOffset; // 현재 ms 위치
	laneY = GetCurrentScrollPosition(GetNowMarker(), player->getPositionMS() - wavOffset, hiSpeed) + yPosition;
	//cout << "nowLaneY: " << laneY << endl;

	short key = 0;
	if (keys['d'])
		key += 15;

	if (keys['D'])
		key += 15;

	if (keys['f'])
		key += 240;

	if (keys['F'])
		key += 240;

	if (keys['j'])
		key += 3840;

	if (keys['J'])
		key += 3840;

	if (keys['k'])
		key += 61440;

	if (keys['K'])
		key += 61440;

	laneKeyBeam->SetKey(key);

	// 키 처리
	for (map<char, map<long, bool>>::iterator iterator = keyMap.begin(); iterator != keyMap.end(); iterator++) {
		while (!iterator->second.empty()) {

			string key;
			switch (iterator->first) {
			case 'd':
				key = "0";
				break;

			case 'D':
				key = "0";
				break;

			case 'f':
				key = "4";
				break;

			case 'F':
				key = "4";
				break;

			case 'j':
				key = "8";
				break;

			case 'J':
				key = "8";
				break;

			case 'k':
				key = "c";
				break;

			case 'K':
				key = "c";
				break;
			}


			if (!sortedNoteMap[key].empty() && iterator->second.begin()->first > sortedNoteMap[key].begin()->first - 500 && iterator->second.begin()->second) {
				// sortedNoteMap[key].begin();

				short judgeTime = (sortedNoteMap[key].begin()->first - iterator->second.begin()->first);

				// 판정
				if (abs(judgeTime) <= 55) {
					judgeView.AddJugde(0);
					dataViewer->upPerfect();

				}
				else if (abs(judgeTime) <= 150) {
					judgeView.AddJugde(1);
					dataViewer->upGreat();

				}
				else if (abs(judgeTime) <= 350) {
					judgeView.AddJugde(2);
					dataViewer->upGood();

				}
				else {
					judgeView.AddJugde(3);
					dataViewer->upMiss();

				}

				cout << "gap " << judgeTime << "ms" << endl;
				// 여기서 콤보 증가
				dataViewer->upCombo();

				cout << "Deleted " << sortedNoteMap[key].begin()->first << "ms, Pressed " << iterator->second.begin()->first << "ms" << endl;

				// 키 맵 삭제
				sortedNoteMap[key].erase(sortedNoteMap[key].begin()->first);
			}
			// 키 프레스 맵 삭제
			iterator->second.erase(iterator->second.begin());

		}
	}
		

	// 여기서 지나간 노트 맵 삭제
	for (map<string, map<long, ofNote*>>::iterator iterator = sortedNoteMap.begin(); iterator != sortedNoteMap.end(); iterator++) {

		bool isEnd = false;
		
		while (!isEnd) {

			if (iterator->second.size() && iterator->second.begin()->first < nowMS - 500) {

				cout << nowMS << ": Deleted " << iterator->second.begin()->first << "ms" << endl;
				// 미스
				judgeView.AddJugde(3);
				// 여기서 콤보 깨기
				dataViewer->upMiss();
				dataViewer->breakCombo();

				iterator->second.erase(iterator->second.begin()->first);
			}
			else
				isEnd = true;
				
		}
	}
		
	judgeView.update();

	// if (sortedNoteMap.size() && sortedNoteMap.begin()->second. first < nowMS - 500) {
	// 	cout << nowMS << ": Deleted " << sortedNoteMap.begin()->first.first << "ms" << endl;
	// 	sortedNoteMap.erase(sortedNoteMap.begin()->first);
	// }

	// vector 비었으면 맵을 erase(key)로 삭제
}

void LaneViewer::draw() {
	ofPushMatrix();
	ofRotateX(rX);
	ofTranslate(tX, 0, tZ);
	
	ofSetColor(255, 255, 255, 255);

	// 여기서 키프레스 표시
	laneKeyBeam->draw();

	ofTranslate(0, laneY, 0);

	// 노트 그리는 곳
	laneData->draw();
	
	ofRotateX(rX - (rX * 2));
	ofRotateY(rY);
	ofRotateX(rZ);

	//texturePtr[k].draw(0, 0);
	ofPopMatrix();

	judgeView.draw();

	// gui.draw();
}

void LaneViewer::keyPressed(int key) {
	double nowMS = player->getPositionMS() - wavOffset; // 현재 ms 위치

	if (!instanceKeyMap[key]){
		keyMap[key][nowMS] = true;

		// cout << nowMS << "ms::keyPressed " << key << endl;
	}

	instanceKeyMap[key] = true;
}

void LaneViewer::keyReleased(int key) {
	double nowMS = player->getPositionMS() - wavOffset; // 현재 ms 위치

	instanceKeyMap[key] = false;

	keyMap[key][nowMS] = false;
	
	// cout << nowMS << "ms::keyReleased " << key << endl;
}

void LaneViewer::setMusicPlayer(MusicPlayer* _musicPlayer) {
	player = _musicPlayer;
}

void LaneViewer::setDataViewer(DataViewer * _dataViewer) {
	dataViewer = _dataViewer;
}

void LaneViewer::play() {

}

void LaneViewer::GenerateNote() {
	// 메타데이터 얻어옴
	metas = parser->getMetaData();

	// 데이터뷰어에 메타데이터 연결
	dataViewer->setMetaData(metas);

	wavOffset = metas.WAVEOFFSET * 1000;
	cout << "wavOffset: " << wavOffset << endl;

	// 하이스피드 설정
	laneData->SetHiSpeed(hiSpeed);
	laneData->GenerateNote();

	// 노트맵 복사
	sortedNoteMap = laneData->GetSortedNoteMap();
}

// 노래의 현재 시각과 현재 읽어들이는 Marker로 레인의 포지션 구하는 함수
double LaneViewer::GetCurrentScrollPosition(Mark* _marker, double _nowSyncTime, double _hiSpeed) {
	Mark* m = _marker;

	if (_nowSyncTime <= 0)
		return 0;

	// 마디 한개의 총 시간
	double barTime = 60000 / m->bpm * m->barBeat;
	double nowPosition = ((_nowSyncTime - m->syncTime) / barTime * m->height + m->position) * _hiSpeed;

	return nowPosition;
}

Mark* LaneViewer::GetNowMarker() {
	return laneData->GetNowMarker(player->getPositionMS() - wavOffset);
}

// 노래 재생 시각 기준 +-500ms의 노트를 모두 읽어와야 함
// LaneData의 noteMap을 ms단위의 시간을 가지고 정렬시키면 쉽게 판정을 처리할 수 있음

/*
void LaneViewer::genrateNote() {
	cout << "noteGen" << endl;

	// 파서로부터 노트 정보와 BPM, 속도 정보를 받아옴
	notes = parser->getNoteData();
	metas = parser->getMetaData();

	float tempo = 4;	// 박자
	float hiSpeed = 1;	// 속도	
	int tpb = 480;		// 4분음표 한개 길이
	float bpm = 120;

	tpb = stoi(metas.REQUEST["ticks_per_beat"]);

	int nYPos = -965;	// 노트 시작위치가 Y: -965
	 
	position[0] = nYPos;

	int prevYPos = -1;

	for (note::iterator i = notes.notes.begin(); i != notes.notes.end();) {
		
		vector<float> nBpm;

		vector<ofNote>* BarVector = new vector<ofNote>();
		noteMap[i->first] = BarVector;

		if (notes.speeds[i->first].size() == 0)
			hiSpeed = hiSpeed;
		else
			hiSpeed = notes.speeds[i->first][0];
		cout << "Changed hiSpeed: " << hiSpeed << endl;

		long nodeHeight = ((bpm * hiSpeed * (tempo / 2)));
		//cout << "Now nodeHeight: " << nodeHeight << endl;
		for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); j++) {
			
			// tempo
			if(j->first == "02"){
				tempo = stof(j->second);

				nodeHeight = ((bpm * hiSpeed * (tempo / 2)));

				cout << "Changed Tempo: " << tempo << ", Changed nodeHeight: " << nodeHeight << endl;
				continue;
			}

			// bpm
			if (j->first == "08") {
				nBpm.push_back(notes.bpms[stoi(j->second.substr(0, 2))]);
				//for (int l = 0; l < j->second.length() / 2; l++)
					//nBpm.push_back(notes.bpms[stoi(j->second.substr(l, 2))]);
				
				bpm = notes.bpms[stoi(j->second.substr(0, 2))];
				
				nodeHeight = ((bpm * hiSpeed * (tempo / 2)));

				cout << "Changed BPM: " << bpm << ", Changed nodeHeight: " << nodeHeight << endl;
				continue;
			}
			
			// 이외의 일반노트
			if (j->first.length() == 2) {
				// 현재 노트의 가로포지션
				char x = j->first.substr(1, 1).c_str()[0];
				int xPos = (x >= 97) ? x - 87 : x - 48;

				// float prevPos = 0;
				for (int l = 0; l < j->second.length() / 2; l++) {
				 	string nNoteStr = j->second.substr(l * 2, 2);

					if (nNoteStr == "00") continue;
				 
					int yPos = nYPos + ((nodeHeight / (j->second.length() / 2)) * l);

				 	// int yPos = nYPos + ((l + 1) * nodeHeight);
				 
				 	j->second.substr(l * 2, 2);

					//cout << "xPos: " << xPos << ", yPos: " << yPos << endl;

					ofNote _note;
					
					_note.setNoteImage(normalNote);

						

					_note.setPosition(xPos);
					_note.setYPosition(-yPos);
					_note.setNoteLength(4);
					noteMap[i->first]->push_back(_note);
				}


				// for (map<int, float>::iterator k = (notes.speeds[i->first]).begin(); k != (notes.speeds[i->first]).end(); k++) {
				// 	(k->first / tpb);
				// }

				// ofNote _note;
				// _note.setNoteImage(normalNote);
				// _note.setPosition(XPos);

				continue;
			}

			// 어차피 3자리

			

			
			
			
			// 여기서부터 쪼갠 데이터를 그려주면 됨
			// TODO: pos를 자리수로 잘라줘서 롱노트인지 아닌지를 구분해주면 될 듯
			// TODO: 노트를 draw할 때에 배속을 주면 될 듯 (배속을 주나 지나간 노트에는 배속을 무조건 양수로 적용해줄 것)


		}
		//cout << "endYPos: " << nYPos << endl;
		int nMeasure = i->first;
		int nextMesure = nMeasure + 1;
		i++;
		if (i != notes.notes.end())
			nextMesure = i->first;
		else
			break;

		

		//cout << "i->first - prevY: " << nextMesure << " - " << nMeasure << endl;
		nYPos += nodeHeight * (nextMesure - nMeasure);
		position[i->first] = nYPos;
		prevYPos = i->first;


		if(nBpm.size() >= 1)
			bpm = nBpm[(nBpm.size() - 1 < 0)];

	}



	// 파서한테 노트정보 받아옴
	//tapNotes = parser->getTapNote();
	//notes = new vector<ofNote>[tapNotes.size()];
	//
	//long presentPosition = 300;
	//int beatPos = 0;
	//for (int i = 0; i < tapNotes.size(); i++) {
	//	int splitNoteCount = get<2>(tapNotes.at(i)).size();
	//	for (int j = 0; j < splitNoteCount; j++) {
	//		//cout << get<0>(tapNotes.at(i)) << "," << get<1>(tapNotes.at(i)) << "," << get<2>(tapNotes.at(i)).at(j) << endl;
	//
	//		string _noteData = get<2>(tapNotes.at(i)).at(j);
	//
	//		if (_noteData != "00") {
	//			ofNote _note;
	//
	//			int notePos = strtol(get<1>(tapNotes.at(i)).substr(1, 1).c_str(), 0, 16);
	//
	//			if(beatPos != get<0>(tapNotes.at(i)))
	//
	//			cout << get<0>(tapNotes.at(i)) << ", ";
	//			// cout << presentPosition + (500.0 / splitNoteCount * j) << ", " << notePos << ", ";
	//			_note.setNoteImage(normalNote);
	//			_note.setPosition(notePos);
	//			_note.setOriginData(_noteData);
	//			_note.setYPosition(presentPosition - (100.0 / splitNoteCount * j));
	//
	//			cout << ", Y-Position: " << presentPosition - ((100.0 / splitNoteCount) * j) << endl;
	//			notes[i].push_back(_note);
	//		}
	//	}
	//
	//}
}
*/
