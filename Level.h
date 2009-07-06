/*
 * Level.h
 *
 *  Created on: 17 juil. 2008
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

#ifndef LEVEL_H_
#define LEVEL_H_

#include <sstream>
#include "Rect.h"
#include "Moving_Rect.h"
#include "Perso.h"
#include "Player.h"
#include "Bat.h"
#include "Item.h"
#include "Camera.h"

/**
 * Levels are (0,0)-(1800,400)
 */
class Level {
public:
	std::vector <Rect*> walls;
	std::vector <Bat*> bats;
	std::vector <Item*> items;
	Camera cam;
	Player player;
	Moving_Rect Princess;
	Moving_Rect BadBoy;

	float people_area;//where only one team can go
    int score_p1;
    int score_p2;

	Level();
	virtual ~Level();
	void make_Level1(int nbr_bat,int nbr_items);
	void draw(sf::RenderWindow & App);

	void update();
	std::string str_score();
};

#endif /* LEVEL_H_ */
