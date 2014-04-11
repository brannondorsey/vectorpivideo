//
//  TextDisplay.cpp
//  vector_pi_video
//
//  Created by bdorse on 4/5/14.
//
//

#include "TextDisplay.h"

TextDisplay::TextDisplay(const std::string& text,
                         const ofRectangle& bound,
                         const ofColor& highlightColor):
    _highlightColor(highlightColor),
    _textBox(bound),
    _fontSize(24)
{
    _boxY = _textBox.y + _textBox.height/2 + _fontSize/2;
    _font.loadFont("fonts/Arial.ttf", _fontSize);
    _font.setEncoding(OF_ENCODING_UTF8);
    restart(text);
}

void TextDisplay::update(){
    
    if (_wordIndex >= _words.size() &&
        _charIndex >= _words[_words.size() - 1].length()) {
        _textFinished = true;
    }
    
    int verticalPadding = 3;
    int horizontalPadding = 10;
    ofRectangle screenTextBox = _font.getStringBoundingBox(_screenText, _textBox.x, _boxY);
    _backgroundBox = _textBox;
    _backgroundBox.y -= verticalPadding;
    _backgroundBox.x -= horizontalPadding;
    _backgroundBox.setWidth(screenTextBox.width + horizontalPadding * 2);
    _backgroundBox.setHeight(_backgroundBox.height + verticalPadding * 2);
}

void TextDisplay::draw(){

//    ofNoFill();
//    ofSetColor(0);
//    ofRect(_textBox);
//    ofFill();
    
    ofSetColor(255);
    ofFill();
    ofRect(_backgroundBox);
    
    std::string normalText;
    std::string highlightedText;
    
    int lastSpace = _screenText.find_last_of(' ');
    if (lastSpace != std::string::npos) {
        normalText = _screenText.substr(0, lastSpace) + ' ';
        highlightedText = _screenText.substr(lastSpace, _screenText.length());
        
        ofSetColor(0);
        _font.drawString(normalText, _textBox.x, _boxY);
    
    } else {
        normalText = "";
        highlightedText = _screenText;
    }
    
    if ((lastSpace != std::string::npos) ||
        (normalText == "")) {
        
        ofRectangle normalTextBounds = _font.getStringBoundingBox(normalText, _textBox.x, _boxY);
        float boxX = max(_textBox.x, normalTextBounds.x + normalTextBounds.width);
        ofSetColor(_highlightColor);
        
        _font.drawString(highlightedText, boxX, _boxY);
    }

    
}

void TextDisplay::restart(const std::string& text){
    
    _charIndex = 0;
    _wordIndex = 0;
    _textFinished = false;
    _text = text;
    
    ofStringReplace(_text, "\n\n", " ");
    ofStringReplace(_text, "\n", " ");
    
    _words = ofSplitString(_text, " ");
}

// this needs to always return the last character that was added
void TextDisplay::next() {
    
    std::string word = _words[_wordIndex];
    char character;
    
    if ((word == "") &&
        (_wordIndex < _words.size() - 1)) {
        _wordIndex++;
        word = _words[_wordIndex];
    }
    
    if (_charIndex == word.length()){
        character = ' ';
        _charIndex = 0;
        
        if (_wordIndex < _words.size() - 1){
            _wordIndex++;
            word = _words[_wordIndex];
        } else _textFinished = true;
    } else {
        
        character = word[_charIndex];
        _charIndex++;
    }
    
    
    int lastSpace = _screenText.find_last_of(' ');
    std::string temp = _screenText.substr(0, lastSpace) + ' ' + word;
    
    _textBounds = _font.getStringBoundingBox(temp, _textBox.x, _textBox.y);
    
    if (_textBounds.width >= _textBox.width) {
        _screenText = "";
    }
    
    if (!_textFinished) {
        _screenText += character;
    }
}

bool TextDisplay::isFinished(){
    return _textFinished;
}

bool TextDisplay::hasScreenText(){
    return _screenText.length() > 0;
}

char TextDisplay::getLastScreenChar() {
    return _screenText[_screenText.length() - 1];
}

std::vector<std::string> TextDisplay::getWords() {
    return _words;
}
