#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Liste.hpp"
#include "Jeu.hpp"

using namespace std;

class Concepteur
{
public:
	//TODO: Un constructeur par défaut et un constructeur paramétré.
	Concepteur() { nom_ = "Unknown"; anneeNaissance_ = 0; pays_ = "unknown"; };
	Concepteur(string nom, unsigned annee, string pays) 
	{ nom_ = nom; anneeNaissance_ = annee; pays_ = pays; }
	bool operator== (Concepteur concepteur) const { return concepteur.getNom() == nom_; };
	friend ostream& operator<<(ostream& out, const Concepteur& c);

	const std::string& getNom() const     { return nom_; }
	void setNom(const std::string& nom)   { nom_ = nom; }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(const std::string& pays) { pays_ = pays; }

private:
	std::string nom_;
	unsigned int anneeNaissance_;
	std::string pays_;
};
