//
// Created by albert on 9/03/23.
//

#ifndef POSICIO_H
#define POSICIO_H
#include <iostream>
using namespace std;
#include "NodeLlista.h"

template <class Element>
class Posicio : public error_code {

public:
    Posicio(NodeLlista<Element> *node); // inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio &origen);
    virtual ~Posicio();
    Posicio<Element> next() const; // retorna la següent posició a l’actual
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element &element() const;    // retorna el contingut de l’actual posició
    NodeLlista<Element> *elimina();

    void fixarAnterior(NodeLlista<Element> *node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element> *node);  // assigna l’adreça del següent node

    Posicio<Element> operator++() const;         // sobrecarrega operador ++
    Posicio<Element> operator--() const;         // sobrecarrega operador --
    bool operator==(const Posicio &other) const; // sobrecarrega operador ==
    bool operator!=(const Posicio &other) const; // sobrecarrega operador !=
    const Element &operator*() const;            // sobrecarrega operador contingut
   // ostream& operator<<(ostream& os, const Posicio<Element>& posicio);

    //metode creat per jo
    NodeLlista<Element>* getNode();

private:
    NodeLlista<Element> *_node;
};


/*########################################################
#####           .CPP                                 ###
########################################################*/

template<class Element>
Posicio<Element>::Posicio(NodeLlista<Element> *node) {
    this->_node = node;
//    this->_node->setNext(node->getNext());
//    this->_node->setPrevious(node->getPrevious());
    
}   

template <class Element>
Posicio<Element>::~Posicio() {

    //delete this->_node;  
}
template <class Element>
NodeLlista<Element>* Posicio<Element>::getNode(){
    if (this->_node == nullptr)
        throw invalid_argument( "Punter és NULL" );
    return this->_node;
}
template<class Element>
Posicio<Element> Posicio<Element>::next() const {
    if (this->_node->getNext() == nullptr)
        throw invalid_argument( "Punter és NULL" );
    return this->_node->getNext();
}

template<class Element>
Posicio<Element> Posicio<Element>::anterior() const {
    if (this->_node->getPrevious() == nullptr)
        throw invalid_argument( "Punter és NULL" );
    return this->_node->getPrevious();
}

template<class Element>
const Element &Posicio<Element>::element() const {
    return this->_node->getElement();
}
template<class Element>
NodeLlista<Element> *Posicio<Element>::elimina() {
    this->_node->getPrevious()->setNext(this->_node->getNext());
    this->_node->getNext()->setPrevious(this->_node->getPrevious());
    return this->_node->getElement(); // retorna element eliminat.. suposo que per mostrar-lo
}

template<class Element>
void Posicio<Element>::fixarAnterior(NodeLlista<Element> *node) {
    this->_node->setPrevious(node);
    node->setNext(this->_node);
    
}

template<class Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element> *node) {
    this->_node->setNext(node);
    node->setPrevious(this->_node);
}

template<class Element>
Posicio<Element> Posicio<Element>::operator++() const {
    return this->next();
}

template<class Element>
Posicio<Element> Posicio<Element>::operator--() const {
    return this->anterior();
}

template<class Element>
bool Posicio<Element>::operator==(const Posicio &other) const {
    return this->_node == other._node;
}

template<class Element>
bool Posicio<Element>::operator!=(const Posicio &other) const {
    return this->_node != other._node;
}

template <class Element>
const Element &Posicio<Element>::operator*() const {
    return 0;
}

//template<class Element>
//ostream& Posicio<Element>::operator<<(ostream &os, const Posicio<Element> &posicio) {
//
//    return os << posicio._node;
//}
#endif