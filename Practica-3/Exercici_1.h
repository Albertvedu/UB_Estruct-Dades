//
// Created by albert on 26/04/23.
//

#ifndef PRACTICA_4_EXERCICI_1_H
#define PRACTICA_4_EXERCICI_1_H

#include "ArbreBinari.h"

template <class Clau, class Valor>
class Exercici_1: protected ArbreBinari<Clau, Valor>{
public:
    Exercici_1();
    void inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1);
    void imprimir(const ArbreBinari<int, int> *tree1);
    void obtenirRang(const vector<NodeBinari<int, int> *> &rang);
    void cami(const ArbreBinari<int, int> *tree1, const int &clau);
    NodeBinari<Clau,Valor>* getProtectedSearch(const ArbreBinari<int, int> *tree1, const int clau);

protected:
   // NodeBinari<Clau,Valor>* searchProtected(const int &clau, const ArbreBinari<int, int> *tree1 ) const;
};


/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
Exercici_1<Clau, Valor>::Exercici_1() {

}
template <class Clau, class Valor>
void Exercici_1<Clau, Valor>::inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1) {
    for (int i = 0; i < 8; ++i) {
        tree1->insert(testKeys[i], testValuies[i]);
    }
}
template <class Clau, class Valor>
void Exercici_1<Clau, Valor>::imprimir(const ArbreBinari<int, int> *tree1) {
    cout << endl;
    tree1->imprimirPreordre(tree1->getRoot());
    tree1->imprimirInordre(tree1->getRoot());
    tree1->imprimirPostordre(tree1->getRoot());
}
template <class Clau, class Valor>
void Exercici_1<Clau, Valor>::obtenirRang(const vector<NodeBinari<int, int> *> &rang) {
    cout << "ObteValorsRang={ ";

    for(int i = 0; i < rang.size()-1; i++)
        cout << rang[i]->getKey() << ", ";
    cout << rang[rang.size()-1]->getKey() << " }" << endl;
}


template <class Clau, class Valor>
NodeBinari<Clau,Valor>* Exercici_1<Clau, Valor>::getProtectedSearch(const ArbreBinari<int, int> *tree1, const int clau){
    //return ArbreBinari<int, int>::search(clau);
    return tree1->search(clau);
}

template <class Clau, class Valor>
void Exercici_1<Clau, Valor>::cami(const ArbreBinari<int, int> *tree1, const int &clau) {
    NodeBinari<int, int>* node = tree1->search(clau); //getProtectedSearch(tree1, clau);    // tree1->search(clau);
    vector<NodeBinari<int,int>*> cami;
    cami.push_back(node);

    while (node->getPare() != nullptr) {
        cami.push_back(node->getPare());
        node = node->getPare();
    }
    cout << "ImprimirCami = { ";
    for(int i = cami.size()-1; i >= 1; i--)
        cout << cami[i]->getKey()<< ", ";
    cout << cami[0]->getKey() << " }" << endl;
}
#endif //PRACTICA_4_EXERCICI_1_H
