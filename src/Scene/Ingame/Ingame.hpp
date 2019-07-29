//
//  MusicSelect.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
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
	void keyRelease(int key);

	void readyMusic();
	
private:
	FileSystem* file;

	DataViewer *dataViewer;
	LaneViewer *laneViewer;
	MusicPlayer musicPlayer;
	
	ofImage backLane;
	
	bool isAliveViewer = false;
};

#endif /* __INGAME_HPP_ */
