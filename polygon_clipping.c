#include <GL/glut.h>
#include <stdio.h>

int i, n, xmin, xmax, ymin, ymax, side1[10], side2[10], ch;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void getdata() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the coordinates of vertices (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &side1[i], &side2[i]);
    }
}

void polygon1() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw clipping window (cyan)
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(0, 0);
        glVertex2i(100, 0);
        glVertex2i(100, 100);
        glVertex2i(0, 100);
    glEnd();
    glFlush();

    // Draw user polygon (magenta)
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        for (i = 0; i < n; i++) {
            glVertex2i(side1[i], side2[i]);
        }
    glEnd();
    glFlush();

    while (1) {
        printf("\nDo you want to see the clipped polygon?\n");
        printf("1. YES\n2. NO\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                glClear(GL_COLOR_BUFFER_BIT);

                // Redraw clipping window (blue)
                glColor3f(0.0, 0.0, 1.0);
                glBegin(GL_LINE_LOOP);
                    glVertex2i(0, 0);
                    glVertex2i(100, 0);
                    glVertex2i(100, 100);
                    glVertex2i(0, 100);
                glEnd();
                glFlush();

                // Draw clipped polygon (magenta)
                glColor3f(1.0, 0.0, 1.0);
                glBegin(GL_LINE_LOOP);
                    for (i = 0; i < n; i++) {
                        if (side1[i] <= 100 && side1[i] >= 0 && side2[i] <= 100 && side2[i] >= 0) {
                            glVertex2i(side1[i], side2[i]);
                        }
                        else if (side1[i] <= 100 && side1[i] >= 0 && side2[i] > 100) {
                            glVertex2i(side1[i], 100);
                        }
                        else if (side1[i] <= 100 && side1[i] >= 0 && side2[i] < 0) {
                            glVertex2i(side1[i], 0);
                        }
                        else if (side2[i] <= 100 && side2[i] >= 0 && side1[i] > 100) {
                            glVertex2i(100, side2[i]);
                        }
                        else if (side2[i] <= 100 && side2[i] >= 0 && side1[i] < 0) {
                            glVertex2i(0, side2[i]);
                        }
                        else if (side1[i] > 100 && side2[i] > 100) {
                            glVertex2i(100, 100);
                        }
                        else {
                            glVertex2i(0, 0);
                        }
                    }
                glEnd();
                glFlush();
                break;

            case 2:
                exit(0);
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

void main(int argc, char **argv) {
    getdata();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Polygon Clipping");

    glClear(GL_COLOR_BUFFER_BIT);
    init();
    glutDisplayFunc(polygon1);
    glutMainLoop();
}
