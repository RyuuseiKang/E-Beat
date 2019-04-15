//
//  ofBackgroundPlayer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "ofBackgroundPlayer.hpp"

ofBackgroundPlayer::ofBackgroundPlayer() {
	BGAblur.setup(1920, 1080);

#ifdef defined _WIN32 || defined _WIN64
    ofVideoPlayer::setPixelFormat(OF_PIXELS_NATIVE);
#endif
	
}

ofBackgroundPlayer::~ofBackgroundPlayer() {
	ofThread::stopThread();
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
	filePath = "musicData/" + _fileName + "/BGA.mp4";
	
#ifdef TARGET_OS_MAC
    ofVideoPlayer::loadAsync(filePath);
    videoPlay();
#elif defined _WIN32 || defined _WIN64
    ThreadStart();
    videoPlay();
#endif
}

void ofBackgroundPlayer::videoPlay() {
	ofVideoPlayer::play();
}

void ofBackgroundPlayer::videoStop() {
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

void ofBackgroundPlayer::ThreadStart() {
#ifdef defined _WIN32 || defined _WIN64
	if (ofThread::isThreadRunning() != 0)
		ThreadStop();

    ofThread::startThread(true);
#endif

}

void ofBackgroundPlayer::ThreadStop() {
	ofThread::stopThread();
}

void ofBackgroundPlayer::threadedFunction() {
	while (isThreadRunning() != 0) {
#ifdef TARGET_OS_MAC
        if(!isPlaying()){
            ofThread::lock();
            
            ofVideoPlayer::play();
#elif defined _WIN32 || defined _WIN64
        if(ofThread::lock()){
            ofVideoPlayer::loadMovie(filePath);
#endif
			ofThread::unlock();
		}
		videoPlay();
		ofThread::stopThread();
	}
}
