//
//  DataViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 18/04/2019.
//

#include "DataViewer.hpp"

DataViewer::DataViewer() {
    
}

DataViewer::DataViewer(FileSystem * _file) {
    LevelBackgroundRect.load("Scene/Ingame/DataViewer/LevelBackground.png");
    
    string judgeFontPath = "Fonts/GOTHICB0.ttf";
    int judgeFontSize = 22;
    judgeTextBlock[0].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[1].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[2].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[3].init(judgeFontPath, judgeFontSize);
    
    levelColor[0] = ofColor(98, 6, 168, 255);
    levelColor[1] = ofColor(136, 3, 232, 255);
}

DataViewer::~DataViewer() {
    
}

void DataViewer::update() {
    
}

void DataViewer::draw() {
    
    // 화면 상단처리
    ofRectangle levelBackground((1920 / 2) - (1820 / 2), 0, 1820, 160);
    
    // 난이도별 상단 색상처리 안햇음
    // 색상은 그라데이션으로 주고 있음, 리팩토링 끝
    ofMesh levelColorBackgroundMesh;
    levelColorBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) - (1820 / 2), 0));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) + (1820 / 2), 0));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 - (1820 / 2), 160));
    levelColorBackgroundMesh.addColor(levelColor[1]);
    levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 + (1820 / 2), 160));
    levelColorBackgroundMesh.addColor(levelColor[1]);
    levelColorBackgroundMesh.draw();
    
    // 레벨표시
    LevelBackgroundRect.draw(1752 - 5, 41 - 5, 105, 77);
    // 여기에 텍스트블럭 추가 요망
    
    // 판정 후면 검은색
    ofSetColor(0, 0, 0, 255);
    ofDrawRectangle((1920 / 2) - (760 / 2), 0, 760, 35);
    
    // 옵션 후면 검은색
    ofDrawRectangle(1365, 0, 487, 35);
    
    // 판정 처리
    // TODO :: 임의로 위치값 (0, 0)으로 지정했음, 나중에 수정 요망
    judgeTextBlock[0].draw(0, 0);
    judgeTextBlock[1].draw(0, 0);
    judgeTextBlock[2].draw(0, 0);
    judgeTextBlock[3].draw(0, 0);
    
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
