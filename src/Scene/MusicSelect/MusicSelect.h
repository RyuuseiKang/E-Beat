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
#include	"MusicList.h"
#include "Extension/ofBackgroundPlayer.h"
#include "Extension/ofSelectSlider.h"
#include "Extension/KeyBeam.h"

class MusicSelect {
public:
	MusicSelect();
	~MusicSelect();

	void update(bool keys[256]);
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);

private:
	MusicList musicList;

	ofImage musicLinerBackRect;
	ofImage bottombuttonsRect;

	ofBackgroundPlayer bgaPlayer;
	ofSelectSlider slider;

	float bgaStartPosition = 0.28;
	float bgaEndPosition = 0.43;

	int p = 0;
	int m = 1;

	int x = 1;

	KeyBeam button[4];

	MusicCard card;
};

#endif /* __MUSIC_SELECT_H_ */
