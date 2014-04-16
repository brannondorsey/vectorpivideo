#pragma once

#include "ofMain.h"
#include "TextDisplay.h"
#include "Word.h"
#include "Animation.h"

class testApp : public ofBaseApp{

	public:
    
        int totalWords;
        bool fullSpeed;
        bool showStats;
        ofRectangle textBox;
        TextDisplay textDisplay;
        Animation animation;
    
		void setup();
		void update();
		void draw();
        void toggleFrameRate();
        void restart();
    
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
