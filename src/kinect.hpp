//
//  kinect.hpp
//  suisuiduck_VJ
//
//  Created by 諸星智也 on 2019/08/31.
//

#pragma once

#include "ofxState.h"
#include "SharedData.h"

#include "ofxKinect.h"
#include "ofxGui.h"


class kinect : public itg::ofxState<SharedData>{
public:
    void setup();
    void update();
    void draw();

//    void keyReleased(int key);
    string getName();

    
    ofxKinect kinect; //Kinectインスタンス
    ofImage kinectImage; // Kinectカメラ映像
    ofImage depthImage; // Kinect深度映像
    ofEasyCam cam;          // カメラ (デバッグ)
    
    // GUI FOR CV
    ofxPanel gui;
    
    
    // GUI FOR pointcloud
    ofxFloatSlider positionZ;
    ofxFloatSlider scaleZ;
    ofxFloatSlider pointSize;
    ofxIntSlider step;
};

