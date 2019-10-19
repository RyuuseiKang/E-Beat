//
//  Result.cpp
//  E-Beat
//
//  Created by 一ノ瀬琉聖 on 17/10/2019.
//

#include "Result.hpp"

Result::Result() {

}

Result::~Result() {

}

void Result::update(bool keys[256]) {
	dataViewer->update();
}

void Result::draw() {
	dataViewer->draw();
}

void Result::keyPressed(int key) {

}

void Result::keyReleased(int key) {

}

void Result::setDataViewer(DataViewer * _dataViewer) {
	dataViewer = _dataViewer;
}

bool Result::isReady() {
	return isResultEnd;
}

