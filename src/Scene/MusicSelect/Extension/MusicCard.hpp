//
//  MusicCard.hpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 03/04/2019.
//

#ifndef __MUSIC_CARD_HPP_
#define __MUSIC_CARD_HPP_

#include <iostream>
#include "../ofMain.h"
#include "../Extension/ofxTextSuite.h"
#include "../Extension/MusicMetaData.hpp"

class MusicCard {
public:
	MusicCard();
	~MusicCard();

	void update();
	void draw();

	void Select(bool direction);
	void Deselect(bool direction);

	void setMetaData(musicMeta _metaData);
	
private:
	musicMeta metaData;
	double maxScore;

	ofImage patternOverlay;
	ofImage albumImage;

	const int selectedCardWidth = 423;
	const int selectedCardHeight = 572;
	const int selectedBoxPadding = 358;
	const int selectedAlbumSize = 315;
	const int selectedAlbumPadding = 26;

	const int normalCardWidth = 285;
	const int normalCardHeight = 386;
	const int normalBoxPadding = 470;
	const int normalAlbumSize = 212;
	const int normalAlbumPadding = 18;

	const int selectedLeftPadding = 75;
	const int normalLeftPadding = 26;
	
	bool isSelected = false;

	const ofColor expertColor = ofColor(255, 102, 102, 255);

	const double countKey = 8;
	bool isSizeChange;
	int changeCounter;
	bool isDirection;
	void sizeChange(bool selected, bool direction);
};

#endif __MUSIC_CARD_HPP_