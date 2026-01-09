#include <iostream>
#include <unistd.h> //pour sleep 

#include "bras_robot.h"
#include "robot++.h"

using namespace std;

// Constructors/Destructors
//  

bras_robot::bras_robot (tapis &t1, table &ti): systeme(5), t1_(t1), ti_(ti) 
{
	place_[surTi]++; //initialisation du RdP de bras_robot : 1 jeton dans la place "surTi"
}

bras_robot::~bras_robot () 
{
	
}

//  
// Methods
//  
/*void prendre_obj(void)
{
	
	
}
void pose_obj(void)
{
	
}*/
int bras_robot ::evolue(void) //RdP 
{
	int nb_tr=0; //initialisation du nombre de tirage a 0
	//nom_place {surTi, versGauche, Priseobj1, versDroite, Poseobj1};

	if (place_[surTi] && C1()== 0) //le bras est au-dessus de la table ; un objet passe devant le capteur du tapis 1 
	{
		place_[surTi]--; place_[versGauche]++;
        Gauche(1);
		Droite(0);
		Prise(0);
		Pose(0);
		return(nb_tr++);
	}
	if (place_[versGauche] && T1() == 1) // le bras a tourne a gauche et est maintenant au-dessus du tapis 1 
	{
		place_[versGauche]--; place_[Priseobj1]++;
         	Prise(1);
		Pose(0);
		Gauche(0);
		Droite(0);
		return(nb_tr++);
	}
	if (place_[Priseobj1] && FinPrise() == 1) // le bras a pris l objet du tapis 1
	{
		place_[Priseobj1]--; place_[versDroite]++;
         	Droite(1);
		Gauche(0);
		Prise(0);
		Pose(0);
		return(nb_tr++);
	}
	if (place_[versDroite] && TI() == 1) // le bras a tourne a droite et est maintenant sur la table 
	{
		place_[versDroite]--; place_[Poseobj1]++;
         	Pose(1);
		Prise(0);
		Gauche(0);
		Droite(0);
		return(nb_tr++);
	}
	if (place_[Poseobj1] && FinPose() == 1) // le bras a pose l objet sur la table ; reinitialisation des RdP des classes tapis et table
	{
		place_[Poseobj1]--; place_[surTi]++;
		Pose(0);
		Prise(0);
		Gauche(0);
		Droite(0);
		t1_.appeltapis();
		ti_.appeltable();
		return(nb_tr++);
	}

	return(nb_tr);
	
}




