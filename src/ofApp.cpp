#include "ofApp.h"

using namespace std;
bool keys[256];
ofSoundPlayer player;

//--------------------------------------------------------------
void ofApp::setup(){
    player.setMultiPlay(true);
    player.load("Rooftop.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){
    if(keys['q'])
        player.play();
    
    if(keys['r'])
        player.setPositionMS(player.getPositionMS() - 2);
    
    if(keys['t'])
        player.setPositionMS(player.getPositionMS() + 2);
    
    if(keys['e'])
        player.setPaused(player.isPlaying());
    
    if(keys['f'])
        player.setPaused(false);
    
    cout << "music Position : " << player.getPositionMS() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapStringHighlight("isPlaying : " + to_string(player.isPlaying()), 20, 20);
    ofDrawBitmapStringHighlight("POSITION : " + to_string(player.getPositionMS()), 20, 40);
    
    if(keys['r'])
        ofDrawBitmapStringHighlight("<<", 20, 60);
    
    if(keys['t'])
        ofDrawBitmapStringHighlight(">>", 20, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << "KeyPressed : " << key << endl;
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
