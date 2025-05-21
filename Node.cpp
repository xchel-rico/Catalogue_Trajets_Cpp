/*************************************************************************
                           Node  -  description
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

//------------------------------------------------------ Include personnel
#include "Node.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Trajet* Node::GetTrajet(void)
// Algorithme :
//
{
  return val;
}//----- Fin de Méthode
void Node::SetNext(Node* node_next)
// Algorithme :
//
{
  next = node_next;
}//----- Fin de Méthode

Node* Node::GetNext(void)
// Algorithme :
//
{
  return next;
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Node::Node (Trajet* ptrajet)
// Algorithme :
//
{
  #ifdef MAP
    cout << "Appel au constructeur de <Node>" << endl;
  #endif
  val = ptrajet;
  next = nullptr;
}//----- Fin de Node

Node::~Node()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Node>" << endl;
#endif
} //----- Fin de ~Node

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées