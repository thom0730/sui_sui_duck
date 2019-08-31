#include "ofApp.h"
#include "kinect.hpp"
#include "Particle.hpp"
#include "model.hpp"
#include "duck.hpp"
#include "Cv.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofToggleFullscreen();
	
	// initialise state machine

    stateMachine.addState<kinect>();
    stateMachine.addState<model>();
    stateMachine.addState<Particle>();
    stateMachine.addState<duck>();
    stateMachine.addState<Cv>();
	stateMachine.changeState("kinect");
    
    receiver.setup(PORT);
    
    stateMachine.getSharedData().Threshold = 0.7;
}


//--------------------------------------------------------------
void ofApp::update(){
    // OSCの個数分繰り返す
    int index = 0;
    while(receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string value = m.getArgAsString(index);
        // msg += "getAddress: " + m.getAddress() + "\n";
        // msg += "getArgAsString " + ofToString(index) + ": " + value + "\n";
        
        if( index == 0 ){
            getFFT = ofMap( ofToFloat( m.getArgAsString(index) ), -90, 0, 0, 1 );
        }
        index++;
    }
    stateMachine.getSharedData().FFT = getFFT;
    cout << "ofApp = " << getFFT << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        stateMachine.changeState("kinect");
    }
    if (key == '2') {
        stateMachine.changeState("Particle");
    }
    if (key == '3') {
        stateMachine.changeState("model");
    }
    if (key == '4') {
        stateMachine.changeState("duck");
    }
    if (key == '5') {
        stateMachine.changeState("Cv");
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
