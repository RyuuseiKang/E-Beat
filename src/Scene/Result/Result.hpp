//
//  Result.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/10/2019.
//

#ifndef __RESULT_HPP_
#define __RESULT_HPP_

#include <iostream>
#include "../ofMain.h"


#include "../Ingame/Extension/DataViewer.hpp"

class Result {
public:

	Result();
	~Result();

	void update(bool keys[256]);
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);

	void setDataViewer(DataViewer *_dataViewer);

	bool isReady();


private:

	DataViewer *dataViewer;

	bool isResultEnd = false;
};

#endif /* __RESULT_HPP_ */