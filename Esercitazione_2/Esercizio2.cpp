#include <iostream>
#include <cmath>


int main() {
    const int N = 10;
    double dati[N];

   
    std::cout << "Inserisci " << N << " numeri reali (double):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "Elemento [" << i << "]: ";
        std::cin >> dati[i];
    }
  
    double somma = 0.0;
    for (int i = 0; i < N; ++i) {
        somma += dati[i];
    }
    double media = somma / N;

    double somma_scarti_quadrati = 0.0;
    for (int i = 0; i < N; ++i) {
        double scarto = dati[i] - media;
        somma_scarti_quadrati += scarto * scarto;
    }
    double varianza = somma_scarti_quadrati / N;

    std::cout << "RISULTATI" << std::endl;
    std::cout << "Media:    " << media << std::endl;
    std::cout << "Varianza: " << varianza << std::endl;

    return 0;
}