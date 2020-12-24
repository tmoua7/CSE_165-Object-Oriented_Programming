#ifndef Rect_h
#define Rect_h

#include "Shape.h"

class Rect : public Shape{
protected:
    int n;
    float x;
    float y;
    float w;
    float h;
    
public:
    Rect();
    Rect(float, float, float, float);
    Rect(float, float, float, float, float, float, float);
    
    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;
    
    void setScore(float);
    void setX(float);
    void setY(float);
    void setH(float);
    void setW(float);
    
    void draw();
    
    bool contains (float, float) const;
};

#endif
