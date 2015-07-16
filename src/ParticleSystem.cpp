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

#include "ParticleSystem.h"
#include "Particle.h"
#include <vector>
#include <iostream>
//#include "Globals.h"

//extern Globals glob;

// PUBLIC FUNCTIONS

ParticleSystem::ParticleSystem(){
    points = std::vector<Particle>();
    points.reserve(ParticleSystem::sizeSys);
    Counter = 0;
}

int ParticleSystem::getSysSize(){
    return sizeSys;
}

void ParticleSystem::addParticle(float posX, float posY, float velX, float velY){
    PVector pos(posX, posY);
    PVector vel(velX, velY);
    Particle p(pos, vel);
    addParticle(p);
}


void ParticleSystem::sysUpdate(){
    for (int i = 0; i < ParticleSystem::sizeSys; ++i) {
        //std::cout << " " << "UPDATES THE " << i; // print variables and end the line
        points[i].update();
    }
}


void ParticleSystem::sysDraw(){
    for (int i = 0; i < ParticleSystem::sizeSys; ++i) {
        points[i].draw();
    }
}


// PRIVATE FUNCTIONS

int ParticleSystem::getPositionDeadParticle(){
    for (int i = 0; i < ParticleSystem::sizeSys; ++i) {
        if (points[i].isDead) return i;
    }
    return -1;
}

void ParticleSystem::rebornParticle(int pos, Particle p){
    points[pos].equals(p);
}


void ParticleSystem::addParticle(Particle p){
    if (Counter <= ParticleSystem::sizeSys) {
        // If we have space we add the particle
        points[Counter] = p;
        ++Counter;
    }
    else {
        //if we havent, we search for a dead Particle in the array
        int pos = getPositionDeadParticle();
        if (pos >= 0) {
            rebornParticle(pos, p);
        }
    }
}

void ParticleSystem::sysReset(){
    points.clear();
    //points.reserve(ParticleSystem::sizeSys);
    Counter = 0;
}







