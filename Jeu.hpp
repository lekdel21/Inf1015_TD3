#pragma once
#include "Concepteur.hpp"
#include "Liste.hpp"
#include <string>
#include <memory>
#include <functional>
#include <iostream>
#include <fstream>

using namespace std;

class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu();
	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir accéder à la liste de concepteurs.
	Liste<Concepteur>& getConcepteurs() { return concepteurs_; }

	void setConcepteurs(Liste<Concepteur>& concepteurs) { concepteurs_ = concepteurs;}

	friend ostream& operator<<(ostream& out, const Jeu& j);
	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	shared_ptr<Concepteur> chercherConcepteur(const function<bool(Concepteur)>& critere);

private:
	string titre_;
	unsigned anneeSortie_;
	string developpeur_;
	Liste<Concepteur> concepteurs_;
	//TODO: Attribut de la liste des concepteurs du jeu
};
