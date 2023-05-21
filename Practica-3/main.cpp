#include <iostream>
#include "CercadorMoviesAB.h"
#include "CercadorMoviesHeap.h"
#include <chrono>

using namespace std;
/*
 *
 *             ##################################################################################################
 *             ####   OPERACIÓ               ###    ArbreBinari               ###        MinHeap              ###
 *             ##################################################################################################
 *             ####                          ###                              ###                             ###
 *             #### Inserció arbre petit     ###                              ###                             ###
 *             #### movie_rating_small.tx    ###   1,0 Mil·lèsimes de segon   ###   1,0 Mil·lèsimes de segon  ###
 *             ##################################################################################################
 *             ####                          ###                              ###                             ###
 *             #### Inserció arbre gran      ###                              ###                             ###
 *             #### movie_rating.txt         ###   593 Mil·lèsimes de segon   ###   815 Mil·lèsimes de segon  ###
 *             ##################################################################################################
 *             ####                          ###                              ###                             ###
 *             ### Cerca arbre petit         ###                              ###                             ###
 *             ### cercaPelicules.txt        ###   790 Mil·lèsimes de segon   ###   479 Mil·lèsimes de segon  ###
 *             ##################################################################################################
 *             ####                          ###                              ###                             ###
 *             ### Cerca arbre gran          ###                              ###                             ###
 *             ### cercaPelicules.txt        ###   1260 Mil·lèsimes de segon   ###   2453 Mil·lèsimes de segon ###
 *             ##################################################################################################
 *    
 *      
 *    Abans de res, he de dir que, que per fer aquesta pràctica he utilitzat l'IDE CLION, de JetBrains.
 *    I a l'hora de fer les últimes proves amb el VScode i comprovar que els temps obtinguts amb el CLION,
 *    son bastant inferiors al obtinguts amb VScode. Molt inferiors en algun cas. Quatre vegades més ràpid.
 * 
 *    Al final he dicidit possar aqui, les dades obtingudes amb VScode, però no son les més optimes.
 * 
 *    Pero, también veo que, con VScode cada vez obtengo resultados muy diferentes entre ellos mismos.
 *    Conclusión, no me fio de VScode.
 *    Entonces las conclusiones son difíciles de verlas claras. 
 * 
 *    Una cosa si que és clara en todos los casos.
 *    La búsqueda con Heaps, és siempre más lenta. debido que Buscar con Heaps és un coste O(n).
 * 
 * 
 *    # Aqui muestro conclusiones obtenidas con ClION: 
 *   
 *    Analitzant aquesta taula, podem veure que el temps empleat per minHeap(), és lleugerament inferior a fer-ho amb
 *    Arbreinari(). De fet, la diferència, és quasi res.
 *
 *    Menys en el cas d'una cerca amb minHeap(), que necessita 5 vegades més temps, per fer la mateixa feina.
 *
 *    Això és degut a la cerca amb minHeap() té un cost O(n) i amb arbreBinari() té un cost de O(log n).
 *    El motiu és que a arbreBinari(), per la manera que estan ordenats els nodes, només cal verificar una de les dues
 *    branques. I aixi per cada fill.
 *    En canvi, amb Heaps, es necessari verifica els dos fills de cada Pare.
 *    Perquè en Heaps, no hi ha un ordre en fill esquerre i fill dret, només hi ha la condició que el pare sigui
 *    inferior als fills.
 *
 *    Tot això comporta un cost de O(n) a la cerca, utilitzant Heaps.
 *
 *    Para la implementación de este main(), yo hubiera utilizado clases para el ejercicio 1,2,3 y 4. Y instanciarlos
 *    desde este main.
 *    Pero el enunciado especificaba de poner en este main, los cuatro ejercicios en forma de métodos.
 *
 *    De esta forma, queda una clase main, con una cohesión muy baja. Lo que va en contra de un óptimo patrón de diseño.
 *
 *
 */

