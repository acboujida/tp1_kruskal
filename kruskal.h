/**
 * @file kruskal.h
 * @author Achraf Boujida
 * @brief kruskal interface
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef KRUSKAL__H
#define KRUSKAL__H

#include <string>
#include <vector>

using namespace std;

typedef struct graph
{
	int nb_nodes, nb_edges;
	vector<pair<int, pair<int, int>>> edges;
} graph_t;

typedef struct set
{
	vector<int> parents;
	vector<int> ranks;
} set_t;

void read_graph(string file_name, graph_t & graph);
int run_kruskal(graph_t & graph);
void create_union(set_t& set, int x, int y);
int find_root_parent(set_t& set, int i);

#endif // KRUSKAL__H