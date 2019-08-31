//
//  kinect.hpp
//  suisuiduck_VJ
//
//  Created by 諸星智也 on 2019/08/31.
//

#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "ofxRollingCam.h"
#include "ofxPostGlitch.h"


#define NUM_BILLBOARDS 40000


class Particle : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();

    string getName();
    
    
    ofImage texture;
    ofVbo billboardVbo;
    ofVec3f billboardVerts[NUM_BILLBOARDS];
    ofFloatColor billboardColor[NUM_BILLBOARDS];
    ofVec3f billboardVels[NUM_BILLBOARDS];
    
    //RollingCam
    ofxRollingCam rollCam;
    
    //Glitch
    ofxPostGlitch postGlitch;
    ofFbo buffer;
};


