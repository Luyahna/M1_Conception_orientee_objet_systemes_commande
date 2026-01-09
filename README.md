# M1_Conception_orientee_objet_systemes_commande
Projet : gestion d'un tampon dans une cellule d'atelier de production (C++, environnement Linux, maquette salle de TP )

# Présentation 
L’objectif de ce projet est de travailler dans un environnement Linux en C++, afin de prendre en main le langage de programmation C++, et les notions de classe et d’héritage qui sont nouvelles par rapport au langage de programmation C. Ceci tout en modélisant les commandes envisagées et la communication entre les différents éléments de la maquette, par des réseaux de Petri. Enfin, l’analyse et la conception orientée objet sera faite à partir de diagrammes UML, ce qui permettra d’avoir une vision globale des différentes classes à concevoir et des différentes fonctionnalités spécifiées par un cahier des charges. \
\
<img width="713" height="290" alt="maquette" src="https://github.com/user-attachments/assets/5fd49553-379e-4e4e-aa68-73ec01f55eff" /> \

La maquette étudiée est alors une cellule contenant un bras robotisé capable de se déplacer entre le capteur 'SCG' et 'SCD' présenté sur la figure ci-dessus, deux tapis capables d’acheminer des pièces et de se stopper, et enfin une table d’indexage capable de tourner sur elle-même.
Les différents capteurs et actionneurs des éléments de la maquette sont présentés par le tableau ci-dessous. Les valeurs de ces signaux sont relevées grâce à des fonctions proposées par la librairie de la maquette 'robot++.h'. \
\
<img width="765" height="282" alt="tabmaquette" src="https://github.com/user-attachments/assets/7441150a-0b4d-4d91-8999-071663087034" />
