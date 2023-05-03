//
// Created by albert on 28/04/23.
//

#ifndef PRACTICA_3_EXERCICI_1_H
#define PRACTICA_3_EXERCICI_1_H

#include <iostream>
#include "ArbreBinari.h"


class Exercici_1 {
public:
    Exercici_1();
    // Post: Executa el Test del Exercici

private:
    //MÈTODES PRIVATS
    void inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1);
    //Post: arbre _tree1 en memòria dinàmica amb tots el nodes de pel·licules

    void imprimir(const ArbreBinari<int, int> *tree1);
    //Post: Imprimeix en PreOrdre, InOrdre i PostOrdre

    void imprimirRang(const vector<NodeBinari<int, int> *> &rang);
    //Pre: vector amb els valors obtinguts del mètode obtenirRang de la classe ArbreBinari
    //Post: imprimeix valors del vector rang.

    void imprimirCami(const ArbreBinari<int, int> *tree1, const int & clau);
    //Post: Imprimeix el cami a seguir, des de l'arrel fins a la clau donada

    void imprimirCamiRecurs(NodeBinari<int, int>* node, int clau);
    //Post: forma recursiva del mètode imprimir cami

    void executarTest_Exercici_1();
    //Post: Main del Exercici 1

    //ATRIBUTS PRIVATS
    int _testKeys[8] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int _testValuies[8] = {5, 5, 1, 88, 99, 12, 9, 11};

    ArbreBinari<int, int>* _tree1;
    ArbreBinari<int, int>* _tree2;
};


#endif //PRACTICA_3_EXERCICI_1_H
