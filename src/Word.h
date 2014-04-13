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
         ofVec2f start,
         float rotation,
         float angleIncrement,
         const std::string& characters);
    
    void draw();
    void addCharacter(const char& character);
    void assignBox();
    bool hasBox();
    bool onScreen(ofVec2f offset);
    float getBeginHeading(const float& rotation);
    float getEndHeading(const float& rotation);
    ofVec2f getFirstVertex();
    ofVec2f getLastVertex();
    ofRectangle getBoundingBox();
    
    
protected:
    
    bool _needsUpdate;
    bool _hasBox;
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
    ofRectangle _box;
    
    ofVec2f _getCartesian(const float& angle);
    
};


#endif
