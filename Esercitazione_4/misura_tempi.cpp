#include <iostream>
#include <vector>
#include <algorithm>
#include "algoritmi_ordinamento.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() {
    randfiller rf;
    timecounter tc;
    
    std::cout << "Dimensione\tBolle\tInserimento\tSelezione\tstd::sort\n";
    
    for (int n = 4; n <= 8192; n *= 2) {
        std::vector<int> base(n);
        rf.fill(base, -1000, 1000);
        
        std::vector<int> v;

        v = base;
        tc.tic(); 
        ordina_bolle(v); 
        double t_bolle = tc.toc();
        
        v = base;
        tc.tic(); 
        ordina_inserimento(v); 
        double t_ins = tc.toc();
        
        v = base;
        tc.tic(); 
        ordina_selezione(v); 
        double t_sel = tc.toc();
        
        v = base;
        tc.tic(); 
        std::sort(v.begin(), v.end()); 
        double t_std = tc.toc();
        
        std::cout << n << "\t" << t_bolle << "\t" << t_ins << "\t" << t_sel << "\t" << t_std << "\n";
    }
    return 0;
}