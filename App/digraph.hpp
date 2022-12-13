/*
 * Squelette minimal pour la classe générique Digraph<T> du TP3.
 * TP3 -- Dictionnaires et ensemble d'apprentissage
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#ifndef __DIGRAPH_HPP__
#define __DIGRAPH_HPP__

#include <set>
#include <map>
#include <string>
#include <assert.h>

/***** Décommenter les include que vous voulez utiliser ******/
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
// #include <multiset>
// #include <multimap>
// #include <unordered_set>
// #include <unordered_map>
// #include <unordered_multiset>
// #include <unordered_multimap>
#include <stack>
#include <queue>
// #include <priority_queue>

/*** Surcharge de la focntion to_string pour fonctionner avec std::string ***/
std::string to_string(const std::string &value)
{
	return value;
}
template <typename T>
std::string valeur(T u)
{
	using namespace std;
	return to_string(u);
}
/****************************************************************************/

template <class T>
class Digraph
{
	/*** Interface publique ***/
	/**** Vous n'avez pas le droit de modifier l'interface publique de cette classe ******/
	/**** Vous n'avez donc pas le droit d'ajouter des fonctions publiques ni de **********/
	/**** modifier les signatures des fonctions publiques ********************************/
public:
	Digraph();
	~Digraph();

	/*** Modificateurs ***/
	/*
	 * Permet d'insérer un nouveau sommet avec une liste
	 * de sommets successeurs vide.
	 * Si le sommet est déjà dans le graphe, cette fonction
	 * ne fait rien (elle n'écrase pas la valeur associé à la clé).
	 */
	void inserer_sommet(T u);
	void inserer_arc(T u, T v);
	/*
	 * Supprime un sommet et tous les arcs adjacents à ce sommet.
	 */
	void supprimer_sommet(T u);
	void supprimer_arc(T u, T v);

	/*** Fonctions pour les caractéristiques de graphe ***/
	/*
	 * Les deux fonctions suivantes retournent respectivement
	 * le nombre de sommets et le nombre d'arcs du graphe.
	 */
	int nb_sommets() const;
	int nb_arcs() const;
	/*
	 * Retourne un ensemble avec tous les sommets p, tel qu'il
	 * existe un arc (p,u)
	 */
	const std::set<T> predecesseurs(T u) const;
	/*
	 * Retourne un ensemble avec tous les sommets s, tel qu'il
	 * existe un arc (u,s) (ensemble des succésseurs de u).
	 */
	const std::set<T> successeurs(T u) const;
	int degre_entrant(T u) const;
	int degre_sortant(T u) const;
	/*
	 * Retourne "true" si (u,v) est arc du graphe, "false" si non.
	 */
	bool arc(T u, T v) const;

	/*** Prédicats ***/
	/*
	 * Retourne "true" si l'arc (u,u) existe dans le graphe, "false"
	 * si non.
	 */
	bool boucle(T u) const;
	/*
	 * Retourne "true" si le degré sortant de u est 0, "false" si non.
	 */
	bool puits(T u) const;
	/*
	 * Retourne "true" si,
	 *	- le degré sortant de u vaut 1 et le degré entrant de u > 0
	 * ou
	 *	- le degré entrant de u vaut 1 et le degré sortant de u > 0
	 * "false" si non.
	 */
	bool contourner(T u) const;
	/*
	 * Retourne "true" si aucun circuit ne passe par l'arc (u,v),
	 * "false" si non.
	 */
	bool acyclique(T u, T v) const;

	/*** Réductions de graphes ***/
	/*
	 * Applique autant de fois que possible les réductions de base
	 * (voir l'énoncé et les fonctions boucle(T u) et puits(T u)).
	 * Elle retourne "true" si au moins une réduction de base a été
	 * appliquée, "false" si non.
	 */
	bool reduction_base();
	/*
	 * Applique autant de fois que possible la réduction intermédiaire
	 * (voir l'énoncé et la fonction contourner(T u)). Elle retourne
	 * "true" si au moins une réduction intermédiaire a été appliquée,
	 * "false" si non.
	 */
	bool reduction_intermediaire();
	/*
	 * Applique autant de fois que possible la réduction avancée
	 * (voir l'énoncé et la fonction acyclique(T u, T v). Elle retourne
	 * "true" si au moins une réduction avancée a été appliquée, "false"
	 * si non.
	 */
	bool reduction_avancee();

	/*** Pour dessiner un graphe avec la commande dot ***/
	std::string graphviz() const;

	/*** Représentation ***/
	/**** Vous n'avez pas le droit de modifier cette représentation ******/
	/**** Donc vous ne pouvez pas ajouter de nouveau attribut/variable ***/
private:
	/*
	 * On représente un graphe avec une liste d'adjacence.
	 * Chaque sommet u est associé à un ensemble de sommets s tel que
	 * l'arc (u,s) existe (tous les succésseurs de u). Voir l'énoncé
	 * pour des exemples.
	 */
	std::map<T, std::set<T>> graphe;

	bool chemin_existe(T u, T v) const;
};

/******* Implémentation *******/

