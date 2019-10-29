//
//  DataViewer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 18/04/2019.
//

#include "DataViewer.hpp"

DataViewer::DataViewer() {

}

DataViewer::DataViewer(FileSystem* _file) {
	readDesigner();

	LevelBackgroundRect.load("Scene/Ingame/DataViewer/LevelBackground.png");
	JudgeBackground.load("Scene/Ingame/DataViewer/JudgeBackground.png");

	scoreLabel.load("Scene/Ingame/DataViewer/ScoreLabel.png");
	comboLabel.load("Scene/Ingame/DataViewer/ComboLabel.png");
	maxComboLabel.load("Scene/Ingame/DataViewer/MaxComboLabel.png");

	

	judgeTextBlock[0].setText(to_string(judge[0]));
	judgeTextBlock[1].setText(to_string(judge[1]));
	judgeTextBlock[2].setText(to_string(judge[2]));
	judgeTextBlock[3].setText(to_string(judge[3]));

	scoreTextBlock.setText(to_string(int(score)));
	comboTextBlock.setText(to_string(combo));
	maxComboTextBlock.setText(to_string(maxCombo));


	cout << _file->getNowMusicData() << endl;

	albumArt.loadImage(_file->getNowMusicPath() + "album.jpg");
	
	LoadBoxRect();
	
}

DataViewer::~DataViewer() {

}

void DataViewer::update() {
	musicNameLabel.update();
	artistNameLabel.update();
	
}

void DataViewer::draw() {
	// 화면 상단처리
	levelColorBackgroundMesh.draw();

	// 옵션들 상자표시
	DrawBoxRect(userProfileBoxBorderVector[0], userProfileBoxBorderVector[1], userProfileBoxBorderVector[2], userProfileBoxBorderVector[3]);
	ofSetColor(userProfileBoxVector[4], userProfileBoxVector[5], userProfileBoxVector[6], userProfileBoxVector[7]);
	ofDrawRectangle(userProfileBoxVector[0], userProfileBoxVector[1], userProfileBoxVector[2], userProfileBoxVector[3]);

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

	// 난이도 표시
	difficultyLabel.setColor(difficultyLabelColorVector[0], difficultyLabelColorVector[1], difficultyLabelColorVector[2], difficultyLabelColorVector[3]);
	difficultyLabel.drawJustified(difficultyLabelVector[0], difficultyLabelVector[1], difficultyLabelVector[3]);
	
	// 레벨표시
 	ofSetColor(255, 255, 255, 255);
 	LevelBackgroundRect.draw(LevelBackgroundRectVector[0], LevelBackgroundRectVector[1], LevelBackgroundRectVector[2], LevelBackgroundRectVector[3]);
	// 여기에 레벨 텍스트
 	levelLabel.setColor(levelLabelColorVector[0], levelLabelColorVector[1], levelLabelColorVector[2], levelLabelColorVector[3]);
 	levelLabel.drawCenter(levelLabelVector[0], levelLabelVector[1]);
	
	// 판정 후면 검은색
 	ofSetColor(0, 0, 0, 255);
 	ofDrawRectangle(580, 0, 762, 35);
 
 	// 옵션 후면 검은색
 	ofDrawRectangle(1367, 0, 487, 35);
	
	// 판정 처리
	ofSetColor(255, 255, 255, 255);
	JudgeBackground.draw(JudgeBackgroundVector[0], JudgeBackgroundVector[1]);
	judgeTextBlock[0].setColor(255, 255, 255, 255);
	judgeTextBlock[0].drawCenter(JudgeTextBlock0Vector[0], JudgeTextBlock0Vector[1]);
	judgeTextBlock[1].setColor(255, 255, 255, 255);
	judgeTextBlock[1].drawCenter(JudgeTextBlock1Vector[0], JudgeTextBlock1Vector[1]);
	judgeTextBlock[2].setColor(255, 255, 255, 255);
	judgeTextBlock[2].drawCenter(JudgeTextBlock2Vector[0], JudgeTextBlock2Vector[1]);
	judgeTextBlock[3].setColor(255, 255, 255, 255);
	judgeTextBlock[3].drawCenter(JudgeTextBlock3Vector[0], JudgeTextBlock3Vector[1]);

	// 점수, 콤보 처리
	ofSetColor(255, 255, 255, 255);
	scoreTextBlock.setColor(255, 255, 255, 255);
	scoreTextBlock.drawRight(scoreTextBlockVector[0], scoreTextBlockVector[1]);
	comboTextBlock.setColor(0, 0, 0, 255);
	comboTextBlock.drawRight(comboTextBlockVector[0], comboTextBlockVector[1]);
	maxComboTextBlock.setColor(0, 0, 0, 255);
	maxComboTextBlock.drawRight(maxComboTextBlockVector[0], maxComboTextBlockVector[1]);

	ofSetColor(255, 255, 255, 255);
	scoreLabel.draw(scoreLabelVector[0], scoreLabelVector[1], scoreLabelVector[2], scoreLabelVector[3]);
	comboLabel.draw(comboLabelVector[0], comboLabelVector[1], comboLabelVector[2], comboLabelVector[3]);
	maxComboLabel.draw(maxComboLabelVector[0], maxComboLabelVector[1], maxComboLabelVector[2], maxComboLabelVector[3]);

	musicNameLabel.draw();
	artistNameLabel.draw();
}

