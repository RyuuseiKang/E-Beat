//
//  FileSystem.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 12/04/2019.
//

#ifndef FileSystem_hpp
#define FileSystem_hpp

#include "ofMain.h"
#include <stdio.h>

class FileSystem{
public:
    FileSystem();
    ~FileSystem();
    
    int getMusicCount();
	string getMusicData(int num);

	string getNowMusicData();
    
	void setNowMusicNumber(int _num);
private:    
	ofDirectory *dir;

	string dataPath;
	string musicDataPath;

	string *musicData;

    size_t musicDataSize;

	int nowMusicNumber = 0;
};

#endif /* FileSystem_hpp */
