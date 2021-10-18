#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
#include "Jeu.hpp"

using namespace std;

template <typename T> class Liste
{
public:
	//TODO: Constructeurs et surcharges d'op�rateurs
	Liste<T>();
	shared_ptr<T> operator[](unsigned int index) {return elements_[index]};
	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(shared_ptr<T> element) { elements_[nElements_] = element; }
	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }
	shared_ptr<T[]> getElements() const { return elements_; }
	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite();
	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	int chercherElement(const T& element, const function<bool(string)>& critere);
	
private:
	unsigned nElements_;
	unsigned capacite_;
	shared_ptr<T[]> elements_;
	//TODO: Attribut contenant les �l�ments de la liste.
};
