#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    textCharIndex = 0;
    textFinished = false;
    fontSize = 32;
    font.loadFont("fonts/Arial.ttf", fontSize);
    text = "Render this to the screen one letter at a time. If there are more letters then don't do anything ok?";
    words = ofSplitString("test this", " ");
    textBox = ofRectangle(100, ofGetHeight() - 120, ofGetWidth() - 200, 50);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (textCharIndex >= text.size()) {
        textFinished = true;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofNoFill();
    ofRect(textBox);
    ofFill();
    
    // animate a new letter
    if (ofGetFrameNum() % 5 == 0 &&
        !textFinished) {
        
        std::string temp = screenText + text[textCharIndex];
        ofRectangle textBounds = font.getStringBoundingBox(temp, textBox.x, textBox.y);
        if (textBounds.width >= textBox.width) {
            
            cout<<"fired"<<endl;
            screenText = "";
        }
        
        screenText += text[textCharIndex];
        textCharIndex++;
    }
    
    ofSetColor(0);
    font.drawString(screenText, textBox.x, textBox.y + textBox.height/2 + fontSize/2);
}

//--------------------------------------------------------------
void testApp::resetScreenText() {
    screenText = "";
    
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
