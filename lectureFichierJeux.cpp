// Fonctions pour lire le fichier binaire.
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "lectureFichierJeux.hpp"
#include <fstream>
#include "gsl/span"
#include "cppitertools/range.hpp"

using namespace std;

#pragma region "Fonctions de lecture de base"
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion

shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, Concepteur concepteur)
{
	//TODO: Compl�ter la fonction (�quivalent de trouverDesigner du TD2).
	shared_ptr<Concepteur> ptrConcepteur = nullptr;
	for (int i : iter::range(listeJeux.size()))
	{
		ptrConcepteur = listeJeux.getElements()[i].chercherConcepteur([&](Concepteur c) {return c == concepteur; }); //Surcharger == pour les concepteurs.
	}
	return ptrConcepteur;
}

shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	Concepteur concepteur(lireString(f), lireUint16(f), lireString(f));
	//concepteur.setNom(lireString(f));
	//concepteur.setAnneeNaissance(lireUint16(f));
	//concepteur.setPays(lireString(f));

	//TODO: Compl�ter la fonction (�quivalent de lireDesigner du TD2).
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, concepteur);
	if (concepteurExistant != nullptr)
	{
		return concepteurExistant;
	}
	cout << "C: " << concepteur.getNom() << endl;  //TODO: Enlever cet affichage temporaire servant � voir que le code fourni lit bien les jeux.
	return make_shared<Concepteur>(concepteur);
}

shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	Jeu jeu = {};
	jeu.setTitre(lireString(f));
	jeu.setAnneeSortie(lireUint8(f));
	jeu.setDeveloppeur(lireString(f));
	unsigned nConcepteurs = lireUint8(f);
	//TODO: Compl�ter la fonction (�quivalent de lireJeu du TD2).
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(jeu);

	Liste<Concepteur> concepteurs = Liste<Concepteur>();
	
	for (unsigned int i = 0; i < nConcepteurs; i++)
	{
		if (concepteurs.size() == concepteurs.getCapacite())
		{
			concepteurs.changerCapacite();
		}
		concepteurs.ajouterElement(lireConcepteur(lj, f)); // Pas bon si le concepteur existe deja, a changer
	}
	ptrJeu->setConcepteurs(concepteurs);
	cout << "J: " << jeu.getTitre() << endl;  //TODO: Enlever cet affichage temporaire servant � voir que le code fourni lit bien les jeux.
	return ptrJeu;
}

Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//TODO: Compl�ter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		listeJeux.ajouterElement(lireJeu(f, listeJeux));

	return listeJeux;
}
