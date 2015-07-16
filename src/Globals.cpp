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

#include "Globals.h"

Globals::Globals(){
    
    linesMode = false;
    justDeactivated = false;
    elapsedFrames = 0;
    v0_x = 100;
    spectrumScale = 4;
    
    // With Perlin.h 10000 is slow
    // With ofNoise()  100000 is slow
    MAX_PARTICLES = 1000;
    
    precisionL = 0.005;
    precisionR = 0.005;
    
    LifeTime = 400;
    
    ParticleAlpha = 10;
    
    ParSpeedRedFactor = 1.3;
    
    //Couner for Perlin use reset
    useCounter = 0;
}

float Globals::getPerlinNoise(float p_x, float p_y, float p_z){
    if (MAX_PARTICLES > 10000) {
        if (useCounter > 100) {
            Perlin per;
            useCounter = 0;
        }
    }
    else {
        if (useCounter > (MAX_PARTICLES/MAX_PARTICLES)) {
            Perlin per;
            useCounter = 0;
        }
    }
    noiseF = per.noise(p_x, p_y, p_z);
    ++useCounter;
    return noiseF;
}

void Globals::setWid(int w){
    wid = w;
}

void Globals::setHei(int h){
    hei = h;
}

int Globals::getWid(){
    return wid;
}

int Globals::getHei(){
    return hei;
}

void Globals::setLinesMode(bool b){
    linesMode = b;
}

bool Globals::getLinesMode(){
    return linesMode;
}

void Globals::setJustDeactivated(bool b){
    justDeactivated = b;
}

bool Globals::getJustDeactivated(){
    return justDeactivated;
}

int Globals::getElapsedFrames(){
    return elapsedFrames;
}

void Globals::setElapsedFrames(int f){
    elapsedFrames = f;
}

int Globals::getMaxPart(){
    return MAX_PARTICLES;
}

int Globals::getV0_x(){
    return v0_x;
}

float Globals::getPrecisionR(){
    return precisionR;
}

float Globals::getPrecisionL(){
    return precisionL;
}

int Globals::getLifetime(){
    return LifeTime;
}

float Globals::getSpectrumScale(){
    return spectrumScale;
}

int Globals::getPartAlpha(){
    return ParticleAlpha;
}

float Globals::getParSpeedRedFactor(){
    return ParSpeedRedFactor;
}


