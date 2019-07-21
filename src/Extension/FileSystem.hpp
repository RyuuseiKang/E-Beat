//
//  FileSystem.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include <iostream>
#include "ofMain.h"
#include "Parser.hpp"
#include "MusicMetaData.hpp"

class FileSystem{
public:
    FileSystem();
    ~FileSystem();

	void Initialize();
	void ParseMetaData(string _str, musicMeta& _metaData, string _filePath);
	    
    int getMusicCount();
	musicMeta getMusicData(int num);

	string getNowMusicData();
	string getNowMusicDifficulty();
    
	void setNowMusicNumber(int _num);
	void setNowMusicDifficulty(int _diff);
private:    
	ofDirectory *dir;

	string dataPath;
	string musicDataPath;

	string *musicData;

    size_t musicDataSize;

	int nowMusicNumber = 0;
	int nowMusicDifficulty = 0;

	vector<musicMeta> meta;

	Parser p;
};

#endif /* FileSystem_hpp */
