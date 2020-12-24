#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    
    //row1
    TexRect* brick1;
    TexRect* brick2;
    TexRect* brick3;
    TexRect* brick4;
    TexRect* brick5;
    TexRect* brick6;
    TexRect* brick7; 
    
    //row2
    TexRect* brick8;
    TexRect* brick9;
    TexRect* brick10;
    TexRect* brick11;
    TexRect* brick12;
    TexRect* brick13;
    TexRect* brick14;

    //row3
    TexRect* brick15;
    TexRect* brick16;
    TexRect* brick17;
    TexRect* brick18;
    TexRect* brick19;
    TexRect* brick20;
    TexRect* brick21;

    //row4
    TexRect* brick22;
    TexRect* brick23;
    TexRect* brick24;
    TexRect* brick25;
    TexRect* brick26;
    TexRect* brick27;
    TexRect* brick28;

    //row5
    TexRect* brick29;
    TexRect* brick30;
    TexRect* brick31;
    TexRect* brick32;
    TexRect* brick33;
    TexRect* brick34;
    TexRect* brick35;

    //row6
    TexRect* brick36;
    TexRect* brick37;
    TexRect* brick38;
    TexRect* brick39;
    TexRect* brick40;
    TexRect* brick41;
    TexRect* brick42;

    TexRect* background;
    TexRect* game_end;

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    TexRect* platform;
    Circle* ball;
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);

    void idle();
    bool moving;

};

#endif
