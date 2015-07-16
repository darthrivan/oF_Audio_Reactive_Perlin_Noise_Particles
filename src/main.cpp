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

#include "ofMain.h"
#include "ofApp.h"
#include "Globals.h"

// We create a Global variable to use in external classes
Globals glob = Globals();

//========================================================================
int main( ){
	ofSetupOpenGL(1200,650,OF_WINDOW);			// <-------- setup the GL context
    //ofSetupOpenGL(1200,650,OF_FULLSCREEN);			// <-------- setup the GL context
    
    //We save values for latter process
    glob.setHei(ofGetWindowHeight());
    glob.setWid(ofGetWindowWidth());
    
    // this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
