#ifndef PRACTICA_2_MAINEXERCICI2_H
#define PRACTICA_2_MAINEXERCICI2_H

#include <iostream>
#include "Posicio.h"
#include "Llista.h"

using namespace std;

class MainExercici2{
    public:
        MainExercici2();
    private:
        void compare(int valor, int limitA, int limitB);
        bool esNumero(char *lectura);

        int llegirStringTOint(string text, int limitA, int limitB);
        template <class Element>
        Posicio<Element> inserirEnUnaPosicio(int pos, const Llista<Element> *pLlista);

        void llegirParaula(string &paraula);
        bool inserirDades( string text);
        int llegirPos(int tamany);
        void print(Llista<string> *l1);
        void printReverse(Llista<string> *l1 );
        void primerNode(Llista<string> *l1, int &nParaules);

};


#endif