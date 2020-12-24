#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape {
    float x;
    float y;
    float w;
    float h;
    float radius;
    bool solid;
public:
    Circle();
    Circle(float, float, float, float, float);
    Circle(float, float, float, float, float, float);
    
    float getRadius() const;
    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;

    void setRadius(float);
    void setX(float);
    void setY(float);

    void jump();
    bool xRising;
    bool yRising;
    void collide();
    
    void draw() const;
};

#endif
