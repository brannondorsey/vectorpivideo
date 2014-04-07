//
//  TextDisplay.cpp
//  vector_pi_video
//
//  Created by bdorse on 4/5/14.
//
//

#include "TextDisplay.h"

TextDisplay::TextDisplay(const std::string& text, const ofRectangle& bound){
    
    _textBox = bound;
    _fontSize = 24;
    _font.loadFont("fonts/Arial.ttf", _fontSize);
    _font.setEncoding(OF_ENCODING_UTF8);
    restart(text);
}

void TextDisplay::update(){
    
    if (_wordIndex >= _words.size() &&
        _charIndex >= _words[_words.size() - 1].length()) {
        _textFinished = true;
    }
}

void TextDisplay::draw(){
    
    ofSetColor(0);
    _font.drawString(_screenText, _textBox.x, _textBox.y + _textBox.height/2 + _fontSize/2);
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

char TextDisplay::next() {
    
    std::string word = _words[_wordIndex];
    if (word == "") {
        _wordIndex++;
        word = _words[_wordIndex];
    }
    
    if (_charIndex == word.length()){
        _screenText += " ";
        _charIndex = 0;
        
        if (_wordIndex < _words.size() - 1){
            _wordIndex++;
            word = _words[_wordIndex];
        } else _textFinished = true;
    }
    
    int lastSpace = _screenText.find_last_of(" ");
    std::string temp = _screenText.substr(0, lastSpace) + " " + word;
    _textBounds = _font.getStringBoundingBox(temp, _textBox.x, _textBox.y);
    
    if (_textBounds.width >= _textBox.width) {
        _screenText = "";
    }
    
    char character = word[_charIndex];
    
    if (!_textFinished) {
        _screenText += character;
        _charIndex++;
    }
    
    return character;
}

bool TextDisplay::isFinished(){
    return _textFinished;
}

std::vector<std::string> TextDisplay::getWords() {
    return _words;
}
