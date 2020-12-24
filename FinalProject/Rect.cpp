#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rect::Rect() : Shape() {
    n = 0;
    x = -0.2;
    y = 0.2;
    w = 0.4;
    h = 0.4;
}

Rect::Rect(float x, float y, float w, float h) : Shape() {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b) : Shape(r, g, b) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

float Rect::getX() const {
    return x;
}
float Rect::getY() const {
    return y;
}
float Rect::getW() const {
    return w;
}
float Rect::getH() const {
    return h;
}

void Rect::setScore(float score){
	this->n = score;
}
void Rect::setX(float x) {
    this->x = x;
}
void Rect::setY(float y) {
    this->y = y;
}
void Rect::setW(float w) {
    this->w = w;
}
void Rect::setH(float h) {
    this->h = h;
}

bool Rect::contains(float mx, float my) const {
    return mx >= x && mx <= x + w && my <= y && my >= y - h;
}
