//
//  MusicPlayer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 09/06/2019.
//

#ifndef __MUSIC_PLYER_HPP_
#define __MUSIC_PLYER_HPP_

#include <iostream>
#include "../ofMain.h"

class MusicPlayer {
public:
	MusicPlayer();
	~MusicPlayer();

	void SetMusic(string _musicName);
	void play();
	long getPosition();


private:
	ofSoundPlayer player;
};

#endif // __MUSIC_PLYER_HPP_