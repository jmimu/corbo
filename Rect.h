/*
 * Rect.h
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

#ifndef RECT_H_
#define RECT_H_

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Camera.h"

inline int signof(double a) { return (a == 0.0) ? 0 : (a<0 ? -1 : 1); }
inline float abs(double a) { return (a > 0.0) ? a : -a; }

class Rect {
protected:
public:
	float x,y,sx,sy;//x,y : up left
	sf::Shape shp;//rectangle
	sf::Image img;
    sf::Sprite spr;//nice picture
public:
	Rect();
	Rect(float x1,float y1,float sx1,float sy1);
	virtual ~Rect();
	void draw(sf::RenderWindow & App,Camera &cam);//later, add camera
	int relative_pos_x(Rect &other);
	int relative_pos_y(Rect &other);
	void set_picture(std::string file);
};

#endif /* RECT_H_ */
