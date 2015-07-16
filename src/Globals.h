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

#ifndef __oF_Audio_Reactive_Perlin_Noise_Particles__Globals__
#define __oF_Audio_Reactive_Perlin_Noise_Particles__Globals__

#include "Perlin.h"
#include <iostream>
#include <vector>

class Globals {
public:
    //Attributes
    
    // Screen size
    int wid, hei;
    
    // Mode
    bool linesMode;
    
    //justDeactivated acts as a white rectangle restarter trigger
    bool justDeactivated;
    
    // Elapsed Frames
    int elapsedFrames;
    
    // Maximum Number of Particles in the System
    int MAX_PARTICLES;
    
    // Limit for the space where particles are generated
    int v0_x;
    
    // PRECISION FOR BOTH CHANNELS
    //Precision value >= 1.5 is highly imposible to feel anything
    //For R Channel it will ignore values between precisionR and -precisionR
    //And the same for L Channel.
    float precisionL, precisionR;
    
    // Lifetime for every Particle in the System. Old Initial: 250
    int LifeTime;
    
    float spectrumScale;
    
    //Particles Transparency where 0 is fully transparent and 255 is fully opaque
    int ParticleAlpha;
    
    //Particles Speed reducing Factor from 1.1 to whatever to go from more speed to less speed.
    float ParSpeedRedFactor;
    
    //Perlin Noise
    Perlin per;
    float noiseF;
    int useCounter;
        
    //Functions
    
    Globals();
    float getPerlinNoise(float sample_x, float sample_y, float sample_z);
    void setWid(int w);
    void setHei(int h);
    int getWid();
    int getHei();
    void setLinesMode(bool b);
    bool getLinesMode();
    void setJustDeactivated(bool b);
    bool getJustDeactivated();
    int getElapsedFrames();
    void setElapsedFrames(int f);
    int getMaxPart();
    int getV0_x();
    float getPrecisionR();
    float getPrecisionL();
    int getLifetime();
    float getSpectrumScale();
    int getPartAlpha();
    float getParSpeedRedFactor();
    
};


#endif /* defined(__oF_Audio_Reactive_Perlin_Noise_Particles__Globals__) */
