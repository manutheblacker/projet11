#include <iostream>
using namespace std;
#include "Etudiants.h"
#include "Etudiant_en_Maitrise.h"
int main() {
    cout << "Bienvenue dans le programme permettant d'obtenir les informations sur un étudiant.";
    Etudiants etudiant1;
    etudiant1.inscription();
    Etudiants etudiant2;
    etudiant2.inscription();
    etudiant1.exae_quo(etudiant2);
    Etudiant_en_Maitrise etudiant3();
    etudiant3().admis();
    Etudiant_en_Maitrise etudiant4();
    etudiant4().admis();
    etudiant3().exae_quo(etudiant4());
    return 0;
}
