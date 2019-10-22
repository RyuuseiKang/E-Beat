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

	LoadBoxRect();
	
}

Result::~Result() {

}

void Result::update(bool keys[256]) {
	dataViewer->update();
}

void Result::draw() {
	DrawBoxRect(ScoreBackgroundRect[0], ScoreBackgroundRect[1], ScoreBackgroundRect[2], ScoreBackgroundRect[3]);
	ofSetColor(ScoreBackgroundRect[4], ScoreBackgroundRect[5], ScoreBackgroundRect[6], ScoreBackgroundRect[7]);
	ofDrawRectangle(ScoreBackgroundRect[0], ScoreBackgroundRect[1], ScoreBackgroundRect[2], ScoreBackgroundRect[3]);
	DrawBoxRect(RankBackgroundRect[0], RankBackgroundRect[1], RankBackgroundRect[2], RankBackgroundRect[3]);
	ofSetColor(RankBackgroundRect[4], RankBackgroundRect[5], RankBackgroundRect[6], RankBackgroundRect[7]);
	ofDrawRectangle(RankBackgroundRect[0], RankBackgroundRect[1], RankBackgroundRect[2], RankBackgroundRect[3]);

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
}

void Result::keyReleased(int key) {

}

void Result::setDesign() {
	ScoreBackgroundRect = changeVectorIntType(dataParse("ScoreBackgroundRect"));
	RankBackgroundRect = changeVectorIntType(dataParse("RankBackgroundRect"));

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

	musicName = dataViewer->getMusicName();
	difficult = dataViewer->getDifficult();
	score = dataViewer->getScore();

	registrationToServer();
}

bool Result::isReady() {
	return isResultEnd;
}

void Result::registrationToServer() {
	dataKey = random_string(20);

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
