//
//  MusicSelect.h
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#ifndef __MUSIC_SELECT_H_
#define __MUSIC_SELECT_H_

#include <iostream>
#include "../ofMain.h"
#include "../Shader/ofxBlurShader.h"
#include "../extension/Extensions.h"

class MusicSelect {
public:
	MusicSelect();
	~MusicSelect();

    void update(bool keys[256]);
    void draw();
	void keyPressed(int key);
	void keyReleased(int key);
    
private:
	ofImage musicLinerBackRect;
	ofBackgroundPlayer bgaPlayer;
	//ofVideoPlayer backBGAPlayer;
	ofxBlurShader BGAblur;
	ofSelectSlider slider;

	float bgaStartPosition = 0.28;
	float bgaEndPosition = 0.43;

	int p = 0;
	int m = 1;
};

#endif /* __MUSIC_SELECT_H_ */
