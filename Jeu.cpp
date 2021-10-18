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
	concepteurs_ = make_shared<Liste<Concepteur>>();
}

