/*
 * Bat.cpp
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

#include <sstream>
#include "Bat.h"

using namespace std;

std::vector <sf::Image*> Bat::pics;//static members have to be redefined in the cpp file
bool Bat::pic_loaded=false;
sf::SoundBuffer * Bat::sndBuffer1;
sf::SoundBuffer * Bat::sndBuffer2;
sf::SoundBuffer * Bat::sndBuffer3;
sf::Sound Bat::stat_snd_block;
sf::Sound Bat::stat_snd_attack;
sf::Sound Bat::stat_snd_point;

/*Bat::Bat() {
	// TODO Auto-generated constructor stub

}*/

Bat::Bat(float x1,float y1,float sx1,float sy1):Perso(x1,y1,sx1,sy1,NULL),target(NULL),ia_vx(0),
	ia_vy(0) {
	// TODO Auto-generated constructor stub
	nb_fly_img=31;
	if (!pic_loaded) load_pic();
	images=&pics;
	snd_block=&stat_snd_block;
	snd_attack=&stat_snd_attack;
}

Bat::~Bat() {
	// TODO Auto-generated destructor stub
	unload_pic();
}

void Bat::IA(std::vector <Item*> &items,std::vector <Rect*> & rects,std::vector <Perso*> &targets,Moving_Rect &BadBoy)
{
	bool button=false;
	if (attacking>=0)
	{
		double want_x=0;
		double want_y=0;
		if (holding==NULL)
		{
			vector <Moving_Rect*> lock_list(items.begin(),items.end());
			lock_list.push_back(targets[0]);//the player

			find_target(lock_list,BadBoy.x);
		}
		if (target!=NULL)
		{
			if (target->x>x) want_x=1;
			if (target->x<x) want_x=-1;
			if (target->y>y) want_y=1;
			if (target->y<y) want_y=-1;
			if ((abs(target->x-x)<20)&&(abs(target->y-y)<20)) button=true;
			if (((abs(target->x-x)<20))&&(target==&BadBoy))
			{
				//cout<<"ok!";
				button=false;
				drop_item();
			}

		}
		ia_vx+=(rand() % 10 - 5 + want_x*5)/150.0;
		//if (ia_vx<-4) ia_vx=-4;
		//if (ia_vx>4) ia_vx=4;
		ia_vy+=(rand() % 10 - 5 + want_y*5)/150.0;
		//if (ia_vy<-4) ia_vy=-4;
		//if (ia_vy>4) ia_vy=4;
		//cout<<ia_vx<<"  "<<ia_vy<<endl;
		//vx=(int)ia_vx;
		//vy=(int)ia_vy;
		vx+=ia_vx;
		if (vx<-3) vx=-3;
		if (vx>3) vx=3;
		vy+=ia_vy;
		if (vy<-3) vy=-3;
		if (vy>3) vy=3;
	}
	if (dynamic(rects))//collision
	{
		if (vx==0) ia_vx=0;
		if (vy==0) ia_vy=0;
	}

	if (holding!=NULL)
	{
		button=true;
		target=&BadBoy;
	}
	activity(items,button,targets);
}

void Bat::find_target(std::vector <Moving_Rect*> &targets,float max_x)
{
	float min_dist=10000;
	int nearest_target=-1;
	for (unsigned int i=0;i<targets.size();i++)
	{
		float dist_manhattan=abs(targets[i]->x-x)+abs(targets[i]->y-y);
		if ((dist_manhattan<min_dist)&&(targets[i]->x<max_x)&&((i==targets.size()-1)||(((Item*)targets[i])->held_by==NULL)))
		{//pb if casting Player
			nearest_target=i;
			min_dist=dist_manhattan;
		}
	}
	if (nearest_target>=0) target=targets[nearest_target];
	else target=NULL;
}

void Bat::load_pic()
{
	sndBuffer1=new sf::SoundBuffer();
	sndBuffer1->LoadFromFile("data/sound/hurt.wav");
	stat_snd_block.SetBuffer(*sndBuffer1);

	sndBuffer2=new sf::SoundBuffer();
	sndBuffer2->LoadFromFile("data/sound/fall.wav");
	stat_snd_attack.SetBuffer(*sndBuffer2);

	sndBuffer3=new sf::SoundBuffer();
	sndBuffer3->LoadFromFile("data/sound/lifeup.wav");
	stat_snd_point.SetBuffer(*sndBuffer3);


	for (unsigned int i=0;i<31;i++)
	{
		sf::Image * img1=new sf::Image();
		ostringstream oss;
		oss<<"data/bat/vol"<<i+100<<".png",
		img1->LoadFromFile(oss.str());
		pics.push_back(img1);
	}

    sf::Image * img11=new sf::Image();
    img11->LoadFromFile("data/bat/vol100.png");
    pics.push_back(img11);
    sf::Image * img12=new sf::Image();
    img12->LoadFromFile("data/bat/vol102.png");
    pics.push_back(img12);
    pic_loaded=true;
}

void Bat::unload_pic()
{
	if (!pic_loaded) return;
    for (unsigned int i=0;i<Bat::pics.size();i++)
    {
    	delete Bat::pics[i];
    	//cout<<" del";
    }
    pic_loaded=false;
}
