#include <stdlib.h>
#include <GL/glut.h>
float boatX = -0.2f;
float boatY = 0.0f;
float boatZ = -1.0f;
static int flag = 1;
static int flagger = 1;
void triangle();
void water() {
    float x1 = -0.9, x2 = -0.85, y = -0.1;
    int i, j;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 20; j++) {
            glVertex2f(x1, y);
            glVertex2f(x2, y);
            x1 += 0.09;
            x2 += 0.09;
        }
        y -= 0.02;
        x1 = -0.9;
        x2 = -0.85;
    }
    glEnd();
    glFlush();
}
void triangle() {
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(boatX, boatY, boatZ);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.2, 0.0);
    glVertex2f(0.05, 0.0);
    glEnd();
    glFlush();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.075, 0.15);
    glVertex2f(0.075, 0.1);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0.2, 0.14);
    glVertex2f(0.0, -0.1);
    glEnd();
    glFlush();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.075, 0.175, 0);
    glutSolidSphere(0.02, 50, 100);
}
void keyPress(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        boatY += 1.0f;
    if (key == GLUT_KEY_DOWN)
        boatY -= 1.0f;
    if (key == GLUT_KEY_LEFT)
        boatX -= 1.0f;
    if (key == GLUT_KEY_RIGHT)
        boatX += 1.0f;
    glutPostRedisplay();
}
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    water();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    triangle();
    glutSwapBuffers();
}
float rt = 0.5;
void updater(int value) {
    if (flag == 1) {
        boatX += 0.004f;
        if (boatX > 1.2)
            flag = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(1, updater, 5000);
}
void update(int value) {
    if (flag) {
        boatY += 0.01f;
        if (boatY > rt)
            flag = 0;
    }
    rt = rt - 0.001;
    if (!flag) {
        boatY -= 0.01f;
        if (boatY < -0.5)
            flag = 1;
    }
    glutPostRedisplay();
    glutTimerFunc(1, update, 5000);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("BOAT");
    initRendering();
    glutDisplayFunc(drawScene);
    glutSpecialFunc(keyPress);
    glutTimerFunc(30, updater, 5000);
    glutMainLoop();
    return 0;
}
