//
// Created by albert on 28/04/23.
//

#include <csignal>
#include "Exercici_1.h"

Exercici_1::Exercici_1() {
//     _testKeys = {2, 0, 8, 45, 76, 5, 3, 40 };
//     _testValuies = {5, 5, 1, 88, 99, 12, 9, 11};
    _tree1 = new ArbreBinari<int, int>();
    executarTest_Exercici_1();
}
void Exercici_1::inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1) {
    for (int i = 0; i < 8 ; ++i) {
        tree1->insert(testKeys[i], testValuies[i]);
    }
}
void Exercici_1::imprimir(const ArbreBinari<int, int> *tree1) {
    cout << endl;
    tree1->imprimirPreordre(tree1->getRoot());
    tree1->imprimirInordre(tree1->getRoot());
    tree1->imprimirPostordre(tree1->getRoot());
}
void Exercici_1::imprimirRang(const vector<NodeBinari<int, int> *> &rang) {
    cout << "ObteValorsRang = { ";

    for(int i = 0; i < rang.size()-1; i++)
        cout << rang[i]->getKey() << ", ";
    cout << rang[rang.size()-1]->getKey() << " }" << endl;
}
void Exercici_1::imprimirCamiRecurs(NodeBinari<int, int>* node, int clau){
    cout << node->getKey();

    if ( node->getKey() != clau && (node->hasRight() || node->hasLeft()) ) {
        cout << ", ";

        if (node->getKey() < clau) {
            if (node->hasRight())
                imprimirCamiRecurs(node->getRight(), clau);
        } else
        if (node->hasLeft())
            imprimirCamiRecurs(node->getLeft(), clau);
    }
}
void Exercici_1::imprimirCami(const ArbreBinari<int, int> *tree1, const int & clau){
    if ( tree1->isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "ImprimirCami={ ";
        imprimirCamiRecurs(tree1->getRoot(), clau);
        cout << " }" << endl;
    }
}
void Exercici_1::executarTest_Exercici_1(){

    try{
        inserirNodes(_testKeys, _testValuies, _tree1);
        imprimir(_tree1);
        cout << "Height:  " << _tree1->height() << endl;

        vector<NodeBinari<int,int>*> rang = _tree1->obteValorsRang(5, 45);
        imprimirRang(rang);

        _tree2 = new ArbreBinari<int, int>(_tree1);
        _tree2->imprimirPostordre(_tree2->getRoot());
        imprimirCami(_tree1, 40);
        cout << "\n\e[1mEliminar minim\e[0m" << endl;
        _tree1->eliminaMinim();
        _tree1->imprimirInordre(_tree1->getRoot());

        delete _tree1;

    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        cout << "L'EXERCICI 1 A PETAT..... a saltat una execpció" << endl;
        sleep(1);
    }
}