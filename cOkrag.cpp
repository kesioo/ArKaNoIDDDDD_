#include "cOkrag.h"

cOkrag::cOkrag(){
	r = 0.1;
	x = 0; y = 0;
	setGeometria(x, y, x - r, y - r, x + r, y + r);
}
/************************/
cOkrag::cOkrag(float _r)
{
	x =0; y =0; r = _r; kolor =1;
	setGeometria(x, y, x - r, y - r, x + r, y + r);
}
/************************/
void cOkrag::rysuj() {
	glPushMatrix();
	glColor3f(0.5, 0.1, 1);
	glTranslatef(x, y, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (float kat = 0; kat<360; kat += 10)
	{
		GLfloat x, y;
		x = r*cos(kat / 180 * 3.14);
		y = r*sin(kat / 180 * 3.14);
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
}
/**********************************************/
bool cOkrag::czy_kliknieto(float xf, float yf){
	float openglX = ((float)xf - 400) / 800 * 2 * x;
	float openglY = ((float)yf - 400) / 800 * y;
	if (fabs(openglX - x) < x&&fabs(openglY - y) < y)
	{
		return true;
	}
	else
	{
		return false;
	}
}