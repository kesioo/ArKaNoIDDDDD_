#ifndef _CKLOCEK_H
#define _CKLOCEK_H
#include "scena.h"
#include "cProstokat.h"

class cKlocek : public cProstokat {
protected:
	int punktacja;
	int odpornosc;
public:
	cKlocek();
	cKlocek(float _R, float _G, float _B, int _p, int _o);
	cKlocek(float _a, float _b, float _R, float _G, float _B, int _p, int _o);
	void odbicie();
	int punkty();
};
#endif