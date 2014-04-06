#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    
    ofBuffer buffer = ofBufferFromFile("texts/gatsby.txt");
    text = buffer.getText();
    
    ofRectangle textBox(100, ofGetHeight() - 120, ofGetWidth() - 200, 50);
    textDisplay = TextDisplay(text, textBox);
    
}

//--------------------------------------------------------------
void testApp::update(){
    textDisplay.update();
    if (textDisplay.isFinished()) {
        textDisplay.restart("I just restarted.");
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (ofGetFrameNum() % 5 == 0 &&
        !textDisplay.isFinished()) {
        textDisplay.next();
    }
    
    textDisplay.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
