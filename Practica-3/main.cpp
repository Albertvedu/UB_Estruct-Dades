#include <iostream>
#include "ArbreBinari.h"
#include <iostream>
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
void cami(const ArbreBinari<int, int> *tree1, int clau) {

    NodeBinari<int, int>* node = tree1->search(clau);
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

        cami(tree1, 40);
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








