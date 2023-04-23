#ifndef MAINEXERCICI2_H
#define MAINEXERCICI2_H
#include "Posicio.h"
#include "Llista.h"
#include "NodeLlista.h"

class MainExercici2{
public:
    MainExercici2();
    ~MainExercici2();
    void inici();

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