template <class T>
Digraph<T>::Digraph() : graphe()
{
}

template <class T>
Digraph<T>::~Digraph()
{
}

/*** Modificateurs ***/
template <class T>
void Digraph<T>::inserer_sommet(T u)
{
	graphe[u];
}

template <class T>
void Digraph<T>::inserer_arc(T u, T v)
{
	(graphe[u]).insert(v);
}

template <class T>
void Digraph<T>::supprimer_sommet(T u)
{
	graphe.erase(u);
	for (auto &pair : graphe)
	{
		auto i = pair.second.begin();
		while (i != pair.second.end())
		{
			if (*i == u)
				i = pair.second.erase(i);
			else
				++i;
		}
	}
}

template <class T>
void Digraph<T>::supprimer_arc(T u, T v)
{
	std::set<T> &s = graphe[u];
	s.erase(v);
}

/*** Fonctions pour les caractéristiques de graphe ***/
template <class T>
int Digraph<T>::nb_sommets() const
{
	return graphe.size();
}

template <class T>
int Digraph<T>::nb_arcs() const
{
	int count = 0;

	for (const auto v : graphe)
	{
		count += v.second.size();
	}
	return count;
}

template <class T>
const std::set<T> Digraph<T>::predecesseurs(T u) const
{
	std::set<T> p;

	for (auto const &[v, set] : graphe)
		for (auto const &w : set)
			if (u == w)
			{
				p.insert(v);
				break;
			}

	return p;
}

template <class T>
const std::set<T> Digraph<T>::successeurs(T u) const
{
	return graphe.at(u);
}

template <class T>
int Digraph<T>::degre_entrant(T u) const
{
	int count = 0;
	for (auto it = graphe.begin(); it != graphe.end(); ++it)
	{
		for (auto setItem : it->second)
		{
			if (setItem == u)
			{
				count++;
			}
		}
	}

	return count;
}

template <class T>
int Digraph<T>::degre_sortant(T u) const
{
	return graphe.at(u).size();
}

template <class T>
bool Digraph<T>::arc(T u, T v) const
{
	if (graphe.at(u).count(v))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*** Prédicats ***/
template <class T>
bool Digraph<T>::boucle(T u) const
{
	const auto it = graphe.find(u);
	if (it == graphe.end())
	{
		return false; // there is no such vertex in the graph at all
	}
	return it->second.find(u) != it->second.end();
}

template <class T>
bool Digraph<T>::puits(T u) const
{
	if (graphe.at(u).size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Digraph<T>::contourner(T u) const
{
	return (degre_sortant(u) == 1 && degre_entrant(u) > 0) || (degre_entrant(u) == 1 && degre_sortant(u) > 0);
}

template <class T>
bool Digraph<T>::acyclique(T u, T v) const
{
	if(chemin_existe(u,v) && chemin_existe(v,u)){
		return false;
	}

	return true;
}

/*** Réductions de graphes ***/
template <class T>
bool Digraph<T>::reduction_base()
{
	   std::list<T> listesommet;
    bool estSuprrimer= false;

    for (const auto &p: graphe) {
        if (puits(p.first) || boucle(p.first)) {
            listesommet.push_back(p.first);
            estSuprrimer= true;
        }


    }
    for (T sommet:listesommet) {
        supprimer_sommet(sommet);
    }
    if (estSuprrimer){
        reduction_base();
    }

    return estSuprrimer;
}

template <class T>
bool Digraph<T>::reduction_intermediaire()
{
	// À compléter
	return false;
}

template <class T>
bool Digraph<T>::reduction_avancee()
{
	// À compléter
	return false;
}

/*** Fonctions privées ***/
template <class T>
bool Digraph<T>::chemin_existe(T u, T v) const
{
	// Base case
	if (u == v)
		return true;

	// Mark all the vertices as not visited
	bool *visited = new bool[nb_sommets()];
	for (int i = 0; i < nb_sommets(); i++)
		visited[i] = false;

	// Create a queue for BFS
	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[u] = true;
	queue.push_back(u);

	// it will be used to get all adjacent vertices of a vertex
	std::set<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		u = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex u
		// If a adjacent has not been visited, then mark it visited
		// and enqueue it
		for (i = graphe.at(u).begin(); i != graphe.at(u).end(); ++i)
		{
			// If this adjacent node is the destination node, then
			// return true
			if (*i == v)
				return true;

			// Else, continue to do BFS
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

	// If BFS is complete without visiting v
	return false;
}

/*** Pour dessiner un graphe avec la commande dot ***/
#include <iostream>

template <class T>
std::string Digraph<T>::graphviz() const
{
	std::string header = "digraph {\n";
	std::string body_v = "";
	std::string body_a = "";
	for (auto iter = graphe.begin(); iter != graphe.end(); ++iter)
	{
		body_v += "  " + valeur(iter->first) + ";\n";
		for (auto reti = iter->second.begin(); reti != iter->second.end(); ++reti)
			body_a += "  " + valeur(iter->first) + " -> " + valeur(*reti) + ";\n";
	}
	std::string footer = "}\n";
	return header + body_v + body_a + footer;
}

#endif
