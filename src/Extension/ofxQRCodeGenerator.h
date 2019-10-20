#pragma once

#include "ofMain.h"
#include "qrencode/include/QrCode.hpp"

class ofxQRCodeGenerator {
public:
	ofxQRCodeGenerator();
	~ofxQRCodeGenerator();

	int qrSize;
	vector<int> qrCodeArr;

	void generate(string url);
	void draw(int x, int y, double size);
	void setColor(int _r, int _g, int _b, int _a);

private: 
	int r; 
	int g; 
	int b; 
	int a;
};
