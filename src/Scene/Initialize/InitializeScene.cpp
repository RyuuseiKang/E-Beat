//
//  InitializeScene.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 26/03/2019.
//

#include "InitializeScene.hpp"

InitializeScene::InitializeScene(){
    ofDirectory dir("");
    
    string dataPath = dir.path();
    
    dir.open(dataPath + "MusicData");
    
    //populate the directory object
	// 이거 꼭 필요함
    dir.listDir();
    
    cout << dir.path() << endl;
    
    for(int i = 0; i < dir.size(); i++){
        ofLogNotice(dir.getPath(i));
        cout << dir.getPath(i) << endl;
    }
}
    
InitializeScene::~InitializeScene(){
	
}

void InitializeScene::update(bool keys[256]) {
    // TODO: 파일 읽는 쓰레드 추가
	// 위에서 추가해벌임

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
