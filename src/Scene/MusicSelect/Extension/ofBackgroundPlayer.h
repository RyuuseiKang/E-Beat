//
//  ofBackgroundPlayer.h
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/2019.
//

#ifndef __OF_BACKGROUND_PLAYER_H_
#define __OF_BACKGROUND_PLAYER_H_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/ofxBlurShader.h"

class ofBackgroundPlayer : ofVideoPlayer {
public:
	ofBackgroundPlayer();
	~ofBackgroundPlayer();

	void update();
	bool load(string name);
	void play();
	void stop();
	bool isPaused();
	bool isPlaying();
	void setVolume(float volume);

	void SetLoopFrame(int startFrame, int endFrame);
	void draw(float x, float y, float w, float h);

private:
	ofxBlurShader BGAblur;
	int blurAmount = 2;
	int blurIterations = 5;

	int bgaStartFrame = 2005;
	int bgaEndFrame = 3072;

	int fadeFrame = 15;
};

#endif /* __OF_BACKGROUND_PLAYER_H_ */
