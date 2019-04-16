#include "DataViewer.hpp"

DataViewer::DataViewer() {

}

DataViewer::DataViewer(FileSystem * _file) {
	LevelBackgroundRect.load("Scene/Ingame/DataViewer/LevelBackground.png");
}

DataViewer::~DataViewer() {

}

void DataViewer::update() {

}

void DataViewer::draw() {

	// 화면 상단처리
	ofRectangle levelBackground((1920 / 2) - (1820 / 2), 0, 1820, 160);

	// 난이도별 상단 색상처리 안햇음
	ofMesh levelColorBackgroundMesh;
	levelColorBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) - (1820 / 2), 0));
	levelColorBackgroundMesh.addColor(ofColor(98, 6, 168, 255));
	levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) + (1820 / 2), 0));
	levelColorBackgroundMesh.addColor(ofColor(98, 6, 168, 255));
	levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 - (1820 / 2), 160));
	levelColorBackgroundMesh.addColor(ofColor(136, 3, 232, 255));
	levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 + (1820 / 2), 160));
	levelColorBackgroundMesh.addColor(ofColor(136, 3, 232, 255));
	levelColorBackgroundMesh.draw();

	// 레벨표시
	LevelBackgroundRect.draw(1752 - 5, 41 - 5, 105, 77);

	// 판정 후면 검은색
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle((1920 / 2) - (760 / 2), 0, 760, 35);

	// 옵션 후면 검은색
	ofDrawRectangle(1365, 0, 487, 35);

	// 판정 처리

}

void DataViewer::setScore(double _score) {
	score = _score;
}

void DataViewer::upCombo() {
	combo++;
}

void DataViewer::breakCombo() {
	combo = 0;
}