void menu(int &opcio, string tipusCerca, LecturaDades lectura) {
    //Post: print per pantalla opcions del menu
    vector<string> opMenu =
            {"1. Triar fitxer lectura ", "2. Mostrar arbre en ordre creixent", "3. Llegir fitxer \"cercaPelicules.txt\"",
             "4. Visualitzar profunditat de l'arbre", "5. Esborrar les n pelicules amb Id més petit",
             "6. Sortit"};

    cout << "\nCERCADOR DE PELICULES AMB \e[1m" << tipusCerca << "\e[0m \n" << endl;

    for (int i = 0; i < 6; ++i) {
        cout << opMenu[i] << endl;
    }
    opcio = lectura.llegirStringTOint("\nOpció: ", 1, 6);   // Va a llegir la opció seleccionada
}
template <class Classe>
void triarFitxer(Classe* cercador) {
    //Post: pregunta quin fitxe vols seleccionar
    string opcio;
    cout << "\nQuin fitxer vols utilitzar ( P / G) (Petit o Gran): ";
    cin >> opcio;
    opcio = tolower(opcio[0]);

    if (opcio != "p" && opcio != "g")
        throw invalid_argument("\e[1mOpció no vàlida\e[0m");
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    if (opcio == "p")                       
        cercador->appendMovies("ressources/movie_rating_small.txt"); 
    else
        cercador->appendMovies("ressources/movie_rating.txt"); 
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end -begin).count()
    << " Mil·lèsimes de segon." << endl;
}
void llegirFitxerCerques(vector<int> &idCerca){
    int n = 0;
    if (idCerca.size() == 0){               // Per no llegir dos cops el fitxer, en una segona crida
        if (ifstream arxiu{ "ressources/cercaPelicules.txt"}) {
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
        cout << "\nDestruint arbre _tree1" << endl;
        delete _tree1;
        cout << "\nDestruint arbre _tree2" << endl;
        delete _tree2;
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
            movie.toString();  //movie.print() << endl;
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
    //Post: retorna valor del mètode profunditat()
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cout << "\nLa profunditat d'aquest arbre es: " << cercador->profunditat() << endl;

}
template <class Classe>
void eliminarNodes(Classe * cercador, LecturaDades lectura ){
    //Post: Pregunta a usuari, quants nodes vol eliminar i va al mètode eliminarMinimaMovie()
    int opcioEliminar;
    cout << "\n\nQuants nodes vols eliminar?: " ;
    opcioEliminar = lectura.llegirStringTOint("\nOpció: ", 1, INT32_MAX);
    cercador->eliminarMinimaMovie(opcioEliminar);
}
template<typename Base, typename T>
inline bool instanceof(const T *cercador) {
    //Post: Mètode que detecta quina classe arriba per paràmetres.
    return dynamic_cast<const Base*>(cercador) != nullptr;
}

template <class ClasseComodi>
void opcionsMenu(const int opcio, vector<int> &idCerca, ClasseComodi *cercador, LecturaDades lectura ) {
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
            eliminarNodes(cercador, lectura);
            break;
        case 6:
            if(instanceof<CercadorMoviesAB<int, Movie>>(cercador))   // Si és ArbreBinari, farà el delete
                delete cercador;     // Sortir del menu i destruir punters d'Arbre Binari
            break;
        default:
            break;
    }
}

template <class ClasseComodi>
void main_Binari_Heap(ClasseComodi *cercador, LecturaDades lectura){
    int opcio;
    string fitxer, tipusCerca;
    vector<int> idCerca;
    Movie movie;

    //*** Detecta quina classe arriba instanciada per paràmetres
    if(instanceof<CercadorMoviesAB<int, Movie>>(cercador))
        tipusCerca = "( ARBRE BINARI )";                      // Text que es veura al menu
    else
        tipusCerca = "( HEAPS )";                            // Text que es veura al menu
    try {
        do {
            try {
                menu(opcio, tipusCerca, lectura);                   // Mostra menu
                opcionsMenu(opcio, idCerca, cercador, lectura);     // Llegeix opcions del menu
            }catch(const invalid_argument &e){
                cerr << e.what() << '\n';
            }
        } while (opcio != 6);            // Sortida del menu
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
/*########################################################
  #####           MAIN ARBRE BINARI                    ###
  ########################################################*/

void mainArbreBinari( LecturaDades lectura){    // Este método en vez de penalizar, debería doblar la nota
    main_Binari_Heap(new CercadorMoviesAB<int, Movie>, lectura);
}

/*########################################################
  #####           MAIN HEAP                            ###
  ########################################################*/

void mainHeap( LecturaDades lectura){           // Este método en vez de penalizar, debería doblar la nota
    main_Binari_Heap(new CercadorMoviesHeap<int, Movie>, lectura);
}

int main(){


    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    // TODO .......  MODIFICAR RUTA ACCESS A FITXERS... PER ENTREGAR
    LecturaDades lectura;      // Classe per llegir opcions dels menus del projecte

    int opcioMain;
    do {
        try {
            menuMain();
            opcioMain = lectura.llegirStringTOint("\nOpció: ", 1, 5);
            switch ( opcioMain) {
                case 1:
                    mainExercici_1();
                    break;
                case 2:
                    mainArbreBinari(lectura);  // Exigència de l'exercici, noms diferents
                    break;
                case 3:
                    casDeProvaExercici3();
                    break;
                case 4:
                    mainHeap(lectura);         // Exigència de l'exercici, noms diferents
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