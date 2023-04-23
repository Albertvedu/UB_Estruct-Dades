//
// Created by albert on 8/03/23.
//
#include "PilaEstatica.h"
#include <iostream>
using namespace std;


PilaEstatica::PilaEstatica(int tamany_maxim){
    this->_front = -1; 
    this->_dades = new int[tamany_maxim];
    this->_capacitat = 0;
    cout << "ESTRUCTURA CREADA DE " << tamany_maxim << " ELEMENTS." << endl;
}

PilaEstatica::PilaEstatica(const PilaEstatica &origen){

    //_front = 0;  //NULL no pirula


    if ( !origen.esBuida()){
        
        this->_front = origen._front;
        this->_capacitat = origen._capacitat;

        for (size_t i = 0; i < origen.tamany(); i++)
            _dades[i] = origen._dades[i];
    }
    else
        cout << "La pila que vols copia és buïda" << endl;
}
PilaEstatica::PilaEstatica(initializer_list<int> elements){

    if (elements.size() <= TAMANY_MAXIM){
        initializer_list<int>::iterator it;
        for (it = elements.begin(); it != elements.end(); ++it)
            afegirElement(*it);
    }else
        throw string("\n\e[1mEXCEPTION: L’estructura que vols inserir es més gran, que l'espai disponible\n\e[0m");
}
PilaEstatica::~PilaEstatica(){
    delete _dades;
}

//CONSULTORS
int PilaEstatica::tamany() const{
    return _capacitat;
}
bool PilaEstatica::esBuida()const{
    return _capacitat == 0;
}
bool PilaEstatica::esPlena() const{
    return _capacitat == TAMANY_MAXIM;
}
int PilaEstatica::elementFront() const{
    if ( !esBuida() ){
        return _dades[_capacitat -1]; 
    }else 
        throw string("\n\e[1mEXCEPTION: L’estructura està buïda\n\e[0m");
  
}
void PilaEstatica::imprimeix() const{
    if ( !esBuida() ){
        cout << "\n[";
        for (size_t i = 0; i < tamany()-1; i++)
            cout << _dades[i] << ", ";
        cout << _dades[_capacitat -1] << "]\n" << endl; 
    }else 
        throw string("\n\e[1mEXCEPTION: L’estructura està buïda\n\e[0m");
}

//MODIFICADORS 
void PilaEstatica::afegirElement(const int &e){
    if ( !esPlena()){
        _dades[_capacitat] = e;
        _capacitat ++;   
    }else 
        throw string("\n\e[1mEXCEPTION: L’estructura està plena\n\e[0m");

}
void PilaEstatica::treureElement(){
    if ( !esBuida()){
        // _dades[_capacitat -1] = 0;  //NULL no pirula
        _capacitat --;
    }else
        throw string("\n\e[1mEXCEPTION: L’estructura està buïda\n\e[0m");
}
