/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$ holq
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#if ! defined ( LTRAJET_H )
  #include "L_trajet.h"
#endif
#if ! defined ( TrajetCompose_H )
    #include "TrajetCompose.h"
#endif
#if ! defined ( TrajetSimple_H )
    #include "TrajetSimple.h"
#endif
#if ! defined ( Trajet_H )
  #include "Trajet.h"
#endif

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe Catalogue gère une collection de trajets et permet d'effectuer
// des recherches, d'ajouter de nouveaux trajets et d'afficher la liste des
// trajets disponibles dans le catalogue.
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet *t);
    // Mode d'emploi :
    // Cette méthode ajoute un objet Trajet (simple ou composee) au catalogue.
    //
    // Contrat :
    // Le trajet ne doit pas être un pointeur nul.
    void Rechercher(const char *, const char*);
    // Mode d'emploi :
    //Cette méthode permet de chercher des trajets dans le catalogue
    // Contrat :
    //
    void Afficher(void);
    // Mode d'emploi :
    // Cette méthode parcourt la liste des trajets et les affiche un par un.
    //
    // Contrat :
    //
    void Initialiser(void);
    // Mode d'emploi :
    // Cette méthode cree un exemple.
    //
    // Contrat :
    //
    void Sauvegarder(std::string);
    void SurEcrire(std::string name);

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
    Catalogue (void);
    // Mode d'emploi :
    // Crée un objet Catalogue vide
    // Contrat :
    // Le nom ne doit pas être un pointeur nul.


    virtual ~Catalogue ( );
    // Mode d'emploi :
    // destruit un catalogue
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
int nombre_trajets;
L_trajet liste_trajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
