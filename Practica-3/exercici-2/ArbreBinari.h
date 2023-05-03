//
// Created by albert on 20/04/23.
//

#ifndef PRACTICA_3_ARBREBINARI_H
#define PRACTICA_3_ARBREBINARI_H

#include "NodeBinari.h"
#include "Movie.h"
#include <vector>
#include <iostream>
#include <cstdlib>


using namespace std;

template <class Clau, class Valor>
class ArbreBinari {
public:
    //CONSTRUCTORS
    ArbreBinari();
    ArbreBinari(ArbreBinari<Clau, Valor> *orig);

    //DESTRUCTOR
     virtual ~ArbreBinari();

    //CONSULTORS
    bool isEmpty() const;    // Cost (O) 1
    int height() ;           // Cost (O) log n
    const Valor& valueOf(const Clau& clau) const;                                   // Cost (O) 1
    void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const;         // Cost (O) n log n
    void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const;          // Cost (O) n log n
    void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const;        // Cost (O) n log n
    vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const;           // Cost (O) log n
    void imprimirCami(Clau _key) const;                                             // Cost (O) log n
    NodeBinari<Clau, Valor> *getRoot() const;
    int getHeight() const;

    //MODIFICADORS
    NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);
    void eliminaMinim();

    void setRoot(NodeBinari<Clau, Valor> *root);
    void setHeight(int n);

protected:
    NodeBinari<Clau,Valor>* root;
    NodeBinari<Clau,Valor>* search(const Clau& k) const;
    void calcularHeightArbre(const NodeBinari<Clau,Valor>* node);
    void mostrarArbreOrdenat() const;

