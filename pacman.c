#include <stdlib.h>
#include <GL/glut.h>

float pacX = 0.0f;
float pacY = 0.0f;

void line(void) {
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-.2,0); glVertex2f(-.2,-.2); glVertex2f(.2,-.2);
    glVertex2f(.2,.2); glVertex2f(-.4,.2); glVertex2f(-.4,-.4);
    glVertex2f(.4,-.4); glVertex2f(.4,-.1);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(.4,.1); glVertex2f(.4,.4); glVertex2f(-.6,.4); glVertex2f(-.6,-.4);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-.6,-.5); glVertex2f(-.6,-.6); glVertex2f(.6,-.6);
    glVertex2f(.6,.6); glVertex2f(-.8,.6); glVertex2f(-.8,-.8);
    glVertex2f(.8,-.8); glVertex2f(.8,.8);
    glEnd();
    glFlush();
}

void drawBall(void) {
    line();
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(pacX, pacY, 0.0);
    glutSolidSphere(0.04, 10, 10);
    glPopMatrix();
}

void keyPress(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) pacX += 0.01f;
    if (key == GLUT_KEY_LEFT) pacX -= 0.01f;
    if (key == GLUT_KEY_UP) pacY += 0.01f;
    if (key == GLUT_KEY_DOWN) pacY -= 0.01f;
    glutPostRedisplay();
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBall();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("PacMan Movement");
    initRendering();
    glutDisplayFunc(drawScene);
    glutSpecialFunc(keyPress);
    glutMainLoop();
    return 0;
}