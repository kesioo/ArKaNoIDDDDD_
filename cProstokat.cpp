#include "cProstokat.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "cProstokat.h"
/******************************/
cProstokat::cProstokat(){
	w = 0.1; s = 0.2;
	x = 0; y = 0;
	setGeometria(x, y, x - (s / 2), y - (w / 2), x + (s / 2), y + (w / 2));
}
/**************************/
cProstokat::cProstokat(float _w, float _s)
{
	s = _s; w = _w;
	setGeometria(x, y, -(s / 2), -(w / 2), (s / 2), (w / 2));
	
}

/**************************/
void cProstokat::rysuj(){
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glVertex2f(-s / 2, w / 2);
		glVertex2f(s / 2, w / 2);
		glVertex2f(s / 2, -w/ 2);
		glVertex2f(-s / 2, -w / 2);
	}
	glEnd();
	glPopMatrix();
}
/****************************/
bool cProstokat::czy_kliknieto(float xf, float yf){
	float openglX = ((float)xf - 400) / 800 * s;
	float openglY = ((float)yf - 400) / 800 * w;
	if (fabs(openglX - x) <s / 2 && fabs(openglY - y) < w / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
