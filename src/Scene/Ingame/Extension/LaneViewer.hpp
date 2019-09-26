//
//  LaneViewer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 01/05/2019.
//

#ifndef __LANE_VIEWER_HPP_
#define __LANE_VIEWER_HPP_

#include <iostream>
#include "../ofMain.h"

#include "ofxGui.h"
#include "../Extension/FileSystem.hpp"
#include "Extension/Parser.hpp"
#include "Extension/LaneData.hpp"
#include "LaneKeyBeam.hpp"
#include "MusicPlayer.hpp"
#include "ofNote.hpp"
#include "JudgeView.hpp"

class LaneViewer {
public:
	LaneViewer();
	LaneViewer(FileSystem* _file);
	~LaneViewer();

	void update(bool keys[256]);
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void play();

	void setMusicPlayer(MusicPlayer* _musicPlayer);

private:
	void GenerateNote();

	double GetCurrentScrollPosition(Marker* _marker, double _nowSyncTime, double _hiSpeed);

	Marker* GetNowMarker();
	
	ofxPanel gui;

	ofFile *musicFile;

	Parser *parser;
	LaneData *laneData;
	//tapNote tapNotes;
	LaneKeyBeam *laneKeyBeam;

	ofxFloatSlider rX;
	ofxFloatSlider rY;
	ofxFloatSlider rZ;
	ofxFloatSlider tX;
	ofxFloatSlider tY;
	ofxFloatSlider tZ;
	ofxFloatSlider x;
	ofxFloatSlider y;
	ofxFloatSlider w;
	ofxFloatSlider h;
	ofxFloatSlider tilt;

	const double yPosition = 965;
	double laneY = 0;
	double wavOffset = 0;

	ofMesh airNote;
	ofPath airNotePath;
	ofFbo fbo;
	ofImage texturePtr[8];

	int n;
	int k;

	ofNote *note;

	note_data notes;
	meta_data metas;

	// map<int, vector<ofNote>* > noteMap;
	map<int, long> position;

	MusicPlayer* player;

	string filePath;

	double hiSpeed = 0.3; // 사용자 설정 속도 받아서 입력 필요
	// vector<ofNote*> noteMap; // 노트맵
	map<string, map<long, ofNote*>> sortedNoteMap;

	// 키 프레스 맵
	map<char, map<long, bool>> keyMap;
	bool instanceKeyMap[256];

	JudgeView judgeView;
};

#endif // __LANE_VIEWER_HPP_
