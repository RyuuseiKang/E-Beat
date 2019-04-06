//
//  EntryScene.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#ifndef __ENTRY_SCENE_HPP_
#define __ENTRY_SCENE_HPP_

#include <iostream>
#include "../ofMain.h"

class EntryScene {
public:
	EntryScene();
	~EntryScene();

    void update(bool keys[256]);
    void draw();
	void keyPressed(int key);
	void keyReleased(int key);

private:


};

#endif /* __ENTRY_SCENE_HPP_ */
