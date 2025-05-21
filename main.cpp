#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Node.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include "L_trajet.h"
#include "Catalogue.h"
using namespace std;

void test(){
  
  //Trajet t ("T", "Lyon", "Paris");
  //t.Afficher();
  TrajetSimple* t1 = new TrajetSimple("TS1", "AB", "CD", "cheval");
  TrajetSimple* t2 = new TrajetSimple("TS2", "CD", "EF", "pied");
  TrajetSimple* t3 = new TrajetSimple("TS3", "XY", "AB", "pied");
  TrajetSimple* t4 = new TrajetSimple("TS4", "OP", "RH", "pied");

  //t1->Afficher();
  //t2->Afficher();

  L_trajet* liste= new L_trajet;
  liste->Ajout(t1);
  liste->Ajout(t2);
  liste->Ajout(t3);
  liste->Ajout(t4);

  //cout<<liste->numT<<endl;

  //cout<<liste->numT<<endl;
  //liste->Afficher();
  Trajet* tab[2]={t1,t2};
  TrajetCompose* tc = new TrajetCompose("TC1", "AB", "EF", tab, 2);
  liste->Ajout(tc);
  liste->Afficher();
  //const char* villearrive = "Lille";
  //const char* villedep ="Lyon";
  liste->Rechercher("AB", "EF");

  cout<<"----"<<endl;
  
  Catalogue *c =new Catalogue;
  c->Initialiser();
  c->Afficher();
  cout<<"----"<<endl;
  //c->Rechercher("Lyon", "Paris");
  string name = "catalogue";
  c->Sauvegarder(name);

}

void test_2(){
  //Catalogue *c =new Catalogue;
  //c->Initialiser();
  TrajetSimple* t1 = new TrajetSimple("TS1", "AB", "CD", "cheval");
  TrajetSimple* t2 = new TrajetSimple("TS2", "CD", "EF", "pied");
  Trajet* tab[2]={t1,t2};
  TrajetCompose* tc = new TrajetCompose("TC1", "AB", "EF", tab, 2);

  std::ofstream fichier_w;
  fichier_w.open("catalogue.txt");
  if (!fichier_w) {
       cerr << "Erreur d'ouverture du fichier !" << endl;
   }
  string nom;
  nom=t1->Get('n');

  fichier_w << "Nom,Prénom,Âge" << endl;
  fichier_w <<nom<<","<< t1->Get('d')<<t1->Get('a')<<t1->Get('t')<< endl;
  L_trajet list_tc = tc->GetListeTrajets();
  Node *head = list_tc.GetHead();
  Node* current =head;
  fichier_w <<tc->Get('n')<<","<<tc->Get('d')<<','<<tc->Get('a');
  while(current!=nullptr){
    string nom, villeA, villeD, transport;

    Trajet* t = current->GetTrajet();
    nom = t->Get('n');
    villeD = t->Get('d');
    villeA = t->Get('a');
    transport = t->Get('t');
    fichier_w<<':'<<nom<<','<<villeD<<','<<villeA<<','<<transport;
    current=current->GetNext();
  }
  fichier_w<<endl;
  fichier_w.close();

}

void TestGetListeTrajets() {
    // Agregar elementos a `tc.l_trajet`
    TrajetSimple* t3 = new TrajetSimple("TS3", "XY", "AB", "pied");
    TrajetSimple* t4 = new TrajetSimple("TS4", "OP", "RH", "pied");
    Trajet* tab[2]={t3,t4};
    TrajetCompose* tc = new TrajetCompose("TC1", "AB", "EF", tab, 2);

    L_trajet copia = tc->GetListeTrajets();
    
    // Recorre la copia y verifica que los datos sean correctos
    Node* current = copia.GetHead();
    while (current != nullptr) {
        cout << "Elemento: " << current->GetTrajet()->Get('n') << endl;
        current = current->GetNext();
    }
}

