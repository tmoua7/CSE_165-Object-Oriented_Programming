#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Circle.h"


Circle::Circle() : Shape() {
    x = 0;
    y = 0;
    radius = 1;
    solid = true;
}

Circle::Circle(float radius, float x, float y, float w, float h) : Shape() {
    this->radius = radius;
    this->x = x;
    this->y = y;
    this->h = h;
    this->w = w;
    solid = true;
    xRising = true;
    yRising= true;
}

Circle::Circle(float radius, float x, float y, float r, float g, float b) : Shape(r, g, b) {
    this->radius = radius;
    this->x = x;
    this->y = y;
    solid = true;
    xRising = true;
    yRising = true;
}

float Circle::getRadius() const {
    return radius;
}

float Circle::getX() const {
    return x;
}

float Circle::getY() const {
    return y;
}
float Circle::getW() const {
    return w;
}
float Circle::getH() const {
    return h;
}

void Circle::setRadius(float radius) {
    this->radius = radius;
}

void Circle::setX(float x) {
    this->x = x;
}

void Circle::setY(float y) {
    this->y = y;
}

void Circle::jump() {
    if (yRising) {
        y += 0.01;
    }
    if (!yRising) {
        y -= 0.01;
    }
    if (y > 0.99){
        yRising = false;
    }
	if (y < -0.99) {
		//yRising = true;
	}
	if (xRising) {
		x += 0.01;
	}
	if (!xRising) {
		x -= 0.01;
	}
	if (x > 0.99) {
		xRising = false;
	}
	if (x < -0.99) {
		xRising = true;
	}

}

void Circle::collide() {
		
	if (yRising){
		yRising = false;
		y += 0.01;
		x += 0.015;
	}else if (!yRising){
		yRising = true;
		x -= 0.015;
		y -= 0.01;
		}
	jump();

}


void Circle::draw() const {
    
    float inc = 0.01;
    
    glColor3f(r, g, b);
    
    if(solid){
        glBegin(GL_POLYGON);
        for (float theta = 0; theta < 2 * M_PI; theta += inc) {
            glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
        }
        glEnd();
    }
    else {
        glBegin(GL_LINES);
        for (float theta = 0; theta < 2 * M_PI; theta += inc) {
            glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
            glVertex2f(radius * cos(theta + inc) + x, radius * sin(theta + inc) + y);
        }
        
        glEnd();
    }
    
    
    
    
    
}
