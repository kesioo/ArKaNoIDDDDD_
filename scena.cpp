#include "scena.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

cScena scena;
/***********************************************/
void przerysuj()
{
	scena.rysuj();
}
/*******************/
cScena::cScena(){
	aktywny = -1;
}
/*******************/
void cScena::rysuj(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	for (auto f = figury.begin(); f != figury.end(); f++)
	{
		(*f)->rysuj();
	}
	glPopMatrix();
	glutSwapBuffers();
}
/*************************************/
void cScena::aktualizuj()

{
	int czas = GetTickCount(); //zwraca czas w [ms]
		for (int i = 0; i< figury.size(); i++)
			figury[i]->Aktualizuj(czas); //obliczanie nowych polozen
										 //wykrywanie kolizji
		for (int i = 0; i< figury.size() - 1; i++)
			for (int j = i + 1; j<figury.size(); j++)
				if (figury[i]->Kolizja(*figury[j])) //znajduje kolizje
				{
					cKlocek*k = dynamic_cast<cKlocek*>(figury[j]);
					if (k != NULL)
					{
						if(k->od)
						k->odbicie();
					}
				}

}

/*************************************/
void cScena::init()
{
	cOkrag *okr = new cOkrag(0.6);
	okr->setPredkosc(0.03, 210);
	
	okr->przesun(0, 10);
	figury.push_back(okr);
	cProstokat *paletka = new cProstokat(2, 7);
	paletka->setPredkosc(0, 0);
	paletka->setFizyka(0, 0);
	paletka->idz_do(0, -24);
	figury.push_back(paletka);
	//(-37.5, 0, 5, 75, 0.5, 0.5, 0.5));
	cProstokat *sciana1 = new cProstokat(50, 2);
	sciana1->setPredkosc(0, 0);
	sciana1->setFizyka(0, 0);
	sciana1->idz_do(-28,0);
	figury.push_back(sciana1);
	cProstokat *sciana2 = new cProstokat(50, 2);
	sciana2->setPredkosc(0, 0);
	sciana2->setFizyka(0, 0);
	sciana2->idz_do(28, 0);
	figury.push_back(sciana2);
	cProstokat *sufit = new cProstokat(2, 58);
	sufit->setPredkosc(0, 0);
	sufit->idz_do(0, 25);
	figury.push_back(sufit);
	/*
	cKlocek *k0 = new cKlocek(0.2, 0.1, 0.5, 0.5, 0.5, 1, 1);
	k0->przesun(0, 0.2);
	*/
	cKlocek *kl0 = new cKlocek(10, 0.5, 0.5, 0.5, 0.50, 0, 0);
	kl0->idz_do(-10, 20);
	figury.push_back(kl0);
	
	/*cProstokat *pr0 = new cProstokat(2,20);
	pr0->setPredkosc(0, 0);
	pr0->setFizyka(0, 0);
	pr0->przesun(0, -7);
	figury.push_back(pr0);
	cProstokat *pr1 = new cProstokat(20, 2);
	pr1->setPredkosc(0, 0);
	pr1->setFizyka(0, 0);
	pr1->przesun(10, 2);
	figury.push_back(pr1);
	cProstokat *pr2 = new cProstokat(20, 2);
	pr2->setPredkosc(0, 0);
	pr2->setFizyka(0, 0);
	pr2->przesun(-10, 02);
	figury.push_back(pr2);
	*/

}
void cScena::mysz_aktywnie(int x1, int y1)
{
	int szerokosc_okna, wysokosc_okna;
	szerokosc_okna = glutGet(GLUT_WINDOW_WIDTH);
	wysokosc_okna = glutGet(GLUT_WINDOW_HEIGHT);
	figury[1]->idz_do((((double)x1 - (szerokosc_okna / 2))) / ((wysokosc_okna) / 38), -24);
}
void mysz_aktywna(int x, int y)
{
	scena.mysz_aktywnie(x, y);
}
void idle()
{
	scena.loop();
	glutPostRedisplay();
	glutPassiveMotionFunc(::mysz_aktywna);
	Sleep(1);
}
void cScena::loop()
{
	//sprawdzanie kolizji ze œcianami
	for (int i = 1; i < figury.size(); i++)
	{
		if (figury[0]->Kolizja(*figury[i]));
	}
	//wyliczenie nowej pozycji pi³ki
	figury[0]->Aktualizuj(GetTickCount());
	figury[0]->Reset();

	Sleep(1);
}
/****************************************/
void cScena::inicjuj(){
	glutInitWindowPosition(200,0);
	glutInitWindowSize(1000, 700);
	init();
	glutIdleFunc(idle);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//| GLUT_DEPTH | GLUT_MULTISAMPLE
	glutCreateWindow("Prostokaty");
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(::przerysuj);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30, 30, -30,30, -30,30);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********************************************/