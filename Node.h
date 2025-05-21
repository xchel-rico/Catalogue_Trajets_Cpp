/*************************************************************************
                           Node  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if ! defined ( Node_H )
#define Node_H
//--------------------------------------------------- Interfaces utilisées
#if ! defined ( Trajet_H )
  #include "Trajet.h"
#endif

//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------

class Node
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
  

  void SetNext(Node*);
  // Mode d'emploi :
  //Cette méthode change le pointeur next à un autre node
  // Contrat :
  //

  Node* GetNext(void);
  // Mode d'emploi :
  //Cette méthode retourne le pointeur point au node suivant
  // Contrat :
  //
  Trajet* GetTrajet(void);
  // Mode d'emploi :
  //Cette méthode retourn le pointeur de trajet 
  // Contrat :
  //
//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
  Node (Trajet*);
  // Mode d'emploi :
  //Cette méthode construit un node de trajet à partir d'un trajet 
  //
  virtual ~Node ( );
  // Mode d'emploi :
  //Cette méthode détruit un node
  // Contrat :
  //
protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
  Trajet* val;
  Node* next;
};

//-------------------------------- Autres définitions dépendantes de <Node>

#endif// Node_H
