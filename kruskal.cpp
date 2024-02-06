/**
 * @file kruskal.cpp
 * @author Achraf Boujida
 * @brief implementation of kruskal
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <fstream>
#include "kruskal.h"
#include <vector>
#include <algorithm>

/**
 * @brief read a graph from a file
 * 
 * @param file_name name of the file
 * 
 */
void read_graph(string file_name, graph_t& graph)
{
    int weight;
    int source;
    int dest;

    std::ifstream file(file_name);

    file >> graph.nb_edges >> graph.nb_nodes;

    for (int i=0; i<graph.nb_edges; ++i) {
        file >> source >> dest >> weight;
        auto node = make_pair(source, dest);
        auto edge = make_pair(weight, node);
        graph.edges.push_back(edge);
    }
}

/**
 * @brief run kruskal algorithm
 * 
 * @param graph graph object
 * @return int minimal weight
 */
int run_kruskal(graph_t& graph)
{
    // Objet qui contient les deux vecteurs parents et ranks
    set_t set;
    int min_weight = 0;
    int source;
    int dest;
    
    for (int i=0; i<graph.nb_nodes; ++i)
    {
        set.parents.push_back(i);
        set.ranks.push_back(0);
    }

    sort(graph.edges.begin(), graph.edges.end(), [] (const std::pair<int, std::pair<int, int>>& e1, const std::pair<int, std::pair<int, int>>& e2) -> bool { return e1.first < e2.first; } );

    cout << "w\ti\tj" << endl << endl;

    for (auto& edge : graph.edges)
    {
        source = find_root_parent(set, edge.second.first);
        dest = find_root_parent(set, edge.second.second);

        if (source != dest)
        {
            cout << edge.first << "\t" << edge.second.first << "\t" << edge.second.second << endl;
            min_weight += edge.first;
            create_union(set, source, dest);
        }
    }

    cout << "minimum weight : " << min_weight << endl;

    return min_weight;
}

/**
 * @brief find root parent of an element
 * 
 * @param set set object
 * @param i node to find
 * @return int root parent
 */
int find_root_parent(set_t& set, int i)
{
    if (i != set.parents[i]) set.parents[i] = find_root_parent(set, set.parents[i]);
    return set.parents[i];
}

/**
 * @brief fonction qui merge les deux vertex x et y en un nouveau subset et l'ajout au subset passé en argument
 * 
 * @param set Objet qui contient les deux vecteurs parents et ranks
 * @param x source node
 * @param y destination node
 */
void create_union(set_t& set, int x, int y)
{
    int root_x = find_root_parent(set, x);
    int root_y = find_root_parent(set, y);

    if (set.ranks[root_x] > set.ranks[root_y]) set.parents[root_y] = root_x;
    else if (set.ranks[root_x] < set.ranks[root_y]) set.parents[root_x] = root_y;
    else
    {
        set.parents[root_y] = root_x;
        set.ranks[root_y]++;
    }
}