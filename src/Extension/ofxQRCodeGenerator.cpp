#include "ofxQRCodeGenerator.h"

/**
 * Initialize parameters
 */
ofxQRCodeGenerator::ofxQRCodeGenerator() {}

ofxQRCodeGenerator::~ofxQRCodeGenerator() {}

//--------------------------------------------------------------
/**
 * receive url to generate qrcode
 * @params {string}  m padding from corner points area
 */
void ofxQRCodeGenerator::generate(string url) {
	const char *text = url.c_str();  // User-supplied text
	//const qrcodegen::QrCode::Ecc &errCorLvl = qrcodegen::QrCode::Ecc::LOW;  // Error correction level
	const qrcodegen::QrCode::Ecc &errCorLvl = qrcodegen::QrCode::Ecc::HIGH;  // Error correction level
	const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, errCorLvl);

	for (int y = 0; y < qr.size; y++) {
		for (int x = 0; x < qr.size; x++) {
			qrCodeArr.push_back((qr.getModule(x, y) == 1 ? 1 : 0));
		}
	}
	qrSize = qr.size;
}

//--------------------------------------------------------------

void ofxQRCodeGenerator::draw(int x, int y, double size) {
	double blockSize = size / qrSize;

	for (int i = 0; i < qrCodeArr.size(); i++) {
		if (qrCodeArr[i] == 1) ofSetColor(r, g, b, a);
		else ofSetColor(255, 255, 255, 0);
		ofDrawRectangle(x + (i%qrSize)*blockSize, y + (i/qrSize)*blockSize, blockSize, blockSize);
	}
}

void ofxQRCodeGenerator::setColor(int _r, int _g, int _b, int _a) {
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}
