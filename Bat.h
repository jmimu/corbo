/*
 * Bat.h
 *
 *  Created on: 14 juil. 2008
 *      Author: JMM
 */
/*
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef BAT_H_
#define BAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Perso.h"
#include "Item.h"

class Bat: public Perso {
protected:
	static std::vector <sf::Image*> pics;
	static sf::SoundBuffer * sndBuffer1;
	static sf::SoundBuffer * sndBuffer2;
	static sf::SoundBuffer * sndBuffer3;
	static sf::Sound stat_snd_block;
	static sf::Sound stat_snd_attack;
	static bool pic_loaded;
	static void load_pic();
	static void unload_pic();
protected:
	//for IA
	Moving_Rect *target;
	void find_target(std::vector <Moving_Rect*> &targets,float max_x);
	float ia_vx,ia_vy;
public:
	static sf::Sound stat_snd_point;
	//Bat();
	Bat(float x1,float y1,float sx1,float sy1);
	virtual ~Bat();
	void IA(std::vector <Item*> &items,std::vector <Rect*> & rects,std::vector <Perso*> &targets,Moving_Rect &BadBoy);
};

#endif /* BAT_H_ */
