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

Les documents et codes mis à disposition pour démarrer ce projet sont données dans le dossier 'projet_coo_vierge' et ce qui a été produit, dans le dossier 'projet_coo_code_complet'. \
Parmis les élements mis à disposition on dispose des codes 'robot++.cpp' et robot++.h permettant de déclarer et de définir toutes les fonctions liées à la maquette. De plus, les code 'structure++.cpp' et 'structure++.h' permettent de lire les valeurs des capteurs de la maquette. 

# Cahier des charges 

L’objectif de ce projet était d’implémenter sur la maquette le cahier des charges suivant : \
"Les pièces en provenance des tapis 1 et 2 doivent être déposées dans le tampon (table d’indexage). La capacité maximale du tampon est de 8 pièces. Les deux tapis sont constamment en marche et s’arrêtent lorsqu’une pièce arrive en bout (capteurs C1 ou C2). Le robot vient saisir la pièce du tapis et la dépose sur la table d’indexage. Une fois la pièce saisie, le tapis redémarre. Le dépôt de pièce sur le tampon se fait, table arrêtée, sur un secteur disponible. Après chaque pose, la table tourne pour présenter un nouveau secteur disponible au robot." (ref Cahier de TP). \ 
Afin de mettre en œuvre la commande souhaitée et définie par le cahier des charges ci-dessus : une première étape de modélisation par réseau de Petri sera effectuée afin de décrire au mieux les différentes fonctionnalités souhaitées. Puis, une étape d’analyse et de conception orientée objets du système, sera effectué à l’aide de la notation UML, ceci afin de concevoir les différentes classes nécessaires aux différentes fonctionnalités attendues, de manière propre et structuré, sans en oublier.

# Modélisation Commandes

## Commande Table
<img width="172" height="435" alt="RdPtable_github" src="https://github.com/user-attachments/assets/768ec7a5-248b-45f3-aa5c-ca9b8f3181e6" />

## Commande Tapis
<img width="224" height="442" alt="RdPtapis1_github" src="https://github.com/user-attachments/assets/f368f128-266b-462a-971a-e6a3ce7841c8" />

## Commande Bras Robot
<img width="280" height="687" alt="RdPbras_github" src="https://github.com/user-attachments/assets/075fcb5f-bd17-4470-85b2-3fed19227ee0" />

# Conception solution C++ (Diagramme UML )
Les diagrammes UML ont été réalisé avec le logiciel umbrello. 
## Diagramme d'objets 
<img width="361" height="556" alt="Dobj_gitHub" src="https://github.com/user-attachments/assets/a873c51e-7964-411f-b196-3a84e1eedaf5" />

## Diagramme de classes
<img width="1063" height="591" alt="Diagramme_classes" src="https://github.com/user-attachments/assets/e63be538-3f20-43ff-93c6-dd0fa3facb06" />




