/*************************************************************************
                           L_trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               : $EMAIL$ holq
*************************************************************************/

//---------- Réalisation de la classe <L_trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "L_trajet.h"
//------------------------------------------------------------- Constantes
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques



void L_trajet::Ajout(Trajet* trajet)
// Algorithme :
//
{
  if (trajet == nullptr) {
    std::cerr << "Error: trying to add a null trajet!" << std::endl;
    return; // O manejar el error adecuadamente
  }
  //std::cout << "Tipo dinámico antes de agregar: " << typeid(*trajet).name() << std::endl;
  Node* node_t = new Node(trajet);
  //std::cout << "Tipo dinámico en nodo: " << typeid(*node_t->GetTrajet()).name() << std::endl;
  //if (head != nullptr && strcmp(ville, head->GetTrajet()->Get('d')) < 0)
  const char* ville = trajet->Get('d');

  if (head==nullptr)
  {
    head=node_t;
    fin=node_t;
  }
  else if (strcmp(ville, head->GetTrajet()->Get('d')) < 0)
  {
    node_t->SetNext(head);
    head = node_t;
  }
  else
  {
    Node* ptr = head;
    Node* prev =nullptr;
    while(ptr!=nullptr && strcmp(ville, ptr->GetTrajet()->Get('d')) >= 0)
    {
        prev=ptr;
        ptr=ptr->GetNext();
    }
    // Insérer le nouveau nœud entre 'prev' et 'ptr'
    prev->SetNext(node_t);
    node_t->SetNext(ptr);
    if(ptr==nullptr)
    {
      fin = node_t;
    }
  }
  numT++;
}//----- Fin de Méthode

void L_trajet::Afficher(void)
// Algorithme :
//
{
  Node* ptr = head;
  while(ptr!=nullptr)
  {
    ptr->GetTrajet()->Afficher();
    ptr = ptr->GetNext();
  }
}//----- Fin de Méthode

Node* L_trajet::GetHead(){
  return head;
}

void L_trajet::Rechercher(const char* vd, const char* va)
// Algorithme :
//
{
  Node* ptr = head;
  while(ptr!=nullptr && (strcmp(ptr->GetTrajet()->Get('d'),vd)!=0))// || strcmp(ptr->GetTrajet()->Get('a'),va)!=0) )
  {
    ptr = ptr->GetNext();
  }
  if (ptr==nullptr)
  {
    cout<<"Pas de trajet possible"<<endl;
  }
  else
  {
    while(ptr!=nullptr && (strcmp(ptr->GetTrajet()->Get('d'),vd) == 0))// && strcmp(ptr->GetTrajet()->Get('a'),va)==0))
    {
      if (strcmp(ptr->GetTrajet()->Get('a'),va)==0){
        cout<<"-----------"<<endl;
        ptr->GetTrajet()->Afficher();
        cout<<"-----------"<<endl;
      }
      ptr = ptr->GetNext();
    }
  }
}//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

L_trajet::L_trajet(const L_trajet& other) {
    Node* current = other.head; // Suponiendo que `head` es el puntero inicial
    while (current != nullptr) {
        // Crear nuevos nodos y copiar el contenido
        Ajout(new Trajet(*(current->GetTrajet())));
        current = current->GetNext();
    }
}

//-------------------------------------------- Constructeurs - destructeur


L_trajet::L_trajet(void)
// Algorithme :
//
{
  #ifdef MAP
    cout << "Appel au constructeur de <L_trajet>" << endl;
#endif
  head=nullptr;
  fin=nullptr;
  numT=0;
}//----- Fin de L_trajet


L_trajet::~L_trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <L_trajet>" << endl;
#endif
Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->GetNext(); // Guardamos el siguiente nodo
        delete current->GetTrajet();    // Liberamos la memoria del `Trajet` contenido en el nodo
        delete current;            // Liberamos el nodo
        current = next;            // Avanzamos al siguiente nodo
    }
    head = nullptr;
    fin = nullptr;
} //----- Fin de ~L_trajet
/*
L_trajet::~L_trajet() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->GetNext();
        delete toDelete->GetTrajet(); // Liberar Trajet asociado
        delete toDelete;             // Liberar el nodo
    }
}*/

//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées
