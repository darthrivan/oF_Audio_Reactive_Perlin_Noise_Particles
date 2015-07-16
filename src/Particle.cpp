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

#include "Particle.h"
#include "ofGraphics.h"
#include "Globals.h"
#include "Perlin.h"

#include <cmath>
#include <iostream>

extern Globals glob;

Particle::Particle(PVector _pos, PVector _vel){
    pos.equals(_pos);
    vel.equals(_vel);
    lifeTime = glob.getLifetime();
    age = 0;
    isDead = false;
    noiseVec.reset();
}

void Particle::equals(Particle p){
    pos.equals(p.pos);
    vel.equals(p.vel);
    lifeTime = p.lifeTime;
    age = p.age;
    isDead = p.isDead;
    noiseVec = p.noiseVec;
}

void Particle::update(){
    
    // Use either ofNoise() in case you want to use oF internal Perlin Noise
    // or per.noise() in case you want to use Chris Little's implementation
    //Comment or Uncomment depending on your needs
    // Option 1a, Chris direct ::::
    //Perlin per;
    //noiseFloat = per.noise(pos.x * 0.0025, pos.y * 0.0025, glob.getElapsedFrames() * 0.001);
    // Option 1b, Chris via Globals.h ::::
    noiseFloat = glob.getPerlinNoise(pos.x * 0.0025, pos.y * 0.0025, glob.getElapsedFrames() * 0.001);
    // Option 2, openFrameworks internal ::::
    //noiseFloat = ofNoise(pos.x * 0.0025, pos.y * 0.0025, glob.getElapsedFrames() * 0.001);
    
    noiseVec.modX((float)(cos(((noiseFloat - 0.3) * (M_PI*2)) * 10)));
    noiseVec.modY((float)(sin(((noiseFloat - 0.3) * (M_PI*2)) * 10)));

    vel.add(noiseVec);
    vel.div(glob.getParSpeedRedFactor());
    pos.add(vel);
    
    if(1.0-(age/lifeTime) == 0){
        isDead = true;
    }
    
    //if we have the lines, respect the space for them
    if (glob.getLinesMode()){
        if(pos.x < glob.getV0_x() || pos.x > glob.getWid() - glob.getV0_x() || pos.y < 0 || pos.y > glob.getHei()){
            isDead = true;
            age = lifeTime;
        }
    } else { //else grab the whole screen as limit to kill the particles
        if(pos.x < 0 || pos.x > glob.getWid() || pos.y < 0 || pos.y > glob.getHei()){
            isDead = true;
            age = lifeTime;
        }
    }
    
    if(1.0-(age/lifeTime) != 0){
        age++;
    }
}

void Particle::draw(){
    if (!isDead) {
        ofPushStyle();
            ofColor aux;
            aux.r=0; aux.g=0; aux.b=0; aux.a=glob.getPartAlpha();
            ofSetColor(aux);
            ofCircle(pos.x, pos.y, 1-(age/lifeTime));        
        ofPopStyle();
    }
}


