/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$ holq
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H
//--------------------------------------------------- Interfaces utilisées
#if ! defined ( Trajet_H )
  #include "Trajet.h"
#endif

#if ! defined ( LTRAJET_H )
  #include "L_trajet.h"
#endif
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( void );
    // Mode d'emploi :
    //Cette méthode affiche un trajet Composé
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
  TrajetCompose(const TrajetCompose& other);

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const char*, const char*, const char*, Trajet* trajets[], int);
    // Mode d'emploi :
    //Cette méthode construit un trajet composé à partir de son nom, de ville départ et
    //ville d'arrivee d'une Liste de Trajets
    // Contrat :
    //
    L_trajet& GetListeTrajets(void);
    int GetNombreTrajets(void);
    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //Cette méthode détruit des trajets composés
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  int nombre_t;
  L_trajet l_trajet;
};
//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H