private:
    int _size;
    int _heightArbre;
    NodeBinari<Clau, Valor>* _node;

    // MÈTODES PRIVATS
    NodeBinari<Clau, Valor>* cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const;
    void imprimirOrdreRecurs(const NodeBinari<Clau,Valor>* n, string ordre ) const;
    vector<NodeBinari<Clau,Valor>*> buscarRang(NodeBinari<Clau,Valor>* node, int k1, int k2, vector<NodeBinari<Clau,Valor>*> rangVector) const;
    void copyArbre(NodeBinari<Clau, Valor>* node);
    void rutinaEsquerra(const NodeBinari<Clau,Valor>* n, string ordre ) const;
    void rutinaDreta(const NodeBinari<Clau,Valor>* n, string ordre ) const;
    void  eliminarNode(NodeBinari<Clau,Valor>* &node);
    NodeBinari<Clau, Valor>* buscarSuccesortoEliminiar(NodeBinari<Clau,Valor>* node);
    int mostrarPelisRecurs(const NodeBinari<Clau,Valor>* node, int contador) const;
    NodeBinari<Clau,Valor>*  eliminaMinimRecur(NodeBinari<Clau, Valor>* node);

    int verificarHeight(const NodeBinari<Clau,Valor>* node);


    void eliminarNodeExtern(NodeBinari<Clau, Valor> *&node, int &n, NodeBinari<Clau, Valor> *nodeInicial) ;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::ArbreBinari(){
    this->root = nullptr;
    this->_node = nullptr;
    this->_size = 0;
    this->_heightArbre = 0;
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
ArbreBinari<Clau, Valor>::ArbreBinari(ArbreBinari<Clau, Valor> *orig){
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
    cout << "Destruint arbre binari " << endl;
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
int ArbreBinari<Clau, Valor>::height() {
    calcularHeightArbre(this->root);
    return this->_heightArbre;
}
template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::getHeight() const{
    return this->_heightArbre;
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::setHeight(int n) {
    this->_heightArbre = n;
}
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::insert(const Clau& clau, const Valor& value){

    NodeBinari<Clau, Valor>* nodeNou= new NodeBinari<Clau, Valor>(clau, value);
    NodeBinari<Clau, Valor>* nodeAux;

    if(isEmpty()) {
        this->root = nodeNou;
        this->_node = root;
        this->_heightArbre = 1;

    }
    else{
        this->_node = cercarPosicioInsercio(clau, root);          //Recorre arbre per trobar posició inserció.
        nodeNou->setPare(this->_node);
        nodeAux = nodeNou;

        if( clau < this->_node->getKey() ){
            this->_node->setLeft(nodeNou);
            this->_node->getLeft()->setIsRight(false);   // Indico que aquest node, és node de l'esquerra
        }
        else{
            this->_node->setRight(nodeNou);
            this->_node->getRight()->setIsRight(true);
        }
    }
    this->_size ++;
    cout << "Inserta a l’arbre element " << nodeNou->getKey() <<  endl;

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
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::eliminaMinimRecur(NodeBinari<Clau, Valor>* node){
    NodeBinari<Clau, Valor>* nodeInicial = node->getPare();

    if (node != nullptr)
        if (node->hasLeft())
            node =  eliminaMinimRecur(node->getLeft());
    return node;
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminaMinim(){

    if ( isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        NodeBinari<Clau,Valor>* nodeAux = this->root;
        nodeAux = eliminaMinimRecur(nodeAux);
        eliminarNode(nodeAux);
        this->_size --;
    }
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminarNode(NodeBinari<Clau,Valor>* &node){

    if (node->isExternal()) {
        if (node->getPare() == nullptr) {
            node = nullptr;
            this->root = nullptr;
        }
        else{
            if (node->isIsRight())
                node->getPare()->setRight(nullptr);
            else
                node->getPare()->setLeft(nullptr);
            delete node;
        }
    }
    else{
        NodeBinari<Clau, Valor>* successor = buscarSuccesortoEliminiar(node);

        if (node->getPare() == nullptr){                            //Elimina Root
            // Intercanvia dades successor amb node Root
            node->setKey(successor->getKey());
            node->setValue(successor->getValue());
            node->setIsRight(false);

            if ( successor->isExternal() ){
                if (successor->isIsRight())
                    successor->getPare()->setRight(nullptr);
                else
                    successor->getPare()->setLeft(nullptr);

            }else{
                successor->getRight()->setPare(successor->getPare());
                if( successor->getRight()->getKey() < successor->getPare()->getKey()) {
                    successor->getRight()->setIsRight(false);
                    successor->getPare()->setRight(successor->getRight());
                }
                else{
                    successor->getRight()->setIsRight(true);
                    successor->getPare()->setRight(successor->getRight());
                }
            }
            delete successor;
        }else{
            if (successor->isIsRight()){
                node->getPare()->setLeft(successor);
                successor->setPare(node->getPare());
                successor->setIsRight(false);
                delete node;
            }else{
                node->setKey(successor->getKey());
                node->setValue(successor->getValue());

                if (successor->isExternal()){
                    successor->getPare()->setLeft(nullptr);
                }else{
                    successor->getRight()->setPare(successor->getPare());
                    successor->getPare()->setLeft(successor->getRight());
                    successor->getRight()->setIsRight(false);
                }
                delete successor;
            }
        }
    }
}

template<class Clau, class Valor>
void ArbreBinari<Clau, Valor>::eliminarNodeExtern(NodeBinari<Clau, Valor> *&node, int &n,
                                                   NodeBinari<Clau, Valor> *nodeInicial)  {
    if (node->getPare() == nullptr) {
        delete node;
        delete nodeInicial;
        n--;
    }
    else {
        if (node->isIsRight())
            node->getPare()->setRight(nullptr);
        else
            node->getPare()->setLeft(nullptr);
        n --;
        delete node;

        eliminaMinimRecur(node->getPare(), n);

    }
}
template <class Clau, class Valor>
NodeBinari<Clau, Valor>* ArbreBinari<Clau, Valor>::buscarSuccesortoEliminiar(NodeBinari<Clau,Valor>* node){
    if (node->hasRight()) {
        node = node->getRight();

        while (node->hasLeft())
            node = node->getLeft();
    }
    return node;
}

////Mètodes Protected
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::search(const Clau& k) const{
    //Mètode Iteratiu per petició de l'anunciat

    NodeBinari<Clau, Valor>* node = this->root;      // Crea un node amb el root
    while(k != node->getKey()) {
        while (k < node->getKey())
            if (node->hasLeft())
                node = node->getLeft();
            else{
                //cout << k << " No existeixoArbrebi" << endl;
                return nullptr;
            }

                //throw invalid_argument("\n\e[1mEl node no aaaaaexisteix\e[0m");
        while (k > node->getKey())
            if (node->hasRight())
                node = node->getRight();
            else{
               // cout << k << " No existeixoArbrebi" << endl;
                return nullptr;
            }
               // throw invalid_argument("\n\e[1mEl node no sssexisteix\e[0m");
    }
    return node;
}

// MÈTODES PRIVATS

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* ArbreBinari<Clau, Valor>::cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const {
    //Pre: Clau i Node Pare.
    //Post: Retorna el node Pare, on haurà d'insertar el Node nou.
//    if (clau == node->getKey())           // Clau repetida retorna missatge error
//        throw invalid_argument("No pot haver una clau repetida");
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
int ArbreBinari<Clau, Valor>::verificarHeight(const NodeBinari<Clau,Valor>* node) {
    int altura = 0;

    if (node != nullptr)
        altura =  1 + verificarHeight(node->getPare());
    return  altura;
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::calcularHeightArbre(const NodeBinari<Clau,Valor>* node)  {
    if ( isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        if ( node->isExternal()){
            int altura = verificarHeight(node);
            if ( this->_heightArbre < altura)          // Es queda amb el valor més alt
                 setHeight(altura);
        }else{
            if (node->hasLeft())
                calcularHeightArbre(node->getLeft());
            if (node->hasRight())
                calcularHeightArbre(node->getRight());

        }
    }
}

template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::mostrarPelisRecurs(const NodeBinari<Clau,Valor>* node, int contador) const{

    if (node != nullptr) {
        if (node->hasLeft())
            contador = mostrarPelisRecurs(node->getLeft(), contador);  // Acció recursiva buscant el node esquerra
        cout << node->getValue().print() << endl;                           // Imprimeix pel·licula.
        contador++;

        if (contador == 40) {                                  // Controla per mostrar de 40 en 40
            cout << "\n\e[1mPrem enter per continuar... \n\e[0m";
            cin.ignore();
            cin.get();
            contador = 0;
        }
        if (node->hasRight())
            contador = mostrarPelisRecurs(node->getRight(), contador); //Acció recursiva buscant node dret
    }
    return contador;
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::mostrarArbreOrdenat() const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "\n\e[1mMostra arbre ordenat: \n\e[0m";
        mostrarPelisRecurs(this->root, 0);
        cout << "\n\e[1mTotal Pel·licules: \e[0m" << this->_size << endl;
    }
}

#endif //PRACTICA_4_ARBREBINARI_H


