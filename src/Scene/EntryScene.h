//
//  EntryScene.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#ifndef __ENTRY_SCENE_H_
#define __ENTRY_SCENE_H_

#include <iostream>

class EntryScene {
public:
	EntryScene();
	~EntryScene();

    void update(bool keys[256]);
    void draw();
private:


};

#endif /* __ENTRY_SCENE_H_ */
