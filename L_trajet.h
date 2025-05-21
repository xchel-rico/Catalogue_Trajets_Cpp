/*************************************************************************
                           Node  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Node> (fichier L_trajet.h) ----------------
#if ! defined ( LTRAJET_H )
#define LTRAJET_H
//--------------------------------------------------- Interfaces utilisées
#if ! defined ( Trajet_H )
  #include "Trajet.h"
#endif

#if ! defined ( Node_H )
  #include "Node.h"
#endif

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------

class L_trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  void Ajout(Trajet*);
  // Mode d'emploi :
  //Cette méthode ajout un pointeur dans la liste dans un bonne odre
  // d'alphabet selon ville de départ
  // Contrat :
  //
  virtual void Afficher(void);
  // Mode d'emploi :
  //Cette méthode affiche tous les trajets
  // Contrat :
  //
  void Rechercher(const char* , const char* );
  // Mode d'emploi :
  //Cette méthode recherche les trajets à partir de ville de départ et de ville d'arrivée,
  //et les affiche
  // Contrat :
  //
  //------------------------------------------------- Surcharge d'opérateurs
  //-------------------------------------------- Constructeurs - destructeur

  L_trajet(const L_trajet& other);

  L_trajet(void);
  // Mode d'emploi :
  //Cette méthode construit une liste de trajet vide
  virtual ~L_trajet ( );
  // Mode d'emploi :
  //Cette méthode détruit une  liste de trajet
  // Contrat :
  //
  Node* GetHead(void);

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  Node* head;
  Node* fin;
  int numT;

};

//-------------------------------- Autres définitions dépendantes de <L_trajet>

#endif // L_trajet_H
