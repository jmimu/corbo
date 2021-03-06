/*
 * Player.cpp
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

#include "Player.h"
#include <sstream>

using namespace std;

std::vector <sf::Image*> Player::pics;//static members have to be redefined in the cpp file
bool Player::pic_loaded=false;
sf::SoundBuffer * Player::sndBuffer1;
sf::SoundBuffer * Player::sndBuffer2;
sf::SoundBuffer * Player::sndBuffer3;
sf::Sound Player::stat_snd_block;
sf::Sound Player::stat_snd_attack;
sf::Sound Player::stat_snd_point;

/*Player::Player() {
	// TODO Auto-generated constructor stub
	if (!pic_loaded) load_pic();
}*/

Player::Player(float x1,float y1,float sx1,float sy1):Perso(x1,y1,sx1,sy1,NULL) {
	// TODO Auto-generated constructor stub
	nb_fly_img=31;
	if (!pic_loaded) load_pic();
	images=&pics;
	snd_block=&stat_snd_block;
	snd_attack=&stat_snd_attack;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
	unload_pic();
}

void Player::control(sf::RenderWindow &App,std::vector <Item*> &items,std::vector <Perso*> &targets)
{
    bool button=App.GetInput().IsJoystickButtonDown(0, 1);

    if (attacking>=0)
    {
    	if ((App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)!=0)||(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)!=0))
    	{
    		vx=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)/20.0);
			vy=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)/20.0);
    	}else{
        	if (!(App.GetInput().IsKeyDown(sf::Key::Left))&&(!(App.GetInput().IsKeyDown(sf::Key::Left)))) vx=0;
        	if (!(App.GetInput().IsKeyDown(sf::Key::Up))&&(!(App.GetInput().IsKeyDown(sf::Key::Down)))) vy=0;
        	if (App.GetInput().IsKeyDown(sf::Key::Left))
        		vx=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Right))
        		vx=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Up))
        		vy=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Down))
        		vy=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Space))
        		button=true;
        	else button=App.GetInput().IsJoystickButtonDown(0, 1);
        }
    }
    activity(items,button,targets);
}

void Player::load_pic()
{
	sndBuffer1=new sf::SoundBuffer();
	sndBuffer1->LoadFromFile("data/sound/hurt.wav");
	stat_snd_block.SetBuffer(*sndBuffer1);
	//stat_snd_block.Play();

	sndBuffer2=new sf::SoundBuffer();
	sndBuffer2->LoadFromFile("data/sound/fall.wav");
	stat_snd_attack.SetBuffer(*sndBuffer2);
	//stat_snd_attack.Play();

	sndBuffer3=new sf::SoundBuffer();
	sndBuffer3->LoadFromFile("data/sound/lifeup.wav");
	stat_snd_point.SetBuffer(*sndBuffer3);
	//stat_snd_attack.Play();

	for (unsigned int i=0;i<31;i++)
	{
		sf::Image * img1=new sf::Image();
		ostringstream oss;
		oss<<"data/raven/vol"<<i+100<<".png",
		img1->LoadFromFile(oss.str());
		pics.push_back(img1);
	}

    sf::Image * img5=new sf::Image();
    img5->LoadFromFile("data/raven/vol100.png");
    pics.push_back(img5);
    sf::Image * img6=new sf::Image();
    img6->LoadFromFile("data/raven/vol102.png");
    pics.push_back(img6);
    pic_loaded=true;
}

void Player::unload_pic()
{
	if (!pic_loaded) return;
    for (unsigned int i=0;i<Player::pics.size();i++)
    {
    	delete Player::pics[i];
    	//cout<<" del";
    }
    delete sndBuffer1;
    delete sndBuffer2;
    pic_loaded=false;
}

