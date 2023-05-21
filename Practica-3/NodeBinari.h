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
    NodeBinari(const NodeBinari<Clau,Valor >& orig);                            // Cost O (1)

    //DESTRUCTORS
    virtual ~NodeBinari();                                                      // Cost O (1)

    /* Modificadors */
    void insertValue(const Valor & v);                                          // Cost O (1)
    void insertKey(const Clau &k);                                              // Cost O (1)
    void setPare( NodeBinari<Clau, Valor>* node);                               // Cost O (1)
    void setLeft( NodeBinari<Clau, Valor>* node) ;                              // Cost O (1)
    void setRight( NodeBinari<Clau, Valor>* node) ;                             // Cost O (1)
    void setKey(Clau key);                                                      // Cost O (1)
    void setValue(Valor valor);                                                 // Cost O (1)

    /* Consultors */
    const Clau& getKey() const;                                                 // Cost O (1)
    const Valor& getValue() const;                                              // Cost O (1)
    NodeBinari<Clau, Valor>* getPare() const;                                   // Cost O (1)
    NodeBinari<Clau, Valor>* getLeft() const;                                   // Cost O (1)
    NodeBinari<Clau, Valor>* getRight() const;                                  // Cost O (1)


    /* CONSULTORS */
    bool isRoot() const;                                                        // Cost O (1)
    bool hasLeft() const;                                                       // Cost O (1)
    bool hasRight() const;                                                      // Cost O (1)
    bool isExternal() const;                                                    // Cost O (1)
    int height() const;                                                         // Cost O (1)
    bool isIsRight() const;                                                     // Cost O (1)
    void setIsRight(bool isRight);                                              // Cost O (1)

    //OPERADORS LOGISCS
    bool operator==(const NodeBinari<Clau,Valor >& node) const;                 // Cost O (1)

private:
    Clau _key;
    Valor _value;
    bool _isRight;        // Necessari per a l'hora d'esborrar, saber quin node es
    int _heightNode;      // Cada node, té un atribut amb l'alçada que està el node
    NodeBinari<Clau, Valor>* _pare;
    NodeBinari<Clau, Valor>* _left;
    NodeBinari<Clau, Valor>* _right;
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
    if (orig != nullptr) {
        this->_key = orig._key;
        this->_value = orig._value;
        this->_pare = orig._pare;
        this->_left = orig._left;
        this->_right = orig._right;
        this->_heightNode = orig._heightNode;
        this->_isRight = orig._isRight;
    }else
        throw invalid_argument("Node que vols copiar és NULL");
}
template <class Clau, class Valor >
NodeBinari<Clau, Valor>::~NodeBinari() {
    //Post: si té node esquerre o node dret, destrueix

    if (hasLeft()) {
        delete _left;
        _left = nullptr;
    }
    if (hasRight()) {
        delete _right;
        _right = nullptr;
    }

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

#endif //PRACTICA_4_NODEBINARI_H
