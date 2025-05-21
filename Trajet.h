/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------

#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées
  /*#if ! defined ( LTRAJET_H )
    #include "L_trajet.h"
  #endif*/
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet //: public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( void );
    // Mode d'emploi :
    //Cette méthode affiche le trajet.
    // Contrat :
    //
    //virtual L_trajet GetListeTrajets(void)=0;

    virtual const char* Get(char );
    // Mode d'emploi :
    //Cette methode retourne un pointeur constant sur la ville de départ, la
    //ville d'arivee ou le nom de trajet
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
  //Trajet(const Trajet& other);

//-------------------------------------------- Constructeurs - destructeur
    Trajet (const char*, const char*, const char*);
    // Mode d'emploi :
    //Cette méthode construit un trajet à partir du Depart, de l'arrivée et de son nom
    // Contrat :
    //


    virtual ~Trajet ( );
    // Mode d'emploi :
    //Cette méthode détruit un trajet, elle doit être virtuelle.
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  char *nom;
  char *ville_d;
  char *ville_a;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H
