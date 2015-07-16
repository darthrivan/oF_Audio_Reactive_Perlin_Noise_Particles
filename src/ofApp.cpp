/* This file is part of of_Audio_Reactive_Perlin_Noise_Particles.
 
 of_Audio_Reactive_Perlin_Noise_Particles is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 of_Audio_Reactive_Perlin_Noise_Particles is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with of_Audio_Reactive_Perlin_Noise_Particles.
 If not, see <http://www.gnu.org/licenses/>. */

#include "ofApp.h"
#include "Globals.h"
#include "ParticleSystem.h"
#include "ofGraphics.h"

extern Globals glob;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(255,255,255);
    
    // SOUND SETUP
    
    // 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	//soundStream.listDevices();
	
                                // if you want to set a different device id
	soundStream.setDeviceID(2); // bear in mind the device id corresponds to all audio
                                // devices, including  input-only and output-only devices.
	
	//int bufferSize = 256; //ORIGINAL BUFFER SIZE
    int bufferSize = 512;
	
	
	left.assign(bufferSize, glob.getPrecisionL());
	right.assign(bufferSize, glob.getPrecisionR());
	
	bufferCounter	= 0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    ps = ParticleSystem();

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::resetSoundLines(){
    ofPushMatrix();
        ofPushStyle();
            ofSetColor(255, 255, 255);
            ofRect((float)0,(float)0, glob.getV0_x()+5, glob.getHei()); //we add a 5 margin
        ofPopStyle();
    ofPopMatrix();
    ofPushMatrix();
        ofPushStyle();
            ofTranslate(glob.getWid() - glob.getV0_x()-5, 0.0);
            ofSetColor(255, 255, 255);
            ofRect((float)0,(float)0, glob.getV0_x()+5, glob.getHei()); //we add a 5 margin
        ofPopStyle();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    
    if (glob.getLinesMode() || glob.getJustDeactivated()) {
        resetSoundLines();
        glob.setJustDeactivated(false);
    }

    if (glob.getLinesMode()) {
        // draw the left channel:
        ofPushStyle();
            ofNoFill();
            ofPushMatrix();
                ofTranslate((glob.getV0_x()/2), 0, 0);
                
                //ofSetColor(245, 58, 135); // Uber Cool Pink
                ofSetColor(0, 0, 0);
                ofSetLineWidth(1);
                
                ofBeginShape();
                    for (unsigned int i = 0; i < left.size(); i++){
                        ofVertex(left[i]*180.0f, i*2);
                    }
                ofEndShape(false);
            
            ofPopMatrix();
        ofPopStyle();
        
        // draw the right channel:
        ofPushStyle();
            ofNoFill();
            ofPushMatrix();
                ofTranslate(glob.getWid() - (glob.getV0_x()/2), 0, 0);
                
                //ofSetColor(245, 58, 135); // Uber Cool Pink
                ofSetColor(0, 0, 0);
                ofSetLineWidth(2);
                
                ofBeginShape();
                    for (unsigned int i = 0; i < right.size(); i++){
                            ofVertex(right[i]*180.0f, i*2);
                    }
                ofEndShape(false);
        
            ofPopMatrix();
        ofPopStyle();
    }
    
    ofPushStyle();
        ofPushMatrix();
            ps.sysDraw();
        ofPopMatrix();
    ofPopStyle();
    
    glob.setElapsedFrames(glob.getElapsedFrames()+1);
}
//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2]*0.5;
        right[i] = input[i*2+1]*0.5;
        
        if ((input[i*2+1]*0.5 > glob.getPrecisionR()) || (input[i*2+1]*0.5 < (-1)*glob.getPrecisionR())){
            float pos_x = glob.getWid() - glob.getV0_x()-75, pos_y = (glob.getHei()/2)+ofRandom(-(glob.getHei()-50),(glob.getHei()-50));
            float vel_x = 0.0, vel_y = 0.0;
            ps.addParticle(pos_x, pos_y, vel_x, vel_y);
        }
        //std::cout << input[i*2]*0.5 << std::endl;
        if ((input[i*2]*0.5 > glob.getPrecisionL()) || (input[i*2]*0.5 < (-1)*glob.getPrecisionL())){
            float pos_x = glob.getV0_x()+70, pos_y = (glob.getHei()/2)+ofRandom(-(glob.getHei()-50),(glob.getHei()-50));
            float vel_x = 0.0, vel_y = 0.0;
            ps.addParticle(pos_x, pos_y, vel_x, vel_y);
        }
        
	}
    
    ps.sysUpdate();
	
}

//--------------------------------------------------------------
void ofApp::resetCanvas(){
    //reset the noise particles zone
    if (glob.getLinesMode()){
        ofColor(255, 255, 255, 255);
        ofRect(95, 0, glob.getWid()-95, glob.getHei());
        ps.sysReset();
    }
    else {
        ofColor(255, 255, 255, 255);
        ofRect(0, 0, glob.getWid(), glob.getHei());
        ps.sysReset();
    }
    //reset the variables
    glob.setElapsedFrames(0);
    //Create new Particle System
    ps = ParticleSystem();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'l':
            if (glob.getLinesMode()) {
                glob.setLinesMode(false);
                cout << "PERLIN WITH SPECTRUM MODE DEACTIVATED" << endl;
                //we activate justDeactivated
                glob.setJustDeactivated(true);
            }
            else {
                glob.setLinesMode(true);
                cout << "PERLIN WITH SPECTRUM MODE ACTIVATED" << endl;
            }
            break;
            
        case 'r': //RESET
            ofPushStyle();
                ofPushMatrix();
                    resetCanvas();
                ofPopMatrix();
            ofPopStyle();
            cout << "RESET DONE" << endl;
            break;
            
        default:
            break;
            
    };
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
