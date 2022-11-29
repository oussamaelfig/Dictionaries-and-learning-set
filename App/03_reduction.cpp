/* 
 * Tests pour la classe Digraph.
 * TP3 -- Dictionnaires et ensemble d'apprentissage
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */
 
#include "digraph.hpp"
#include <iostream>

int main() {
	Digraph<int> graphe;
	int erreur = 0;
	for(int i = 0; i < 14; i++)
		graphe.inserer_sommet(i);
	graphe.inserer_arc(0, 5);
	std::set<int> s_1({0, 2, 6, 7});
	for(auto const & i : s_1)
		graphe.inserer_arc(1, i);
	std::set<int> s_3({2, 4, 8, 9});
	for(auto const & i : s_3)
		graphe.inserer_arc(3, i);
	graphe.inserer_arc(4, 10);
	graphe.inserer_arc(4, 13);
	graphe.inserer_arc(5, 1);
	graphe.inserer_arc(6, 11);
	graphe.inserer_arc(7, 3);
	graphe.inserer_arc(8, 13);
	graphe.inserer_arc(9, 13);
	graphe.inserer_arc(10, 4);
	std::set<int> s_11({5, 7, 11, 12});
	for(auto const & i : s_11)
		graphe.inserer_arc(11, i);
	graphe.inserer_arc(12, 7);
	graphe.inserer_arc(12, 13);
	graphe.reduction_avancee();
	if(graphe.nb_sommets() != 14) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(graphe.nb_arcs() != 9) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(!graphe.arc(0, 5) ||
			!graphe.arc(1, 0) ||
			!graphe.arc(1, 6) ||
			!graphe.arc(4, 10) ||
			!graphe.arc(5, 1) || 
			!graphe.arc(6, 11) ||
			!graphe.arc(10, 4) ||
			!graphe.arc(11, 5) ||
			!graphe.arc(11, 11)) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}	
	graphe.supprimer_arc(11, 11);
	graphe.reduction_avancee();
	if(graphe.nb_sommets() != 14) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(graphe.nb_arcs() != 8) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(!graphe.arc(0, 5) ||
			!graphe.arc(1, 0) ||
			!graphe.arc(1, 6) ||
			!graphe.arc(4, 10) ||
			!graphe.arc(5, 1) || 
			!graphe.arc(6, 11) ||
			!graphe.arc(10, 4) ||
			!graphe.arc(11, 5)) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	graphe.supprimer_arc(5, 1);
	graphe.reduction_avancee();
	if(graphe.nb_sommets() != 14) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(graphe.nb_arcs() != 2) {
		std::cerr << "ECHEC - VIII" << std::endl;
		erreur++;
	}
	if(!graphe.arc(4, 10) || !graphe.arc(10, 4)) {
		std::cerr << "ECHEC - IX" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK"<< std::endl;
	return erreur;
}
