#include "MyObject.h"

MyObject::MyObject() {}

MyObject::MyObject(int _width, int x_Coordinate, int y_Coordinate) {
	setDimensions(_width);
	setCoordinates(x_Coordinate, y_Coordinate);
}

 // this function sets dimensions
void MyObject::setDimensions(int _width) {
	width = _width;
	length = width * 2;
}

 // this function sets coordinates
void MyObject::setCoordinates(int x_Coordinate, int y_Coordinate) {
	x1 = x_Coordinate ;
	y1 = y_Coordinate ;
	x2 = x1 + width;
	y2 = y1 + length;
}

// this function draws our object on game area
void MyObject::draw() {
	
	useBrush(1, RGB(160,32,240));
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

// this function clear our object on game area
void MyObject::clear() {
	usePen(PS_SOLID, 71, RGB(255,255,255));
	drawRectangle(x1, y1, x2, y2);
	usePen(PS_SOLID, 0, RGB(0,0,0));
}

// this function moves our object according to mouse coordinates
void MyObject::move(int mouseX) {
	
	if (mouseX > 358) mouseX = 358;
	if (mouseX < 70) mouseX = 70;
	
	clear();
	setCoordinates(mouseX, y1);
	draw();
}

int MyObject::getCurrentX1() {
	return x1;
}

int MyObject::getCurrentX2() {
	return x2;
}

int MyObject::getCurrentY1() {
	return y1;
}

int MyObject::getCurrentY2() {
	return y2;
}
