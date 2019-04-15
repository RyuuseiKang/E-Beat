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
	backLane.loadImage("Scene/Ingame/BackLane.png");
	backLane.resize(1920, 1080);
}

Ingame::~Ingame() {

}

void Ingame::update(bool keys[256]) {

}

void Ingame::draw() {
    // BGA 등
	backLane.draw(0, 0);
    


    // 화면 상단처리
	ofRectangle levelBackground((1920 / 2) - (1820 / 2), 0, 1820, 160);

	// 난이도별 상단 색상처리 안햇음
	ofMesh levelBackgroundMesh;
	levelBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	levelBackgroundMesh.addVertex(ofPoint((1920 / 2) - (1820 / 2), 0));
	levelBackgroundMesh.addColor(ofColor(98, 6, 168, 255));
	levelBackgroundMesh.addVertex(ofPoint((1920 / 2) + (1820 / 2), 0));
	levelBackgroundMesh.addColor(ofColor(98, 6, 168, 255));
	levelBackgroundMesh.addVertex(ofPoint(1920 / 2 - (1820 / 2), 160));
	levelBackgroundMesh.addColor(ofColor(136, 3, 232, 255));
	levelBackgroundMesh.addVertex(ofPoint(1920 / 2 + (1820 / 2), 160));
	levelBackgroundMesh.addColor(ofColor(136, 3, 232, 255));
	levelBackgroundMesh.draw();

	// 판정 후면 검은색
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle((1920 / 2) - (760 / 2), 0, 760, 35);

	// 옵션 후면 검은색


	// 판정 처리



	ofDrawBitmapStringHighlight("Ingame Scene", 20, 20);

	ofSetColor(255, 255, 255, 255);
}

void Ingame::keyPressed(int key) {

}
