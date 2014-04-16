//
//  Test.h
//  vectorPi_1
//
//  Created by bdorse on 3/27/14.
//
//

#ifndef vectorPi_1_Test_h
#define vectorPi_1_Test_h
#include "ofMain.h"

class Word{
public:
    
    ofPoint lastPoint;
    
    Word(const std::string& word,
         const ofVec2f& start,
         float rotation,
         float angleIncrement,
         const std::string& characters);
    
    void draw();
    void addCharacter(const char& character);
    bool onScreen(const ofVec2f& offset) const;
    float getBeginHeading(const float& rotation) const;
    float getEndHeading(const float& rotation) const;
    ofVec2f getFirstVertex() const;
    ofVec2f getLastVertex() const;
    const ofRectangle& getBoundingBox() const;
    
protected:
    
    int _lineLength;
    int _lineWidth;
    float _circleWidth;
    float _angleIncrement;
    float _angleInDegrees;
    float _angleSum;
    std::string _characters;
    std::string _word;
    std::vector<float> _angles;
    ofVec2f _center;
    ofPolyline _polyline;

    mutable bool _isBBDirty;
    mutable ofRectangle _BB;
    
    ofVec2f _getCartesian(const float& angle);
    
};


#endif
