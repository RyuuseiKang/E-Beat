//
//  KeyBeam.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 31/03/countKey19.
//

#include "MusicCard.hpp"

MusicCard::MusicCard() {
	// 오버레이

	patternOverlay.loadImage("Scene/MusicSelect/CardOverlay.png");
	albumImage.loadImage("MusicData/Yes or Yes/album.png");

	patternOverlay.resize(normalCardWidth, normalCardHeight);
	albumImage.resize(normalAlbumSize, normalAlbumSize);
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

void MusicCard::draw() {
	//ofDrawRectangle(19countKey / 2 - (cardWidth / 2), 1080 / 2 - (cardHeight / 2), cardWidth, cardHeight);
	
	double changeSizeWidth = 0, changeSizeHeight = 0, changeAlbumSize = 0;
	double changePaddingAlbum = 0, changePaddingBox = 0;
	double changeLeftPadding = 0;
	if (isSizeChange) {
		double pos = ((-(1 / countKey) * std::pow((changeCounter - countKey), 2)) + countKey) / countKey;


		changeSizeWidth = pos * (selectedCardWidth - normalCardWidth);
		changeSizeHeight = pos * (selectedCardHeight - normalCardHeight);
		changeAlbumSize = pos * (selectedAlbumSize - normalAlbumSize);
		
		changePaddingBox = pos * (normalBoxPadding - selectedBoxPadding);
		changePaddingAlbum = pos * (normalAlbumPadding - selectedAlbumPadding);

		changeLeftPadding = pos * (normalLeftPadding - selectedLeftPadding);
	}

	ofSetColor(expertColor);
	if(!isDirection)
		if (isSelected) {
			ofDrawRectangle(selectedLeftPadding + changeLeftPadding, selectedBoxPadding + changePaddingBox, selectedCardWidth - changeSizeWidth, selectedCardHeight - changeSizeHeight);
			ofSetColor(255, 255, 255, 255);

			patternOverlay.draw(selectedLeftPadding + changeLeftPadding, selectedBoxPadding + changePaddingBox, selectedCardWidth - changeSizeWidth, selectedCardHeight - changeSizeHeight);
			albumImage.draw(selectedLeftPadding + changeLeftPadding + (selectedCardWidth - changeSizeWidth) / 2 - ((selectedAlbumSize - changeAlbumSize) / 2), selectedBoxPadding + selectedAlbumPadding + changePaddingBox + changePaddingAlbum, selectedAlbumSize - changeAlbumSize, selectedAlbumSize - changeAlbumSize);
		}
		else {
			ofDrawRectangle(normalLeftPadding + (changeLeftPadding * 4), normalBoxPadding - changePaddingBox, normalCardWidth + changeSizeWidth, normalCardHeight + changeSizeHeight);
			ofSetColor(255, 255, 255, 255);

			patternOverlay.draw(normalLeftPadding + (changeLeftPadding * 4), normalBoxPadding - changePaddingBox, normalCardWidth + changeSizeWidth, normalCardHeight + changeSizeHeight);
			albumImage.draw(normalLeftPadding + (changeLeftPadding * 4) + (normalCardWidth + changeSizeWidth) / 2 - ((normalAlbumSize + changeAlbumSize) / 2), normalBoxPadding + normalAlbumPadding - changePaddingBox - changePaddingAlbum, normalAlbumSize + changeAlbumSize, normalAlbumSize + changeAlbumSize);
		}
	else
		if (isSelected) {
			ofDrawRectangle(selectedLeftPadding - (changeLeftPadding * 4), selectedBoxPadding + changePaddingBox, selectedCardWidth - changeSizeWidth, selectedCardHeight - changeSizeHeight);
			ofSetColor(255, 255, 255, 255);

			patternOverlay.draw(selectedLeftPadding - (changeLeftPadding * 4), selectedBoxPadding + changePaddingBox, selectedCardWidth - changeSizeWidth, selectedCardHeight - changeSizeHeight);
			albumImage.draw(selectedLeftPadding - (changeLeftPadding * 4) + (selectedCardWidth - changeSizeWidth) / 2 - ((selectedAlbumSize - changeAlbumSize) / 2), selectedBoxPadding + selectedAlbumPadding + changePaddingBox + changePaddingAlbum, selectedAlbumSize - changeAlbumSize, selectedAlbumSize - changeAlbumSize);
		}
		else {
			ofDrawRectangle(normalLeftPadding - changeLeftPadding, normalBoxPadding - changePaddingBox, normalCardWidth + changeSizeWidth, normalCardHeight + changeSizeHeight);
			ofSetColor(255, 255, 255, 255);

			patternOverlay.draw(normalLeftPadding - changeLeftPadding, normalBoxPadding - changePaddingBox, normalCardWidth + changeSizeWidth, normalCardHeight + changeSizeHeight);
			albumImage.draw(normalLeftPadding - changeLeftPadding + (normalCardWidth + changeSizeWidth) / 2 - ((normalAlbumSize + changeAlbumSize) / 2), normalBoxPadding + normalAlbumPadding - changePaddingBox - changePaddingAlbum, normalAlbumSize + changeAlbumSize, normalAlbumSize + changeAlbumSize);
		}
}

void MusicCard::Select(bool direction) {
	sizeChange(true, direction);
}

void MusicCard::Deselect(bool direction) {
	sizeChange(false, direction);
}

void MusicCard::setMetaData(MusicMeta _metaData) {
	bga = _metaData.bga;
	bgaEndPos = _metaData.bgaEndPos;
	bgaStartPos = _metaData.bgaStartPos;
	jacket = _metaData.jacket;
	musicPath = _metaData.musicPath;
	path = _metaData.path;
	title = _metaData.title;
	artist = _metaData.artist;
	
	albumImage.loadImage(jacket);
	albumImage.resize(normalAlbumSize, normalAlbumSize);
}

void MusicCard::sizeChange(bool selected, bool direction) {
	isSizeChange = true;
	changeCounter = countKey;
	isSelected = selected;
	isDirection = direction;
}