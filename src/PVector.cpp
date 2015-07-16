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

#include "PVector.h"

PVector::PVector(){
    x = y = 0.0;
}

PVector::PVector(float _x, float _y){
    x = _x;
    y = _y;
}

float PVector::getX(){
    return x;
}

float PVector::getY(){
    return y;
}

void PVector::add(PVector a){
    x = x + a.x;
    y = y + a.y;
}

void PVector::div(float d){
    x /= d;
    y /= d;
}

void PVector::modX(float _x){
    x = _x;
}

void PVector::modY(float _y){
    y = _y;
}

void PVector::equals(PVector a){
    x = a.x;
    y = a.y;
}

void PVector::reset(){
    x = 0;
    y = 0;
}

