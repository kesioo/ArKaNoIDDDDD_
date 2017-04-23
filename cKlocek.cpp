#include "cKlocek.h"

cKlocek::cKlocek() {
	punktacja = (rand() % 5) + 1;
	odpornosc = (rand() % 2) + 1;
	w = 1; s = 3;
}
/*******************/
cKlocek::cKlocek(float _R, float _G, float _B, int _p, int _o) {
	R = _R;
	G = _G;
	B = _B;
	punktacja = _p;
	odpornosc = _o;
}
/********************/
cKlocek::cKlocek(float _a, float _b, float _R, float _G, float _B, int _p, int _o) {
	s = _a; w = _b; R = _R; G = _G; B = _B;
	punktacja = _p;
	odpornosc = _o;
	setGeometria(x, y, -(w / 2), -(s / 2), (w / 2), (s / 2));
}
/********************/
void cKlocek::odbicie() {
	odpornosc--;
	if (odpornosc <= 0)
		widoczny = false;
}
/**********************/
int cKlocek::punkty() {
	if (widoczny) return 0;
	else return punktacja;
}