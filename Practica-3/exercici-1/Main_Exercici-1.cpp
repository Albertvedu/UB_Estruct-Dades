#include <iostream>
#include "ArbreBinari.h"
#include <unistd.h>

using namespace std;

void inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1) {
    for (int i = 0; i < 8; ++i) {
        tree1->insert(testKeys[i], testValuies[i]);
    }
}
void imprimir(const ArbreBinari<int, int> *tree1) {
    cout << endl;
    tree1->imprimirPreordre(tree1->getRoot());
    tree1->imprimirInordre(tree1->getRoot());
    tree1->imprimirPostordre(tree1->getRoot());
}
void obtenirRang(const vector<NodeBinari<int, int> *> &rang) {
    cout << "ObteValorsRang={ ";

    for(int i = 0; i < rang.size()-1; i++)
        cout << rang[i]->getKey() << ", ";
    cout << rang[rang.size()-1]->getKey() << " }" << endl;
}
void imprimirCamiRecurs(NodeBinari<int, int>* node, int clau){
    cout << node->getKey();

    if ( node->hasRight() || node->hasLeft()) {
        cout  << ", ";

        if (node->getKey() < clau) {
            if (node->hasRight())
                imprimirCamiRecurs(node->getRight(), clau);
        } else
        if (node->hasLeft())
            imprimirCamiRecurs(node->getLeft(), clau);
    }
}
void imprimirCami(const ArbreBinari<int, int> *tree1, const int & clau){
    if ( tree1->isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "ImprimirCami={ ";
        imprimirCamiRecurs(tree1->getRoot(), clau);
        cout << " }" << endl;
    }
}
int main(){


    int testKeys [] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int testValuies[]={5,5,1,88,99,12,9,11};

    try{
        ArbreBinari<int, int>* tree1 = new ArbreBinari<int, int>();
        inserirNodes(testKeys, testValuies, tree1);
        imprimir(tree1);

        vector<NodeBinari<int,int>*> rang = tree1->obteValorsRang(5,45);
        obtenirRang(rang);

        ArbreBinari<int, int>* tree2 = new ArbreBinari<int, int>(tree1);
        tree2->imprimirPostordre(tree2->getRoot());

        //exercici1->cami(exercici1->getProtectedSearch(40));
        imprimirCami(tree1, 40);
        cout << "\n\e[1mEliminar minim\e[0m" << endl;
        tree1->eliminaMinim();
        tree1->imprimirInordre(tree1->getRoot());

        delete tree1;

    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }


    return 0;
}








