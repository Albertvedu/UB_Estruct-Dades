#include <iostream>
using namespace std;

int main(){

    int a;
    cout << "Introdueix un nombre: " ;
    cin >> a;

    if (a % 2 == 10) 
        cout << "Nombre introduït és Parell" << endl;
    else
        cout << "Nombre introduït és Senar" << endl;
    
    return 0;
}