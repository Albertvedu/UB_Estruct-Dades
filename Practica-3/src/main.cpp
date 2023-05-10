#include <iostream>
#include "CercadorMoviesAB.h"
#include "CercadorMoviesHeap.h"
#include <chrono>

using namespace std;

template <class Classe>
void opcionsMenu(int opcio, vector<int> &idCerca, Classe *cercador);

using namespace std;
void compare(int valor, int limitA, int limitB){
    if (valor < limitA || valor > limitB)
        throw invalid_argument( "Dades introduïdes incorrectes" );
}
bool esNumero(char *lectura) {
    for( ; *lectura; ++lectura )
        if( !isdigit(*lectura) )
            return false;
    return true;
}

int llegirStringTOint(string text, int limitA, int limitB) {
    // Post: retorna lectura Integer o error si no és Integer

    char lectura[100];

    while(true){
        try{
            cout << text;
            cin >> lectura;
            if(!esNumero(lectura) )
                throw invalid_argument( "Dades introduïdes incorrectes");
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const invalid_argument &e){
            cerr << e.what() << '\n';
        }
    }

    return atoi(lectura);
}

void menu(int &opcio) {
    vector<string> opMenu =
            {"1. Triar fitxer lectura ", "2. Mostrar arbre en ordre creixent", "3. Llegir fitxer \"cercaPelicules.txt\"",
             "4. Visualitzar profunditat de l'arbre", "5. Esborrar les n pelicules amb Id més petit",
             "6. Sortit"};

    cout << "\nCERCADOR DE PELICULES\n" << endl;

    for (int i = 0; i < 6; ++i) {
        cout << opMenu[i] << endl;
    }
    opcio = llegirStringTOint("\nOpció: ", 1, 6);
}
template <class Classe>
void triarFitxer(Classe* cercador) {
//void triarFitxer(CercadorMoviesAB<int, Movie>* cercador){
    string opcio;
    cout << "\nQuin fitxer vols utilitzar ( P / G) (Petit o Gran): ";
    cin >> opcio;
    opcio = tolower(opcio[0]);

    if (opcio != "p" && opcio != "g")
        throw invalid_argument("\e[1mOpció no vàlida\e[0m");
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    if (opcio == "p")
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/src/ressources/movie_rating_small.txt"); // todo ... cambiar ruta VS
    else
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/src/ressources/movie_rating.txt"); //todo cambiar ruta
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::microseconds
        >(end -begin).count() << " micras de segon." << endl;
}
void llegirFitxerCerques(vector<int> &idCerca){
    int n = 0;
    if (idCerca.size() == 0){                   // Per no llegir dos cops el fitxer, en una segona crida
        if (ifstream arxiu{ "/home/albert/CLionProjects/Practica-3/src/ressources/cercaPelicules.txt"}) {
            while ( !arxiu.eof() ){
                arxiu >> n;
                idCerca.push_back(n);
            }
            arxiu.close();

        } else {
            throw invalid_argument ("\nNO S'HA POGUT OBRIR EL FITXER");
        }
    }
}

/*########################################################
#####           EXERCICI  -   1                        ###
########################################################*/

void inserirNodes(const int *testKeys, const int *testValuies, ArbreBinari<int, int> *tree1) {
    for (int i = 0; i < 8 ; ++i) {
        tree1->insert(testKeys[i], testValuies[i]);
    }
}
void imprimir(const ArbreBinari<int, int> *tree1) {
    cout << endl;
    tree1->imprimirPreordre(tree1->getRoot());
    tree1->imprimirInordre(tree1->getRoot());
    tree1->imprimirPostordre(tree1->getRoot());
}
void imprimirRang(const vector<NodeBinari<int, int> *> &rang) {
    cout << "ObteValorsRang = { ";

    for(int i = 0; i < rang.size()-1; i++)
        cout << rang[i]->getKey() << ", ";
    cout << rang[rang.size()-1]->getKey() << " }" << endl;
}
void imprimirCamiRecurs(NodeBinari<int, int>* node, int clau){
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
void imprimirCami(const ArbreBinari<int, int> *tree1, const int & clau){
    if ( tree1->isEmpty() )
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        cout << "ImprimirCami={ ";
        tree1->imprimirCami(clau);
        cout << " }" << endl;
    }
}
void mainExercici_1(){
    cout << "\n ------------------------------------------------- " << endl;
    cout << " ------------- Cas de prova exercici 1 ----------- " << endl;
    cout << " ------------------------------------------------- " << endl;
    int _testKeys[8] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int _testValuies[8] = {5, 5, 1, 88, 99, 12, 9, 11};

    ArbreBinari<int, int>* _tree1 = new ArbreBinari<int, int>();
    ArbreBinari<int, int>* _tree2;
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
    }
}

/*########################################################
#####           EXERCICI  -   2                        ###
########################################################*/
template <class Classe>
void mostrarArbre(Classe *cercador) {
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cercador->mostrarArbre();
}

