/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$ holq
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



const char * Trajet::Get(char attribut)
{
  if(attribut=='n')
  {
    return nom;
  }
  else if(attribut=='d')
  {
    return ville_d;
  }
  else if(attribut=='a')
  {
    return ville_a;
  }
  else
  {
    return "error";
  }
}//----- Fin

void Trajet::Afficher(void)
{
  cout<<nom<<" = de "<<ville_d<<" à "<<ville_a;
}//----- Fin

//------------------------------------------------- Surcharge d'opérateurs
/*Trajet::Trajet(const Trajet& other)
        : nom(other.nom), ville_d(other.ville_d), ville_a(other.ville_a) {}*/


//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet (const char* noM, const char* ville_D, const char* ville_A)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
  nom = new char[strlen(noM) + 1];
  strcpy(nom, noM);
  ville_d = new char[strlen(ville_D) + 1];
  strcpy(ville_d, ville_D);
  ville_a = new char[strlen(ville_A) + 1];
  strcpy(ville_a, ville_A);
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
