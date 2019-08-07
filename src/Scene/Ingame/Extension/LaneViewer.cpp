//
//  LaneViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#include "LaneViewer.hpp"

LaneViewer::LaneViewer() {

}

LaneViewer::LaneViewer(FileSystem* _file) {

	// 파일 주소 취득 및 노래 대기
	filePath = _file->getNowMusicPath();
	
	// 레인 데이터 생성
	laneData = new LaneData();

	// 파서 생성
	parser = new Parser(filePath + _file->getNowMusicDifficulty() + ".sus", laneData);

	for (int i = 0; i < 3; i++)
		normalNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Normal_0" + to_string(i + 1) + ".png");

	for (int i = 0; i < 3; i++)
		bonusNote[i].loadImage("Scene/Ingame/LaneViewer/Note/Bonus_0" + to_string(i + 1) + ".png");

	gui.setup();
	gui.add(rX.setup("Rotate X", 56.6, -100, 100));
	gui.add(rY.setup("Rotate Y", 0, -100, 100));
	gui.add(rZ.setup("Rotate Z", 165, -360, 360));
	gui.add(tX.setup("Translate X", 846, 500, 1200));
	gui.add(tY.setup("Translate Y", 0, 0, 8400));
	gui.add(tZ.setup("Translate Z", -110, -300, 200));
	gui.add(x.setup("x", 0, -3000, 3000));
	gui.add(y.setup("y", 0, -3000, 3000));
	gui.add(w.setup("width", 114, -500, 500));
	gui.add(h.setup("height", 150, -500, 500));
	gui.add(tilt.setup("tilt", 0, -100, 100));

	for (int i = 0; i < 8; i++)
		texturePtr[i].loadImage("Scene/Ingame/LaneViewer/airNote" + to_string(i) + ".png");

	// 여기서부터 노트 생성
	GenerateNote();


}

LaneViewer::~LaneViewer() {
	delete parser;
	delete laneData;
}

void LaneViewer::update() {
	// 여기서 레인 갱신
}

int slider = 0;
void LaneViewer::draw() {
	ofPushMatrix();
	ofRotateX(rX);
	ofTranslate(tX, tY, tZ);

	slider += 2;

	ofSetColor(255, 255, 255, 255);

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < notes[i].size(); j++) {
	//		notes[i].at(j).draw();
	//	}
	//}

	// 노트들 draw


	/*
	for (note::iterator i = notes.notes.begin(); i != notes.notes.end(); i++) 
		for (int j = 0; j < noteMap[i->first]->size(); j++) {
			noteMap[i->first]->at(j).draw();
		}
	

		_ofNote->setPosition(0);
		_ofNote->setNoteLength(4);
		_ofNote->draw(x, y);

		_ofNote->setPosition(4);
		_ofNote->setNoteLength(4);
		_ofNote->draw(x, y - 50);

		_ofNote->setPosition(8);
		_ofNote->setNoteLength(4);
		_ofNote->draw(x, y - 120);

		_ofNote->setPosition(12);
		_ofNote->setNoteLength(4);
		_ofNote->draw(x, y - 90);

		_ofNote->setPosition(8);
		_ofNote->setNoteLength(4);
		_ofNote->draw(x, y - 90);
		*/

	//ofDrawRectangle(x, y, w, -700);

	ofRotateX(rX - (rX * 2));
	ofRotateY(rY);
	ofRotateX(rZ);

	//texturePtr[k].draw(0, 0);
	ofPopMatrix();

	gui.draw();
}

void LaneViewer::setMusicPlayer(MusicPlayer* _musicPlayer) {
	player = _musicPlayer;
}

void LaneViewer::play() {

}

void LaneViewer::GenerateNote() {
	// 메타데이터 얻어옴
	metas = parser->getMetaData();

	double hiSpeed = 1; // 사용자 설정 속도 받아서 입력 필요
	// 하이스피드 설정
	laneData->SetHiSpeed(hiSpeed);

}

// 노래	의 현재 시각과 현재 읽어들이는 Marker로 레인의 포지션 구하는 함수
double LaneViewer::GetCurrentScrollPosition(Marker _marker, double _nowSyncTime, double _hiSpeed) {
	Marker m = _marker;

	// 마디 한개의 총 시간
	double barTime = 60000 / m.bpm * m.barBeat;
	double nowPosition = ((_nowSyncTime - m.syncTime) / barTime * m.height + m.position) * _hiSpeed;

	return nowPosition;
}

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