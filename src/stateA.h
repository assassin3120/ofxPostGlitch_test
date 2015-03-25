#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
#include "ofxState.h"
#include "ofxSyphon.h"

class polygon3d {
    public :
    ofVec3f mPolygonPosition = ofVec3f(0, 0, 0);
    int mPolygonSize = 0; //object size
    int mPolygonType = 0; //object type
    polygon3d(){
        mPolygonPosition = ofVec3f(ofRandom(200));
        mPolygonSize = (50, 50, 50);
        mPolygonType = (0);
    };

~polygon3d(){};
void draw(){
    if (mPolygonType == 0) {
        ofBoxPrimitive box;
        box.set(mPolygonSize);
        box.setPosition(mPolygonPosition);
        box.draw();
    }
}
    void setPosition(int x ,int y,int z){
        mPolygonPosition=ofVec3f(x,y,z);
    }
};

class stateA : public itg::ofxState<>{
    
public:
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
    
    void drawBox(int interval);

    string getName();
    vector<polygon3d *> polygons;
    
    ofEasyCam Ecam;
    ofCamera cam;
    ofLight light;
    ofImage lenna;
    
    ofFbo myFbo;
    ofxPostGlitch myGlitch;
    bool			bDrawLenna;
    bool			bShowHelp;

};