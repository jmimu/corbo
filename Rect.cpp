/*
 * Rect.cpp
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

#include "Rect.h"

using namespace std;

Rect::Rect():x(0),y(0),sx(0),sy(0),img(),spr() {
	// TODO Auto-generated constructor stub
	shp = sf::Shape::Rectangle(0, 0, sx, sy, sf::Color::Blue ,1,sf::Color::Red );
}

Rect::Rect(float x1,float y1,float sx1,float sy1):x(x1),y(y1),sx(sx1),sy(sy1),img(),spr() {
	// TODO Auto-generated constructor stub
	shp = sf::Shape::Rectangle(0, 0, sx, sy, sf::Color::Blue ,1,sf::Color::Red );
}

Rect::~Rect() {
	// TODO Auto-generated destructor stub
}

void Rect::draw(sf::RenderWindow & App,Camera &cam)//later, add camera
{
	shp.SetPosition(x-cam.x+cam.size_x/2,y-cam.y+cam.size_y/2);
	//App.Draw(shp);
	if (spr.GetImage()!= NULL) {
		float dx=spr.GetSize().x-sx;//diff of picture and rect size
		float dy=spr.GetSize().y-sy;
		spr.SetPosition(x-dx/2-cam.x+cam.size_x/2,y-dy/2-cam.y+cam.size_y/2);
		App.Draw(spr);
	}
}

/**
 * Where is the other ?
 *  5 : no collision
 * -3 : left
 * -2 : left contact
 * -1 : left collison
 *  0 : one is inside the other
 *  1 : right collision
 *  2 : right contact
 *  3 : right
 */
int Rect::relative_pos_x(Rect &other)
{
	float x1=x;
	float x2=x+sx;

	float other_x1=other.x;
	float other_x2=other.x+other.sx;

	//if ((other.y+other.sy<y)||(other.y>y+sy)) return 5;//no collision

	if (other_x2<x1) return -3;
	if (other_x1>x2) return  3;
	if (other_x2==x1) return -2;
	if (other_x1==x2) return 2;
	if ((other_x2>x1)&&(other_x2<x2)&&(other_x1<x1)) return -1;
	if ((other_x1<x2)&&(other_x1>x1)&&(other_x2>x2)) return 1;
	return 0;
}

int Rect::relative_pos_y(Rect &other)
{
	float y1=y;
	float y2=y+sy;
	float other_y1=other.y;
	float other_y2=other.y+other.sy;

	//if ((other.x+other.sx<x)||(other.x>x+sx)) return 5;//no collision

	if (other_y2<y1) return -3;
	if (other_y1>y2) return  3;
	if (other_y2==y1) return -2;
	if (other_y1==y2) return 2;
	if ((other_y2>y1)&&(other_y2<y2)&&(other_y1<y1)) return -1;
	if ((other_y1<y2)&&(other_y1>y1)&&(other_y2>y2)) return 1;
	return 0;
}

void Rect::set_picture(string file)
{
	img.LoadFromFile(file);
	spr.SetImage(img);
}
