//
//  MusicPlayer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 29/07/2019.
//

#ifndef __MUSIC_PLAYER_HPP_
#define __MUSIC_PLAYER_HPP_

#include <iostream>
#include "../ofMain.h"

class MusicPlayer : ofSoundPlayer {
public:
	
	void load(string _path);
	void play();
	int getPositionMS();
	void setPositionMS(int _time);
	
	bool getIsPlaying();

private:
	
};

#endif /* __MUSIC_PLAYER_HPP_ */