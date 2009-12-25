/*
 * corbo.cpp
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

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Rect.h"
#include "Moving_Rect.h"
#include "Perso.h"
#include "Player.h"
#include "Bat.h"
#include "Item.h"
#include "Camera.h"
#include "Level.h"

using namespace std;

int main(void) {
	srand ( time(NULL) );

	//sf::RenderWindow App(sf::VideoMode(640, 400, 32), "Corbeau", sf::Style::Fullscreen);
	sf::RenderWindow App(sf::VideoMode(640, 400, 32), "Corbeau");
	float FPS=50.;
    App.SetFramerateLimit(FPS);

    sf::Font Cheeseburger;
    Cheeseburger.LoadFromFile("data/cheeseburger.ttf");

    //1st screen
    sf::Image TitleImage;
    TitleImage.LoadFromFile("data/Crow.png");
    sf::Sprite Title(TitleImage);
    App.Draw(Title);
    App.Display();
    {
    	sf::Event Event;
    	bool running2=true;
    	while (running2)
    	{
			while (App.GetEvent(Event))
				if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
					return EXIT_SUCCESS;
			if (App.GetInput().IsJoystickButtonDown(0, 1)) running2=false;
			if (App.GetInput().IsKeyDown(sf::Key::Space)) running2=false;
    	}
    }

    //game
    sf::String txt_score;
    txt_score.SetFont(Cheeseburger);
    txt_score.SetSize(20.f);
    txt_score.Move(10.f, 1.f);
    txt_score.SetColor(sf::Color(250, 250, 250));

    Level level1;
    level1.make_Level1(5,15);

    bool running=true;
	while (running)
	{

        sf::Event Event;
        while (App.GetEvent(Event))
        {
			if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
				return EXIT_SUCCESS;
        }

        vector <Perso*> perso_bats(level1.bats.begin(),level1.bats.end());

        vector <Perso*> perso_players;
        perso_players.push_back(&level1.player);

        level1.player.control(App,level1.items,perso_bats);
        level1.player.dynamic(level1.walls);
        for (unsigned int i=0;i<level1.bats.size();i++)
        {
        	level1.bats[i]->IA(level1.items,level1.walls,perso_players,level1.BadBoy);
        }

        for (unsigned int i=0;i<level1.items.size();i++)
        {
        	level1.items[i]->activity();
        	level1.items[i]->dynamic(level1.walls);
        }

		level1.update();
        level1.draw(App);

        txt_score.SetText(level1.str_score());
        App.Draw(txt_score);

        App.Display();

        if ((unsigned int)(level1.score_p1+level1.score_p2)==level1.items.size()) //finished !
        {
        	//end of game
        	running=false;
        	sf::String txt_end;
        	txt_end.SetFont(Cheeseburger);
        	txt_end.SetSize(20.f);
        	txt_end.SetColor(sf::Color(250, 250, 250));
        	txt_end.SetText("Finish !\n"+level1.str_score());
        	float t=0;
        	bool running2=true;
        	float wait_time=0;
        	while (running2)
        	{
        		t=t+0.1;
        		txt_end.SetSize(20+2*sin(t));
            	txt_end.SetPosition(50.f-(0+2*sin(t)), 50.f-(0+1.5*sin(t)));
        		App.Draw(txt_end);
        		App.Display();
        		while (App.GetEvent(Event))
        			if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
        				return EXIT_SUCCESS;
        		if (wait_time>100)
        		{
        			if (App.GetInput().IsJoystickButtonDown(0, 1)) running2=false;
        			if (App.GetInput().IsKeyDown(sf::Key::Space)) running2=false;
        		}
        		wait_time+=1;
        	}
        }

    }
	return EXIT_SUCCESS;
}