void DataViewer::setScore(double _score) {
	score = _score;
}

double DataViewer::getScore() {
	return score;
}

void DataViewer::upPerfect() {
	judgeTextBlock[0].setText(to_string(++judge[0]));
	score += 1000;

	scoreTextBlock.setText(to_string(int(score)));
}

void DataViewer::upGreat() {
	judgeTextBlock[1].setText(to_string(++judge[1]));
	score += 750;

	scoreTextBlock.setText(to_string(int(score)));
}

void DataViewer::upGood() {
	judgeTextBlock[2].setText(to_string(++judge[2]));
	score += 500;

	scoreTextBlock.setText(to_string(int(score)));
}

void DataViewer::upMiss() {
	judgeTextBlock[3].setText(to_string(++judge[3]));

	breakCombo();
}

void DataViewer::upCombo() {
	combo++;
	if (maxCombo < combo)
		maxCombo = combo;

	comboTextBlock.setText(to_string(combo));
	maxComboTextBlock.setText(to_string(maxCombo));
}

void DataViewer::breakCombo() {
	combo = 0;

	comboTextBlock.setText(to_string(combo));
	maxComboTextBlock.setText(to_string(maxCombo));
}

void DataViewer::setDesign() {
	LevelBackgroundRectVector = changeVectorIntType(dataParse("LevelBackgroundRect"));
	
	userProfileBoxVector = changeVectorIntType(dataParse("userProfileBox"));
	userProfileBoxBorderVector = changeVectorIntType(dataParse("userProfileBoxBorder"));

	musicProfileSpliterVector = changeVectorIntType(dataParse("musicProfileSpliter"));
	musicProfileBoxBorderVector = changeVectorIntType(dataParse("musicProfileBoxBorder"));
	musicProfileHalfBoxVector = changeVectorIntType(dataParse("musicProfileHalfBox"));
	musicProfileHalfInBoxVector = changeVectorIntType(dataParse("musicProfileHalfInBox"));
	musicProfileBoxVector = changeVectorIntType(dataParse("musicProfileBox"));

	judgeDetailBoxBorderVector = changeVectorIntType(dataParse("judgeDetailBoxBorder"));
	judgeDetailHalfBoxVector = changeVectorIntType(dataParse("judgeDetailHalfBox"));
	judgeDetailHalfInBoxVector = changeVectorIntType(dataParse("judgeDetailHalfInBox"));
	judgeDetailBoxVector = changeVectorIntType(dataParse("judgeDetailBox"));
	
	JudgeBackgroundVector = changeVectorIntType(dataParse("judgeBackgroundImage"));
	JudgeTextBlock0Vector = changeVectorIntType(dataParse("judgeTextBlock0"));
	JudgeTextBlock1Vector = changeVectorIntType(dataParse("judgeTextBlock1"));
	JudgeTextBlock2Vector = changeVectorIntType(dataParse("judgeTextBlock2"));
	JudgeTextBlock3Vector = changeVectorIntType(dataParse("judgeTextBlock3"));
	
	judgeTextBlock[0].init("Fonts/ITCAvantGardeStd-Bold.ttf", JudgeTextBlock0Vector[2]);
	judgeTextBlock[1].init("Fonts/ITCAvantGardeStd-Bold.ttf", JudgeTextBlock1Vector[2]);
	judgeTextBlock[2].init("Fonts/ITCAvantGardeStd-Bold.ttf", JudgeTextBlock2Vector[2]);
	judgeTextBlock[3].init("Fonts/ITCAvantGardeStd-Bold.ttf", JudgeTextBlock3Vector[2]);
	judgeTextBlock[0].setTracking(JudgeTextBlock0Vector[3]);
	judgeTextBlock[1].setTracking(JudgeTextBlock1Vector[3]);
	judgeTextBlock[2].setTracking(JudgeTextBlock2Vector[3]);
	judgeTextBlock[3].setTracking(JudgeTextBlock3Vector[3]);
	judgeTextBlock[0].setColor(255, 255, 255, 255);
	judgeTextBlock[1].setColor(255, 255, 255, 255);
	judgeTextBlock[2].setColor(255, 255, 255, 255);
	judgeTextBlock[3].setColor(255, 255, 255, 255);

	scoreTextBlockVector = changeVectorIntType(dataParse("scoreTextBlock"));
	comboTextBlockVector = changeVectorIntType(dataParse("comboTextBlock"));
	maxComboTextBlockVector = changeVectorIntType(dataParse("maxComboTextBlock"));
	scoreTextBlock.init("Fonts/ITCAvantGardeStd-Bold.ttf", scoreTextBlockVector[2]);
	comboTextBlock.init("Fonts/ITCAvantGardeStd-Bold.ttf", comboTextBlockVector[2]);
	maxComboTextBlock.init("Fonts/ITCAvantGardeStd-Bold.ttf", maxComboTextBlockVector[2]);
	scoreTextBlock.setTracking(scoreTextBlockVector[3]);
	comboTextBlock.setTracking(comboTextBlockVector[3]);
	maxComboTextBlock.setTracking(maxComboTextBlockVector[3]);
	scoreTextBlock.setColor(255, 255, 255, 255);
	comboTextBlock.setColor(255, 255, 255, 255);
	maxComboTextBlock.setColor(255, 255, 255, 255);

	scoreLabelVector = changeVectorIntType(dataParse("scoreLabel"));
	comboLabelVector = changeVectorIntType(dataParse("comboLabel"));
	maxComboLabelVector = changeVectorIntType(dataParse("maxComboLabel"));
	
    // 곡 제목, 아티스트명 부분
	musicNameLabelVector = changeVectorIntType(dataParse("musicNameLabel"));
	musicNameLabel.init("Fonts/ITCAvantGardeStd-Md.ttf", musicNameLabelVector[2]);
	musicNameLabel.setWidth(musicNameLabelVector[4]);
	musicNameLabel.setTracking(musicNameLabelVector[3]);
	musicNameLabel.setPosition(musicNameLabelVector[0], musicNameLabelVector[1]);
	artistNameLabelVector = changeVectorIntType(dataParse("artistNameLabel"));
	artistNameLabel.init("Fonts/ITCAvantGardeStd-Md.ttf", artistNameLabelVector[2]);
	artistNameLabel.setWidth(artistNameLabelVector[4]);
	artistNameLabel.setTracking(artistNameLabelVector[3]);
	artistNameLabel.setPosition(artistNameLabelVector[0], artistNameLabelVector[1]);
	 
	albumArtVector = changeVectorIntType(dataParse("albumArt"));
	albumArtBoxVector = changeVectorIntType(dataParse("albumArtBox"));

	// 난이도 영어표기
	difficultyLabelColorVector = changeVectorIntType(dataParse("difficultyLabelColor"));
	string difficulty;
	switch (difficult) {
		case 1:
			difficultyLabelVector = changeVectorDoubleType(dataParse("difficultyLabel0"));
			difficulty = "B\nA\nS\nI\nC";
			break;
		case 2:
			difficultyLabelVector = changeVectorDoubleType(dataParse("difficultyLabel1"));
			difficulty = "A\nD\nV\nA\nN\nC\nE\nD";
			break;
		case 3:
			difficultyLabelVector = changeVectorDoubleType(dataParse("difficultyLabel2"));
			difficulty = "E\nX\nP\nE\nR\nT";
			break;
		case 4:
			difficultyLabelVector = changeVectorDoubleType(dataParse("difficultyLabel3"));
			difficulty = "M\nA\nS\nT\nE\nR";
			break;
	}
	difficultyFontSize = difficultyLabelVector[2];
	difficultyLabel.init("Fonts/ITCAvantGardeStd-Bold.ttf", difficultyFontSize);
	difficultyLabel.setText(difficulty);
	
	levelLabelVector = changeVectorDoubleType(dataParse("levelLabel"));
	levelLabelColorVector = changeVectorIntType(dataParse("levelLabelColor"));
	levelLabel.init("Fonts/ITCAvantGardeStd-Demi.ttf", levelLabelVector[2]);
	levelLabel.setTracking(levelLabelVector[3]);
	levelLabel.setText(to_string(level));

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

	levelColorBackgroundMeshVector = changeVectorDoubleType(dataParse("levelColorBackgroundMesh"));
	levelColorBackgroundMesh.clear();
	levelColorBackgroundMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0], levelColorBackgroundMeshVector[1]));
	levelColorBackgroundMesh.addColor(levelColor[0]);
	levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0] + levelColorBackgroundMeshVector[2], levelColorBackgroundMeshVector[1]));
	levelColorBackgroundMesh.addColor(levelColor[0]);
	levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0], levelColorBackgroundMeshVector[3]));
	levelColorBackgroundMesh.addColor(levelColor[difficult]);
	levelColorBackgroundMesh.addVertex(ofPoint(levelColorBackgroundMeshVector[0] + levelColorBackgroundMeshVector[2], levelColorBackgroundMeshVector[3]));
	levelColorBackgroundMesh.addColor(levelColor[difficult]);
	
}

