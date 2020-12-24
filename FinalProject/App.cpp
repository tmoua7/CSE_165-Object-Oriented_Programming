#include "App.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>

template <typename T>
std::string ToString(T val) {
    std::stringstream stream;
    stream << val;
    return stream.str();
}

int score = 0;

bool gameOver = false;


void drawResult(void *font, const char s[], float x, float y) {
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen(s); i++) {
	glutBitmapCharacter(font, s[i]);
    }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

    moving = false;

    platform = new TexRect("bar.bmp", 1, 1, -0.2, -0.8, 0.4, 0.07);

    ball = new Circle(.02, 0, 0, 1, 1, 1);

    background = new TexRect("bg.bmp", 1, 1, -1, 1, 2, 2);
    game_end = new TexRect("gameover.bmp", 1, 1, -1, 1, 2, 2);


    //row1
    brick1 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09, 0.2571, 0.09);
    brick2 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09, 0.2571, 0.09);
    brick3 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09, 0.2571, 0.09);
    brick4 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09, 0.2571, 0.09);
    brick5 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 -0.09, 0.2571, 0.09);
    brick6 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09, 0.2571, 0.09);
    brick7 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09, 0.2571, 0.09);

    //row2
    brick8 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09*2, 0.2571, 0.09);
    brick9 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09*2, 0.2571, 0.09);
    brick10 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09*2, 0.2571, 0.09);
    brick11 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09*2, 0.2571, 0.09);
    brick12 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 - 0.09*2, 0.2571, 0.09);
    brick13 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09*2, 0.2571, 0.09);
    brick14 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09*2, 0.2571, 0.09);

    //row3
    brick15 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09*3, 0.2571, 0.09);
    brick16 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09*3, 0.2571, 0.09);
    brick17 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09*3, 0.2571, 0.09);
    brick18 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09*3, 0.2571, 0.09);
    brick19 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 - 0.09*3, 0.2571, 0.09);
    brick20 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09*3, 0.2571, 0.09);
    brick21 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09*3, 0.2571, 0.09);

    //row4
    brick22 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09*4, 0.2571, 0.09);
    brick23 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09*4, 0.2571, 0.09);
    brick24 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09*4, 0.2571, 0.09);
    brick25 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09*4, 0.2571, 0.09);
    brick26 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 - 0.09*4, 0.2571, 0.09);
    brick27 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09*4, 0.2571, 0.09);
    brick28 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09*4, 0.2571, 0.09);

    //row5
    brick29 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09*5, 0.2571, 0.09);
    brick30 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09*5, 0.2571, 0.09);
    brick31 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09*5, 0.2571, 0.09);
    brick32 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09*5, 0.2571, 0.09);
    brick33 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 - 0.09*5, 0.2571, 0.09);
    brick34 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09*5, 0.2571, 0.09);
    brick35 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09*5, 0.2571, 0.09);

    //row6
    brick36 = new TexRect("greenbrick.bmp", 1, 1, -0.9, 0.9 - 0.09*6, 0.2571, 0.09);
    brick37 = new TexRect("redbrick.bmp", 1, 1, -0.9 + 0.2571*1, 0.9 - 0.09*6, 0.2571, 0.09);
    brick38 = new TexRect("bluebrick.bmp", 1, 1, -0.9 + 0.2571*2, 0.9 - 0.09*6, 0.2571, 0.09);
    brick39 = new TexRect("greenbrick.bmp", 1, 1, -0.9 + 0.2571*3, 0.9 - 0.09*6, 0.2571, 0.09);
    brick40 = new TexRect("greenbrick.bmp", 1, 1, 0.9 - 0.2571*1, 0.9 - 0.09*6, 0.2571, 0.09);
    brick41 = new TexRect("bluebrick.bmp", 1, 1, 0.9 - 0.2571*2, 0.9 - 0.09*6, 0.2571, 0.09);
    brick42 = new TexRect("redbrick.bmp", 1, 1, 0.9 - 0.2571*3, 0.9 - 0.09*6, 0.2571, 0.09);

}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glClearDepth(-0.2f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    background->draw();

    glClearDepth(0.99f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    background->draw();
    
    platform->draw();
    ball->draw();

    brick1->draw();
    brick2->draw();
    brick3->draw();
    brick4->draw();
    brick5->draw();
    brick6->draw();
    brick7->draw();

    brick8->draw();
    brick9->draw();
    brick10->draw();
    brick11->draw();
    brick12->draw();
    brick13->draw();
    brick14->draw();

    brick15->draw();
    brick16->draw();
    brick17->draw();
    brick18->draw();
    brick19->draw();
    brick20->draw();
    brick21->draw();

    brick22->draw();
    brick23->draw();
    brick24->draw();
    brick25->draw();
    brick26->draw();
    brick27->draw();
    brick28->draw();
    
    brick29->draw();
    brick30->draw();
    brick31->draw();
    brick32->draw();
    brick33->draw();
    brick34->draw();
    brick35->draw();

    brick36->draw();
    brick37->draw();
    brick38->draw();
    brick39->draw();
    brick40->draw();
    brick41->draw();
    brick42->draw();

    if(gameOver) {
	game_end->draw();
	
	drawResult(GLUT_BITMAP_TIMES_ROMAN_24, "SCORE:", -0.4, -0.8);
	
	std::string scoree = ToString(score);
	const char *pchar = scoree.c_str();
	moving = false;
	glColor3d(0.0, 1.0, 0.0);
	drawResult(GLUT_BITMAP_TIMES_ROMAN_24, pchar, 0.1, -0.8);
    }
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scenedddddadd
    redraw();
}

void App::idle(){
    if (moving){
        ball->jump();
        redraw();
    }
    if (
	(ball->getX() > platform->getX()) &&
	(ball->getX() < (platform->getX() + platform->getW())) &&
	(ball->getY() > platform->getY()) &&
	(ball->getY()) < (platform->getY() + platform->getH() - 0.05)
	) {
		ball->collide();
    }

    float bx = ball->getX() + ball->getW()/2;
    float by = ball->getY() - ball->getH() + 0.1;

    if (
	brick1->contains(bx, by) || brick30->contains(bx, by) || brick31->contains(bx, by) ||
	brick2->contains(bx, by) || brick29->contains(bx, by) || brick32->contains(bx, by) ||
	brick3->contains(bx, by) || brick28->contains(bx, by) || brick33->contains(bx, by) ||
	brick4->contains(bx, by) || brick27->contains(bx, by) || brick34->contains(bx, by) ||
	brick5->contains(bx, by) || brick26->contains(bx, by) || brick35->contains(bx, by) ||
	brick6->contains(bx, by) || brick25->contains(bx, by) || brick36->contains(bx, by) ||
	brick7->contains(bx, by) || brick24->contains(bx, by) || brick37->contains(bx, by) ||
	brick8->contains(bx, by) || brick23->contains(bx, by) || brick38->contains(bx, by) ||
	brick9->contains(bx, by) || brick22->contains(bx, by) || brick39->contains(bx, by) ||
	brick10->contains(bx, by) || brick21->contains(bx, by) || brick40->contains(bx, by) ||
	brick11->contains(bx, by) || brick20->contains(bx, by) || brick41->contains(bx, by) ||
	brick12->contains(bx, by) || brick19->contains(bx, by) || brick42->contains(bx, by) ||
	brick13->contains(bx, by) || brick18->contains(bx, by) || 
	brick14->contains(bx, by) || brick17->contains(bx, by) ||
	brick15->contains(bx, by) || brick16->contains(bx, by)
	){
	    ball->collide();   
    }

    if (brick1->contains(bx,by)){ brick1->deletethis(); score += 100;}
    if (brick2->contains(bx,by)){ brick2->deletethis(); score += 100;}    
    if (brick3->contains(bx,by)){ brick3->deletethis(); score += 100;}
    if (brick4->contains(bx,by)){ brick4->deletethis(); score += 100;}	
    if (brick5->contains(bx,by)){ brick5->deletethis(); score += 100;}
    if (brick6->contains(bx,by)){ brick6->deletethis(); score += 100;}
    if (brick7->contains(bx,by)){ brick7->deletethis(); score += 100;}
    if (brick8->contains(bx,by)){ brick8->deletethis(); score += 100;}
    if (brick9->contains(bx,by)){ brick9->deletethis(); score += 100;}
    if (brick10->contains(bx,by)){ brick10->deletethis(); score += 100;}
    if (brick11->contains(bx,by)){ brick11->deletethis(); score += 100;}
    if (brick12->contains(bx,by)){ brick12->deletethis(); score += 100;}
    if (brick13->contains(bx,by)){ brick13->deletethis(); score += 100;}
    if (brick14->contains(bx,by)){ brick14->deletethis(); score += 100;}
    if (brick15->contains(bx,by)){ brick15->deletethis(); score += 100;}
    if (brick16->contains(bx,by)){ brick16->deletethis(); score += 100;}
    if (brick17->contains(bx,by)){ brick17->deletethis(); score += 100;}
    if (brick18->contains(bx,by)){ brick18->deletethis(); score += 100;}
    if (brick19->contains(bx,by)){ brick19->deletethis(); score += 100;}
    if (brick20->contains(bx,by)){ brick20->deletethis(); score += 100;}
    if (brick21->contains(bx,by)){ brick21->deletethis(); score += 100;}
    if (brick22->contains(bx,by)){ brick22->deletethis(); score += 100;}
    if (brick23->contains(bx,by)){ brick23->deletethis(); score += 100;}
    if (brick24->contains(bx,by)){ brick24->deletethis(); score += 100;}
    if (brick25->contains(bx,by)){ brick25->deletethis(); score += 100;}
    if (brick26->contains(bx,by)){ brick26->deletethis(); score += 100;}
    if (brick27->contains(bx,by)){ brick27->deletethis(); score += 100;}
    if (brick28->contains(bx,by)){ brick28->deletethis(); score += 100;}
    if (brick29->contains(bx,by)){ brick29->deletethis(); score += 100;}
    if (brick30->contains(bx,by)){ brick30->deletethis(); score += 100;}
    if (brick31->contains(bx,by)){ brick31->deletethis(); score += 100;}
    if (brick32->contains(bx,by)){ brick32->deletethis(); score += 100;}
    if (brick33->contains(bx,by)){ brick33->deletethis(); score += 100;}
    if (brick34->contains(bx,by)){ brick34->deletethis(); score += 100;}
    if (brick35->contains(bx,by)){ brick35->deletethis(); score += 100;}
    if (brick36->contains(bx,by)){ brick36->deletethis(); score += 100;}
    if (brick37->contains(bx,by)){ brick37->deletethis(); score += 100;}
    if (brick38->contains(bx,by)){ brick38->deletethis(); score += 100;}
    if (brick39->contains(bx,by)){ brick39->deletethis(); score += 100;}
    if (brick40->contains(bx,by)){ brick40->deletethis(); score += 100;}
    if (brick41->contains(bx,by)){ brick41->deletethis(); score += 100;}
    if (brick42->contains(bx,by)){ brick42->deletethis(); score += 100;}

    if (ball->getY() < -1.1) {
	gameOver = true;
    }

    if (score == 4200) {
	gameOver = true;
    }

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
	delete platform;
	delete ball;
    if (score == 0) {
	delete brick1;
	delete brick2;
	delete brick3;
	delete brick4;
	delete brick5;
	delete brick6;
	delete brick7;
	
	delete brick8;
	delete brick9;
	delete brick10;
	delete brick11;
	delete brick12;
	delete brick13;
	delete brick14;
    
	delete brick15;
	delete brick16;
	delete brick17;
	delete brick18;
	delete brick19;
	delete brick20;
	delete brick21;

	delete brick22;
	delete brick23;
	delete brick24;
	delete brick25;
	delete brick26;
	delete brick27;
	delete brick28;

	delete brick29;
	delete brick30;
	delete brick31;
	delete brick32;
	delete brick33;
	delete brick34;
	delete brick35;

	delete brick36;
	delete brick37;
	delete brick38;
	delete brick39;
	delete brick40;
	delete brick41;
	delete brick42;
    }
        exit(0);	
    }
    if (key == 'a' && moving == true) {
	if ((platform->getX() - 0.04)  > -1) {
		platform->setX(platform->getX() - 0.2f);
	}
    }
    if (key == 'd' && moving == true) {
	if ((platform->getX() + 0.4) < 1) {
		platform->setX(platform->getX() + 0.2f);
	}
    }
    if (moving == true) {
	if (key == ' ') {
		moving = false;
	}
    } else if (moving == false) {
	if (key == ' ') {
		moving = true;
	}
    }
    
    redraw();

}
