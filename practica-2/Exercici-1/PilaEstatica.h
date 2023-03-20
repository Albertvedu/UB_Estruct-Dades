#ifndef PILAESTATICA_H
#define PILAESTATICA_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>
using namespace std;

class PilaEstatica{
public:

    PilaEstatica(int tamany_maxim = TAMANY_MAXIM);
    PilaEstatica(const PilaEstatica &origen);
    PilaEstatica(initializer_list<int> elements); //initizalizes the stack from the list
    virtual ~PilaEstatica();

    //CONSULTORS
    int tamany() const;    // return the size
    bool esBuida()const;   // return TRUE if the stack is empty
    bool esPlena() const;  // return TRUE if the stack is full
    int elementFront() const; // return the top element of stack
    void imprimeix() const;  // print all the stack on the terminal

    //MODIFICADORS
    void afegirElement(const int &e); // introduce an element in the stack, exception if it is not possible
    void treureElement(); // remove top element from the stack, exception if it is not possible

private:
    enum {TAMANY_MAXIM = 3};
    int _capacitat;
    int _front;    // top de la pila
    int* _dades;  //stack
};

#endif

