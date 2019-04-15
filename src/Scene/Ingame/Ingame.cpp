//
//  Ingame.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 15/04/2019.
//

#include "Ingame.hpp"

Ingame::Ingame() {

}

Ingame::Ingame(FileSystem* _file) {
	backLane.loadImage("Scene/Ingame/BackLane.png");
	backLane.resize(1920, 1080);
}

Ingame::~Ingame() {

}

void Ingame::update(bool keys[256]) {

}

void Ingame::draw() {
	backLane.draw(0, 0);

}

void Ingame::keyPressed(int key) {

}