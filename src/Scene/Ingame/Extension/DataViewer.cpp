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

	// ȭ�� ���ó��
	ofRectangle levelBackground((1920 / 2) - (1820 / 2), 0, 1820, 160);

	// ���̵��� ��� ����ó�� ������
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

	// ����ǥ��
	LevelBackgroundRect.draw(1752 - 5, 41 - 5, 105, 77);

	// ���� �ĸ� ������
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle((1920 / 2) - (760 / 2), 0, 760, 35);

	// �ɼ� �ĸ� ������
	ofDrawRectangle(1365, 0, 487, 35);

	// ���� ó��

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
