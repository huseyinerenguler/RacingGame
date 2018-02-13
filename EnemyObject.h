#include "SimpleDraw.h"

class EnemyObject {
	private:
		int width;
		int length;
		int x1; // x1 coordinate
		int x2; // x2 coordinate
		int y1; // y1 coordinate
		int y2; // y2 coordinate
		
	public:
		EnemyObject(); 
		void setCoordinates(int x_Coordinate, int y_Coordinate); // this function sets coordinates
		void setDimensions(int _width); // this function sets dimensions
		void draw(); // this function draws enemy objects on game area
		void clear(int unit); // this function clears enemy objects on game area
		void move(int unit); // this function moves enemy objects according to speed unit
		int getCurrentX1();
		int getCurrentX2();
		int getCurrentY1();
		int getCurrentY2();
};