template <class Classe>
void cercarTotsElement( Classe * cercador, vector<int> idCerca) {
    if(cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");

    Movie movie;
    int contador = 0;
    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();

    for (int i = 0; i < idCerca.size(); ++i) {
        try {
            movie = cercador->buscarMovie(idCerca[i]);
            cout << movie.print() << endl;
            contador ++;
        }catch(const invalid_argument &e){
            cerr << idCerca[i] << "::  " << e.what() << '\n';
            cout << idCerca[i] << "  No existeix" << endl;  //todo VERIFICAR SINÓ BORRAR AIXÓ
        }
    }
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end1 -begin1).count() << " milessimes de segon." << endl;
    cout << "Total pel·licules trovades: " << contador << "\nFitxer cerca size: " << idCerca.size() << endl;
}
template <class Classe>
void profundidad(Classe * cercador){
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cout << "\nLa profunditat d'aquest arbre es: " << cercador->height()-1 << endl;

}

void mainArbreBinari(){
    int opcio;
    string fitxer;
    vector<int> idCerca;
    Movie movie;
    try {

        CercadorMoviesAB<int, Movie> *cercador = new CercadorMoviesAB<int, Movie>;

        do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
            try {
                menu(opcio);
                opcionsMenu(opcio, idCerca, cercador);
            }catch(const invalid_argument &e){
                cerr << e.what() << '\n';
            }
        } while (opcio != 6);
    }catch(const invalid_argument &e){
        cerr << e.what() << '\n';
    }
}



/*########################################################
#####           EXERCICI  -   3                        ###
########################################################*/
void casDeProvaExercici3() {
    cout << "\n ------------------------------------------------- " << endl;
    cout << " ------------- Cas de prova exercici 3 ----------- " << endl;
    cout << " ------------------------------------------------- " << endl;
    MinHeap<int, int> heap1;

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++) {
        heap1.inserir(testKeys[i], testValues[i]);
    }
    cout << "heap1 ={ ";
    heap1.imprimir();
    cout << "}" << endl;
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
    cout << "Heap recent creat. is isEmpty? (0/1): " << heap1.isEmpty() << endl;
    cout << "Clau minima " << heap1.minim() << endl;
    cout << "EliminaMinim" << endl;
    heap1.eliminaMinim();
    cout<<"Heap despres eliminar 1. Print: "<<endl;
    heap1.imprimir();
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
    heap1.eliminaMinim();
    cout<<"Heap despres eliminar 2. Print: "<<endl;
    heap1.imprimir();
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
}

/*########################################################
#####           EXERCICI  -   4                        ###
########################################################*/
void mainHeap(){
    int opcio;
    string fitxer;
    vector<int> idCerca;
    Movie movie;
    try {
        auto *cercador = new CercadorMoviesHeap<int, Movie>;

        do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
            try {
                menu(opcio);
                opcionsMenu(opcio, idCerca, cercador);
            }catch(const invalid_argument &e){
                cerr << e.what() << '\n';
            }
        } while (opcio != 6);
    }catch(const invalid_argument &e){
        cerr << e.what() << '\n';
    }
}
template <class Classe>
void opcionsMenu(int opcio, vector<int> &idCerca, Classe *cercador) {
    switch (opcio) {
        case 1:
            triarFitxer(cercador);
            break;
        case 2:
            mostrarArbre(cercador);
            break;
//        case 3:
//            llegirFitxerCerques(idCerca);
//            cercarTotsElement(cercador, idCerca);
//            break;
//        case 4:
//            profundidad(cercador);
//            break;
//        case 5:
//            cercador->eliminarMinimaMovie(5);
//            mostrarArbre(cercador);
//            break;
        default:
            break;
    }
}
int main(){

    /*
     * PREGUNTES:
     *
     * Mètode toString i Print de Movie.
     * Al buscar ID's de fichero solo encuentra 512 id, ¿Debo mostrar "no existe" cuando no encuetre un Id?
     * Mostrar Heap de peliculas... se muestra igual que el Heap de Int... en forma de arbol, por niveles?
     * Al Heredar d'ArbreBinari, es crea un Arbre sense nom propi
     * Try/catch si peta en Exercici 1... salta despres de imprimir Menu
     * Verificar a cole, si execpcio al buscar ID's del fitxer cerca salta a temps... llavors treure "No existeix linea 105
     *
     */
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR

//    mainExercici_1();          // Executa l'exercici 1
 //   casDeProvaExercici3();

    cout << "\n\n\t\t\t\t#######################################################" << endl;
    cout << "\t\t\t\t***\t\tQue vols executar?:                 ###" << endl;
    cout << "\t\t\t\t***                                                 ###" << endl;
    cout << "\t\t\t\t***\t  <1>   Menu Arbre Binari                   ###" << endl;
    cout << "\t\t\t\t***\t  <2>   Menu Arbre Heaps                    ###" << endl;
    cout << "\t\t\t\t***                                                 ###" << endl;

    cout << "\t\t\t\t#######################################################" << endl;
    cout << "\n\tOpció?: " << endl;

 //   mainArbreBinari();

    mainHeap();
    return 0;
}








