//
// Created by albert on 20/04/23.
//

#ifndef PRACTICA_4_ARBREBINARI_H
#define PRACTICA_4_ARBREBINARI_H

#include "NodeBinari.h"
#include <vector>
#include <iostream>

using namespace std;

template <class Clau, class Valor>
class ArbreBinari {
public:
    //CONSTRUCTORS
    ArbreBinari();
    ArbreBinari(ArbreBinari<int, int> *orig);

    //DESTRUCTOR
     virtual ~ArbreBinari();

    //CONSULTORS
    bool isEmpty() const;
    int height() const;
    const Valor& valueOf(const Clau& clau) const;
    void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const;
    vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const;
    void imprimirCami(Clau _key) const;
    NodeBinari<Clau, Valor> *getRoot() const;
    void setRoot(NodeBinari<Clau, Valor> *root);

    //MODIFICADORS
    NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);
    void eliminaMinim();

protected:
    NodeBinari<Clau,Valor>* root;
public://todo aixo es protected
    NodeBinari<Clau,Valor>* search(const Clau& k) const;

private:
    int _size;
    NodeBinari<Clau, Valor>* _node;

    /* Mètodes auxiliars definiu aquí els que necessiteu */
    NodeBinari<Clau, Valor>* cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const;
    void imprimirOrdreRecurs(const NodeBinari<Clau,Valor>* n, string ordre ) const;
    vector<NodeBinari<Clau,Valor>*> buscarRang(NodeBinari<Clau,Valor>* node, int k1, int k2, vector<NodeBinari<Clau,Valor>*> rangVector) const;
    void copyArbre(NodeBinari<Clau, Valor>* node);
    void rutinaEsquerra(const NodeBinari<Clau,Valor>* n, string ordre ) const;
    void rutinaDreta(const NodeBinari<Clau,Valor>* n, string ordre ) const;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(){
    this->root = nullptr;
    this->_node = nullptr;
    this->_size = 0;
    cout << "\n\e[1mArbre binari creat\e[0m\n" << endl;
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::copyArbre(NodeBinari<Clau, Valor>* node){
    insert(node->getKey(), node->getValue());
    if ( node->hasLeft())
        copyArbre(node->getLeft());

    if (node->hasRight())
        copyArbre(node->getRight());
}
template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(ArbreBinari<int, int> *orig){
    if ( orig->isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << endl;
        copyArbre(orig->root);
        cout << "\n\e[1mArbre binari copiat\e[0m" << endl;
    }
}

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::~ArbreBinari(){

    NodeBinari<Clau, Valor>* node = this->root;
    NodeBinari<Clau, Valor>* nodeAux;
    cout << "DESTRUCTOR........................ " << endl;
    while( node != nullptr){
        while ( node->hasLeft() ){
            node = node->getLeft();
        }

        while ( node->hasRight() ){
            node = node->getRight();
        }

        if (node->isExternal()){

            nodeAux = node;

            if (node->getPare() != nullptr) {
                node->isIsRight() ? node->getPare()->setRight(nullptr) :
                    node->getPare()->setLeft(nullptr);
            }
            cout << "Eliminat "<< node->getKey() << endl;
            delete node;
            node = nodeAux->getPare();
        }
    }
    cout << "Arbre binari destruït" << endl;
}

template <class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const{
    return this->root == nullptr;
}

template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() const{
    return this->_node->height();
}

template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::insert(const Clau& clau, const Valor& value){

    NodeBinari<Clau, Valor>* nodeNou= new NodeBinari<Clau, Valor>(clau, value);

    if(isEmpty()) {
        this->root = nodeNou;
        this->_node = root;

    }
    else{
        this->_node = cercarPosicioInsercio(clau, root);          //Recorre arbre per trobar posició inserció.
        nodeNou->setPare(this->_node);

//        while (nodeAux != nullptr){
//            nodeAux->setHeightNode(nodeAux->getHeightNode() +1);
//            nodeAux = nodeAux->getPare();
//        }

       // nodeNou->setHeightNode(1);


        if( clau < this->_node->getKey() ){
            this->_node->setLeft(nodeNou);
            this->_node->getLeft()->setIsRight(false);   // Indico que aquest node, és node de la dreta
        }
        else{
            this->_node->setRight(nodeNou);
            this->_node->getRight()->setIsRight(true);
        }

    }
    this->_size ++;
    cout << "Inserta a l’arbre element " << nodeNou->getKey() << endl;

    return nodeNou;
}

template <class Clau, class Valor>
const Valor& ArbreBinari<Clau, Valor>::valueOf(const Clau& clau) const{
    //Post: Retorna el valor del node del cual li donem la clau
    return search(clau)->getValue();
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPreordre(const NodeBinari<Clau,Valor>* n ) const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "PreOrdre = { ";
        imprimirOrdreRecurs(n, "Pre");
        cout << " } " << endl;
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirInordre(const NodeBinari<Clau,Valor>* n) const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "InOrdre = { ";
        imprimirOrdreRecurs(n, "In");
        cout << " } " << endl;
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirPostordre(const NodeBinari<Clau,Valor>* n ) const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "PostOrdre = { ";
        imprimirOrdreRecurs(n, "Post");
        cout << " } " << endl;
    }
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::rutinaEsquerra(const NodeBinari<Clau,Valor>* n, string ordre ) const{
    if (n->hasLeft()) {
        if (ordre == "Pre") cout << ", " ;           // Control de la coma
        imprimirOrdreRecurs(n->getLeft(), ordre);
        if (ordre != "Pre" ) cout << ", " ;
    }
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::rutinaDreta(const NodeBinari<Clau,Valor>* n, string ordre ) const{
    if (n->hasRight()) {
        if (ordre != "Post") cout << ", " ;                // Control de la coma
        imprimirOrdreRecurs(n->getRight(), ordre);
        if (ordre == "Post") cout << ", " ;
    }
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirOrdreRecurs(const NodeBinari<Clau,Valor>* n, string ordre ) const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        if (ordre == "Pre"){
            cout << n->getKey();
            rutinaEsquerra(n, ordre);    // Verifica si hi ha node esquerra
            rutinaDreta(n, ordre);       // Verifica si hi ha node dreta
        }
        if (ordre == "In"){
            rutinaEsquerra(n, ordre);   // Verifica si hi ha node esquerra
            cout << n->getKey();
            rutinaDreta(n, ordre);       // Verifica si hi ha node dreta
        }
        if (ordre == "Post"){
            rutinaEsquerra(n, ordre);   // Verifica si hi ha node esquerra
            rutinaDreta(n, ordre);       // Verifica si hi ha node dreta
            cout << n->getKey();
        }
    }
}

template <class Clau, class Valor>
vector<NodeBinari<Clau,Valor>*> ArbreBinari<Clau, Valor>::buscarRang(NodeBinari<Clau,Valor>* node, int k1, int k2, vector<NodeBinari<Clau,Valor>*> rangVector) const{
    //Post: Retorna un vector amb el nodes que hi ha entre el rangVector donat
    if (node->hasLeft())
        rangVector = buscarRang(node->getLeft(), k1, k2, rangVector);

    if( (node->getKey() >= k1) && (node->getKey() <= k2) )
        rangVector.push_back(node);

    if (node->hasRight())
        rangVector = buscarRang(node->getRight(), k1, k2, rangVector);

    return rangVector;

}
template <class Clau, class Valor>
vector<NodeBinari<Clau,Valor>*> ArbreBinari<Clau, Valor>::obteValorsRang(int k1, int k2) const{
    vector<NodeBinari<Clau,Valor>*> rangVector;
    return buscarRang(this->root, k1, k2, rangVector);
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau _key) const{
  //  NodeBinari<Clau, Valor> n =
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim(){

    if ( isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        NodeBinari<Clau, Valor>* node = this->root;      // Crea un node amb el root

        while ( node->hasLeft() )                     // Recorre mentres hi hagi node esquerra
            node = node->getLeft();

        //Elimina el node amb la clau mínima.
        node->getPare()->setLeft(nullptr);           // Treu conexió del node Pare amb el node eliminat
        delete node;                                 //  Elimina node de memòria
    }
}

////Mètodes Protected
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::search(const Clau& k) const{
    //Mètode Iteratiu.
    NodeBinari<Clau, Valor>* node = this->root;      // Crea un node amb el root
    while(k != node->getKey()) {
        while (k < node->getKey())
            if (node->hasLeft())
                node = node->getLeft();
            else
                throw invalid_argument("\n\e[1mEl node no existeix\e[0m");
        while (k > node->getKey())
            if (node->hasRight())
                node = node->getRight();
            else
                throw invalid_argument("\n\e[1mEl node no existeix\e[0m");
    }
    return node;

}

// MÈTODES PRIVATS

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* ArbreBinari<Clau, Valor>::cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const {
    //Pre: Clau i Node Pare.
    //Post: Retorna el node Pare, on haurà d'insertar el Node nou.
    if (clau == node->getKey())           // Clau repetida retorna missatge error
        throw invalid_argument("No pot haver una clau repetida");
    if(clau < node->getKey())
        if (node->hasLeft())
            return cercarPosicioInsercio(clau, node->getLeft());
        else
            return node;
    else
        if (node->hasRight())
            return cercarPosicioInsercio(clau, node->getRight());
        else
            return node;
}

template<class Clau, class Valor>
NodeBinari<Clau, Valor> *ArbreBinari<Clau, Valor>::getRoot() const {
    return root;
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::setRoot(NodeBinari<Clau, Valor> *root) {
    ArbreBinari::root = root;
}

template <class Clau, class Valor>
class Prova : ArbreBinari<Clau, Valor>{
public:
    void useSearch(){
      //  search();
    }
};
#endif //PRACTICA_4_ARBREBINARI_H



