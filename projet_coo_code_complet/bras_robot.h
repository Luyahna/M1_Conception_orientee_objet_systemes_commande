
#ifndef BRAS_ROBOT_H
#define BRAS_ROBOT_H
#include "systeme.h"
#include "tapis.h" // permet d utiliser les methodes de la classe tapis (mise en place de la communication bras -> tapis)
#include "table.h" // permet d utiliser les methodes de la classe table (mise en place de la communication bras -> table)

/**
  * class bras_robot
  * 
  */
class bras_robot : public systeme // la classe bras_robot herite de la classe systeme
{
public:
	enum nom_place{surTi, versGauche, Priseobj1, versDroite, Poseobj1}; // declaration des noms des places du reseau de Petri de bras_robot


	//Empty Constructor
	bras_robot(tapis &, table &); // depend d objet tapis et table pour etre construit et pour fonctionner
	//Empty Destructor
	virtual ~bras_robot();

	// Les methodes associees aux points de communication
	//void prendre_obj(void);
	//void pose_obj(void);
	int  evolue(void); // regle d evolution du RdP de bras_robot

	tapis &t1_; // Le tapis avec lequel on se synchronise
	table &ti_; // La table avec laquelle on se synchronise

	
private : 
	
public :


};

#endif // BRAS_ROBOT_H
