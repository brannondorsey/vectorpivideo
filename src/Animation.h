//
//  Animation.h
//  vector_pi_video
//
//  Created by bdorse on 4/6/14.
//
//

#ifndef vector_pi_video_Animation_h
#define vector_pi_video_Animation_h
#include "ofMain.h"
#include "Word.h"

class Animation{
    
public:
    
    Animation(){};
    Animation(const float& angleIncrement, const std::string& characters);
    
    void update();
    void draw();
    void addWord();
    void addCharacter(const char& character);
    bool isReady();
    
protected:
    
    bool _animating;
    int _lineLength;
    int _space;
    float _speed;
    float _angleIncrement;
    float _heading;
    float _targetAngle;
    float _currentAngle;
    char _currentCharacter;
    std::string _text;
    std::string _characters;
    std::vector<Word> _words;
    ofVec2f _start;
    ofVec2f _center;
    ofVec2f _connectionPoint;
    ofVec2f _currentPoint;
    ofVec2f _offset;
    
    void _step();
    bool _withinFinalFrameDistance();
    ofVec2f _polarToCartesian(ofVec2f polar);
};

#endif
