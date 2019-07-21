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
    
	dir->close();
}

void FileSystem::Initialize() {
	musicDataPath = dataPath + "/MusicData";

	dir->open(musicDataPath);
	dir->listDir();

	musicDataSize = dir->size();

	musicData = new string[musicDataSize];
	for (int i = 0; i < musicDataSize; i++) {
		musicMeta _data;

		ofFile _file;
		string filePath = musicDataPath + "/" + dir->getFile(i).getFileName() + "/metadata.meta";
		_file.open(ofToDataPath(filePath));
		ofBuffer buff = _file.readToBuffer();

		for (const std::string &line : buff.getLines()) {
			if (line.substr(0, 1).c_str()[0] == '#') {
				try {
						//ParseMetaData(line, _data);
				}
				catch (int expn) {
				}
			}
		}



	}

}

/*
void FileSystem::ParseMetaData(string _str, musicMeta& _metaData) {
	vector<string> v = split(_str, ' ');

	string command = v.at(0);

	command = command.substr(1, command.length() - 1);

	string val;
	try {
		val = v.at(1);
	}
	catch (int expn) {
		val = "";
	}

	val = ReplaceAll(v.at(1), "\"", "");

	if (command == "TITLE")
		_metaData.title = val;

	else if (command == "ARTIST")
		_metaData.artist = val;

	else if (command == "JACKET")
		_metaData.jacket = val;

	else if (command == "#BGASTARTPOS")
		_metaData.bgaStartPos = stoi(val);

	else if (command == "PLAYLEVEL")
		_metaData.bgaEndPos = stoi(val);
}
*/

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
