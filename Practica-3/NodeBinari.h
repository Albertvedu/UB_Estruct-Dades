//
// Created by albert on 20/04/23.
//

#ifndef PRACTICA_4_NODEBINARI_H
#define PRACTICA_4_NODEBINARI_H
#include <iostream>
using namespace std;

template <class Clau, class Valor >
class NodeBinari {
public:
    NodeBinari(const Clau& key);
    NodeBinari(const Clau& clau, const Valor& valor);
    NodeBinari(const NodeBinari<Clau,Valor >& orig);
    virtual ~NodeBinari();

    /* Modificadors */
    // declareu aquí els modificadors (setters) dels atributs que necessiteu
    void insertValue(const Valor & v);
    void insertKey(const Clau &k);
    void setPare( NodeBinari<Clau, Valor>* node);
    void setLeft( NodeBinari<Clau, Valor>* node) ;
    void setRight( NodeBinari<Clau, Valor>* node) ;

    /* Consultors */
    const Clau& getKey() const;
    const Valor& getValue() const;
    NodeBinari<Clau, Valor>* getPare() const;
    NodeBinari<Clau, Valor>* getLeft() const;
    NodeBinari<Clau, Valor>* getRight() const;
    // declareu aquí els consultors (getters) dels atributs que necessiteu
    /* Operacions */
    bool isRoot() const;
    bool hasLeft() const;
    bool hasRight() const;
    bool isExternal() const;

    int height() const;
    bool operator==(const NodeBinari<Clau,Valor >& node) const;

    bool isIsRight() const;

    void setIsRight(bool isRight);

private:
    Clau _key;
    Valor _value;
    bool _isRight;        // Necessari per a l'hora d'esborrar, saber quin node es
    NodeBinari<Clau, Valor>* _pare;
    NodeBinari<Clau, Valor>* _left;
    NodeBinari<Clau, Valor>* _right;
    int heightArbre;
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
    return false;
}

#endif //PRACTICA_4_NODEBINARI_H