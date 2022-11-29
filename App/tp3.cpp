/** 
 * Programme principal pour utiliser la classe Digraph.
 * TP3 -- Dictionnaires et ensemble d'apprentissage
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */
#include "digraph.hpp"
#include <iostream>

/**
 * La fonction main est le point d'entrée. En principe, vous n'avez pas à la modifier.
 *
 * Utilisation : 
 *	g++ tp3.cpp -o tp3
 * 	./tp3 < dico
 * Sortie attendue :
 *	Dictionnaire original : 6036 mots et 28623 liens.
 *	Nombre de mots essentiels : 78
 * Temps d'exécution : moins de 40 secondes.
 */

int main() {
	Digraph<std::string> graphe;
	while(std::cin) {
		std::string dep, arr;
		std::cin >> dep >> arr;
		if(!dep.empty() && !arr.empty()) {
			graphe.inserer_sommet(dep);
			graphe.inserer_sommet(arr);
			graphe.inserer_arc(dep, arr);
		}
	}
	int mots = graphe.nb_sommets(), arcs = graphe.nb_arcs();
	while(graphe.reduction_base() ||
		graphe.reduction_intermediaire() ||
		graphe.reduction_avancee()) {}
	std::cout << "Dictionnaire original : " << mots << " mots et " << arcs << " liens." << std::endl;
	std::cout << "Nombre de mots essentiels : " << graphe.nb_sommets() << std::endl;
	// Pour afficher le dirctionnaire essentiel
	//std::cout << graphe.graphviz() << std::endl;
	return 0;
}
