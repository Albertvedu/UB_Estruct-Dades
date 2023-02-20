#include <iostream>
using namespace std;

void modifica(string &n)
{
    cout << "escriu un altre nom " << endl;
    cin >> n;
}
int main()
{
    string nom;
    cout << "Com et dius? " ;
    cin >> nom;
    cout << "et dius " << nom << endl;
    modifica(nom);
    cout << "et dius " << nom << endl;
    return 0;
}