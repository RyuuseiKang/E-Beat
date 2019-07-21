#ifndef __MUSIC_META_DATA_HPP_
#define __MUSIC_META_DATA_HPP_

#include "ofMain.h"

typedef struct musicMeta {
	string title;
	string artist;
	string jacket;
	string bga;

	int bgaStartPos = 0;
	int bgaEndPos = 0;
} musicMeta;

#endif //__MUSIC_META_DATA_HPP_