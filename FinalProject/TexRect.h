#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    int rows;
    int cols;

public:
    TexRect (const char*, int, int, float, float, float, float);

    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;
    
    void deletethis();
    void setX(float);
    void setY(float);
    void setH(float);
    void setW(float);

    bool contains (float, float) const;
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();

    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
};

#endif
