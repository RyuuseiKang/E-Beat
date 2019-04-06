//
//  InitializeScene.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/03/2019.
//

#ifndef __INITIALIZE_SCENE_HPP_
#define __INITIALIZE_SCENE_HPP_

#include <iostream>
#include "../ofMain.h"

class InitializeScene{
public:
    InitializeScene();
    ~InitializeScene();
    
	void update(bool keys[256]);
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
private:
    
};

#endif /* __INITIALIZE_SCENE_HPP_ */