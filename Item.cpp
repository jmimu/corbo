/*
 * Item.cpp
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


#include "Item.h"

/*Item::Item():held_by(NULL) {
	// TODO Auto-generated constructor stub
}*/

Item::Item(float x1,float y1,float sx1,float sy1):Moving_Rect(x1,y1,sx1,sy1),held_by(NULL) {
	// TODO Auto-generated constructor stub

}


Item::~Item() {
	// TODO Auto-generated destructor stub
}


void Item::activity()//falling
{
	vy+=0.5;
	vx*=0.99;
}


