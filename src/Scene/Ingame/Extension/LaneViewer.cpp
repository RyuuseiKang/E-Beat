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

	gui.setup();
	gui.add(rX.setup("Rotate X", 56.6, -100, 100));
	gui.add(rY.setup("Rotate Y", 0, -100, 100));
	gui.add(rZ.setup("Rotate Z", 165, -360, 360));
	gui.add(tX.setup("Translate X", 846, 500, 1200));
	gui.add(tY.setup("Translate Y", 634.125, -500, 2400));
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

	int tempo;			// 박자
	float hiSpeed = 1;	// 속도	
	int tpb = 480;		// 4분음표 한개 길이
	float bpm;

	tpb = stoi(metas.REQUEST["ticks_per_beat"]);

	int nPos = 0;

	cout << notes.notes.size() << endl;

	noteObj = new vector<ofNote>;

	for (note::iterator i = notes.notes.begin(); i != notes.notes.end(); i++) {
		
		vector<float> nBpm;
		for (map<string, string>::iterator j = i->second.begin(); j != i->second.end(); j++) {
			
			cout << i->first << ", " << j->first << ", " << j->second << endl;

			// tempo
			if(j->first == "02"){
				tempo = stoi(j->second);
				continue;
			}

			// bpm
			if (j->first == "08") {
				for (int l = 0; j->second.length() / 2; l++)
					nBpm.push_back(notes.bpms[stoi(j->second.substr(l, 2))]);
				continue;
			}
			
			// 이외의 일반노트
			if (j->first.length() == 2) {
				int XPos = (j->first.substr(1, 1).c_str()[0] >= 97) ? j->first.substr(1, 1).c_str()[0] - 87 : j->first.substr(1, 1).c_str()[0] - 48;

				int nodeHeight = ((tpb * tempo) / j->second.length());
				float prevPos = 0;
				for (int l = 0; l < j->second.length() / 2; l++) {
					string nNoteStr = j->second.substr(l, 2);



					if (nNoteStr == "") continue;

					

					j->second.substr(l, 2);
				}

					

					

				for (map<int, float>::iterator k = (notes.speeds[i->first]).begin(); k != (notes.speeds[i->first]).end(); k++) {
					(k->first / tpb) 
				}

				ofNote _note;
				_note.setNoteImage(normalNote);
				_note.setPosition(XPos);

				continue;
			}

			// 어차피 3자리

			

			// ofNote _note;
			// _note.setNoteImage(normalNote);
			// _note.setPosition(notePos);
			// _note.setYPosition(presentPosition - (100.0 / splitNoteCount * j));
			// noteObj[i].push_back(_note);
			
			
			// 여기서부터 쪼갠 데이터를 그려주면 됨
			// TODO: pos를 자리수로 잘라줘서 롱노트인지 아닌지를 구분해주면 될 듯
			// TODO: 노트를 draw할 때에 배속을 주면 될 듯 (배속을 주나 지나간 노트에는 배속을 무조건 양수로 적용해줄 것)


		}
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
