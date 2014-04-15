#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofColor highlightColor(158, 25, 25);
    
    ofBuffer buffer = ofBufferFromFile("texts/one_flew_over.txt");
    std::string text = buffer.getText();
    _totalWords = ofSplitString(text, " ").size();
        
    ofRectangle textBox(100, ofGetHeight() - 120, ofGetWidth() - 200, 50);
    textDisplay = TextDisplay(text, textBox, highlightColor);
    
    buffer = ofBufferFromFile("languages/english.txt");
    std::string characters = buffer.getText();
    float angleIncrement = float(360) / characters.length();
    animation = Animation(angleIncrement,
                          characters,
                          highlightColor,
                          _totalWords);
    
    ofDirectory dir("frames");
    dir.remove(true);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (textDisplay.isFinished()) {
        textDisplay.restart();
        animation.restart();
    }
    
    textDisplay.update();
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
    
    animation.draw();
    textDisplay.draw();
    
//    // ofSaveFrame();
//    std::ostringstream localOSS;
//    localOSS << "frame_" << setw(6) << setfill('0') << ofToString(ofGetFrameNum()) << ".png";
//    ofSaveScreen("frames/" + localOSS.str());
    
    // stats
    ofSetColor(0);
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate(), 2)+" fps", 100, 15);
    float seconds = ofGetElapsedTimef();
    std::string measure("sec");
    if (seconds > 60) {
        measure = "min";
        seconds /= 60;
    }
    ofDrawBitmapStringHighlight(ofToString(seconds, 2) + " " + measure, 100, 30);
    float percent = (float(animation.getWords().size()) / float(_totalWords)) * 100;
    ofDrawBitmapStringHighlight(ofToString(percent, 2) + "% complete", 100, 45);
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
