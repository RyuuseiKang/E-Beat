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
	readDesigner();

    LevelBackgroundRect.load("Scene/Ingame/DataViewer/LevelBackground.png");
    
    string judgeFontPath = "Fonts/GOTHICB0.ttf";
    int judgeFontSize = 22;
    judgeTextBlock[0].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[1].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[2].init(judgeFontPath, judgeFontSize);
    judgeTextBlock[3].init(judgeFontPath, judgeFontSize);
    
	// 마스터 난이도 색상
    levelColor[0] = ofColor(0, 0, 64, 255);
    levelColor[1] = ofColor(94, 58, 148, 255);
}

DataViewer::~DataViewer() {
    
}

void DataViewer::update() {
    
}

void DataViewer::draw() {
    
    // 화면 상단처리
    ofRectangle levelBackground((1920 / 2) - (1825 / 2), 0, 1825, 160);
    
    // 난이도별 상단 색상처리 안햇음
    // 색상은 그라데이션으로 주고 있음, 리팩토링 끝
    ofMesh levelColorBackgroundMesh;
    levelColorBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) - (1825 / 2), 0));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint((1920 / 2) + (1825 / 2), 0));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 - (1825 / 2), 160));
    levelColorBackgroundMesh.addColor(levelColor[1]);
    levelColorBackgroundMesh.addVertex(ofPoint(1920 / 2 + (1825 / 2), 160));
    levelColorBackgroundMesh.addColor(levelColor[1]);
    levelColorBackgroundMesh.draw();
    
    // 레벨표시
    LevelBackgroundRect.draw(LevelBackgroundRectVector.at(0), LevelBackgroundRectVector.at(1), LevelBackgroundRectVector.at(2), LevelBackgroundRectVector.at(3));
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
    

	// 115, 115 앨범 아트 사이즈
	// 1376, 53 앨범 아트 포지션

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

void DataViewer::readDesigner() {
	// 디자이너 파일 내용 읽어오기
	ofBuffer designerBuffer = ofBufferFromFile("Scene/Ingame/DataViewer/Designer.des");

	designerVector.clear();
	int countLines = 0;
	for (auto line : designerBuffer.getLines()) {
		designerVector.push_back(line);
		countLines++;
	}

	setDesign();
}

void DataViewer::setDesign() {
	LevelBackgroundRectVector = changeVectorType(dataParse("LevelBackgroundRect"));
}

vector<string> DataViewer::dataParse(string itemName) {
	vector<string> data;

	int pos = 0;
	bool isEnabled = false;

	for (auto line : designerVector) {
		if (line.find("#" + itemName, 0) != string::npos)
			isEnabled = true;

		if(!isEnabled)
			pos++;
	}

	if (!isEnabled)
		return data;

	stringstream str();

	data = split(designerVector.at(pos), ' ');
		
	// for (int i = 0; i < data.size(); i++) {
	// 	cout << data[i] << endl;
	// 
	// }

	return data;
}

vector<string> DataViewer::split(string str, char delimiter) {
	vector<string> internal;
		stringstream ss(str);
		string temp;

		while (getline(ss, temp, delimiter)) {
			internal.push_back(temp);
		}

	return internal;
}

vector<int> DataViewer::changeVectorType(vector<string> str) {
	vector<int> data;
	for (int i = 1; i < str.size(); i++) {
		data.push_back(stoi(str[i]));
	}
	return data;
}
