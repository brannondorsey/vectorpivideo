#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    charIndex = 0;
    wordIndex = 0;
    textFinished = false;
    fontSize = 32;
    font.loadFont("fonts/Arial.ttf", fontSize);
    
    ofBuffer buffer = ofBufferFromFile("texts/gatsby.txt");
    text = buffer.getText();
    
    ofStringReplace(text, "\n\n", " ");
    ofStringReplace(text, "\n", " ");
    
    words = ofSplitString(text, " ");
    textBox = ofRectangle(100, ofGetHeight() - 120, ofGetWidth() - 200, 50);
    
    cout<<"Number of words: "<<words.size()<<endl;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (wordIndex >= words.size() &&
        charIndex >= words[words.size() - 1].length()) {
        textFinished = true;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
//    ofNoFill();
//    ofRect(textBox);
//    ofFill();
//    
//    ofNoFill();
//    ofSetColor(255, 0, 0);
//    ofRect(textBounds);
//    ofFill();
    
    // animate a new letter
    if (ofGetFrameNum() % 5 == 0 &&
        !textFinished) {
        
        std::string word = words[wordIndex];
        
        if (charIndex == word.length()){
            screenText += " ";
            charIndex = 0;
            
            if (wordIndex < words.size() - 1){
                wordIndex++;
                word = words[wordIndex];
                cout<<word<<endl;
            } else textFinished = true;
        }
    
        int lastSpace = screenText.find_last_of(" ");
        std::string temp = screenText.substr(0, lastSpace) + " " + word;
        cout<<temp<<endl;
        textBounds = font.getStringBoundingBox(temp, textBox.x, textBox.y);
        
        cout<<textBounds.width<<endl;
        cout<<textBox.width<<endl;
        
        if (textBounds.width >= textBox.width) {
            cout<<"fired"<<endl;
            screenText = "";
        }
        
        char character = word[charIndex];
        
        if (!textFinished) {
            screenText += character;
            charIndex++;
        }
    }
    
    ofSetColor(0);
    font.drawString(screenText, textBox.x, textBox.y + textBox.height/2 + fontSize/2);
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
