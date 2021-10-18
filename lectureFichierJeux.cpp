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

shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
	int i = 0;
	//TODO: Compléter la fonction (équivalent de trouverDesigner du TD2).
	int pos = listeJeux.chercherElement(listeJeux.getElements()[i], [nom](string nomCompare) {return nom = nomCompare; });
	/*for (int i : iter::range(listeJeux.size()))
	{
		for (int j : iter::range(listeJeux[i]))
		{ }
	}
	return {};*/
}

shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	Concepteur concepteur;
	concepteur.setNom(lireString(f));
	concepteur.setAnneeNaissance(lireUint16(f));
	concepteur.setPays(lireString(f));

	//TODO: Compléter la fonction (équivalent de lireDesigner du TD2).
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, concepteur.getNom());
	if (concepteurExistant != nullptr)
	{
		return concepteurExistant;
	}
	cout << "C: " << concepteur.getNom() << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return make_shared<Concepteur>(concepteur);
}

shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	Jeu jeu = {};
	jeu.setTitre(lireString(f));
	jeu.setAnneeSortie(lireUint8(f));
	jeu.setDeveloppeur(lireString(f));
	unsigned nConcepteurs = lireUint8(f);
	//TODO: Compléter la fonction (équivalent de lireJeu du TD2).
	shared_ptr<Jeu> ptrJeu = make_shared<Jeu>(jeu);

	Liste<Concepteur> concepteurs;
	*ptrJeu->getConcepteurs() = concepteurs;
	
	for (unsigned int i = 0; i < nConcepteurs; i++)
	{
		if (ptrJeu->getConcepteurs()->size() == ptrJeu->getConcepteurs()->getCapacite())
		{
			ptrJeu->getConcepteurs()->changerCapacite();
		}
		ptrJeu->getConcepteurs()->getElements()[i] = *lireConcepteur(lj, f); // Je ne crois pas que c'est bon, a voir...
	}

	cout << "J: " << jeu.getTitre() << endl;  //TODO: Enlever cet affichage temporaire servant à voir que le code fourni lit bien les jeux.
	return ptrJeu;
}

Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//TODO: Compléter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements))
		lireJeu(f, listeJeux);

	return listeJeux;
}
