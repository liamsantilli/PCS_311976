#pragma once
#include <iostream>
#include <algorithm>

class unidirected_edge {
private:
    int u, v; // I due nodi connessi

public:
    
    unidirected_edge(int node1, int node2) {
        u = std::min(node1, node2);
        v = std::max(node1, node2);
    }

    int from() const { return u; } 
    int to() const { return v; }   

    
    bool operator<(const unidirected_edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }

    
    bool operator==(const unidirected_edge& other) const {
        return u == other.u && v == other.v;
    }

    
    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
        os << "(" << e.u << " -- " << e.v << ")";
        return os;
    }
};