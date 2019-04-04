//
//  MusicList.h
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 04/04/2019.
//

#ifndef __MUSIC_LIST_H_
#define __MUSIC_LIST_H_

#include <iostream>
#include "../ofMain.h"
#include "Extension/MusicCard.h"

class MusicList {
public:
	MusicList();
	~MusicList();

	void update();
	void draw();

	void addList();
	void move(bool direction);

private:
	bool isMove = false;
	bool moveDirection = false;
	int moveCounter = 30;
	int normalPadding = 13;
	int specialPadding = 65;

	MusicCard card[6];

	int selectedPosition = 0;
	int maxCount = 6;
};

#endif __MUSIC_LIST_H_