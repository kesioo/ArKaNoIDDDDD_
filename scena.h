#ifndef _SCENA_H
#define _SCENA_H
#include "cFizyka.h"
#include <vector>
#include "cKlocek.h"
#include "cFigura.h"
#include "cProstokat.h"
#include "cOkrag.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

class cScena{
protected:
	int aktywny;
	vector<cFigura*> figury;
public:
	cScena();
	void rysuj();
	void inicjuj();
	void init();
	void aktualizuj();
	void loop();
	void mysz_aktywnie(int x1, int y1);
	
	
};
extern cScena scena;

#endif