void DataViewer::LoadBoxRect() {
	boxLeft.loadImage("Scene/Ingame/DataViewer/boxLeft.png");
	boxRight.loadImage("Scene/Ingame/DataViewer/boxRight.png");
	boxTop.loadImage("Scene/Ingame/DataViewer/boxTop.png");
	boxBottom.loadImage("Scene/Ingame/DataViewer/boxBottom.png");
	boxLeftTop.loadImage("Scene/Ingame/DataViewer/boxLeftTop.png");
	boxRightTop.loadImage("Scene/Ingame/DataViewer/boxRightTop.png");
	boxLeftBottom.loadImage("Scene/Ingame/DataViewer/boxLeftBottom.png");
	boxRightBottom.loadImage("Scene/Ingame/DataViewer/boxRightBottom.png");
}

void DataViewer::DrawBoxRect(float x, float y, float w, float h) {
	// 색상 덧씌워짐을 방지
	ofSetColor(255, 255, 255, 255);

	// 폼 테두리
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
	
	vector<string> _designerVector;
	int countLines = 0;
	for (auto line : designerBuffer.getLines()) {
		_designerVector.push_back(line);
		countLines++;
	}

	designerVector.clear();
	designerVector = _designerVector;
	
	setDesign();
}

void DataViewer::setDifficult(int _difficult) {
	difficult = _difficult;
	
	setDesign();
}

