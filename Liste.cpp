/*#include "Liste.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
#include "Jeu.hpp"

using namespace std;

template <typename T> 
Liste<T>::Liste()
{
	capacite_ = 1;
	nElements_ = 0;
	elements_ = make_shared<T[]>(capacite_);
}

template <typename T> 
void Liste<T>::changerCapacite()
{
	if (capacite_ == 0)
		capacite_ += 1;
	else
		capacite_ *= 2;
	auto newTabConcepteurs = make_shared<Concepteur[]>(capacite_);
	for (int i = 0; i < nElements_; i++)
	{	
		newTabConcepteurs[i] = elements_[i];
	}
	delete elements_;
	elements_ = newTabConcepteurs;
}

template <typename T> 
shared_ptr<T> Liste<T>::chercherElement(const Liste<T>& liste, const function<bool(T)>& critere)
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

template<typename T>
Liste<T>::Liste(const Liste<T>& liste)
{
	nElements_ = liste.size();
	capacite_ = liste.getCapacite();
	elements_ = liste.getElements();
}*/