#include "EnemyObject.h"

EnemyObject::EnemyObject() {}

// this function sets dimensions
void EnemyObject::setDimensions(int _width) {
	width = _width;
	length = width * 2;
}

 // this function sets coordinates
void EnemyObject::setCoordinates(int x_Coordinate, int y_Coordinate) {
	x1 = x_Coordinate ;
	y1 = y_Coordinate ;
	x2 = x1 + width;
	y2 = y1 + length;
}

// this function draws enemy objects on game area
void EnemyObject::draw() {
	
	useBrush(1, RGB(0,139,139));
	drawRectangle(x1, y1, x2, y2); // main body
	
	useBrush(1, RGB(240,255,240));
	drawRectangle(x1, y1, x1+(width/5), y1+(length/7)); // left white headlight
	drawRectangle(x2-(width/5), y1, x2, y1+(length/7)); // right white headlight	
	
	useBrush(1, RGB(205,38,38));
	drawRectangle(x1, y2-(length/13), x1+(width/4), y2); // left red headlight
	drawRectangle(x2-(width/4), y2-(length/13), x2, y2); // right red headlight

	useBrush(1, RGB(152,245,255));
	drawRectangle(x1, y1+(length/4), x2, y2-(length/6)); // glass
	
	useBrush(1, RGB(156,156,156));
	drawRectangle(x1+(width/6), y1+(length/12)*5, x2-(width/6), y2-(length/4)); // roof
	
	// side lines of vehicle
	usePen(PS_SOLID, 2, RGB(0,0,0));
	drawLine(x1, y1, x1, y2); // main body
	drawLine(x1, y1, x2, y1);
	drawLine(x1, y2, x2, y2);
	drawLine(x2, y1, x2, y2);
	
	drawLine(x1, y1+(length/4), x2, y1+(length/4)); // glass
	drawLine(x1, y2-(length/6), x2, y2-(length/6));
	
	drawLine(x1+(width/6), y1+(length/12)*5, x2-(width/6), y1+(length/12)*5); // roof up
	drawLine(x1+(width/6), y2-(length/4), x2-(width/6), y2-(length/4)); // roof down
	drawLine(x1+(width/6), y1+(length/12)*5, x1+(width/6), y2-(length/4)); // roof left
	drawLine(x2-(width/6), y1+(length/12)*5, x2-(width/6), y2-(length/4)); // roof right
	
	drawLine(x1+(width/6), y2-(length/4), x1, y2-(length/6)); // back left
	drawLine(x2-(width/6), y2-(length/4), x2, y2-(length/6)); // back right
	
	drawLine(x1, y2-(length/12)*5, x1+(width/6), y2-(length/12)*5); // lateral left
	drawLine(x2-(width/6), y2-(length/12)*5, x2, y2-(length/12)*5); // lateral right
	
	drawLine(x1+(width/6), y1+(length/12)*5, x1, y1+(length/4)); // front left
	drawLine(x2, y1+(length/4), x2-(width/6), y1+(length/12)*5); // front right
	
	drawLine(x1+(width/5), y1, x1+(width/5), y1+(length/7)); // left white headlight (right)
	drawLine(x1, y1+(length/7), x1+(width/5), y1+(length/7)); // left white headlight (down)
	drawLine(x2-(width/5), y1, x2-(width/5), y1+(length/7)); // right white headlight (left)
	drawLine(x2-(width/5), y1+(length/7), x2, y1+(length/7)); // right white headlight (down)
	
	drawLine(x1, y2-(length/13), x1+(width/4), y2-(length/13)); // left red headlight (up)
	drawLine(x1+(width/4), y2-(length/13), x1+(width/4), y2); // left red headlight (right)
	
	drawLine(x2-(width/4), y2-(length/13), x2, y2-(length/13)); // right red headlight (up)
	drawLine(x2-(width/4), y2-(length/13), x2-(width/4), y2); // right red headlight (left)
}

// this function clears enemy objects on game area
void EnemyObject::clear(int unit) {
	usePen(PS_SOLID, unit*2, RGB(255,255,255));
	drawRectangle(x1, y1, x2, y2);
	usePen(PS_NULL);
}

// this function moves enemy objects according to speed unit
void EnemyObject::move(int unit) {
	clear(unit);
	setCoordinates(x1, y1 + unit);
	draw();
}

int EnemyObject::getCurrentX1() {
	return x1;
}

int EnemyObject::getCurrentX2() {
	return x2;
}

int EnemyObject::getCurrentY1() {
	return y1;
}

int EnemyObject::getCurrentY2() {
	return y2;
}

