//
// Created by Emmanuel ADEKPLOVI on 10/11/20.
//

#ifndef PROJET11_ETUDIANT_EN_MAITRISE_H
#define PROJET11_ETUDIANT_EN_MAITRISE_H
#include "Etudiants.h"


class Etudiant_en_Maitrise :  Etudiants{

private:
    double note_memoire ;

    void set_note_memoire(double note_memoire){
        this->note_memoire = note_memoire;
    }

    double get_note_memoire(){
        return this->note_memoire;
    }


public:
    Etudiant_en_Maitrise(){
        this->inscription();
        this->continuer();
    }

    bool admis(){
        bool is_admis = false;
        if (this->calculateMoyenne() >= 10 && this->get_note_memoire() >= 10){
            is_admis = true;
        }
        return is_admis;
    }

    bool exae_quo(Etudiant_en_Maitrise etudiants_a_comparer){
        bool same_moy = false;
        if ( this->calculateMoyenne() == etudiants_a_comparer.calculateMoyenne() && this->admis() == etudiants_a_comparer.admis()){
            same_moy = true;
        }
        return same_moy;
    }

};


#endif //PROJET11_ETUDIANT_EN_MAITRISE_H
