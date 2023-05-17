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
#include<algorithm>


using namespace std;

template <class Clau, class Valor>
class ArbreBinari {
public:
    //CONSTRUCTORS
    ArbreBinari();
    ArbreBinari(ArbreBinari<Clau, Valor> *orig);

    //DESTRUCTOR
     virtual ~ArbreBinari();                                             // Cost (O) n

    //CONSULTORS
    bool isEmpty() const;                                                // Cost (O) 1
    //Post: Retorna booleà si l'arbre està buit o plé

    int height() ;                                                       // Cost (O) log n
    //Post: Retorna int amb l'alçada de l'arbre.

    const Valor& valueOf(const Clau& clau) const;                                   // Cost (O) 1
    //Post: Retorna Objecta Valor, donada una clau

    void imprimirPreordre(const NodeBinari<Clau,Valor>* n = nullptr) const;         // Cost (O) n log n
    //Post: Sortida impresa per pantalla de l'arbre, amb pre-Ordre

    void imprimirInordre(const NodeBinari<Clau,Valor>* n = nullptr) const;          // Cost (O) n log n
    //Post: Sortida impresa per pantalla de l'arbre, amb in-Ordre

    void imprimirPostordre(const NodeBinari<Clau,Valor>* n = nullptr) const;        // Cost (O) n log n
    //Post: Sortida impresa per pantalla de l'arbre, amb post-Ordre

    vector<NodeBinari<Clau,Valor>*> obteValorsRang(int k1, int k2) const;           // Cost (O) log n
    //Post: Retorna nodes entre rang de k1 i k2

    void imprimirCami(Clau _key) const;                                             // Cost (O) log n
    //Post: Retorna cami des de l'arrel fins el node amb la clau key

    NodeBinari<Clau, Valor> *getRoot() const;                                        // Cost (O) 1
    //Post: Retorna atribut privat _root

    int getHeight() const;                                                            // Cost (O) n log(n)
    //Post: Retorna int de valor del atribut privat _heightArbre

    //MODIFICADORS
    NodeBinari<Clau,Valor>* insert(const Clau& clau, const Valor& value);             // Cost (O) 1 log(n) Buscar pos
    //Post: Insereix element nou i retorna node que ha creat

    void eliminaMinim();                                                              // Cost (O) log(n)
    //Post: Elimina l'element amb la clau més petita.

    int nivell();
    int nivellr(const NodeBinari<Clau,Valor>* node);
    //Post: Setter per l'atribut _heightArbre

protected:
    // Atributs
    NodeBinari<Clau,Valor>* root;

    //MÈTODES PROTECTED
    NodeBinari<Clau,Valor>* search(const Clau& k);                              // Cost (O) log(n)
    //Post: busca i retorna node amb la clau que arriba per paràmetres

    void calcularHeightArbre(const NodeBinari<Clau,Valor>* node);                     // Cost (O) n log(n)
    //Post: Actualitza valor atribut _heightArbre, amb el càlcul de l'alçada del arbre

    void mostrarArbreOrdenat() const;                                                 // Cost (O) n
    //Post: Mostra per pantalla arbre ordenat en in-ordre

    void setHeight(int n);                                                            // Cost (O) 1
    //Post: Reinicialitzar la variable _heightArbre;

    int getSize() const;


private:
    //Atributs
    int _size;
    int _heightArbre;
    NodeBinari<Clau, Valor>* _node;

    // MÈTODES PRIVATS
    NodeBinari<Clau, Valor>* cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const;//Cost (O) log(n)
    //Post: Retorna el node Pare, on haurà d'insertar el Node nou. PERMET NODES REPETITS

    void imprimirOrdreRecurs(const NodeBinari<Clau,Valor>* n, string ordre ) const;                  // Cost (O) n
    //Post: Mètode recursiu del imprimirOrdre.

    vector<NodeBinari<Clau,Valor>*> buscarRang(NodeBinari<Clau,Valor>* node, int k1, int k2,
                                               vector<NodeBinari<Clau,Valor>*> rangVector) const;    // Cost (O) log(n)
    //Post: Retorna vector amb els nodes entre el rang k1 i k2

    void copyArbre(NodeBinari<Clau, Valor>* node);                                                  // Cost (O) n
    //Post: Mètode recursiu del CONSTRUCTOR COPIA

    void rutinaEsquerra(const NodeBinari<Clau,Valor>* n, string ordre ) const;                    // Cost (O) log(n)
    //Post: rutina interna del mètode imprimirOrdreRecurs()

    void rutinaDreta(const NodeBinari<Clau,Valor>* n, string ordre ) const;                       // Cost (O) log(n)
    //Post: rutina interna del mètode imprimirOrdreRecurs()

    void  eliminarNode(NodeBinari<Clau,Valor>* &node);                                            // Cost (O) 1 log(n)
    //Post:  //Post: rutina interna del mètode EliminarMinin(),

