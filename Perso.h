/*
 * Perso.h
 *
 *  Created on: 13 juil. 2008
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

#ifndef PERSO_H_
#define PERSO_H_

#include <vector>
#include <SFML/Audio.hpp>
#include "Moving_Rect.h"
#include "Item.h"

class Perso: public Moving_Rect {
protected:
	std::vector <sf::Image*> * images;
	int nb_fly_img;
	float current_image;//number of current image
	int direction;//1 or -1
	float attacking;//0 : nothing, ]0;1] 1st pic, ]1;3] 2nd pic <0 : attacked, ]3;8] after attack
	Item *holding;//which item is it holding ?
	sf::Sound *snd_block;
	sf::Sound *snd_attack;
public:
	//Perso();
	Perso(float x1,float y1,float sx1,float sy1,std::vector <sf::Image*> * img);
	virtual ~Perso();
	void draw_perso(sf::RenderWindow & App,Camera &cam);
	void set_direction(bool right);
	void activity(std::vector <Item*> &items,bool button,std::vector <Perso*> &targets);//attacking activity
	Item * is_holding() const;
	bool catch_item(Item *item);
	void drop_item();
};

#endif /* PERSO_H_ */
