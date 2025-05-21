/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 29/11/2024
    copyright            : (C) 2024 par XRICOVILLA et TRAN
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool estNumero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // Si un carácter no es un dígito, no es número
        }
    }
    return !str.empty(); // Devuelve false si la cadena está vacía
}

void Catalogue::Ajouter(Trajet* t)
// Algorithme :
//
{
    liste_trajets.Ajout(t);
    nombre_trajets++;
}//----- Fin de Méthode

void Catalogue::Rechercher(const char* villeD, const char* villeA)
// Algorithme :
//
{
    liste_trajets.Rechercher(villeD, villeA);
}//----- Fin de Méthode

void Catalogue::Afficher(void)
// Algorithme :
//
{
    if (nombre_trajets==0){
        cout<<"Il n'y a pas encore des trajets disponibles"<<endl;
    }
    else{
        liste_trajets.Afficher();
    }
}//----- Fin de Méthode

void Catalogue::Initialiser(void)
// Algorithme :
//
{
    TrajetSimple* t1 = new TrajetSimple("TS1", "Lyon", "Paris", "TGV");
    TrajetSimple* t2 = new TrajetSimple("TS2", "Paris", "Lille", "Bus");
    liste_trajets.Ajout(t1);
    liste_trajets.Ajout(t2);
    Trajet* tab[2]={new TrajetSimple("TS1", "Lyon", "Paris", "TGV"),new TrajetSimple("TS2", "Paris", "Lille", "Bus")};
    TrajetCompose* tc = new TrajetCompose("TC1", "Lyon", "Lille", tab, 2);
    liste_trajets.Ajout(tc);
    nombre_trajets=3;
}//----- Fin de Méthode

void Catalogue::SurEcrire(string name){

    name = name + ".txt";
    ifstream fichier_e(name);
    if (!fichier_e) {
       cerr << "Erreur d'ouverture du fichier !" << endl;
       return;
   }
    string ligne;
    vector<vector<string>> tous;
    while (getline(fichier_e, ligne)){
        vector<string> parties;
        stringstream ss(ligne);
        string elements;
        while(getline(ss, elements,',')){
            parties.push_back(elements);
        }
        tous.push_back(parties);
    }
    int nombre_ts = 0;
    
    //cout<<nombre_ts<<endl;
    /*
    for (const auto& fila : tous) {
        for (const auto& elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }*/


    if (nombre_ts==0){
        for (const auto& parties : tous) {
            string nom, villeD, villeA, transport;
            if (parties.size() < 4) {
                cerr << "Error: parties no tiene suficientes elementos." <<tous.size()<<endl;
                continue;
            }
            nom = parties[0];
            char* puntero_n = new char[nom.size() + 1]; // Reservar memoria
            strcpy(puntero_n, nom.c_str());

            villeD= parties[1];
            char* puntero_d = new char[villeD.size() + 1]; // Reservar memoria
            strcpy(puntero_d, villeD.c_str());

            villeA=parties[2];
            char* puntero_a = new char[villeA.size() + 1]; // Reservar memoria
            strcpy(puntero_a, villeA.c_str());

            if(estNumero(parties[3])){
                nombre_ts=stoi(parties[3]);
                Trajet** lis_trajets_simples= new Trajet*[nombre_ts];
                for(int i=0; i<(nombre_ts)*4;i=i+4){
                    string nom, villeD, villeA, transport;
                    nom = parties[i+4];
                    char* puntero_n = new char[nom.size() + 1]; // Reservar memoria
                    strcpy(puntero_n, nom.c_str());

                    villeD= parties[i+5];
                    char* puntero_d = new char[villeD.size() + 1]; // Reservar memoria
                    strcpy(puntero_d, villeD.c_str());

                    villeA=parties[i+6];
                    char* puntero_a = new char[villeA.size() + 1]; // Reservar memoria
                    strcpy(puntero_a, villeA.c_str());
                    transport=parties[i+7];
                    char* puntero_t = new char[transport.size() + 1]; // Reservar memoria
                    strcpy(puntero_t, transport.c_str());

                    lis_trajets_simples[i/4] = new TrajetSimple(puntero_n, puntero_d, puntero_a, puntero_t);
                }
                TrajetCompose* tc = new TrajetCompose(puntero_n, puntero_d, puntero_a, lis_trajets_simples, nombre_ts);
                this->Ajouter(tc);
            }
            else{
                transport=parties[3];
                char* puntero_t = new char[transport.size() + 1]; // Reservar memoria
                strcpy(puntero_t, transport.c_str());

                TrajetSimple* ts = new TrajetSimple(puntero_n, puntero_d, puntero_a, puntero_t);
                this->Ajouter(ts);
            }
            //delete[] puntero_n;
            //delete[] puntero_a;
            //delete[] puntero_a;
            //delete[] puntero_t;
        }
    }else{
        for(int i=4; i<(1+nombre_ts*4);i++){

        }
    }

    
   
}

void Catalogue::Sauvegarder(string name){
  name = name + ".txt";
  ofstream fichier_w(name);

  if (!fichier_w) {
       cerr << "Erreur d'ouverture du fichier !" << endl;
       return;
   }
   else{
   Node *current = liste_trajets.GetHead();

   // Verificación adicional
    if (current == nullptr) {
        cerr << "Error: current es nullptr antes del bucle principal" << endl;
        return;
    }

   while(current!=nullptr){

     Trajet* t = current->GetTrajet();
     //cout << "Procesando nodo: " << current << endl;

     if (dynamic_cast<TrajetSimple*>(t)){
       string nom, villeA, villeD, transport;
       nom = t->Get('n');
       villeD = t->Get('d');
       villeA = t->Get('a');
       transport = t->Get('t');
       fichier_w<<nom<<','<<villeD<<','<<villeA<<','<<transport<<endl;
     }
     else if(dynamic_cast<TrajetCompose*>(t)){
       TrajetCompose *tc = dynamic_cast<TrajetCompose*>(t);
       L_trajet& list_tc = dynamic_cast<TrajetCompose*>(t)->GetListeTrajets();
       //L_trajet& list_tc = dynamic_cast<TrajetCompose*>(t)->GetListeTrajets();

       
       Node *subCurrent= list_tc.GetHead();
       fichier_w <<tc->Get('n')<<","<<tc->Get('d')<<','<<tc->Get('a')<<','<<tc->GetNombreTrajets();


       while(subCurrent!=nullptr){
        //cout << "Procesando subnodo: " << subCurrent << endl;
        Trajet *ts =subCurrent->GetTrajet();
        if (dynamic_cast<TrajetSimple*>(ts)){
         string noms, villeAs, villeDs, transports;
         noms = ts->Get('n');
         villeDs = ts->Get('d');
         villeAs = ts->Get('a');
         transports = ts->Get('t');
         fichier_w<<','<<noms<<','<<villeDs<<','<<villeAs<<','<<transports;
        }
        else if (dynamic_cast<TrajetCompose*>(ts)) {
            cout << "Es un TrajetCompose." << endl;
        } else {
            cout << "Es un Trajet." << endl;}
         subCurrent=subCurrent->GetNext();
        }
        fichier_w<<endl;
       }
     else{
        fichier_w<<"Hay un pedo y no es ningun tipo we";
     }
     current = current->GetNext();
   }
   }
 }

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur



Catalogue::Catalogue ( ) : liste_trajets()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
nombre_trajets =0;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
