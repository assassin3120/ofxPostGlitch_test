#include "stateA.h"
#define NUM_OF_POLYGONS 5

//--------------------------------------------------------------
void stateA::setup(){
    ofSetCircleResolution(100); //円を滑らかにするぜっていう宣言
    
    ofEnableDepthTest(); //深度を使うぜっていう宣言
    ofEnableAlphaBlending();
    //ofBlendMode(OF_BLENDMODE_ALPHA);
    
    for (int i = 0; i < NUM_OF_POLYGONS; i++) {
        polygons.push_back(new polygon3d);
    }
    //ヘッダーファイルで書いたdrawClassを呼んだ
    
    light.enable(); //ライトを使用可能にした
    light.setSpotlight(); //スポットライトに指定した
    light.setPosition(100, 100, 100); //ライトの位置を指定した
    light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2, 0.1)); //環境反射光の色
    light.setDiffuseColor(ofFloatColor(0.5, 0.5, 0.5)); //拡散反射光の色
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0)); //鏡面反射光の色
    bDrawLenna = false;
    bShowHelp  = true;
    
    myFbo.allocate(1024, 768);
    myGlitch.setup(&myFbo);
    
    lenna.loadImage("a.png");
    
}
//--------------------------------------------------------------
void stateA::update(){
    myFbo.begin();
    ofClear(0, 0, 0, 255);
    if (!bDrawLenna){
        Ecam.begin();
        
        for (int i = 0;i < 100;i++){
            if		(i % 5 == 0)ofSetColor(50 , 255, 100);
            else if (i % 9 == 0)ofSetColor(255, 50, 100);
            else				ofSetColor(255, 255, 255);
            
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
            Ecam.begin();
            cam.setPosition(1000, 200, 100);
            cam.lookAt(ofVec3f(100, 100, 100));
            for (int i = 0; i < NUM_OF_POLYGONS; i++) {
                //ofClear(0, 0, 0, 255);
                ofSetColor(255);
                polygons.at(i)->setPosition(4, 3, i*100);
                polygons.at(i)->draw();
                //setupで呼んだやつを書くぜっていう宣言
            }
        }
        Ecam.end();
    }else{
        ofSetColor(255);
        lenna.draw(0, 0);
    }
    myFbo.end();
}

//--------------------------------------------------------------
void stateA::draw(){
    
    ofBackgroundGradient(100, 0); //グラデーション
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    ofSetColor(255);
    myFbo.draw(0, 0);
    
     if (bShowHelp){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
    Ecam.begin();
    cam.setPosition(1000, 200, 100);
    cam.lookAt(ofVec3f(100, 100, 100));
    for (int i = 0; i < NUM_OF_POLYGONS; i++) {
        //ofClear(0, 0, 0, 255);
        ofSetColor(255);
        polygons.at(i)->setPosition(4, 3, i*100);
        polygons.at(i)->draw();
        //setupで呼んだやつを書くぜっていう宣言
    }
    Ecam.end();
    ofPopMatrix();
     }
}

//void stateA::drawBox(int interval){
//    関数にするべきか、Classで書くべきかを考える
    
//}

string stateA::getName(){
    return "stateA";
}

//--------------------------------------------------------------
void stateA::keyPressed(int key){
    if (key == 'b') {
        changeState("stateB");
    }
    
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, true);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, true);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, true);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, true);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, true);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, true);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, true);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, true);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, true);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, true);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, true);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, true);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, true);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, true);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, true);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, true);
    
    }

//--------------------------------------------------------------
void stateA::keyReleased(int key){
    if (key == '1') myGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE	, false);
    if (key == '2') myGlitch.setFx(OFXPOSTGLITCH_GLOW			, false);
    if (key == '3') myGlitch.setFx(OFXPOSTGLITCH_SHAKER			, false);
    if (key == '4') myGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER		, false);
    if (key == '5') myGlitch.setFx(OFXPOSTGLITCH_TWIST			, false);
    if (key == '6') myGlitch.setFx(OFXPOSTGLITCH_OUTLINE		, false);
    if (key == '7') myGlitch.setFx(OFXPOSTGLITCH_NOISE			, false);
    if (key == '8') myGlitch.setFx(OFXPOSTGLITCH_SLITSCAN		, false);
    if (key == '9') myGlitch.setFx(OFXPOSTGLITCH_SWELL			, false);
    if (key == '0') myGlitch.setFx(OFXPOSTGLITCH_INVERT			, false);
    
    if (key == 'q') myGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
    if (key == 'w') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE	, false);
    if (key == 'e') myGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE	, false);
    if (key == 'r') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE	, false);
    if (key == 't') myGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT	, false);
    if (key == 'y') myGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT	, false);
    if (key == 'u') myGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT	, false);

}

//--------------------------------------------------------------
void stateA::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void stateA::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateA::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateA::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void stateA::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void stateA::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void stateA::dragEvent(ofDragInfo dragInfo){
    
}
