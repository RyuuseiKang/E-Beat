//
//  InitializeScene.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/03/2019.
//

#include "InitializeScene.h"

InitializeScene::InitializeScene(){
        
}
    
InitializeScene::~InitializeScene(){
        
}

void InitializeScene::update(bool keys[256]) {
    // TODO: 파일 읽는 쓰레드 추가
}

void InitializeScene::draw() {
	ofDrawBitmapStringHighlight("Initialize Scene", 20, 20);
}

class FileSystem : public ofThread{
    
};
