#pragma once
#include <iostream>
#include <algorithm>

class unidirected_edge {
    int u, v; // I due nodi

public:
    unidirected_edge(int n1, int n2) {
        // Metto sempre il più piccolo a sinistra
        u = std::min(n1, n2);
        v = std::max(n1, n2);
    }

    int from() const { return u; }
    int to() const { return v; }

    bool operator<(const unidirected_edge& altro) const {
        if (u != altro.u) return u < altro.u;
        return v < altro.v;
    }

    bool operator==(const unidirected_edge& altro) const {
        return u == altro.u && v == altro.v;
    }

    friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& e) {
        return os << "(" << e.u << " -- " << e.v << ")";
    }
};