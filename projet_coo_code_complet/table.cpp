#include <iostream>
#include <unistd.h> //pour sleep 

#include "table.h"
#include "robot++.h"

using namespace std;
// Constructors/Destructors
//  

table::table (int compteur, bool pleine): systeme(4)
{
	table_pleine = pleine;
  	compteur_obj = compteur;
	place_[initTable]++; //initialisation du RdP de table : 1 jeton dans la place "initTable"
}

table::~table () { }

//  
// Methods
//  

void table::Tourne (void)
{
	cout << "compteur_obj :" << compteur_obj << endl; //verification du nombre de piece sur la table

	if (compteur_obj != 8) // si la table n est pas pleine elle peut tourner
	{
		StartTi(0);
		StopTi(1);	
	}
	else  // sinon la table est pleine, il faut la vider pour quelle tourne
	{
		table_pleine = true ;
		cout << "Veuillez vider la table" << endl;
	}
	
}

void table::Arret_table (void)
{
	StartTi(1);
	StopTi(0);
}

int table::evolue (void) // RdP de table
{
	int nb_tr=0; //initialisation du nombre de tirage a 0

	cout<< "valeur_capteur I : "<< I() << endl; // verification de la position de la table

	if (place_[initTable] && I() == 1) // position initiale de la table ; elle tourne
	{
		place_[initTable]--; place_[TableTourne1]++;
        Tourne();
		return(nb_tr++);
	}
	if (place_[TableTourne1] && I() == 0) // capteur I depasse , elle continue de tourner
	{
		place_[TableTourne1]--; place_[TableTourne2]++;
        Tourne();
		return(nb_tr++);
	}
	if (place_[TableTourne2] && I() == 1) // retour sur le capteur I, arret de la table 
	{
		place_[TableTourne2]--; place_[TableStop]++;
        Arret_table();
		compteur_obj++;
		return(nb_tr++);
	}
	return(nb_tr);
	
}





