//
//  ScrollableTextBlock.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 05/05/2019.
//

#include "ScrollableTextBlock.hpp"
#include <string>

ScrollableTextBlock::ScrollableTextBlock() {
	gui.setup();
	gui.add(tX.setup("transform X", 0, -1000, 1000));
	gui.add(tY.setup("transform Y", 0, -1000, 1000));

	setText("");
}

ScrollableTextBlock::~ScrollableTextBlock() {

}

void ScrollableTextBlock::init(string fontLocation, float _fontSize) {
	fontSize = _fontSize;
	ofxTextBlock::init(fontLocation, fontSize);
	defaultFont.load(fontLocation, fontSize);

}

string strText;
void ScrollableTextBlock::setText(string _inputText) {
	strText = _inputText;
	text = vector<char>(_inputText.c_str(), _inputText.c_str() + _inputText.size() + 1);
	ofxTextBlock::setText(_inputText);
}

void ScrollableTextBlock::setWidth(float _width) {
	width = _width;

	cout << "fbo Allocate: " << width << ", " << fontSize << endl;
	fbo.allocate(width, fontSize);
}

void ScrollableTextBlock::setPosition(float _x, float _y) {
	x = _x;
	y = _y;
}

void ScrollableTextBlock::setTracking(float _tracking) {
	tracking = _tracking;

	ofxTextBlock::setTracking(tracking);
}

void ScrollableTextBlock::setColor(int r, int g, int b, int a) {
	ofxTextBlock::setColor(r, g, b, a);
}

void ScrollableTextBlock::update(){

}

void ScrollableTextBlock::draw() {
	//ofSetColor(0, 0, 0, 255);

	float drawX = x;
	float drawY = y;
	
	glPushMatrix();

	int textWidth = width;

	ofSetColor(words[0].color);
	for (int i = 0; i < text.size(); i++) {
		string tmpStr(1, text.at(i));

		ofTexture mask;
		ofTexture textMask;
		ofTrueTypeFont *dF = &defaultFont;

		textWidth -= defaultFont.stringWidth(tmpStr);

		if (textWidth > 0) {
			mask.allocate((textWidth < defaultFont.stringWidth(tmpStr))?textWidth:defaultFont.stringWidth(tmpStr), defaultFont.stringHeight(tmpStr) * 1.3, GL_LUMINANCE); // or GL_RED in opengl 3+
			// mask.allocate(defaultFont.stringWidth(tmpStr), defaultFont.stringHeight(tmpStr) * 1.3, GL_LUMINANCE); // or GL_RED in opengl 3+
			mask.setAlphaMask(dF->getStringTexture(tmpStr, false));

			mask.draw(drawX, drawY);
		}

		glTranslatef(tracking, 0, 0.0f);
		if(tmpStr != " ")
			glTranslatef(defaultFont.stringWidth(tmpStr), 0, 0.0f);
		else
			glTranslatef(fontSize / 2, 0, 0.0f);
	}
		
	glPopMatrix();

	// gui.draw();

	// string  strToDraw;
	// int     currentWordID;
	// float   drawX;
	// float   drawY;
	// 
	// float currX = 0;
	// 
	// if (words.size() > 0) {
	// 
	// 	for (int l = 0; l < lines.size(); l++) {
	// 		for (int w = 0; w < lines[l].wordsID.size(); w++) {
	// 			
	// 			currentWordID = lines[l].wordsID[w];
	// 
	// 			//cout << "words[currentWordID].rawWord: " << words[currentWordID].rawWord << endl;
	// 
	// 			drawX = x + currX;
	// 			drawY = y + (defaultFont.getLineHeight() * (l + 1));
	// 
	// 			ofSetColor(words[currentWordID].color.r, words[currentWordID].color.g, words[currentWordID].color.b, words[currentWordID].color.a);
	// 			glPushMatrix();
	// 
	// 			for (int i = 0; i < words[currentWordID].rawWord.length(); i++) {
	// 				
	// 				//glTranslatef(drawX, drawY, 0.0f);
	// 				glScalef(scale, scale, scale);
	// 
	// 				vector<char> ch(words[currentWordID].rawWord.c_str(), words[currentWordID].rawWord.c_str() + words[currentWordID].rawWord.size() + 1);
	// 				
	// 				
	// 				defaultFont.drawString(tmpStr, drawX, drawY);
	// 				glTranslatef(tracking, 0, 0.0f);
	// 			}
	// 			currX += words[currentWordID].width + (words[currentWordID].rawWord.length() * tracking);
	// 			glPopMatrix();
	// 
	// 		}
	// 		currX = 0;
	// 
	// 	}
	// }
}
