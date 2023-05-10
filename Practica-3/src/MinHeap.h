//
// Created by albert on 7/05/23.
//

#ifndef PRACTICA_3_MINHEAP_H
#define PRACTICA_3_MINHEAP_H

#include <iostream>
#include <vector>
#include "NodeHeap.h"

using namespace std;
template<class Clau, class Valor>
class MinHeap {
public:
    MinHeap(); // constructor
    MinHeap<Clau,Valor> (const MinHeap<Clau,Valor>&);

   // MinHeap(const vector<NodeHeap<Clau, Valor>> &data, int mida);

    // constructor còpia
    int tamany();
    // retorna el nombre d'elements que hi ha al heap
    bool isEmpty() const; // retorna cert si és buit, fals en cas contrari
    void inserir(const Clau& clau, const Valor& valor);
    Clau minim();
    // retorna la clau mínima
    Valor valorMinim(); // retorna el valor de la clau mínima
    void eliminaMinim(); // elimina el node amb valor minim
    void imprimir(); // Imprimeix per pantalla tot el Heap, una línia per a cada _nivell de l'arbre
//    Valor cerca(const Clau& clau); // cerca al heap una clau donada
    int altura(); // retorna l'alçada del heap


private:
    vector< NodeHeap<Clau, Valor>> _data;

    int _mida;
    int _size;
    int _height;

// MÈTODES PRIVATS
    void upHeap(NodeHeap<Clau, Valor> node, int i);
    void calcularAltura(NodeHeap<Clau, Valor> &node, int &altura, int &i);
    int verificarAltura( NodeHeap<Clau, Valor> &node, int i);
    void reOrdenarArbre();

protected:
    NodeHeap<Clau, Valor> _root;
    const NodeHeap<Clau, Valor> &getRoot() const;
    int getHeight() const;
public:


public:

};

#endif //PRACTICA_3_MINHEAP_H


/*########################################################
#####           .CPP                                 ###
########################################################*/

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap() {
    this->_mida = 8;
    this->_height = 0;
    this->_root = NodeHeap<Clau, Valor>();
    this->_size = 0;
}

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(const MinHeap<Clau,Valor>& copia){
    this->_mida = 8;

}
template<class Clau, class Valor>
bool MinHeap<Clau, Valor>::isEmpty() const{
    return this->_size == 0;
}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::tamany(){
    return this->_size;
}
template<class Clau, class Valor>
Clau MinHeap<Clau, Valor>::minim(){
    return this->_root.getKey();
}
template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::valorMinim(){
    return this->_root.getValue();
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::inserir(const Clau& clau, const Valor& valor){
    auto node = NodeHeap<Clau, Valor>(clau, valor);
    this->_data.push_back(node);

    if (this->isEmpty()) {
        this->_root = node;
        this->_root.setNivell(1);
        this->_size ++;
        this->_data[tamany()-1].setNivell(1);

    }
    else {
        this->_size ++;
        int cas = node.getPare(tamany()-1);
        int xx = this->_data[node.getPare(tamany()-1)].getNivell();
        this->_data[tamany()-1].setNivell(xx +1);
        node.setNivell(xx +1);

        upHeap(node, tamany() -1);
    }


}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::upHeap(NodeHeap<Clau, Valor> node, int i){
    int pare = node.getPare(i);
    int pos = i;

    while (this->_data[pare].getKey() > this->_data[pos].getKey()){
        this->_data[pos] = this->_data[pare];
        this->_data[pos].setNivell(this->_data[pos].getNivell() +1);
        this->_data[pare] = node;
        this->_data[pare].setNivell( this->_data[pos].getNivell() -1 );

        if (pare == 0)
            this->_root = this->_data[pare];
        pos = pare;
        pare = node.getPare(pare);
    }
}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::verificarAltura( NodeHeap<Clau, Valor> &node, int i){
    int altura = 1;
    if ( i <= 0)
        return altura;

    altura =  1 + verificarAltura(this->_data[node.getPare(i)], node.getPare(i));
    return  altura;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::calcularAltura(NodeHeap<Clau, Valor> &node, int &altura, int &i){
    if ( i >= 0 || i < tamany() -1) {
        if (this->_data[i].isExternal(i, tamany())) {
            altura = verificarAltura(node, i);

            if (this->_height < altura)          // Es queda amb el valor més alt
                this->_height = altura;
        } else {

            if (node.hasLeft(i, tamany())) {
                int w = node.getLeft(i);
                calcularAltura(this->_data[node.getLeft(i)], altura, w);
            }

            if (node.hasRight(i, tamany())) {
                int w = node.getRight(i);
                calcularAltura(this->_data[node.getRight(i)], altura, w);
            }
        }
    }else
        throw invalid_argument("Node és Nullptr");

}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::altura(){
    NodeHeap<Clau, Valor> node = this->_root;
    int altura = 1;
    int i = 0;
    if (isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        calcularAltura(this->_root, altura, i);
        return this->_height;
    }

  //  return 0;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::imprimir() {
    int x = 3;
    cout << this->_data[0].getKey() << endl;

    for (int i = 1; i < tamany(); i++) {
        if (this->_data[i].getNivell() == x){
            cout <<  endl;
            x = this->_data[i].getNivell() +1;
        }
        cout << this->_data[i].getKey() << "   ";
    }
    cout << endl;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::reOrdenarArbre(){
    for (int i = 1; i < tamany(); ++i)
            upHeap(this->_data[i], i);
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::eliminaMinim(){
    if (isEmpty())
        throw invalid_argument("L'arbre està buit, no hi ha res a esborrar");
    this->_data.erase(this->_data.begin());
    this->_size --;
    this->_height = 0;
    this->_root = this->_data[0];

    reOrdenarArbre();
}

template<class Clau, class Valor>
const NodeHeap<Clau, Valor> &MinHeap<Clau, Valor>::getRoot() const {
    return _root;
}

template<class Clau, class Valor>
int MinHeap<Clau, Valor>::getHeight() const {
    return _height;
}
