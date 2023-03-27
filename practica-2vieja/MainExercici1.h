#ifndef PRACTICA_2_MAINEXERCICI1_H
#define PRACTICA_2_MAINEXERCICI1_H

#include <iostream>
#include "PilaEstatica.h"
#include "vector"
using namespace std;

class MainExercici1{
public:
    MainExercici1();
private:
    void compare(int valor, int limitA, int limitB);
    bool esNumero(char *lectura);

    int llegirStringTOint(string text, int limitA, int limitB);

    void menu(int &opcio, vector<string> opMenu);
    void empilar(PilaEstatica &p);
    void desempilar(PilaEstatica &p);
    void veureCim(PilaEstatica &p);
    void veurePila(PilaEstatica &p);
    void posicioCim(PilaEstatica &p);
    void casProva1(PilaEstatica &p);
};

#endif //PRACTICA_2_MAINEXERCICI1_H
