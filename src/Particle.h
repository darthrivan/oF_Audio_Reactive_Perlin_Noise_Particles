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

#ifndef __oF_Audio_Reactive_Perlin_Noise_Particles__Particle__
#define __oF_Audio_Reactive_Perlin_Noise_Particles__Particle__


#include "PVector.h"
#include "Perlin.h"

#include <iostream>

class Particle {
    
private:
    
public:
    
    //Attributes
    
    PVector pos, vel, noiseVec;
    float noiseFloat, lifeTime, age;
    bool isDead;
    
    //Functions
    
    // Constructor
    Particle(PVector _pos, PVector _vel);
    // Equals one particle to another
    void equals(Particle p);
    // Updates the movement with Perlin
    void update();
    // Draws the particle on the window
    void draw();

};

#endif /* defined(__oF_Audio_Reactive_Perlin_Noise_Particles__Particle__) */