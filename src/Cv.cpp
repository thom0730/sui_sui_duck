//
//  WebCam.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "Cv.hpp"
using namespace ofxCv;
using namespace cv;
//--------------------------------------------------------------
void Cv::setup(){
    // CV初期設定
    camera.initGrabber(320, 240);
    
    // GUI
    gui.setup();
    gui.add(pyrScale.setup("pyrScale", .5, 0, 1));
    gui.add(levels.setup("levels", 4, 1, 8));
    gui.add(winsize.setup("levels", 8, 4, 64));
    gui.add(iterations.setup("iterations", 2, 1, 8));
    gui.add(polyN.setup("polyN", 7, 5, 10));
    gui.add(polySigma.setup("polySigma", 1.5, 1.1, 2));
    gui.add(OPTFLOW_FARNEBACK_GAUSSIAN.setup("OPTFLOW_FARNEBACK_GAUSSIAN", false));
    
    gui.add(useFarneback.setup("useFarneback", true));
    gui.add(winSize.setup("winSize", 32, 4, 64));
    gui.add(maxLevel.setup("maxLevel", 3, 0, 8));
    gui.add(levels.setup("maxFeatures", 200, 1, 1000));
    gui.add(qualityLevel.setup("levels", 0.01, 0.001, .02));
    gui.add(minDistance.setup("minDistance", 4, 1, 16));
    curFlow = &farneback;
}
void Cv::update(){
    camera.update();
    if(camera.isFrameNew()) {
        if(useFarneback) { // Farnebackの密なオプティカルフロー
            curFlow = &farneback;
            farneback.setPyramidScale(pyrScale);
            farneback.setNumLevels(levels);
            farneback.setWindowSize(winsize);
            farneback.setNumIterations(iterations);
            farneback.setPolyN(polyN);
            farneback.setPolySigma(polySigma);
            farneback.setUseGaussian(OPTFLOW_FARNEBACK_GAUSSIAN);
        } else { // 画像ピラミッドを利用した、疎なオプティカルフロー
            curFlow = &pyrLk;
            pyrLk.setMaxFeatures(maxFeatures);
            pyrLk.setQualityLevel(qualityLevel);
            pyrLk.setMinDistance(minDistance);
            pyrLk.setWindowSize(winSize);
            pyrLk.setMaxLevel(maxLevel);
        }
        // オプティカルフローを計算
        curFlow->calcOpticalFlow(camera);
    }
    
}

void Cv::draw(){
    ofBackground(0);
    
    ofSetColor(255);
    camera.draw(0,0,ofGetWidth(),ofGetHeight());
    curFlow->draw(0,0,ofGetWidth(),ofGetHeight());
    
    gui.draw();
}

string Cv::getName()
{
    return "Cv";
}
