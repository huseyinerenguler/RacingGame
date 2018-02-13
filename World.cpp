#include "World.h"

World::World() {}

World::World(int width, int height) {
	widthOfGameArea = width;
	heightOfGameArea = height;
	setGameArea(widthOfGameArea, heightOfGameArea);
}

// this function set window size according to input size values
void World::setGameArea(int _widthOfGameArea, int _heightOfGameArea) {
	setWindowSize(_widthOfGameArea, _heightOfGameArea);
}

void World::createMyObject(int _width, int x_Coordinate, int y_Coordinate) {
	myObject.setDimensions(_width);
	myObject.setCoordinates(x_Coordinate, y_Coordinate);
	
	drawMyObject();
}

// this function randomly create enemy objects 
void World::createEnemyObjects(int _width) {
	
	enemyObject1.setDimensions(_width);
	enemyObject2.setDimensions(_width);
	
	srand(time(NULL));
	int random1 = rand() % 3 + 1; // 1,2,3
	int random2 = rand() % 3 + 1;
	while(random1 == random2) {
		random2 = rand() % 3 + 1;
	}
	
	enemyObject1.setCoordinates((-2*_width)+(random1*2*_width)+70, -144);
	enemyObject2.setCoordinates((-2*_width)+(random2*2*_width)+70, -144);
}

// this function draws our object to game area
void World::drawMyObject() {
	myObject.draw();
}

// this function draws enemy objects to game area
void World::drawEnemyObject() {
	enemyObject1.draw();
	enemyObject2.draw();
}

// this function draws roadside lines to game area
void World::drawRoadSideLines() {
	usePen(PS_SOLID, 8, RGB(205,205,0));
	drawRectangle(17,0,25,heightOfGameArea); // left roadside line
	drawRectangle(475,0,483,heightOfGameArea); // right roadside line
}

// this function gets mouse coordinates and move our object
void World::moveMyObject(int mouseX) {
	myObject.move(mouseX);
}

// this function gets speed unit and move enemy objects 
void World::moveEnemyObjects(int unit) {
	
	if (enemyObject1.getCurrentY1() >= heightOfGameArea) {
		createEnemyObjects(72);
	}
	enemyObject1.move(unit);
	enemyObject2.move(unit);
}

// if there are a collision this function returns false
int World::collisionControl() {
	
	int Bx1 = myObject.getCurrentX1();
	int Bx2 = myObject.getCurrentX2();
	int By1 = myObject.getCurrentY1();
	int By2 = myObject.getCurrentY2();
	
	int Ax1 = enemyObject1.getCurrentX1();
	int Ax2 = enemyObject1.getCurrentX2();
	int Ay1 = enemyObject1.getCurrentY1();
	int Ay2 = enemyObject1.getCurrentY2();
	
	if (By1 <= Ay2) {
		if (Ay1 > By2)
			return 1;
		if ((Bx1 >= Ax1 && Bx1 <= Ax2))
			return 0;
		if ((Bx2 >= Ax1 && Bx2 <= Ax2))
			return 0;
			
		Ax1 = enemyObject2.getCurrentX1();
		Ax2 = enemyObject2.getCurrentX2();
		Ay1 = enemyObject2.getCurrentY1();
		Ay2 = enemyObject2.getCurrentY2();
	
		if (By1 <= Ay2) {
			if (Ay1 > By2)
				return 1;
			if ((Bx1 >= Ax1 && Bx1 <= Ax2))
				return 0;
			if ((Bx2 >= Ax1 && Bx2 <= Ax2))
				return 0;
			return 1;
		}
	}	
}

