//
//  Result.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/10/2019.
//

#include "Result.hpp"

Result::Result() {
	readDesigner();
	
	registrationUserNameLabel.load("Scene/Result/registrationUserNameLabel.png");

	ScoreLabel.load("Scene/Result/ScoreLabel.png");
	RankLabel.load("Scene/Result/RankLabel.png");

	rankImage = new ofImage[5];
	rankImage[0].load("Scene/Result/Rank/S+.png");
	rankImage[1].load("Scene/Result/Rank/S.png");
	rankImage[2].load("Scene/Result/Rank/A.png");
	rankImage[3].load("Scene/Result/Rank/B.png");
	rankImage[4].load("Scene/Result/Rank/C.png");

	LoadBoxRect();
	
}

Result::~Result() {

}

void Result::update(bool keys[256]) {
	dataViewer->update();

	ScoreText.setText(to_string(int(score)));
}

void Result::draw() {
	DrawBoxRect(ScoreBackgroundRect[0], ScoreBackgroundRect[1], ScoreBackgroundRect[2], ScoreBackgroundRect[3]);
	ofSetColor(ScoreBackgroundRect[4], ScoreBackgroundRect[5], ScoreBackgroundRect[6], ScoreBackgroundRect[7]);
	ofDrawRectangle(ScoreBackgroundRect[0], ScoreBackgroundRect[1], ScoreBackgroundRect[2], ScoreBackgroundRect[3]);
	DrawBoxRect(RankBackgroundRect[0], RankBackgroundRect[1], RankBackgroundRect[2], RankBackgroundRect[3]);
	ofSetColor(RankBackgroundRect[4], RankBackgroundRect[5], RankBackgroundRect[6], RankBackgroundRect[7]);
	ofDrawRectangle(RankBackgroundRect[0], RankBackgroundRect[1], RankBackgroundRect[2], RankBackgroundRect[3]);

	ScoreLabel.draw(ScoreLabelVector[0], ScoreLabelVector[1], ScoreLabelVector[2], ScoreLabelVector[3]);
	RankLabel.draw(RankLabelVector[0], RankLabelVector[1], RankLabelVector[2], RankLabelVector[3]);

	RankTextImage->draw(RankTextImageVector[0], RankTextImageVector[1], RankTextImageVector[2], RankTextImageVector[3]);

	ScoreText.drawRight(ScoreTextVector[0], ScoreTextVector[1]);

	ofSetColor(nicknameRegisterBackgroundRectVector[4], nicknameRegisterBackgroundRectVector[5], nicknameRegisterBackgroundRectVector[6], nicknameRegisterBackgroundRectVector[7]);
	ofDrawRectangle(nicknameRegisterBackgroundRectVector[0], nicknameRegisterBackgroundRectVector[1], nicknameRegisterBackgroundRectVector[2], nicknameRegisterBackgroundRectVector[3]);
	DrawBoxRect(nicknameRegisterBackgroundRectVector[0], nicknameRegisterBackgroundRectVector[1], nicknameRegisterBackgroundRectVector[2], nicknameRegisterBackgroundRectVector[3]);
	nicknameRegisterQR.draw(nicknameRegisterQRVector[0], nicknameRegisterQRVector[1], nicknameRegisterQRVector[2]);
	
	ofSetColor(255, 255, 255, 255);
	registrationUserNameLabel.draw(registrationUserNameLabelVector[0], registrationUserNameLabelVector[1], registrationUserNameLabelVector[2], registrationUserNameLabelVector[3]);

	dataViewer->draw();

	ofDrawBitmapStringHighlight("Result Scene", 20, 20);

	ofSetColor(255, 255, 255, 255);
}

void Result::keyPressed(int key) {
	if (key == 'r')
		readDesigner();

	if (key == 'd' || key == 'D')
		isResultEnd = true;

	if (key == 'f' || key == 'F')
		isResultEnd = true;

	if (key == 'j' || key == 'J')
		isResultEnd = true;

	if (key == 'k' || key == 'K')
		isResultEnd = true;
}

void Result::keyReleased(int key) {

}

