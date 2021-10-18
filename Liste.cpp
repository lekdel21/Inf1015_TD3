#include "Liste.hpp"
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
#include "Jeu.hpp"

using namespace std;

template <typename T> Liste<T>::Liste<T>()
{
	capacite_ = 1;
	nElements_ = 0;
	elements_ = make_shared<T[]>(capacite_);
}

template <typename T> void Liste<T>::changerCapacite()
{
	capacite_ = max(capacite_*2, 1);
	auto newTabConcepteurs = make_shared<Concepteur[]>(capacite_);
	for (int i = 0; i < nElements_ )
	{	
		newTabConcepteurs[i] = elements_[i];
	}
	elements_ = newTabConcepteurs;
}

template <typename T> int Liste<T>::chercherElement(const T& element, const function<bool(string)>& critere)
{
	for (int i = 0; i < element.size())
	{
		if (critere(elments_[i]))
			return i;
	}
	return -1;
}