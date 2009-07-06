/*
 * Player.h
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

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Audio.hpp>
#include "Perso.h"
#include "Item.h"

class Player: public Perso {
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
public:
	static sf::Sound stat_snd_point;
	//Player();
	Player(float x1,float y1,float sx1,float sy1);
	virtual ~Player();
	void control(sf::RenderWindow &App,std::vector <Item*> &items,std::vector <Perso*> &targets);//true=exit !
};

#endif /* PLAYER_H_ */
