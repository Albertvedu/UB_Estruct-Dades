#include <iostream>
#include <vector>
using namespace std;

void identificat(string &nom)
{
    cout << "Hola, com et dius? ";
    cin >> nom;
}
void llegirOpcio(int &opcio, int arrSize)
{
    // Post: Retorna l'opció del menu

    do
    {
        cout << "\nopció: ";
        cin >> opcio;
        if (opcio <= 0 || opcio > arrSize)
            cout << "Opció incorrecta: \n\n"
                 << endl;
    } while (opcio <= 0 || opcio > arrSize);
}
void menu(int &opcio, string nom, vector<string> arrOptions)
{
    cout << "\nHola " << nom << ", que vols fer? " << endl;
    vector<string>::iterator it;

    for (it = arrOptions.begin(); it != arrOptions.end(); ++it)
        cout << "\n"
             << *it << endl;
    llegirOpcio(opcio, arrOptions.size());
}
void benvinguda(string nom)
{
    cout << "\nBenvingut/da a l'assignatura d'estructura de dades " << nom << endl;
}

int main()
{
    string nom;
    vector<string> arrOptions = {"1. Sortir", "2. Benvinguda", "3. Redefinir el nom"};
    int opcio;
    identificat(nom);

    do
    {
        menu(opcio, nom, arrOptions);
        switch (opcio)
        {
        case 2:
            benvinguda(nom);
            break;
        case 3:
            identificat(nom);
            break;
        default:
            break;
        }
    } while (opcio != 1);

    cout << "\nFins a la propera " << nom << endl
         << endl;

    return 0;
}