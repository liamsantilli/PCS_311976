#pragma once
#include <set>
#include <list>
#include "arco.hpp"

class unidirected_graph {
    std::set<unidirected_edge> archi;
    std::set<int> nodi;

public:
    unidirected_graph() {}
    unidirected_graph(const unidirected_graph& g) = default;

    void add_edge(int u, int v) {
        archi.insert(unidirected_edge(u, v));
        nodi.insert(u);
        nodi.insert(v);
    }

    std::list<int> neighbours(int n) const {
        std::list<int> vicini;
        for (auto arco : archi) {
            if (arco.from() == n) vicini.push_back(arco.to());
            else if (arco.to() == n) vicini.push_back(arco.from());
        }
        return vicini;
    }

    std::set<int> all_nodes() const { return nodi; }
    std::set<unidirected_edge> all_edges() const { return archi; }

    int edge_number(const unidirected_edge& e) const {
        int i = 0;
        for (auto arco : archi) {
            if (arco == e) return i;
            i++;
        }
        return -1;
    }

    unidirected_edge edge_at(int n) const {
        auto it = archi.begin();
        for(int i = 0; i < n; i++) it++; // Metodo semplice per scorrere il set
        return *it;
    }

    unidirected_graph operator-(const unidirected_graph& g2) const {
        unidirected_graph diff;
        for (auto arco : archi) {
            // Se non trovo l'arco in g2, lo aggiungo
            if (g2.archi.count(arco) == 0) {
                diff.add_edge(arco.from(), arco.to());
            }
        }
        return diff;
    }
};