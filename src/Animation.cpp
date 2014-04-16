//
//  Animation.cpp
//  vector_pi_video
//
//  Created by bdorse on 4/6/14.
//
//

#include "Animation.h"

Animation::Animation(const float& angleIncrement,
                     const std::string& characters,
                     const ofColor& highlightColor,
                     const int& numWords):
_numWords(numWords),
_angleIncrement(angleIncrement),
_characters(characters),
_animating(false),
_highlightColor(highlightColor),
_speed(1),
_heading(0),
_space(10),
_start(ofVec2f(ofGetWidth()/2, ofGetHeight()/2)),
_center(_start){}

void Animation::update(){
    
        
    if (_animating) {
        if (_withinFinalFrameDistance()) {
            if (_words.size() > 0) _words[_words.size() - 1].addCharacter(_currentCharacter);
            _animating = false;
        } else {
            _animating = true;
            _step();
        }
    }
    
    if (_words.size() > 0) {
        _offset = (_start - _words[_words.size() - 1].getLastVertex());
    }
}

void Animation::draw(){
    
    ofSetColor(0);
    ofPushMatrix();
    
    if (_words.size() > 0) ofTranslate(_offset);
    int numWordsOnScreen = 0;
    for (int i = 0; i < _words.size(); i++) {
        
        if (i == _words.size() - 1) ofSetColor(_highlightColor);
        else ofSetColor(ofMap(i, 1, _numWords, 0, 230));
        
        if (_words[i].onScreen(_offset)) {
            _words[i].draw();
            numWordsOnScreen++;
        }
    }
    ofPopMatrix();
}

void Animation::addWord(){
    
        const Word& lastWord = _words[_words.size() - 1];
        _heading = lastWord.getEndHeading(_heading);
        ofVec2f offset(_space * cos(ofDegToRad(_heading)), _space * sin(ofDegToRad(_heading)));
        _center = lastWord.getLastVertex() + offset;

        Word word = Word("", _center, _heading, _angleIncrement, _characters);
        _words.push_back(word);
}

void Animation::addCharacter(const char& character){
    
    if (_words.size() == 0) {
        _words.push_back(Word(ofToString(character), ofVec2f(0, 0), _heading, _angleIncrement, _characters));
    }
    
    _currentCharacter = character;
    _connectionPoint = _words[_words.size() - 1].getLastVertex();
    _animating = true;
}

void Animation::restart(){
    _center = _start;
    _words.clear();
    _heading = 0;
}

bool Animation::isReady(){
    return !_animating;
}

const std::vector<Word>& Animation::getWords() const {
    return _words;
}

void Animation::_step(){
    _currentAngle += _speed;
}

// returns true if currentPoint will reach or pass
// targetPoint this frame
bool Animation::_withinFinalFrameDistance() {
//    return abs(_targetAngle - _currentAngle) <= _speed;
    return true;
}
