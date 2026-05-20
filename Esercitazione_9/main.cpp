#include <iostream>
#include <fstream>
#include "grafo.hpp"
#include "code.hpp"
#include "algoritmi.hpp"

using namespace std; // Classico per velocizzare

void salva_grafo(const unidirected_graph& g, string nome_file) {
    ofstream out(nome_file);
    out << "graph G {\n";
    for (auto arco : g.all_edges()) {
        out << "  " << arco.from() << " -- " << arco.to() << ";\n";
    }
    out << "}\n";
}

int main() {
    unidirected_graph g;
    
    // Ricreo il grafo della foto della lezione
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 7);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 7);
    g.add_edge(6, 8);
    g.add_edge(7, 9);
    g.add_edge(8, 9);

    salva_grafo(g, "originale.dot");

    fifo coda;
    unidirected_graph bfs_g = graph_visit(g, 1, coda);
    salva_grafo(bfs_g, "bfs.dot");

    unidirected_graph dfs_g = recursive_dfs(g, 1);
    salva_grafo(dfs_g, "dfs.dot");

    map<int, int> distanze = dijkstra(g, 1);
    cout << "Distanze dal nodo 1 (Dijkstra):\n";
    for (auto d : distanze) {
        cout << "Nodo " << d.first << " -> " << d.second << "\n";
    }

    return 0;
}