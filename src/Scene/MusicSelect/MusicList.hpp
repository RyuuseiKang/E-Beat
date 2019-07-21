//
//  MusicList.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 04/04/2019.
//

#ifndef __MUSIC_LIST_HPP_
#define __MUSIC_LIST_HPP_

#include <iostream>
#include "../ofMain.h"
#include "Extension/MusicCard.hpp"

class MusicList {
public:
	MusicList();
	~MusicList();

	void update();
	void draw();

	void addItem(musicMeta _metaData);
	void move(bool direction);
	void setPosition(int selectedKey);

	void setMaxCount(int max);

	bool isMoving();

private:
	bool isMove = false;
	bool moveDirection = false;
	int moveCounter = 30;
	int normalPadding = 13;
	int specialPadding = 65;

	int selectedPosition = 0;
	int maxCount = 7;
};

#endif /* __MUSIC_LIST_HPP_ */