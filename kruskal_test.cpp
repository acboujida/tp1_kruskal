/**
 * @file kruskal_test.cpp
 * @author Achraf BOUJIDA
 * @brief file for the test cases
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "catch.hpp"

#include <sstream>
#include <iostream>
#include <type_traits>

#include "kruskal.h"

TEST_CASE("TEST 1")
{
    graph_t graph;
    std::vector<int> edges;
    std::string input_file_name = "test_file.txt";
	
	read_graph(input_file_name, graph);

    REQUIRE ( graph.nb_edges == 14 );
    REQUIRE ( graph.nb_nodes == 9 );
    
    int min_weight = run_kruskal(graph);
    
    REQUIRE ( min_weight == 37 );
}

TEST_CASE("TEST 2")
{
    graph_t graph;
    std::vector<int> edges;
    std::string input_file_name = "test2_file.txt";
	
	read_graph(input_file_name, graph);

    REQUIRE ( graph.nb_edges == 18 );
    REQUIRE ( graph.nb_nodes == 11 );
    
    int min_weight = run_kruskal(graph);
    
    REQUIRE ( min_weight == 44 );
}