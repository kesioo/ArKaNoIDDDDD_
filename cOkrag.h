#ifndef _COKRAG_H
#define _COKRAG_H
#include "cFizyka.h"
#include "cFigura.h"

class cOkrag : public cFigura{
protected:
	float r;
	int kolor;
public:
	cOkrag();
	cOkrag(float _r);
	void rysuj();
	bool czy_kliknieto(float xf, float yf);
	
};
#endif