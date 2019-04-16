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

	dataViewer = new DataViewer(file);
}

Ingame::~Ingame() {

}

void Ingame::update(bool keys[256]) {
	dataViewer->update();
}

void Ingame::draw() {
    // BGA 등
	backLane.draw(0, 0);
    
	// 노트 작성


	// 상단 데이터뷰어 작성
	dataViewer->draw();

	ofDrawBitmapStringHighlight("Ingame Scene", 20, 20);

	ofSetColor(255, 255, 255, 255);
}

void Ingame::keyPressed(int key) {

}
