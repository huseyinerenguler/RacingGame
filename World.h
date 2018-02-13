#include "SimpleDraw.h"
#include "MyObject.h"
#include "EnemyObject.h"
#include <time.h>

class World {
	private:
		int widthOfGameArea;
		int heightOfGameArea;
		EnemyObject enemyObject1;
		EnemyObject enemyObject2;
		MyObject myObject;
		
	public:
		World();
		World(int width, int height);
		void setGameArea(int _widthOfGameArea, int _heightOfGameArea); // this function set window size according to input size values
		void createMyObject(int _width, int x_Coordinate, int y_Coordinate);
		void createEnemyObjects(int _width); // this function randomly create enemy objects 
		void drawMyObject(); // this function draws our object to game area
		void drawEnemyObject(); // this function draws enemy objects to game area
		void drawRoadSideLines(); // this function draws roadside lines to game area
		void moveEnemyObjects(int unit); // this function gets speed unit and move enemy objects 
		void moveMyObject(int mouseX); // this function gets mouse coordinates and move our object
		int collisionControl(); // if there are a collision this function returns false
};
