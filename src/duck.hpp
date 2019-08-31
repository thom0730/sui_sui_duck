#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "ofxRollingCam.h"
#include "ofxPostGlitch.h"
#include "ofxAssimpModelLoader.h"

#define NUM 800



class duck : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();
    string getName();
    
    
    ofxAssimpModelLoader model;
    ofLight light;
    
    ofVboMesh vbomesh;
    ofVec3f vec[NUM];
    
    //RollingCam
    ofxRollingCam rollCam;
    
    //Glitch
    ofxPostGlitch postGlitch;
    ofFbo buffer;
};


