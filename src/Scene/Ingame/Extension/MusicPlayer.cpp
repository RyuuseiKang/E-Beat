//
//  MusicPlayer.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#include "MusicPlayer.hpp"

void MusicPlayer::load(string _path) {
	ofSoundPlayer::load(_path);
}

void MusicPlayer::play() {
	ofSoundPlayer::play();
}

int MusicPlayer::getPositionMS() {
	return ofSoundPlayer::getPositionMS();
}