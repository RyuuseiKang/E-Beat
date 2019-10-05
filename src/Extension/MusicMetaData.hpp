#ifndef __MUSIC_META_DATA_HPP_
#define __MUSIC_META_DATA_HPP_

#include "ofMain.h"

class MusicMeta {
public:
	string path;
	string musicPath;

	string title;
	string artist;
	string jacket;
	string bga;

	int bgaStartPos = 0;
	int bgaEndPos = 0;
};

#endif //__MUSIC_META_DATA_HPP_