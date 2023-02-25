#include <iostream>
#include "vector"
#include "Estudiant.h"
#include <stdexcept> 

void llegirOpcio(int &opcio, int arrSize){
    // Post: Retorna l'opció del menu

    do{
        cout << "\nopció: ";
        cin >> opcio;
        if (opcio <= 0 || opcio > arrSize)
            cout << "Opció incorrecta: \n\n"
                 << endl;
    } while (opcio <= 0 || opcio > arrSize);
}

void menu(int &opcio, vector<string> menuOptions){
    cout << "\nHola " <<  ", que vols fer? " << endl;
    vector<string>::iterator it;

    for (it = menuOptions.begin(); it != menuOptions.end(); ++it)
        cout << "\n"
             << *it << endl;
    llegirOpcio(opcio, menuOptions.size());
}
void compare(int anyNeix){
    if (anyNeix < 0 || anyNeix > 2023)
        throw invalid_argument( "Any de naixement incorrecte”" );
}
void llegirAny(int &anyNeix){
    while (true){
        try{
            cout << "\nAny neixament?: "; 
            cin >> anyNeix;
            compare(anyNeix);
            break;
        }
        catch(const std::exception& e){
            cerr << e.what() << '\n';
        }
    }
}
Estudiant afegirEstudiant(int &nEstudiant){
    //Post: Estudiant insertat 
    string nom;
    int anyNeix, nAssignatures;
    nEstudiant ++;

    cout << "\nEstudiant: " << nEstudiant << endl;
    cout << "\nNom?: "; cin >> nom;
    llegirAny(anyNeix);
    cout << "\nAssignatures?: "; cin >> nAssignatures;

    Estudiant estudiant(nom, anyNeix, nAssignatures);
  
    return estudiant;
}
void print(Estudiant estudiant){
    cout << "\n\nEstudiant (Nom ==> " << estudiant.getName()
        << ", Naixement ==> " << estudiant.getDataNaixement()
        << ", Assignatures ==> " << estudiant.getAssignatures() << ")" << endl;
    cout << "Edat del nou estudiant: " << estudiant.getEdat() << endl;
}
int main(){
    
    int nEstudiant = 0; 

    vector<string> menuOptions = {"1. Sortir", "2. Informar Estudiant"};
    int opcio;
    
     do
    {
        menu(opcio, menuOptions);
        switch (opcio)
        {
        case 2:
            print (afegirEstudiant(nEstudiant));
            break;

        default:
            break;
        }
    } while (opcio != 1);
    cout << "\nFins a la propera\n" << endl;
}