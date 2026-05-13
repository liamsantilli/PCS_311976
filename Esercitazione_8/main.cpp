#include <iostream>
#include "unidirected_graph.hpp"

int main() {
    unidirected_graph g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(3, 1);

    std::cout << "Archi in G1:\n";
    for (const auto& e : g1.all_edges()) std::cout << e << " ";
    std::cout << "\n";

    unidirected_graph g2;
    g2.add_edge(1, 2); 

    unidirected_graph g_diff = g1 - g2;
    std::cout << "Differenza (G1 - G2):\n";
    for (const auto& e : g_diff.all_edges()) std::cout << e << " ";
    std::cout << "\n";

    return 0;
}