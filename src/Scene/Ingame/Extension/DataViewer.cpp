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
	albumArt.loadImage("MusicData/Yes or Yes/album.jpg");
}

DataViewer::~DataViewer() {
    
}

void DataViewer::update() {
    
}

void DataViewer::draw() {
	// 화면 상단처리
    // 난이도별 상단 색상처리 안햇음
    // 색상은 그라데이션으로 주고 있음, 리팩토링 끝
    levelColorBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0], levelColorBackgroundMeshVector[1]));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0] + levelColorBackgroundMeshVector[2], levelColorBackgroundMeshVector[1]));
    levelColorBackgroundMesh.addColor(levelColor[0]);
    levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0], levelColorBackgroundMeshVector[3]));
    levelColorBackgroundMesh.addColor(levelColor[difficult]);
    levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0] + levelColorBackgroundMeshVector[2], levelColorBackgroundMeshVector[3]));
    levelColorBackgroundMesh.addColor(levelColor[difficult]);
    levelColorBackgroundMesh.draw();
    
	// 옵션들 상자표시
	DrawBoxRect(musicProfileBoxBorderVector[0], musicProfileBoxBorderVector[1], musicProfileBoxBorderVector[2], musicProfileBoxBorderVector[3]);
	ofSetColor(musicProfileBoxVector[4], musicProfileBoxVector[5], musicProfileBoxVector[6], musicProfileBoxVector[7]);
	ofDrawRectangle(musicProfileBoxVector[0], musicProfileBoxVector[1], musicProfileBoxVector[2], musicProfileBoxVector[3]);
	DrawBoxRect(musicProfileHalfBoxVector[0], musicProfileHalfBoxVector[1], musicProfileHalfBoxVector[2], musicProfileHalfBoxVector[3]);
	ofSetColor(levelColor[difficult]);
	ofDrawRectangle(musicProfileHalfInBoxVector[0], musicProfileHalfInBoxVector[1], musicProfileHalfInBoxVector[2], musicProfileHalfInBoxVector[3]);

	DrawBoxRect(judgeDetailBoxBorderVector[0], judgeDetailBoxBorderVector[1], judgeDetailBoxBorderVector[2], judgeDetailBoxBorderVector[3]);
	ofSetColor(judgeDetailBoxVector[4], judgeDetailBoxVector[5], judgeDetailBoxVector[6], judgeDetailBoxVector[7]);
	ofDrawRectangle(judgeDetailBoxVector[0], judgeDetailBoxVector[1], judgeDetailBoxVector[2], judgeDetailBoxVector[3]);
	DrawBoxRect(judgeDetailHalfBoxVector[0], judgeDetailHalfBoxVector[1], judgeDetailHalfBoxVector[2], judgeDetailHalfBoxVector[3]);
	ofSetColor(levelColor[difficult]);
	ofDrawRectangle(judgeDetailHalfInBoxVector[0], judgeDetailHalfInBoxVector[1], judgeDetailHalfInBoxVector[2], judgeDetailHalfInBoxVector[3]);
   
	ofSetColor(255, 255, 255, 255);

	// 앨범아트 관련
	albumArt.draw(albumArtVector[0], albumArtVector[1], albumArtVector[2], albumArtVector[2]);
	DrawBoxRect(albumArtBoxVector[0], albumArtBoxVector[1], albumArtBoxVector[2], albumArtBoxVector[2]);

	// 노래 정보 스플리터
	ofSetColor(levelColor[difficult]);
	ofDrawRectangle(musicProfileSpliterVector[0], musicProfileSpliterVector[1], musicProfileSpliterVector[2], musicProfileSpliterVector[3]);

	// 레벨표시
	ofSetColor(255, 255, 255, 255);
	LevelBackgroundRect.draw(LevelBackgroundRectVector[0], LevelBackgroundRectVector[1], LevelBackgroundRectVector[2], LevelBackgroundRectVector[3]);
	// 여기에 레벨 텍스트


    // 판정 후면 검은색
    ofSetColor(0, 0, 0, 255);
    ofDrawRectangle(580, 0, 762, 35);
    
    // 옵션 후면 검은색
    ofDrawRectangle(1367, 0, 487, 35);
    
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

