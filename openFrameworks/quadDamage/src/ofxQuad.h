//
//  ofxQuad.h
//  quadDamage
//
//  Created by Bruno Kruse on 11/5/14.
//
//

#ifndef __quadDamage__ofxQuad__
#define __quadDamage__ofxQuad__
#include "ofMain.h"
#include "BaseSprite.h"

class BitmapSprite;

class ofxQuad : public BaseSprite{
    
public:
    
    void init();
    void update();
    void render();
    
    // sup quad
    void ofxQuadWarp(ofBaseHasTexture &tex, ofPoint lt, ofPoint rt, ofPoint rb, ofPoint lb, int rows, int cols);
    ofPoint ofxLerp(ofPoint start, ofPoint end, float amt);
    int ofxIndex(float x, float y, float w);
    
    ofVideoPlayer myPlayer;
    ofImage img;
    ofPoint corners[4];
    int selectedCorner;
    int index;
    string path;
    int xpos;
    int ypos;
    
    ofxQuad(int inXpos, int inYpos, int inIndex, string inPath);
    
private:
    
};

#endif
