// ////////////////////////////////////////////
// Pour compiler : make
// Pour lancer : run monprog
// Pour arreter : Connecter inter au port A bit 0. 0=ARRET 1=RUN
// //////////////////////////////////////////// 


#include <iostream>
#include <unistd.h> //pour sleep 

#include "robot++.h"
#include "tapis.h"
#include "bras_robot.h"
#include "table.h"


using namespace std;

short fini(void) {return (GetPortA() & 1);}

int main (void)

{
  
  if (!init_comm()) // Condition permettant de lancer la suite du main seulement si l initialisation de l interface avec le materiel a ete effectuee (fonction init_comm)
    exit (0);
  sleep(1); // pause de 1 seconde 

  /* Declarations */

  tapis t1(1); // creation d un objet de la classe tapis : t1

  //tapis t2(2); // creation d un objet de la classe tapis : t2

  table T_index(0,false); // creation d un objet de la classe table : T_index + initialisation du compteur de piece sur la table a 0 et de la variable plein a "false"
                          // permet d indiquer que la table est vide a la creation

  bras_robot R(t1,T_index); // creation d un objet de la class bras_robot : R + initialisation des parametres du constructeur, indiquand que l objet R depend 
                            // des objets T_index et t1 

  
  /* Fin des declarations */

   cout << "Debut de l application" << endl;

  /* Initialisation de la position de la table */
   cout << "Initialisation position table"<<endl; 

   do {
	  StartTi(0);
	  StopTi(1);
      }while(I()==0);

   cout << "FIN d'initialisation position table"<<endl;
  /* Fin Initialisation de la position de la table */

   while ( !fini()) /* sortie quand PA0 = 1 */
    {
      /* 1. lecture des entrees */

      /* 2. Evolution du Reseau de Petri */

	    R.evolue(); // evolution du reseau de Petri du bras robot

	    t1.get_val_capteur(); // recuperation de la valeur du capteur pour le tapis 1

	    //t2.get_val_capteur(); 

	    t1.evolue();  // evolution du reseau de Petri du tapis 1 en fonction de la valeur recuperee

	    //t2.evolue();

	    cout<< "tapis 1:"<< t1 <<endl; // affichage de l evolution du tapis 1, pour verifier le derouler du reseau de Petri et confirmer qu il n y a pas d erreur
      
	    T_index.evolue(); // evolution de la table d indexage


      /* 3. Calcul des sorties et ecriture des sorties sur les ports */
      cout << "dans la boucle" << endl;
    }
  reset_comm(); // reset des positions et valeur des capteurs et actionneurs de la maquette
  return (1);

}
