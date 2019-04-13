//
//  MusicSelect.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#ifndef __MUSIC_SELECT_HPP_
#define __MUSIC_SELECT_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/FileSystem.hpp"
#include "MusicList.hpp"
#include "Extension/ofBackgroundPlayer.hpp"
#include "Extension/ofSelectSlider.hpp"
#include "Extension/KeyBeam.hpp"


class MusicSelect {
public:
	MusicSelect();
    MusicSelect(FileSystem *file);
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

	int maxCountMusic = 7;

	KeyBeam button[4];

	};

#endif /* __MUSIC_SELECT_HPP_ */
