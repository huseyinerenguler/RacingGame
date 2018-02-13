/*
 *	Name: Hüseyin Eren Güler
 *	Date: 02/01/2018
 */

#include <iostream>
#include <sstream>
#include "World.h"

#define OBJECT_WIDTH 72

int main () {
	
	World world(700,550); // create a game area with size

	// create objects
	world.createEnemyObjects(OBJECT_WIDTH);
	world.createMyObject(OBJECT_WIDTH, 250, 325);

	int level = 1;
	int count = 0;
	int score = 1;
	
	while (true) {
		
		drawText(560,150,"SCORE");
		drawText(530,170,"______________");
		drawText(560,280,"LEVEL");
		drawText(530,300,"______________");
		
		std::stringstream s1,s2;
		std::string str;
    	s1 << score;
    	s1 >> str;
		drawText(567,200,str.c_str()); // display current score on the screen

		s2 << level;
		s2 >> str;
		drawText(573,330,str.c_str()); // display current level on the screen
		
		world.moveMyObject(getMouseX()); // move our object according to mouse coordinates
		world.moveEnemyObjects(level); // move enemy objects according to speed that is depend on level
		world.drawRoadSideLines(); // display roadside lines
		
		score = score + level; // score is increasing rapidly according to the level
		count++;
		
		// nearly every 3 second, level is increasing 
		if (count ==  70 && level < 25) {
			level++;
			count = 0;
		}
		
		// collision control
		if (!world.collisionControl())
			system("PAUSE");
		
		Sleep(15);
	}

	return 0;
}
