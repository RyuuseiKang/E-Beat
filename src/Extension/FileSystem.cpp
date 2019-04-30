//
//  FileSystem.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#include "FileSystem.hpp"

FileSystem::FileSystem(){
	dir = new ofDirectory();

    // 파일 데이터 패스
    dataPath = dir->path();
    
    // 이외 패스들 주소 기록
	musicDataPath = dataPath + "MusicData";

	dir->close();
}

FileSystem::~FileSystem(){
	dir->close();

	delete dir;
}

int FileSystem::getMusicCount(){
	dir->open(musicDataPath);
	dir->listDir();

	musicDataSize = dir->size();

	musicData = new string[musicDataSize];
	for (int i = 0; i < musicDataSize; i++) {
		musicData[i] = dir->getFile(i).getFileName();
	}

	dir->close();
	
    return musicDataSize;
}

string FileSystem::getMusicData(int num) {
	return musicData[num];
}
