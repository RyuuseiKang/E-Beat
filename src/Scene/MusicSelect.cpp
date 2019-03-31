//
//  MusicSelect.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "MusicSelect.h"

MusicSelect::MusicSelect() {
	musicLinerBackRect.loadImage("Scene/MusicSelect/BackRect.png");
	musicLinerBackRect.resize(1920, 1080);
	
	bgaPlayer.load("MusicData/Yes or Yes/BGA.mp4");
	bgaPlayer.play();
}

MusicSelect::~MusicSelect() {

}

void MusicSelect::update(bool keys[256]) {
	// BGA 갱신
	bgaPlayer.update();

	//if (keys['a'])
		//cout << backBGAPlayer.getCurrentFrame() << endl;

}

void MusicSelect::draw(){
	// BGA 부분 처리
	bgaPlayer.draw(-265, -150, 2450, 1380);
	

	// 백그라운드 Rect
	musicLinerBackRect.draw(0, 0);

	
	// 하단 슬라이더
	slider.draw();
	

	// 상태 표시
	ofDrawBitmapStringHighlight("Initialize Scene", 20, 20);
	//ofDrawBitmapStringHighlight("Amount : " + to_string(mouseX), 20, 40);
	//ofDrawBitmapStringHighlight("Iterations : " + to_string(mouseY), 20, 60);
	

	// 흰색으로 설정을 왜하느냐 묻는다면 그것은 수련이 부족한 것
	ofSetColor(255, 255, 255, 255);
}

void MusicSelect::keyPressed(int key) {
	if (key == 'a')
		p--;

	if (key == 'd')
		p++;

	if (key == 'w')
		m++;

	if (key == 's')
		m--;

	slider.setMaxCount(m);
	slider.setPosition(p);
}

void MusicSelect::keyReleased(int key) {

}
