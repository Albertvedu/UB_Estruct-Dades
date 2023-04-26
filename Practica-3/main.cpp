#include <iostream>
#include "ArbreBinari.h"
#include <iostream>
#include <unistd.h>

#include "Exercici_1.h"


using namespace std;

int main(){
    Exercici_1<int, int>* exercici1 = new Exercici_1<int, int>();

    int testKeys [] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int testValuies[]={5,5,1,88,99,12,9,11};

    try{
        ArbreBinari<int, int>* tree1 = new ArbreBinari<int, int>();
        exercici1->inserirNodes(testKeys, testValuies, tree1);
        exercici1->imprimir(tree1);

        vector<NodeBinari<int,int>*> rang = tree1->obteValorsRang(5,45);
        exercici1->obtenirRang(rang);

        ArbreBinari<int, int>* tree2 = new ArbreBinari<int, int>(tree1);
        tree2->imprimirPostordre(tree2->getRoot());

        //exercici1->cami(exercici1->getProtectedSearch(40));
        exercici1->cami(tree1, 40);
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








