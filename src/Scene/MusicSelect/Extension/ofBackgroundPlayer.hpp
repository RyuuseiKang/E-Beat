//
//  ofBackgroundPlayer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#ifndef __OF_BACKGROUND_PLAYER_HPP_
#define __OF_BACKGROUND_PLAYER_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/ofxBlurShader.h"

class ofBackgroundPlayer : ofVideoPlayer, ofThread{
public:
	ofBackgroundPlayer();
	~ofBackgroundPlayer();

	void update();
	void loadAsync(string _fileName);
	void videoPlay();
	void videoStop();
	bool isPaused();
	bool isPlaying();
	void setVolume(float volume);

	void SetLoopFrame(int startFrame, int endFrame);
	void draw(float x, float y, float w, float h);

	void ThreadStart();
	void ThreadStop();

	void threadedFunction();

private:
	ofxBlurShader BGAblur;

	string filePath;

	int currentPos = 0;
	int maxCount = 0;

	int blurAmount = 2;
	int blurIterations = 5;

	int bgaStartFrame = 2005;
	int bgaEndFrame = 3072;

	int fadeFrame = 15;
};

#endif /* __OF_BACKGROUND_PLAYER_HPP_ */
