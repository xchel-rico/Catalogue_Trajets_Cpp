/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char * TrajetSimple::Get(char lettre){
  if (lettre=='t'){
    return transport;
  }
  else{
    return Trajet::Get(lettre);
  }
}

void TrajetSimple::Afficher(void)
{
    Trajet::Afficher();
  cout<<" en "<<transport<<endl;
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

/*TrajetSimple::TrajetSimple(const TrajetSimple& other)
        : Trajet(other) {
          #ifdef MAP
            cout << "Appel au copie de <TrajetSimple>" << endl;
          #endif
          transport = other.transport;
        }*/


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* noM, const char* ville_D, const char* ville_A, const char* tranS) : Trajet(noM, ville_D, ville_A)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
transport = new char[strlen(tranS) + 1];
strcpy(transport, tranS);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
}
 //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
