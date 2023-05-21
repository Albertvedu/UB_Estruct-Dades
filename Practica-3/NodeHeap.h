//
// Created by albert on 7/05/23.
//

#ifndef PRACTICA_3_NODEHEAP_H
#define PRACTICA_3_NODEHEAP_H

#include <iostream>
using namespace std;

template <class Clau, class Valor >
class NodeHeap{
public:
    //CONSTRUCTORS
    NodeHeap();
    NodeHeap(const Clau& key);                                                       // Cost O(1)
    NodeHeap(const Clau& clau, const Valor& valor);                                  // Cost O(1)
    NodeHeap(const NodeHeap<Clau,Valor>* orig);                                      // Cost O(1)

    //DESTRUCTORS
    virtual ~NodeHeap();   // utilitzem memèria estàtica. Aquest destructor és innecessari.

    /* CONSULTORS */
    const Clau& getKey() const;                                                           // Cost O(1)
    const Valor& getValue() const;                                                       // Cost O(1)
    int getNivell() const;                                                               // Cost O(1)
    void setNivell(int i);                                                               // Cost O(1)

    //OPERADORS LOGISCS
    bool operator==(const NodeHeap<Clau,Valor >& node) const;     // No utilitzats
    bool operator!=( NodeHeap<Clau,Valor >& node) ;                // No utilitzats

private:
    Clau _key;
    Valor _value;
    int _nivell;
};

/*########################################################
  #####           .CPP                                 ###
  ########################################################*/

template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(){
    this->_key = -1;
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const Clau& key){
    this->_key = key;
}

template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const Clau& clau, const Valor& valor){
    this->_key = clau;
    this->_value = valor;
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const NodeHeap<Clau,Valor >* orig){
    if (orig != nullptr) {
        this->_key = orig->_key;
        this->_value = orig->_value;
        this->_nivell = orig->_nivell;
    }else
        throw invalid_argument("Node que vols copiar és NULL");
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::~NodeHeap(){
  // utilitzem memèria estàtica. Aquest destructor és innecessari.
}

/* Consultors */
template <class Clau, class Valor >
const Clau& NodeHeap<Clau, Valor>::getKey() const{
    return this->_key;
}
template <class Clau, class Valor >
const Valor& NodeHeap<Clau, Valor>::getValue() const{
    return this->_value;
}
template <class Clau, class Valor >
int NodeHeap<Clau, Valor>::getNivell() const {
    return this->_nivell;
}

template <class Clau, class Valor >
void NodeHeap<Clau, Valor>::setNivell(int i){
    this->_nivell = i;
}

template <class Clau, class Valor >
bool NodeHeap<Clau, Valor>::operator==(const NodeHeap<Clau,Valor >& node) const{
    return this == node;
}
template <class Clau, class Valor >
bool NodeHeap<Clau, Valor>::operator!=( NodeHeap<Clau,Valor >& node) {
    return this != node;
}
#endif //PRACTICA_3_NODEHEAP_H
