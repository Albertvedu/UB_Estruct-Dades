//
// Created by albert on 20/04/23.
//

#ifndef PRACTICA_3_NODEBINARI_H
#define PRACTICA_3_NODEBINARI_H
#include <iostream>
using namespace std;

template <class Clau, class Valor >
class NodeBinari {
public:
    // CONSTRUCTORS
    NodeBinari(const Clau& key);
    NodeBinari(const Clau& clau, const Valor& valor);
    NodeBinari(const NodeBinari<Clau,Valor >& orig);

    //DESTRUCTORS
    virtual ~NodeBinari();

    /* Modificadors */
    void insertValue(const Valor & v);
    void insertKey(const Clau &k);
    void setPare( NodeBinari<Clau, Valor>* node);
    void setLeft( NodeBinari<Clau, Valor>* node) ;
    void setRight( NodeBinari<Clau, Valor>* node) ;
    void setKey(Clau key);
    void setValue(Valor valor);

    /* Consultors */
    const Clau& getKey() const;
    const Valor& getValue() const;
    NodeBinari<Clau, Valor>* getPare() const;
    NodeBinari<Clau, Valor>* getLeft() const;
    NodeBinari<Clau, Valor>* getRight() const;


    /* Operacions */
    bool isRoot() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool isExternal() const;
    int height() const;
    bool operator==(const NodeBinari<Clau,Valor >& node) const;

    bool isIsRight() const;

    void setIsRight(bool isRight);
    int getHeightNode() ;
    void setHeightNode(int h);
private:
    Clau _key;
    Valor _value;
    bool _isRight;        // Necessari per a l'hora d'esborrar, saber quin node es
    int _heightNode;
    NodeBinari<Clau, Valor>* _pare;
    NodeBinari<Clau, Valor>* _left;
    NodeBinari<Clau, Valor>* _right;
    //int heightArbre;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor >
NodeBinari<Clau, Valor>::NodeBinari(const Clau& key){
    this->_key = key;
    this->_pare = nullptr;
    this->_left = nullptr;
    this->_right = nullptr;
   // this->heightArbre = 1; //todo .. revisar
}

template <class Clau, class Valor >
NodeBinari<Clau, Valor>::NodeBinari(const Clau& clau, const Valor& valor){
    this->_key = clau;
    this->_value = valor;
    this->_pare = nullptr;
    this->_left = nullptr;
    this->_right = nullptr;
    this->_heightNode = 0;
}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>::NodeBinari(const NodeBinari<Clau,Valor >& orig){

}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>::~NodeBinari(){

}

/* Modificadors */
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::insertValue(const Valor & v){
    this->_value = v;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::insertKey(const Clau &k){
    this->_key = k;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setPare( NodeBinari<Clau, Valor>* node) {
    this->_pare = node;
}

template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setLeft( NodeBinari<Clau, Valor>* node) {
    this->_left = node;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setRight( NodeBinari<Clau, Valor>* node) {
    this->_right = node;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setKey(Clau key) {
    this->_key = key;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setValue(Valor valor) {
    this->_value = valor;
}
/* Consultors */
template <class Clau, class Valor >
const Clau& NodeBinari<Clau, Valor>::getKey() const{
    return this->_key;
}
template <class Clau, class Valor >
const Valor& NodeBinari<Clau, Valor>::getValue() const{
    return this->_value;
}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getPare() const{
    return this->_pare;
}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getLeft() const {
    return this->_left;
}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>* NodeBinari<Clau, Valor>::getRight() const {
    return this->_right;
}

template<class Clau, class Valor>
bool NodeBinari<Clau, Valor>::isIsRight() const {
    return _isRight;
}

template<class Clau, class Valor>
void NodeBinari<Clau, Valor>::setIsRight(bool isRight) {
    this->_isRight = isRight;
}

/* Operacions */
template <class Clau, class Valor >
bool NodeBinari<Clau, Valor>::isRoot() const{
    return this->_pare == nullptr;
}
template <class Clau, class Valor >
bool NodeBinari<Clau, Valor>::hasLeft() const{
    return this->_left != nullptr;
}
template <class Clau, class Valor >
bool NodeBinari<Clau, Valor>::hasRight() const{
    return this->_right != nullptr;
}
template <class Clau, class Valor >
bool NodeBinari<Clau, Valor>::isExternal() const{
    return !this->hasRight() && !this->hasLeft();
}

template <class Clau, class Valor >
int NodeBinari<Clau, Valor>::height() const{
    return this->heightArbre;
}
template <class Clau, class Valor >
bool NodeBinari<Clau, Valor>::operator==(const NodeBinari<Clau,Valor >& node) const{
    return this->_key == node._key && this->_key == node._key;
}
template <class Clau, class Valor >
int NodeBinari<Clau, Valor>::getHeightNode() {
    return this->_heightNode;
}
template <class Clau, class Valor >
void NodeBinari<Clau, Valor>::setHeightNode(int h) {
    this->_heightNode = h;
}
#endif //PRACTICA_4_NODEBINARI_H
