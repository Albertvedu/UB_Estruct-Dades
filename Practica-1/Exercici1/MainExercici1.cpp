#include <iostream>
using namespace std;

void identificat(string &nom){
    cout << "Hola, com et dius? ";
    cin >> nom;
}
void llegirOpcio(int &opcio, int arrSize){
    //Post: Retorna l'opció del menu
    
    do{
        cout << "\nopció: "; 
        cin >> opcio;
        if (opcio <= 0 || opcio > arrSize) 
            cout << "Opció incorrecta: \n\n" << endl;
    }while(opcio <= 0 || opcio > arrSize);
}
void menu(int &opcio, string nom, string arrOptions[], int arrSize){
    cout << "\nHola " << nom << ", que vols fer? " << endl;
    
    for(int i= 0; i < arrSize; i++)
        cout << "\n" << arrOptions[i] << endl;
    llegirOpcio(opcio, arrSize);

}
void benvinguda(string nom){
    cout << "\nBenvingut/da a l'assignatura d'estructura de dades " << nom << endl;
}

int main(){
    string nom;
    string arrOptions [] = {"1. Sortir", "2. Benvinguda"};
    int opcio;
    identificat(nom);
    int arrSize = (sizeof(arrOptions)/sizeof(arrOptions[0]));

    do{
        menu(opcio, nom, arrOptions, arrSize);
        switch (opcio){
            case 2:
                benvinguda(nom);
                break;
            default:
                break;
        }
        
    }while ( opcio != 1 );

    cout << "\nFins a la propera " << nom << endl << endl;

    return 0;
}