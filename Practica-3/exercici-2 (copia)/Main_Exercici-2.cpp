#include <iostream>
#include <csignal>
#include "CercadorMoviesAB.h"

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
        throw invalid_argument("merda");

    if (opcio == "p")
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/exercici-2/movie_rating_small.txt"); // todo ... cambiar ruta VS
    else
        cercador->appendMovies("/home/albert/CLionProjects/Practica-3/exercici-2/movie_rating.txt"); //todo cambiar ruta
}
void mostrarArbre(CercadorMoviesAB<int, struct Movie> *cercador) {
    if (cercador == nullptr)
        throw invalid_argument("\n\e[1mAbans has de llegir les dades del fitxer\n\e[0m");
    cercador->mostrarMovie(3676);
}
int main(){
    int opcio;
    string fitxer;

    try {

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
                        cout << "op 3" << endl;
                        break;
                    case 4:
                        cout << "op 4" << endl;
                        break;
                    case 5:
                        cout << "op 5" << endl;
                        break;
                    default:
                        break;
                }

            }catch(const std::exception& e){
                cerr << e.what() << '\n';
                sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge d'error
            }

                cout <<"cococunu" << endl;
        } while (opcio != 6);


       // cercador->appendMovies("/home/albert/CLionProjects/Practica-3/exercici-2/movie_rating_small.txt");
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge d'error
    }
    cout << "exercici2" << endl;
    return 0;
}








