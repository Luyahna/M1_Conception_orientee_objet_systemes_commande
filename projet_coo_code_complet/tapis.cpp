#include <iostream>
#include <unistd.h> //pour sleep 

#include "tapis.h"
#include "robot++.h"

using namespace std;

// Constructors/Destructors
//  

tapis::tapis (int id): systeme(4) 
{ 
	id_tapis=id; // permet de savoir quel fonction de robot++.h utiliser
	place_[init]++; // initialisation du reseau de Petri : M0 : marquage initial
}

tapis::~tapis () // destructeur vide
{ 
	
}

//  
// Methods
//  

void tapis::marche (void)
{
	if(id_tapis==1)
	{
		Start1(0);
		Stop1(1);

	}else if (id_tapis==2)
	{
		Start2(0);
		Stop2(1);		
	}
}

void tapis::arret (void)
{
	if(id_tapis==1)
	{
		Start1(1);
		Stop1(0);

	}else if (id_tapis==2)
	{
		Start2(1);
		Stop2(0);
	}	
}

void tapis::get_val_capteur()
{
	if(id_tapis == 1)
	{
		valeur_capteur = C1();
	}else if (id_tapis == 2)
	{
		valeur_capteur = C2();	
	}
}

int tapis::evolue (void)
{
	int nb_tr=0; //initialisation du nombre de tirage a 0

	cout<< "valeur_capteur : "<< valeur_capteur << endl; // permet de verifier dans la console que l on a recupere la valeur du bon capteur

	if (place_[init] && valeur_capteur == 1) // aucun objet devant le capeteur ; tapis en marche
	{
		place_[init]--; place_[m1]++;
        	marche();
		return(nb_tr++);
	}
	if (place_[m1] && valeur_capteur == 0) // un objet passe devant le capteur ; tapis en marche
	{
		place_[m1]--; place_[m2]++;
         	marche();
		return(nb_tr++);
	}
	if (place_[m2] && valeur_capteur == 1) // un objet a franchi le capteur ; tapis s arrete
	{
		place_[m2]--; place_[a]++;
         	arret();
		return(nb_tr++);
	}
	return(nb_tr);
}



