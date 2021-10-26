#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

//TODO: Vos surcharges d'opérateur <<
ostream& operator<<(ostream& out, const Concepteur& c)
{
	return out << c.getNom() << "\t" << c.getAnneeNaissance() << "\t" << c.getPays() << endl;
}
ostream& operator<<(ostream& out, Jeu& j)
{
	out << j.getTitre() << "\t" << j.getAnneeSortie() << "\t" << j.getDeveloppeur() << endl;
	for (unsigned i = 0; i < j.getConcepteurs().size(); i++)
	{
		out << j.getConcepteurs()[i] << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const Liste<Jeu>& l)
{
	for (unsigned i = 0; i < l.size(); i++)
		out << l.getElements()[i] << endl;
	return out;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//cout << ligneSeparation << lj;
	//ofstream("sortie.txt") << lj;

	//TODO: Compléter le main avec les tests demandés.
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}