#pragma once
#include <vector>
#include <set>
#include <map>
#include <list>
#include "unidirected_edge.hpp"

class unidirected_graph {
private:
    std::set<unidirected_edge> edges; 
    std::set<int> nodes;              

public:
    unidirected_graph() = default; 

    
    void add_edge(int u, int v) {
        unidirected_edge e(u, v);
        edges.insert(e);
        nodes.insert(u);
        nodes.insert(v);
    }

    
    std::list<int> neighbours(int node) const {
        std::list<int> result;
        for (const auto& e : edges) {
            if (e.from() == node) result.push_back(e.to());
            else if (e.to() == node) result.push_back(e.from());
        }
        return result;
    }

    std::set<int> all_nodes() const { return nodes; } 
    std::set<unidirected_edge> all_edges() const { return edges; }

    
    int edge_number(const unidirected_edge& e) const {
        int count = 0;
        for (const auto& current : edges) {
            if (current == e) return count;
            count++;
        }
        return -1; 
    }

    
    unidirected_edge edge_at(int n) const {
        auto it = edges.begin();
        std::advance(it, n);
        return *it;
    }

    
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& e : edges) {
            // Se l'arco di questo grafo non è presente nell'altro
            if (other.edges.find(e) == other.edges.end()) {
                result.add_edge(e.from(), e.to());
            }
        }
        return result;
    }
};