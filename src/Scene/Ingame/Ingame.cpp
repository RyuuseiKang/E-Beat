//
//  Ingame.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/04/2019.
//

#include "Ingame.hpp"

Ingame::Ingame() {

}

Ingame::Ingame(FileSystem* _file) {
	file = _file;

	backLane.loadImage("Scene/Ingame/BackLane.png");
	backLane.resize(1920, 1080);
}

Ingame::~Ingame() {

}

void Ingame::update(bool keys[256]) {

	laneViewer->update(keys);
	dataViewer->update();

	if (!musicPlayer.getIsPlaying()) {
		// 여기서 노래 종료
		isIngameEnd = true;
	}
}

void Ingame::draw() {
    // BGA 등
	backLane.draw(0, 0);
    
	// 노트 작성
	laneViewer->draw();

	// 상단 데이터뷰어 작성
	dataViewer->draw();

	ofDrawBitmapStringHighlight("Ingame Scene", 20, 20);

	ofSetColor(255, 255, 255, 255);
}

void Ingame::keyPressed(int key) {
	laneViewer->keyPressed(key);

	if (key == 'r')
		dataViewer->readDesigner();

	if (key == '1') {
		dataViewer->setDifficult(1);
	}
			
	if (key == '2') {
		dataViewer->setDifficult(2);
	}

	if (key == '3') {
		dataViewer->setDifficult(3);
	}
	
	if (key == '4') {
		dataViewer->setDifficult(4);
	}

	if (key == 'e') {
		musicPlayer.setPositionMS(0);
	}
	
}

void Ingame::keyReleased(int key) {
	laneViewer->keyReleased(key);
}

void Ingame::readyMusic() {

	// Release때에는 제거해줄 것
	// if (isAliveViewer) {
	// 	delete dataViewer;
	// 	delete laneViewer;
	// }

	dataViewer = new DataViewer(file);
	laneViewer = new LaneViewer(file, dataViewer);

	musicPlayer.load(file->getNowMusicData());

	dataViewer->setDifficult(stoi(file->getNowMusicDifficulty()) + 1);
	
	laneViewer->setMusicPlayer(&musicPlayer);
	
	musicPlayer.play();
	cout << "Play" << endl;

	isAliveViewer = true;
}

void Ingame::readyResult() {
	delete laneViewer;
}

bool Ingame::isReady() {
	return isIngameEnd;
}

DataViewer * Ingame::getDataViewer() {
	return dataViewer;
}
