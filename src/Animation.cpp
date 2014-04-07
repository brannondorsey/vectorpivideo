//
//  Animation.cpp
//  vector_pi_video
//
//  Created by bdorse on 4/6/14.
//
//

#include "Animation.h"

Animation::Animation(const float& angleIncrement, const std::string& characters){
    
    _angleIncrement = angleIncrement;
    _characters = characters;
    _speed = 1;
    _animating = false;
    
    _heading = 0;
    _space = 10;
    _lineLength = 24;
}

void Animation::update(){
    
    if (_animating) {
        if (_withinFinalFrameDistance()) {
            _words[_words.size() - 1].addCharacter(_currentCharacter);
            _animating = false;
        } else {
            _animating = true;
            _step();
        }
    }
    
    _currentPoint = _polarToCartesian(ofVec2f(_lineLength, _currentAngle));
}

void Animation::draw(){
    
    ofPushMatrix();
    ofTranslate(_currentPoint);
    ofVec2f wordsEnd = _polarToCartesian(ofVec2f( - _lineLength, - _currentAngle));
    ofLine(0, 0, wordsEnd.x, wordsEnd.y);
    ofPopMatrix();
    
    for (int i = 0; i < _words.size(); i++) {
        _words[i].draw();
    }
}

void Animation::addWord(){
    
        cout<<"added word"<<endl;
        Word lastWord = _words[_words.size() - 1];
        _heading = lastWord.getBeginHeading(_heading);
        
        ofVec2f offset(_space * cos(ofDegToRad(_heading)), _space * sin(ofDegToRad(_heading)));
        _center = lastWord.getFirstVertex() + offset;
        
        Word word = Word("", _center, _heading, _lineLength, _angleIncrement, _characters);
        _words.push_back(word);
}

void Animation::addCharacter(const char& character){
    
    if (_words.size() == 0) {
        _words.push_back(Word(ofToString(character), ofVec2f(0, 0), 0, _lineLength, _angleIncrement, _characters));
    }
    
    _currentCharacter = character;
    _connectionPoint = _words[_words.size() - 1].getLastVertex();
    _heading = _words[_words.size() - 1].getBeginHeading(_heading);
    _animating = true;
}

bool Animation::isReady(){
    return !_animating;
}

void Animation::_step(){
    _currentAngle += _speed;
}

// returns true if currentPoint will reach or pass
// targetPoint this frame
bool Animation::_withinFinalFrameDistance() {
    return abs(_targetAngle - _currentAngle) <= _speed;
}

ofVec2f Animation::_polarToCartesian(ofVec2f polar){
    return ofVec2f(polar.x * cos(ofDegToRad(polar.y)), polar.x * sin(ofDegToRad(polar.y)));
}