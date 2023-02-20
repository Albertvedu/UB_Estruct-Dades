#include <iostream>
using namespace std;

double harmonic(int &x){

    double resultat = 0.0;

    for( int i = 2; i <= x; i++){
        resultat += 1.0/i;
        cout << ".... " << resultat;
    }
    return resultat;
}

int main(){
    int x ;
    cout << "Introdueix un nombre enter: ";
    cin >> x;
    cout << "Resultat: " << harmonic(x) << endl;
    

    return 0;
}