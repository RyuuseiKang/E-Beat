//
//  FileSystem.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#include "FileSystem.hpp"

FileSystem::FileSystem(){
	dir = new ofDirectory();

    
    dataPath = dir->path();
    
	musicDataPath = dataPath + "/MusicData";
	
	dir->open(musicDataPath);
	dir->listDir();

	musicDataSize = dir->size();

	musicData = new string[musicDataSize];
	for (int i = 0; i < musicDataSize; i++) {
		musicData[i] = dir->getFile(i).getFileName();
	}

	dir->close();
}

FileSystem::~FileSystem(){
	dir->close();

	delete dir;
}

int FileSystem::getMusicCount(){
    return musicDataSize;
}

string FileSystem::getMusicData(int num) {
	return musicData[num];
}

string FileSystem::getNowMusicData() {
	return musicData[nowMusicNumber];
}

string FileSystem::getNowMusicDifficulty() {
	return to_string(nowMusicDifficulty);
}

void FileSystem::setNowMusicNumber(int _num) {
	nowMusicNumber = _num;
}

void FileSystem::setNowMusicDifficulty(int _diff) {
	nowMusicDifficulty = _diff;
}
