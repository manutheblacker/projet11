//
// Created by Emmanuel ADEKPLOVI on 10/6/20.
//

#ifndef PROJET11_ETUDIANTS_H
#define PROJET11_ETUDIANTS_H
#include "iostream"
using namespace std;

class Etudiants {

public:

    void saisie(){
        string noms;
        cout << "Veuillez entrer votre nom de famille : "<<endl;
        cin >> noms;
        if ( noms.empty() ){
            cout << "Le nom de famille ne peut être vide. "<<endl;
        }
        this->setNoms(noms);
        string prenoms;
        cout << "Veuillez entrer votre prénoms : "<<endl;
        cin >> prenoms;
        if ( noms.empty() ){
            cout << "Le nom de famille ne peut être vide. "<<endl;
        }
        this->setPrenoms(prenoms);
        double notes[10];
        int note_limit = 0;
        while (note_limit <= 10){
            double note;
            cout << "Veuillez entrer la note : "<< note_limit<<endl;
            cin >> note;
            if ( !note){
                note = 0;
            }
            this->setNotes(note,note_limit);
            note_limit ++;
        }
    }

    void affichage(){
        cout << "L'étudiant de noms de famille : "<< this->getNoms()<< " et de prénoms : " << this->getPrenoms() << "a pour notes : "<< this->getNotes() <<endl;
    }

    void moyenne(){
        cout << "La moyenne obtenue par l'étudiant est : " << this->calculateMoyenne() << endl;
    }

    void setNotes(double note, int notes_position){
        this->tabnotes[notes_position] = note;
    }

    void setNoms(string noms){
        this->noms = noms;
    }

    void setPrenoms(string prenoms){
        this->prenoms = prenoms;
    }

    string getNoms(){
        return this->noms;
    }

    string getPrenoms(){
        return this->prenoms;
    }


    double * getNotes(){
        return this->tabnotes;
    }

    bool admis(){
        bool admis= true;
        if (this->calculateMoyenne() <= 10){
            admis = false;
        }
        return admis;
    }

    bool exae_quo(Etudiants etudiants_a_comparer){
        bool same_moy = false;
        if ( this->admis() == etudiants_a_comparer.admis()){
            same_moy = true;
        }
        return same_moy;
    }

    void continuer(){
        cout << "Aimeriez-vous continuer? Oui(y) ou Non(n)" <<endl;
        char choix;
        cin >> choix;
        while(choix){
            inscription();
            break;
        }
    }

     void inscription(){
        cout << "Veuillez chosir ce que vous aimerez faire : " <<endl;
        cout << "1 - Ajouter un nouvel étudiant.  " <<endl;
        cout << "2 - Ajouter les notes pour l'étudiant.  " <<endl;
        cout << "3 - Obtenir la moyenne de l'étudiant.  " <<endl;
        cout << "4 - Obtenir l'admissibilité de l'étudiant.  " <<endl;
         cout << "5 - Quitter le programme.   " <<endl;

         int choix;
        cin >> choix;
        switch (choix) {
            case 1:
                this->ajouterEtudiant();
                this->continuer();
                break;

            case 2:
                this->ajouterNotes();
                this->continuer();
                break;

            case 3:
                cout  << " La moyenne de l'étudiant est : " << this->calculateMoyenne() << endl;
                this->continuer();
                break;

            case 4:
                if (this->admis()){
                    cout << " L'etudiant est admis." <<endl;
                }else{
                    cout << "L'etudiant a échouée."<<endl;
                }
                this->continuer();
                break;

            case 5:
            default:
                cout << "Veuillez choisir une valeur comprise entre 1 et 4." <<endl;
                this->continuer();
                break;
        }

    }




private:
    string noms;
    string prenoms;
    double tabnotes[10];

    void ajouterEtudiant(){
        string etudiant_name, etudiant_prenoms;
        cout << "Veuillez entrer le nom de famille de l'étudiant : " <<endl;
        cin >> etudiant_name;
        this->setNoms(etudiant_name);

        cout << "Veuillez entrer le prenoms de l'étudiant : " <<endl;
        cin >> etudiant_name;
        this->setPrenoms(etudiant_prenoms);
    }

    void ajouterNotes(){
        double notes[10];
        int index = 0;
        while (index < 10){
            double tmp_notes;
            cout << "Veuillez entrer la note " << index+1<<" de l'étudiant : " <<endl;
            cin >> tmp_notes;
            this->setNotes(tmp_notes,index);
            index ++;
        }
    }

protected:
    double calculateMoyenne(){
        double * notes = this->getNotes();
        double tmp_notes_sum;
        for(int i=0; i <= 10 ; i++){
            tmp_notes_sum += notes[i];
        }
        return tmp_notes_sum / 10;
    }
};



#endif //PROJET11_ETUDIANTS_H