    NodeBinari<Clau, Valor>* buscarSuccesortoEliminiar(NodeBinari<Clau,Valor>* node);             // Cost (O) log(n)
    //Post: Retorna node eliminat. Rutina interna del mètode Eliminar node().

    int mostrarPelisRecurs(const NodeBinari<Clau,Valor>* node, int contador) const;               // Cost (O) n
    //Post: Mètode recursiu de mostrarArbreOrdenat, retorna contador pelicules

    NodeBinari<Clau,Valor>*  eliminaMinimRecur(NodeBinari<Clau, Valor>* node);                    // Cost (O) log(n)
    //Post: Mètode recursiu d'eliminarMinim()

    int verificarHeight(const NodeBinari<Clau,Valor>* node);                                      // Cost (O) log(n)
    //Post: Retorna alçada. Mètode intern de calcularHeightArbre()

    void imprimirCamiRecurs(NodeBinari<int, int>* node, int clau) const;                          // Cost (O) log(n)
    //Post: Mètode recursiu del mètode imprimirCami()

    void deleteArbreRecursiu(NodeBinari<Clau, Valor>* root);                                     // Cost (O) n
    //Mètode recursiu del Destructor
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
void ArbreBinari<Clau, Valor>::deleteArbreRecursiu(NodeBinari<Clau, Valor>* node){

    if (node == nullptr)                               // Caso base: árbol vacío
        return;

    // eliminar primero el subárbol izquierdo y derecho (Postorder)
    deleteArbreRecursiu(node->getLeft());
    deleteArbreRecursiu(node->getRight());

    node = nullptr;
    delete node;
}
template <class Clau, class Valor>
ArbreBinari<Clau, Valor>::~ArbreBinari(){

    deleteArbreRecursiu(this->root);
    deleteArbreRecursiu(this->_node);

    this->root = nullptr;
    delete this->root;
    this->_node = nullptr;
    delete this->_node;

    this->_size = 0;
    cout << "Arbre binari destruït" << endl;

          // Opcio Iterativa
//    NodeBinari<Clau, Valor>* node = this->root;
//    NodeBinari<Clau, Valor>* nodeAux;
//    cout << "Destruint arbre binari " << endl;
//    while( node != nullptr){
//        while ( node->hasLeft() ){
//            node = node->getLeft();
//        }
//
//        while ( node->hasRight() ){
//            node = node->getRight();
//        }
//
//        if (node->isExternal()){
//
//            nodeAux = node;
//
//            if (node->getPare() != nullptr) {
//                node->isIsRight() ? node->getPare()->setRight(nullptr) :
//                    node->getPare()->setLeft(nullptr);
//            }
//            cout << "Eliminat "<< node->getKey() << endl;

//            delete node;
//            node = nullptr;
//            node = nodeAux->getPare();
//        }
//        cout << "size... " << this->_size-- << endl;
//    }

//    this->_size = 0;
//
//    cout << "Arbre binari destruït" << endl;
}

template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::copyArbre(NodeBinari<Clau, Valor>* node){
    //Post: Mètode recursiu del CONSTRUCTOR COPIA

    insert(node->getKey(), node->getValue());
    if ( node->hasLeft())
        copyArbre(node->getLeft());

    if (node->hasRight())
        copyArbre(node->getRight());
}
template <class Clau, class Valor>
bool ArbreBinari<Clau, Valor>::isEmpty() const{
    //Post: retorna booleà, true si és buit
    return this->root == nullptr;
}

template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::height() {
    //Post: retorna variable _hightArbre, després d'actualitzar-la

    calcularHeightArbre(this->root);
    return this->_heightArbre;
}
template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::getSize() const{
    //Post: retorna variable _size
    return this->_size;
}
template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::getHeight() const{
    //Post: retorna variable _heightArbre
    return this->_heightArbre;
}
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::setHeight(int n) {
    //Post: setter variable _heightArbre
    this->_heightArbre = n;
}
template <class Clau, class Valor>
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::insert(const Clau& clau, const Valor& value){
    //Post: crea i inserta node, amb el paràmetres d'entrada

    NodeBinari<Clau, Valor>* nodeNou= new NodeBinari<Clau, Valor>(clau, value);

    if(isEmpty()) {
        this->root = nodeNou;
        this->_node = root;
        this->_heightArbre = 1;

    }
    else{
        this->_node = cercarPosicioInsercio(clau, root);          //Recorre arbre per trobar posició inserció.
        nodeNou->setPare(this->_node);

        if( clau < this->_node->getKey() ){
            this->_node->setLeft(nodeNou);
            this->_node->getLeft()->setIsRight(false);   // Indico que aquest node, és node de l'esquerra
        }
        else{
            this->_node->setRight(nodeNou);
            this->_node->getRight()->setIsRight(true);    // Indico que aquest node, és node de la dreta
        }
    }
    this->_size ++;
    cout << "Insertat a l’arbre element " << nodeNou->getKey() <<  endl;

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
void ArbreBinari<Clau, Valor>::imprimirCamiRecurs(NodeBinari<int, int>* node, int clau) const{
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
template <class Clau, class Valor>
void ArbreBinari<Clau, Valor>::imprimirCami(Clau _key) const{
    if ( isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        imprimirCamiRecurs(this->getRoot(), _key);
    }
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

    if (node->isExternal()) {                         // Node a eliminar és extern
        if (node->getPare() == nullptr) {            // Saber si és el root. Sense fills
            node = nullptr;
            this->root = nullptr;
            delete this->root;
        }
        else{              // No es root, llavors verifica si es node esquerra o dreta
            if (node->isIsRight())
                node->getPare()->setRight(nullptr);
            else
                node->getPare()->setLeft(nullptr);
            delete node;
        }
    }
    else{    // Node No es extern
        NodeBinari<Clau, Valor>* successor = buscarSuccesortoEliminiar(node);      // Busca node successor

        if (node->getPare() == nullptr){                            //Elimina Root  AMB fills
            // Intercanvia dades successor amb node Root
            node->setKey(successor->getKey());
            node->setValue(successor->getValue());
            node->setIsRight(false);

            // Aqui, canvia enllaços del successor amb el node a eliminar
            if ( successor->isExternal() ){                         // Si successor és extern
                if (successor->isIsRight())
                    successor->getPare()->setRight(nullptr);
                else
                    successor->getPare()->setLeft(nullptr);

            }else{                                                 // Si successor NO és extern
                successor->getRight()->setPare(successor->getPare());

                //Aqui verifica si la clau del fill dret del successor es menor que el Pare del succesor
                if( successor->getRight()->getKey() < successor->getPare()->getKey()) {
                    successor->getRight()->setIsRight(false);
                    successor->getPare()->setLeft(successor->getRight());  // Si és MENOR és setLeft()
                }
                else{ //Si la clau del fill dret del successor és MAJOR que el Pare del succesor
                    successor->getRight()->setIsRight(true);
                    successor->getPare()->setRight(successor->getRight());   // Si és MAJOR és setRight()
                }
            }
            delete successor;
        }else{                        // No és l'Arrel i té fills
            if (successor->isIsRight()){                    // Si successor és node dret
                node->getPare()->setLeft(successor);
                successor->setPare(node->getPare());
                successor->setIsRight(false);
                delete node;
            }else{                                         // Successor es node esquerra
                node->setKey(successor->getKey());
                node->setValue(successor->getValue());

                if (successor->isExternal()){                  // Successor és extern
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
NodeBinari<Clau,Valor>* ArbreBinari<Clau, Valor>::search(const Clau& k) {
    //Mètode ITERATIU per petició de l'anunciat
    //Post: Retorna el node amb la clau 'k' que arriba per paràmetres

    if (isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");       // Execció Arbre buit

    NodeBinari<Clau,Valor>* node = this->root;

    while(k != node->getKey()) {                              //Repeteix fins trobar la Key

        while (k < node->getKey()) {
            if (node->hasLeft())
                node = node->getLeft();
            else
                throw invalid_argument("Aquest Id no existeix...");    // No hi ha node esquerra. La clau no existeix
        }
        while (k > node->getKey()) {
            if (node->hasRight())
                node = node->getRight();
            else
                throw invalid_argument("Aquest Id no existeix...");    // No hi ha node dreta. La clau no existeix
        }
    }
    return node;
}

// MÈTODES PRIVATS

template <class Clau, class Valor>
NodeBinari<Clau, Valor>* ArbreBinari<Clau, Valor>::cercarPosicioInsercio(const Clau &clau, NodeBinari<Clau, Valor>* node) const {
    //Pre: Clau i Node Pare.
    //Post: Retorna el node Pare, on haurà d'insertar el Node nou. NO PERMET NODES REPETITS
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
//template <class Clau, class Valor>
//int ArbreBinari<Clau, Valor>::nivellr(const NodeBinari<Clau,Valor>* node, int nivell)  {
//    int left, right ;
//    if (node == nullptr)
//        return nivell;
//    else{
//         left = nivellr(node->getLeft(), nivell++) ;
//         right = nivellr(node->getRight(), nivell++);
//    }
//    if (left > right )
//        return left;
//    else
//    return right;
//}


template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::nivellr(const NodeBinari<Clau,Valor>* node)  {

    if (node == nullptr)
        return 0;
    //Cridas recursives, si el uns dels nodes no existeix, retorna zero
    return 1 + max(nivellr(node->getLeft()), nivellr(node->getRight()));
}
template <class Clau, class Valor>
int ArbreBinari<Clau, Valor>::nivell()  {
    if ( isEmpty())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        return nivellr(this->root);
    }
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
                this->_heightArbre = altura;

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

        if (contador == 40){                                             // Controla per mostrar de 40 en 40
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