int main(){
  //test();
  //TestGetListeTrajets();
  Catalogue* c = new Catalogue;
  cout<<"----------------------------------------------------------------------------------"<<endl;
  cout<<"Bienvenue au catalogue des Trajets"<<endl;
  cout<<"Si tu veux construire un Catalogue depuis 0, entre la touche 0"<<endl;
  cout<<"Sinon entre n'importe quel autre touche : ";


  char touche;
  cin>>touche;
  cout<<endl;
  cout<<"----------------------------------------------------------------------------------"<<endl;
  if (touche!='0'){
    c->Initialiser();
  }
  cout<<"----------------------------------------------------------------------------------"<<endl;

  cout<<"Tu peux choisir parmi quatre options"<<endl;
  cout<<"1 : pour AJOUTER un trajet"<<endl;
  cout<<"2 : pour AFFICHER les trajets disponibles"<<endl;
  cout<<"3 : pour RECHERCHER un trajet sohaité"<<endl;
  cout<<"4 : pour Arreter le catalogue"<<endl;
  cout<<"Entre l'option souhaitée : "<<endl;
  char option;
  const int tailleMax = 100;
  cin>>option;
  while (option!='4'){
    cout<<"----------------------------------------------------------------------------------"<<endl;
    switch(option){
      case '1':
        cout<<"T'as selectioné sur AJOUTER :"<<endl;
        cout<<"Sohaites tu ajouter un trajet Simple (entre s) :"<<endl;
        cout<<"Sohaites tu ajouter un trajet Compose (entre c) :"<<endl;
        cout<<"Si tu souhaites revenir au menu precedent entre un autre touche"<<endl;
        char typetrajet;
        cin>>typetrajet;
        if(typetrajet=='s'){
          char nomtrajet[tailleMax], nomvilled[tailleMax], nomvillea[tailleMax], transport[tailleMax];

          cout<<"Quel est le nom du trajet :"<<endl;
          cin>>nomtrajet;

          cout<<"Quel est la ville de départe :"<<endl;
          cin>>nomvilled;

          cout<<"Quel est la ville d'arrivée :"<<endl;
          cin>>nomvillea;

          cout<<"Quel est la transport souhaité:"<<endl;
          cin>>transport;

          cout<<"Résumé :"<<endl;
          cout<<"Nom du trajet : "<<nomtrajet<<endl;
          cout<<"Nom de la Ville de départe : "<<nomvilled<<endl;
          cout<<"Nom de la ville d'arrivée : "<<nomvillea<<endl;
          cout<<"Nom du moyen de transport : "<<transport<<endl;
          cout<<"Entre y pour oui, n'importe quel autre touche pour revenir au menu d'avant"<<endl;
          char confirmer;
          cin>>confirmer;
          if (confirmer=='y'){
            c->Ajouter(new TrajetSimple(nomtrajet, nomvilled, nomvillea, transport));
          }
          break;
        }
        else if(typetrajet=='c'){
            cout<<"Quel est le nom du trajet composé?"<<endl;
            char nomtc[tailleMax];
            cin>>nomtc;
            cout<<"Combien de trajets simples pour ton trajet composé ? "<<endl;
            int nombreTS;
            cin>>nombreTS;
            bool possible =true;
            Trajet** lis_trajets_simples= new Trajet*[nombreTS];
            for(int i =0; i<nombreTS; i++){
              char nomtrajet[tailleMax], nomvilled[tailleMax], nomvillea[tailleMax], transport[tailleMax];
              cout<<"Quel est le nom du trajet :"<<endl;
              cin>>nomtrajet;
              cout<<"Quel est la ville de départe :"<<endl;
              cin>>nomvilled;
              cout<<"Quel est la ville d'arrivée :"<<endl;
              cin>>nomvillea;
              cout<<"Quel est la transport souhaité:"<<endl;
              cin>>transport;
              lis_trajets_simples[i] = new TrajetSimple(nomtrajet, nomvilled, nomvillea, transport);
              if (i>=1){
                const char* ville_a_anterieur=lis_trajets_simples[i-1]->Get('a');
                const char* ville_d_now =lis_trajets_simples[i]->Get('d');
                if (strcmp(ville_a_anterieur, ville_d_now)!=0){
                  possible=false;
                  break;
                }
              }
            }
            if (possible){
              TrajetCompose* tc = new TrajetCompose(nomtc, lis_trajets_simples[0]->Get('d'), lis_trajets_simples[nombreTS-1]->Get('a'), lis_trajets_simples, nombreTS);
              c->Ajouter(tc);
              }
            else{
              cout<<"Le trajet composé ne peut pas être fait, les villes ne coïncident pas"<<endl;
            }
            delete[] lis_trajets_simples;
            break;
        }else{
          break;
        }
      case '2':
        cout<<"T'as selectioné sur AFFICHER, à continuation les trajets disponibles :"<<endl;
        c->Afficher();
        break;
      case '3':
        cout<<"T'as selectioné sur RECHERCHER, proportionne les informations correspondantes :"<<endl;
        char nomvilled[tailleMax], nomvillea[tailleMax];
        cout<<"Quel est la ville de départe :"<<endl;
        cin>>nomvilled;
        cout<<"Quel est la ville d'arrivée :"<<endl;
        cin>>nomvillea;
        c->Rechercher(nomvilled, nomvillea);
        break;
      case '4': break;
      case '5':{
        cout<<"T'as selectioné sur SAUVEGARDER, quel est le nom du fichier souhaité :"<<endl;
        string name;
        cin>>name;
        c->Sauvegarder(name);
        break;}
      case '6':{
        cout<<"T'as selectioné sur SURECRIRE, quel est le nom du fichier souhaité :"<<endl;
        string name;
        cin>>name;
        c->SurEcrire(name);}
        break;
      default:
        cout<<"T'as selectioné une option qui n'est pas disponible sur le catalogue"<<endl;
        cout<<"Pour AJOUTER     entre 1, pour AFFICHER  entre 2"<<endl;
        cout<<"Pour RECHERCHER  entre 3, pour ARRETER   entre 4"<<endl;
        cout<<"Pour SAUVEGARDER entre 5, pour SURECRIRE entre 6"<<endl;
        cout<<"Essaie à nouveau"<<endl;
    }
    cout<<"Entre un valeur pour continuer"<<endl;
    cout<<"1 : pour AJOUTER un trajet"<<endl;
    cout<<"2 : pour AFFICHER les trajets disponibles"<<endl;
    cout<<"3 : pour RECHERCHER un trajet sohaité"<<endl;
    cout<<"4 : pour ARRETER le catalogue"<<endl;
    cout<<"5:  pour SAUVGARDER le catalogue"<<endl;
    cout<<"6:  pour SURECRIRE le catalogue"<<endl;
    cin>>option;
  }
  cout<<"T'as selectioné sur ARRETER, merci d'utiliser le catalogue"<<endl;
  cout<<"----------------------------------------------------------------------------------"<<endl;
  delete c;
  return 0;

}
