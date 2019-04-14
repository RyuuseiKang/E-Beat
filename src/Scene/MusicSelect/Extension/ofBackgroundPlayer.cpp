//
//  ofBackgroundPlayer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "ofBackgroundPlayer.hpp"

ofBackgroundPlayer::ofBackgroundPlayer() {
	BGAblur.setup(1920, 1080);
}

ofBackgroundPlayer::~ofBackgroundPlayer() {

}

void ofBackgroundPlayer::update() {
	float currentFrame = ofVideoPlayer::getCurrentFrame();

	if (!(bgaStartFrame < currentFrame && currentFrame < bgaEndFrame))
		ofVideoPlayer::setFrame(bgaStartFrame + 1);

	if (currentFrame - bgaStartFrame < fadeFrame) {
		this->setVolume((currentFrame - bgaStartFrame) / fadeFrame);
		//cout << "Set Volume : " << (currentFrame - bgaStartFrame) / fadeFrame << endl;
	}
		
	if (bgaEndFrame - currentFrame < fadeFrame) {
		this->setVolume((bgaEndFrame - currentFrame) / fadeFrame);
		//cout << "Set Volume : " << (bgaEndFrame - currentFrame) / fadeFrame << endl;
	}
		
	ofVideoPlayer::update();
}

void ofBackgroundPlayer::loadAsync(string _fileName) {
			
	string filePath = "musicData/" + _fileName + "/BGA.mp4";
	ofVideoPlayer::load(filePath);
}

void ofBackgroundPlayer::play() {
	ofVideoPlayer::play();
}

void ofBackgroundPlayer::stop() {
	ofVideoPlayer::stop();
}

bool ofBackgroundPlayer::isPaused() {
	return ofVideoPlayer::isPaused();
}

bool ofBackgroundPlayer::isPlaying() {
	return ofVideoPlayer::isPlaying();
}

void ofBackgroundPlayer::setVolume(float volume) {
	ofVideoPlayer::setVolume(volume);
}

void ofBackgroundPlayer::SetLoopFrame(int startFrame, int endFrame) {
	bgaStartFrame = startFrame;
	bgaEndFrame = endFrame;
}

void ofBackgroundPlayer::draw(float x, float y, float w, float h) {
	BGAblur.begin();
	BGAblur.amount = blurAmount;
	BGAblur.iterations = blurIterations;
	ofVideoPlayer::draw(x, y, w, h);
	BGAblur.end();
}
