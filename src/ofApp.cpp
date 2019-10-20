#include "ofApp.h"
#include "Scene.hpp"

using namespace std;
bool keys[256];

// Scenes
InitializeScene *initializeScene;
EntryScene *entryScene;
MusicSelect *musicSelect;
Ingame *ingame;
Result *result;
FileSystem file;

Scene scene;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(120);
	ofSetVerticalSync(false);

	file.Initialize();

	initializeScene = new InitializeScene();
    entryScene = new EntryScene();
    musicSelect = new MusicSelect(&file);
	ingame = new Ingame(&file);
	result = new Result();

	scene = MUSIC_SELECT;
}

//--------------------------------------------------------------
void ofApp::update(){
    
	switch (scene) {
	case INITIALIZE:
		initializeScene->update(keys);
		break;

	case ENTRY:
        entryScene->update(keys);
		if (entryScene->isReady()) {
			scene = MUSIC_SELECT;
			//ingame->readyMusic();
		}
		break;

	case MUSIC_SELECT:
        musicSelect->update(keys);
		if (musicSelect->isReady()) {
			scene = INGAME;
			musicSelect->readyIngame();
			ingame->readyMusic();
		}
		break;

	case INGAME:
		ingame->update(keys);
		if (ingame->isReady()) {
			scene = RESULT;
			ingame->readyResult();
			result->setDataViewer(ingame->getDataViewer());
			//result->setData();
		}
		break;

	case RESULT:
		result->update(keys);
		break;

	default:
		break;
	}

    // if(keys['q'])
    //     player.play();
    // 
    // if(keys['a'])
    //     player.setPositionMS(player.getPositionMS() - 2);
    // 
    // if(keys['d'])
    //     player.setPositionMS(player.getPositionMS() + 2);
    // 
	// if (keys['w']) 
	// 	player.setVolume(player.getVolume() + 0.0005f);
	// 
	// if (keys['s']) 
	// 	player.setVolume(player.getVolume() - 0.0005f);
	// 
    // if(keys['e'])
    //     player.setPaused(player.isPlaying());
    // 
    // if(keys['r'])
    //     player.setPaused(false);
    
    if(keys['0'])
        scene = INGAME;
    if(keys['9'])
        scene = MUSIC_SELECT;

	nFps = ofGetFrameRate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch (scene) {
	case INITIALIZE:
		initializeScene->draw();
		break;

	case ENTRY:
        entryScene->draw();
		break;

	case MUSIC_SELECT:
        musicSelect->draw();
		break;

	case INGAME:
		ingame->draw();
		break;

	case RESULT:
		result->draw();
		break;

	default:
		break;
	}

    // ofDrawBitmapStringHighlight("isPlaying : " + to_string(player.isPlaying()), 20, 20);
    // ofDrawBitmapStringHighlight("POSITION : " + to_string(player.getPositionMS()), 20, 40);
	// ofDrawBitmapStringHighlight("VOLUME : " + to_string(player.getVolume()), 20, 60);
	ofDrawBitmapStringHighlight("fps: " + to_string(nFps), 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keys[key] = true;

	switch (scene) {
	case INITIALIZE:
		initializeScene->keyPressed(key);
		break;

	case ENTRY:
		entryScene->keyPressed(key);
		break;

	case MUSIC_SELECT:
		musicSelect->keyPressed(key);
		break;

	case INGAME:
		ingame->keyPressed(key);
		break;

	case RESULT:
		result->keyPressed(key);
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keys[key] = false;

	if(key == '0') scene = INGAME;
	if(key == '9') scene = MUSIC_SELECT;

	switch (scene) {
	case INITIALIZE:
		initializeScene->keyReleased(key);
		break;

	case ENTRY:
		entryScene->keyReleased(key);
		break;

	case MUSIC_SELECT:
		musicSelect->keyReleased(key);
		break;

	case INGAME:
		ingame->keyReleased(key);
		break;

	case RESULT:
		result->keyReleased(key);
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
