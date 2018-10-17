/*! \file main.cpp
 * \brief programme qui propose d'ajouter / supprimer / afficher des valeurs dans un tableau via menu
 * \author Aurelien_Guillemot
 * \version 1.0
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main (void)
{

/*! \brief On créer une variable cpt pour faire tourner une boucle. Cette valeur sera initialisé à 0. La boucle tournera tant que cpt = 0. L'option quitter incrementera cpt.
 * \param cpt = 0 : (compteur), une fois incremente, on quitte le menu.
 * \param aux : (auxiliaire), est utiliser pour stocker les valeurs de l'utilisateur. Une fois que celui ci a choisi dans le menu ce qu'il voulait faire, aux est utilisé pour stocker le reel a ajouter / supprimer 1 fois / Supprimer partout. Chaque nouvelle valeur ecrase la precedente
 * \param ree : Definie comme un vecteur de type float. les valeurs seront stocké dedans.
 * \param i: i permet de definir la taille du tableau. A chaque ajout de valeur il incremente et a chaque suppression, il decremente
*/
	int cpt;
	float aux;
	vector <float> reel;
	int i;

	cpt = 0;
	i = 0;
	while (cpt == 0)
	{
		int menu;
		cout << "Que voulez vous faire ? (1) Ajouter un reel ? (2) Afficher la liste des reels ? (3) Supprimer le premier reel ayant une valeur donnee ? (4) Supprimer tous les réels ayant une valeur donnee ? (5) Quitter" << endl;
		cin >> menu;

/*! \brief ici debute le case qui va nous permettre de creer notre menu. case 1 : Ajouter reel / case 2 : afficher tous les reels / case 3 : Supprimer un reel 1 fois / case 4 : supprime le reel partout / case 5 : quitter le menu
/* \param menu : variable utilise par l'utilisateur pour naviguer dans le menu (switch)
/* \param j : sera appele a la creation de chaque boucle et detrtuit a la fin de celle ci. Il sert a afficher le nombre exact de reel dans le tableau
*/
		switch (menu)
		{
		case 1 :
		{
		cout << "Ajouter un reel : Quel reel voulez-vous ajouter ? " << endl;
		cin >> aux;
		reel.push_back (aux);
		i++;
		break;
		}

		case 2 :
		{
		cout << "Afficher la liste des reels" << endl;
		for (int j=0; j<i; j++)
		{
			cout << reel [j] << endl;
		}
		break;
		}

		case 3 :
		{
		cout << "Supprimer le premier reel ayant une valeur donnee : Quel reel supprimer ?" << endl;
		cin >> aux;
		for (int j=0; j<i; j++)
		{
			if (aux==reel[j])
			{
				reel.erase(reel.begin() + j);
				//i--;
				break;
			}
		}
		break;
		}

		case 4 :
		{
		cout << "Supprimer tous les reels ayant une valeur donnee : Quel reel souhaitez-vous supprimer ?" << endl;
		cin >> aux;
		for (int j=0; j<=i; j++)
		{
			if (reel[j] == aux)
			{
				reel.erase(reel.begin() + j);
				//i--;
			}
		}
		break;
		}
/* \brief Quand l'utilisateur decide de quitter le menu, on ecrit les valeurs reel dans un fichier txt du nom de reel.txt
*/
		case 5 :
		{
		ofstream fichier_reel;
		fichier_reel.open("reel.txt");
			for (int j=0; j<i; j++)
			{
				fichier_reel << reel[j] << endl;
			}
			fichier_reel.close();
		cpt ++;
		break;
		}

		default :{ cout << "erreur" << endl;
		break;}
}
	}
	// cout << reel.size() << endl;
	return 0;
}
