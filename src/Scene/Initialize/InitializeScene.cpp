//
//  InitializeScene.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/03/2019.
//

#include "InitializeScene.hpp"

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

void InitializeScene::keyPressed(int key) {

}

void InitializeScene::keyReleased(int key) {

}

class FileSystem : public ofThread{
    
};
