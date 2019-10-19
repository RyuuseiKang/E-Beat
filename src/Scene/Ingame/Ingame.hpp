//
//  Ingame.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/04/2019.
//

#ifndef __INGAME_HPP_
#define __INGAME_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/FileSystem.hpp"
#include "Extension/DataViewer.hpp"
#include "Extension/LaneViewer.hpp"
#include "Extension/MusicPlayer.hpp"

class Ingame {
public:
	Ingame();
	Ingame(FileSystem* _file);
	~Ingame();

	void update(bool keys[256]);
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void readyMusic();
	void readyResult();
	bool isReady();
	
	DataViewer* getDataViewer();

private:
	FileSystem* file;

	DataViewer *dataViewer;
	LaneViewer *laneViewer;
	MusicPlayer musicPlayer;
	
	ofImage backLane;
	
	bool isAliveViewer = false;
	bool isIngameEnd = false;
};

#endif /* __INGAME_HPP_ */
