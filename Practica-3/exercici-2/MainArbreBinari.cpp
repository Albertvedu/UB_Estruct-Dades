#include <iostream>
#include <csignal>
#include "CercadorMoviesAB.h"
#include "Exercici_1.h"
#include <chrono>

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
    int numero;

    while(true){
        try{
            cout << text;
            cin >> lectura;
            if(!esNumero(lectura) )
                throw invalid_argument( "Dades introduïdes incorrectes");
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
            sleep(1);
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
void triarFitxer(CercadorMoviesAB<int, Movie> *cercador) {
    string opcio;
    cout << "\nQuin fitxer vols utilitzar ( P / G) (Petit o Gran): ";
    cin >> opcio;
    opcio = tolower(opcio[0]);

    if (opcio != "p" && opcio != "g")
        throw invalid_argument("\e[1mOpció no vàlida\e[0m");
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();


    if (opcio == "p")
        cercador->appendMovies("ressources/movie_rating_small.txt"); // todo ... cambiar ruta VS
    else
        cercador->appendMovies("ressources/movie_rating.txt"); //todo cambiar ruta
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds
    >(end -begin).count() << " milessimes de segon." << endl;
}
void mostrarArbre(CercadorMoviesAB<int, struct Movie> *cercador) {
    if (cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");
    cercador->mostrarArbre();
    //cout << cercador->mostrarMovie(3676);
}
void llegirFitxerCerques(vector<int> &idCerca){
    int n;
    if (idCerca.size() == 0){                   // Per no llegir dos cops el fitxer, en una segona crida
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
void cercarTotsElement( CercadorMoviesAB<int, Movie> * cercador, vector<int> idCerca) {
    if(cercador->isNull())
        throw invalid_argument("\n\e[1mNo es possible executar aquesta acció. \nAbans has de llegir les dades del fitxer\n\e[0m");

    Movie movie;
    int contador = 0;
    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();

    for (int i = 0; i < idCerca.size(); ++i) {
        try {
            movie = cercador->buscarMovie(idCerca[i]);
            if (movie.getNom() == "") {
                throw invalid_argument("");
            }else{
                cout << movie.print() << endl;
                contador ++;
            }

        }catch(const std::exception& e){
            cerr << e.what();// << '\n';
            cout << idCerca[i] << "  No existeix" << endl;
        }
    }
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << "Temps transcorregut: " << chrono::duration_cast<chrono::milliseconds>(end1 -begin1).count() << " milessimes de segon." << endl;
    cout << "Total pel·licules trovades: " << contador << " id cerca size: " << idCerca.size() << endl;
}
void profundidad(CercadorMoviesAB<int, Movie> * cercador){
    cout << "\nLa profunditat d'aquest arbre es: " << cercador->height()-1 << endl;
}
int main(){
    int opcio;
    string fitxer;
    vector<int> idCerca;
    Movie movie;
    try {
        Exercici_1 exercici1;          // Executa l'exercici 1
        CercadorMoviesAB<int, Movie> *cercador = new CercadorMoviesAB<int, Movie>;

        do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
            try {

                menu(opcio);
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
                        cercador->eliminarMinimaMovie(20);
                        mostrarArbre(cercador);
                        break;
                    default:
                        break;
                }
            }catch(const std::exception& e){
                cerr << e.what() << '\n';
              //  sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge d'error
            }
        } while (opcio != 6);
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
      //  sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge d'error
    }
    return 0;
}








