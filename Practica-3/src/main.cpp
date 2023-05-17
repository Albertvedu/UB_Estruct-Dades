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

void menu(int &opcio, string tipusCerca) {
    vector<string> opMenu =
            {"1. Triar fitxer lectura ", "2. Mostrar arbre en ordre creixent", "3. Llegir fitxer \"cercaPelicules.txt\"",
             "4. Visualitzar profunditat de l'arbre", "5. Esborrar les n pelicules amb Id més petit",
             "6. Sortit"};

    cout << "\nCERCADOR DE PELICULES AMB " << tipusCerca << " \n" << endl;

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

    if (opcio == "p")                       //   ressources/movie_rating_small.txt
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/src/ressources/movie_rating_small.txt"); // todo ... cambiar ruta VS
    else
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/src/ressources/movie_rating.txt"); //todo cambiar ruta
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end -begin).count()
    << " Mil·lèsimes de segon." << endl;
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
    int _testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40 };
    int _testValuies[] = {5, 5, 1, 88, 99, 12, 9, 11};

    ArbreBinari<int, int>* _tree1 = new ArbreBinari<int, int>();
    ArbreBinari<int, int>* _tree2;
    try{
        inserirNodes(_testKeys, _testValuies, _tree1);
        imprimir(_tree1);
        cout << "Height:  " << _tree1->height()  << endl;
        vector<NodeBinari<int,int>*> rang = _tree1->obteValorsRang(5, 45);
        imprimirRang(rang);

        _tree2 = new ArbreBinari<int, int>(_tree1);
        _tree2->imprimirPostordre(_tree2->getRoot());
        imprimirCami(_tree1, 40);
        cout << "\n\e[1mEliminar minim\e[0m" << endl;
        _tree1->eliminaMinim();
        _tree1->imprimirInordre(_tree1->getRoot());

        delete _tree1;
        cout << endl;

    }catch(const std::exception& e){
        cerr << e.what() << '\n';
    }
}

/*########################################################
#####           EXERCICI  -   2  i  4                  ###
########################################################*/
template <class Classe>
void mostrarArbre(Classe *cercador) {
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cercador->mostrarArbre();
}

template <class Classe>
void cercarTotsElement( Classe *cercador, vector<int> idCerca) {
    if(cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");

    Movie movie;
    int contador = 0;
    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();

    for (int i = 0; i < idCerca.size(); ++i) {
        try {
            movie = cercador->buscarMovie(idCerca[i]);
            movie.toString(movie);  //movie.print() << endl;   // Que tonteria usar toString i print(). Necesito un objeto Movie, para llamar a toString()
            contador ++;
        }catch(const invalid_argument &e){
            cerr << idCerca[i] << "::  " << e.what() << '\n';
        }
    }
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << "\n\e[1mTemps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end1 -begin1).count() << " Mil·lèsimes de segon." << endl;
    cout << "Total pel·licules trovades: " << contador << "\nFitxer cerca size: " << idCerca.size() << "\e[0m" << endl;
}
template <class Classe>
void profundidad(Classe * cercador){
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cout << "\nLa profunditat d'aquest arbre es: " << cercador->profunditat() << endl;

}
template <class Classe>
void opcionsMenu(const int opcio, vector<int> &idCerca, Classe *cercador) {
    switch (opcio) {
        case 1:
            triarFitxer(cercador);
            break;
        case 2:
            mostrarArbre(cercador);
            break;
        case 3:
            llegirFitxerCerques(idCerca);
            cercarTotsElement(cercador, idCerca);
            break;
        case 4:
            profundidad(cercador);
            break;
        case 5:
            cercador->eliminarMinimaMovie(5);
            mostrarArbre(cercador);
            break;
        case 6:
            delete cercador;     // Sortir del menu i destruir punters d'Arbre Binari
            break;
        default:
            break;
    }
}
template<typename Base, typename T>
inline bool instanceof(const T *cercador) {
    return dynamic_cast<const Base*>(cercador) != nullptr;
}

template <class Classe>
void main_Binari_Heap(Classe *cercador){
    int opcio;
    string fitxer, tipusCerca;
    vector<int> idCerca;
    Movie movie;

    // Detecta quina classe arriba instanciada per paràmetres
    if(instanceof<CercadorMoviesAB<int, Movie>>(cercador))
        tipusCerca = "ARBRE BINARI";
    else
        tipusCerca = "HEAPS";

    try {
        do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
            try {
                menu(opcio, tipusCerca);
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
    for (int i = 0; i < 8; i++) {
        heap1.inserir(testKeys[i], testValues[i]);
    }
    cout << "heap1 ={ ";
    heap1.imprimir();
    cout << "}" << endl;
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
    cout << "Heap recent creat. is esBuit? (0/1): " << heap1.esBuit() << endl;
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
void menuMain() {
    cout << "\n\n\t\t\t\t#######################################################" << endl;
    cout << "\t\t\t\t***\t\tQue vols executar?:                 ###" << endl;
    cout << "\t\t\t\t***                                                 ###" << endl;
    cout << "\t\t\t\t***\t\t  <1>   Exercici - 1                ###" << endl;
    cout << "\t\t\t\t***\t\t  <2>   Menu Arbre Binari           ###" << endl;
    cout << "\t\t\t\t***\t\t  <3>   Exercici - 3                ###" << endl;
    cout << "\t\t\t\t***\t\t  <4>   Menu Arbre Heaps            ###" << endl;
    cout << "\t\t\t\t***\t\t  <5>   Sortir                      ###" << endl;
    cout << "\t\t\t\t***                                                 ###" << endl;
    cout << "\t\t\t\t#######################################################" << endl;
}
int main(){

    /*
     * PREGUNTES:
     *
     * Después de leer fichero. Estando en el menu. Sé puede volver a leer para cambiar de fichero ????
     *
     * Linia 191 del main, que tonteria llamar a toString.
     *
     * mètodes AppendMovies... com activar destructor per esborrar dades anteriors... He fet eliminar(tot)
     *
     *
     */
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR


    int opcioMain;
    do {
        try {
            menuMain();
            opcioMain = llegirStringTOint("\nOpció: ", 1, 5);
            switch ( opcioMain) {
                case 1:
                    mainExercici_1();
                    break;
                case 2:
                    main_Binari_Heap(new CercadorMoviesAB<int, Movie>);
                    break;
                case 3:
                    casDeProvaExercici3();
                    break;
                case 4:
                    main_Binari_Heap(new CercadorMoviesHeap<int, Movie>);
                    break;
                default:
                    break;
            }
        }catch(const invalid_argument &e){
            cerr << e.what() << '\n';
        }
    } while (opcioMain != 5);

    cout << "\n\nBye Bye...\n\n" << endl;
    return 0;
}