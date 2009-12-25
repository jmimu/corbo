/*
 * Level.cpp
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

#include "Level.h"

using namespace std;

Level::Level():player(720,150,33,15),cam(1800,400),Princess(100,0,32,48),
BadBoy(1700,0,32,48),people_area(150),score_p1(0),score_p2(0) {
	// TODO Auto-generated constructor stub
	Rect *wall1=new Rect(0,0,1,400);
	walls.push_back(wall1);
	Rect *wall2=new Rect(0,0,1800,1);
	walls.push_back(wall2);
	Rect *wall3=new Rect(1799,0,1,400);
	walls.push_back(wall3);
	Rect *wall4=new Rect(0,399,1800,1);
	walls.push_back(wall4);
	Princess.set_picture("data/people/princess.png");
	BadBoy.set_picture("data/people/badboy.png");
}

Level::~Level() {
	// TODO Auto-generated destructor stub
	//delete all walls
	for (unsigned int i=0;i<walls.size();i++)
	{
		delete walls[i];
	}
	//delete all items
	for (unsigned int i=0;i<items.size();i++)
	{
		delete items[i];
	}
	//delete all bats
	for (unsigned int i=0;i<bats.size();i++)
	{
		delete bats[i];
	}
}


void Level::make_Level1(int nbr_bat,int nbr_items)
{
	Rect *wall5=new Rect(800,300,120,100);
	wall5->set_picture("data/walls/wall5.png");
	walls.push_back(wall5);

	Rect *wall6=new Rect(580,168,32,32);
	wall6->set_picture("data/walls/wall6.png");
	walls.push_back(wall6);

	Rect *wall7=new Rect(500,304,22,96);
	wall7->set_picture("data/walls/wall7.png");
	walls.push_back(wall7);

	for (int i=0;i<nbr_bat;i++)
	{
		Bat *bat=new Bat(rand() % 500 + 500,rand() % 100 + 50,20,15);
		bats.push_back(bat);
	}
	for (int i=0;i<nbr_items;i++)
	{
		Item *item=new Item(rand() % 500 + 500,rand() % 100 + 50,20,15);
		item->set_picture("data/item/item1.png");
		items.push_back(item);
	}
}

void Level::draw(sf::RenderWindow & App)
{
    cam.set_position(player.x,player.y);
    cam.draw_bg(App);

    for (unsigned int i=0;i<walls.size();i++)
    {
    	walls[i]->draw(App,cam);
    }
    for (unsigned int i=0;i<items.size();i++)
    {
    	items[i]->draw(App,cam);
    }
    for (unsigned int i=0;i<bats.size();i++)
    {
    	bats[i]->draw_perso(App,cam);
    }
    player.draw_perso(App,cam);
    Princess.draw(App,cam);
    BadBoy.draw(App,cam);


}

void Level::update()
{
    for (unsigned int i=0;i<items.size();i++)
    {
    	if ((items[i]->held_by==NULL)&&(items[i]->x<people_area))
    	{
    		items[i]->held_by=&Princess;
    		Player::stat_snd_point.Play();
    	}
    	if ((items[i]->held_by==NULL)&&(items[i]->x>1800-people_area))
    	{
    		items[i]->held_by=&BadBoy;
    		Bat::stat_snd_point.Play();
    	}
    }

    Princess.vy+=0.5;
    Princess.dynamic(walls);
    BadBoy.vy+=0.5;
    BadBoy.dynamic(walls);

    if (player.x>1800-people_area)
    {
    	player.x=1800-people_area;
    	player.vx=0;
    }

    for (unsigned int i=0;i<bats.size();i++)
    {
    	if (bats[i]->x<people_area)
    	{
    		bats[i]->x=people_area;
    		bats[i]->vx=0;
    	}
    }

}

std::string Level::str_score()
{
	score_p1=0;
	score_p2=0;
    for (unsigned int i=0;i<items.size();i++)
    {
    	if (items[i]->x<people_area) score_p1++;
    	if (items[i]->x>1800-people_area) score_p2++;
    }
	std::ostringstream oss;//output stream
	oss<<"Score :   P1="<<score_p1<<"   P2="<<score_p2;
	return oss.str();
}
