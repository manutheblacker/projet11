#include <iostream>
using namespace std;
#include "Etudiants.h"

 void exae_quo(Etudiants etudiant_extra){
    cout << "Aimeriez-vous voir si cet étudiant est exae_quo avec un autre étudiant ? Oui(y) ou Non(n)";
    Etudiants etudiants2;
    char choix;
    cin >> choix;
    switch (choix) {
        case 'y':
            cout << "Veuillez entrer les informations de l'étudiant à comparer.";
            etudiants2.inscription();
            etudiant_extra.exae_quo(etudiants2);
            break;

        case 'n':
        default:
            cout << "Merci d'avoir utiliser le programme à la prochaine.";
            break;
    }
}

int main() {
    cout << "Bienvenue dans le programme permettant d'obtenir les informations sur un étudiant.";
    Etudiants etudiant1;
    etudiant1.inscription();
    etudiant1.continuer();
    exae_quo(etudiant1);
    return 0;
}
