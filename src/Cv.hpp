//
//  kinect.hpp
//  suisuiduck_VJ
//
//  Created by 諸星智也 on 2019/08/31.
//

#pragma once

#include "ofxState.h"
#include "SharedData.h"

#include "ofxCv.h"
#include "ofxGui.h"


class Cv : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();
    
    //    void keyReleased(int key);
    string getName();
    
    ofVideoGrabber camera;
    ofxCv::FlowFarneback farneback;
    ofxCv::FlowPyrLK pyrLk;
    ofxCv::Flow* curFlow;
    
    ofxPanel gui;
    ofxFloatSlider pyrScale;
    ofxIntSlider levels;
    ofxIntSlider winsize;
    ofxIntSlider iterations;
    ofxIntSlider polyN;
    ofxFloatSlider polySigma;
    ofxToggle OPTFLOW_FARNEBACK_GAUSSIAN;
    
    ofxToggle useFarneback;
    ofxIntSlider winSize;
    ofxIntSlider maxLevel;
    
    ofxFloatSlider maxFeatures;
    ofxFloatSlider qualityLevel;
    ofxFloatSlider minDistance;
};


