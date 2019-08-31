//
//  model.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/31.
//

#include "model.hpp"
//--------------------------------------------------------------
void model::setup(){
    buffer.allocate(ofGetWidth(), ofGetHeight());
    postGlitch.setup(&buffer);
    
    model_path = "CIT.obj";
    mAssimpModelLoader.setScale(10, 10, 10);
    mAssimpModelLoader.loadModel(model_path);
    
}
void model::update(){
    mAssimpModelLoader.update();
    cam.lookAt(ofVec3f(0,0,0));
    cam.setPosition(500*cos(ofGetElapsedTimef()/10), 200, 500*sin(ofGetElapsedTimef()/10));
    
}
void model::draw(){
    buffer.begin();
    ofClear(0);
    cout << "cam position"<<cam.getPosition() << endl;
    //    ofBackground(0);
    //    ofSetColor(255,30);
    //    ofPushMatrix();
    //    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    //    cam.begin();
    //    ofRotateX(-90);
    //    ofSetLineWidth(1);
    //    mAssimpModelLoader.drawWireframe();  //モデルを描画
    //    cam.end();
    //    ofPopMatrix();
    
    
    ofSetColor(255,50);
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    cam.begin();
    ofRotateX(-180);
    ofSetLineWidth(1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(0.5 , 0x0101);
    mAssimpModelLoader.drawWireframe();  //モデルを描画
    glDisable(GL_LINE_STIPPLE);
    cam.end();
    ofPopMatrix();
    
    postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
    postGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
    if(getSharedData().FFT  > getSharedData().Threshold){
        postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
        postGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
//        rollCam.setRandomScale(0.5, 1.5);
//        rollCam.setRandomPos(270);
    }
    buffer.end();
    postGlitch.generateFx();
    buffer.draw(0,0);
}
string model::getName()
{
    return "model";
}



