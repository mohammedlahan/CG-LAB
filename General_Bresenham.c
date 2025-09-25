#include<stdio.h>
#include<GL/glut.h>
float x1;
float Y1;
float x2;
float y2;
void data(){
printf("Enter the first coordinate: ");
scanf("%f %f",&x1,&Y1);
printf("Enter the second coordinate: ");
scanf("%f %f",&x2,&y2);
}
int sign(float a,float b)
{
if((b-a)>0)
return (1);
else if((b-a)<0)
return (-1);
else
return (0);
}
void init(){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,150.0);
}
void general(){
float x,y,dx,dy,e=0.0;
int s1,s2,i,temp;
int flag=0;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POINTS);
x=x1;
y=Y1;
dx=abs(x2-x1);
dy=abs(y2-Y1);
s1=sign(x1,x2);
s2=sign(Y1,y2);
if(dy>dx){
       temp=dx;
       dx=dy;
       dy=temp;
       flag=1;
}
else
flag=0;
e=2*dy-dx;
for(i=1;i<dx;i++)
{
glVertex2f(x,y);
while(e>0)
{
if(flag==1)
{
x=x+s1;
}
else
y=y+s2;
e=e-2*dx;
}
if(flag==1)
y=y+s2;
else
x=x+s1;
e=e+2*dy;
}
glEnd();
glFlush();
}
void main(int argc,char **argv){
data();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,50);
glutInitWindowSize(400,300);
glutCreateWindow("Line");
init();
glutDisplayFunc(general);
glutMainLoop();
}
