//
// Created by albert on 9/03/23.
//

#ifndef POSICIO_H
#define POSICIO_H

#include "NodeLlista.h"

template <class Element>
class Posicio{

public:
    Posicio(NodeLlista<Element> *node); // inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio &origen);



    virtual ~Posicio();
    Posicio<Element> next() const; // retorna la següent posició a l’actual
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element &element() const;    // retorna el contingut de l’actual posició
    NodeLlista<Element> *elimina();

    //NO ENTENC... PERQUÈ L'ADREÇA... JA HI HA ANTERIOR .. 
    void fixarAnterior(NodeLlista<Element> *node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element> *node);  // assigna l’adreça del següent node

    Posicio<Element> operator++() const;         // sobrecarrega operador ++
    Posicio<Element> operator--() const;         // sobrecarrega operador --
    bool operator==(const Posicio &other) const; // sobrecarrega operador ==
    bool operator!=(const Posicio &other) const; // sobrecarrega operador !=
    const Element &operator*() const;            // sobrecarrega operador contingut
private:
    NodeLlista<Element> *_node;
};


/*########################################################
#####           .CPP                                 ###
########################################################*/

template<class Element>
Posicio<Element>::Posicio(NodeLlista<Element> *node) {
    this->_node->_element = node->getElement();
    this->_node->setNext(node->getNext);
    this->_node->setPrevious(node->getPrevious);
    
}   

template<class Element>
Posicio<Element>::~Posicio() {
    delete this->_node;
}

template<class Element>
Posicio<Element> Posicio<Element>::next() const {
    return this->_node->getNext();
}

template<class Element>
Posicio<Element> Posicio<Element>::anterior() const {
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

}

template<class Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element> *node) {

}

template<class Element>
Posicio<Element> Posicio<Element>::operator++() const {
    return this->next();
}

template<class Element>
Posicio<Element> Posicio<Element>::operator--() const {
    return Posicio<Element>(nullptr);
}

template<class Element>
bool Posicio<Element>::operator==(const Posicio &other) const {
    return false;
}

template<class Element>
bool Posicio<Element>::operator!=(const Posicio &other) const {
    return false;
}

template<class Element>
const Element &Posicio<Element>::operator*() const {
    return 0;
}

#endif