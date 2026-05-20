#pragma once
#include "grafo.hpp"
#include "code.hpp"
#include <map>
#include <set>

template <typename Contenitore>
unidirected_graph graph_visit(const unidirected_graph& G, int start, Contenitore& c) {
    unidirected_graph albero;
    std::set<int> visitati;
    std::map<int, int> padre;
    
    c.put(start);
    
    while (!c.empty()) {
        int nodo = c.get();
        
        if (visitati.count(nodo) == 0) {
            visitati.insert(nodo);
            
            if (nodo != start) {
                albero.add_edge(padre[nodo], nodo);
            }
            
            for (int v : G.neighbours(nodo)) {
                if (visitati.count(v) == 0) {
                    c.put(v);
                    padre[v] = nodo;
                }
            }
        }
    }
    return albero;
}

// Funzione di supporto per la ricorsione
void dfs_ricorsiva(const unidirected_graph& G, int nodo, std::set<int>& vis, unidirected_graph& albero) {
    vis.insert(nodo);
    for (int v : G.neighbours(nodo)) {
        if (vis.count(v) == 0) {
            albero.add_edge(nodo, v);
            dfs_ricorsiva(G, v, vis, albero);
        }
    }
}

unidirected_graph recursive_dfs(const unidirected_graph& G, int start) {
    unidirected_graph albero;
    std::set<int> visitati;
    dfs_ricorsiva(G, start, visitati, albero);
    return albero;
}

std::map<int, int> dijkstra(const unidirected_graph& G, int start) {
    std::map<int, int> dist;
    for (int n : G.all_nodes()) {
        dist[n] = 999999; // Uso un numero grande finto come infinito
    }
    dist[start] = 0;
    
    std::set<std::pair<int, int>> coda_prio;
    coda_prio.insert({0, start});
    
    while (!coda_prio.empty()) {
        int u = coda_prio.begin()->second;
        coda_prio.erase(coda_prio.begin());
        
        for (int v : G.neighbours(u)) {
            // Peso è 1 per tutti gli archi
            if (dist[u] + 1 < dist[v]) {
                coda_prio.erase({dist[v], v});
                dist[v] = dist[u] + 1;
                coda_prio.insert({dist[v], v});
            }
        }
    }
    return dist;
}