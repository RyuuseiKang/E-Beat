//
//  MusicCard.h
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 03/04/2019.
//

#ifndef __MUSIC_CARD_H_
#define __MUSIC_CARD_H_

#include <iostream>
#include "../ofMain.h"

class MusicCard {
public:
	MusicCard();
	~MusicCard();

	void update();
	void draw(int x);

	void Select();
	void Deselect();

	void setMusicData(string _musicName, string _artistName, double maxScore);

	
private:
	string musicName;
	string artistName;
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

	bool isSelected = true;

	const ofColor expertColor = ofColor(255, 102, 102, 255);

	const double countKey = 10;
	bool isSizeChange;
	int changeCounter;
	bool changeDirection;
	void sizeChange(bool direction);
};

#endif __MUSIC_CARD_H_