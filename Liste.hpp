#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
#include "Jeu.hpp"

using namespace std;

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste()
	{
		capacite_ = 1;
		nElements_ = 0;
		elements_ = make_shared<T[]>(1);
	}
	Liste(const Liste<T>& liste)
	{
		nElements_ = liste.size();
		capacite_ = liste.getCapacite();
		elements_ = liste.getElements();
	}
	shared_ptr<T> operator[](unsigned int index) const { return elements_[index]; }
	friend ostream& operator<<(ostream& out, const Liste<T>& l);
	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(shared_ptr<T> element) { elements_[nElements_] = element; nElements_++; }
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const				{ return nElements_; }
	unsigned getCapacite() const		{ return capacite_; }
	shared_ptr<T[]> getElements() const { return elements_; }
	//TODO: Méthode pour changer la capacité de la liste
	void changerCapacite();
	//TODO: Méthode pour trouver une élément selon un critère (lambda).
	shared_ptr<T> chercherElement(const Liste<T>& liste, const function<bool(T)>& critere)
	{
		shared_ptr<T> ptr = nullptr;
		for (int i : iter::range(liste.size()))
		{
			if (critere(liste.getElements()[i]))
			{
				ptr = liste.getElements()[i];
			}
		}
		return ptr;
	}

private:
	unsigned nElements_;
	unsigned capacite_;
	shared_ptr<T[]> elements_;
	//TODO: Attribut contenant les éléments de la liste.
};