int DataViewer::getDifficult() {
	return difficult;
}

void DataViewer::setLevel(int _level) {
	level = _level;

	setDesign();
}

double DataViewer::getRate() {
	double rate = (judge[0] * 1.1) + (judge[1] * 1.0) + (judge[2] * 0.7);
	int maxCount = judge[0] + judge[1] + judge[2] + judge[3];
		
	return rate / maxCount * 100;
}

int DataViewer::getJudge0() {
	return judge[0];
}

int DataViewer::getJudge1() {
	return judge[1];
}

int DataViewer::getJudge2() {
	return judge[2];
}

int DataViewer::getJudge3() {
	return judge[3];
}

void DataViewer::setMusicName(string _musicName) {
	musicName = _musicName;
	musicNameLabel.setText(musicName);
}

string DataViewer::getMusicName() {
	return musicName;
}

void DataViewer::setArtistName(string _artistName) {
	artistNameLabel.setText(_artistName);
}

void DataViewer::setMetaData(meta_data _metas) {
	setMusicName(_metas.TITLE);
	setArtistName(_metas.ARTIST);
	setLevel(stoi(_metas.PLAYLEVEL));
}

vector<string> DataViewer::dataParse(string itemName) {
	vector<string> data;

	int pos = 0;
	bool isEnabled = false;

	for (auto line : designerVector) {
		if (line.find("#" + itemName + " ", 0) != string::npos)
			isEnabled = true;

		if (!isEnabled)
			pos++;
	}

	if (!isEnabled)
		return data;

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
