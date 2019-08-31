//
//  Box.cpp
//  suisuiduck
//
//  Created by 諸星智也 on 2019/08/30.
//

#include "Box.hpp"
//--------------------------------------------------------------
void Box::setup(){

    
    this->box.set(90);  //立方体の大きさ(100,100,100)
    this->box.setResolution(10);  //数値が大きいほど立方体を構成するメッシュの量が増える
    mesh = this->box.getMesh();  //boxの頂点情報群を取得しmeshに格納
    for(int i = 0; i < mesh.getVertices().size(); i++){  //各々の頂点に対して
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        ofVec3f loc = mesh.getVertices()[i] * ofRandom(0.5,1.0);  //位置情報を0.5~1.0で掛ける
        mesh.setVertex(i, loc);  //新しい位置情報としてセット
        //        ofColor c;
        //        c.setHsb(ofRandom(255),255,255);  //HSBで色定義
        //        mesh.setColor(i,c);  //新しい色情報としてセット
    }
    ofDisableArbTex();
    //this makes sure that the back of the model doesn't show through the front
    ofEnableDepthTest();
    light.enable();
    
    rollCam.setup();//rollCam's setup.
    rollCam.setCamSpeed(0.1);//rollCam's speed set;
    buffer.allocate(ofGetWidth(), ofGetHeight());
    postGlitch.setup(&buffer);
    
}
void Box::update(){
    rollCam.update();
    
    
}
void Box::draw(){
    buffer.begin();
    ofClear(0);
    rollCam.begin();
    mesh = this->box.getMesh();  //boxの頂点情報群を取得しmeshに格納
    for(int i = 0; i < mesh.getVertices().size(); i++){  //各々の頂点に対して
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        ofVec3f loc = mesh.getVertices()[i] *getSharedData().FFT*10* ofRandom(0.5,1.0);  //位置情報を0.5~1.0で掛ける
        mesh.setVertex(i, loc);  //新しい位置情報としてセット
    }
    mesh.drawWireframe();  //メッシュのフレームを描画
    // mesh.draw();  //メッシュのフレームを描画
    rollCam.end();
    buffer.end();
    
    postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
    postGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
    if(getSharedData().FFT  > getSharedData().Threshold){
        postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
        postGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
        rollCam.setRandomScale(0.5, 1.5);
        rollCam.setRandomPos(270);
    }
    buffer.end();
    postGlitch.generateFx();
    buffer.draw(0,0);
    
}
string Box::getName()
{
    return "Box";
}

