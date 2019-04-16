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

class Ingame {
public:
	Ingame();
	Ingame(FileSystem* _file);
	~Ingame();

	void update(bool keys[256]);
	void draw();

	void keyPressed(int key);

private:
	FileSystem* file;

	DataViewer *dataViewer;
	
	ofImage backLane;
};

#endif /* __INGAME_HPP_ */
