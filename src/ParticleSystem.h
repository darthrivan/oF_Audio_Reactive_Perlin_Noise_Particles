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

#ifndef __oF_Audio_Reactive_Perlin_Noise_Particles__ParticleSystem__
#define __oF_Audio_Reactive_Perlin_Noise_Particles__ParticleSystem__

#include "Particle.h"
#include "Globals.h"

#include <iostream>
#include <vector>

extern Globals glob;

class ParticleSystem{
public:
    //Attributes
    int sizeSys = glob.getMaxPart();
    std::vector<Particle> points;
    int Counter;
    
    
    //Functions
    
    // Constructor
    ParticleSystem();
    // Get size of the Particle System
    int getSysSize();
    // Add a Particle to the System
    void addParticle(float posX, float posY, float velX, float velY);
    // Updates the System
    void sysUpdate();
    // Draws the System
    void sysDraw();
    // Resets the System
    void sysReset();
    
private:
    // Returns the position of the first dead Particle in the System
    int getPositionDeadParticle();
    // Gives to the Particle in the position pos of the System the parameters of a new Particle
    void rebornParticle(int pos, Particle p);
    // Add a Particle to the System
    void addParticle(Particle p);
    
};

#endif /* defined(__oF_Audio_Reactive_Perlin_Noise_Particles__ParticleSystem__) */
