#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofColor highlightColor(158, 25, 25);
    
    ofBuffer buffer = ofBufferFromFile("texts/gatsby.txt");
    text = buffer.getText();
    
        
    ofRectangle textBox(100, ofGetHeight() - 120, ofGetWidth() - 200, 50);
    textDisplay = TextDisplay(text, textBox);
    
    buffer = ofBufferFromFile("languages/english.txt");
    std::string characters = buffer.getText();
    float angleIncrement = float(360) / characters.length();
    // add 1) opacity over time and 2) colored word
    animation = Animation(angleIncrement,
                          characters,
                          highlightColor,
                          ofSplitString(text, " ").size());
}

//--------------------------------------------------------------
void testApp::update(){
    textDisplay.update();
    if (textDisplay.isFinished()) {
//        textDisplay.restart("I just restarted.");
    }
    animation.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if (ofGetFrameNum() % 8 == 0 &&
        animation.isReady() &&
        !textDisplay.isFinished()) {
        textDisplay.next();
        
        if (textDisplay.hasScreenText()) {
            char character = textDisplay.getLastScreenChar();
            if (character == ' ') animation.addWord();
            else animation.addCharacter(character);
        }
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    animation.draw();
    ofPopMatrix();
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
