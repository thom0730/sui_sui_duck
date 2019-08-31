#pragma once

#include "ofxState.h"
#include "SharedData.h"
#include "ofxRollingCam.h"
#include "ofxPostGlitch.h"
#include "ofxAssimpModelLoader.h"


#define NUM_BILLBOARDS 40000


class model : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();
    string getName();
    
    
    ofCamera camera;
    ofEasyCam cam;
    ofxAssimpModelLoader mAssimpModelLoader;
    string model_path;
    
    //RollingCam
    ofxRollingCam rollCam;
    
    //Glitch
    ofxPostGlitch postGlitch;
    ofFbo buffer;
};

