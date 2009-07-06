/*
 * Camera.h
 *
 *  Created on: 12 juil. 2008
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

#ifndef CAMERA_H_
#define CAMERA_H_

#include <SFML/Graphics.hpp>

class Camera {
protected:
	sf::Image bg0_img;
	sf::Sprite bg0_spr;
	float bg0_speed;
	sf::Image bg1_img;
	sf::Sprite bg1_spr;
	float bg1_speed;
	sf::Image bg2_img;
	sf::Sprite bg2_spr;
	float bg2_speed;
	sf::Image bg3_img;
	sf::Sprite bg3_spr;
	float bg3_speed;
public:
	float x,y;
	int size_x,size_y;
	float max_x,max_y;
public:
	Camera(float _max_x,float _max_y);
	virtual ~Camera();
	void set_position(float interest_x,float interest_y);
	void draw_bg(sf::RenderWindow & App);
	void draw_fg(sf::RenderWindow & App);
};

#endif /* CAMERA_H_ */
