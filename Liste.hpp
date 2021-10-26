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
	//TODO: Constructeurs et surcharges d'op�rateurs
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
	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(shared_ptr<T> element) { elements_[nElements_] = element; nElements_++; }
	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const				{ return nElements_; }
	unsigned getCapacite() const		{ return capacite_; }
	shared_ptr<T[]> getElements() const { return elements_; }
	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite();
	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
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
	//TODO: Attribut contenant les �l�ments de la liste.
};
