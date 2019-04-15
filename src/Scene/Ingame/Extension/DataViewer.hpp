//
//  DataViewer.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/04/2019.
//

#ifndef __DATA_VIEWER_HPP_
#define __DATA_VIEWER_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/FileSystem.hpp"

class DataViewer {
public:

	DataViewer();
	DataViewer(FileSystem* _file);
	~DataViewer();

	void update();
	void draw();

	void setScore(double _score);
	void upCombo();
	void breakCombo();


private:

	double score;
	unsigned int combo;

	// 판정 예
	// JUSTICE_CRITICAL
	// JUSTICE
	// ATTACK
	//MISS
	unsigned int judge[4];

	unsigned int maxCombo;

	ofImage LevelBackgroundRect;
};

#endif // __DATA_VIEWER_HPP_