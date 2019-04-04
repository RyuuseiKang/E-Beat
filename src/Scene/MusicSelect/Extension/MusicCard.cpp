//
//  KeyBeam.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/countKey19.
//

#include "MusicCard.h"

int cWidth, cHeight, aSize;
MusicCard::MusicCard() {
	// 오버레이

	patternOverlay.loadImage("Scene/MusicSelect/CardOverlay.png");
	albumImage.loadImage("MusicData/Yes or Yes/album.png");

	cWidth = normalCardWidth;
	cHeight = normalCardHeight;
	aSize = normalAlbumSize;

	patternOverlay.resize(cWidth, cHeight);
	albumImage.resize(aSize, aSize);
}

MusicCard::~MusicCard() {

}

void MusicCard::update() {
	if (isSizeChange)
		changeCounter--;
	else
		return;

	if (changeCounter <= 0)
		isSizeChange = false;
}

void MusicCard::draw(int x) {

	
	//ofDrawRectangle(19countKey / 2 - (cardWidth / 2), 1080 / 2 - (cardHeight / 2), cardWidth, cardHeight);
	

	double changeSizeWidth, changeSizeHeight, changeAlbumSize;
	double changePaddingAlbum, changePaddingBox;
	if (isSizeChange) {
			changeSizeWidth = ((-(1 / countKey) * (changeCounter - countKey) * (changeCounter - countKey)) + countKey) / countKey * (selectedCardWidth - normalCardWidth);
			changeSizeHeight = ((-(1 / countKey) * (changeCounter - countKey) * (changeCounter - countKey)) + countKey) / countKey * (selectedCardHeight - normalCardHeight);
			changeAlbumSize = ((-(1 / countKey) * (changeCounter - countKey) * (changeCounter - countKey)) + countKey) / countKey * (selectedAlbumSize - normalAlbumSize);
			changePaddingBox = ((-(1 / countKey) * (changeCounter - countKey) * (changeCounter - countKey)) + countKey) / countKey * (normalBoxPadding - selectedBoxPadding);
			changePaddingAlbum = ((-(1 / countKey) * (changeCounter - countKey) * (changeCounter - countKey)) + countKey) / countKey * (normalAlbumPadding - selectedAlbumPadding);
	}

	ofSetColor(expertColor);
	if (changeDirection) {
		ofDrawRectangle(x, selectedBoxPadding + changePaddingBox, cWidth - changeSizeWidth, cHeight - changeSizeHeight);
		ofSetColor(255, 255, 255, 255);

		patternOverlay.draw(x, selectedBoxPadding + changePaddingBox, cWidth - changeSizeWidth, cHeight - changeSizeHeight);
		albumImage.draw(x + (cWidth - changeSizeWidth) / 2 - ((selectedAlbumSize - changeAlbumSize) / 2), selectedBoxPadding + selectedAlbumPadding + changePaddingBox + changePaddingAlbum, selectedAlbumSize - changeAlbumSize, selectedAlbumSize - changeAlbumSize);
	}
	else {
		ofDrawRectangle(x, normalBoxPadding - changePaddingBox, cWidth + changeSizeWidth, cHeight + changeSizeHeight);
		ofSetColor(255, 255, 255, 255);

		patternOverlay.draw(x, normalBoxPadding - changePaddingBox, cWidth + changeSizeWidth, cHeight + changeSizeHeight);
		albumImage.draw(x + (cWidth + changeSizeWidth) / 2 - ((normalAlbumSize + changeAlbumSize) / 2), normalBoxPadding + normalAlbumPadding - changePaddingBox - changePaddingAlbum, normalAlbumSize + changeAlbumSize, normalAlbumSize + changeAlbumSize);
	}

}

void MusicCard::Select() {
	sizeChange(true);

	cWidth = selectedCardWidth;
	cHeight = selectedCardHeight;
	aSize = selectedAlbumSize;
}

void MusicCard::Deselect() {
	sizeChange(false);

	cWidth = normalCardWidth;
	cHeight = normalCardHeight;
	aSize = normalAlbumSize;
}

void MusicCard::setMusicData(string _musicName, string _artistName, double maxScore) {

}

void MusicCard::sizeChange(bool direction) {
	isSizeChange = true;
	changeCounter = countKey;
	changeDirection = direction;
}