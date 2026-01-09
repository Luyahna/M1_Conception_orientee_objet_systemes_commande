
#ifndef TAPIS_H
#define TAPIS_H
#include "systeme.h"


/**
  * class tapis
  *
  */


class bras_robot; //declaration de la class bras robot pour la communication bras -> tapis

class tapis : public systeme // la classe tapis herite de la classe systeme
{
public:
	enum nom_place {init,a,m1,m2}; // declaration des noms des places du reseau de Petri de tapis

	// Constructors/Destructors
	tapis(int id);
	virtual ~tapis();

	//methodes
	void get_val_capteur();
	void marche (void);
	void arret (void);

	// Les methodes associees aux points de communication
	void appeltapis(void) {place_[init]++;}; //retour au marquage initial du RdP de tapis
	int  evolue(void); //regle d evolution du RdP de tapis

private :
	//attributes
	int id_tapis;
	short valeur_capteur;

public :

};

#endif // TAPIS_H
