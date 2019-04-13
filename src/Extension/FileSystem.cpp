//
//  FileSystem.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#include "FileSystem.hpp"

FileSystem::FileSystem(){
    ofDirectory applicationDirectory("");
    
    // 파일 데이터 패스
    string dataPath = applicationDirectory.path();
    applicationDirectory.close();
    
    // 이외 패스들
    const string musicDataPath = dataPath + "MusicData";
    
    
    // 패스별 처리
    musicDataDirectory = new ofDirectory(musicDataPath);
    //dir.open(dataPath + "MusicData");
    
    // 이거 꼭 필요함
    // 하위 폴더 리스트 처리
    musicDataDirectory->listDir();
    
    musicDataSize = musicDataDirectory->size();
    
    //for(int i = 0; i < musicDataDirectory.size(); i++){
    //    ofLogNotice(musicDataDirectory.getPath(i));
    //    cout << musicDataDirectory.getPath(i) << endl;
    //}
    
}

FileSystem::~FileSystem(){
    delete musicDataDirectory;
}

int FileSystem::getMusicCount(){
    return musicDataSize;
}
