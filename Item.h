/*
 * Item.h
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

#ifndef ITEM_H_
#define ITEM_H_

#include "Moving_Rect.h"

/**
 * Item has to be smaller than Perso
 */
class Item: public Moving_Rect {
public:
	Moving_Rect *held_by;
	//Item();
	Item(float xx1,float yy1,float xx2,float yy2);
	void activity();
	virtual ~Item();
};

#endif /* ITEM_H_ */
