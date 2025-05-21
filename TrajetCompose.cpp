/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher(void)
// Algorithme :
//
{

    Trajet::Afficher();
    cout<<" est composé de : "<<endl;
    cout<<"[ "<<endl;
    l_trajet.Afficher();
    cout<<"]"<<endl;

}//----- Fin de Méthode
L_trajet& TrajetCompose::GetListeTrajets(void){
  return l_trajet;
}
int TrajetCompose::GetNombreTrajets(void){
  return nombre_t;
}
//------------------------------------------------- Surcharge d'opérateurs

TrajetCompose::TrajetCompose(const TrajetCompose& other) : Trajet(other) 
{
  #ifdef MAP
    cout << "Appel au copie de <TrajetCompose>" << endl;
  #endif
  nombre_t = other.nombre_t;
  l_trajet = other.l_trajet;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const char* noM, const char* ville_D, const char* ville_A, Trajet* trajets[], int numtrajets) : Trajet(noM, ville_D, ville_A)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
  nombre_t = numtrajets;
  for(int i =0;i<nombre_t;l_trajet.Ajout(trajets[i++]));
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
