//
//  ofxQuad.cpp
//  quadDamage
//
//  Created by Bruno Kruse on 11/5/14.
//
//

#include "ofxQuad.h"

ofxQuad::ofxQuad(int inXpos, int inYpos, int inIndex, string inPath)
{
    xpos = inXpos;
    ypos = inYpos;
    index = inIndex;
    path = inPath;
    cout << "creating new quad: " << inXpos << " , " << inYpos << " path: " << inPath << endl;
}

//--------------------------------------------------------------
void ofxQuad::init() {


    //img.loadImage("img" + ofToString(index) + ".jpg");
    
    myPlayer.loadMovie(path);
    myPlayer.play();
    //myPlayer.width = myPlayer.width / 3;
    //myPlayer.height = myPlayer.height / 3;
    
    selectedCorner = -1;
    
    //set corners
    corners[0].set(0,0);
    corners[1].set(myPlayer.width,0);
    corners[2].set(myPlayer.width,myPlayer.height);
    corners[3].set(0,myPlayer.height);

}

//--------------------------------------------------------------
void ofxQuad::update(){
    myPlayer.update(); // get all the new frames
}

//--------------------------------------------------------------
void ofxQuad::render(){
    
    
    //ofPushMatrix();
    ofTranslate(xpos, ypos);
    //ofScale(0.5f, 0.5f);
    ofxQuadWarp(myPlayer, corners[0], corners[1], corners[2], corners[3], 40, 40);
    for (int i=0; i<4; i++) {
        //cout << "corner: " << corners[i] << endl;
        ofCircle(corners[i],10);
    }
    //ofPopMatrix();
    
    
}

//--------------------------------------------------------------
ofPoint ofxQuad::ofxLerp(ofPoint start, ofPoint end, float amt) {
    return start + amt * (end - start);
}

//--------------------------------------------------------------
int ofxQuad::ofxIndex(float x, float y, float w) {
    return y*w+x;
}

//--------------------------------------------------------------
void ofxQuad::ofxQuadWarp(ofBaseHasTexture &tex, ofPoint lt, ofPoint rt, ofPoint rb, ofPoint lb, int rows, int cols) {
    float tw = tex.getTextureReference().getWidth();
    float th = tex.getTextureReference().getHeight();
    
    ofMesh mesh;
    
    for (int x=0; x<=cols; x++) {
        float f = float(x)/cols;
        ofPoint vTop(ofxLerp(lt,rt,f));
        ofPoint vBottom(ofxLerp(lb,rb,f));
        ofPoint tTop(ofxLerp(ofPoint(0,0),ofPoint(tw,0),f));
        ofPoint tBottom(ofxLerp(ofPoint(0,th),ofPoint(tw,th),f));
        
        for (int y=0; y<=rows; y++) {
            float f = float(y)/rows;
            ofPoint v = ofxLerp(vTop,vBottom,f);
            mesh.addVertex(v);
            mesh.addTexCoord(ofxLerp(tTop,tBottom,f));
        }
    }
    
    for (float y=0; y<rows; y++) {
        for (float x=0; x<cols; x++) {
            mesh.addTriangle(ofxIndex(x,y,cols+1), ofxIndex(x+1,y,cols+1), ofxIndex(x,y+1,cols+1));
            mesh.addTriangle(ofxIndex(x+1,y,cols+1), ofxIndex(x+1,y+1,cols+1), ofxIndex(x,y+1,cols+1));
        }
    }
    
    tex.getTextureReference().bind();
    mesh.draw();
    tex.getTextureReference().unbind();
    //mesh.drawVertices();
}
