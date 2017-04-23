#ifndef _CPROSTOKAT_H
#define _CPROSTOKAT_H
#include "cFizyka.h"
#include "cFigura.h"

class cProstokat : public cFigura {
protected:
	float s, w;
	int kolor;
public:
	cProstokat();
	cProstokat(float _w,float _s);
	void rysuj();
	bool czy_kliknieto(float xf, float yf);

};

#endif