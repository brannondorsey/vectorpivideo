#pragma once

#include "ofMain.h"
#include "TextDisplay.h"

class testApp : public ofBaseApp{

	public:
    
        int charIndex;
        int wordIndex;
        int fontSize;
        float fontHeight;
        bool textFinished;
        std::string text;
        std::vector<std::string> words;
        std::string renderedText;
        std::string screenText;
        ofRectangle textBox;
        ofRectangle textBounds;
        ofTrueTypeFont font;
        TextDisplay textDisplay;
    
		void setup();
		void update();
		void draw();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
