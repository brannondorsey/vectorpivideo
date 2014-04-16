//
//  Test.cpp
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#include "Word.h"

Word::Word(const std::string& word,
           const ofVec2f& start,
           float rotation,
           float angleIncrement,
           const std::string& characters):
_lineWidth(2),
_lineLength(35),
_circleWidth(7),
_word(word),
_characters(characters),
_angleIncrement(angleIncrement),
_angleInDegrees(0),
_polyline(ofPolyline()),
_angleSum(rotation),
_center(start),
_isBBDirty(true),
_BB(ofRectangle())
{

    for (int i = 0; i < _word.length(); i++) {
        
        int index = _characters.find(_word[i]);
        if (index != -1) {
            _angleInDegrees = (index + 1) * _angleIncrement;
            _angles.push_back(_angleInDegrees);
        }
    }

    _polyline.addVertex(start);
    
    for (int i = 0; i < _angles.size(); i++) {
        _angleSum += _angles[i];
        _center += _getCartesian(_angleSum);
        _polyline.addVertex(_center);
    }

    _isBBDirty = true;
}

void Word::draw(){

    ofSetLineWidth(_lineWidth);
    ofFill();
    ofCircle(_polyline.getVertices().at(0), _circleWidth / 2);
    ofNoFill();
    _polyline.draw();
}

void Word::addCharacter(const char& character){
    _characters += character;
    
    int index = _characters.find(character);
    if (index != -1) {
        _angleInDegrees = (index + 1) * _angleIncrement;
        _angles.push_back(_angleInDegrees);
        _angleSum += _angleInDegrees;
        _center += _getCartesian(_angleSum);
        _polyline.addVertex(_center);

        _isBBDirty = true;
    }
}

bool Word::onScreen(const ofVec2f& offset) const {
    ofRectangle screen(-offset.x, -offset.y, ofGetWidth(), ofGetHeight());
    return getBoundingBox().intersects(screen);
}

float Word::getBeginHeading(const float& rotation) const {
    if (_angles.size() > 0) return _angles[0] + rotation;
    else return rotation;
}

float Word::getEndHeading(const float& rotation) const {
    
    float angleSum = rotation;
    for (int i = 0; i < _angles.size(); i++) {
        angleSum += _angles[i];
    }
    return angleSum;
}

ofVec2f Word::getFirstVertex() const {
    return _polyline[0];
}

ofVec2f Word::getLastVertex() const {
    return _polyline[_polyline.size() - 1];
}

const ofRectangle& Word::getBoundingBox() const{
    if (_isBBDirty)
    {
        _BB = _polyline.getBoundingBox();
        _isBBDirty = false;
    }

    return _BB;
}

ofVec2f Word::_getCartesian(const float& angle) {

    float x = _lineLength * cos(ofDegToRad(_angleSum));
    float y = _lineLength * sin(ofDegToRad(_angleSum));
    return ofVec2f(x, y);
}
