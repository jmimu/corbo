/*
 * Moving_Rect.cpp
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

#include "Moving_Rect.h"

using namespace std;

Moving_Rect::Moving_Rect():vx(0),vy(0) {
	// TODO Auto-generated constructor stub

}

Moving_Rect::Moving_Rect(float x1,float y1,float sx1,float sy1):Rect(x1,y1,sx1,sy1),vx(0),vy(0)
{

}

Moving_Rect::~Moving_Rect() {
	// TODO Auto-generated destructor stub
}

bool Moving_Rect::dynamic(vector <Rect*> & rects)//collision with static rects
{
	//bool collision_x=false;
	//bool collision_y=false;

	Rect next(x+(int)vx,y+(int)vy,sx,sy);

	float time_1st_collision_x=1000;
	float rect_1st_collision_x=-1;
	float time_1st_collision_y=1000;
	float rect_1st_collision_y=-1;

    for (unsigned int i=0;i<rects.size();i++)
    {
    	//if (i==4) {cout<<"y "<<rects[i]->relative_pos_y(*this)<<"   "<<rects[i]->relative_pos_y(next)<<endl;}
    	//if (i==5) {cout<<"x "<<rects[i]->relative_pos_x(*this)<<"   "<<rects[i]->relative_pos_x(next)<<endl;}
    	if ((rects[i]->relative_pos_y(*this) != rects[i]->relative_pos_y(next))
    	    	||(abs(rects[i]->relative_pos_y(*this))<3)
    	    	||(abs(rects[i]->relative_pos_y( next))<3))
    	{
    		//possible collision in x
    		if (rects[i]->relative_pos_x(*this)<0) //old is on the left
    		{
    			if (rects[i]->relative_pos_x(next)>rects[i]->relative_pos_x(*this))//collision
    			{
    				float collision_time=-(x+sx-rects[i]->x+1)/vx;
    				//cout<<"Left Collision ! "<<collision_time*vx<<"   av "<<x+sx-rects[i]->x<<"  ap "<<x+sx+vx-rects[i]->x<<"   vit "<<vx<<"\n";
    				if ((collision_time>=0)&&(collision_time<time_1st_collision_x))
    				{
    					time_1st_collision_x=collision_time;
    					rect_1st_collision_x=i;
    				}
    			}
    		}
    		if (rects[i]->relative_pos_x(*this)>0) //old is on the right
    		{
    			if (rects[i]->relative_pos_x(next)<rects[i]->relative_pos_x(*this))//collision
    			{
    				float collision_time=-(x-rects[i]->x-rects[i]->sx-1)/vx;
    				//cout<<"Right Collision ! "<<collision_time*vx<<"   av "<<x-rects[i]->x-rects[i]->sx<<"  ap "<<x+vx-rects[i]->x-rects[i]->sx<<"   vit "<<vx<<"\n";
    				if ((collision_time>=0)&&(collision_time<time_1st_collision_x))
    				{
    					time_1st_collision_x=collision_time;
    					rect_1st_collision_x=i;
    				}
    			}
    		}
    	}


    	if ((rects[i]->relative_pos_x(*this) != rects[i]->relative_pos_x(next))
    	    	||(abs(rects[i]->relative_pos_x(*this))<3)
    	    	||(abs(rects[i]->relative_pos_x( next))<3))
    	{
    		//possible collision in y
    		if (rects[i]->relative_pos_y(*this)<0) //old is on the up
    		{
    			if (rects[i]->relative_pos_y(next)>rects[i]->relative_pos_y(*this))//collision
    			{
    				float collision_time=-(y+sy-rects[i]->y+1)/vy;
    				//cout<<"Up Collision ! "<<collision_time*vy<<"   av "<<y+sy-rects[i]->y<<"  ap "<<y+sy+vy-rects[i]->y<<"   vit "<<vy<<"\n";
    				if ((collision_time>=0)&&(collision_time<time_1st_collision_y))
    				{
    					time_1st_collision_y=collision_time;
    					rect_1st_collision_y=i;
    				}
    			}
    		}
    		if (rects[i]->relative_pos_y(*this)>0) //old is on the down
    		{
    			if (rects[i]->relative_pos_y(next)<rects[i]->relative_pos_y(*this))//collision
    			{
    				float collision_time=-(y-rects[i]->y-rects[i]->sy-1)/vy;
    				//cout<<"Down Collision ! "<<collision_time*vy<<"   av "<<y-rects[i]->y-rects[i]->sy<<"  ap "<<y+vy-rects[i]->y-rects[i]->sy<<"   vit "<<vy<<"\n";
    				if ((collision_time>=0)&&(collision_time<time_1st_collision_y))
    				{
    					time_1st_collision_y=collision_time;
    					rect_1st_collision_y=i;
    				}
    			}
    		}
    	}
    }
    //if (rect_1st_collision_x!=-1) cout<<" *** "<<rect_1st_collision_x<<" ***\n";

    //cout<<"Finally : "<<time_1st_collision_x<<" "<<rect_1st_collision_x<<" ; "<<time_1st_collision_y<<" "<<rect_1st_collision_y<<endl;
    if ((rect_1st_collision_x>=0)&&(time_1st_collision_x<=time_1st_collision_y))
    {
    	//cout<<"x collision chosen\n";
		x+=time_1st_collision_x*vx;
		vx=0;
		if ((rect_1st_collision_y>=0)&&(time_1st_collision_x<time_1st_collision_y))
		{
			//cout<<" --- recall\n";
			dynamic(rects);return true;
		}
    }
    if ((rect_1st_collision_y>=0)&&(time_1st_collision_x>=time_1st_collision_y))
    {
    	//cout<<"y collision chosen\n";
		y+=time_1st_collision_y*vy;
		vy=0;
		if ((rect_1st_collision_x>=0)&&(time_1st_collision_x>time_1st_collision_y))
		{
			//cout<<" --- recall\n";
			dynamic(rects);return true;
		}
    }

    x+=(int)vx;
    y+=(int)vy;
	return (rect_1st_collision_x>0 || rect_1st_collision_y>0);
}

