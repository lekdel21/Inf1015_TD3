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
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste<T>();
	shared_ptr<T> operator[](unsigned int index) {return elements_[index]};
	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(shared_ptr<T> element) { elements_[nElements_] = element; }
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }
	shared_ptr<T[]> getElements() const { return elements_; }
	//TODO: Méthode pour changer la capacité de la liste
	void changerCapacite();
	//TODO: Méthode pour trouver une élément selon un critère (lambda).
	int chercherElement(const T& element, const function<bool(string)>& critere);
	
private:
	unsigned nElements_;
	unsigned capacite_;
	shared_ptr<T[]> elements_;
	//TODO: Attribut contenant les éléments de la liste.
};
