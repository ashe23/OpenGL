#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;


class Draw {
    Draw();

    ~Draw();

public:
    void drawChessField();

    void drawCircle();

    void drawTriangle();

    void drawSquare();

private:
    void clearScreen() {
        glClearColor(1, 1, 1, 0.5);
        glClear(GL_COLOR_BUFFER_BIT);
    }
};


void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.5f); // White and opaque
}

const GLdouble DEG2RAD = M_PI / 180;

void drawCircle() {
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 1);
    GLfloat r = 0.5;
//    for(GLfloat r=0.1;r<=1;r+=0.01) {
    for (int i = 0; i < 360; i++) {
        GLdouble degInRad = i * DEG2RAD;
        glVertex2d(cos(degInRad) * r, sin(degInRad) * r);
    }
//    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle();
    glFlush();
//    glEnable(GL_BLEND);
//    // Drawing chess field
//    glBegin(GL_QUADS);
//    glColor3f(0, 0, 1);
//
//    int count = 0;
//    GLfloat step = 0.125;
//    for (GLfloat x = 0; x <= 1; x += step) {
//        for (GLfloat y = 0; y <= 1; y += step) {
//            if (!(count % 2))
//                glColor3f(0, 0, 1);
//            else
//                glColor3f(1, 1, 1);
//            glVertex2f(x, y);
//            glVertex2f(x, y + step);
//            glVertex2f(x + step, y + step);
//            glVertex2f(x + step, y);
//            count++;
//        }
//    }
//    glEnd();
//    glFlush();
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv) {

    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(600, 600);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Chess Field");  // Create window with the given title
//    gluOrtho2D(0, 1, 0, 1);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event

//    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}

