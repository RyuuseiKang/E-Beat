//
//  MusicSelect.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 20/03/2019.
//

#include "MusicSelect.hpp"

MusicSelect::MusicSelect() {
	musicLinerBackRect.loadImage("Scene/MusicSelect/BackRect.png");
	musicLinerBackRect.resize(1920, 1080);

	// 하단 버튼
	bottombuttonsRect.loadImage("Scene/MusicSelect/BottomButtons.png");
	bottombuttonsRect.resize(1920, 1080);
	
	// 하단 키빔
	button[0].setCount(0);
	button[0].setColor("Green");
	button[1].setCount(1);
	button[1].setColor("Green");
	button[2].setCount(2);
	button[2].setColor("White");
	button[3].setCount(3);
	button[3].setColor("Red");

	bgaPlayer.load("MusicData/Yes or Yes/BGA.mp4");
	bgaPlayer.play();

	slider.setMaxCount(maxCountMusic);
	musicList.setMaxCount(maxCountMusic);
	musicList.setPosition(0);
}

MusicSelect::MusicSelect(FileSystem *file){
    maxCountMusic = file->getMusicCount();
    MusicSelect();
}

MusicSelect::~MusicSelect() {

}

void MusicSelect::update(bool keys[256]) {
	// 키 갱신
	if (keys['d'] == true)
		button[0].Active();

	if (keys['f'] == true)
		button[1].Active();

	if (keys['j'] == true)
		button[2].Active();

	if (keys['k'] == true)
		button[3].Active();

	// BGA 갱신
	bgaPlayer.update();

	// 노래 리스트 갱신
	musicList.update();
	
	// 키빔 갱신
	button[0].update();
	button[1].update();
	button[2].update();
	button[3].update();

	//if (keys['a'])
		//cout << backBGAPlayer.getCurrentFrame() << endl;

}

void MusicSelect::draw(){
	// BGA 부분 처리
	bgaPlayer.draw(-265, -150, 2450, 1380);
	
	// 하단 버튼 키빔
	button[0].draw();
	button[1].draw();
	button[2].draw();
	button[3].draw();

	// 백그라운드 Rect
	musicLinerBackRect.draw(0, 0);


	// 하단 버튼 인디케이터
	bottombuttonsRect.draw(0, 0);

	
	// 하단 슬라이더
	slider.draw();
	
	// 카드 카메라 이동
	musicList.draw();

	// 상태 표시
	ofDrawBitmapStringHighlight("MusicSelect Scene", 20, 20);
	//ofDrawBitmapStringHighlight("Amount : " + to_string(mouseX), 20, 40);
	//ofDrawBitmapStringHighlight("Iterations : " + to_string(mouseY), 20, 60);
	

	// 흰색으로 설정을 왜하느냐 묻는다면 그것은 수련이 부족한 것
	ofSetColor(255, 255, 255, 255);
}

void MusicSelect::keyPressed(int key) {
	if (key == 'd') {
		p--;
		if (p < 0) {
			p = 0;
			return;
		}
		musicList.setPosition(p);
		slider.setPosition(p);
	}
		
	if (key == 'f') {
		p++;
		if (p >= maxCountMusic) {
			p = maxCountMusic - 1;
			return;
		}
		musicList.setPosition(p);
		slider.setPosition(p);
	}
		
	if (key == 'w') {
		m++;
	}

	if (key == 's') {
		m--;
	}
			
}

void MusicSelect::keyReleased(int key) {

}