void DataViewer::setDesign() {
	LevelBackgroundRectVector = changeVectorIntType(dataParse("LevelBackgroundRect"));
	
	levelColorBackgroundMeshVector = changeVectorDoubleType(dataParse("levelColorBackgroundMesh"));

	musicProfileSpliterVector = changeVectorIntType(dataParse("musicProfileSpliter"));
	musicProfileBoxBorderVector = changeVectorIntType(dataParse("musicProfileBoxBorder"));
	musicProfileHalfBoxVector = changeVectorIntType(dataParse("musicProfileHalfBox"));
	musicProfileHalfInBoxVector = changeVectorIntType(dataParse("musicProfileHalfInBox"));
	musicProfileBoxVector = changeVectorIntType(dataParse("musicProfileBox"));

	judgeDetailBoxBorderVector = changeVectorIntType(dataParse("judgeDetailBoxBorder"));
	judgeDetailHalfBoxVector = changeVectorIntType(dataParse("judgeDetailHalfBox"));
	judgeDetailHalfInBoxVector = changeVectorIntType(dataParse("judgeDetailHalfInBox"));
	judgeDetailBoxVector = changeVectorIntType(dataParse("judgeDetailBox"));

	albumArtVector = changeVectorIntType(dataParse("albumArt"));
	albumArtBoxVector = changeVectorIntType(dataParse("albumArtBox"));

	// 난이도 색상
	levelColorVector[0] = changeVectorIntType(dataParse("levelColor0"));
	levelColorVector[1] = changeVectorIntType(dataParse("levelColor1"));
	levelColorVector[2] = changeVectorIntType(dataParse("levelColor2"));
	levelColorVector[3] = changeVectorIntType(dataParse("levelColor3"));
	levelColorVector[4] = changeVectorIntType(dataParse("levelColor4"));

	switch (difficult) {
		case 1:
			levelColor[0] = ofColor(levelColorVector[0][1], levelColorVector[0][0], levelColorVector[0][1], levelColorVector[0][2]);
			break;
		case 2:
			levelColor[0] = ofColor(levelColorVector[0][0], levelColorVector[0][0], levelColorVector[0][1], levelColorVector[0][2]);
			break;		
		case 3:
			levelColor[0] = ofColor(levelColorVector[0][0], levelColorVector[0][1], levelColorVector[0][1], levelColorVector[0][2]);
			break;
		case 4:
			levelColor[0] = ofColor(levelColorVector[0][1], levelColorVector[0][1], levelColorVector[0][0], levelColorVector[0][2]);
			break;
	}
	
	levelColor[1] = ofColor(levelColorVector[1][0], levelColorVector[1][1], levelColorVector[1][2], levelColorVector[1][3]);
	levelColor[2] = ofColor(levelColorVector[2][0], levelColorVector[2][1], levelColorVector[2][2], levelColorVector[2][3]);
	levelColor[3] = ofColor(levelColorVector[3][0], levelColorVector[3][1], levelColorVector[3][2], levelColorVector[3][3]);
	levelColor[4] = ofColor(levelColorVector[4][0], levelColorVector[4][1], levelColorVector[4][2], levelColorVector[4][3]);
}

void DataViewer::DrawBoxRect(float x, float y, float w, float h) {
	ofImage boxLeft, boxRight, boxTop, boxBottom, boxLeftTop, boxRightTop, boxLeftBottom, boxRightBottom;
	
	boxLeft.loadImage("Scene/Ingame/DataViewer/boxLeft.png");
	boxRight.loadImage("Scene/Ingame/DataViewer/boxRight.png");
	boxTop.loadImage("Scene/Ingame/DataViewer/boxTop.png");
	boxBottom.loadImage("Scene/Ingame/DataViewer/boxBottom.png");
	boxLeftTop.loadImage("Scene/Ingame/DataViewer/boxLeftTop.png");
	boxRightTop.loadImage("Scene/Ingame/DataViewer/boxRightTop.png");
	boxLeftBottom.loadImage("Scene/Ingame/DataViewer/boxLeftBottom.png");
	boxRightBottom.loadImage("Scene/Ingame/DataViewer/boxRightBottom.png");

	ofSetColor(255, 255, 255, 255);

	boxLeft.draw(x - 3, y + 3, 5, h - 5);
	boxRight.draw(x + w - 2, y + 3, 5, h - 5);
	boxTop.draw(x + 2, y - 2, w - 2 - 2, 5);
	boxBottom.draw(x + 2, y + h - 2, w - 2 - 2, 5);
	boxLeftTop.draw(x - 3, y - 2, 5, 5);
	boxRightTop.draw(x + w - 2, y - 2, 5, 5);
	boxLeftBottom.draw(x - 3, y + h - 2, 5, 5);
	boxRightBottom.draw(x + w - 2, y + h - 2, 5, 5);

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

void DataViewer::setDifficult(int _difficult) {
	difficult = _difficult;
}

vector<string> DataViewer::dataParse(string itemName) {
	vector<string> data;

	int pos = 0;
	bool isEnabled = false;

	for (auto line : designerVector) {
		if (line.find("#" + itemName + " ", 0) != string::npos)
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

vector<int> DataViewer::changeVectorIntType(vector<string> str) {
	vector<int> data;
	for (int i = 1; i < str.size(); i++) {
		data.push_back(stoi(str[i]));
	}
	return data;
}

vector<double> DataViewer::changeVectorDoubleType(vector<string> str) {
	vector<double> data;
	for (int i = 1; i < str.size(); i++) {
		data.push_back(stod(str[i]));
	}
	return data;
}
