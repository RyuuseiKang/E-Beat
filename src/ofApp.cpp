#include "ofApp.h"
#include "Scene.h"

using namespace std;
bool keys[256];
ofSoundPlayer player;

// Scenes
InitializeScene *initializeScene;
EntryScene *entryScene;

Scene scene;

//--------------------------------------------------------------
void ofApp::setup(){
    player.setMultiPlay(true);
    player.load("Rooftop.mp3");
    
	initializeScene = new InitializeScene;
    entryScene = new EntryScene();
    // musicSelect = new MusicSelect();

	scene = INITIALIZE;
}

//--------------------------------------------------------------
void ofApp::update(){
    
	switch (scene) {
	case INITIALIZE:
		initializeScene->update();
		break;

	case ENTRY:
		break;

	case MUSIC_SELECT:
		break;

	case INGAME:
		break;

	default:
		break;
	}

    if(keys['q'])
        player.play();
    
    if(keys['a'])
        player.setPositionMS(player.getPositionMS() - 2);
    
    if(keys['d'])
        player.setPositionMS(player.getPositionMS() + 2);
    
	if (keys['w']) 
		player.setVolume(player.getVolume() + 0.0005f);

	if (keys['s']) 
		player.setVolume(player.getVolume() - 0.0005f);

    if(keys['e'])
        player.setPaused(player.isPlaying());
    
    if(keys['r'])
        player.setPaused(false);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	switch (scene) {
	case INITIALIZE:
		initializeScene->draw();
		break;

	case ENTRY:
		break;

	case MUSIC_SELECT:
		break;

	case INGAME:
		break;

	default:
		break;
	}

    // ofDrawBitmapStringHighlight("isPlaying : " + to_string(player.isPlaying()), 20, 20);
    // ofDrawBitmapStringHighlight("POSITION : " + to_string(player.getPositionMS()), 20, 40);
	// ofDrawBitmapStringHighlight("VOLUME : " + to_string(player.getVolume()), 20, 60);
    
    if(keys['a'])
        ofDrawBitmapStringHighlight("<<", 20, 80);
    
    if(keys['d'])
        ofDrawBitmapStringHighlight(">>", 20, 80);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keys[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keys[key] = false;
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
