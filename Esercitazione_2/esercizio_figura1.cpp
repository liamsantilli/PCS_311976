#include <iostream>


int main() {
    
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};
    
    int x = 1;
    float y = 1.1;

    
   
    std::cout << "Indirizzo di x (int):   " << &x << std::endl;
    std::cout << "Indirizzo di y (float): " << &y << std::endl;


    
    for (int i = 0; i < 4; ++i) {
        std::cout << "ad[" << i << "]: " << &ad[i] << std::endl;
    }
    std::cout << std::endl;


    for (int i = 0; i < 8; ++i) {
        std::cout << "af[" << i << "]: " << &af[i] << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; ++i) {
        std::cout << "ai[" << i << "]: " << &ai[i] << std::endl;
    }
    std::cout << std::endl;

    
    (&y)[1] = 0; 


    std::cout << "Valore di x: " << x << std::endl;

    return 0;
}
