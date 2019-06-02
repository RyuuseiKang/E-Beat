//
//  LaneViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#include "LaneViewer.hpp"

LaneViewer::LaneViewer() {
	// 파서 여기잇음
	parser = new Parser();

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
	genrateNote();
}

LaneViewer::~LaneViewer() {
	delete parser;
}

void LaneViewer::update() {
	// n++;
	//
	// if (n < 0)
	// 	n = 0;
	//
	// k = n % 24 / 3;
	// texturePtr[k].resize(w, h / 2);
	//
	// airNotePath.clear();
	// airNotePath.lineTo(x - tilt, y, 0);
	// airNotePath.lineTo(x + w, y, 0);
	// airNotePath.lineTo(x + w , y + (h / 2), 0);
	// airNotePath.lineTo(x - tilt, y + (h / 2), 0);
	//
	// fbo.allocate(w, h, GL_RGBA); //or GL_RED if you are using the programmable renderer
	// fbo.begin();
	// ofClear(255, 255, 255, 0);
	// airNotePath.draw();
	// fbo.end();
	// texturePtr[k].getTexture().setAlphaMask(fbo.getTexture());

	// airNote.clear();
	// airNote.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	// airNote.addVertex(ofPoint(x, y, 0));
	// airNote.addTexCoord(ofVec2f(0, 0));
	// airNote.addVertex(ofPoint(x + w, y, 0));
	// airNote.addTexCoord(ofVec2f(w, 0));
	// airNote.addVertex(ofPoint(x + w - tilt, y + (h / 2), 0));
	// airNote.addTexCoord(ofVec2f(w, h / 2));
	// airNote.addVertex(ofPoint(x - tilt, y + (h / 2), 0));
	// airNote.addTexCoord(ofVec2f(0, h / 2));
	// airNote.addVertex(ofPoint(x, y, 0));
	// airNote.addTexCoord(ofVec2f(0, 0));
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

	for (note::iterator i = notes.notes.begin(); i != notes.notes.end(); i++) 
		for (int j = 0; j < noteMap[i->first]->size(); j++) {
			noteMap[i->first]->at(j).draw();
		}
	

	/*
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

void LaneViewer::genrateNote() {

	// 파서로부터 노트 정보와 BPM, 속도 정보를 받아옴
	notes = parser->getNoteData();
	metas = parser->getMetaData();

	int tempo = 4;		// 박자
	float hiSpeed = 1;	// 속도	
	int tpb = 480;		// 4분음표 한개 길이
	float bpm = 120;

	tpb = stoi(metas.REQUEST["ticks_per_beat"]);

	int nYPos = -965;	// 노트 시작위치가 Y: -965
		
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

		int nodeHeight = ((bpm * hiSpeed * (tempo / 2)));
		cout << "Now nodeHeight: " << nodeHeight << endl;
		for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); j++) {
			
			// tempo
			if(j->first == "02"){
				tempo = stoi(j->second);

				cout << "Changed Tempo: " << tempo << endl;
				continue;
			}

			// bpm
			if (j->first == "08") {
				nBpm.push_back(notes.bpms[stoi(j->second.substr(0, 2))]);
				//for (int l = 0; l < j->second.length() / 2; l++)
					//nBpm.push_back(notes.bpms[stoi(j->second.substr(l, 2))]);
				
				bpm = notes.bpms[stoi(j->second.substr(0, 2))];
				
				nodeHeight = ((bpm * hiSpeed * (tempo / 2)));
				cout << "Changed nodeHeight: " << nodeHeight << endl;
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
		cout << "endYPos: " << nYPos << endl;
		int nMeasure = i->first;
		int nextMesure = nMeasure + 1;
		i++;
		if (i != notes.notes.end())
			nextMesure = i->first;
		else
			break;


		cout << "i->first - prevY: " << nextMesure << " - " << nMeasure << endl;
		nYPos += nodeHeight * (nextMesure - nMeasure);
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
