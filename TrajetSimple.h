/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H
//--------------------------------------------------- Interfaces utilisées
#if ! defined ( Trajet_H )
  #include "Trajet.h"
#endif
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( void );
    // Mode d'emploi :
    //Cette méthode affiche un Trajet Simple
    // Contrat :
    //
    virtual const char * Get( char);

//------------------------------------------------- Surcharge d'opérateurs
//TrajetSimple(const TrajetSimple& other);
//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char*, const char*, const char*, const char*);
    // Mode d'emploi :
    //Cette méthode construit un trajet simple à partir de son départ, arrivée, nom et moyen de transport
    // Contrat :
    //
    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //Cette méthode détruit un trajet simple
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  char* transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TrajetSimple_H
