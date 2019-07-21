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

typedef struct musicMeta {
	string title;
	string artist;
	string jacket;

	int bgaStartPos = 0;
	int bgaEndPos = 0;
} musicMeta;

class FileSystem{
public:
    FileSystem();
    ~FileSystem();

	void Initialize();
	//void ParseMetaData(string _str, musicMeta& _metaData);
	    
    int getMusicCount();
	string getMusicData(int num);

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
};

#endif /* FileSystem_hpp */
