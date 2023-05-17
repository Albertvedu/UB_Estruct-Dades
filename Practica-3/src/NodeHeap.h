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
    NodeHeap(const Clau& key);
    NodeHeap(const Clau& clau, const Valor& valor);
    NodeHeap(const NodeHeap<Clau,Valor>& orig);

    //DESTRUCTORS
    virtual ~NodeHeap();

    /* Modificadors */
//    void insertValue(const Valor & v);
//    void insertKey(const Clau &k);
//    void setPare( NodeHeap<Clau, Valor>* node);
//    void setLeft( NodeHeap<Clau, Valor>* node) ;
//    void setRight( NodeHeap<Clau, Valor>* node) ;
//    void setKey(Clau key);
//    void setValue(Valor valor);

    /* CONSULTORS */
    /* Consultors */
    const Clau& getKey() const;
    const Valor& getValue() const;
//    int getPare(int i) const;
//    int getLeft(int i) const;
//    int getRight(int i) const;
    int getNivell() const;
    void setNivell(int i);

    //OPERADORS LOGISCS
    bool operator==(const NodeHeap<Clau,Valor >& node) const;
    bool operator!=( NodeHeap<Clau,Valor >& node) ;

private:
    Clau _key;
    Valor _value;
    int _pare;
    int _left;
    int _right;
    int _nivell;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(){
    this->_key = -1;
//    this->_pare = nullptr;
//    this->_left = nullptr;
//    this->_right = nullptr;
    // this->heightArbre = 1; //todo .. revisar
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const Clau& key){
    this->_key = key;
//    this->_pare = nullptr;
//    this->_left = nullptr;
//    this->_right = nullptr;
    // this->heightArbre = 1; //todo .. revisar
}

template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const Clau& clau, const Valor& valor){
    this->_key = clau;
    this->_value = valor;
//    this->_pare = nullptr;
//    this->_left = nullptr;
//    this->_right = nullptr;
//    this->_heightNode = 0;
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::NodeHeap(const NodeHeap<Clau,Valor >& orig){
    //if (orig != nullptr) {
        this->_key = orig._key;
        this->_value = orig._value;
        this->_nivell = orig._nivell;
//        this->_pare = orig._pare;
//        this->_left = orig._left;
   //     this->_right = orig._right;
      //  this->_heightNode = orig._heightNode;
  //      this->_isRight = orig._isRight;
//    }else
//        throw invalid_argument("Node que vols copiar és NULL");
}
template <class Clau, class Valor >
NodeHeap<Clau, Valor>::~NodeHeap(){
//    delete this->_pare;
//    delete this->_left;
//    delete this->_right;
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
//template <class Clau, class Valor >
//int NodeHeap<Clau, Valor>::getPare(int i) const{
//    return (i-1) /2;
//}
//template <class Clau, class Valor >
//int NodeHeap<Clau, Valor>::getLeft(int i) const {
//
//    return ( 2 * i) + 1;
//}
//template <class Clau, class Valor >
//int NodeHeap<Clau, Valor>::getRight(int i) const {
//    return ( 2 * i) + 2;
//}
template <class Clau, class Valor >
int NodeHeap<Clau, Valor>::getNivell() const {
    return this->_nivell;
}
//template <class Clau, class Valor >
//bool NodeHeap<Clau, Valor>::isRoot() const{
//    return false; // todo areglar aixo ..................this->_pare == nullptr;
//}
//template<class Clau, class Valor>
//bool NodeHeap<Clau, Valor>::hasLeft(int i, int tamany) const{
//    return (this->getLeft(i) <= tamany -1) && (this->getLeft(i) >= 0);
//}
//template<class Clau, class Valor>
//bool NodeHeap<Clau, Valor>::hasRight(int i, int tamany) const{
//    return this->getRight(i) <= tamany-1;
//}
//template<class Clau, class Valor>
//bool NodeHeap<Clau, Valor>::isExternal(int i, int tamany) const{
//    return (this->getRight(i) > tamany -1) && (this->getLeft(i) > tamany -1);
//}
//SETTERS
//template <class Clau, class Valor >
//void NodeHeap<Clau, Valor>::setKey(Clau key) {
//    this->_key = key;
//}
//template <class Clau, class Valor >
//void NodeHeap<Clau, Valor>::setValue(Valor valor) {
//    this->_value = valor;
//}
template <class Clau, class Valor >
void NodeHeap<Clau, Valor>::setNivell(int i){
    this->_nivell = i;
}
//template <class Clau, class Valor >
//void NodeHeap<Clau, Valor>::setPare(int i){
//    this->_pare = i;
//}
template <class Clau, class Valor >
bool NodeHeap<Clau, Valor>::operator==(const NodeHeap<Clau,Valor >& node) const{
    return this == node;
}
template <class Clau, class Valor >
bool NodeHeap<Clau, Valor>::operator!=( NodeHeap<Clau,Valor >& node) {
    return this != node;
}
#endif //PRACTICA_3_NODEHEAP_H
