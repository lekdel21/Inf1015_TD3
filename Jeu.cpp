#include "Jeu.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>
#include <iostream>
#include "cppitertools/range.hpp"

using namespace std;

Jeu::Jeu()
{
	titre_ = "Unknown";
	anneeSortie_ = 0;
	developpeur_ = "Unknown";
	concepteurs_ = Liste <Concepteur>(); 
}

shared_ptr<Concepteur> Jeu::chercherConcepteur(const function<bool(Concepteur)>& critere)
{
	shared_ptr<Concepteur> ptrConcepteur = nullptr;
	for (int i : iter::range(concepteurs_.size()))
		if (critere(concepteurs_.getElements()[i]))
		{
			ptrConcepteur = make_shared<Concepteur>();
			*ptrConcepteur = concepteurs_.getElements()[i];
		}

	return ptrConcepteur;
}
