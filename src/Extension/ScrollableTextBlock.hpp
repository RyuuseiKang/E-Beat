//
//  ScrollableTextBlock.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 05/05/2019.
//

#ifndef __SCROLLABLE_TEXTBLOCK_HPP_
#define __SCROLLABLE_TEXTBLOCK_HPP_

#include "ofxTextBlock.h"
#include "ofxGui.h"

class ScrollableTextBlock : ofxTextBlock {
public:
	ScrollableTextBlock();
	~ScrollableTextBlock();

	void init(string fontLocation, float fontSize);

	void setText(string _inputText);
	void setWidth(float _width);
	void setPosition(float _x, float _y);
	void setTracking(float _tracking);
	void setColor(int r, int g, int b, int a);

	void update();
	void draw();

private:
	vector<char> text;
	
	float width;
	float tracking;
	float x, y;
	float fontSize;

	ofFbo fbo;
	ofPath path;

	ofTexture tex;

	ofxPanel gui;
	ofxFloatSlider tX;
	ofxFloatSlider tY;
};

#endif // __SCROLLABLE_TEXTBLOCK_HPP_
