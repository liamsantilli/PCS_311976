#include <iostream>
#include <vector>
#include <string>
#include "algoritmi_ordinamento.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    
    for (int k = 0; k < 100; ++k) {
        std::vector<int> v(50);
        
        rf.fill(v, -500, 500);
        ordina_bolle(v);
        if (!e_ordinato(v)) return EXIT_FAILURE;

        rf.fill(v, -500, 500);
        ordina_inserimento(v);
        if (!e_ordinato(v)) return EXIT_FAILURE;

        rf.fill(v, -500, 500);
        ordina_selezione(v);
        if (!e_ordinato(v)) return EXIT_FAILURE;
    }

    std::vector<std::string> nomi = {"Torino", "Milano", "Roma", "Napoli", "Venezia"};
    ordina_inserimento(nomi);
    if (!e_ordinato(nomi)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}