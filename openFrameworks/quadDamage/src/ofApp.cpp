#include "ofApp.h"
#include "MouseEventController.h"

//--------------------------------------------------------------
void ofApp::setup(){
    MouseEventController::init();
    
    root = new BaseSprite();
    root->isRoot = true;
    root->name = "root";
    root->visible = true;
    
    // setup the filepaths
    // bk: update to load from JSON source
    
    string img1Path = "img1.jpg";
    string img2Path = "img2.jpg";
    string img3Path = "sample.mov";
    string vid1Path = "tricap.mp4";
    filenames.push_back(img1Path);
    filenames.push_back(img2Path);
    filenames.push_back(img3Path);
    filenames.push_back(vid1Path);
    
    // loop through and create the quad objects
    // bk: pass in the filename as third parameter
    // x, y, index, filepath
    for (int q = 0; q < NUM_QUADS; q++) {
        ofxQuad* newQuad;
        if (q == 0)
            newQuad = new ofxQuad(50, 50, q, filenames[0]);
        else if (q == 1)
            newQuad = new ofxQuad(400, 50, q, filenames[1]);
        else if (q == 2)
            newQuad = new ofxQuad(50, 400, q, filenames[2]);
        else if (q == 3)
            newQuad = new ofxQuad(300, 300, q, filenames[3]);
        
        newQuad->init();
        quads.push_back(newQuad);
        root->addChild(quads[q]);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Update mouse events
    MouseEventController::processEvents();
    
    // Update
    root->update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Clear our background
    ofBackground(127);
    
    // Draw
    root->draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    for (int q = 0; q < NUM_QUADS; q++) {
        quads[q]->selectedCorner = -1;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (int q = 0; q < NUM_QUADS; q++) {
        quads[q]->corners[quads[q]->selectedCorner].set(x-quads[q]->xpos,y-quads[q]->ypos);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    for (int q = 0; q < NUM_QUADS; q++) {
        quads[q]->selectedCorner = -1;
        for (int i=0; i<4; i++) {
            if (ofDist(quads[q]->corners[i].x, quads[q]->corners[i].y, x-quads[q]->xpos, y-quads[q]->ypos)<10) {
                quads[q]->selectedCorner = i;
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
