/*
 * Camera.cpp
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

#include "Camera.h"

Camera::Camera(float _max_x,float _max_y):x(800),y(200),size_x(640),size_y(400),
max_x(_max_x),max_y(_max_y) {
	// TODO Auto-generated constructor stub
	bg0_img.LoadFromFile("data/bg0.png");
	bg0_spr.SetImage(bg0_img);
	bg0_speed=0.1;
	bg1_img.LoadFromFile("data/bg1.png");
	bg1_spr.SetImage(bg1_img);
	bg1_speed=0.2;
	bg2_img.LoadFromFile("data/bg2.png");
	bg2_spr.SetImage(bg2_img);
	bg2_speed=0.6;
	bg3_img.LoadFromFile("data/bg3.png");
	bg3_spr.SetImage(bg3_img);
	bg3_speed=0.9;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::set_position(float interest_x,float interest_y)
{
	if (interest_x-50>x) x+=((int)(interest_x-50-x)/2)/10.0;
	if (interest_x+50<x) x+=((int)(interest_x+50-x)/2)/10.0;
	if (x<size_x/2) x=size_x/2;
	if (y<size_y/2) y=size_y/2;
	if (x>max_x-size_x/2) x=max_x-size_x/2;
	if (y>max_y-size_y/2) y=max_y-size_y/2;
}


void Camera::draw_bg(sf::RenderWindow & App)
{
	bg0_spr.SetPosition(-(x-size_x/2)*bg0_speed,-(y-size_y/2)*bg0_speed);
	App.Draw(bg0_spr);
	bg1_spr.SetPosition(-(x-size_x/2)*bg1_speed,-(y-size_y/2)*bg1_speed);
	App.Draw(bg1_spr);
	bg2_spr.SetPosition(-(x-size_x/2)*bg2_speed,-(y-size_y/2)*bg2_speed);
	App.Draw(bg2_spr);
	bg3_spr.SetPosition(-(x-size_x/2)*bg3_speed,-(y-size_y/2)*bg3_speed);
	App.Draw(bg3_spr);

}

void Camera::draw_fg(sf::RenderWindow & App)
{

}

