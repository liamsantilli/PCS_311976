#include <iostream>
#include <vector>
#include <algorithm>
#include "algoritmi_ordinamento.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() {
    randfiller rf;
    timecounter tc;
    const int n_vettori = 100;
    
    std::cout << "Dim\tIns\tMerge\tQuick\tIbrido\tstd::sort\n";
    
    for (int n : {10, 20, 50, 100, 500, 1000}) {
        std::vector<std::vector<int>> base(n_vettori, std::vector<int>(n));
        for(auto& v : base) rf.fill(v, -1000, 1000);
        
        auto test = base;
        tc.tic();
        for(auto& v : test) ordina_inserimento(v);
        double t_ins = tc.toc() / n_vettori;
        
        test = base;
        tc.tic();
        for(auto& v : test) ordina_merge(v);
        double t_m = tc.toc() / n_vettori;
        
        test = base;
        tc.tic();
        for(auto& v : test) ordina_quick(v);
        double t_q = tc.toc() / n_vettori;
        
        test = base;
        tc.tic();
        for(auto& v : test) ordina_quick_ibrido(v, 20); 
        double t_qi = tc.toc() / n_vettori;
        
        test = base;
        tc.tic();
        for(auto& v : test) std::sort(v.begin(), v.end());
        double t_std = tc.toc() / n_vettori;
        
        std::cout << n << "\t" << t_ins << "\t" << t_m << "\t" << t_q << "\t" << t_qi << "\t" << t_std << "\n";
    }
    return 0;
}