/*
 * Perso.cpp
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

#include "Perso.h"

using namespace std;
/*
Perso::Perso():images(),current_image(0),direction(1),attacking(0),holding(NULL)
{
	// TODO Auto-generated constructor stub

}*/

Perso::Perso(float x1,float y1,float sx1,float sy1,std::vector <sf::Image*> * img):Moving_Rect(x1,y1,sx1,sy1),images(img),
	current_image(0),direction(-1),attacking(0),holding(NULL),nb_fly_img(0)
{
	// TODO Auto-generated constructor stub
}


Perso::~Perso() {
	// TODO Auto-generated destructor stub

}

void Perso::draw_perso(sf::RenderWindow & App,Camera &cam)//later, add camera
{
	current_image+=(0.1+abs(vx/20.0)-vy/100)*(nb_fly_img/4.0);
	if (current_image>=nb_fly_img) current_image=0;
	spr.SetImage(*(*images)[(int)current_image]);

	if ((attacking<0)||((attacking>0)&&(attacking<1))) spr.SetImage(*(*images)[nb_fly_img]);
	if ((attacking>=1)&&(attacking<3)) spr.SetImage(*(*images)[nb_fly_img+1]);


	spr.FlipX(direction==1);
	draw(App,cam);

}

void Perso::set_direction(bool right)
{
	if (right) direction=1;
	else direction=-1;
}



void Perso::activity(vector <Item*> &items,bool button,std::vector <Perso*> &targets)//attacking and holding activity
{
    if (vx<0) set_direction(false);
    if (vx>0) set_direction(true);

	if ((button)&&(holding==NULL)) if (attacking==0) attacking=0.1;//start attack

	if ((attacking>0.5)&&(attacking<2)) //try to attack someone
	{
		for (unsigned int i=0;i<targets.size();i++)
		{
			//
			if ((abs(relative_pos_y(*targets[i]))<3)&&(targets[i]->attacking>=0))
				if ((abs(targets[i]->x-x)<targets[i]->sx)&&((targets[i]->x>x)==(direction==1)))
				{
					//try to attack
					//sound
					//cout<<"attack ! ";
					if (direction==targets[i]->direction)
					{
						//cout<<" a !"<<snd_attack->GetVolume()<<"\n";
						snd_attack->Play();
						targets[i]->drop_item();
						targets[i]->attacking=-0.1;
					}else{
						//cout<<" b !"<<snd_block->GetVolume()<<"\n";
						snd_block->Play();
					}
				}
		}
	}

	if ((attacking>0)&&(attacking<1)&&(holding==NULL)) //try to catch an item
	{
        for (unsigned int i=0;i<items.size();i++)
        {
        	if ((abs(items[i]->relative_pos_x(*this))<3)&&(abs(items[i]->relative_pos_y(*this))<3))
        	{
        		catch_item(items[i]);
        		//cout<<"Caught "<<i<<endl;
        	}
        }
	}
	if (!button) drop_item();
	if (holding!=NULL)
	{
		holding->x=x;
		holding->y=y;
		holding->vx=vx;
		holding->vy=vy;
	}

	//cout<<"activity "<<attacking;
	if (attacking<0)//attacked
	{
		//cout<<"!";
		attacking-=0.1;
		vy=vy+0.5;
	}
	if (attacking<-2) attacking=0;


	if (attacking>0) attacking+=0.2;
	if ((attacking>1)&&(!button)) attacking=0;
	if (attacking>8) attacking=0;
	//cout<<"   "<<attacking<<endl;
}

Item* Perso::is_holding() const
{
	return holding;
}

void Perso::drop_item()
{
	if (holding==NULL) return;
	holding->held_by=NULL;
	holding=NULL;
}

bool Perso::catch_item(Item *item)
{
	//cout<<"try to catch : "<<item<<"   held by "<<item->held_by<<"   already holding "<<holding<<endl;
	if ((item==NULL)||(holding!=NULL)||(item->held_by!=NULL)) return false;
	holding=item;
	item->held_by=this;
	return true;
}
