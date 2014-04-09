//
//  TextDisplay.h
//  vector_pi_video
//
//  Created by bdorse on 4/5/14.
//
//

#ifndef vector_pi_video_TextDisplay_h
#define vector_pi_video_TextDisplay_h
#include "ofMain.h"

class TextDisplay {
   
public:
    
    TextDisplay(){};
    TextDisplay(const std::string& text,
                const ofRectangle& bound,
                const ofColor& highlightColor);
    
    void update();
    void draw();
    void restart(const std::string& text);
    void next();
    bool isFinished();
    bool hasScreenText();
    char getLastScreenChar();
    std::vector<std::string> getWords();
    
protected:
    
    int _charIndex;
    int _wordIndex;
    int _fontSize;
    float _fontHeight;
    float _boxY;
    bool _textFinished;
    std::string _text;
    std::vector<std::string> _words;
    std::string _screenText;
    ofColor _highlightColor;
    ofRectangle _textBox;
    ofRectangle _textBounds;
    ofRectangle _backgroundBox;
    ofTrueTypeFont _font;
    
};

#endif
