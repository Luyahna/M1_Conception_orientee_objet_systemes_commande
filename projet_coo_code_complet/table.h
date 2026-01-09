
#ifndef TABLE_H
#define TABLE_H
#include "systeme.h"

/**
  * class table
  *
  */

class bras_robot; //declaration de la class bras robot pour la communication bras -> table

class table : public systeme // la classe table herite de la classe systeme
{
public:
	enum nom_place{initTable, TableTourne1, TableTourne2,TableStop}; // declaration des noms des places du reseau de Petri de table

	// Constructors/Destructors
	//

	//Constructor
	table (int compteur=0, bool pleine=false); // initialisation des attributs de table dans le constructeur, permettant a la construction de dire que la table est vide
	//Empty Destructor
	virtual ~table ();

	// Les methodes
	void Tourne(void);
	void Arret_table(void);

	//Communication
	void appeltable(void) {place_[initTable]++;}; //permet de reinitialiser le RdP de table
	int evolue(void); //regle d evolution du RdP de table


private:

  // Private attributes
  bool table_pleine;
  int compteur_obj;


public:

};

#endif // TABLE_H
