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


class Box : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();
    
    string getName();
    
    ofBoxPrimitive box;  //立方体
    ofMesh mesh;
    ofLight light;
    
    //RollingCam
    ofxRollingCam rollCam;
    
    //Glitch
    ofxPostGlitch postGlitch;
    ofFbo buffer;
};