void Result::setDesign() {
	ScoreLabelVector = changeVectorIntType(dataParse("ScoreLabel"));
	ScoreTextVector = changeVectorIntType(dataParse("ScoreText"));
	ScoreTextColorVector = changeVectorIntType(dataParse("ScoreTextColor"));
	ScoreText.init("Fonts/ITCAvantGardeStd-Bold.ttf", ScoreTextVector[2]);
	ScoreText.setTracking(ScoreTextVector[3]);
	ScoreText.setColor(ScoreTextColorVector[0], ScoreTextColorVector[1], ScoreTextColorVector[2], ScoreTextColorVector[3]);

	RankLabelVector = changeVectorIntType(dataParse("RankLabel"));
	ScoreBackgroundRect = changeVectorIntType(dataParse("ScoreBackgroundRect"));
	RankBackgroundRect = changeVectorIntType(dataParse("RankBackgroundRect"));
	RankTextImageVector = changeVectorIntType(dataParse("RankTextImage"));

	nicknameRegisterQRVector = changeVectorDoubleType(dataParse("nicknameRegisterQR"));
	nicknameRegisterQR.setColor(nicknameRegisterQRVector[3], nicknameRegisterQRVector[4], nicknameRegisterQRVector[5], nicknameRegisterQRVector[6]);
	nicknameRegisterBackgroundRectVector = changeVectorIntType(dataParse("nicknameRegisterBackgroundRect"));

	registrationUserNameLabelVector = changeVectorIntType(dataParse("registrationUserNameLabel"));

}

void Result::LoadBoxRect() {
	boxLeft.loadImage("Scene/Ingame/DataViewer/boxLeft.png");
	boxRight.loadImage("Scene/Ingame/DataViewer/boxRight.png");
	boxTop.loadImage("Scene/Ingame/DataViewer/boxTop.png");
	boxBottom.loadImage("Scene/Ingame/DataViewer/boxBottom.png");
	boxLeftTop.loadImage("Scene/Ingame/DataViewer/boxLeftTop.png");
	boxRightTop.loadImage("Scene/Ingame/DataViewer/boxRightTop.png");
	boxLeftBottom.loadImage("Scene/Ingame/DataViewer/boxLeftBottom.png");
	boxRightBottom.loadImage("Scene/Ingame/DataViewer/boxRightBottom.png");
}

void Result::DrawBoxRect(float x, float y, float w, float h) {
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

void Result::readDesigner() {
	// 디자이너 파일 내용 읽어오기
	ofBuffer designerBuffer = ofBufferFromFile("Scene/Result/Designer.des");

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

void Result::setDataViewer(DataViewer * _dataViewer) {
	dataViewer = _dataViewer;
	
	isResultEnd = false;

	musicName = dataViewer->getMusicName();
	difficult = dataViewer->getDifficult();
	score = dataViewer->getScore();
	rate = dataViewer->getRate();

	ScoreText.setText(to_string(int(score)));

	if (rate >= 100)
		RankTextImage = &rankImage[0];
	else if (rate >= 90)
		RankTextImage = &rankImage[1];
	else if (rate >= 70)
		RankTextImage = &rankImage[2];
	else if (rate >= 50)
		RankTextImage = &rankImage[3];
	else
		RankTextImage = &rankImage[4];

	// cout << rate << endl;

	registrationToServer();
}

bool Result::isReady() {
	return isResultEnd;
}

void Result::endResult() {

}

void Result::registrationToServer() {
	dataKey = random_string(20);

	ofHttpResponse resp = ofLoadURL("http://ec2-15-164-163-252.ap-northeast-2.compute.amazonaws.com:3000/ebeat/rank?music=" + removeSpace(musicName) + "." + to_string(difficult));
	cout << resp.data << endl;
	cout << "http://ec2-15-164-163-252.ap-northeast-2.compute.amazonaws.com:3000/ebeat/rank?music=" << removeSpace(musicName) << "." << to_string(difficult) << endl;

	ofHttpRequest request;
	request.method = ofHttpRequest::GET;
	request.url = "http://ec2-15-164-163-252.ap-northeast-2.compute.amazonaws.com:3000/ebeat/registration/key?key=" + dataKey + "&score=" + to_string(int(score)) + "&music=" + removeSpace(musicName) + "." + to_string(difficult);
	ofURLFileLoader http;
	auto response = http.handleRequest(request);

	cout << request.url << endl;
	cout << "http://seoulmet.ro/registration?key=" + dataKey << endl;

	nicknameRegisterQR.generate("http://seoulmet.ro/registration?key=" + dataKey);
	//nicknameRegisterQR.generate(dataKey);
}

string Result::removeSpace(string _str) {
	auto pos = _str.find(" ");
	auto len = 1;
	if (pos != std::string::npos) {
		_str.replace(pos, len, "_");
	}

	return _str;
}

string Result::random_string(size_t length) {
	auto randchar = []() -> char {
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

vector<string> Result::dataParse(string itemName) {
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

vector<string> Result::split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

vector<int> Result::changeVectorIntType(vector<string> str) {
	vector<int> data;
	for (int i = 1; i < str.size(); i++) {
		data.push_back(stoi(str[i]));
	}
	return data;
}

vector<double> Result::changeVectorDoubleType(vector<string> str) {
	vector<double> data;
	for (int i = 1; i < str.size(); i++) {
		data.push_back(stod(str[i]));
	}
	return data;
}
