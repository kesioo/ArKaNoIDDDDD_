#ifndef _CFIGURA_H
#define _CFIGURA_H

#include <iostream>
#include <string>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "cFizyka.h"

using namespace std;

class cFigura:public CFizyka{
protected:
	float alpha;
	float R, G, B;
public:
	cFigura();
	virtual void rysuj() = 0;
	void obroc(float dalpha);
	void przesun(float dx, float dy);
	void idz_do(float q, float r);
	void ustaw_kolor(float r, float g, float b);
	virtual bool czy_kliknieto(float xf, float yf) = 0;

};
#endif