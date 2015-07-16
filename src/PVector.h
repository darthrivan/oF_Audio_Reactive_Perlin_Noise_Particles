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

#ifndef __oF_Audio_Reactive_Perlin_Noise_Particles__PVector__
#define __oF_Audio_Reactive_Perlin_Noise_Particles__PVector__

#include <iostream>

class PVector {
public:
    //Attributes
    
    float x, y;
    
    //Functions
    
    // Empty constructor
    PVector();
    // Constructor with 2 parameters
    PVector(float _x, float _y);
    // Get X value
    float getX();
    // Get Y value
    float getY();
    // Adds 2 PVectors
    void add(PVector a);
    // Divides a PVector by a number
    void div(float d);
    // Modifies the X of a PVector
    void modX(float _x);
    // Modifies the Y of a PVector
    void modY(float _y);
    // Equals 2 PVectors
    void equals(PVector a);
    // Resets a PVector (give values equal to zero)
    void reset();

};

#endif /* defined(__oF_Audio_Reactive_Perlin_Noise_Particles__PVector__) */
