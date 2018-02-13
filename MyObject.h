#include "SimpleDraw.h"

class MyObject {
	private:
		int width;
		int length;
		int x1; // x1 coordinate
		int x2; // x2 coordinate
		int y1; // y1 coordinate
		int y2; // y2 coordinate
		
	public:
		MyObject();
		MyObject(int _width, int x_Coordinate, int y_Coordinate);
		void setCoordinates(int x_Coordinate, int y_Coordinate); // this function sets coordinates
		void setDimensions(int _width);  // this function sets dimensions
		void draw(); // this function draws our object on game area
		void clear(); // this function clear our object on game area
		void move(int mouseX); // this function moves our object according to mouse coordinates
		int getCurrentX1();
		int getCurrentX2();
		int getCurrentY1();
		int getCurrentY2();
};
