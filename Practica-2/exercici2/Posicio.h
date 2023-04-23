#ifndef POSICIO_H
#define POSICIO_H

#include <iostream>
using namespace std;
#include "NodeLlista.h"

template <class Element>
class Posicio : public error_code {

public:
    //CONSTRUCTOR
    Posicio(NodeLlista<Element> *node); // inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio &origen);

    //DESTRUCTOR
    virtual ~Posicio();

    //CONSULTORS
    Posicio<Element> next() const; // retorna la següent posició a l’actual
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element &element() const;    // retorna el contingut de l’actual posició

    //MODIFICADORS
    NodeLlista<Element> *elimina();
    void fixarAnterior(NodeLlista<Element> *node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element> *node);  // assigna l’adreça del següent node

    //OPERADORS LOGICS
    Posicio<Element> operator++() const;         // sobrecarrega operador ++
    Posicio<Element> operator--() const;         // sobrecarrega operador --
    bool operator==(const Posicio &other) const; // sobrecarrega operador ==
    bool operator!=(const Posicio &other) const; // sobrecarrega operador !=
    const Element &operator*() const;            // sobrecarrega operador contingut
    // ostream& operator<<(ostream& os, const Posicio<Element>& posicio);

    // meu
    NodeLlista<Element> getNode();

private:
    NodeLlista<Element> *_node;
};



/*########################################################
#####           .CPP                                 ###
########################################################*/
template<class Element>
NodeLlista<Element> Posicio<Element>::getNode(){
    return this->_node;
}
template<class Element>
Posicio<Element>::Posicio(NodeLlista<Element> *node) {
    this->_node = node;
}

template <class Element>
Posicio<Element>::~Posicio() {
    // delete this->_node;
}

template<class Element>
Posicio<Element> Posicio<Element>::next() const {
    return this->_node->accedirSeguent();
}

template<class Element>
Posicio<Element> Posicio<Element>::anterior() const {
    return this->_node->accedirAnterior();
}

template<class Element>
const Element &Posicio<Element>::element() const {
    return this->_node->accedirElement();
}
template<class Element>
NodeLlista<Element> *Posicio<Element>::elimina() {
    this->_node->accedirAnterior()->fixarSeguent(this->_node->accedirSeguent());
    this->_node->accedirSeguent()->fixarAnterior(this->_node->accedirAnterior());
    return this->_node;
}

template<class Element>
void Posicio<Element>::fixarAnterior(NodeLlista<Element> *node) {
    this->_node->fixarAnterior(node);
    node->fixarSeguent(this->_node);
}

template<class Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element> *node) {
    this->_node->fixarSeguent(node);
    node->fixarAnterior(this->_node);
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
    return this->_node->accedirElement();
}

//template<class Element>
//ostream& Posicio<Element>::operator<<(ostream &os, const Posicio<Element> &posicio) {
//
//    return os << posicio._node;
//}
#endif //PRACTICA_2_POSICIO_H